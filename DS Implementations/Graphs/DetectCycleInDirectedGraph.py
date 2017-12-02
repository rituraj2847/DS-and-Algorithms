class Graph:
	def __init__(self,v):
		self.V = v
		self.graph = {}
		self.visited=[0]*v
		for i in range(0,v):
			self.graph[i] = []

	def addEdge(self,u,v):
		self.graph[u].append(v)

	def isCyclicUtil(self,u,recStack):
		self.visited[u] = 1
		for v in self.graph[u]:
			if self.visited[v] is 0:
				recStack.append(v)
				if self.isCyclicUtil(v,recStack) is True:
					return True
			elif v in recStack:
				return True
		recStack.pop()
		return False
	
	def isCyclic(self):
		for v in range(0,self.V):
			if self.visited[v] == 0:
				recStack=[v]
				if self.isCyclicUtil(v,recStack) is True:
					return True
		return False

g = Graph(4)
g.addEdge(0, 1)
g.addEdge(0, 2)
g.addEdge(1, 2)
g.addEdge(2, 0)
g.addEdge(2, 3)
g.addEdge(3, 3)
if g.isCyclic() == 1:
    print ("Graph has a cycle")
else:
    print ("Graph has no cycle")