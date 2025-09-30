class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n1 = -1;
        int c1 = 0;
        int n2 = -1;
        int c2 = 0;

        for(int i : nums) {
            if(c1 == 0 && n2 != i) {
                n1 = i;
                c1++;
            }
            else if(c2 == 0 && n1 != i) {
                n2 = i;
                c2++;
            }
            else if(n1 == i) c1++;
            else if(n2 == i) c2++;
            else {
                c1--;
                c2--;
            }
        }

        int s = nums.size() / 3;

        int cnt1 = ranges::count(nums, n1);
        int cnt2 = ranges::count(nums, n2);
        
        vector<int> ans;
        if(cnt1 > s)
            ans.push_back(n1);
        if(cnt2 > s)
            ans.push_back(n2);
        
        return ans;
    }
};