using namespace std;

#include <iostream>
#include <vector>

class PartitionSet {
public:
  int canPartition(const vector<int> &num) { 
    
    int n = (int)(num.size());
    int sum = 0;
    for(int i = 0; i < n; i++)
     sum += num[i];
    
    vector<int> dp(sum + 1, 0);

    // sum of 0 size is possible
    dp[0] = 1;

    for(int i = 0; i < n; i++) {
      for(int w = sum; w >= 0; w--) {
        if(dp[w] == 1) continue;
        int prev = w - num[i];
        if(prev >= 0) {
          dp[w] = dp[prev];
        }
      }
    }

    int C = sum / 2;
    int isPossibleAt = -1;
    for(int c = C; c >= 0; c--) {
      if(dp[c] == 1) {
        isPossibleAt = c;
        break;
      }
    }

    if(isPossibleAt != -1) {
      int sum1 = isPossibleAt;
      int sum2 = sum - sum1;
      int diff = abs(sum1 - sum2);
      return diff;
    }
    return -1; 
  }
};

int main(int argc, char *argv[]) {
  PartitionSet ps;
  vector<int> num = {1, 2, 3, 9};
  cout << ps.canPartition(num) << endl;
  num = vector<int>{1, 2, 7, 1, 5};
  cout << ps.canPartition(num) << endl;
  num = vector<int>{1, 3, 100, 4};
  cout << ps.canPartition(num) << endl;
}
