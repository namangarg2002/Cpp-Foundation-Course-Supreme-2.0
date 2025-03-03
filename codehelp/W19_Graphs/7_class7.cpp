#include <iostream>
#include <unordered_map>
#include <set>
#include <list>
#include <vector>
#include <limits.h>
#include <stack>
using namespace std;
template <typename T>
class Graph
{
public:
  // unordered_map<T, list<pair<T, int>>> adjList;
  // void addEdge(T u, T v, int wt, bool direction)
  // {
  //   if (direction == 1)
  //   {
  //     adjList[u].push_back({v, wt});
  //   }
  //   else
  //   {
  //     adjList[u].push_back({v, wt});
  //     adjList[v].push_back({u, wt});
  //   }
  // }
  // void printAdjList()
  // {
  //   for (auto i : adjList)
  //   {
  //     cout << i.first << "-> " << "{";
  //     for (auto j : i.second)
  //     {
  //       cout << "{" << j.first << ", " << j.second << "}, ";
  //     }
  //     cout << "}" << endl;
  //   }
  // }
  unordered_map<T, list<T>> adjList;
  void addEdge(T u, T v, bool direction)
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
    for (auto i : adjList)
    {
      cout << i.first << "-> " << "{";
      for (auto j : i.second)
      {
        cout << "{" << j << "}, ";
      }
      cout << "}" << endl;
    }
  }
  void bellmanFord(int n, T src)
  {
    // initial State
    vector<int> dist(n, INT_MAX);
    dist[src - 'A'] = 0;
    // N-1 times ->  relaxation
    for (int i = 1; i < n; i++)
    {
      // traverse on entire edgeList
      for (auto a : adjList)
      {
        T u = a.first;
        for (auto b : a.second)
        {
          T v = b.first;
          int wt = b.second;
          if (dist[u - 'A'] != INT_MAX && dist[u - 'A'] + wt < dist[v - 'A'])
          {
            dist[v - 'A'] = dist[u - 'A'] + wt;
          }
        }
      }
    }
    // yaha tk shortest distance ready hai
    // check for negative cycle
    // ek baar relaxation or chlata hu
    bool anyUpdate = false;
    for (auto a : adjList)
    {
      for (auto b : a.second)
      {
        T u = a.first;
        T v = b.first;
        int wt = b.second;
        if (dist[u - 'A'] != INT_MAX && dist[u - 'A'] + wt < dist[v - 'A'])
        {
          anyUpdate = true;
          break;
        }
      }
    }
    if (anyUpdate == true)
    {
      cout << "Negative cycle Present" << endl;
    }
    else
    {
      cout << "No Negative Cycle in Graph" << endl;
      cout << "printing distance Array : ";
      for (auto i : dist)
      {
        cout << i << " ";
      }
      cout << endl;
    }
  }
  void floydWarshall(int n)
  {
    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    // diagonal par 0
    for (int i = 0; i < n; i++)
    {
      dist[i][i] = 0;
    }
    // kuch weights graph ke ander bhi given hai
    // update dist array Accordingly
    for (auto a : adjList)
    {
      for (auto b : a.second)
      {
        int u = a.first;
        int v = b.first;
        int wt = b.second;
        dist[u][v] = wt;
      }
    }
    // main logic - helper logic
    for (int helper = 0; helper < n; helper++)
    {
      for (int src = 0; src < n; src++)
      {
        for (int dest = 0; dest < n; dest++)
        {
          dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
        }
      }
    }
    // printing distance array
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cout << dist[i][j] << " ";
      }
      cout << endl;
    }
  }

  void dfs1(int node, stack<int> &ordering, unordered_map<int, bool> &visit)
  {
    visit[node] = true;
    for (auto child : adjList[node])
    {
      if (!visit[child])
      {
        dfs1(child, ordering, visit);
      }
    }
    ordering.push(node);
  }
  void dfs2(int node, unordered_map<int, bool> &visit2, unordered_map<T, list<T>> &adjListNew)
  {
    visit2[node] = true;
    cout << node << " ";
    for (auto child : adjListNew[node])
    {
      if (!visit2[child])
      {
        dfs2(child, visit2, adjListNew);
      }
    }
    // cout << endl;
  }
  int getStronglyConnectedComponenent(int n)
  {
    // step1: get the ordering
    stack<int> ordering;
    unordered_map<int, bool> visit;
    for (int i = 0; i < n; i++)
    {
      if (!visit[i])
      {
        dfs1(i, ordering, visit);
      }
    }
    // step2: reverse the edge
    unordered_map<T, list<T>> adjListNew;
    for (auto a : adjList)
    {
      for (auto b : a.second)
      {
        int u = a.first;
        int v = b;
        // v -> u kientry create akrni hai or usko adjListNew mai dalni hai
        adjListNew[v].push_back(u);
      }
    }
    // step3: traverse using orderring and count components
    int count = 0;
    unordered_map<int, bool> visit2;
    while (!ordering.empty())
    {
      int node = ordering.top();
      ordering.pop();
      if (!visit2[node])
      {
        cout << "SCC #" << count + 1 << ": ";
        dfs2(node, visit2, adjListNew);
        cout << endl;
        count++;
      }
    }
    return count;
  }
};
int main()
{
  // Graph<char> g;
  // g.addEdge('A', 'B', -1, 1);
  // g.addEdge('B', 'C', 2, 1);
  // g.addEdge('C', 'D', -3, 1);
  // g.addEdge('D', 'E', 5, 1);
  // g.addEdge('A', 'E', 4, 1);
  // g.addEdge('B', 'E', 3, 1);
  // g.addEdge('B', 'D', 2, 1);
  // g.addEdge('D', 'B', 1, 1);
  // g.printAdjList();
  // g.bellmanFord(5, 'A');

  // Graph<int> g;
  // g.addEdge(0, 1, 3, 1);
  // g.addEdge(1, 0, 2, 1);
  // g.addEdge(0, 3, 5, 1);
  // g.addEdge(1, 3, 4, 1);
  // g.addEdge(2, 1, 1, 1);
  // g.addEdge(3, 2, 2, 1);
  // g.printAdjList();
  // g.floydWarshall(4);

  Graph<int> g;
  g.addEdge(0, 1, 1);
  g.addEdge(1, 2, 1);
  g.addEdge(2, 3, 1);
  g.addEdge(3, 0, 1);
  g.addEdge(2, 4, 1);
  g.addEdge(4, 5, 1);
  g.addEdge(5, 6, 1);
  g.addEdge(6, 4, 1);
  g.addEdge(6, 7, 1);

  g.printAdjList();
  int ans = g.getStronglyConnectedComponenent(7);
  cout << "Number of Strongly Connected Components are: " << ans << endl;
  return 0;
}