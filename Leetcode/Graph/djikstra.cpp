#include<bits/stdc++.h>
using namespace std;

int main(){
    int V = 5;

    vector<vector<pair<int,int>>>adj(V);

    // u -> (v, weight)

    adj[0].push_back({1,4});
    adj[0].push_back({2,1});

    adj[2].push_back({1,2});
    adj[1].push_back({3,1});

    adj[2].push_back({3,5});
    adj[3].push_back({4,3});

    vector<int>dist(V,INT_MAX);
    int source = 0;

    dist[source]=0;

    priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> minheap;
    minheap.push({0, source});

    while (!minheap.empty())
    {
        int d= minheap.top().first;
        int u= minheap.top().second;

        minheap.pop();

        if(d>dist[u]) continue;

        for(auto edges : adj[u]){
            int src = edges.first;
            int dis = edges.second;

            if(d+ dis < dist[src]){
                dist[src]= d+dis;
                minheap.push({dist[src], src});
            }
        }
    }
    
    for(int i = 0; i < V; i++) {

        cout << i << " -> "
             << dist[i] << endl;
    }

}