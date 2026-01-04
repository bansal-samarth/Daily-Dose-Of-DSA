class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int> map;
        
        map[0] = -1;
        
        int maxi = 0;
        int sum = 0;
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            
            int target = sum - k;
            if(map.count(target)) {
                maxi = max(maxi, i - map[target]);
            }
            
            if(!map.count(sum))
                map[sum] = i;
        }
        
        return maxi;
    }
};