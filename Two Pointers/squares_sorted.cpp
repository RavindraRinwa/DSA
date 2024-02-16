#include <iostream>
#include <vector>
using namespace std;
void Sort_of_Square(vector<int> v)   // declar like this   vector<int>&v also
{
    vector<int>ans;
    int left_ptr = 0, right_ptr = v.size() - 1;

    while (left_ptr <= right_ptr)   // <= for pushback last element in vector
    {
        if(abs(v[left_ptr])<=abs(v[right_ptr])){
            ans.push_back(v[right_ptr] * v[right_ptr]);
            right_ptr--;
        }
        else{
            ans.push_back(v[left_ptr]*v[left_ptr]);
            left_ptr++;
        }
    }
    
    for(int i = 0,j=ans.size()-1;i<j;i++,j--){
          int temp = ans[i];
          ans[i] = ans[j];
          ans[j] = temp;
    }

    // reverse(ans.begin(),ans.end());

    for(int ele:ans){
         cout<<ele<<" ";
    }
   

}

int main()
{
    int n, element;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> element;
        v.push_back(element);
    }

    Sort_of_Square(v);

}