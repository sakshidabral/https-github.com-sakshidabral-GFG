//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        deque<int> dq;
        vector<int> ans;
        int n = arr.size();
    
        for (int i = 0; i < n; i++) {
            // Remove elements out of window
            if (!dq.empty() && dq.front() == i - k) 
                dq.pop_front();
    
            // Remove smaller elements (they will never be max)
            while (!dq.empty() && arr[dq.back()] <= arr[i]) 
                dq.pop_back();
    
            // Add current element index
            dq.push_back(i);
    
            // Store max when the first window is formed
            if (i >= k - 1) 
                ans.push_back(arr[dq.front()]);
        }
    
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends