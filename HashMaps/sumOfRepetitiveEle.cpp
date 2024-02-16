#include<iostream>
#include<map>
using namespace std;

int main(){
    int n = 7;
    int arr[] = {1,1,2,1,3,3,3};
    // you can declare using pointer
    
    map<int,int>m;

    for(int i = 0;i<n;i++){

        m[arr[i]]++;
        // ++ operator value ++ kerega
    }

    int sum = 0;

    for(auto pair:m){

        if(pair.second > 1){
            sum+=pair.first;
        }

    }

    cout<<"The Sum is:"<<sum<<endl;
    return 0;
}
