#ifndef HUFFMAN_TREE_H_
#define HUFFMAN_TREE_H_
#include "../common.h"
struct HuffmanTreeNode {
    int weight;
    struct HuffmanTreeNode* left;
    struct HuffmanTreeNode* right;
};

typedef struct HuffmanTreeNode* HuffmanTree;

HuffmanTree HuffmanTree_CreateHuffmanTree(int arr[], int n);
int         HuffmanTree_GetWPL(HuffmanTree tree, int len);
void        HuffmanTree_HuffmanCoding(HuffmanTree tree, int len, int arr[]);
void        HuffmanTree_PrintTree(HuffmanTree tree);

#endif
