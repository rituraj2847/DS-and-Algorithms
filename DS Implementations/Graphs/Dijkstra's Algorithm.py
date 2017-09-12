import sys

class Graph:

	def __init__(self,vertices):
		self.V = vertices
		self.visited=[False]*self.V
		self.distance=[sys.maxsize]*self.V

	def minDist(self):
		mindist = sys.maxsize
		minIndex=0
		for i in range(0,self.V):
			if mindist > self.distance[i] and self.visited[i] != True:
				mindist = self.distance[i]
				minIndex = i
		return minIndex
	
	def shortestPath(self,src):
		self.distance[src] = 0
		for i in range(0,self.V):
			u = self.minDist()
			self.visited[u]=True
			for j in range(0,len(self.graph[u])):
				if self.visited[j] != True and self.graph[u][j] != 0:
					if self.distance[j] > self.graph[u][j] + self.distance[u]:
						self.distance[j] = self.graph[u][j] + self.distance[u]

	def printSol(self):
		print("Vertex" + "   " + "Distance from src")
		for u in range(self.V):
			print("  {0:10}  {1:3}".format(str(u),str(self.distance[u])))

g = Graph(9)
g.graph = [[0, 4, 0, 0, 0, 0, 0, 8, 0],
           [4, 0, 8, 0, 0, 0, 0, 11, 0],
           [0, 8, 0, 7, 0, 4, 0, 0, 2],
           [0, 0, 7, 0, 9, 14, 0, 0, 0],
           [0, 0, 0, 9, 0, 10, 0, 0, 0],
           [0, 0, 4, 14, 10, 0, 2, 0, 0],
           [0, 0, 0, 0, 0, 2, 0, 1, 6],
           [8, 11, 0, 0, 0, 0, 1, 0, 7],
           [0, 0, 2, 0, 0, 0, 6, 7, 0]
          ]
g.shortestPath(0)
g.printSol()
