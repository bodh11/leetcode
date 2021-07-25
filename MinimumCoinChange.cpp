using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class CoinChange {

public:
  int countChange(const vector<int> &denominations, int total) {
    
    // minimum number of coins needed to make a change of T
    int n = (int)(denominations.size());

    // minimum number of coins needed to make a sum
    vector<int> dp(total + 1, 0);

    for(int i = 0; i <= total; i++)
     dp[i] = (1<<25);
    // base case 
    dp[0] = 0;
    // here we have to minimize

    for(int i = 0; i < n; i++) {
      for(int w = 0; w <= total; w++) {
        int prev = w - denominations[i];
        
        // 2 choices here ....
        // either you are going to take the ith element
        // or you are not going to take the ith element

        // note: you are taking the element again
        // item = 2
        // w = 4, dp[2] = 1
        dp[w] = min(dp[w], dp[prev] + 1);
      }
    }


    return dp[total];
  }
};

int main(int argc, char *argv[]) {
  CoinChange *cc = new CoinChange();
  vector<int> denominations = {1, 2, 3};
  cout << cc->countChange(denominations, 5) << endl;
  cout << cc->countChange(denominations, 11) << endl;
  cout << cc->countChange(denominations, 7) << endl;
  denominations = vector<int>{3, 5};
  cout << cc->countChange(denominations, 7) << endl;

  delete cc;
}