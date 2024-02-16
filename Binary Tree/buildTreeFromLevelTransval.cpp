#include<iostream>
#include<queue>
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

void buildFromLevelTrasval(node*root){

     queue<node*>q;
     cout<<"Enter root node:";
     int data;
     cin>>data;
     root = new node(data);
     q.push(root);

     while(!q.empty()){

            root = q.front(); // use to access left and right of node
            q.pop();
         
             cout<<"give the  data for left node "<<root->data <<":";
             int d1;
             cin>>d1;
             if(d1!=-1){
                root->left = new node(d1);
                q.push(root->left);
             }


             cout<<"give the data for right node "<<root->data <<":";
             int d2;
             cin>>d2;
             if(d2!=-1){
                root->right = new node (d2);
                q.push(root->right);
             }

     }

}
int main(){

    node*root = NULL;
    buildFromLevelTrasval(root);

}