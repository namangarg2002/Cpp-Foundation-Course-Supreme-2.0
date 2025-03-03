#include <iostream>
#include <list>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

class Graph
{
public:
  unordered_map<int, list<int>> adjList;

  void addEdge(int u, int v, bool direction)
  {
    if (direction == 1)
    {
      adjList[u].push_back(v);
    }
    else
    {
      adjList[u].push_back(v);
      adjList[v].push_back(u);
    }
  }
  void printAdjList()
  {
    for (auto &i : adjList)
    {
      cout << i.first << " -> {";
      for (auto j : i.second)
      {
        cout << j << ", ";
      }
      cout << "}" << endl;
    }
    cout << endl;
  }
  void topoSortDFS(int src, map<int, bool> &visit, stack<int> &st)
  {
    visit[src] = true;
    for (auto child : adjList[src])
    {
      if (!visit[child])
      {
        topoSortDFS(child, visit, st);
      }
    }
    st.push(src);
  }

  void topoSortBFS(int n)
  {
    queue<int> q;
    map<int, int> inDegree;
    // initialise inDegree
    for (auto i : adjList)
    {
      for (auto child : i.second)
      {
        inDegree[child]++;
      }
    }
    // push all zero indegree wali node into queue
    for (int node = 0; node < n; node++)
    {
      if (inDegree[node] == 0)
      {
        q.push(node);
      }
    }

    // BFS CONCEPT
    while (!q.empty())
    {
      int frontNode = q.front();
      q.pop();
      cout << frontNode << " ";
      for (auto child : adjList[frontNode])
      {
        inDegree[child]--;
        // check for 0
        if (inDegree[child] == 0)
        {
          q.push(child);
        }
      }
    }
  }

  void shortestPathBFS(int src, int dest)
  {
    queue<int> q;
    map<int, bool> visit;
    map<int, int> parent;

    // initial State
    q.push(src);
    visit[src] = true;
    parent[src] = -1;

    while (!q.empty())
    {
      int frontNode = q.front();
      q.pop();
      for (auto child : adjList[frontNode])
      {
        if (!visit[child])
        {
          q.push(child);
          visit[child] = true;
          parent[child] = frontNode;
        }
      }
    }
    // parent Array is ready
    vector<int> ans;
    while (dest != -1)
    {
      ans.push_back(dest);
      dest = parent[dest];
    }

    reverse(ans.begin(), ans.end());
    for (auto i : ans)
    {
      cout << i << " ";
    }
    cout << endl;
  }
};
int main()
{
  Graph g;
  // g.addEdge(0, 1, 1);
  // g.addEdge(1, 2, 1);
  // g.addEdge(2, 3, 1);
  // g.addEdge(2, 4, 1);
  // g.addEdge(3, 5, 1);
  // g.addEdge(4, 5, 1);
  // g.addEdge(5, 6, 1);
  // g.addEdge(5, 7, 1);

  // g.printAdjList();

  // int n = 8;
  // map<int, bool> visit;
  // stack<int> st;
  // for (int i = 0; i < n; i++)
  // {
  //   if (!visit[i])
  //   {
  //     g.topoSortDFS(i, visit, st);
  //   }
  // }

  // while (!st.empty())
  // {
  //   int top = st.top();
  //   st.pop();
  //   cout << top << " ";
  // }
  // cout << endl;

  // g.topoSortBFS(n);

  g.addEdge(0, 4, 0);
  g.addEdge(0, 3, 0);
  g.addEdge(0, 6, 0);
  g.addEdge(4, 1, 0);
  g.addEdge(3, 5, 0);
  g.addEdge(6, 2, 0);
  g.addEdge(1, 5, 0);
  g.addEdge(2, 5, 0);

  g.shortestPathBFS(0, 5);

  return 0;
}