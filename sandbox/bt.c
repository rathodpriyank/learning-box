#include "ds.h"

void printBT (binarytree_t *node, ord_t type) {
    if (node == NULL) 
        return;
    else {
        if (type == INORDER) {
        printBT(node->left, type);
        printf("%d ", node->data);
        printBT(node->right, type);
        } else if (type == PREORDER) {
        printf("%d ", node->data);
        printBT(node->left, type);
        printBT(node->right, type);
        } else {
        printBT(node->left, type);
        printBT(node->right, type);
        printf("%d ", node->data);
        }
    }
}

binarytree_t *addLeaf (binarytree_t *node, int data) {
    if (node == NULL) {
        binarytree_t *newNode = (binarytree_t *) malloc(sizeof(binarytree_t));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    } else {
        if (node->data < data)
            node->left = addLeaf(node->left, data);
        else
            node->right = addLeaf(node->right, data);
    }
    return node;
}

int getMaxDepth (binarytree_t *node) {
    int count = 0;
    if (node == NULL)
        return 0;
    else { 
        int leftLength = getMaxDepth(node->left);
        int rightLength = getMaxDepth(node->right);
        
        if (leftLength > rightLength)
            count = leftLength + 1;
        else
            count = rightLength + 1;
    }
    return count;
}

binarytree_t *getValue(binarytree_t *node, value_t val) {
    binarytree_t *temp = node;
    if (val == MIN) {
        while (temp->left != NULL)
            temp = temp->left;
    } else {
        while (temp->right != NULL)
            temp = temp->right;
    }
    return temp;
}
