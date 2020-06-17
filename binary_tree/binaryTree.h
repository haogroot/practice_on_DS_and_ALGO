struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
};

struct treeNode* insert (struct treeNode *tree, int key);
struct treeNode* newNode(int key);
void inOrder (struct treeNode *tree);
