#include<iostream>
using namespace std;
int main()
{
    int rows;
    cin>>rows;
    for(int i = 1;i<=rows;i++)
    {
        for(int j = rows;j>i;j--)
        cout<<" ";
        for(int k =1;k<=i;k++)
        cout<<k;
        for(int l=i-1;l>=1;l--)
        cout<<l;

        cout<<endl;
    }
}