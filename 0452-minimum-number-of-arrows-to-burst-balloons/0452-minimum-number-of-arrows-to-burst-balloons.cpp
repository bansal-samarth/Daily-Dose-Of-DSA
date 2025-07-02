class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(), points.end());

        int start = points[0][0];
        int end = points[0][1];

        int arrows = 1;

        for(int i = 1; i < points.size(); i++) {
            if(end >= points[i][0]) {
                end = min(end, points[i][1]);
            } else {
                arrows++;
                start = points[i][0];
                end = points[i][1];
            }
        }

        return arrows;
    }
};