/*
 V + E*log(V) time complexity

vector<int>dist(V,1e9);
dist[S] = 0;
vector<pair<int,int>,vector<pair<int,int>>,greater<int>>pq;
pq.push({0,S});
while(!pq.empty()){
   int dis = pq.top().first;        auto it = st.begin();
   int node = pq.top().second;

   pq.pop();
   for(auto it:adj[node]){
       int edgeWeight = it[1];
       int adjNode = it[0]
       if(dist[adjNode] > dis+edgeWeight){
           dist[adjNode] = dis+edgeWeight;
           pq.push({dist[adjNode],adjNode});
       }
   }
}
*/