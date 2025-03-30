class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') ||
               (ch == 'u') || (ch == 'A') || (ch == 'E') || (ch == 'I') || (ch == 'O') ||
               (ch == 'U');
    }
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            while (i < s.size() && !isVowel(s[i]))
                i++;
            while (j >= 0 && !isVowel(s[j]))
                j--;
            
            if(i < j)
                swap(s[i++], s[j--]);
        }

        return s;
    }
};