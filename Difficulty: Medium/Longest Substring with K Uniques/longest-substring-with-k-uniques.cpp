class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        
        unordered_map<char, int> map;
        int maxi = -1;
        
        int left = 0;
        for(int right = 0; right < s.size(); right++) {
            
            map[s[right]]++;
            
            while(map.size() > k) {
                map[s[left]]--;
                
                if(map[s[left]] == 0)
                    map.erase(s[left]);
                
                left++;
            }
            
            if(map.size() == k)
                maxi = max(maxi , right - left + 1);
        }
        
        return maxi;
    }
};