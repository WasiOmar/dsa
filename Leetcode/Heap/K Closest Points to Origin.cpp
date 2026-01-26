class Solution {
    private:
    int k;
    priority_queue<pair<int,pair<int,int>>> maxheap;
public:
    int calc(int a, int b){
        return ((a*a+b*b));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        this->k=k;
        for(auto i: points){
            maxheap.push({calc(i[0],i[1]),{i[0],i[1]}});
            if(maxheap.size()>k){
                maxheap.pop();
            }
        }
        vector<vector<int>> result;
        while(!maxheap.empty()){
            result.push_back({maxheap.top().second.first,maxheap.top().second.second});
            maxheap.pop();
        }
        return result;
    }
};
