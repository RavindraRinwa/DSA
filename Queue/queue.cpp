// based on FIFO theorem
#include<iostream>
#include<queue>
using namespace std;
int main(){
   queue<int>q;

   //push operation
   q.push(2);
   q.push(4);
   q.push(6);
   q.pop();
   cout<<q.front();
   //You can use back(for back element) and empty and size function

}