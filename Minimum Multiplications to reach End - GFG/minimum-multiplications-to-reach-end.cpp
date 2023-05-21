//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int,int>>q;
        q.push({0,start});
        vector<int> dist(100000,1e9);
        dist[start]=0;
        int modu= 100000;
        while(!q.empty()){
            int node= q.front().second;
            int dis= q.front().first;
            q.pop();
            for(auto it: arr){
                int ele= (node*it)%modu;
                if(dis+1<dist[ele]){
                    dist[ele]=dis+1;
                    if(ele==end) return dist[ele];
                    q.push({dis+1, ele});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends