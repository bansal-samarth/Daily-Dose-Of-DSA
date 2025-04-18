//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Node {
public:
    Node* children[26];
    bool endOfWord;

    Node() {
        for(int i = 0; i < 26; i++)
            children[i] = NULL;
        endOfWord = false;
    }
};

class Trie {
  public:
    Node* root;
    
    Trie() {
        root = new Node();
    }

    void insert(string &word) {
        
        Node* p = root;
        for(char ch : word) {
            
            if(!p->children[ch - 'a']) {
                p->children[ch - 'a'] = new Node();
            }
            
            p = p->children[ch - 'a'];
        }
        
        p->endOfWord = true;
    }

    bool search(string &word) {
        
        Node* p = root;
        for(char ch : word) {
            
            if(!p->children[ch - 'a']) {
                return false;
            }
            
            p = p->children[ch - 'a'];
        }
        
        return p->endOfWord;
    }

    bool isPrefix(string &word) {
        
        Node* p = root;
        for(char ch : word) {
            
            if(!p->children[ch - 'a']) {
                return false;
            }
            
            p = p->children[ch - 'a'];
        }
        
        return true;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int q;
        cin >> q;
        cin.ignore();
        vector<bool> ans;
        Trie ob;
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            string s;
            cin >> s;
            cin.ignore();
            if (x == 1) {
                ob.insert(s);
            } else if (x == 2) {
                ans.push_back(ob.search(s));
            } else if (x == 3) {
                ans.push_back(ob.isPrefix(s));
            }
        }
        cout << boolalpha;
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends