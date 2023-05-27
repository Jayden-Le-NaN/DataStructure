/*
 * @author      JAYDEN_NAN
 * @time        2023-05-27 17:23
 */
#ifndef SEARCH_TREE_H_
#define SEARCH_TREE_H_

#include <stdlib.h>
#include <stdio.h>

struct SearchTreeNode {
    int data;
    struct SearchTreeNode* left;
    struct SearchTreeNode* right;
};
typedef struct SearchTreeNode* SearchTreePos;
typedef struct SearchTreeNode* SearchTree;

SearchTree      SearchTree_Init(int data);
SearchTree      SearchTree_MakeEmpty(SearchTree tree);
SearchTree      SearchTree_Find(SearchTree tree, int data);
SearchTreePos   SearchTree_FindMin(SearchTree tree);
SearchTreePos   SearchTree_FindMax(SearchTree tree);
SearchTree      SearchTree_Insert(SearchTree tree, int data);
SearchTree      SearchTree_Delete(SearchTree tree, int data);
int             SearchTree_Retrieve(SearchTreePos pos);
void            SearchTree_PrintTree(SearchTree tree);
void            SearchTree_SetPrintCount(const unsigned int cnt);
#endif

