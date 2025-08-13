class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> left(n);
        vector<int> right(n);

        stack<int> st;
        st.push(-1);

        for(int i = 0; i < n; i++) {

            while(st.top() != -1 && heights[i] <= heights[st.top()])
                st.pop();

            left[i] = st.top();
            st.push(i);
        }

        stack<int> s;
        s.push(n);

        for(int i = n-1; i >= 0; i--) {

            while(s.top() != n && heights[i] <= heights[s.top()])
                s.pop();

            right[i] = s.top();
            s.push(i);
        }

        int maxArea = 0;

        for(int i = 0; i < n; i++) {
            int area = (right[i] - left[i] - 1) * heights[i];
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};