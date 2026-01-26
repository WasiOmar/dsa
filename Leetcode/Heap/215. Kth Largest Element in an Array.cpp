

class KthLargest {
    private: 
    priority_queue<int, vector<int>,greater<int>> minheap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(auto i: nums){
            minheap.push(i);
        }
        while(minheap.size()>k){
            minheap.pop();
        }
    }
    
    int add(int val) {
        minheap.push(val);
        if(minheap.size()>k){
            minheap.pop();
        }
        return minheap.top();
    }
};
