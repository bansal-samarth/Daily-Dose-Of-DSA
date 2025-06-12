struct cmp{
    bool operator()(pair<int, int> &a, pair<int, int> &b){
        if(a.first < b.first)
            return true;
        if(a.first == b.first){
            if(a.second > b.second)
                return true;
            return false;    
        }
        return false;
    }
    
};


class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        // Code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> maxpq;
        for(auto z : arr){
            int dif = abs(z-x);
            if(dif){
                maxpq.push({dif, z});
                if(maxpq.size() > k)
                    maxpq.pop();
            }
        }
        
        vector<int> ans;
        while(!maxpq.empty()){
            ans.push_back(maxpq.top().second);
            maxpq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};