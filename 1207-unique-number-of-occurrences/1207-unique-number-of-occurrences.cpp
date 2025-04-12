class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        vector<int> map(2001, 0);

        for(int num : arr)
            map[num+1000]++;
        
        vector<bool> ans(1001, false);

        for(int freq : map) {
            if(freq == 0)
                continue;
            
            if(ans[freq])
                return false;
            
            ans[freq] = true;
        }

        return true;
    }
};