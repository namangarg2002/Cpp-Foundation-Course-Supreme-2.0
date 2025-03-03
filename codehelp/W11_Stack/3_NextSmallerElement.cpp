#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextSmallerElement(int *arr, int size, vector<int> &ans)
{
  stack<int> st;
  st.push(-1);

  for (int i = size - 1; i >= 0; i--)
  {
    int curr = arr[i];
    // answer find karo current ke liye
    while (st.top() >= curr)
    {
      st.pop();
    }
    ans[i] = st.top();
    st.push(curr);
  }
  return ans;
}

int main()
{
  int arr[6] = {2, 1, 5, 6, 2, 3};
  int size = 6;

  vector<int> ans(size);

  nextSmallerElement(arr, size, ans);

  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;

  return 0;
}
