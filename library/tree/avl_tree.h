#ifndef AVL_TREE_H_
#define AVL_TREE_H_
#include <stdlib.h>
#include <stdio.h>
#include "../basic_function/basic_function.h"

struct AvlTreeNode {
    int data;
    int height;
    struct AvlTreeNode* left;
    struct AvlTreeNode* right;
};

typedef struct AvlTreeNode* AvlTreePos;
typedef struct AvlTreeNode* AvlTree;

AvlTree         AvlTree_Init(int data);
AvlTree         AvlTree_MakeEmpty(AvlTree tree);
AvlTreePos      AvlTree_Find(AvlTree tree, int data);
AvlTreePos      AvlTree_FindMin(AvlTree tree);
AvlTreePos      AvlTree_FindMax(AvlTree tree);
AvlTree         AvlTree_Insert(AvlTree tree, int data);
AvlTree         AvlTree_Delete(AvlTree tree, int data);
int             AvlTree_Retrieve(AvlTreePos pos);
void            AvlTree_PrintTree(AvlTree tree);
void            AvlTree_SetPrintCount(const unsigned int cnt);

#endif
