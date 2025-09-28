class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> umap;

        for(int i = 0; i < nums.size(); i++)
        {
            int j = target - nums[i];

            if(umap.find(j) == umap.end())
                umap[nums[i]] = i;
            else
                return {i , umap[j]};
        }

        return {};
    }
};

/*
    vector<int> twoSum(vector<int>& nums, int target) {

        vector <int> ans;

        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }

        return ans;
    }
*/