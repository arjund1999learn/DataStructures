
public class DeleteNode {
	//Define node
	static public class Node {
		public int val;
		public Node left;
		public Node right;
	}
	
	// Method to insert Node
	static void insertBST(int val, Node temp) {
		// If val is less insert left if empty or call insert on left node
		if(val < temp.val) {
			if(temp.left == null) {
				Node left = new Node();
				left.val = val;
				temp.left = left;
				return;
			}
			insertBST(val, temp.left);
		}
		// If val is right insert right if empty or call insert on right node
		if(val > temp.val) {
			if(temp.right == null) {
				Node right = new Node();
				right.val = val;
				temp.right = right;
				return;
			}
			insertBST(val, temp.right);
		}
	}
	
	// Inorder traverse tree
	static void inOrder(Node temp) {
		if(temp == null) {
			return;
		}
		inOrder(temp.left);
		System.out.print(temp.val + ", ");
		inOrder(temp.right);
	}
	
	static void deleteBST(int val, Node temp) {
		// Case for head
		if(temp.val == val) {
			temp.val = findSuccessor(temp.right);
		}
		// If val is less than temp check if left child is val and if so replace else traverse left
		else if(val < temp.val) {
			deleteBST(val, temp.left);
		}
		// If val is greater than temp check if right child is val and if so replace else traverse right
		else {
			deleteBST(val, temp.right);			
		}
		
	}
	// Finds in order successor of node
	static int findSuccessor(Node temp) {
		//find left most node and return it after replacing with its right node
		if(temp.left.left == null) {
			int temp1 = temp.left.val;
			temp.left = temp.left.right;
			return temp1;
		}
		return findSuccessor(temp.left);
	}
	
	
	public static void main(String[] args) {
		int[] values = {40, 60, 20, 80, 50, 10, 30, 15, 5, 35, 25, 45, 55, 70, 90, 32, 33, 48, 46};
		// Create root node 
		Node root = new Node();
		root.val = values[0];
		
		//insert all non-root nodes 
		for(int i = 0; i < values.length; i++) {
			insertBST(values[i], root);
		}
		System.out.println("Original tree");
		inOrder(root);
		
		System.out.println("");
		
		System.out.println("Tree after 40 deleted");
		deleteBST(40, root);
		inOrder(root);
		
		System.out.println("");
		
		System.out.println("Tree after 40 and 20 deleted");
		deleteBST(20, root);
		inOrder(root);
	}
	
}
