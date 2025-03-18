#include<stdint.h>

#define MAXNODES 100

typedef uint8_t TKey;

typedef struct {
	uint8_t prim_fiu, frate_dreapta;
	TKey key;
}TNode;

typedef uint8_t TNodeRef;

typedef struct {
	TNode nodes[MAXNODES];
	uint8_t size; //tree size = number of nodes in the tree	
}TTree;

TTree InitTree(TTree a);

TTree InsertNode(TTree a, TNodeRef  prim_fiu, TNodeRef  frate_dreapta, TKey key);

void printArray(TTree a);

void printNode(TNode node, char* message);

TKey nodeKey(TTree a, TNodeRef noderef);

TNode nodeByRef(TTree a, TNodeRef noderef);

TTree deleteNode(TTree a, TNodeRef noderef);

TNodeRef firstChild(TTree a, TNodeRef noderef);

TNodeRef rightSibling(TTree a, TNodeRef noderef);

void preOrder(TTree a);
void inOrder(TTree a);
void postOrder(TTree a);