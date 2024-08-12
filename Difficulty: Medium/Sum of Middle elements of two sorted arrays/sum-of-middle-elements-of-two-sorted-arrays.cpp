//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        int n = arr1.size();
        int mid1 = (n+n)/2 - 1; //first mid element
        int mid2 = mid1+1;
        
        int i=0, j=0, ans=0;
        int count = 0;
        
        while (i < n && j < n) {
        int curr;
            if (arr1[i] < arr2[j]) {
                curr = arr1[i++];
            } else {
                curr = arr2[j++];
            }
    
            if (count == mid1 || count == mid2) {
                ans += curr;
            }
            
            count++;
            if (count > mid2) break;  // Stop early if both middle elements are found
        }
        
        // Handle remaining elements if one array is exhausted
        while (i < n && count <= mid2) {
            if (count == mid1 || count == mid2) {
                ans += arr1[i];
            }
            i++;
            count++;
        }
        
        while (j < n && count <= mid2) {
            if (count == mid1 || count == mid2) {
                ans += arr2[j];
            }
            j++;
            count++;
        }
    
        return ans;
    }
};

//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends