/**
 * This sample code is inspired by leetcode 102 and 107 
 * Binary Tree Level Order Traversal
 */
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

int col[100];
/**
 * Traversal up-bottom level order of binary tree.
 * \param   root    pointer to the root of binary tree.
 * \param   level   the distance to the actual_level.
 * \param   actual_level    which level of tree to print.
 * \param   data_array  data array of specific level.
 */
void handleGivenLevel(struct treeNode *root, int level, int actual_level, int *data_array)
{
    if (root == NULL)
        return;
    if (level == 0)
    {
        data_array[col[actual_level]++] = root->data;
        //printf ("data[%d][%d]=%d ", actual_level, col[actual_level]-1, root->data);
    }
    else
    {
        handleGivenLevel(root->left, level-1, actual_level, data_array);
        handleGivenLevel(root->right, level-1, actual_level, data_array);
    }
}

/** 
 * Count the number of nodes at each level.
 * \param   root    pointer to the root of binary tree.
 * \param   count   array which contains the number of nodes at each level(index).
 * \param   level   tree's depth.
 */
void countEachLevel (struct treeNode *root, int *count, int level)
{
    if (root == NULL)
        return;
    else
    {
        count[level]++;
    }
    countEachLevel (root->left, count, level+1);
    countEachLevel (root->right, count,  level+1);
}


/**
 * Traversal up-bottom level order of binary tree.
 * \param   root    pointer to the root of binary tree
 */
void levelOrderTraversal(struct treeNode *root)
{
    int treeHeight = height (root);
    printf ("Tree's height = %d\n", treeHeight);
    int *levelCount = (int *) malloc (treeHeight * sizeof(int));
    countEachLevel (root, levelCount, 0);
    for (int i=0; i<treeHeight; i++)
    {
        printf ("level %d: %d\n", i, levelCount[i]);
    }

    int **result = (int **) malloc (treeHeight * sizeof(int *));
    for (int i=0; i<treeHeight; i++)
    {
        result[i] = (int *) malloc (levelCount[i] * sizeof(int));
    }
    for (int i=0; i<treeHeight; i++)
    {
        handleGivenLevel (root, i, i, result[i]);
    }
    printf("\n");
    for (int i=0; i<treeHeight; i++)
    {
        printf ("level %d:\n", i);
        for (int j=0; j<levelCount[i]; j++)
        {
            printf ("%d ", result[i][j]); 
        }
        printf("\n");
    }
}

int main()
{
    struct treeNode *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 80);
    root = insert(root, 60);
    //root = insert(root, 90);

    levelOrderTraversal (root);

    return 0;
}
