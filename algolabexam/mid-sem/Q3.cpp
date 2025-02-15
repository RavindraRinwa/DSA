#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>
#include <algorithm>
using namespace std;

const int INF = numeric_limits<int>::max();

// Dijkstra's Algorithm
vector<int> dijkstra(int source, int n, const unordered_map<int, vector<pair<int, int>>> &graph)
{
    vector<int> dist(n, INF); // Distance from source to each node
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // Min-heap
    pq.push({0, source});                                                 // {distance, node}

    while (!pq.empty())
    {
        pair<int, int> top_element = pq.top();
        int d = top_element.first;
        int u = top_element.second;
        pq.pop();

        if (d > dist[u])
            continue; // Skip if we already found a shorter path

        for (const auto &neighbor : graph.at(u))
        {
            int v = neighbor.first;       // First element of the pair (neighbor node)
            int weight = neighbor.second; // Second element of the pair (weight of the edge)

            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main()
{
    // Input: Graph representation
    vector<tuple<int, int, int>> roads = {
        {0, 1, 4}, {0, 2, 2}, {1, 2, 1}, {1, 3, 5}, {2, 3, 8}, {2, 4, 10}, {3, 4, 2}, {4, 5, 3}};
    int n = 6;                       // Number of intersections (nodes)
    int source = 0;                  // Ambulance's starting location
    vector<int> targets = {3, 5, 4}; // Emergency locations

    // Build the graph as an adjacency list
    unordered_map<int, vector<pair<int, int>>> graph;
    for (const auto &road : roads)
    {
        int u = get<0>(road);
        int v = get<1>(road);
        int w = get<2>(road);
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w); // Undirected graph
    }

    // Calculate shortest distances using Dijkstra
    vector<int> dist = dijkstra(source, n, graph);

    // Part 1: Shortest travel time to each emergency location
    cout << "Shortest travel times to targets:" << endl;
    for (int target : targets)
    {
        if (dist[target] == INF)
            cout << "Target " << target << ": Unreachable (INF)" << endl;
        else
            cout << "Target " << target << ": " << dist[target] << " minutes" << endl;
    }

    // Part 2: Total travel time in order of increasing travel time
    vector<int> travel_times;
    for (int target : targets)
    {
        travel_times.push_back(dist[target]);
    }
    sort(travel_times.begin(), travel_times.end());

    int total_time = 0;
    for (int time : travel_times)
    {
        if (time != INF)
            total_time += time;
    }

    cout << "Total travel time to visit all reachable emergencies in order: " << total_time << " minutes" << endl;

    return 0;
}
