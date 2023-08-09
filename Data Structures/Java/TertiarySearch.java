
public class TertiarySearch {
	public static int search(int[] arr, int target, int low, int high){
		int mid1 = low + (high-low)/3;
		int mid2 = low + 2*(high-low)/3;
		if(low > high) {
			return -1;
		}
		if(arr[mid1] == target) {
			return mid1;
		}
		if(arr[mid2] == target) {
			return mid2;
		}
		if (target < arr[mid1]) {
            return search(arr, target, low, mid1 - 1);
        }
		else if (target > arr[mid2]) {
            return search(arr, target, mid2 + 1, high);
        }
        else {
        	return search(arr, target, mid1 + 1, mid2 - 1);
        }	
	}
	public static void main(String[] args) {
		int arr[] = {1,2,3,4,5,6,7,8,10};
		System.out.println(search(arr, 2, 0, 8));
		System.out.println(search(arr, 9, 0, 8));
	}
}
