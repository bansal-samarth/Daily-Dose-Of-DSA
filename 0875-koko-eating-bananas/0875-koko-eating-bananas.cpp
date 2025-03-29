class Solution {
public:
    bool isValid(vector<int>& piles, int h, int k) {
        int cnt = 0;

        for(int pile : piles) {
            cnt += (pile + (k - 1)) / k;
        }

        return cnt <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while(left < right) {
            int speed = left + (right - left) / 2;

            if(isValid(piles, h, speed))
                right = speed;
            else
                left = speed + 1;
        }

        return left;
    }
};