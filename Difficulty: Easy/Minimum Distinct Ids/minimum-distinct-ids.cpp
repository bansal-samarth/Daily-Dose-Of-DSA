//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int distinctIds(int arr[], int n, int m) {
        
        unordered_map<int,int> map;
        
        for(int i = 0; i < n; i++)
            map[arr[i]]++;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto pair : map)
            pq.push(pair.second);
        
        while(!pq.empty() && m > 0) {
            int mini = pq.top();
            
            if(mini <= m) {
                m -= mini;
                pq.pop();
            } else {
                m = 0;
            }
        }
        
        return pq.size();
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
        {
          cin>>arr[i];
        }
    
    	int m ;
    	cin >> m;
        Solution ob;
    	cout << ob.distinctIds(arr, n, m) << endl;
    
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends