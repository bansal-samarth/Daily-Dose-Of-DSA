class Solution {
  public:
    int countStrings(string S) {
        vector<int> map(26, 0);
        int ans = 0;
        bool containsDuplicate = false;
    
        for (int i = 0; i < S.length(); i++) {
            ans += (i - map[S[i] - 'a']);
            map[S[i] - 'a']++;
            if (map[S[i] - 'a'] > 1) containsDuplicate = true;
        }
    
        return containsDuplicate ? ans + 1 : ans;
    }
};
