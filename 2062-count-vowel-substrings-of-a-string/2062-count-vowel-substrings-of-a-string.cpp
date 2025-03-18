class Solution {
public:
    int isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch =='u';
    }

    int countVowelSubstrings(string word) {
        int n = word.size();
        
        unordered_map<int,int> map;
        int ans = 0;
        
        int left = 0;
        for(int right = 0; right < n; right++) {
            char ch = word[right];
            if(isVowel(ch)) {
                map[ch]++;

                if(map.size() == 5) {
                    int p = left;
                    unordered_map<int,int> freq = map;

                    while(freq.size() == 5) {
                        freq[word[p]]--;
                        if(freq[word[p]] == 0)
                            freq.erase(word[p]);
                        p++;
                        ans++;
                    }
                }
            } else {
                left = right + 1;
                map.clear();
            }
        }

        return ans;
    }
};