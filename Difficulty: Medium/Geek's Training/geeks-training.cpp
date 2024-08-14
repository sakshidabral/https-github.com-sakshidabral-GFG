//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int day, int last, vector<vector<int>>& arr, vector<vector<int>>& dp){
        if(dp[day][last] != -1) return dp[day][last];
        
        //base case : when we reach 0th day
        if(day == 0){
            int maxx = 0;
            //chose diff activity than last one
            for(int i=0;i<=2;i++){
                if(i!=last)
                maxx = max(arr[0][i], maxx);
            }
            return dp[day][last] = maxx;
        }
        
        int maxx = 0;
        for(int i=0;i<=2;i++){
            if(i!=last){
                int activity = arr[day][i] + solve(day-1, i, arr, dp);
                maxx = max(activity, maxx);
            }
        }
        
        return dp[day][last] = maxx;
    }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return solve(n-1,3,arr,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends