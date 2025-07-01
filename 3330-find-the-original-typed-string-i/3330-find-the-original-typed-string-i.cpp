class Solution {
public:
    int possibleStringCount(string word) {

        int ans = 1;

        int cnt = 1;
        char letter = word[0];
        for(int i = 1; i < word.size(); i++) {
            if(letter != word[i]) {
                ans += cnt - 1;
                letter = word[i];
                cnt = 1;
            }
            else
                cnt++;
        }

        return ans + cnt - 1;
    }
};