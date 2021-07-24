using namespace std;

#include <iostream>
#include <vector>

class SubsetSum {
public:
  int countSubsets(const vector<int> &num, int sum) {
    int n = (int)(num.size());
    
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;

    for(int i = 0; i < n; i++) {
      for(int w = sum; w>= 0; w--) {
        int prev = w - num[i];
        if(prev >= 0) {
          dp[w] += dp[prev];
        } 
      }
    }

    return dp[sum];
  }
};