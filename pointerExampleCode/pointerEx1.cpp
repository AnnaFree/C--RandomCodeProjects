#include <iostream>
using namespace std;

//node structure
//structures are a way to group several related variables into one place. Each variable in the structure is known as a member of the structure
//can contain different data types
struct Node {
	int data; //node value
	Node* nextNode; //pointer to the next node
	//initialization contruct
	Node(int val) : data(val), nextNode(nullptr){}
};

//linked list class
class LinkedList {
private:
	//private pointer to the head node of the list
	Node* headNode; 

public:
	//constructor
	LinkedList() : headNode(nullptr){}

	//Desctructor
	//~ signifies deconstructor and it has no arguments
	//only one per class
	//automatically called when an object goes out of scope and when delete is called on a dynamically allocated object
	~LinkedList() {
		Node* currentNode = headNode;
		while (currentNode) {
			Node* tempNode = currentNode;
			currentNode = currentNode->nextNode;
			delete tempNode; //frees allocated memory
		}
	}

	//insert at head function
	void insertAtHead(int value) {
		Node* newNode = new Node(value); 
		//-> is equal to (*newNode).nextNode
		newNode->nextNode = headNode;
		headNode = newNode;
	}
	void insertAtTail(int value) {
		Node* newNode = new Node(value);
		//checks if head node exists and if node makes the new node the head node
		if (!headNode) {
			headNode = newNode;
			return;
		}
		Node* current = headNode;
		while (current->nextNode) {
			current = current->nextNode;
		}
		current->nextNode = newNode;
	}
	//print value
	void display() {
		Node* current = headNode;
		while (current) {
			cout << current->data << "-> ";
			current = current->nextNode;
		}
		cout << "end of list" << endl;
	}
	//search for data value, return index - used for delete
	int search(int value) {
		Node* current = headNode;
		int tempNodeIndex = 0;
		while (current) {
			if (current->data == value) {
				cout << current << ": " << current->data;
				return tempNodeIndex;
			}
			tempNodeIndex++;
			current = current->nextNode;
		}
		return tempNodeIndex;
	}
	//moves node forward
	//delete node by value
	void deleteByValue(int value) {
		int forwardVal = search(value);
		Node* deleteNode = headNode;
		for (int i = 0; i <= forwardVal; i++) {
			if (deleteNode == nullptr) {
				cout << "Reached end of the list before " << forwardVal << " node was reached. ";

			}
			if (i == forwardVal) {
				delete deleteNode;
			}
			deleteNode->nextNode;
		}

	}
	void changeByValue(int value) {
		Node* changedNode = headNode;
		int changeLoc = search(value);
		for (int i = 0; i <= changeLoc; i++) {
			if (changedNode == nullptr) {
				cout << "Reached end of the list before " << changeLoc << " node was reached. ";

			}
			if (i == changeLoc) {
				changedNode->data = value;
			}
			changedNode->nextNode;
		}
	}

};

int main() {
	LinkedList list1;
}