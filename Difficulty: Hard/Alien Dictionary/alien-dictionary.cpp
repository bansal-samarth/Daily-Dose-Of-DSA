//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string findOrder(vector<string> &words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;
        
        for(string word : words) {
            for(char ch : word) {
                adj[ch] = {};
                indegree[ch] = 0;
            }
        }
        
        for(int i = 0; i < words.size() - 1; i++) {
            string first = words[i];
            string second = words[i+1];
            
            int minLen = min(first.size(), second.size());
            
            if(first.size() > second.size() && first.substr(0, minLen)
                == second.substr(0, minLen))
                return "";
            
            for(int it = 0; it < minLen; it++) {
                if(first[it] != second[it]) {
                    
                    adj[first[it]].push_back(second[it]);
                    indegree[second[it]]++;
                    break;
                }
            }
        }
        
        queue<char> q;
        string res = "";

        for(auto it : indegree) {
            if(it.second == 0) {
                q.push(it.first);
            }
        }
        
        while(!q.empty()) {
            char letter = q.front();
            q.pop();
            
            res += letter;
            
            for(char ch : adj[letter]) {
                indegree[ch]--;
                
                if(indegree[ch] == 0) {
                    q.push(ch);
                }
            }
        }
        
        return res.size() == indegree.size() ? res : "";
    }
};


//{ Driver Code Starts.

bool validate(const vector<string> &original, const string &order) {
    unordered_map<char, int> mp;
    for (const string &word : original) {
        for (const char &ch : word) {
            mp[ch] = 1;
        }
    }
    for (const char &ch : order) {
        if (mp.find(ch) == mp.end())
            return false;
        mp.erase(ch);
    }
    if (!mp.empty())
        return false;

    for (int i = 0; i < order.size(); i++) {
        mp[order[i]] = i;
    }

    for (int i = 0; i < original.size() - 1; i++) {
        const string &a = original[i];
        const string &b = original[i + 1];
        int k = 0, n = a.size(), m = b.size();
        while (k < n and k < m and a[k] == b[k]) {
            k++;
        }
        if (k < n and k < m and mp[a[k]] > mp[b[k]]) {
            return false;
        }
        if (k != n and k == m) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        string curr;
        vector<string> words;
        while (ss >> curr)
            words.push_back(curr);

        vector<string> original = words;

        Solution ob;
        string order = ob.findOrder(words);

        if (order.empty()) {
            cout << "\"\"" << endl;
        } else {
            cout << (validate(original, order) ? "true" : "false") << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends