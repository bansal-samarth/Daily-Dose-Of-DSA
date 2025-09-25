class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        if(nums.size() == 1)
            return nums;
        
        int one = INT_MIN;
        int count1 = -1;
        int two = INT_MIN;
        int count2 = -1;

        for(int i = 0 ; i < nums.size(); i++)
        {
            if(count1 == -1 && nums[i] != two)
            {
                count1++;
                one = nums[i];
            }

            else if(count2 == -1 && nums[i] != one)
            {
                count2++;
                two = nums[i];
            }
            else if(nums[i] == one) count1++;

            else if(nums[i] == two) count2++;

            else
            {
                count1--;
                count2--;
            }
        }

        cout << one << endl << two <<endl;

        int freq1 = 0; int freq2 = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == one)
                freq1++;
            
            else if(nums[i] == two)
                freq2++;
        }

        vector<int> ans;

        if(freq1 > nums.size()/3)
            ans.push_back(one);

        if(freq2 > nums.size()/3)
            ans.push_back(two);
        
        return ans;
    }
};











/*
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        if (nums.size() == 1) return nums;
        
        int first = INT_MIN;
        int count1 = 0;
        int second = INT_MIN;
        int count2 = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            
            if(count1 == 0 && second != nums[i])
            {
                first = nums[i];
                count1 = 1;
            }
            else if(count2 == 0 && first != nums[i])
            {
                second = nums[i];
                count2 = 1;
            }
            else if(first == nums[i])
                count1++;
            else if(second == nums[i])
                count2++;
            else
            {
                count1--;
                count2--;
            }
        }

        int freq1 = 0 , freq2 = 0;

        for(int i: nums)
        {
            if(first != INT_MIN && first == i)
                freq1++;
            else if (second != INT_MIN && second == i)
                freq2++;
        }


        vector<int> ans;

        if(freq1 > nums.size() / 3)
            ans.push_back(first);

        if(freq2 > nums.size() / 3)
            ans.push_back(second);
        
        cout << first << endl << second << endl;
        
        return ans;
    }
};
*/