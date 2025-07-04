class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        
        unordered_map<int, int> map;
        int ans = 0;
        
        int left = 0;
        for(int right = 0; right < arr.size(); right++) {
            
            map[arr[right]]++;
            
            while(map.size() > k) {
                map[arr[left]]--;
                
                if(map[arr[left]] == 0)
                    map.erase(arr[left]);
                
                left++;
            }
            
            ans += right - left + 1;
        }
        
        return ans;
    }
};