class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        for(int i = 1; i <= numRows; i++) {
            vector<int> row(i, 1);
            triangle.push_back(row);
        }

        for(int i = 2; i <= numRows - 1; i++) {
            for(int j = 1; j < i; j++) {
                triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
            }
        }

        return triangle;
    }
};