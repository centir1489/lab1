#pragma once
#ifndef AVLTREE
#define AVLTREE
#include<iostream>
#include"QueuePlusPlus.h"

struct ANode{
    int Data;
	size_t height;
	ANode* Left;
	ANode* Right;
	ANode(int Val) : Data(Val), Left(0), Right(0), height(1) {}
};

struct AVLTree{
	ANode* Root;
};

QueuePP<int> AVLTreeToQueue(ANode* NTree);

size_t Height(ANode* Root);
void FixHeight(ANode* NTree);
ANode* RightRotate(ANode* NTree);
ANode* LeftRotate(ANode* NTree);
ANode* BalanceNode(ANode* NTree);


ANode* TPUSH(ANode* NTree, int Val);
ANode* TDEL(ANode* NTree, int Val);
int TFIND(ANode* NTree, int Val);
void TGET(ANode* NTree);


#endif