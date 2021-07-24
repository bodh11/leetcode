// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& A, int target) {

        int n = (int)(A.size());
        
        if(n == 0) {
            vector<int> t; t.push_back(-1); t.push_back(-1);
            return t;
        }

        // first occurence of a number in the sorted array
        // binary function: A[x] < target
        // applying above function on array would make it like : [0 0 0 0 1 1 1 1 1]
        // our job is to find the first 1 in this sequence
        vector<int> ans;

        int lo = 0; int hi = n - 1;
        while(hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            if(A[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        int firstPos = -1;
        if(A[lo] == target) firstPos = lo;
        else if(A[hi] == target) firstPos = hi;

        ans.push_back(firstPos);

        // last occurence of a number in a sorted array
        // binary function : A[x] <= target
        // applying above function on array would make it like : [1 1 1 1 1 0 0 0 0]
        // find last 1
        lo = 0; hi = n - 1;
        while(hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            if(A[mid] <= target) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        int lastPos = -1;
        if(A[hi] == target) lastPos = hi;
        else if(A[lo] == target) lastPos = lo;
        ans.push_back(lastPos);
        return ans;
    }
};

int main() {

    Solution solve;
    int n; cin >> n;
    vector<int> A;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        A.push_back(a);
    }

    int target; cin >> target;

    vector<int> ans = solve.searchRange(A, target);

    cout << ans[0] << " : " << ans[1] << endl;
}