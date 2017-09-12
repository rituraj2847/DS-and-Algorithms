
def partition(arr,l,r):
	global comp
	comp += r-l
	pivot = arr[r]
	j = l
	for i in range(l,r):
		if arr[i] < pivot:
			(arr[i],arr[j]) = (arr[j],arr[i])
			j += 1
	(arr[j],arr[r]) = (arr[r],arr[j])
	return j

def quickSort(arr,l,r):
	if r>l:
		pIndex = partition(arr,l,r)
		quickSort(arr,l,pIndex-1)
		quickSort(arr,pIndex+1,r)
	
comp=0
f = open('qsort.txt', 'r')
arr = [int(i) for i in f.readlines()]
quickSort(arr,0,len(arr)-1)
print(comp)
print(arr)