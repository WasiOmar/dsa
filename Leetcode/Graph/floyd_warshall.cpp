#include<bits/stdc++.h>
using namespace std;


int main(){
    int v;
    cin>>v;
    vector<vector<int>>dist(v,(vector<int>(v)));

    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(i==j){
                dist[i][j]=0;
            }else{
                dist[i][j]=1e9;
            }
        }
        
    }

    dist[0][1]=2;
    dist[1][2]=3;

    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(dist[i][k]==1e9 || dist[k][j]==1e9){
                    continue;
                }
                dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
     for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
        
    }




}