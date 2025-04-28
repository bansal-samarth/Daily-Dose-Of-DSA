//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends

/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    Node* segregate(Node* head) {
        
        Node* zeroHead = new Node(0);
        Node* oneHead = new Node(0);
        Node* twoHead = new Node(0);
        
        Node* z = zeroHead;
        Node* o = oneHead;
        Node* t = twoHead;
        
        Node* p = head;
        
        for(; p != NULL; p = p->next) {
            
            if(p->data == 0) {
                z->next = p;
                z = p;
            }
            else if(p->data == 1) {
                o->next = p;
                o = p;
            } 
            else {
                t->next = p;
                t = p;
            } 
        }
        
        // After creating the three chains
        z->next = NULL;  // Terminate zero list
        o->next = NULL;  // Terminate one list 
        t->next = NULL;  // Terminate two list
        
        Node* ans = new Node(-1);
        
        Node* it = ans;
        
        if(zeroHead->next) {
            it->next = zeroHead->next;
            it = z;
        }
        
        if(oneHead->next) {
            it->next = oneHead->next;
            it = o;
        }
        
        if(twoHead->next) {
            it->next = twoHead->next;
            it = t;
        }
        
        return ans->next;
    }
};



//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends