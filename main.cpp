#include"bitree.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
	BiTNode*parentNode,*reNode;
	BiTree*bitree;
	bitree=biTree_init();
	char name[10],name1[10];

	 strncpy(name, "s",10);
	curNode_init(bitree);
	bitree_append(bitree, name);
	 strncpy(name, "q",10);
	curNode_init(bitree);
	bitree_append(bitree, name);
	 strncpy(name, "e",10);
	curNode_init(bitree);
	bitree_append(bitree, name);
	 strncpy(name1, "q",10);
	curNode_init(bitree);
	reNode = BiNode_find(bitree, name1);
	printf("%s",reNode->name);
	system("pause");
	return 0;
}