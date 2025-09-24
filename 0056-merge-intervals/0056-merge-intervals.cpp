class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        int start = intervals[0][0];
        int connect = intervals[0][1];
        for(int i = 0; i < n; i++) {

            if(connect < intervals[i][0]) {
                ans.push_back({start, connect});
                start = intervals[i][0];
            }
            
            connect = max(connect, intervals[i][1]);
        }

        ans.push_back({start, connect});

        return ans;
    }
};