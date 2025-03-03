#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int SumOfKsubArray(vector<int> &nums, int k)
{
  deque<int> dq1, dq2;
  int ans = 0;

  // Step1: first window process
  for (int i = 0; i < k; i++)
  {
    int element = nums[i];
    // jitne bhi queue ke nader chote no. h unhe remove kr do
    while (!dq1.empty() && element > nums[dq1.back()])
    {
      dq1.pop_back();
    }
    // bada element remove kr do
    while (!dq2.empty() && element <= nums[dq2.back()])
    {
      dq2.pop_back();
    }
    // now insert karo
    dq1.push_back(i);
    dq2.push_back(i);
  }

  ans += nums[dq1.front()] + nums[dq2.front()];
  // Step2: remaining window process
  // removal 1:out of range
  //         2:Choote element ko remove kr do
  // addition
  for (int i = k; i < nums.size(); i++)
  {

    // removal
    // out of range
    if (!dq1.empty() && i - dq1.front() >= k)
    {
      dq1.pop_front();
    }

    if (!dq2.empty() && i - dq2.front() >= k)
    {
      dq2.pop_front();
    }

    // chote eleemnt pop krdo
    int element = nums[i];
    while (!dq1.empty() && element >= nums[dq1.back()])
    {
      dq1.pop_back();
    }

    while (!dq2.empty() && element <= nums[dq2.back()])
    {
      dq2.pop_back();
    }

    // addition
    dq1.push_back(i);
    dq2.push_back(i);

    ans += nums[dq1.front()] + nums[dq2.front()];
  }

  return ans;
}

int main()
{
  vector<int> v{2, 5, -1, 7, -3, -1, -2};
  int k = 4;
  cout << SumOfKsubArray(v, k) << endl;
  return 0;
}