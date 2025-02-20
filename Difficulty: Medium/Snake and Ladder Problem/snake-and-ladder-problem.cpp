//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
        unordered_map<int,int> map;
        for(int i = 0; i < 2*N; i += 2)
            map[arr[i]] = arr[i+1];
        
        
        queue<int> q;
        q.push(1);
        
        int minMoves = 1;
        while(!q.empty()) {
            int n = q.size();
            
            for(int k = 0; k < n; k++) {
                int curr = q.front();
                q.pop();
                
                for(int i = 1; i <= 6; i++) {
                    int next = curr + i;
                    
                    if(map.count(next))
                        next = map[next];
                    
                    if(next > 30) continue;
                    else if(next == 30)
                        return minMoves;
                    else
                        q.push(next);
                }
            }
            
            minMoves++;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends