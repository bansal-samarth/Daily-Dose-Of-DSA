class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = 1;

        int cnt = 0;
        int sum = 0;
        for(int num : nums) {
            sum += num;

            int complement = sum - k;

            if(map.find(complement) != map.end()) {
                cnt += map[complement];
            }

            map[sum]++;
        }

        return cnt;
    }
};