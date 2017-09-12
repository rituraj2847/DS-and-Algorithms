
INF = 99999
class Graph:
	def __init__(self,v):
		self.V = v

	def floydWarshall(self):

		for k in range(self.V):
			for i in range(self.V):
				for j in range(self.V):
					if self.distance[i][j] > self.distance[i][k] + self.distance[k][j]:
						self.distance[i][j] = self.distance[i][k] + self.distance[k][j]

	def print(self):
		for i in range(self.V):
			for j in range(self.V):
				if self.distance[i][j]==INF:
					print("INF",end=" ")
				else:
					print("%d"%(self.distance[i][j]),end="  ")
			print("")

g = Graph(4)
g.distance = [[0 , 5, INF, 10],
			  [INF, 0 ,3, INF],
			  [INF, INF, 0, 1],
			  [INF, INF, INF, 0]
			 ]
g.floydWarshall()
g.print()
