//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp){
        
        if(i==s1.size() && j!=s2.size()){ // s1 < s2
            return s2.size()-j;
        }
        
        if(j==s2.size() && i!=s1.size()){ // s2 < s1
            return s1.size()-i;
        }
        
        if(i==s1.size() && j==s2.size()){ //both traversed completely
            return 0;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){ //if char matched
            return solve(s1,s2,i+1,j+1,dp);
        }
        else {
            int insert = solve(s1,s2,i,j+1,dp)+1;
            int remove = solve(s1,s2,i+1,j,dp)+1;
            int replace = solve(s1,s2,i+1,j+1,dp)+1;
            
            dp[i][j] = min(insert, min(remove, replace));
        }
        
        return dp[i][j];
    }
    int editDistance(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(str1, str2, 0, 0, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends