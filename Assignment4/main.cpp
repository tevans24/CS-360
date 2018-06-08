//due to stoi, compile with c++11:  g++ -std=c++0x *.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "BinaryTree.h"
#define TRUE 1
#define FALSE 0

using namespace std;

int main(){

	int value;
	ifstream inFile("data.txt");
	string line;

    BinaryTree *bt = new BinaryTree();

  	while (getline (inFile,line)){
		value = stoi(line);
		cout << "value: " << value << endl;
        bt->addNode(value);
	}

	inFile.close();

    bt->printTree(TRUE);

    bt->search(22);
    bt->search(26);

    delete bt;

}
