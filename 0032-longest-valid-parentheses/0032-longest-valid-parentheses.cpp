class Solution {
public:
    int longestValidParentheses(string s) {
        vector <int> vec; 

        stack <char> st;

        int ans = 0;

        for(int i=0; s[i]!='\0'; i++)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                st.push(s[i]);
                vec.push_back(NULL);
            }

            else if(st.empty() || (s[i]==')' && st.top() != '('))
            {
                vec.push_back(-1);
            }

            else
            {
                for(int i=vec.size()-1 ;i>=0; i--)
                {
                    if(vec[i]==NULL)
                    {
                        vec[i]=2;
                        break;
                    }
                }
                st.pop();
            }
        }

        int maxx = 0;
        for (int i=0; i<vec.size(); i++)
        {
            if( vec[i]>0 )
            {
                maxx += vec[i];
                ans = max(ans,maxx);
            }
            else
            {
                maxx = 0;
            }
        }
        return ans;
    }
};