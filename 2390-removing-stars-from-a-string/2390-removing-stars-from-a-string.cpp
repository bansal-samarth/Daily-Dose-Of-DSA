class Solution {
public:
    string removeStars(string s) {
        stack<char> st;

        for(char ch : s) {
            if(ch == '*') {
                if(!st.empty())
                    st.pop();
            } else {
                st.push(ch);
            }
        }

        string res = "";

        while(!st.empty()) {
            res += st.top();
            st.pop();
        }

        ranges::reverse(res);

        return res;
    }
};