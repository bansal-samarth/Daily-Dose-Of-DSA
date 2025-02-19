//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    Node* divide(vector<Node*>& arr, int low, int high) {
        if(low < high) {
            int mid = low + (high - low) / 2;
            
            Node* left = divide(arr, low, mid);
            Node* right = divide(arr, mid+1, high);
            
            return conquer(left, right);
        }
        
        return arr[low];
    }
    Node* conquer(Node* left, Node* right) {
        if(!left) return right;
        if(!right) return left;
        
        if(left->data < right->data) {
            left->next = conquer(left->next, right);
            return left;
        }
        
        right->next = conquer(left, right->next);
        return right;
    }
    Node* mergeKLists(vector<Node*>& arr) {
        return divide(arr, 0, arr.size() - 1);
    }
};


//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->next = newNode;
                temp = temp->next;
            }
            v[i] = head->next;
        }

        Solution ob;
        Node* head = ob.mergeKLists(v);
        printList(head);
    }

    return 0;
}

// } Driver Code Ends