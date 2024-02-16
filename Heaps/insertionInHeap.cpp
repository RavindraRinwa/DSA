#include <iostream>
using namespace std;

class Heap
{

public:
  int arr[100];
  int size;

  Heap(){
    arr[0] = -1;
    size = 0;
  }

  void insertionInHeap(int val)
  {

    size++;
    int index = size;
    arr[index] = val;

    while (index > 1)
    {
      int parent = index / 2;
      if (arr[index] > arr[parent])
      {
        swap(arr[parent], arr[index]);
        index = parent;
      }
      else
      {
        return;
      }
    }
  }
  void print()
  {
    for (int i = 1; i <= size; i++)
    {
      cout << arr[i] << " ";
    }cout<<endl;
  }

  void deletionOfHeap(){
    if(size==0){
      cout<<"The Heap is Empty";
    }
    //put last element to top
    arr[1] = arr[size];
    //delete last node
    size--;
    // reach correct pos of root 
   
   int i = 1;

   while(i<size){
      
      int largest = i;
      int leftIndex = 2*i;
      int rightIndex = 2*i+1;

      if(leftIndex <= size && arr[leftIndex] > arr[largest]){
         largest = leftIndex;
      }
      /*
      
                  52
                /    \
              53      54
            /
          50

          in this case if you choose maximum then swap
          so that we can make a maxi heap
      
      
      */
      
      if(rightIndex <= size && arr[rightIndex] > arr[largest]){
        largest = rightIndex;
      }

      if(largest!=i){
         swap(arr[i],arr[largest]);
         i = largest;
      }
      else{
        return ;
      }

    }
   }

};

void heapifyAlgo(int*arr,int i,int n){
     
     int largest = i;
     int left = 2*i+1;
     int right = 2*i+2;

     if(left < n && arr[left] > arr[largest]){
         largest = left;
     }
     if(right<n && arr[right] > arr[largest]){
        largest = right;
     }

     if(largest!=i){
        swap(arr[largest],arr[i]);
        heapifyAlgo(arr,largest,n);
     }
     else{
        return ;
     }

}

    

int main()
{

  Heap h1;
  h1.insertionInHeap(50);
  h1.insertionInHeap(55);
  h1.insertionInHeap(54);
  h1.insertionInHeap(53);
  h1.insertionInHeap(52);
  h1.print();
  h1.deletionOfHeap();
  h1.print();

  int arr[6] = {7,10,4,3,20,15};
  int n = 6;

// because in CBT leaf node start form (n/2+1) to n keep in mind


  for(int i = (n/2)-1;i>=0;i--){
        heapifyAlgo(arr,i,n);
  }

  for (int i = 0; i <n; i++)
    {
      cout << arr[i] << " ";
    }cout<<endl;

  return 0;

}