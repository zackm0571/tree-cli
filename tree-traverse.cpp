#import <iostream>
#import <stdio.h>
#import <string.h>
#import <assert.h>
#include <sstream>
#include <vector>
#include <stdlib.h> 
#include <time.h>
using namespace std;

class Node {
	public:
	int val;
	vector<Node*> vertices;
};

Node* generateNode(int val){
	Node* n = new Node();
	n->val = val;
	return n;
}

Node* generateTree(Node *root, int seed){
	if(root == NULL) return NULL;
	int n = seed;
	if(n > 0){
		root->val = n;
		int vertices = rand() % seed * 2+ seed;
		root->vertices = vector<Node*>(vertices);
		for(int i = 0; i < vertices; i++){
			Node *vertice = generateNode(n + i + vertices);
			root->vertices[i] = vertice;
		}

		for(int k = 0; k < vertices; k++){
			generateTree(root->vertices[k], --n);
		}
	}
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

	for(int i = 0; i < n->vertices.size(); i++){
		Node *vertice = n->vertices[i];
		if(vertice != NULL){
			printNode("Vertice value",vertice->val, 10, 1);
		}
		else{
			printNode("Vertice is NULL", -1, 10, 1);
		}
	}
	
	for(int k = 0; k < n->vertices.size(); k++){
		traverseTree(n->vertices[k]);
	}
}

int main(int argc, char *argv[]){
	assert(argc == 2);

	stringstream s(argv[1]);
	int seedArg;
	s >> seedArg;

	srand(time(NULL));

	Node *root = new Node();
	root = generateTree(root, seedArg);
	traverseTree(root);	
	return 0;
}
