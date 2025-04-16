class Solution {
public:
    string decodeString(string s) {
        stack<string> st;

        for(char ch : s) {
            if(ch == ']') {
                string word = "";
                while(!st.empty() && isalpha(st.top()[0])) {
                    word = st.top() + word;
                    st.pop();
                }
                st.pop();

                string num = "";
                while(!st.empty() && isdigit(st.top()[0])) {
                    num = st.top() + num;
                    st.pop();
                }

                int n = stoi(num);
                string res = "";
                for(int i = 0 ; i < n; i++) {
                    res += word;
                }

                st.push(res);
            }
            else {
                // converts their ASCII value to string
                st.push(string(1, ch));
            }
        }

        string ans = "";
        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};