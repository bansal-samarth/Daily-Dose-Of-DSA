//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class StackQueue {
  private:
    stack<int> s1;
    stack<int> s2;

  public:
    void push(int B) {
        // code here
        s1.push(B);
    }

    int pop() {
        // code here
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        
        int front = -1;
        
        if(!s2.empty()) {
            front = s2.top();
            s2.pop();
        }
        
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        
        return front;
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    while (T--) {
        StackQueue *sq = new StackQueue();

        int Q;
        cin >> Q;
        while (Q--) {
            int QueryType = 0;
            cin >> QueryType;
            if (QueryType == 1) {
                int a;
                cin >> a;
                sq->push(a);
            } else if (QueryType == 2) {
                cout << sq->pop() << " ";
            }
        }
        cout << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends