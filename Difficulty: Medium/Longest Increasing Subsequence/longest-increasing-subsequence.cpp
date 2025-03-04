//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int lis(vector<int>& arr) {
        // code here
        int n = arr.size();
        size_t size = 0;
        vector<int> v;
        
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(v.begin(), v.end(), arr[i]);
            if (it == v.end()) {
                v.push_back(arr[i]); // Extend LIS
            } else {
                *it = arr[i]; // Replace element to maintain increasing order
            }
            size = max(size, v.size());
        }
        
        return size;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends