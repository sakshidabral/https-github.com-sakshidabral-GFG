//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // Your code here
        if(s1.size()!=s2.size()) return false;
        map<char,int> m1;
        for(char c : s1){
            m1[c]++;
        }
        for(char c : s2){
            if(m1.find(c) == m1.end()) return false;
            m1[c]--;
        }
        for(auto i : m1){
            if(i.second!=0) return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends