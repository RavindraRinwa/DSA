/*

Inorder  --> LNR

explain. 1. L-->  print left node
         2. N-->  print middel(parent) node
         3. R-->  print right node

Preorder  ---> NLR

explain. 1. N-->  print middel(parent) node
         2. L-->  print left node
         3. R-->  print right node


Postorder ----> LRN

*/

#include <iostream>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *buildTree(node *root)
{

    int data;
    cout << "Enter the data:" << endl;
    cin >> data;

    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the insertion data for left side of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the insertion data for right side of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void inorderTraversal(node *root)
{

    if (root == NULL)
    { // vapis aaja (return back)
        return;
    }

    inorderTraversal(root->left);  // left ja(go to left)
    cout << root->data << " ";     // l to n
    inorderTraversal(root->right); // then go to right
}
int main()
{
    node *root = NULL;
    root = buildTree(root);

    cout << "inorder traversal is:";
    inorderTraversal(root);
}