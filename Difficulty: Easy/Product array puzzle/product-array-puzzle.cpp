//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
        long long int sum = 1;
        int zero = 0;
        for(auto n : nums){
            if(n!=0) sum *= n;
            else zero++;
        }
        vector<long long int> ans;
        if(zero==1){
            for(int i=0;i<nums.size();i++){
                if(nums[i]==0){
                ans.push_back(sum);
                 }else ans.push_back(0);
            }
        }else if(zero>1){
            for(int i=0;i<nums.size();i++){
                ans.push_back(0);
            }
        }else{
            for(int i=0;i<nums.size();i++){
                ans.push_back(sum/nums[i]);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends