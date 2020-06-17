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

/**
 * calculate the height of binary tree.
 * \return the height of tree.
 */
int height (struct treeNode *root)
{
    if (root==NULL)
        return 0;
    else
    {
        int lheight = height(root->left);
        int rheight = height(root->right);

        if (lheight > rheight)
            return lheight+1;
        else
            return rheight+1;
    }
}

/**
 * Print the data of binary tree at specific level.
 * \param   root    binary tree
 * \param   level   which level of tree to print
 */
void printGivenLevel(struct treeNode *root, int level)
{
    if (root == NULL)
        return;
    if (level == 0)
        printf ("%d ", root->data);
    else
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

/**
 * BFS the binary tree and print the data.
 * \param   root    pointer to the root of binary tree
 */
void bfsTraversal(struct treeNode *root)
{
    int treeHeight = height (root);
    printf ("Tree's height = %d\n", treeHeight);
    printf ("BFS traversal:\n");
    for(int i=0; i<treeHeight; i++)
    {
        printGivenLevel (root, i);
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

    bfsTraversal (root);

    return 0;
}
