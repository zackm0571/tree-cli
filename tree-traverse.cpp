#import <iostream>
#import <stdio.h>
#import <string.h>
#import <assert.h>
#include <sstream>
using namespace std;

class Node {
	public:
	int val;
	Node *n1, *n2;
};


Node* generateTree(Node *root, int seed){
	int n = seed;
	if(n <= 0) return NULL;
	root->val = n;
	
	root->n1 = generateTree(new Node(), --n);
	root->n2 = generateTree(new Node(), --n);
	return root;
}

void printNode(string tag, int val, int gap, int newline){
	for(int i = 0; i < newline; i++){
		printf("%s", "\n");
	}

	for(int i = 0; i < gap; i++){
		printf("%s", " ");
	}

	printf("%s: %d",tag.c_str(), val);
	
	for(int i = 0; i < newline; i++){
		printf("%s", "\n");
	}

}

void traverseTree(Node *n){
	if(n == NULL) return;
	printNode("Node value", n->val, 5 , 1);
	if(n->n1 != NULL){
		printNode("n1 value", n->n1->val, 10, 1);
	}
	else{
		printNode("n1 is NULL", -1, 10, 1);
	}

	if(n->n2 != NULL){
		printNode("n2 value", n->n2->val, 10, 1);
	}
	else{
		printNode("n2 is NULL", -1, 10, 1);
	}

	traverseTree(n->n1);
	traverseTree(n->n2);
}

int main(int argc, char *argv[]){
	assert(argc == 2);

	stringstream s(argv[1]);
	int seedArg;
	s >> seedArg;

	Node *root = new Node();
	root = generateTree(root, seedArg);
	traverseTree(root);	
	return 0;
}
