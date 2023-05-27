#include "avl_tree.h"

//the space length of print format
static unsigned int AVL_TREE_COUNT = 10;

/*
 * @brief           return the height of the tree
 * @parameter tree  the tree which need to be processed
 * @return          the height of the tree
 * @author          JAYDEN_NAN
 */
static int AvlTree_Height(AvlTree tree) {
    if (tree == NULL)
        return -1;
    return tree->height;
}

/*
 * @brief           This function can be called only if k2 has a left child
 *                  Perform a rotate between a node(k2) and its left child
 *                  update heights, then return new root
 * @parameter k2    the root of the tree
 * @author          JAYDEN_NAN
 */
static AvlTree AvlTree_SingleRotateWithLeft(AvlTreePos k2) {
    //rotate
    AvlTreePos k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    //update height data
    k2->height = BF_maxInt(AvlTree_Height(k2->left), AvlTree_Height(k2->right)) + 1;
    k1->height = BF_maxInt(AvlTree_Height(k1->left), k2->height) + 1;

    //new root
    return k1;
}

/*
 * @brief           This function can be called only if k2 has a right child
 *                  Perform a rotate between a node(k2) and its right child
 *                  update heights, then return new root
 * @parameter k2    the root of the tree
 * @author          JAYDEN_NAN
 */
static AvlTree AvlTree_SingleRotateWithRight(AvlTreePos k2) {
    //rotate
    AvlTreePos k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;

    //update height data
    k2->height = BF_maxInt(AvlTree_Height(k2->left), AvlTree_Height(k2->right)) + 1;
    k1->height = BF_maxInt(k2->height, AvlTree_Height(k2->right)) + 1;
    
    //new root
    return k1;
}

/*
 * @brief           This function can be called only if k3 has a left child and
 *                  its left has a right child
 *                  Do the left-right double rotation
 *                  Update heights, then return new root
 * @parameter k3    the root of the tree
 * @author          JAYDEN_NAN
 */
static AvlTree AvlTree_DoubleRotateWithLeft(AvlTreePos k3) {
    k3->left = AvlTree_SingleRotateWithRight(k3->left);

    return AvlTree_SingleRotateWithLeft(k3);
}

/*
 * @brief           This function can be called only if k3 has a right child and
 *                  its right has a left child
 *                  Do the right-left double rotation
 *                  Update heights, then return new root
 * @parameter k3    the root of the tree
 * @author          JAYDEN_NAN
 */
static AvlTree AvlTree_DoubleRotateWithRight(AvlTreePos k3) {
    k3->right = AvlTree_SingleRotateWithLeft(k3->right);
    
    return AvlTree_SingleRotateWithRight(k3);
}

/*
 * @brief           Initialize a avl tree
 * @return          head of the new tree
 * author           JAYDEN_NAN
 */
