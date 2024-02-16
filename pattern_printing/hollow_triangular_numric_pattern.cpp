#include<iostream>
using namespace std;
int main()
{
    int rows;
    cin>>rows;
    for(int i =1;i<=rows;i++)
    {
        for(int k = rows;k>i;k--)
        cout<<" ";
        for(int j = 1;j<=2*i-1;j++)
        {
         if(i==1 or i == rows or j==1 or j==2*i-1)
         cout<<i;
         else
         cout<<" ";
        }
        cout<<endl;
    }
}