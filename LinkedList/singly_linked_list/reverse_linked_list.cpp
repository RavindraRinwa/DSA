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

void reverse_link_list(Node*&head){
     Node*prev = NULL;
     Node*curr = head;
     Node*next_use;

     while(curr!=NULL){
        next_use = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_use;
        //  next_use = curr->next; The problem is that you're accessing next_use 
        // before checking if curr is NULL. This can lead to a segmentation fault when curr becomes NULL,
        //  as you're trying to access curr->next at that point.
     }

     display(prev);
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
    reverse_link_list(head);

}