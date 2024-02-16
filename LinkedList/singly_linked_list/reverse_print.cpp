#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node*next;

    Node(int data) {
         val = data;
         next = NULL;
    }
};


void insert(Node*&head,int val){
    Node*new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}


void display(Node*head){
    Node*temp = head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void reverse_display(Node*head){
   if(head==NULL){
       return ;
   }
   else{
       reverse_display(head->next);
       cout<<head->val<<"->";
   }

}
int main(){
    Node*head = NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    insert(head,7);
    insert(head,8);
    display(head);
    reverse_display(head);
    cout<<"NULL";

}