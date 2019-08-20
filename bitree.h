#include<stdlib.h>
#include<string.h>
#define NULL 0
typedef struct _biTNode{

	char name[10];
	_biTNode *lchild, *rchild;

};
typedef struct _biTNode BiTNode;
typedef struct _biTree{
	
	BiTNode*parentNode;
	BiTNode*curNode;
};
typedef struct _biTree BiTree;
BiTree*biTree_init();
void curNode_init(BiTree*bitree);
BiTNode* init_bitNode();
int bitree_append(BiTree*bitree, char*name);
BiTNode* BiNode_find(BiTree*bitree, char*name);
