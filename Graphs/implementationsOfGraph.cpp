#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

template<typename T>

class Graph{

      public:
    
      unordered_map<T,list<T>>adj;

      void addEdge(T u,T v,bool direction){
            //  direction -> 0   means  undirected graphs
           // if undirected
           adj[u].push_back(v);

           if(direction==0){
                adj[v].push_back(u);
           }

      }

      void printGraph(){
            
            for(auto ele:adj){
                 cout<<ele.first<<"->";
                 for(auto j:ele.second){
                    cout<<j<<" ";
                 }
                 cout<<endl;
            }

      }

};
int main(){


    int n;
    cout<<"Enter the number of Nodes:";
    cin>>n;

    int m;
    cout<<"Enter the number of edge:";
    cin>>m;

     Graph<int> g;

    for(int i = 0;i<n;i++){
        int u,v;
        cout<<"Enter The value of U and V:";
        cin>>u>>v;
        g.addEdge(u,v,0);
    }


    // print the graph
     g.printGraph();

    return 0;
}