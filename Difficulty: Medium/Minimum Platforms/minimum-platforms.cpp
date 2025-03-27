//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int maxi = 1;
        int plat = 0;
        
        int i = 0, j = 0;
        while(i < arr.size()) {
            // Arriving 
            if(arr[i] <= dep[j]) {
                plat++;
                maxi = max(maxi, plat);
                i++;
            }
            // Depart
            else {
                plat--;
                j++;
            }
        }
        
        return maxi;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, dep;
        string input;

        // Read first array (arr)
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Read second array (dep)
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            dep.push_back(number);
        }

        // Assuming Solution class is defined elsewhere with a method findPlatform
        Solution ob;
        cout << ob.findPlatform(arr, dep);

        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends