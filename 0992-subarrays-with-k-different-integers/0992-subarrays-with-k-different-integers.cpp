class Solution {
public:
    int countSubsets(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int,int> map;

        int left = 0;
        for(int right = 0; right < nums.size(); right++) {
            map[nums[right]]++;

            while(k < map.size()) {
                map[nums[left]]--;
                if(map[nums[left]] == 0)
                    map.erase(nums[left]);
                left++;
            }

            count += right - left + 1;
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countSubsets(nums, k) - countSubsets(nums, k-1);
    }
};