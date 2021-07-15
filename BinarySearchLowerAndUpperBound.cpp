// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class Solution {
public:
    vector<int> searchRange(vector<int>& A, int target) {
        
        int n = (int)(A.size());
        
        int lo = 0; int hi = n-1;
        // finding lower bound
        
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if(A[mid] >= target) 
                hi = mid;
            else 
                lo = mid+1;
        }
        vector<int> ans;
        // Assert lo == hi
        
        if(A[lo] == target) ans.push_back(lo);
        else {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        } 
        
        lo = 0; hi = n-1;
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if(A[mid] <= target) {
                lo = mid;
            } else {
                hi = mid-1;
            }
        }
        
        if(A[lo] == target) ans.push_back(lo);
        return ans;
    }
};