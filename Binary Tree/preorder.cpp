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

 void preorderTraversal(node*root){

     if(root==NULL){  // vapis aaja (return back)
        return ;
     }
     
     cout<<root->data<<" ";// l to n
     preorderTraversal(root->left);// left ja(go to left)
     preorderTraversal(root->right);// then go to right
     
}
int main(){
     node*root = NULL;
     root = buildTree(root);
     
     cout<<"inorder traversal is:";
     preorderTraversal(root);

}