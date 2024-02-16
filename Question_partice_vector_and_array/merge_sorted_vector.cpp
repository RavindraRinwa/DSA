#include<iostream>
#include<vector>
using namespace std;

void MergeSort(vector<int>v1,vector<int>v2){
    vector<int>res;
    int start = 0,start1 =0,end = v1.size(),end1 = v2.size();
    while(start<end  && start1<end1){

      if(v1[start] < v2[start1]){
       res.push_back(v1[start]);

      }

      else{
        res.push_back(v2[start1]);
        start1++;
      }
    }
    while(start<end){
         res.push_back(start);
         start++;
    }
    while(start1<end1){
      res.push_back(start1);
      start1++;
    }
     
}



int main(){
       vector<int>v1;
       for(int &ele:v1){
          cin>>ele;
          v1.push_back(ele);
       }

       vector<int>v2;
       for(int &ele1:v2){
        cin>>ele1;
        v2.push_back(ele1);
       }

      MergeSort(v1,v2);

}