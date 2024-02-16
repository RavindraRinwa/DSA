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

Node* reverse_K_nodes_At_a_time(Node*&head,int pos){ 

        Node*prev = NULL;
        Node*curr = head;
        int counter = 0 ;
        while(curr!=NULL && counter<pos){  //reverse starting k terms
            Node*next1 = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next1;
            counter++;
        }

        if(curr!=NULL){
            Node*new_head = reverse_K_nodes_At_a_time(curr,pos); // reverse recursivly left terms
            head->next = new_head;
        }

        return prev;

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
    display(reverse_K_nodes_At_a_time(head,3));
}