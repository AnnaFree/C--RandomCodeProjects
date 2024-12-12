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
	LinkedList() : headNode(nullptr) {}

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
		int tempNodeIndex = 0; bool foundValue = false;
		while (current) {
			if (current->data == value) {
				cout << "Search value found at memory address: ";
				cout << current << ": - Value is: " << current->data << endl;
				foundValue == true;
				return tempNodeIndex;
			}
			tempNodeIndex++;
			current = current->nextNode;
		}
		if (foundValue == false) {
			cout << "value not found" << endl;
		}
		return tempNodeIndex;
	}
	//moves node forward
	//delete node by value
	void deleteByValue(int value) {
		Node* current = headNode;
		Node* previous = nullptr;
		while (current != nullptr) {
			if (current->data == value)
			{
				//rearrange leftover nodes
				if (previous != nullptr) {
					previous->nextNode = current->nextNode;
				}
				else {
					headNode = current->nextNode;
				}
				delete current;
				cout << "Target value found and deleted" << endl;
				return;
			}
			else {
				//shift along in searcg
				previous = current;
				current = current->nextNode;
			}
		}
		cout << "Value not found in the list" << endl;

	}
	void changeByValue(int value, int newValue) {
		Node* current = headNode;
		while (current != nullptr) {
			if (current->data == value) {
				current->data = newValue;
				cout << "Target value found and changed" << endl;
				return;
			}
			else {
				//shift along in search
				current = current->nextNode;
			}
		}
		cout << "Value not found in the list" << endl;

	}
	void numericalSort() {
		if (headNode == nullptr) return; // Handle empty list
		bool sorted = false; 
		while (!sorted) { 
			sorted = true; // Assume the list is sorted initially 
			Node* current = headNode; 
			Node* tempAhead = headNode->nextNode; 
			while (tempAhead != nullptr) { 
				if (current->data > tempAhead->data) { 
					// Swap the values 
					int placeholder = current->data; 
					current->data = tempAhead->data; 
					tempAhead->data = placeholder; 
					sorted = false; 
					cout << current->data << " and " << tempAhead->data << " values switched" << endl; 
				} 
				
				current = tempAhead; 
				tempAhead = tempAhead->nextNode;
			}
		}
	}
};

int main() {
	LinkedList list1;
	list1.insertAtHead(10);
	list1.insertAtHead(20);
	list1.insertAtHead(30);

	list1.display();

	list1.insertAtTail(43);
	list1.insertAtTail(32);

	list1.search(30);
	list1.search(100);

	//delete test
	list1.insertAtTail(70);
	list1.display();
	list1.deleteByValue(20);
	list1.display();
	list1.changeByValue(30, 61);
	list1.display();

	list1.numericalSort();
	list1.display();


	return 0;
}