#include<iostream>
#include<queue>
using namespace std;

int main(){
   deque<int>d;

   d.push_back(12);
   d.push_back(16);
   d.push_front(14);
   d.push_front(23);


   d.pop_back();
   d.pop_front();

   cout<<d.front();

}