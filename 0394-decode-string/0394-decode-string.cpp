class Solution {
public:
    string decodeString(string s) {
        stack<string> st;

        for(int i = 0; i < s.size(); i++) {
            
            if(s[i] == ']') {
                
                string mini = "";
                while(!st.empty() && st.top()[0] != '[') {
                    mini += st.top();
                    st.pop();
                }
                st.pop();

                string digits = "";
                while(!st.empty() && isdigit(st.top()[0])) {
                    digits = st.top() + digits;
                    st.pop();
                }
                
                string word = "";
                int num = stoi(digits);
                for(int k = 0; k < num; k++) {
                    word += mini;
                }

                st.push(word);
            }
            else {
                st.push(string(1, s[i]));
            }
        }

        string decoded = "";
        while(!st.empty()) {
            decoded += st.top();
            st.pop();
        }

        reverse(decoded.begin(), decoded.end());

        return decoded;
    }
};