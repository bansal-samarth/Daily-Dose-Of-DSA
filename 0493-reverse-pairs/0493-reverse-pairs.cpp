class Solution {
public:
    int ans;
    
    void merge(vector<int> &arr, int low, int mid, int high) {
        
        int i = low;
        int j = mid + 1;

        while(i <= mid) {
            // while(i <= mid && arr[i] < 2 * arr[j]) 
            //     i++;
            
            // if(i > mid) break;

            while(j <= high && (long)arr[i] > (long)2 * arr[j]) 
                j++;

            ans += j - mid - 1;
            
            i++;
        }

        vector<int> brr(high - low + 1, -1);
        
        i = low;
        j = mid + 1;
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

    int reversePairs(vector<int>& nums) {
        ans = 0;

        mergeSort(nums, 0, nums.size()-1);

        return ans;
    }
};