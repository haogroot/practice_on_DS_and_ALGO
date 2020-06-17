#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

struct treeNode* newNode(int key)
{
    struct treeNode *node = (struct treeNode*) malloc (sizeof(struct treeNode));
    node->data = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct treeNode* insert (struct treeNode *tree, int key)
{
    if(tree == NULL)
        return newNode(key);
    if(key > tree->data)
        tree->right = insert(tree->right, key);
    else
        tree->left = insert(tree->left, key);
    /* return the unchanged node */
    return tree; 
}

void inOrder (struct treeNode *tree)
{
    if (tree != NULL)
    {
        inOrder (tree->left);
        printf ("%d ", tree->data);
        inOrder (tree->right);
    }
}

void preOrder (struct treeNode *tree)
{
    if (tree != NULL)
    {
        printf ("%d ", tree->data);
        preOrder (tree->left);
        preOrder (tree->right);
    }
}

void postOrder (struct treeNode *tree)
{
    if (tree != NULL)
    {
        postOrder (tree->left);
        postOrder (tree->right);
        printf ("%d ", tree->data);
    }
}

int main()
{
    struct treeNode *root = NULL;
    root = insert(root, 50);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 80);
    root = insert(root, 30);
    root = insert(root, 90);
    root = insert(root, 70);
    printf("InOrder traversal:\n");
    inOrder (root); 
    printf("\n");

    printf("PreOrder traversal:\n");
    preOrder (root); 
    printf("\n");
    
    printf("PostOrder traversal:\n");
    postOrder (root); 
    printf("\n");
    return 0;
}
