using namespace std;

#include <iostream>
#include <vector>

class RodCutting {

public:
  int solveRodCutting(const vector<int> &lengths, vector<int> &prices, int n) {
    int sz = (int)(lengths.size());

    vector<int> dp(n+1, 0); // stores the maximum profit
    
    // calculate the max profit if you cut the rod into smaller known portions
    // you can have multiple pieces of same size

    for(int i = 0; i < sz; i++) {
      for(int w = 0; w <= n; w++) {
        int prev = w - lengths[i];
        if(prev >= 0)
         dp[w] = max(dp[w], dp[prev] + prices[i]);
      }
    }

    // so we are interested only in the dp[n] solution
    return dp[n];
  }
};

int main(int argc, char *argv[]) {
  RodCutting *rc = new RodCutting();
  vector<int> lengths = {1, 2, 3, 4, 5};
  vector<int> prices = {2, 6, 7, 10, 13};
  int maxProfit = rc->solveRodCutting(lengths, prices, 5);
  cout << maxProfit << endl;

  delete rc;
}
