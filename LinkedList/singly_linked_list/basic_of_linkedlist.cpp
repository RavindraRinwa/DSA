//challenge face an array
// 1.static size
// 2.continuous memory allocation
// 3.insering and deleting O(n)

// Type of linklist
// 1.singly linklist
// 2.doubly linklist ---> every node know      |  |<---------->|  |
// 3.circularlinklist   ---> last node point to first node

#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node*next;

    Node(int data){  // constructur class ke name ka hi hota he
        val = data;
        next = NULL;
    }
};

void insert(Node*&head,int val){
    Node*new_node = new  Node(val);
    new_node->next = head;
    head  = new_node;
}


// if we want to add node at the last position
void insert_end(Node*&Head,int val){
     Node*new_node = new Node(val);
     Node*temp = Head;

     while(temp->next!=NULL){
          temp = temp->next;
     }
       temp->next = new_node;
       new_node->next = NULL;
}
// timecomplexity of upper function is O(n)
// if tail pointer is passed then O(1)




//function for display
void display(Node*head){
    Node*temp = head;
    while(temp!=NULL){
        cout<<temp->val<<" "<<temp->next<<endl;
        temp = temp->next;
    }
}

int main(){
    
    Node*n = new Node(1);
    // cout<<n->val<<" "<<n->next<<endl;
    insert(n,3);
    display(n);
    insert(n,4);
    display(n);
    insert_end(n,7);
    display(n);

    return 0;
}