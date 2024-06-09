
// inorder of BST is sorted
// 10 20 30 40 50 60
// inorder predecessor  -->  predecessor of 30 is 20(just back element in inorder)
// inorder successor  --> successor of 30 is 40(just after element in inorder)

#include <iostream>
#include <queue>
using namespace std;
class TreeNode
{
public:
    // initialize variable
    int data;
    TreeNode *right;
    TreeNode *left;
    // intialize constructur
    TreeNode(int data)
    {
        this->data = data;
        right = NULL;
        left = NULL;
    }
};

TreeNode *insertIntoBST(TreeNode *root, int data)
{

    if (root == NULL)
    {
        TreeNode *temp = new TreeNode(data);
        return temp;
    }

    if (root->data > data)
    {
        root->left = insertIntoBST(root->left, data);
    }
    else
    {
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}
void takeinput(TreeNode *&root)
{

    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
int main()
{

    cout << "Enter the data for BST:";
    TreeNode *root = NULL;
    takeinput(root);

    cout << "BST:" << endl;
    levelOrderTraversal(root);
    // 10 8 21 7 27 5 4 3 -1
}