
public class QuickSort {
    private int pIndex;
    public int partition(int[] a,int left,int right){
        int pivot=a[right];
        pIndex=left;
        for(int i=left;i<right;i++){
			if(a[i]<pivot){
				int temp=a[pIndex];
				a[pIndex]=a[i];
				a[i]=temp;
				pIndex+=1;
			}
        }
        int temp=a[pIndex];
        a[pIndex]=a[right];
        a[right]=temp;
        return pIndex;
    }
    public void QuickSort(int[] a,int left,int right){
        if(right>left){
			pIndex=partition(a,left,right);
			QuickSort(a,left,pIndex-1);
			QuickSort(a,pIndex+1,right);
		}
    }
    public void Print(int[] a){
        for(int i=0;i<a.length;i++){
				System.out.print(a[i]+" ");
        }
    }
      
    public static void main(String[] args){
        QuickSort q=new QuickSort();
        int[] a={55,44,33,22,11,9,8};
        q.QuickSort(a,0,a.length-1);
        q.Print(a);
    }
}
