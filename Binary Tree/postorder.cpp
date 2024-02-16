#include<iostream>
using namespace std;

class node{

public:
    int data;
    node*left;
    node*right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }

};

node* buildTree(node*root){
   
      int data;
      cout<<"Enter the data:"<<endl;
      cin>>data;

      root = new node(data);

      if(data==-1){
        return NULL;
      }

      cout<<"Enter the insertion data for left side of "<<data<<endl;
      root->left = buildTree(root->left);
      cout<<"Enter the insertion data for right side of "<<data<<endl;
      root->right = buildTree(root->right);

      return root;

}

 void postorderTraversal(node*root){

     if(root==NULL){  // vapis aaja (return back)
        return ;
     }
     
     
     postorderTraversal(root->left);// left ja(go to left)
     postorderTraversal(root->right);// then go to right
     cout<<root->data<<" ";// l to n
     
}
int main(){
     node*root = NULL;
     root = buildTree(root);
     
     cout<<"inorder traversal is:";
     postorderTraversal(root);

}