class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = potions.size();
        ranges::sort(potions);

        vector<int> ans;
        for(int s = 0; s < spells.size(); s++) {

            int left = 0;
            int right = potions.size() - 1;

            if((long long) spells[s] * potions[right] < success) {
                ans.push_back(0);
                continue;
            }

            while(left < right) {
                int mid = left + (right - left) / 2;

                long long val = (long long) spells[s] * potions[mid];
                if(val >= success)
                    right = mid;
                else
                    left = mid + 1;
            }

            ans.push_back(n - right);
        }

        return ans;
    }
};