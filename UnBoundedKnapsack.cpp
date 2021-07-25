using namespace std;

#include <iostream>
#include <vector>

class Knapsack {

public:
  int solveKnapsack(const vector<int> &profits, const vector<int> &weights, int capacity) {
    int n = (int)(profits.size());
    
    vector<int> dp(capacity + 1, 0);
    for(int i = 0; i < n; i++) {
      for(int w = 0; w <= capacity; w++) {
        int prev = w - weights[i];
        if(prev >= 0)
         dp[w] = dp[prev] + profits[i];
      }
    }
    int ans = 0;
    for(int w = 0; w <= capacity; w++) {
      ans = max(ans, dp[w]);
    }
    return ans;
  }
};

int main(int argc, char *argv[]) {
  Knapsack *ks = new Knapsack();
  vector<int> profits = {15, 50, 60, 90};
  vector<int> weights = {1, 3, 4, 5};
  cout << ks->solveKnapsack(profits, weights, 8) << endl;
  cout << ks->solveKnapsack(profits, weights, 6) << endl;

  delete ks;
}