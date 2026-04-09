#include <iostream>
#include<vector>
using namespace std;

class dsu{
    public:
    vector<int>rank;
    vector<int>parent;
    
  dsu(int n){
      rank.resize(n+1,0);
      parent.resize(n+1);
      for(int i=1;i<=n;i++){
          parent[i]=i;
      }
  }
  void unionc(int u,int v){
    int upu=findparent(u);
    int upv=findparent(v);
    if (upu == upv) return;
    if(rank[upu]==rank[upv]){
        rank[upu]++;
        parent[upv]=upu;
    }else if(rank[upu]>rank[upv]){
        parent[upv]=upu;
    }else{
        parent[upu]=upv;
    }
  }
  
  int findparent(int u){
      if(parent[u]==u){
          return u;
      }
      return parent[u]=findparent(parent[u]);
  }
  
  bool check(int u,int v){
      int upu=findparent(u);
      int upv=findparent(v);
      if(upu==upv){
          return true;
      }else{
          return false;
      }
  }
  
};

int main(){
     dsu dsu1(7); // nodes: 0 to 6

    dsu1.unionc(1, 2);
    dsu1.unionc(2, 3);
    dsu1.unionc(4, 5);
    dsu1.unionc(6, 5);

    // Check if 3 and 6 are connected
    cout<< dsu1.check(3,6)<<endl;
 
    dsu1.unionc(3, 6);

    cout<<dsu1.check(3,6)<<endl;

    return 0;
}
