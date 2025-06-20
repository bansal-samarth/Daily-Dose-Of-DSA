class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        int n = arr.size();
        
        if(n % k)
            return false;
            
        unordered_map<int,int> map;
        
        for(int num : arr)
            map[num]++;
        
        // int cnt = n;
        
        sort(arr.begin(), arr.end());
        
        int i = 0;
        while(i < n) {
            
            if(map[arr[i]] == 0) {
                i++;
                continue;
            }
            
            for(int j = 0; j < k; j++) {
                
                int val = arr[i] + j;
                
                if(map.find(val) == map.end())
                    return false;
                
                if(map[val] == 0)
                    return false;
                
                map[val]--;
            }
            
            i++;
        }
        
        return true;
    }
};