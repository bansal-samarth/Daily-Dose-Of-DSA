class Solution {
  public:
    int ans;
    
    void merge(vector<int> &arr, int low, int mid, int high) {
        
        vector<int> brr(high - low + 1, -1);
        
        int i = low;
        int j = mid + 1;
        int k = 0;
        while(k < brr.size()) {
            int a = i <= mid ? arr[i] : INT_MAX;
            int b = j <= high ? arr[j] : INT_MAX;
            
            if(a <= b) {
                brr[k++] = a;
                i++;
            }
            else {
                brr[k++] = b;
                j++;
                ans += mid - i + 1;
            }
        }
        
        for(int b : brr) {
            arr[low++] = b;
        }
        
        return;
    }
    
    void mergeSort(vector<int> &arr, int low, int high) {
        if(low >= high) return;
        
        int mid = low + (high - low) / 2;
        
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        
        merge(arr, low, mid, high);
    }
    
    int inversionCount(vector<int> &arr) {
        ans = 0;
        
        mergeSort(arr, 0, arr.size() - 1);
        
        return ans;
    }
};