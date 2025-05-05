//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        int n = arr.size() ; 
        int i = 0 , j = n-1 ;
        
        while(i <= j) {
            int mid = (i + j) >> 1 ;
            
            if(arr[mid] == target) 
                return mid ;
            
            else if(mid > 0 && arr[mid-1] == target) return mid-1 ; 
            else if(mid < n-1 && arr[mid+1] == target) return mid+1 ; 
            
            else if(arr[mid] > target) j = mid -1 ; 
            else i = mid+1 ; 
        }
        return -1 ; 
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        int target;
        cin >> target;
        cin.ignore();
        Solution sln;
        int ans = sln.findTarget(arr, target);
        cout << ans << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends