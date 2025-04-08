class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int> map;

        int n = nums.size();
        for(int i = n-1; i >= 0; i--) {
            map[nums[i]]++;

            if(map[nums[i]] == 2) {
                return ((i+1) + 2) / 3;
            }
        }

        return 0;
    }
};