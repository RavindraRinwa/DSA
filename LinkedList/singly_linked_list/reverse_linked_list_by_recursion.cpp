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

Node* reverse_link_list_by_recursion(Node*&head){
   // base_case
   if(head==NULL || head->next==NULL){  // please focus on 
        return head;
   }
    // recursive case;
       Node*new_head = reverse_link_list_by_recursion(head->next);
       head->next->next = head;
       head->next = NULL;
       return new_head;
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
    Node*new_node =  reverse_link_list_by_recursion(head);
    display(new_node);

}
