class BSTNode:

	def __init__(self, val):
		self.value = val
		self.left = None
		self.right = None

class BST:

	def __init__(self):
		self.root = None

	def insert(self, val):
		newnode = BSTNode(val)
		if self.root == None:
			self.root = newnode
		else:
			node = self.root
			while True:
				if val < node.value:
					if node.left is None:
						node.left = newnode
						break
					node = node.left
				else:
					if node.right is None:
						node.right = newnode
						break
					node = node.right

				
	def min(self):
		node = self.root
		while node.left != None:
			node = node.left
		print(node.value)

	def max(self):
		node = self.root
		while node.right != None:
			node = node.right
		print(node.value)

	def search(self, val):
		node = self.root
		while node != None:
			if node.value == val:
				return "Found"
			elif node.value >= val:
				node = node.left
			else:
				node = node.right
		return "not"

b = BST()
b.insert(10)
b.insert(6)
b.insert(8)
b.insert(1)
b.insert(6)
b.max()
