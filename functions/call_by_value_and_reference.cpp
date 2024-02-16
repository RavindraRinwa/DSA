#include<iostream>
using namespace std;
// void swape(int &x,int &y){
//     int temp = x;
//     x=y;
//     y = temp;
// }
void swape(int *x,int *y){
    int temp = *x;
    *x=*y;
    *y = temp;
}
int main(){
    int x = 9;
    int c = 1;
    // swape(x,c);
    swape(&x,&c);
    cout<<x<<" "<<c;
    return 0;
}
// int &q = p;
// then we access p using q . if you use &q -> address of p 