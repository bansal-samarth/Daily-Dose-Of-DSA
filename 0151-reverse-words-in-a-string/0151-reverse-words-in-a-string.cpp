class Solution {
public:
    string reverseWords(string str) {
        reverse(str.begin(), str.end());

        int n = str.size();
        int left = 0;
        int right = 0;

        int i = 0;
        while(i < n) {
            
            while(i < str.size() && str[i] == ' ')
                i++;

            if (i == n)
                break;

            while(i < str.size() && str[i] != ' ')
                str[right++] = str[i++];
            
            reverse(str.begin() + left, str.begin() + right);

            str[right++] = ' ';
            left = right;
        }
        
        str.resize(right - 1);
        return str;
    }
};