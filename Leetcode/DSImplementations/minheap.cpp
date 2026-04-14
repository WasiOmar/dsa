// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;
class Minheap{
    public:
    vector<int> vec;
    int capacity;
    int size;
    Minheap(int n){
        size=0;
        capacity=n;
        vec.resize(n);
    }
    
    void insert(int a){
        if(size==capacity){
            return;
        }
        int index=size;
        //percolate up
        vec[index]=a;
        size++;
        while(index>0 && vec[index]<vec[(index-1)/2]){
            swap(vec[index],vec[(index-1)/2]);
            index=(index-1)/2;
        }
    }
    
    void heapifydown(int i){
        int smallest=i;
        if(2*i+1<size && vec[smallest]>vec[2*i+1]){
            smallest=2*i+1;
        }
        if(2*i+2<size && vec[smallest]>vec[2*i+2]){
            smallest=2*i+2;
        }
        
        if(smallest!=i){
            swap(vec[smallest],vec[i]);
            heapifydown(smallest);
        }
    }
    void pop(){
        if(size<=0) return;
        swap(vec[0],vec[--size]);
        //percolate down
        
     
        heapifydown(0);
    }
    
    int peek(){ 
        if(size<=0) return -1;
        return vec[0];
    }
    // Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;
class Minheap{
    public:
    vector<int> vec;
    int capacity;
    int size;
    Minheap(int n){
        size=0;
        capacity=n;
        vec.resize(n);
    }
    
    void insert(int a){
        if(size==capacity){
            return;
        }
        int index=size;
        //percolate up
        vec[index]=a;
        size++;
        while(index>0 && vec[index]<vec[(index-1)/2]){
            swap(vec[index],vec[(index-1)/2]);
            index=(index-1)/2;
        }
    }
    
    void heapifydown(int i){
        int smallest=i;
        if(2*i+1<size && vec[smallest]>vec[2*i+1]){
            smallest=2*i+1;
        }
        if(2*i+2<size && vec[smallest]>vec[2*i+2]){
            smallest=2*i+2;
        }
        
        if(smallest!=i){
            swap(vec[smallest],vec[i]);
            heapifydown(smallest);
        }
    }
    void pop(){
        if(size<=0) return;
        swap(vec[0],vec[--size]);
        //percolate down
        
     
        heapifydown(0);
    }
    
    int peek(){ 
        if(size<=0) return -1;
        return vec[0];
    }
    void build(vector<int>& v){
    vec = v;
    size = v.size();
    capacity = v.size();

    for(int i = (size/2) - 1; i >= 0; i--){
        heapifydown(i);
    }
}

int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";

    return 0;
}
};

int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";

    return 0;
}