using namespace std;

#include <iostream>
#include <vector>

class PartitionSet {
public:
  bool canPartition(const vector<int> &num) {
    int n = (int)num.size();
    int sum = 0;
    for(int i = 0; i < n; i++)
     sum += num[i];
    if(sum % 2 != 0) return 0; 
    int C = sum / 2;
    
    vector<int> dp(C+1, 0);

    // init with first element 
    for(int w = C; w >= 0; w--) {
      if(w >= num[0]) dp[w] = 1;
    }

    for(int i = 1; i < n; i++) {
      for(int w = C; w >= 0; w--) {
        if(dp[w] == 1) continue;
        int prev = w - num[i];
        if(prev >= 0) 
         dp[w] = dp[prev];
      }
    }
    return dp[C];
  }
};