//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    unordered_map<char,int> m;
        int ans=0;
        int r=0;
        int l=0;
        
        for(int i=0;i<pat.size();i++){
            m[pat[i]]++;
        }
        int count = m.size();
        int k = pat.size();
        
        while(r<txt.size()){\
           if(m.find(txt[r]) !=m.end()){
                m[txt[r]]--;
                if(m[txt[r]]==0) count--;
            }
            
            if((r-l+1) < k) r++;
            else if((r-l+1) == k){
                if(count ==0) ans++;
                if(m.find(txt[l])!=m.end()){
                   m[txt[l]]++;
                   if(m[txt[l]]==1) count++;
                }
               r++;
               l++;
            }
        }
        return ans;

	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends