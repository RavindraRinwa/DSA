#include<iostream>
using namespace std;
int result = 0;

int PowerFunction(int p,int q){
     if(q==1){
        return p;
     }
     else{
        if(q%2==0){
            result = PowerFunction(p,q/2);
            return result*result;
        }
        else{
            result = PowerFunction(p,(q-1)/2);
            return result*result*p;
        }
     }
}

int main(){
    int p=2,q=6;
    // cout<<"Enter the value of P:";
    // cin>>p;
    // cout<<"Enter the value of  Q:";
    // cin>>q;

    cout<<PowerFunction(p,q);


// Time Compalexity is O(log(q))

}