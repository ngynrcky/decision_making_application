#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;
using std::getline;

#include <vector>
using std::vector;

#include <cstdlib>
#include <ctime>

void printVector(const vector<string>); // function prototype

int main()
{
	string str;	// variable to take input from user
	vector<string> myVector; // data structure for storing inputs
	
	cout << "Enter your first choice (type 'fin' when done): "; // prompt the user for input
	getline(cin,str); // insert the input into the string variable

	while(str != "fin") { // loop to accept multiple inputs
		if(str == "rm") { // case for removing an incorrect input
			if(myVector.size() > 0) {
				myVector.pop_back(); // used pop_back because of error checking
				printVector(myVector); // display the vector
			}
			else { // size <= 0
				cout << "\nThere are no items to remove\n" << endl;
			}
		}
		else if(str.empty()) { // ignore Enter Key
			cout << "Please input an item before pressing 'return'" << endl;
		}
		else {
			myVector.push_back(str); // insert item into the vector
			printVector(myVector); // display the vector
		}

		cout << "Enter your next choice (type 'fin' when done or 'rm' to remove the last entry): "; // prompt the user
		getline(cin,str); // receive the input
	}

	srand(time(NULL)); // seed the rand function
	if(!myVector.empty()) { // randomly choose an item from the vector
		cout << "\nYour choice is " 
			<< myVector.at(rand() % myVector.size())  // used .at because of boundary checking
			<< endl;
	}
	else { // if no item in the vector
		cout << "\nThere are no choices to choose from" 
			<< endl;
	}

	return 0;
} // end main

// function to display the contents of the vector
void printVector(const vector<string> v)
{
	if(v.size() == 0)
		cout << "\nThe current list is empty" << endl;
	else if(v.size() == 1)
		cout << "\nYour choice so far is:" << endl;
	else
		cout << "\nYour choices are:" << endl;

	for(unsigned i = 0; i < v.size(); i++) { // loop through the vector
		cout << v.at(i)  // print the item to the screen
			<< (i != v.size()-1 ? ",\n" : "\n" );
	}
	cout << endl;
}