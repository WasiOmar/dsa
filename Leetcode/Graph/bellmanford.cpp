#include<bits/stdc++.h>
using namespace std;
struct Edge {
    int u, v, w;
};
int main(){
    int V = 5;

    vector<vector<pair<int,int>>>adj(V);

    // u -> (v, weight)

     vector<Edge> edges = {
        {0,1,-1},
        {0,2,4},
        {1,2,3},
        {1,3,2},
        {1,4,2},
        {3,2,5},
        {3,1,1},
        {4,3,-3}
    };
    
    vector<int> dist(V,INT_MAX);
    int source =0 ;
    dist[source]=0;

    for(int i=0;i < V-1; i++){
        for(auto edge: edges){
            int u= edge.u;
            int v= edge.v;
            int w= edge.w;

            //relaxation
            if(dist[u]!= INT_MAX && dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
            }
        }
    }


    // Detect negative cycle
    bool negativeCycle = false;

    for(auto edge : edges) {

        int u = edge.u;
        int v = edge.v;
        int w = edge.w;

        if(dist[u] != INT_MAX &&
           dist[u] + w < dist[v]) {

            negativeCycle = true;
            break;
        }
    }

    if(negativeCycle) {
        cout << "Negative cycle detected\n";
    }
    else {

        for(int i = 0; i < V; i++) {
            cout << i << " -> " << dist[i] << endl;
        }
    }

    return 0;
}
    

