class Solution {
  public:
    bool isValid(vector<int>& arr, int k, int n) {
        int sum = 0;
        
        for(int num : arr) {
            int div = num / n;
            int rem = num % n;
            
            sum += div;
            sum += rem ? 1 : 0;
        }
        
        return sum <= k;
    }
    int smallestDivisor(vector<int>& arr, int k) {
        int left = 1;
        int right = *max_element(arr.begin(), arr.end());
        
        while(left < right) {
            int mid = left + (right - left) / 2;
            
            if(isValid(arr, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};
