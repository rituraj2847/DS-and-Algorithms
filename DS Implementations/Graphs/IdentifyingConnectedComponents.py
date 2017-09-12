class Graph:

	def __init__(self,v):
		self.count=0
		self.graph={}
		self.visited={}
		self.parent={}
		self.component={}
		for i in range(1,v+1):
			self.graph[i]=[]
			self.visited[i]=0
			self.parent[i]=-1
			self.component[i]=0
		
	def addEdge(self,u,v):
		self.graph[u].append(v)
		self.graph[v].append(u)

	def DFSUtil(self,v,comp):
		self.visited[v]=1
		for i in self.graph[v]:
			if self.visited[i]==0:
				self.component[i]=comp
				self.parent[i]=v
				self.DFSUtil(i,comp)

	def ConnectedComponents(self):
		comp = 0
		for node in self.graph.keys():
			if self.visited[node] == 0:
				comp += 1
				self.component[node]=comp
				self.DFSUtil(node,comp)
		print(self.component)

g = Graph(13)
g.addEdge(1,2)
g.addEdge(1,5)
g.addEdge(5,9)
g.addEdge(9,10)
g.addEdge(10,5)
g.addEdge(6,13)
g.addEdge(3,4)
g.addEdge(3,7)
g.addEdge(4,8)
g.addEdge(7,8)
g.addEdge(8,12)
g.addEdge(11,7)
g.addEdge(8,11)
g.ConnectedComponents()



