
public class LinkedSort {
	static public class Node {
		public int val;
		public Node next;
	}
	
	public static void main(String[] args) {
		Node head = new Node();
		Node temp = head;
		
		// bounds for random int
		int min = 1;
		int max = 1000;
		
		// creates 15 linked node elements
		for(int i = 0; i < 15; i++) {
			int random_int = (int)Math.floor(Math.random() * (max - min + 1) + min);
			temp.val = random_int;
			if(i == 14) {
				temp.next = null;
			}
			else {
				temp.next = new Node();
			}
			temp = temp.next;
		}
		
		//Traverse unsorted linked list
		temp = head;
		while(temp != null) {
			System.out.println(temp.val);
			temp = temp.next;
		}
		System.out.println("\n");
		
		//bubble sort linked list
		boolean swap = true;
		while(swap) {
			temp = head;
			swap = false;
			//special case for head
			if(head.val > head.next.val) {
				head = temp.next;
				Node temp1 = temp.next.next;
				temp.next.next = temp;
				temp.next = temp1;
				swap = true;
			}
			//default swap case
			temp = head;
			while(temp.next.next != null) {
				if (temp.next.val > temp.next.next.val) {
					Node temp1 = temp.next.next.next;
					temp.next.next.next = temp.next;
					Node temp2 = temp.next.next;
					temp.next.next = temp1;
					temp.next = temp2;
					swap = true;
				}
				temp = temp.next;	
			}
		}
		//Traverse sorted linked list
		temp = head;
		while(temp != null) {
			System.out.println(temp.val);
			temp = temp.next;
		}
	}
}
