class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        
        unordered_map<int, long> map;
        map[0] = 1;
        
        long ans = 0;
        
        long sum = 0;
        
        for(int i : arr) {
            sum ^= i;
            
            if(map.count(sum ^ k))
                ans += map[sum ^ k];
            
            map[sum]++;
        }
        
        return ans;
    }
};