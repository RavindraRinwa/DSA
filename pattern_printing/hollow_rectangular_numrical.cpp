#include<iostream>
using namespace std;
int main()
{
    int rows,colume;
    cin>>rows>>colume;
    for(int i = 1;i<=rows;i++)
    {
        for(int j = 1;j<=colume;j++)
        {
            if(i==1 or j==1 or i==rows or j==colume) // or-> || can use
             cout<<j;
             else
              cout<<" ";
        }
        cout<<endl;
    }
}