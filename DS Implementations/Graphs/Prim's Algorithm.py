import sys
INF = sys.maxsize
class Graph:
	def __init__(self,v):
		self.V = v
		self.Dist_TV = [INF for i in range(self.V)]
		self.Ngr_TV = [-1 for i in range(self.V)]
		self.visited = [0 for i in range(self.V)]

	def Prim(self):
		TE = []
		self.visited[0] = 1
		dist = 0

		#Start at 0 vertex and update distances of its neighbours
		for v in range(1,self.V):
			if self.graph[0][v] != 0:
				self.Dist_TV[v] = self.graph[0][v]
				self.Ngr_TV[v] = 0

		for u in range(1,self.V):

			#Find the vertex with minimum distance
			smallest_dist = INF
			add_vertex = -1
			for i in range(1,self.V):
				if smallest_dist > self.Dist_TV[i] and self.visited[i] != 1:
					smallest_dist = self.Dist_TV[i]
					add_vertex = i
			TE.append((self.Ngr_TV[add_vertex],add_vertex))
			self.visited[add_vertex] = 1

			#Update distances of the neighbours of this newly added vertex
			for v in range(self.V):
				if self.Dist_TV[v] > self.graph[add_vertex][v] and self.graph[add_vertex][v] !=0: 
					self.Dist_TV[v] = self.graph[add_vertex][v]
					self.Ngr_TV[v] = add_vertex
		print(TE)

g = Graph(5)
g.graph = [ [0, 2, 0, 6, 0],
             [2, 0, 3, 8, 5],
             [0, 3, 0, 0, 7],
             [6, 8, 0, 0, 9],
             [0, 5, 7, 9, 0],
           ]
g.Prim()


