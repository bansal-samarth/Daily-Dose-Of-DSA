class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extra) {
        int maxi = *max_element(candies.begin(), candies.end());

        vector<bool> ans;
        for(int candy : candies) {
            ans.push_back(maxi <= candy + extra);
        }

        return ans;
    }
};