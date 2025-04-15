class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int maxi = 0;

        for(int i=0; i<k; i++)
        {
            maxi += nums[i];
        }

        int current_average = maxi;

        for(int i = 1; i <= nums.size()-k ; i++)
        {
            current_average += nums[k + i - 1] - nums[i - 1];
            maxi = max(maxi, current_average);
        }

        double ans = (double)maxi/(double)k;

        return ans;
    }
};

// class Solution {
// public:
//     double findMaxAverage(vector<int>& nums, int k) {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
//         double maxi = 0, win = 0;

//         for (int i = 0; i < k; i++) {
//             win += nums[i];
//         }

//         maxi = win / k;  

//         for (int i = k; i < nums.size(); i++) {
//             win += nums[i] - nums[i - k];  
//             maxi = max(maxi, win / k);
//         }

//         return maxi;
//     }
// };