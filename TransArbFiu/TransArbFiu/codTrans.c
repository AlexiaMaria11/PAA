#include <stdio.h>
#include <stdint.h>
#include "TransArbFiu.h"


TTree InitTree(TTree a) {
	for (int i = 0; i < MAXNODES; i++) {
		a.nodes[i].prim_fiu = 0;
		a.nodes[i].frate_dreapta = 0;
		a.nodes[i].key = 0;
	}
	a.size = 0;
	return a;
}

TTree InsertNode(TTree a, TNodeRef  prim_fiu, TNodeRef  frate_dreapta, TKey key) {
	a.size++;
	a.nodes[a.size].key = key;
	a.nodes[a.size].prim_fiu = prim_fiu;
	a.nodes[a.size].frate_dreapta = frate_dreapta;
	return a;
}

void printArray(TTree a) {
	printf("\nIndex:        ");
	for (uint8_t i = 0; i <= a.size; i++) {
		printf("%10d ", i);
	}
	printf("\nKey:          ");
	for (uint8_t i = 0; i <= a.size; i++) {
		printf("%10d ", a.nodes[i].key);
	}
	printf("\nPrim_fiu:     ");
	for (uint8_t i = 0; i <= a.size; i++) {
		printf("%10d ", a.nodes[i].prim_fiu);
	}
	printf("\nFrate_dreapta:");
	for (uint8_t i = 0; i <= a.size; i++) {
		printf("%10d ", a.nodes[i].frate_dreapta);
	}
	printf("\n------------------------------------");
}

void printNode(TNode node, char* message) {
	printf("\n%s Key: %d, Prim_fiu: %d, Frate_dreapta:%d\n", message, node.key, node.prim_fiu, node.frate_dreapta);
}

TNodeRef getRoot(TTree a) {
	if (a.size < 1) return 0;
	return 1;
}
TNodeRef findNodeIndex(TTree a, TNode node) {
	for (uint8_t i = 0; i <= a.size; i++) {
		if (a.nodes[i].key == node.key && a.nodes[i].prim_fiu == node.prim_fiu) return i;
	}
	return 0;
}

TKey nodeKey(TTree a, TNodeRef noderef) {
	if (noderef > a.size) return 0;
	return a.nodes[noderef].key;
}

TNodeRef firstChild(TTree a, TNodeRef index) {
	return a.nodes[index].prim_fiu;
}

TNodeRef rightSibling(TTree a, TNodeRef noderef) {
	return a.nodes[noderef].frate_dreapta;
}

//TNode nodeByRef(TTree a, TNodeRef noderef) {
//	return a.nodes[noderef];
//}
//
//TTree deleteNode(TTree a, TNodeRef noderef) {
//	a.nodes[noderef].key = 0;
//	a.nodes[noderef].parent = 0;
//
//	for (TNodeRef i = noderef; i <= a.size; i++) {
//		if (a.nodes[i].parent == noderef) {
//			a.nodes[i].key = 0;
//			a.nodes[i].parent = 0;
//		}
//	}
//
//	for (TNodeRef i = noderef; i <= a.size; ) {
//		if (a.nodes[i].parent == 0 && a.nodes[i].key == 0) {
//			for (TNodeRef j = i + 1; j <= a.size; j++) {
//				if (a.nodes[j].parent > i) a.nodes[j].parent--;
//				a.nodes[j - 1] = a.nodes[j];
//
//			}
//			a.size--;
//		}
//		if (a.nodes[i].parent != 0 && a.nodes[i].key != 0) i++;
//	}
//	printArray(a);
//
//	return a;
//}

void preOrderDo(TTree a, TNodeRef root) {
	printf("%d, ", nodeKey(a, root));
	TNodeRef fc = firstChild(a, root);
	if (fc) preOrderDo(a, fc);

	TNodeRef rs = fc;
	while ((rs = rightSibling(a, rs))) {
		preOrderDo(a, rs);
	}
}

void inOrderDo(TTree a, TNodeRef root) {
	TNodeRef fc = firstChild(a, root);
	if (!fc) {
		printf("%d, ", nodeKey(a, root));
		return;
	}
	inOrderDo(a, fc);
	printf("%d, ", nodeKey(a, root));
	TNodeRef  rs = fc;
	while ((rs = rightSibling(a, rs))) {
		inOrderDo(a, rs);
	}

}

void postOrderDo(TTree a, TNodeRef root) {
	if (!root) return;
	TNodeRef fc = firstChild(a, root);
	postOrderDo(a, fc);
	TNodeRef rs = fc;
	while ((rs = rightSibling(a, rs))) {
		postOrderDo(a, rs);
	}
	printf("%d, ", nodeKey(a, root));
}

void preOrder(TTree a) {
	if (a.size < 1) return;
	preOrderDo(a, getRoot(a));
}
void inOrder(TTree a) {
	if (a.size < 1) return;
	inOrderDo(a, getRoot(a));
}
void postOrder(TTree a) {
	if (a.size < 1) return;
	postOrderDo(a, getRoot(a));
}

TNodeB* transform(TTree t, TNodeRef noderef)
{
	if (noderef == 0) return NULL;
	TNodeB* bin = (TNodeB*)malloc(sizeof(TNodeB));
	if (bin == NULL)
	{
		printf("Eroare la alocare\n");
		exit(-1);
	}
	printf("%d ", t.nodes[noderef].key);
	bin->key = 1;
	bin->left = transform(t, firstChild(t, noderef));
	bin->right = transform(t, rightSibling(t, noderef));
	return bin;
}

void preOrderBin(TNodeB* root)
{
	if (root == NULL) return;
	printf("%d ", root->key);
	preOrderBin(root->left);
	preOrderBin(root->right);
}

void freeTree(TNodeB* root)
{
	if (root == NULL) return;
	freeTree(root->left);
	freeTree(root->right);
	free(root);
}