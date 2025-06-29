class Solution {
  public:
    bool check(vector<int>& arr, int k, int mid) {
        int cnt = 1;
        
        int sum = 0;
        for(int num : arr) {
            sum += num;
            
            if(sum > mid) {
                cnt++;
                sum = num;
            }
        }
        
        return cnt <= k;
    }
    
    int splitArray(vector<int>& arr, int k) {
        
        int left = *max_element(arr.begin(), arr.end());
        int right = accumulate(arr.begin(), arr.end(), 0) / k + left;
        
        while(left < right) {
            int mid = left + (right - left) / 2;
            
            if(check(arr, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};