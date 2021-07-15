class Solution {
public:
    int search(vector<int>& A, int target) {
        
        int n = (int)(A.size());
        
        int lo = 0;
        int hi = n-1;
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if(A[mid] == target) return mid;
            
            // A[lo ... mid] is sorted
            if(A[lo] <= A[mid]) {
                
                // and target lies in the sorted range
                if(target >= A[lo] && target <= A[mid]) {
                    hi = mid;
                } 
                else {
                    // else look in other half
                    lo = mid+1;
                }
            }
            else {
                // then the other half is sorted
                
                // and target lies in this sorted range
                if(target >= A[mid] && target <= A[hi]) 
                    lo = mid;
                else
                    hi = mid-1;
            }
        }
        if(A[lo] == target) return lo;
        return -1;
            
        
    }
};