//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);


// } Driver Code Ends
class Solution
{
    public:
    vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col) {
        unordered_set<string> s;
        vector<vector<int>>ans;
        
        for(int i=0;i<row;i++) {
            string nstr = "";
            vector<int>temp;
            
            for(int j=0;j<col;j++){
                nstr += to_string(M[i][j]);
                temp.push_back(M[i][j]);
            }
            
            if(s.find(nstr)==s.end()){
                ans.push_back(temp);
                s.insert(nstr);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	Solution ob;
    	vector<vector<int>> vec = ob.uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends