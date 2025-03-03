#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <vector>
#include <limits.h>
#include <set>
using namespace std;

// directed and weighted Graph
class Graph
{
public:
  unordered_map<int, list<pair<int, int>>> adjList;
  void addEdge(int u, int v, int weight, bool direction)
  {
    if (direction == 1)
    {
      adjList[u].push_back({v, weight});
    }
    else
    {
      adjList[u].push_back({v, weight});
      adjList[v].push_back({u, weight});
    }
  }
  void printAdjList()
  {
    for (auto i : adjList)
    {
      cout << i.first << "->{";
      for (auto neighbour : i.second)
      {
        cout << "{" << neighbour.first << ", " << neighbour.second << "}, ";
      }
      cout << "}" << endl;
    }
  }
  void topoOrderDFS(int src, stack<int> &topoOrderStack, unordered_map<int, bool> &visited)
  {
    visited[src] = true;
    for (auto childPair : adjList[src])
    {
      int childNode = childPair.first;
      // int childDist = childPair.second;
      if (!visited[childNode])
      {
        topoOrderDFS(childNode, topoOrderStack, visited);
      }
    }
    topoOrderStack.push(src);
  }
  void shortedtPathDFS(int n, stack<int> &topoOrderStack)
  {
    vector<int> dist(n, INT_MAX);

    // initiallly,  maintain src
    int src = topoOrderStack.top();
    topoOrderStack.pop();
    dist[src] = 0;
    // update neighbour distance for this src node
    for (auto childPair : adjList[src])
    {
      int childNode = childPair.first;
      int childDist = childPair.second;
      if (dist[src] + childDist < dist[childNode])
      {
        dist[childNode] = dist[src] + childDist;
      }
    }
    // apply the same above concept for all the remining node
    // in the topoOrdering
    while (!topoOrderStack.empty())
    {
      int src = topoOrderStack.top();
      topoOrderStack.pop();
      for (auto childPair : adjList[src])
      {
        int childNode = childPair.first;
        int childDist = childPair.second;
        if (dist[src] + childDist < dist[childNode])
        {
          dist[childNode] = dist[src] + childDist;
        }
      }
    }
    // ab mera distanswer array taiyaar hai
    cout << "Printing the Distance array" << endl;
    for (auto i : dist)
    {
      cout << i << " ";
    }
    cout << endl;
  }

  void dijkstraShortestDistance(int n, int src, int dest)
  {
    vector<int> dist(n + 1, INT_MAX);
    set<pair<int, int>> st;

    // initial State -{0, src};
    st.insert({0, src});
    dist[src] = 0;

    // distance updation
    while (!st.empty())
    {
      auto topElement = st.begin();
      pair<int, int> topPair = *topElement;
      int topNode = topPair.second;
      int topDist = topPair.first;
      // remove the topNode
      st.erase(st.begin());

      // update distance of childs
      for (pair<int, int> childPair : adjList[topNode])
      {
        int childNode = childPair.first;
        int childDist = childPair.second;
        if (topDist + childDist < dist[childNode])
        {
          // found a new shorter Distance
          // now update
          // -> set ki entry
          auto previousEntry = st.find({dist[childNode], childNode});
          if (previousEntry != st.end())
          {
            // entry present in set
            st.erase(previousEntry);
          }
          // -> dist ka array
          dist[childNode] = topDist + childDist;
          st.insert({dist[childNode], childNode});
        }
      }
    }
    cout << "Shortest Distance From " << src << " Node to " << dest << " Node: " << dist[dest] << endl;
  }
};

int main()
{
  Graph g;
  // g.addEdge(0, 1, 5, 1);
  // g.addEdge(0, 2, 3, 1);
  // g.addEdge(1, 3, 3, 1);
  // g.addEdge(2, 1, 2, 1);
  // g.addEdge(2, 3, 5, 1);
  // g.addEdge(2, 4, 6, 1);
  // g.addEdge(4, 3, 1, 1);

  // // g.printAdjList();

  // int src = 0;
  // stack<int> topoOrderStack;
  // unordered_map<int, bool> visited;
  // g.topoOrderDFS(src, topoOrderStack, visited);

  // int n = 5;
  // g.shortedtPathDFS(n, topoOrderStack);

  g.addEdge(1, 2, 7, 0);
  g.addEdge(1, 3, 9, 0);
  g.addEdge(1, 6, 14, 0);

  g.addEdge(6, 5, 9, 0);
  g.addEdge(6, 3, 2, 0);

  g.addEdge(5, 4, 6, 0);

  g.addEdge(4, 3, 11, 0);
  g.addEdge(4, 2, 15, 0);

  g.addEdge(2, 3, 10, 0);

  // g.printAdjList();
  int n = 6;
  int src = 6;
  int dest = 4;
  g.dijkstraShortestDistance(n, src, dest);

  return 0;
}