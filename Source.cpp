// Muhammad Abed
// CSCI 3080-001
// Lab 2, ola2
// 11/4/15

#include <iostream>
#include <iomanip>

// Array maximums
const int ROWS = 10;
const int REP_COLS = 3;
const int ADJ_COLS = 10;

// Function prototypes
void initializeTree (int arrayRep[][REP_COLS], int adjMatrix[][ADJ_COLS], int& numNodes);
void displayTree (int arrayRep[][REP_COLS], int adjMatrix[][ADJ_COLS], int numNodes);
void traversePre (int arrayRep[][REP_COLS], int row, int col);

using namespace std;

int main () {
	int arrayRep[ROWS][REP_COLS];
	int adjMatrix[ROWS][ADJ_COLS];
	int numNodes = 0;

	initializeTree(arrayRep, adjMatrix, numNodes);
	displayTree(arrayRep, adjMatrix, numNodes);
	traversePre(arrayRep, 0, 0);

	return 0;
}

// Reads in a left, right, and middle child array representation for a ternay tree,
// then creates an adjacency matrix based on the tree
void initializeTree (int arrayRep[][REP_COLS], int adjMatrix[][ADJ_COLS], int& numNodes) {
	// Get the number of nodes and the array representation from user input
	cout << "Enter the number of nodes in the graph (no more than 10, at least 1): \n"; 
	while (!(numNodes >= 1 && numNodes <= 10))
		cin >> numNodes;
	cout << "Enter the array representation of the tree: \n";
	for (int i = 0; i < numNodes; i++) {
		cin >> arrayRep[i][0] >> arrayRep[i][1] >> arrayRep[i][2];
	}

	// Initialize the adjaceny matrix to 0
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < ADJ_COLS; j++) {
			adjMatrix[i][j] = 0;
		}
	}

	// Construct the adjacency matrix based on the array representation
	for (int i = 0; i < numNodes; i++) {
		for (int j = 0; j < REP_COLS; j++) {
			if (arrayRep[i][j] != -1)
				adjMatrix[i][arrayRep[i][j]-1] = 1;
		}
	}
}

// Displays the adjacency matrix and array representation
void displayTree (int arrayRep[][REP_COLS], int adjMatrix[][ADJ_COLS], int numNodes) {
	// Display the adjacency matrix
	cout << "The adjacency matrix is: \n\n";
	for (int i = 0; i < numNodes; i++) {
		for (int j = 0; j < numNodes; j++) {
			cout << adjMatrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;

	// Display the array representation
	cout << "The left child, middle child, right child array representation is: \n\n";
	for (int i = 0; i < numNodes; i++) {
		
		for (int j = 0; j < REP_COLS; j++) {
			cout << setw(3);
			cout << arrayRep[i][j];
		}
		cout << endl;
	}
	cout << endl << endl;
}

// Displays a pre-order traversal of the tree
void traversePre (int arrayRep[][REP_COLS], int row, int col) {
	
}
