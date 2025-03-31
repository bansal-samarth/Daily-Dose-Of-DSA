class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26);

        for(int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        vector<int> ans;
        int prev = -1;
        int range = 0;

        for(int i = 0; i < s.size(); i++) {
            range = max(range, last[s[i] - 'a']);

            if(range == i) { 
                ans.push_back(i - prev);
                prev = i;
            }
        }

        return ans;
    }
};