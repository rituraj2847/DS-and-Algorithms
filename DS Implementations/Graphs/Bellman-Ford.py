class Graph:

	def __init__(self,v):
		self.graph=[]
		self.V = v
		self.distance={}
		for i in range(1,v+1):
			self.distance[i] = float("Inf")

	def addEdge(self,u,v,w):
		self.graph.append([u,v,w])

	def BellmanFord(self,u):
		self.distance[u] = 0
		for i in range(self.V-1):
			for u,v,w in self.graph:
				if self.distance[u] != float("Inf") and self.distance[v] > w + self.distance[u]:
					self.distance[v] = w + self.distance[u]
		for u, v, w in self.graph:
			if self.distance[u] != float("Inf") and self.distance[u] + w < self.distance[v]:
				print ("Graph contains negative weight cycle")
				return

	def printArr(self):
		print("Vertex   Distance from Source")
		for i in range(self.V):
			print("%d   \t\t %d" % (i, self.distance[i]))
			
g = Graph(5)
g.addEdge(0, 1, -1)
g.addEdge(0, 2, 4)
g.addEdge(1, 2, 3)
g.addEdge(1, 3, 2)
g.addEdge(1, 4, 2)
g.addEdge(3, 2, 5)
g.addEdge(3, 1, 1)
g.addEdge(4, 3, -3)
g.BellmanFord(0)
g.printArr()
 