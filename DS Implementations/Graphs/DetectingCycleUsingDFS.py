
class Graph:

	def __init__(self,v):
		self.count=0
		self.graph={}
		self.visited={}
		self.parent={}
		self.V = v
		for i in range(0,v):
			self.graph[i]=[]
			self.visited[i]=0
			self.parent[i]=0
		
	def addEdge(self,u,v):
		self.graph[u].append(v)
		self.graph[v].append(u)

	def isCyclicUtil(self,u):
		self.visited[u] = 1
		for i in self.graph[u]:
			if self.visited[i]==0:
				self.parent[i]=u
				if self.isCyclicUtil(i):
					return True
			elif i != self.parent[u]:
				return True
		return False

	def isCyclic(self):
	 	for i in range(self.V):
	 		if self.visited[i]==0:
	 			if(self.isCyclicUtil(i)) == True:
	 				return True
	 	return False

g = Graph(5)
g.addEdge(1, 0)
g.addEdge(0, 2)
g.addEdge(2, 0)
g.addEdge(0, 3)
g.addEdge(3, 4)

if g.isCyclic():
	print("Graph contains cycles")
else:
	print("Graph doesn't contain any")

g1 = Graph(3)
g1.addEdge(0,1)
g1.addEdge(1,2)

if g1.isCyclic():
	print("Graph contains cycles")
else:
	print("Graph doesn't contain any")