AvlTree AvlTree_Init(int data) {
    AvlTree newTree = (AvlTree)malloc(sizeof(struct AvlTreeNode));
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
 * @brief           release the data in the tree
 * @parameter tree  the tree which need to be emptied
 * @author          JAYDEN_NAN
 */
AvlTree AvlTree_MakeEmpty(AvlTree tree) {
    if (tree != NULL) {
        AvlTree_MakeEmpty(tree->left);
        AvlTree_MakeEmpty(tree->right);
        free(tree);
    }
    return NULL;
}

/*
 * @brief           find data frome the tree
 * @parameter tree  the tree which need to be processed
 * @parameter data  the data which need to be found
 * @author          JAYDEN_NAN
 */
AvlTreePos AvlTree_Find(AvlTree tree, int data) {
    if (tree != NULL) {
        if (data > tree->data)          //go right
            return AvlTree_Find(tree->right, data);
        else if (data < tree->data)     //go left
            return AvlTree_Find(tree->left, data);
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
AvlTreePos AvlTree_FindMin(AvlTree tree) {
    if (tree != NULL && tree->left != NULL)
        return AvlTree_FindMin(tree->left);
    return tree;
}

/*
 * @brief           find the max data of the tree
 * @parameter tree  the tree which need to be processed
 * @author          JAYDEN_NAN
 */
AvlTreePos AvlTree_FindMax(AvlTree tree) {
    if (tree != NULL && tree->right != NULL)
        return AvlTree_FindMax(tree->right);
    return tree;
}

/*
 * @brief           insert date element into the tree         
 * @parameter tree  the tree which need to be processed
 * @parameter data  the data which need to be inserted
 * @author          JAYDEN_NAN
 */
AvlTree AvlTree_Insert(AvlTree tree, int data) {
    if (tree != NULL) {
        if (data > tree->data){          //go right
            tree->right = AvlTree_Insert(tree->right, data);
            if ((AvlTree_Height(tree->right) - AvlTree_Height(tree->left) == 2)) {
                if (data > tree->right->data) 
                    tree = AvlTree_SingleRotateWithRight(tree);
                else if (data < tree->right->data)
                    tree = AvlTree_DoubleRotateWithRight(tree);
            }
        }
        else if (data < tree->data){     //go left
            tree->left = AvlTree_Insert(tree->left, data);
            if ((AvlTree_Height(tree->left) - AvlTree_Height(tree->right)) == 2) {
                if (data < tree->left->data)
                    tree = AvlTree_SingleRotateWithLeft(tree);
                else if (data > tree->right->data)
                    tree = AvlTree_DoubleRotateWithLeft(tree);
            }
        }

        // if data is in the tree already, we'll do nothing
    }

    else {
        tree = (AvlTreePos)malloc(sizeof(struct AvlTreeNode));
        if (tree == NULL) {
            printf("Out of Space!!!\n");
            return NULL;
        }
        tree->data = data;
        tree->left = NULL;
        tree->right = NULL;
    }
    tree->height = BF_maxInt(AvlTree_Height(tree->left), AvlTree_Height(tree->right)) + 1;
    return tree;
}

/*
 * @brief           delete data from the tree
 * @parameter tree  the tree which need to be processed
 * @parameter data  the date which need to be deleted
 * @author          JAYDEN_NAN
 */
AvlTree AvlTree_Delete(AvlTree tree, int data) {
    if (tree == NULL)
        printf("Data Not Found!\n");
    else if (data > tree->data)        //go right
        tree->right = AvlTree_Delete(tree->right, data);

    
    else if (data < tree->data)       //go left
        tree->left = AvlTree_Delete(tree->left, data);
    
    else if (tree->right && tree->left) {
        //two children
        //found element to be deleted
        //replace with smallest in the right subtree
        tree->data = AvlTree_FindMin(tree->right)->data;
        tree->right = AvlTree_Delete(tree->right, tree->data);
    }
    else {
        //only one or zero children
        AvlTreePos delPos = tree;
        if (tree->left == NULL)
            tree = tree->right;
        else if (tree->right == NULL)
            tree = tree->left;
        free(delPos);
    }
    
    //Prevent segment error
    if (tree == NULL)
        return NULL;
    if (AvlTree_Height(tree->left) - AvlTree_Height(tree->right) == 2) {
        if (AvlTree_Height(tree->left->left) - AvlTree_Height(tree->left->right) == 1)
            tree = AvlTree_SingleRotateWithLeft(tree);
        else
            tree = AvlTree_DoubleRotateWithLeft(tree);
    }
    else if (AvlTree_Height(tree->right) - AvlTree_Height(tree->left) == 2) {
        if (AvlTree_Height(tree->right->right) - AvlTree_Height(tree->right->left) == 1)
            tree = AvlTree_SingleRotateWithRight(tree);
        else
            tree = AvlTree_DoubleRotateWithRight(tree);
    }
    return tree;
}

int AvlTree_Retrieve(AvlTreePos pos) {
    if (pos == NULL)
        return -1;
    return pos->data;
}

static void AvlTree_Print2DUtil(AvlTree tree, int space) {
    //Base case
    if (tree == NULL)
        return;

    //Increase distance between levels
    space += AVL_TREE_COUNT;

    //Process right child first
    AvlTree_Print2DUtil(tree->right, space);

    //print current node after space count
    putchar('\n');
    for (int i = AVL_TREE_COUNT; i < space; ++i)
        putchar(' ');
    printf("%d\n", tree->data);

    //Process left child 
    AvlTree_Print2DUtil(tree->left, space);
}

void AvlTree_PrintTree(AvlTree tree) {
    AvlTree_Print2DUtil(tree, 0);
}

void AvlTree_SetPrintCount(const unsigned int cnt) {
    AVL_TREE_COUNT = cnt;
}

