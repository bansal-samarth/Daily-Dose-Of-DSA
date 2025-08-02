class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        
        unordered_map<int,int> map;
        map[0] = 1;
        
        int sum = 0;
        int ans = 0;
        
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            
            if(map[sum - k] > 0)
                ans += map[sum - k];
            
            map[sum]++;
        }
        
        return ans;
    }
};