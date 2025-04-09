class Solution {
public:
    int compress(vector<char>& chars) {
        int pt = 0;

        int i = 0;
        while(i < chars.size()) {
            char letter = chars[i];

            int start = i;
            while(i < chars.size() && letter == chars[i]) {
                i++;
            }

            int len = i - start;

            chars[pt++] = letter;
            if(len == 1) 
                continue;

            string sizeStr = to_string(len);

            for(int l = 0; l < sizeStr.size(); l++)
                chars[pt++] = sizeStr[l];
        }

        return pt;
    }
};