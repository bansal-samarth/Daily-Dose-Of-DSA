class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();

        int newStart = newInterval[0];
        int newEnd = newInterval[1];

        vector<vector<int>> ans;

        int i = 0;

        for(; i < n; i++) {
            if(newStart <= intervals[i][1])
                break;
            ans.push_back(intervals[i]);
        }

        if(intervals.size() && i != n)
            newStart = min(newStart, intervals[i][0]);
        for(; i < n; i++) {
            if(newEnd < intervals[i][0])
                break;
            newEnd = max(newEnd, intervals[i][1]);
        }
        ans.push_back({newStart, newEnd});

        for(; i < n; i++) {
            ans.push_back(intervals[i]);
        }

        return ans;
    }
};