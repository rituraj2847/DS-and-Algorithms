import sys
INF = sys.maxsize
class Graph:
	def __init__(self,v):
		self.V = v

	def FloydWarshall(self):
		for k in range(self.V):
			for i in range(self.V):
				for j in range(self.V):
					if self.distance[i][j] > self.distance[i][k] + self.distance[k][j] and self.distance[k][j] != INF:
						self.distance[i][j] = self.distance[i][k] + self.distance[k][j]
						self.path[i][j] = k
				g.print()


	def print(self):
		for i in range(self.V):
			for j in range(self.V):
				if self.distance[i][j]==INF:
					print("INF",end=" ")
				else:
					print("%d"%(self.distance[i][j]),end="  ")
			print("")
		print("\n")

g = Graph(4)
g.distance = [[0, INF, 3, INF],
			  [4, 0 ,3, INF],
			  [INF, INF, 0, 2],
			  [INF, -1, INF, 0]
			 ]
g.path = [[0 for i in range(4)] for j in range(4)]
g.FloydWarshall()
g.print()
print(g.path)
