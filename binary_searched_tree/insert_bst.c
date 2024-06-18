//insert a value in the binary search tree 
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

//this function will return the new node with the given value
struct node *getNewNode(int val)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->key   = val;
    newNode->left  = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node *insert(struct node *root, int val)
{
    if(root == NULL)
        return getNewNode(val); //f the tree is empty, return new node in root
    /*
     * if given val is greater than root->key,
     * we should find the correct place in right subtree and insert the new node
     */
    
    if(root->key < val)
        root->right = insert(root->right,val);
    /*
     * if given val is smallar than root->key,
     * we should find the correct place in left subtree and insert the new node
     */
    else if(root->key > val)
        root->left = insert(root->left,val);
    /*
     * (Prevent the duplicate nodes in the tree)
     * 1.if root->key == val it will straight away return the address of the root node
     * 2.After the insertion, it will return the original unchanged root's address
     */
    return root;
}

void inorder(struct node *root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ",root->key);
    inorder(root->right);
} //left-root-right

int main()
{
    struct node *root = NULL;
    root = insert(root,100);
    root = insert(root,50);
    root = insert(root,150);
    root = insert(root,20);

    inorder(root);

    return 0;
}