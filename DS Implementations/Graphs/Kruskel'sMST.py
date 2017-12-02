class Graph:
	def __init__(self,v):
		self.V = v
		self.graph = []
		self.component = [i for i in range(v)]
	def addEdge(self,u,v,w):
		self.graph.append((u,v,w))

	def Kruskal(self):
		self.graph = sorted(self.graph,key=lambda x: x[-1])
		TE = []
		i = 0
		while len(TE) < self.V-1:
			(u,v,w) = self.graph[i]
			if self.component[u] != self.component[v]:
				TE.append((u,v,w))
				comp = self.component[v]
				for j in range(self.V):
					if self.component[j] == comp:
						self.component[j] = self.component[u]
			i += 1
		print(self.component)
		print(TE)

g = Graph(7)
g.addEdge(0,2,18)
g.addEdge(1,2,6)
g.addEdge(0,1,10)
g.addEdge(3,2,70)
g.addEdge(1,4,20)
g.addEdge(4,5,10)
g.addEdge(5,6,5)
g.addEdge(6,4,10)
g.Kruskal()



