#include"bitree.h"
BiTree*biTree_init()
{
	BiTree*bitree;
	bitree = (BiTree*)malloc(sizeof(BiTree));
	bitree->parentNode = NULL;
	bitree->curNode = NULL;
	
	return bitree;
}
void curNode_init(BiTree*bitree)
{
	bitree->curNode = bitree->parentNode;
}
BiTNode* init_bitNode(){

	BiTNode*bitNode;
	bitNode = (BiTNode*)malloc(sizeof(BiTNode));
	//bitNode = NULL;
	bitNode->lchild = NULL;
	bitNode->rchild = NULL;
	return bitNode;
}
int bitree_append(BiTree*bitree, char*name)
{
	BiTNode* bitnode,*tempnode;
	int judge;
	bitnode = init_bitNode();
	tempnode = init_bitNode();
	strncpy(bitnode->name, name,10);
	
	if (bitree->curNode==NULL)
	{
		bitree->parentNode = bitnode;
		bitree->curNode = bitnode;
		return 1;
	}
	else{
		judge = strcmp(name, bitree->curNode->name);
	}
	if (judge > 0)
	{
		if (bitree->curNode->lchild == NULL)
		{
			bitree->curNode->lchild = bitnode;
			return 1;
		}
		else{
			bitree->curNode = bitree->curNode->lchild;
			bitree_append(bitree, name);
		}
	}
	else if (judge<0)
	{
		if (bitree->curNode->rchild == NULL)
		{
			bitree->curNode->rchild = bitnode;
			return 1;
		}
		else{
			bitree->curNode = bitree->curNode->rchild;
			bitree_append(bitree,name);
		}
	}
	else {
		if (judge == 0 && bitree->curNode->lchild != NULL)
		{

			tempnode = bitree->curNode->lchild;
			bitree->curNode->lchild = bitnode;
			bitree->curNode = bitree->parentNode->lchild;
			bitree->curNode->lchild = tempnode;
			return 1;
		}
		else
		{
			bitree->curNode->lchild = bitnode;
			return 1;
		}
	} 
	return 1;
}
BiTNode* BiNode_find(BiTree*bitree, char*name)
{
	
	int judge;
	BiTNode*tempNode;
	tempNode = (BiTNode*)malloc(sizeof(BiTNode));
	if (bitree->curNode == NULL)
	{
		return bitree->curNode;
	}
	judge = strcmp(name, bitree->curNode->name);
	if (judge > 0)
	{
		bitree->curNode = bitree->curNode->lchild;
		BiNode_find(bitree, name);
	}
	else if (judge < 0)
	{
		bitree->curNode = bitree->curNode->rchild;
		BiNode_find(bitree, name);
	}
	else if(judge==0)
	{
		return bitree->curNode; // 返回不完整 ；加栈
	}
}
