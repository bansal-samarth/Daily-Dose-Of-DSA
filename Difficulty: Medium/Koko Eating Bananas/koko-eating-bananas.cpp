class Solution {
  public:
    bool isValid(vector<int>& arr, int k, int n) {
        int hours = 0;
        
        for(int banana : arr) {
            int div = banana / n;
            int rem = banana % n;
            hours += div;
            hours += rem > 0 ? 1 : 0;
        }
        
        return hours <= k;
    }
    int kokoEat(vector<int>& arr, int k) {
        int left = 1;
        int right = *max_element(arr.begin(), arr.end());
        
        while(left < right) {
            int mid = left + (right - left)/2;
            
            if(isValid(arr, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};