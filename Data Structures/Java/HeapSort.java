
public class HeapSort {	
	public static void heapify(int[] arr) {
		//Change array to heap structure
		int heap[] = new int[arr.length+1];
		heap[0] = arr.length;
		for(int i = 0; i < arr.length; i++) {
			heap[i+1] = arr[i];
		}
		// percolate down starting from last parent
		int lastparent = heap[0]/2;
		while(lastparent > 0) {
			percolateDown(heap, lastparent);
			lastparent--;
		}
		//copy data into array
		for(int i = 1; i < heap.length; i++) {
			arr[i-1] = heap[i];
		}
	}
	//finds largest value out of parent and children and swaps and calls percolate down again if necessary 
	public static void percolateDown(int[] arr, int lastparent) {
		int child1 = 2 * lastparent;
		int child2 = 2 * lastparent + 1;
		int swap = lastparent;
		if(child1 <= arr[0]) {
			if(arr[child1] > arr[swap]) {
				swap = child1;
			}		
		}
		if(child2 <= arr[0]) {
			if(arr[child2] > arr[swap]) {
				swap = child2;
			}
		}
		if(swap != lastparent) {
			int temp = arr[swap];
			arr[swap] = arr[lastparent];
			arr[lastparent] = temp;
			percolateDown(arr, swap);
		}
	}
	
	public static void sort(int[] arr) {
		//Change array to heap structure
		int heap[] = new int[arr.length+1];
		heap[0] = arr.length;
		for(int i = 0; i < arr.length; i++) {
			heap[i+1] = arr[i];
		}
		//while there is heap to be sorted swap first and last value and percolate
		while(heap[0] > 1) {
			int temp = heap[1];
			heap[1] = heap[heap[0]];
			heap[heap[0]] = temp;
			heap[0]--;
			int lastparent = heap[0]/2;
			while(lastparent > 0) {
				percolateDown(heap, lastparent);
				lastparent--;
			}
		}
		for(int i = 1; i < heap.length; i++) {
			arr[i-1] = heap[i];
		}	
	}
	
	public static void main(String[] args) {
		int[] arr = {8, 10, 4, 12, 16, 82, 38, 29, 2, 19, 53, 23, 74, 92, 1};
		System.out.println("Array before heap: ");
		for(int x : arr) {
			System.out.print(x + " ");
		}
		heapify(arr);
		System.out.println();
		System.out.println("Array after heap: ");
		for(int x : arr) {
			System.out.print(x +" ");
		}
		sort(arr);
		System.out.println();
		System.out.println("Array after sort: ");
		for(int x : arr) {
			System.out.print(x +" ");
		}
	}

	
	
}
