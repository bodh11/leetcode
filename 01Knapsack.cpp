#include <iostream>
#include <vector>

using namespace std;

class Knapsack {
public:
  int solveKnapsack(const vector<int> &profits, const vector<int> &weights, int capacity) {
    int n = (int)profits.size();
    // 1-D version
    vector<int> dp(capacity+1, 0);
    // init the dp array with the 
    for(int w = 0; w <= capacity; w++) {
      if(w >= weights[0]) dp[w] = profits[0];
    }

    for(int i = 1; i < n; i++) {
      for(int w = capacity; w > 0; w--) {
         if(w - weights[i] >= 0) {
           dp[w] = max(dp[w], dp[w - weights[i]] + profits[i]);
         }
         // else dp[w] = dp[w] // don't take the ith element
      }
    }
    int ans = 0;
    for(int i = 0; i <= capacity; i++)
      ans = max(ans, dp[i]);
    return ans;
  }
};

int main(int argc, char *argv[]) {
  Knapsack ks;
  vector<int> profits = {1, 6, 10, 16};
  vector<int> weights = {1, 2, 3, 5};
  int maxProfit = ks.solveKnapsack(profits, weights, 7);
  cout << "Total knapsack profit ---> " << maxProfit << endl;
  maxProfit = ks.solveKnapsack(profits, weights, 6);
  cout << "Total knapsack profit ---> " << maxProfit << endl;
}