#include <iostream>
#include <vector>
using namespace std;

int solveUsingRecursion(int capacity, int weight[], int profit[], int index, int n)
{
  // base case
  if (index == n)
  {
    return 0;
  }

  // include and exclude
  int include = 0;
  if (weight[index] <= capacity)
  {
    include = profit[index] + solveUsingRecursion(capacity - weight[index], weight, profit, index + 1, n);
  }

  int exclude = 0;
  exclude = 0 + solveUsingRecursion(capacity, weight, profit, index + 1, n);

  int ans = max(include, exclude);

  return ans;
}
// Memoization Approach
int solveUsingMemoization(int capacity, int weight[], int profit[], int index, int n, vector<vector<int>> &dp)
{
  // base case
  if (index == n)
  {
    return 0;
  }

  if (dp[capacity][index] != -1)
  {
    return dp[capacity][index];
  }

  int include = 0;
  if (weight[index] <= capacity)
  {
    include = profit[index] + solveUsingMemoization(capacity - weight[index], weight, profit, index + 1, n, dp);
  }
  int exclude = 0;
  exclude = 0 + solveUsingMemoization(capacity, weight, profit, index + 1, n, dp);

  dp[capacity][index] = max(include, exclude);

  return dp[capacity][index];
}

// Tabulation approach
int solveUsingTabulation(int capacity, int weight[], int profit[], int n)
{
  // Step 1 :
  vector<vector<int>> dp(capacity + 1, vector<int>(n + 1, -1));

  // Step 2: base case analyse
  for (int row = 0; row < capacity; row++)
  {
    dp[row][n] = 0;
  }

  for (int i = 0; i <= capacity; i++)
  {
    for (int j = n - 1; j >= 0; j--)
    {
      int include = 0;
      // replace capacity with i and index with k
      if (weight[j] <= i)
      {
        include = profit[j] + dp[i - weight[j]][j + 1];
      }
      int exclude = 0 + dp[i][j + 1];

      dp[i][j] = max(include, exclude);
    }
  }
  return dp[capacity][0];
}

// Space Optimization Approach
int solveUsingSpaceOptimization(int capacity, int weight[], int profit[], int n)
{
  vector<int> dp(capacity + 1, 0);

  for (int i = 0; i < n; i++)
  {
    for (int j = capacity; j >= weight[i]; j--)
    {
      int include = profit[i] + dp[j - weight[i]];
      int exclude = dp[j];

      dp[j] = max(include, exclude);
    }
  }
  return dp[capacity];
}
int main()
{
  int capacity = 50;
  int weight[] = {10, 20, 30};
  int profit[] = {60, 100, 120};
  int n = 3;

  // // Recursive Approach
  // int ans = solveUsingRecursion(capacity, weight, profit, 0, n);

  // // Memoization approach
  // vector<vector<int>> dp(capacity + 1, vector<int>(n + 1, -1));
  // int ans = solveUsingMemoization(capacity, weight, profit, 0, n, dp);

  // // tabulation Approach
  // int ans = solveUsingTabulation(capacity, weight, profit, n);

  // Space Optimization Approach
  int ans = solveUsingSpaceOptimization(capacity, weight, profit, n);

  cout << "Maximum profit: " << ans << endl;
  return 0;
}