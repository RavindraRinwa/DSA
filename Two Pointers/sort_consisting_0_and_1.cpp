// #include<iostream>
// using namespace std;
// int main(){
//     int size;
//     cout<<"Enter the size of array:";
//     cin>>size;
//     int a[size];
//     for(int i = 0;i<size;i++){
//         cin>>a[i];
//     }
//     int last_element = size-1;
//     for(int j = 0;j<size;j++){
//         if(a[j]==1){
//          for(int k =last_element;k>j;k--){
//             if(a[k]==0){
//                 int temp = a[j];
//                 a[j] = a[k];
//                 a[k] = temp;
//                 last_element=k;
//                 break;
//             }
//          }
//         }
//     }
//     for(int i = 0;i<size;i++){
//         cout<<a[i]<<" ";
//     }
// }

#include<iostream>
#include<vector>
using namespace std;

void SortZeroesAndOnes(vector<int>&v){

    int zero_count = 0;
    for(int ele:v){
        if(ele == 0){
            zero_count++;
        }
    }

    for(int i = 0;i<v.size();i++){
        if(i<zero_count){
            v[i] = 0;
        }
        else{
            v[i] = 1;
        }
    }
}

int main(){
    int n,element;
    cin>>n;
    
    vector<int>v;
    for(int i = 0;i<n;i++){
        cin>>element;
        v.push_back(element);
    }

    SortZeroesAndOnes(v);

    for(int ele:v){
        cout<<ele<<" ";
    }
}