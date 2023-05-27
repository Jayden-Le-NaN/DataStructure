#include "search_tree.h"

// the space length of print format
static unsigned int SERACH_TREE_COUNT = 10;

/*
 * @brief           Initialize a search tree
 * @return          head of the new tree
 * @author          JAYDEN_NAN
 */
SearchTree SearchTree_Init(int data) {
    SearchTree newTree = (SearchTree)malloc(sizeof(struct SearchTreeNode));
    if (newTree == NULL) {
        printf("Out of Space!\n");
        return NULL;
    }
    newTree->data = data;
    newTree->left = NULL;
    newTree->right = NULL;
    return newTree;
}

/*
 * @brief           make empty the search tree
 * @parameter tree  the tree which need to be emptied
 * @author          JAYDEN_NAN
 */
SearchTree SearchTree_MakeEmpty(SearchTree tree) {
    if (tree != NULL) {
        SearchTree_MakeEmpty(tree->left);
        SearchTree_MakeEmpty(tree->right);
        free(tree);
    }
    return NULL;
}

/*
 * @brief           find data from the tree
 * @parameter tree  the tree which need to be processed
 * @parameter data  the data which need to be found
 * @author          JAYDEN_NAN
 */
SearchTree SearchTree_Find(SearchTree tree, int data) {
    if (tree != NULL) {
        if (data > tree->data)          //go right
            return SearchTree_Find(tree->right, data);
        else if (data < tree->data)     //go left
            return SearchTree_Find(tree->left, data);
        else 
            return tree;
    }
    return NULL;
}

/*
 * @brief           find the min data of the tree
 * @parameter tree  the tree which need to be processed
 * @author          JAYDEN_NAN
 */
SearchTreePos SearchTree_FindMin(SearchTree tree) {
    if (tree != NULL && tree->left != NULL) 
        return SearchTree_FindMin(tree->left);
    return tree;
}

/*
 * @brief           find the max data of the tree
 * @parameter tree  the tree which need to be processed
 * @author          JAYDEN_NAN
 */
SearchTreePos SearchTree_FindMax(SearchTree tree) {
    if (tree != NULL && tree->right != NULL)
        return SearchTree_FindMin(tree->right);
    return tree;
}

/*
 * @brief           insert data element into the tree
 * @parameter tree  the tree which need to be processed
 * @parameter data  the data which need to be inserted
 * @author           JAYDEN_NAN
 */
SearchTree SearchTree_Insert(SearchTree tree, int data) {
    if (tree != NULL) {
        if (data > tree->data)          //go right
            tree->right = SearchTree_Insert(tree->right, data);
        else if (data < tree->data)     //go left
            tree->left = SearchTree_Insert(tree->left, data);

        // if data is in the tree already; we'll do nothing
    }
    else {
        tree = (SearchTreePos)malloc(sizeof(struct SearchTreeNode));
        if (tree == NULL) {
            printf("Out of Space!\n");
            return NULL;
        }
        tree->data = data;
        tree->left = NULL;
        tree->right = NULL;
    }
    return tree;
}

/*
 * @brief           delete data from the tree
 * @parameter tree  the tree which need to be processed
 * @parameter data  the data which need to be deleted
 * @author          JAYDEN_NAN
 */
SearchTree SearchTree_Delete(SearchTree tree, int data) {
    if (tree == NULL) {
        printf("Data not Found!\n");
    }
    else if (data < tree->data)     //go left
        tree->left = SearchTree_Delete(tree->left, data);
    else if (data > tree->data)     //go right
        tree->right = SearchTree_Delete(tree->right, data);
    else if (tree->right && tree->left) {
        //two children
        //found element to be deleted
        //replace with smallest in right subtree
        tree->data = SearchTree_FindMin(tree->right)->data;
        tree->right = SearchTree_Delete(tree->right, data);
    }
    else {
        //only one or zero children
        SearchTreePos delPos = tree;
        if (tree->left == NULL)
            tree = tree->right; 
        else if (tree->right == NULL)
            tree = tree->left;
        free(delPos);
    }
    return tree;
}

int SearchTree_Retrieve(SearchTreePos pos) {
    if (pos == NULL)
        return -1;
    else
        return pos->data;
}

static void SearchTree_Print2DUtil(SearchTree tree, int space) {
    //Base case
    if (tree == NULL)
        return;

    //Increase distance between levels
    space += SERACH_TREE_COUNT;

    //Process right child first
    SearchTree_Print2DUtil(tree->right, space);

    //print current node after space count
    putchar('\n');
    for (int i = SERACH_TREE_COUNT; i < space; ++i) {
        putchar(' ');
    }
    printf("%d\n", tree->data);

    //Process left child
    SearchTree_Print2DUtil(tree->left, space);
}

void SearchTree_PrintTree(SearchTree tree) {
    SearchTree_Print2DUtil(tree, 0);
}

void SearchTree_SetPrintCount(const unsigned int cnt) {
    SERACH_TREE_COUNT = cnt;
}
