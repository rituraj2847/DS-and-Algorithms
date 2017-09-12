import sys
class Graph:

	def __init__(self,v):
		self.graph = {}
		self.level = {}
		self.parent = {}
		for i in range(1, v+1):
			self.graph[i] = []
			self.level[i] = -1
			self.parent[i] = -1

	def addEdge(self,u,v):
		self.graph[u].append(v)
		self.graph[v].append(u)

	def BFS(self,v):
		queue = []
		queue.append(v)
		self.level[v] = 0
		while queue != []:
			s = queue.pop(0)
			for i in self.graph[s]:
				if self.level[i] is -1:
					self.level[i] = 1+self.level[s]
					self.parent[i] = s
					queue.append(i)

	def findPath(self,v):
		if self.parent[v] is -1:
			return
		else:
			self.findPath(self.parent[v])
			print(str(self.parent[v])," --> ",end="")
			return

g = Graph(10)
g.addEdge(1,2)
g.addEdge(1,3)
g.addEdge(2,3)
g.addEdge(4,1)
g.addEdge(4,5)
g.addEdge(4,8)
g.addEdge(5,6)
g.addEdge(6,9)
g.addEdge(7,5)
g.addEdge(7,6)
g.addEdge(8,6)
g.addEdge(9,10)
g.BFS(1)
g.findPath(8)
print(8)
