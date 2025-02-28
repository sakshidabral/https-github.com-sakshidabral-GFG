//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        if (arr.empty()) return 0;
        stack<int> st;

        for (auto& s : arr) {
            if (isdigit(s[0]) || (s.size() > 1 && isdigit(s[1]))) {  // Handling negative numbers
                st.push(stoi(s));
            } else {
                if (st.size() < 2) return -1;  // Not enough operands
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                int val = 0;
                
                if (s == "+") val = a + b;
                else if (s == "-") val = a - b;
                else if (s == "*") val = a * b;
                else if (s == "/") {
                    if (b == 0) return -1;  // Handling divide by zero
                    val = a / b;
                } else return -1;  // Invalid operator
                
                st.push(val);
            }
        }

        return st.size() == 1 ? st.top() : -1;  // Ensure a valid result
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends