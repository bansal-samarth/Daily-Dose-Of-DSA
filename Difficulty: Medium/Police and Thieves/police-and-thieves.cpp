class Solution {
  public:
    int nextP(vector<char> &arr, int p) {
        int n = arr.size();
        while(p < n) {
            if(arr[p] == 'P')
                break;
            p++;
        }
        
        return p;
    }
    
    int nextT(vector<char> &arr, int t) {
        int n = arr.size();
        while(t < n) {
            if(arr[t] == 'T')
                break;
            t++;
        }
        
        return t;
    }
    
    int catchThieves(vector<char> &arr, int k) {
        int n = arr.size();
        
        int p = nextP(arr, 0);
        int t = nextT(arr, 0);
        
        int caught = 0;
        
        while(p < n && t < n) {
            
            if(abs(p - t) <= k) {
                caught++;
                
                p++;
                t++;
                p = nextP(arr, p);
                t = nextT(arr, t);
                continue;
            }
            
            if(p > t) {
                t++;
                t = nextT(arr, t);
            } else {
                p++;
                p = nextP(arr, p);
            }
        }
        
        return caught;
    }
};