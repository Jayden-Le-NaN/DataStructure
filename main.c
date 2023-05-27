#include <stdio.h>
#include "./library/headfile.h"
int main() {
    //---------------Search Tree Test---------------//
    SearchTree searchTree = SearchTree_Init(20);
    SearchTree_Insert(searchTree, 18);
    SearchTree_Insert(searchTree, 2);
    SearchTree_Insert(searchTree, 24);
    SearchTree_Insert(searchTree, 16);
    SearchTree_Insert(searchTree, 65);
    SearchTree_PrintTree(searchTree);
    printf("------------------------------\n");
    SearchTree_Delete(searchTree, 65);
    SearchTree_Delete(searchTree, 2);
    SearchTree_PrintTree(searchTree);
    SearchTree_MakeEmpty(searchTree);
    printf("------------------------------\n");

    //---------------Avl Tree Test---------------//
    AvlTree avlTree = AvlTree_Init(20);
    AvlTree_Insert(avlTree, 3);
    AvlTree_Insert(avlTree, 28);
    AvlTree_Insert(avlTree, 7);
    AvlTree_Insert(avlTree, 63);
    AvlTree_Insert(avlTree, 24);
    AvlTree_Insert(avlTree, 13);
    AvlTree_Insert(avlTree, 69);
    AvlTree_Insert(avlTree, 67);
    AvlTree_PrintTree(avlTree);
    printf("------------------------------\n");
    AvlTree_Delete(avlTree, 24);
    AvlTree_Delete(avlTree, 69);
    AvlTree_PrintTree(avlTree);
    printf("------------------------------\n");
    return 0;
}
