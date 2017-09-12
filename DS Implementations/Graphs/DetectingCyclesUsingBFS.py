class Graph:

	def __init__(self,v):
		self.count=0
		self.graph={}
		self.visited={}
		self.parent={}
		self.V = v
		for i in range(0,v):
			self.graph[i]=[]
			self.visited[i]=-1
			self.parent[i]=0
		
	def addEdge(self,u,v):
		self.graph[u].append(v)
		self.graph[v].append(u)

	def BFSforCycles(self):
		self.parent[1] = 0
		self.visited[1] = 1
		queue = []
		queue.append(1)
		while queue != []:
			u = queue.pop(0)
			for v in self.graph[u]:
				if self.visited[v] is -1:
					self.visited[v] = 1
					self.parent[v] = u
					queue.append(v)
				elif self.parent[u] != v:
					return True
		return False

g = Graph(5)
g.addEdge(1, 0)
g.addEdge(0, 2)
g.addEdge(2, 0)
g.addEdge(0, 3)
g.addEdge(3, 4)

if g.BFSforCycles():
	print("Graph contains cycles")
else:
	print("Graph doesn't contain any")

g1 = Graph(3)
g1.addEdge(0,1)
g1.addEdge(1,2)

if g1.BFSforCycles():
	print("Graph contains cycles")
else:
	print("Graph doesn't contain any") 

