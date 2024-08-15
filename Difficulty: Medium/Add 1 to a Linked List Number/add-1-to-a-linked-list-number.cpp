//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* addOne(Node* head) {
        if (!head) return nullptr;
    
        Node* lastNonNine = nullptr;
        Node* current = head;
    
        // Traverse the list to find the last non-nine node
        while (current) {
            if (current->data != 9) {
                lastNonNine = current;
            }
            current = current->next;
        }
    
        // If no non-nine node was found, it means all nodes are 9
        if (!lastNonNine) {
            Node* newHead = new Node(1);  // Create a new head node with value 1
            newHead->next = head;
    
            // Set all existing nodes' values to 0
            current = head;
            while (current) {
                current->data = 0;
                current = current->next;
            }
    
            return newHead;
        }
    
        // Increment the last non-nine node
        lastNonNine->data += 1;
    
        // Set all nodes after the last non-nine node to 0
        current = lastNonNine->next;
        while (current) {
            current->data = 0;
            current = current->next;
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
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends