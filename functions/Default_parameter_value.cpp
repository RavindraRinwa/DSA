// it is a value in function declaration automatically assigned
// by the complier if the calling function does not any value
// to that argument
//  if you pass value  then nothing mean of default parameter
// int fun (int x,int y = 8) y = 8 -> is default value
// if we want to give default value the we always start from right most 
// other nothing mean
// int fun(int x;int y = 9;int z) ->not applicaple give error as output
#include<iostream>
using namespace std;
void fun(int x,int y = 10)
{
    cout<<x<<" "<<y;
}
int main(){
    fun(10);
}