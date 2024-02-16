#include<iostream>
#include<vector>
using namespace std;

int main()
{     int element;
    vector<int>v;// if U want to give size to then follow this step vector-name(size);
    for(int i = 0;i<5;i++)
    {
      cin>>element;
      v.push_back(element);
      // cin>>v[i] then we must decalar first size then we can use
    }

    for(int j = 0;j<v.size();j++)
    {
        cout<<v[j]<<" ";
    }
    cout<<endl;
    v.insert(v.begin()+1,67);
    v.erase(v.begin()+3);
    for(int ele:v){
        cout<<ele<<" ";
    }
}

// vector pass by reference a
// recve  void function name (vector<int>&v)
// function name(v)