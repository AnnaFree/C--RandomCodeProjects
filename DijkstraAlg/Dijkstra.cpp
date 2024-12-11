#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

//typedef for portability
typedef pair<int, int> Node;

void addEdge(vector<vector<Node>>& graph, int startNode, int endNode, int weight) {
	//add new edges to graph
	graph[startNode].push_back({ endNode,weight });
	graph[endNode].push_back({ startNode, weight});
}
//Dijkstra's algorithm function
vector<int> dijkstra(const vector<vector<Node>>& graph, int sourceNode) {
	//number of nodes
	int vecSize = graph.size();
	//new vector with all nodes set to infinity, except for the source node
	vector<int> distance(vecSize, INT_MAX);
	//min-heap
	/*Priority queue is a container adapter. It is not a container itself but wraps other containers in it 
	This is the min-heap version.
	breakdown of this syntax: first argument is the type of element to be stored in queue. in this case it is the Node type, which is the vector
	vector<Node> is the type of internal container used to store these elements.
	greater<Node> is a custom comparison function. This determines how the elements are ordered within the priority queue. tgis argument sets up a min-heap. Smallest element will be at the top of the queue*/
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	distance[sourceNode] = 0; // initialize the first node to be 0 while everything else is infinity
	pq.push({ 0, sourceNode });

	while (!pq.empty()) {
		//comparing the top two distances in the heap before deleting the top one and going on to the next
		int dist = pq.top().first;
		int startNode = pq.top().second;
		pq.pop();

		//skip outdated distance entries that have already been examined
		if (dist > distance[startNode]) {
			continue;
		} 
		//exploring neighboring nodes
		//auto allows compiler to automatically deduce the type from its the value it was initialized with
		for (const auto& neighbor : graph[startNode]) {
			//neighbor node value
			int endNode = neighbor.first;
			//edge weight
			int weight = neighbor.second;
			//updating cuurrent optimal distance if better one is found
			if (distance[startNode] + weight < distance[endNode]) {
					distance[endNode] = distance[startNode] + weight;
					pq.push({ distance[endNode], endNode });
			}
		}
	}
	return distance;
}
int main() {

	int nodeNum = 10;
	vector<vector<Node>> graph(nodeNum);

	//adding edges
	addEdge(graph, 0, 1, 4);//1
	addEdge(graph, 0, 2, 1);
	addEdge(graph, 3, 1, 7);
	addEdge(graph, 1, 4, 3);
	addEdge(graph, 4, 5, 6);//5
	addEdge(graph, 5, 6, 3);
	addEdge(graph, 6, 7, 4);
	addEdge(graph, 7, 8, 2);
	addEdge(graph, 8, 9, 5);//10

	int source = 0;
	vector<int> distances = dijkstra(graph, source);
	cout << "shortest distance from node: " << source << "\n";
	for (int i = 0; i < distances.size(); i++) {
		if (distances[i] == INT_MAX) { //check due to issues i had with some nodes to help me readjust values
			cout << "Node " << i << ": Unreachable" << endl;
		}
		else {
			cout << "Node " << i << ": " << distances[i] << endl;
		}
		

	}
	return 0;
}
