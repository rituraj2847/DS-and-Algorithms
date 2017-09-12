class Graph:

	def __init__(self, v):
		self.indegree={}
		self.graph={}
		for i in range(0,v):
			self.graph[i]=[]
			self.indegree[i]=0

	def addEdge(self, u, v):
		self.graph[u].append(v)

	def topologicalSort(self):
		queue=[]
		for i in self.graph:
			for j in self.graph[i]:
				self.indegree[j] += 1
		for i in self.graph:
			if self.indegree[i] == 0:
				queue.append(i)

		while queue != []:
			s = queue.pop(0)
			print(s)
			for i in self.graph[s]:
				self.indegree[i] -= 1
				if self.indegree[i] == 0:
					queue.append(i)

g= Graph(6)
g.addEdge(5, 2)
g.addEdge(5, 0)
g.addEdge(4, 0)
g.addEdge(4, 1)
g.addEdge(2, 3)
g.addEdge(3, 1)
 
print ("Following is a Topological Sort of the given graph")
g.topologicalSort()