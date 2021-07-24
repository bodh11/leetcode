using namespace std;

#include <iostream>
#include <vector>

class SubsetSum {
public:
  bool canPartition(const vector<int> &num, int sum) {
    
    int n = (int)(num.size());

    vector<int> dp(sum+1, 0);
    
    // sum of size 0 is possible
    dp[0] = 1;

    for(int i = 0; i < n; i++) {
      for(int w = sum; w >= 0; w--) {
        if(dp[w] == 1) continue;

        int prev = w - num[i];
        if(prev >= 0)
         dp[w] = dp[prev];
      }
    }

    return dp[sum];
  }
};