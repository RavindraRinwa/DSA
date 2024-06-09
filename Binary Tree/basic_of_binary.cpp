// Binary Tree  have <=2 childern

/*

Basic Terms
1.Node
2.Root  --> top node
 3.Childern
4.Parent
 5.Siblings  --> who node which have same parent
6.Ancestor --> if you go upper and upper this type order call Ancestor
7.Descendent
8.leaf  --> that node does not have any child


*/

#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{

    int data;
    cout << "Enter the data:";
    cin >> data;

    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data  for inserting at left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data  for inserting at right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTransveral(node *root)
{
    queue<node *> q;
    node *temp = root;
    q.push(root);
    // NULL use as a seprator
    q.push(NULL);

    while (!q.empty())
    {

        node *temp = q.front();

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
    node *root = NULL;
    root = buildTree(root);

    levelOrderTransveral(root);
    return 0;
}
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1