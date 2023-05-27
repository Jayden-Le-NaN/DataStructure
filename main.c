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
    printf("------------------------------");
    SearchTree_Delete(searchTree, 65);
    SearchTree_Delete(searchTree, 2);
    SearchTree_PrintTree(searchTree);
    SearchTree_MakeEmpty(searchTree);
    return 0;
}
