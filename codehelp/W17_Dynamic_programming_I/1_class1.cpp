#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int solveUsingTabulation(int n, int x, int y, int z)
{

  if (n == 0)
    return 0;
  if (n < 0)
    return INT_MIN;

  vector<int> dp(n + 1, -1);

  dp[0] = 0;

  for (int i = 1; i <= n; i++)
  {
    if (i >= x)
      dp[i] = max(dp[i], dp[i - x] + 1);
    if (i >= y)
      dp[i] = max(dp[i], dp[i - y] + 1);
    if (i >= z)
      dp[i] = max(dp[i], dp[i - z] + 1);
  }
  return dp[n] < 0 ? 0 : dp[n];
}

int solveUsingMemoization(int n, int x, int y, int z, vector<int> &dp)
{
  if (n == 0)
    return 0;
  if (n < 0)
    return INT_MIN;

  if (dp[n] != -1)
  {
    return dp[n];
  }

  int opt1 = 1 + solveUsingMemoization(n - x, x, y, z, dp);
  int opt2 = 1 + solveUsingMemoization(n - y, x, y, z, dp);
  int opt3 = 1 + solveUsingMemoization(n - z, x, y, z, dp);

  dp[n] = max(opt1, max(opt2, opt3));

  return dp[n];
}

int solveusingRec(int n, int x, int y, int z)
{
  if (n == 0)
    return 0;
  if (n < 0)
    return INT_MIN;

  int opt1 = 1 + solveusingRec(n - x, x, y, z);
  int opt2 = 1 + solveusingRec(n - y, x, y, z);
  int opt3 = 1 + solveusingRec(n - z, x, y, z);

  int ans = max(opt1, max(opt2, opt3));
  return ans;
}

int main()
{
  int n, x, y, z;

  cout << "Enter the total length (n): ";
  cin >> n;
  cout << "Enter the segment lengths (x, y, z): ";
  cin >> x >> y >> z;

  // recurssion
  // int result = solveusingRec(n, x, y, z);

  // Memoization
  // vector<int> dp(n + 1, -1);
  // int result = solveUsingMemoization(n, x, y, z, dp);

  int result = solveUsingTabulation(n, x, y, z);
  cout << result;

  return 0;
}