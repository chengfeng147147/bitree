#include<stdlib.h>
#include<string.h>
#define NULL 0
typedef struct _biTNode{

	char userblack[10],userwhite[10];
	int offset;
	_biTNode *lchild, *rchild,*mchild;

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
int bitree_append(BiTree*bitree, char*name, int*offset);
BiTNode* BiNode_find(BiTree*bitree, char*name);
