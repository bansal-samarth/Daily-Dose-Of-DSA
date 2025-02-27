class Solution {
public:
    int minInsertions(string s) {
        int mini = 0;
        stack<int> st;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                if(st.empty() || st.top() == 2)
                    st.push(2);
                else {
                    st.pop();
                    st.push(2);
                    mini++;
                }
            } else {
                if(st.empty()) {
                    st.push(1);
                    mini++;
                } else if(st.top() == 1) {
                    st.pop();
                } else {
                    st.pop();
                    st.push(1);
                }
            }
        }

        while(!st.empty()) {
            mini += st.top();
            st.pop();
        }

        return mini;
    }
};