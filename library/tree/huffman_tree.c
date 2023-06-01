#include "huffman_tree.h"

HuffmanTree HuffmanTree_CreateHuffmanTree(int arr[], int n) {
    
    //store all points in the forest
    HuffmanTree forest[n];
    HuffmanTree root = NULL;
    for (int i = 0; i < n; ++i) {
        HuffmanTree tmpPos = (HuffmanTree)malloc(sizeof(struct HuffmanTreeNode));
        if (tmpPos == NULL) {
            printf("Out of Space!\n");
            return NULL;
        }
        tmpPos->weight = arr[i];
        tmpPos->left = NULL;
        tmpPos->right = NULL;
        forest[i] = tmpPos;
    }
        
    //Cycle to build Huffman tree
    for (int i = 1; i < n; ++i) {
        int minIndex = -1;
        int subMinIndex;
        for (int j = 0; j < n; ++j) {
            if (forest[j] != NULL && minIndex == -1) {
                minIndex = j;
                continue;
            }
            if (forest[j] != NULL) {
                subMinIndex = j;
                break;
            }
        }

        for (int j = subMinIndex; j < n; ++j) {
            if (forest[j] != NULL) {
                if (forest[j]->weight < forest[minIndex]->weight) {
                    subMinIndex = minIndex;
                    minIndex = j;
                }
                else if (forest[j]->weight < forest[subMinIndex]->weight)
                    subMinIndex = j;
            }
        }

        //create new tree
        root = (HuffmanTree)malloc(sizeof(struct HuffmanTreeNode));
        root->weight = forest[minIndex]->weight + forest[subMinIndex]->weight;

        root->left = forest[minIndex];
        root->right = forest[subMinIndex];

        forest[minIndex] = root;
        forest[subMinIndex] = NULL;
    }
    return root;
}

int HuffmanTree_GetWPL(HuffmanTree tree, int len) {
    if (tree == NULL)
        return 0;
    else {
        if (tree->left == NULL && tree->right == NULL)
            return tree->weight * len;
        else {
            int left = HuffmanTree_GetWPL(tree->left, len + 1);
            int right = HuffmanTree_GetWPL(tree->right, len + 1);
            return left + right;
        }
    }
}

void HuffmanTree_HuffmanCoding(HuffmanTree tree, int len, int arr[]) {
    if (tree != NULL) {
        if (tree->left == NULL && tree->right == NULL) {
            printf("结点为 %d 的字符编码为: ", tree->weight);
            for (int i = 0; i < len; ++i)
                printf("%d", arr[i]);
            printf("\n");
        }
        else {
            arr[len] = 0;
            HuffmanTree_HuffmanCoding(tree->left, len + 1, arr);
            arr[len] = 1;
            HuffmanTree_HuffmanCoding(tree->right, len + 1, arr);
        }
    }
}

static void HuffmanTree_Print2DUtil(HuffmanTree tree, int space) {
    if (tree == NULL)
        return;

    space += 10;

    HuffmanTree_Print2DUtil(tree->right, space);

    putchar('\n');

    for (int i = 10; i < space; ++i)
        putchar(' ');
    if (tree->left == NULL && tree->right == NULL)
        printf("%d\n", tree->weight);
    else
        printf("|_|\n");

    HuffmanTree_Print2DUtil(tree->left, space);
}
void HuffmanTree_PrintTree(HuffmanTree tree) {
    HuffmanTree_Print2DUtil(tree, 0);
}
