#include<iostream>
using namespace std;
int main()
{
    int rows,sum;
    cin>>rows;
    for(int i = 1;i<=(2*rows-1);i++)
    {
        sum = 65;
        
        if(i<((2*rows-1)/2+1))
        {
            for(int l = ((2*rows-1)/2);l>=i;l--)
        {
            cout<<" ";
        }
        for(int j = 1;j<=2*i-1;j++)
        {
            cout<<char(sum);// 'A'+j ->applicable as-> 65+j
            sum++;
        }
        }
        else{
            for(int l =1;l<=i-((2*rows-1)/2)-1;l++)
        {
            cout<<" ";
        }
            for(int k =1;k<=2*((2*rows-1)-i)+1;k++)
            {
                cout<<char(sum);
                sum++;
            }
        }
        cout<<endl;
    }
}