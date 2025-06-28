class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        
        int maxA = *max_element(a.begin(), a.end());
        int maxB = *max_element(b.begin(), b.end());
        
        int maxLen = max(maxA, maxB) + 1;
        
        vector<int> cumm(maxLen, 0);
        
        for(int i : b)
            cumm[i]++;
        
        for(int i = 1; i < maxLen; i++)
            cumm[i] += cumm[i - 1];
        
        vector<int> ans;
        for(int i : a)
            ans.push_back(cumm[i]);
        
        return ans;
    }
};