//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimizeCost(vector<int>& arr, int& k) {
        int n = arr.size();
        vector<int> dp(n);
        
        dp[0] = 0;
        for(int i=1;i<n;i++){
            int minSteps = INT_MAX;
            for(int j=1;j<=k;j++){
                if(i-j >= 0){
                    int jump = dp[i-j] + abs(arr[i]-arr[i-j]);
                    minSteps = min(jump, minSteps);
                }
            }
            dp[i] = minSteps;
        }
        
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(arr, k);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends