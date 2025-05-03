//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

// User function Template for C++

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/

class Solution {
  public:
    Node *primeList(Node *head) {
        
        int maxi = 1;
        
        Node* p = head;
        for(; p != NULL; p = p->next)
            maxi = max(maxi, p->val);
        
        vector<int> prime;
        prime.push_back(2);
        
        for(int num = 3; num <= maxi + 72; num++) {
            bool isPrime = true;
            for(int d = 2; d <= (int)sqrt(num); d++) {
                if(num % d == 0) {
                    isPrime = false;
                    break;
                }
            }
            if(isPrime) prime.push_back(num);
        }
        
        p = head;
        for(; p != NULL; p = p->next) {
            int val = p->val;
            
            // Check if the value is already prime
            bool isAlreadyPrime = binary_search(prime.begin(), prime.end(), val);
            if(isAlreadyPrime) {
                continue;  // No need to change if already prime
            }
            
            auto high = lower_bound(prime.begin(), prime.end(), val) - prime.begin();
            auto low = high - 1;
            
            if(low < 0) {
                p->val = 2;
                continue;
            }
            
            p->val = abs(p->val - prime[low]) > abs(p->val - prime[high])
                        ? prime[high] : prime[low];
        }
        
        return head;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.primeList(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends