#include<iostream>
#include<vector>
using namespace std;
int ChocolateDistribution(vector<int>&box_chocolate,int student){
     int min = -1,sum = 0;
     int n = box_chocolate.size();
    for(int i = 0;i<n;i++){
        if(min>box_chocolate[i]){
            min = box_chocolate[i];
        }
        sum+=box_chocolate[i];
    }

    int beg = min;
    int end = sum;
    int mid = (beg+end)/2;
    int num_student = 0;
    while(beg<=end){
        int sum1 = 0;
        int j = 0;
        while(sum1<=mid && j<n){
            sum1+=box_chocolate[j];
            j++;
        }
        if(sum1>=mid  && j<n){
            beg = mid+1;
        }
        if(sum1>=mid && j==n){
            end = mid-1;
        }
        
        mid = (beg+end)/2;
    }
}
int main(){
    int student = 0;
    int size,element;
    cin>>size;
    vector<int>box_chocolate;
    for(int i = 0;i<size;i++)
    {
        cin>>element;
        box_chocolate.push_back(element);
    }
    cin>>student;
    int ans = ChocolateDistribution(box_chocolate,student);
    cout<<ans;
}