#include<iostream>
using namespace std;
int main()
{
    int rows,colume;
    cin>>rows>>colume;
    for(int i =1;i<=rows;i++)
    {
        for(int j = 1;j<=colume;j++)
        {
            // if(i%2!=0)
            // {
            //   if(j%2!=0)
            //   cout<<"1";
            //   else
            //   cout<<"2";
            // }
            // else
            // {
            //   if(j%2!=0)
            //   cout<<"2";
            //   else
            //   cout<<"1";
            // }
            if((i+j)%2==0)  // + and %  then % has more priority
            cout<<"1";
            else
            cout<<"2";
        }
        cout<<endl;
    }
}