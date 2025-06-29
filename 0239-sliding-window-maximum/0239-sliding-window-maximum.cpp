class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> ans;

        deque<int> dq;
        for(int i = 0; i < nums.size(); i++) {

            while(!dq.empty() && dq.back() < nums[i])
                dq.pop_back();
            
            if(dq.size() == k)
                dq.pop_front();
            
            dq.push_back(nums[i]);

            if(i >= k-1)
                ans.push_back(dq.front());
        }

        return ans;
    }
};