
def maxHeapify(A, i):
	if 2*i+1 < len(A) and 2*i+2 < len(A):
		leftChild = A[2*i+1]
		rightChild = A[2*i+2]
		largest = i
		if (leftChild > A[largest]):
			largest = 2*i+1
		if (rightChild > A[largest]):
			largest = 2*i+2
		if largest != i:
			(A[largest], A[i]) = (A[i], A[largest])
			maxHeapify(A, largest)
	if 2*i+2 >=len(A) and 2*i+1 < len(A):
		leftChild = A[2*i+1]
		if(leftChild > A[i]):
			largest = 2*i+1
			(A[i], A[largest]) = (A[largest], A[i])
			maxHeapify(A, largest)		
	
def buildMaxHeap(A, n):
	for i in range(n//2,-1,-1):
		maxHeapify(A, i)
		
def heapSort(A):
	while(len(A) != 0):
		(A[0], A[len(A)-1]) = (A[len(A)-1], A[0])
		l.append(A[-1])
		del(A[-1])
		maxHeapify(A, 0)
l = []
A = [9,8,7,5,4,2,16,32,12,11]
buildMaxHeap(A, len(A)-1)
print(A)
heapSort(A)
print("Sorted: " , l)
