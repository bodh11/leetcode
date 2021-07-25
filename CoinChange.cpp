using namespace std;

#include <iostream>
#include <vector>

class CoinChange {
public:
  int countChange(const vector<int> &denominations, int total) {
    
    // we have to find total number of distinct ways in which we can create the target
    // sum
    int n = (int)(denominations.size());
    
    vector<int> dp(total + 1, 0);
    
    // base case: there is one way to create the total of 0
    // choose nothing
    dp[0] = 1;

    for(int i = 0; i < n; i++) { 
      for(int w = 0; w <= total; w++) {
        int prev = w - denominations[i];
        if(prev >= 0) {
          dp[w] = dp[w] + dp[prev];
        }
      }
    }

    return dp[total];
  }
};

int main(int argc, char *argv[]) {
  CoinChange *cc = new CoinChange();
  vector<int> denominations = {1, 2, 3};
  cout << cc->countChange(denominations, 5) << endl;

  delete cc;
}