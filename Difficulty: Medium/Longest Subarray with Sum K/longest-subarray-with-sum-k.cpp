class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        
        unordered_map<int,int> map;
        map[0] = -1;
        
        int maxi = 0;
        int sum = 0;
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            
            if(map.count(sum - k))
                maxi = max(maxi, i - map[sum - k]);
            
            if (!map.count(sum))
                map[sum] = i;
        }
        
        return maxi;
    }
};