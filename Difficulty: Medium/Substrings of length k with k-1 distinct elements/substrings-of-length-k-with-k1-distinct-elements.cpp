class Solution {
  public:
    int substrCount(string &s, int k) {
        
        unordered_map<char, int> map;
        
        for(int i = 0; i < k; i++)
            map[s[i]]++;
        
        int ans = 0;
        
        if(map.size() == k - 1)
            ans++;
        
        for(int i = k; i < s.size(); i++) {
            
            map[s[i]]++;
            map[s[i - k]]--;
            
            if(map[s[i - k]] == 0)
                map.erase(s[i - k]);
            
            if(map.size() == k - 1)
                ans++;
        }
        
        return ans;
    }
};