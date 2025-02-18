//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        deque<int> dq;
        int fault = 0;
        
        for(int i = 0; i < N; i++) {
            auto it = find(dq.begin(), dq.end(), pages[i]);
            
            if(it == dq.end()) {
                
                if(dq.size() == C) {
                    dq.pop_front();
                }
                
                fault++;
            } else {
                dq.erase(it);
            }
            
            dq.push_back(pages[i]);
        }
        
        return fault;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends