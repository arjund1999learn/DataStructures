import java.util.Comparator;
import java.util.PriorityQueue;
public class Dijkstra {
	
	static public class Node {
		public int distance;
		public String label;
		public Node next;
	}
	
	
	static void printGraph(Node[] graph) {
		//print vertices
		System.out.print("Vertices: ");
		for(int i = 0; i < graph.length; i++) {
			System.out.print(graph[i].label +  " ");
		}
		System.out.println();
		// print edges
		System.out.print("Edges: ");
		for(int i = 0; i < graph.length; i++) {
			Node temp = graph[i];
			String temp1 = graph[i].label;
			while(temp.next != null) {
				System.out.print("(" + temp1 + ", " + temp.next.label + ") ");
				temp = temp.next;
			}
		}
		System.out.println();
	}
	
	static void dijkstra(Node[] graph, Node start) {
		//initialize array, parents, settled nodes, and heap for dijkstra's
		int[] dij = new int[10];
		String[] parent = new String[10];		//holds parents of settled nodes
		boolean[] settle = new boolean[10];
		Comparator<Node> comparator = new nodeCompare();	//needed to compare nodes by distance
		PriorityQueue<Node> heap = new PriorityQueue<Node>(comparator);
		heap.add(graph[0]);
		//set starting element to zero and rest to infinity (in this case -1)
		for(int i = 0; i < dij.length; i++) {
			if (i == 0) {
				dij[i] = 0;
			}
			else {
				dij[i] = -1;
			}
		}
		//iterate through graph using heap
		while(!heap.isEmpty()) {
			int loc = findNode(graph, heap.poll());		//find location in graph
			Node temp = graph[loc];						//set temp for iterating
			int dist = dij[loc];
			settle[loc] = true;
			//BFS search through node
			while(temp.next != null) {
				int loc1 = findNode(graph, temp.next);
				Node temp1 = temp.next;
				int dist1 = dij[loc1];
				if(settle[loc1] == false) {
					//if no distance then set distance else if the distance is smaller then change it and parent
					if(dist1 == -1) {
						dij[loc1] = temp1.distance + dist;
						parent[loc1] = graph[loc].label;
					}
					else if(dij[loc1] > dist1 + dist) {
						dij[loc1] = dist1 + dist;
						parent[loc1] = graph[loc].label;
					}
					graph[loc1].distance = dij[loc1];
					heap.add(graph[loc1]);
				}
				temp = temp.next;
			}
		}
		//print vertices
		System.out.print("Vertices: ");
		for(int i = 0; i < graph.length; i++) {
			System.out.print(graph[i].label +  " ");
		}
		System.out.println();
		//print tree
		System.out.print("Tree Edges: ");
		for(int i = 0; i < parent.length; i++) {
			if(parent[i] != null) {
				System.out.print("(" + parent[i] +  ", " + graph[i].label + ")");
			}
		}
	}
	//set up comparison of nodes	
	static class nodeCompare implements Comparator<Node>{
		public int compare(Node node1, Node node2) {
			if(node1.distance < node2.distance) {
				return -1;
			}
			else if(node1.distance > node2.distance) {
				return 1;
			}
			return 0;
		}
		
	}
	
	//find corresponding linked list
	static int findNode(Node[] graph, Node poll) {
		int var = 0;
		for(int i = 0; i < graph.length; i++) {
			if(graph[i].label == poll.label) {
				var = i;
				return var;
			}
		}
		return -1;
	}

	public static void main(String[] args) {
		//arrays for storing values for nodes
		String[] alpha = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
		int[] distances = {76, 93, 24, 52, 20, 35, 78, 17, 78, 51, 8, 46, 85, 4, 92, 94, 81, 63, 85, 3};
		//create graph
		Node[] graph = new Node[10];
		//initialize head of linked lists
		for(int i = 0; i < graph.length; i++) {
			Node temp = new Node();
			temp.label = alpha[i];
			temp.distance = 0;
			temp.next = null;
			graph[i] = temp;
		}
		//create ten edges for graph
		for(int i = 0; i < graph.length; i++) {
			Node temp = new Node();
			temp.label = alpha[(i+1)%10];
			temp.distance = distances[i];
			temp.next = null;
			graph[i].next = temp;
		}
		//create ten edges for graph
		for(int i = 0; i < graph.length; i++) {
			Node temp = new Node();
			temp.label = alpha[(i+2)%10];
			temp.distance = distances[i+10];
			temp.next = null;
			graph[i].next.next = temp;
		}
		//print initial graph
		printGraph(graph);
		//call dijkstra with root of graph[0]
		dijkstra(graph, graph[0]);
	}
}
