import java.util.*;

public class TopSort {
	
	public static class Node {
		public char name;
		public Node next;
		public int visited;
	}
	
	public static Node[] dfsTop(Node[] graph, Node start) {
		//create stack for DFS traversal and int for current order position
		Stack<Node> stack = new Stack<Node>();
		int n = graph.length;
		// dfs search through graph
		Node temp = start;
		// Go through every node if stack is empty and there are still nodes to traverse
		for(int i = 0; i < graph.length; i++) {
			int nodeNum = findNode(graph, temp);
			if(graph[nodeNum].visited == 0) {
				stack.add(temp);
			}
			while(!stack.empty()) {
				if(graph[nodeNum].visited == 0) {
					temp = graph[nodeNum];
					while(temp.next != null) {
						nodeNum = findNode(graph, temp.next);
						// if stack already contains a value then the graph is cyclic so return null
						if(stack.contains(graph[nodeNum])) {
							return null;
						}
						// if node is not visited add to stack
						if(graph[nodeNum].visited == 0) {
							temp = graph[nodeNum];
							stack.push(temp);
						}
						// else go to next node
						else {
							temp = temp.next;
						}
					}
				}
				// we have reached a node with no paths so we pop it and order it
				Node temp1 = stack.pop();
				nodeNum = findNode(graph, temp1);
				graph[nodeNum].visited = n;
				n--;
				// go back to next highest node and repeat while loop
				if(!stack.empty()) {
					temp = stack.peek();
					nodeNum = findNode(graph, temp);
				}	
			}
			// if we are out of edges pick a new node
			temp = graph[i];
		}
		return graph;
	}
	
	public static Node[] bfsTop(Node[] graph, int[] predCount) {
		//create queue for BFS traversal and int for current order position
		Queue<Node> queue = new LinkedList<>();
		int n = 1;
		// queue all nodes with 0 predecessors
		for(int i = 0; i < graph.length; i++) {
			if (predCount[i] == 0) {
				queue.add(graph[i]);
			}
		}
		while(!queue.isEmpty()) {
			// pop top element and give it an order
			Node temp = queue.poll();
			temp.visited = n++;
			// reduce predCount of all adjacent edges
			while(temp.next != null) {
				temp = temp.next;
				int nodeNum = findNode(graph, temp);
				predCount[nodeNum]--;
			}
			// queue all nodes not yet queued with predcount of zero
			for(int i = 0; i < graph.length; i++) {
				if (predCount[i] == 0 && graph[i].visited == 0 && !queue.contains(graph[i])) {
					queue.add(graph[i]);
				}
			}
		}
		// if not all graphs visited then there is cycle so return null
		for(int i = 0; i < graph.length; i++) {
			if(graph[i].visited == 0) {
				return null;
			}
		}
		return graph;
	}
	
	//finds node in graph
	static int findNode(Node[] graph, Node node) {
		int var = 0;
		for(int i = 0; i < graph.length; i++) {
			if(graph[i].name == node.name) {
				var = i;
				return var;
			}
		}
		return -1;
	}
	
	// prints topological order of graph
	static void printGraph(Node[] graph) {
		//print vertices
		System.out.println("Vertices: ");
		for(int i = 0; i < graph.length; i++) {
			System.out.println(graph[i].name +  " " + graph[i].visited);
		}
		System.out.println();

	}

	public static void main(String[] args) {
		//creating representation of graphs
		Node[] graph1 = new Node[14]; 
		Node[] graph2 = new Node[8];
		String[] elem1 = {"mxqr", "nquo", "orvs", "posz", "qt", "ruy", "sr", "t", "ut", "vxw", "wz", "x", "yv", "z"};
		String[] elem2 = {"1652", "2573", "34", "45", "587", "685", "784", "8"};
		//add nodes and edges for first graph
		for(int i = 0; i < graph1.length; i++) {
			Node head = null;
			for(int j = 0; j < elem1[i].length(); j++) {
				Node temp = new Node();
				temp.name = elem1[i].charAt(j);
				temp.next = null;
				if(j == 0) {
					graph1[i] = temp;
					head = graph1[i];
				}
				else {
					graph1[i].next = temp;
					graph1[i] = graph1[i].next;
				}
			}
			graph1[i] = head;	
		}
		// add nodes and edges for first graph
		for(int i = 0; i < graph2.length; i++) {
			Node head = null;
			for(int j = 0; j < elem2[i].length(); j++) {
				Node temp = new Node();
				temp.name = elem2[i].charAt(j);
				temp.next = null;
				temp.visited = 0;
				if(j == 0) {
					graph2[i] = temp;
					head = graph2[i];
				}
				else {
					graph2[i].next = temp;
					graph2[i] = graph2[i].next;
				}
			}
			graph2[i] = head;
		}
		// call dfs of first graph and print if no error
		System.out.println("DFS of first graph: ");
		Node[] graph1copy = dfsTop(graph1, graph1[0]);
		if (graph1copy == null){
			System.out.println("Error: graph is cyclic");
		}
		else {
			printGraph(graph1copy);
		}
		// call dfs of second graph and print if no error
		System.out.println("DFS of second graph: ");
		Node[] graph2copy = dfsTop(graph2, graph2[0]);
		if (graph2copy == null){
			System.out.println("Error: graph is cyclic");
		}
		else {
			printGraph(graph2copy);
		}
		System.out.println();
		//reset visited values of graphs
		for(int i = 0; i < graph1.length; i++) {
			graph1[i].visited = 0;
		}
		for(int i = 0; i < graph2.length; i++) {
			graph2[i].visited = 0;
		}
		// call bfs of first graph and print if no error
		System.out.println("BFS of first graph: ");
		int[] predCount1 = {0,0,2,0,2,3,2,2,2,1,1,2,1,2};
		int[] predCount2 = {0,1,1,2,4,1,2,3};
		Node[] graph3copy = bfsTop(graph1, predCount1);
		if (graph3copy == null){
			System.out.println("Error: graph is cyclic");
		}
		else {
			printGraph(graph3copy);
		}
		// call bfs of second graph and print if no error
		System.out.println("BFS of second graph: ");
		Node[] graph4copy = bfsTop(graph2, predCount2);
		if (graph4copy == null){
			System.out.println("Error: graph is cyclic");
		}
		else {
			printGraph(graph4copy);
		}
	}
}
