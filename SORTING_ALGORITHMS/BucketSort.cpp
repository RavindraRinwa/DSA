#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void bucketSort(vector<float>&num){
    int n = num.size();
    // step1: intialize 2D bucket
    vector<vector<float>>bucket(n,vector<float>());
    // step2:intialize bucket elements with suitable index
    for(int i = 0;i<n;i++){
        int index = num[i]*n;   // 
        bucket[index].push_back(num[i]);
    }
    //step3:sort inividual vector
    for(int i = 0;i<n;i++){
        if(!bucket[i].empty()){
            sort(bucket[i].begin(),bucket[i].end());
        }
    }
    //step4:combining
    int k = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<bucket[i].size();j++){
            num[k++] = bucket[i][j];
        }
    }
}
int main(){
    vector<float>num = {0.13,.45,.12,.89,.75,.63,.85,.39};
    bucketSort(num);
    for(int i = 0;i<8;i++){
        cout<<num[i]<<" ";
    }
}

// The use of vector<float>& num as the function parameter indicates 
// that the vector num is passed by reference. This means that 
// any modifications made to the vector 


// if element has range more than 0 - 1 than
// first calculate range 
// range  = (max-min)/size;
// for index formula should be change
// index = (element-min)/range   
// ex. element  = 1.89 and min = .12
// range = 1.28
// index = 1.38 than place at index 1



// A problem are occur in upper case in step 2:
// for boundary element
// diff = (elemet-min)/range-index
// diff is 0 means that index  = size but index should be size-1
// so this element place at size-1 index
// if(diff==0 && element!=min){
//    arr[index-1].push_back(num[i]);
//}
// else{
//       int index = num[i]*n; 
//       bucket[index].push_back(num[i]);
//}
//
//
//