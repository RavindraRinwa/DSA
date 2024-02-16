#include <iostream>
using namespace std;
int main()
{
    int rows,colume;
    cin>>rows>>colume;
    for (int i = 1; i <=rows; i++)
    {
       
        // if ( i%2 == 0 &&i % 3 == 0)
        // {
        //     for (int j = 0; j < colume; j++)
        //     {
        //         cout<<"*";
        //     }
        // }
        // else if(i%2==0)
        // {
        //    for (int j = 0; j < colume; j++)
        //     {
        //         if (j==colume-1 or j== 0)  //j=0 then i will get error
        //         cout<<"*";
        //         else
        //         cout<<" ";
        //     }
        // }
        // else
        //   cout << "\n";


        for(int j =1;j<=colume;j++)
        {
            if(i== 1 || j == 1 || i == j ||j ==colume) // its check both i and j  if j is true then also check for i
            cout<<"*";
            else
            cout<<" ";
        }
        cout<<endl;
    }
}