class Solution {
  public:
    int maxSum(vector<int> &arr) {
        
        int sum = 0;
        
        for(int i = 0; i < 2; i++)
            sum += arr[i];
        
        int maxi = sum;
        
        for(int i = 2; i < arr.size(); i++) {
            sum += arr[i] - arr[i - 2];
            
            maxi = max(maxi, sum);
        }
        
        return maxi;
    }
};