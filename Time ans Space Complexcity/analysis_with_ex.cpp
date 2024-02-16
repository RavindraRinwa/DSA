#include<iostream>
using namespace std;

int sum_x_to_y(int x,int y){

    int ans = 0;
    for(int i = x;i<=y;i++){
        ans+=i;
    }
    return ans;
}

int isoptimize(int x,int y){
    int n  =  y-x+1;
    int ans = (n/2)*(x+y);
}

int main(){
    int x = 5,y = 100000000;

//    cout<<isoptimize(x,y);
cout<<sum_x_to_y(x,y);
}