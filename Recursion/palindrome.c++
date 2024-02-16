#include<iostream>
using namespace std;

bool f(int arr[],int start,int end){
    if(start>=end){
        return 1 ;
    }
    else{
        return ((arr[start]==arr[end])? 1:0)  & f(arr,start+1,end-1);
    }
}

int main(){
    int arr[] = {1,9,6,7,9,1}; 

    if(f(arr,0,5)){
        cout<<"The given number is palindrome";
    }
    else{
        cout<<"The given number is not palindrome";
    }

}