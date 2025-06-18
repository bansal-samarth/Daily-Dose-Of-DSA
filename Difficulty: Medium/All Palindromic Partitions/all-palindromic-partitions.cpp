class Solution {
  public:
    bool isPalindrome(string &word) {
        int i = 0;
        int j = word.size() - 1;
        
        while(i < j) {
            if(word[i] != word[j])
                return false;
            
            i++;
            j--;
        }
        
        return true;
    }
    
    void solve(string& s, int idx, int n, vector<vector<string>>& ans, vector<string>& parts) {
        if(idx == n) {
            ans.push_back(parts);
            return;
        }
        
        for(int len = 1; len < n - idx + 1; len++) {
            string word = s.substr(idx, len);
            
            if(isPalindrome(word)) {
                parts.push_back(word);
                solve(s, idx + len, n, ans, parts);
                parts.pop_back();
            }
        }
    }
    
    vector<vector<string>> palinParts(string &s) {
        
        vector<vector<string>> ans;
        vector<string> parts;
        
        solve(s, 0, s.size(), ans, parts);
        
        return ans;
    }
};