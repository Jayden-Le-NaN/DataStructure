#include <stdio.h>
#include "huffman_tree.h"
int main() {
    int arr[] = {31, 16, 10, 8, 11, 20, 4};
    HuffmanTree tree = HuffmanTree_CreateHuffmanTree(arr, 7);
    HuffmanTree_PrintTree(tree);
    int buffArr[32];
    HuffmanTree_HuffmanCoding(tree, 0, buffArr);
    return 0;
}
