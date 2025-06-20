class Solution {
  public:
    string caseSort(string& s) {
        int n = s.size();
        
        string sorted = s;
        sort(sorted.begin(), sorted.end());
        
        int low = 0;
        int upp = 0;
        
        while(low < n) {
            if(sorted[low] < 97)
                break;
            low++;
        }
        
        while(upp < n) {
            if(sorted[upp] >= 97)
                break;
            upp++;
        }
        
        for(int i = 0; i < n; i++) {
            if(s[i] < 97) {
                s[i] = sorted[low];
                
                low++;
                while(low < n) {
                    if(sorted[low] < 97)
                        break;
                    low++;
                }
            } else {
                s[i] = sorted[upp];
                
                upp++;
                while(upp < n) {
                    if(sorted[upp] >= 97)
                        break;
                    upp++;
                }
            }
        }
        
        return s;
    }
};