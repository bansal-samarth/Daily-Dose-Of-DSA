class Solution {
public:
    string reverseWords(string s) {
        
        int j = -1;
        string ans = "";

        bool start = false;

        int x;
        for (x = s.size() - 1; x >= 0 && s[x] == ' '; x--) {
            // Empty body, the loop will terminate when a non-space character is found.
        }

        int y;
        for (y = 0; y < s.size() && s[y] == ' '; y++) {
            // Empty body, the loop will terminate when a non-space character is found.
        }

        s = s.substr(y, x + 1);

        cout<<"."<<s<<"."<<endl;

        for(int i = 0 ; i < s.size(); i++)
        {
            if(s[i] == ' ' && start == true)
            {
                ans = s.substr(j,i-j) + ans;
                j = -1;
                while(i+1 < s.size() && s[i]==' ' && s[i+1]==' ')
                    i++;
                
                if(i != s.size()-1)
                    ans = " "+ ans;
            }
            else
            {
                start = true;
                if(j == -1)
                    j = i;
            }
        }
        if(j != -1)
            ans = s.substr(j,s.size()-j) + ans;
        
        return ans;
        
    }
};