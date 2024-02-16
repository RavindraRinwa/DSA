#include<iostream>
using namespace std;
#include<vector>
int Distance(vector<int>trake_distance,int childern){
    
}
int main(){
    int childern = 0;
    int size,element;
    cin>>size;
    vector<int>trake_distance;
    for(int i = 0;i<size;i++)
    {
        cin>>element;
        trake_distance.push_back(element);
    }
    cin>>childern;
    Distance(trake_distance,childern);
}