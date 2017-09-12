class Graph:

	def __init__(self,v):
		self.count=0
		self.graph={}
		self.visited={}
		self.parent={}
		self.pre={}
		self.post={}
		for i in range(1,v+1):
			self.graph[i]=[]
			self.visited[i]=0
			self.parent[i]=-1
			self.pre[i]=0
			self.post[i]=0
		
	def addEdge(self,u,v):
		self.graph[u].append(v)
		self.graph[v].append(u)

	def DFS(self,v):
		self.visited[v]=1
		self.pre[v]=self.count
		self.count += 1
		print(v)
		for i in self.graph[v]:
			if self.visited[i]==0:
				self.parent[i]=v
				self.DFS(i)
				self.post[i]=self.count
		 

g = Graph(10)
g.addEdge(1,2)
g.addEdge(1,3)
g.addEdge(2,3)
g.addEdge(4,1)
g.addEdge(4,5)
g.addEdge(5,6)
g.addEdge(6,7)
g.addEdge(6,8)
g.addEdge(6,9)
g.addEdge(7,5)
g.addEdge(7,6)
g.addEdge(8,4)
g.addEdge(9,10)
g.DFS(8)