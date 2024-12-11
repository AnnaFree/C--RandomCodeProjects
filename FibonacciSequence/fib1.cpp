#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;
//modifying original vector to insert the sum of each into the array using & (like fibonachi)
void printArray(vector<int> array) {
	for (int num : array) {
		cout << num << " ";
	}
	cout << endl;
}

void AdditionVector(vector<int>& fibArray) {
	//add more space for new numbers
	fibArray.push_back(fibArray.size()/2);
	vector<int> tempArray;
	for (int i = 0; i < fibArray.size()-1; i++) {
		tempArray.push_back(fibArray[i] + fibArray[i + 1]);
		//fibArray.insert(fibArray.begin() + i, (fibArray[i] + fibArray[i + 1]));
		cout << fibArray[i] << " ";
	}
	printArray(tempArray);


}
void FibSequence(vector<int>& fibArray) {
	//the two default starting numbers of fibonacci to get it going
	fibArray[0] = 0;
	fibArray[1] = 1;
	for (int i = 2; i < fibArray.size(); i++) {
		fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
	}
}

int main() {
	cout << "Input the length of the sequence" << endl;
	int index = 0;
	cin >> index;
	vector<int> fibArray(index);
	string ans;
	cout << "Do you have any numbers you would like to put in the array initially?(y/n)" << endl;
	cin >> ans;
	if (ans == "yes" || ans == "y") {
		for(int i = 0; i < index; i++) {
			//text prompt
			if (i == 0) {
				cout << "Type the first number" << endl;
			}
			else if (i == index-1) {
				cout << "Type the last number" << endl;
			}
			else {
				cout << "Type the next number" << endl;
			}
			//number input
			cin >> fibArray[i];
		}
	}else if (ans == "no" || ans == "n") {
		cout << "Array will be a default of random numbers" << endl;
		for (int i = 0; i < index; i++) {
			fibArray[i] = rand() % 10;
		}
	}
	else {
		cout << "input not recognized";
	}
	//print array
	printArray(fibArray);
	cout << endl;
	AdditionVector(fibArray);
	//fibonacci
	cout << "Would you like to reinstate the array with a Fibonacci Sequence?" << endl;
	cin >> ans;
	if (ans == "yes" || ans == "y") {
		FibSequence(fibArray);
		printArray(fibArray);
	}
	else if (ans == "no" || ans == "n") {
		cout << "Array will remain set to previous values" << endl;
	}
	else {
		cout << "input not recognized" << endl;
	}

}