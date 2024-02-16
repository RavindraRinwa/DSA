#include<iostream>
using namespace std;
#include<queue>

int main(){
    priority_queue<int>pq;
    pq.push(70);
    pq.push(60);
    pq.push(50);
    pq.push(40);
    pq.push(30);

    cout<<"The maximum element :"<<pq.top()<<endl;

    // MinHeap
    priority_queue<int,vector<int>,greater<int> >mh;
    mh.push(5);
    mh.push(4);
    mh.push(3);

    cout<<"The minimum element:"<<mh.top()<<endl;

    return 0;
}


