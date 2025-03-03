//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        int l = 0, r = 0;
        int maxLen = 0, startIdx = 0;
        
        multiset<int> window;
        while (r < n){
            window.insert(arr[r]);
            
            // Ensure all elements in the window satisfy |max - min| ≤ x
            while(*window.rbegin() - *window.begin() > x) {
                window.erase(window.find(arr[l]));
                l++;
            }
            
            // Update max length and store starting index
            if(r - l + 1 > maxLen) {
                maxLen = r - l + 1;
                startIdx = l;
            }
            
            r++;
        }
        
        // Extract the longest valid subarray
        vector<int> result(arr.begin() + startIdx, arr.begin() + startIdx + maxLen);
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends