#include <iostream>
struct node
{
    int data;
    node *left;
    node *right;

};

node* createNode(int value)
{
    node* newNode = new node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
};

void insertNode(node *node, int value)
{
    if(value <= node->data)
    {
        if(node->left == NULL)
        {
            node->left = createNode(value);
        }
        else
        {
            insertNode(node->left, value);
        }
    }
    else
    {
        if(node->right == NULL)
        {
            node->right = createNode(value);
        }
        else
        {
            insertNode(node->right, value);
        }
        
    }
    
}

void printTree(node *node)
{
    if(node->left != NULL)
    {
        printTree(node->left);
    }
    std::cout << " " << node->data;
    if(node->right != NULL)
    {
        printTree(node->right);
    }




}

int main ()
{
    node *root = createNode(rand() % 1000+1);
    int a {};
    for(int i = 0; i<10; i++)
    {
        std::cout << i+1 << ": "; std::cin >> a;
        insertNode(root, a);
    }
    printTree(root);
    std::cout << std::endl;
    return 0;
}