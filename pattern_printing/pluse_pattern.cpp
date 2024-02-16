#include<iostream>
using namespace std;
int main()
{
    int rows;
    cin>>rows;
    for(int i = 1;i<=rows;i++)
    {
        if(i==(rows/2+1))
        {
            for(int j = 1;j<=rows;j++)
            cout<<"*";
        }
        else{
            for(int j = 1;j<=rows/2;j++)
            cout<<" ";
            cout<<"*";
        }
        cout<<endl;
    }
}