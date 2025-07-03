class Solution {
  public:
    int totalElements(vector<int> &arr) {

        unordered_map<int, int> map;
        int maxi = -1;
        
        int left = 0;
        for(int right = 0; right < arr.size(); right++) {
            
            map[arr[right]]++;
            
            while(map.size() > 2) {
                map[arr[left]]--;
                
                if(map[arr[left]] == 0)
                    map.erase(arr[left]);
                
                left++;
            }
            
            maxi = max(maxi , right - left + 1);
        }
        
        return maxi;
    }
};