#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
using namespace std;

class Graph
{
public:
  unordered_map<int, list<int>> adjList;

  void addEdge(int u, int v, bool direction)
  {
    // direction -> 0 -> undirected
    // direction -> 1 -> directed

    if (direction == 1)
    {
      // u -> v
      adjList[u].push_back(v);
    }
    else
    {
      // u <--> v
      adjList[u].push_back(v);
      adjList[v].push_back(u);
    }
  }

  void printAdjList()
  {
    for (auto i : adjList)
    {
      cout << i.first << "-> {";
      for (auto neighbour : i.second)
      {
        cout << neighbour << ", ";
      }
      cout << "}" << endl;
    }
  }

  void bfsTraversal(int src, unordered_map<int, bool> &visited)
  {
    // queue
    queue<int> q;

    // initial State
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
      int frontNode = q.front();
      q.pop();
      cout << frontNode << " ";

      // go to neighbour
      for (auto nbr : adjList[frontNode])
      {
        if (!visited[nbr])
        {
          q.push(nbr);
          visited[nbr] = true;
        }
      }
    }
    cout << endl;
  }

  void dfsTraversal(int src, unordered_map<int, bool> &visited)
  {
    visited[src] = true;
    cout << src << " ";

    for (auto nbr : adjList[src])
    {
      if (!visited[nbr])
      {
        dfsTraversal(nbr, visited);
      }
    }
  }

  bool checkCycleUndirectedBFS(int src)
  {
    queue<int> q;
    unordered_map<int, bool> visit;
    unordered_map<int, int> parent;

    // initial
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
        else
        {
          // visit[child] == true
          if (child != parent[frontNode])
          {
            // cycle present
            return true;
          }
        }
      }
    }
    return false;
  }
};

int main()
{
  Graph g;
  g.addEdge(0, 1, 0);
  g.addEdge(1, 2, 0);
  g.addEdge(1, 3, 0);
  g.addEdge(2, 4, 0);
  g.addEdge(3, 4, 0);
  g.addEdge(2, 5, 0);

  int src = 0;
  bool isCyclic = g.checkCycleUndirectedBFS(src);
  if (isCyclic)
  {
    cout << "Cycle Present" << endl;
  }
  else
  {
    cout << "Cycle Absent" << endl;
  }

  return 0;
}