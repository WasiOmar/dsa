#include<bits/stdc++.h>
using namespace std;


//find adj of a node

map<string ,pair<int,int> >findAdj(int ru,int rc, int r,int c){
    map<string , pair<int,int> > adj;

    //find up
    if(ru-1>=0){
        adj["up"] = make_pair(ru-1 ,rc);
    }
    //find down
     if(ru+1<r){
        adj["down"] = make_pair(ru+1 ,rc);
    }

    //find left
     if(rc-1>=0){
        adj["left"] = make_pair(ru ,rc-1);
    }
    //find right

      if(rc+1<c){
        adj["right"] = make_pair(ru ,rc+1);
    }
    
    return adj;
}
int main(){
    
}