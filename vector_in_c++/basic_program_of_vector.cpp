#include<iostream>
using namespace std;
#include<vector>

int main()
{
   vector<int>v;

   cout<<"size:"<<v.size()<<endl;
   cout<<"capacity:"<<v.capacity()<<endl;
   v.push_back(1); // -> add

   cout<<"size:"<<v.size()<<endl;
   cout<<"capacity:"<<v.capacity()<<endl;
   v.push_back(2); // -> add

   cout<<"size:"<<v.size()<<endl;
   cout<<"capacity:"<<v.capacity()<<endl;
   v.push_back(3); // -> add

   v.resize(10);
   cout<<"size:"<<v.size()<<endl;
   cout<<"capacity:"<<v.capacity()<<endl;

   v.pop_back();
   v.pop_back();

   cout<<"size:"<<v.size()<<endl;
   cout<<"capacity:"<<v.capacity()<<endl;

    return 0;
}