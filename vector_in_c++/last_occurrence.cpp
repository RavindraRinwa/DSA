#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int x,size,element;
    bool flag =true;
    cin>>size;
    vector<int>v;
    for(int i = 0;i<size;i++)
    {
        cin>>element;
        v.push_back(element);
    }
    cout<<"Enter the value of x:";
    cin>>x;
    for(int j = size-1;j>=0;j--){
        if(v[j]==x){
         cout<<"The last occurrence of element" <<x<< "is:"<<j; //U can use also printf
         flag=false;
         break;}
    }
    if(flag==true)
    cout<<"Element is not present in vector";
}