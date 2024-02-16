#include<iostream>
#include<string>
using namespace std;

class trieNode{
     
     public:
     char data;
     trieNode*children[26];
     bool isTerminal;

     trieNode(char ch){
           data = ch;
           isTerminal = false;
           for(int i = 0;i<26;i++){
               children[i] = NULL;
           }
     }

};

class trie{

   public:

   trieNode*root;

   trie(){
      root = new trieNode('\0');
   }

   void insert(trieNode*root,string word){
      // base case
       if(word.length()==0){
           root->isTerminal = true;
           return ;
       }
 
       int index = word[0]-'A';
       trieNode*child;
      // ask to root
      //present
      if(root->children[index]!=NULL){
          child = root->children[index];
      }
      // absent
      else{
          child = new trieNode(word[0]);
          root->children[index] = child;
      }
      //recursion
      // Copy substring after pos
      insert(root->children[index],word.substr(1));

   }

   void insertionINTrie(string word){
        insert(root,word);
   }


   bool searchNode(string word){
        // ask to root present or not

        trieNode*temp = root;
        
        while(word.length()!=0 ){

         int index = word[0]-'A';

         if(temp->children[index]==NULL){
             return false;
         }

        word = word.substr(1);

        temp = temp->children[index];

        } 
      return temp->isTerminal;
      
   }
    
   void deleteNode(string word){

      trieNode*temp = root;
        
        while(word.length()!=0){
            int index = word[0]-'A';

            if(temp->children[index]==NULL){
                cout<<"The Word is Not present";
            }

             word = word.substr(1);

             temp = temp->children[index];

        }

        if(temp->isTerminal){
             temp->isTerminal = false;
        }
        else{
            cout<<"The Word is Not present";
        }

   }
};


int main(){

    trie *t = new trie();
    // trieNode*root;
    t->insertionINTrie("ABCD");

    cout<<"Present or Not:";

    if(t->searchNode("ABCD")){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }

    return 0;
}