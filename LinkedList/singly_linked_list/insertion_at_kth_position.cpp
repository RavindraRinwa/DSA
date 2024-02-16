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
        cout<<temp->val<<"->";
        temp = temp->next;
    }

    cout<<"NULL"<<endl;
}


void inseration_kth_position(Node*&head,int pos,int val){
 
     int currpos = 0;
     Node*temp = head;
     if(pos==0){
        insert(head,val);
     }
  
     else{
        while(currpos!=pos-1){
             temp = temp->next;
             currpos++;
        }
         Node*new_node = new Node(val);
         new_node->next = temp->next;
         temp->next = new_node;
     }
}

void update_at_kth_position(Node*&head,int pos,int val){

        int currpos = 0;
        Node*temp = head;
        while(currpos!=pos-1){
             temp = temp->next;
             currpos++;
        }
        temp->val = val;
}

void DeletingAtHead(Node*&head){
      Node*temp = head;
      head = temp->next;
      free(temp);
}

void DeletingAtTails(Node*&head){
       Node*temp = head;
       while(temp->next->next!=NULL){
             temp = temp->next;
       }
       Node*Last = temp->next;
       temp->next=NULL;
       free(Last);

}

void DeletingAtKthPosition(Node*&head,int pos){

    if(pos==0){
      DeletingAtHead(head);
       return ;
    }
     Node*temp = head;
     int currpos = 0;
     while(currpos!=pos-1){
         temp = temp->next;
         currpos++;
     }
      Node*store = temp->next->next;
      Node*deletes = temp->next;
      free(deletes);
      temp->next = store;

}

int main(){
    
    Node*n = NULL;
    // cout<<n->val<<" "<<n->next<<endl;
    insert(n,3);
    display(n);
    insert(n,4);
    display(n);
    insert_end(n,7);
    display(n);
    inseration_kth_position(n,1,9);
    display(n);
    update_at_kth_position(n,1,45);
    display(n);
    DeletingAtHead(n);
    display(n);
    DeletingAtKthPosition(n,1);
    display(n);

    return 0;
}