#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

// Graph Creation(unweighted) through Adjacency List
// class Graph
// {
// public:
//   unordered_map<int, list<int>> adjList;

//   void addEdge(int u, int v, bool direction)
//   {
//     // direction -> 0 -> undirected
//     // direction -> 1 -> directed

//     if (direction == 1)
//     {
//       // u -> v ki taraph ek edge hai
//       // u -> v
//       adjList[u].push_back(v);
//     }
//     else
//     {
//       // direction = 0
//       // u <--> v
//       adjList[u].push_back(v);
//       adjList[v].push_back(u);
//     }
//     cout << endl;
//     cout << "Printing adjList" << endl;
//     printAdjList();
//     cout << endl;
//   }
//   void printAdjList()
//   {
//     for (auto i : adjList)
//     {
//       cout << i.first << "-> {";
//       for (auto neighbour : i.second)
//       {
//         cout << neighbour << ", ";
//       }
//       cout << "}" << endl;
//     }
//   }
// };
template <typename T>
class Graph
{
public:
  unordered_map<T, list<pair<T, int>>> adjList;
  void addEdge(T u, T v, int weight, bool direction)
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
    // cout << endl;
    // cout << "Printing adjList" << endl;
    // printAdjList();
    // cout << endl;
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
  // for joint graph
  // void bfsTraversal(T src)
  // {
  //   // adjList already data memeber mai hai
  //   // visited
  //   unordered_map<T, bool> visited;
  //   // queue
  //   queue<T> q;

  //   // initial State
  //   q.push(src);
  //   visited[src] = true;

  //   while (!q.empty())
  //   {
  //     T frontNode = q.front();
  //     q.pop();
  //     cout << frontNode << " ";

  //     // go to neighbout
  //     for (auto nbr : adjList[frontNode])
  //     {
  //       T nbrData = nbr.first;
  //       if (!visited[nbrData])
  //       {
  //         q.push(nbrData);
  //         visited[nbrData] = true;
  //       }
  //     }
  //   }
  //   cout << endl;
  // }

  // For Disjoint Graph
  void bfsTraversal(T src, unordered_map<T, bool> &visited)
  {
    // queue
    queue<T> q;

    // initial State
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
      T frontNode = q.front();
      q.pop();
      cout << frontNode << " ";

      // go to neighbout
      for (auto nbr : adjList[frontNode])
      {
        T nbrData = nbr.first;
        if (!visited[nbrData])
        {
          q.push(nbrData);
          visited[nbrData] = true;
        }
      }
    }
    cout << endl;
  }

  void dfsTraversal(T src, unordered_map<T, bool> &visited)
  {
    visited[src] = true;
    cout << src << " ";

    for (auto nbr : adjList[src])
    {
      T nbrData = nbr.first;
      if (!visited[nbrData])
      {
        dfsTraversal(nbrData, visited);
      }
    }
  }
};

int main()
{
  // unweighted Graph Creation
  // Graph g;
  // g.addEdge(0, 1, 0);
  // g.addEdge(1, 2, 0);
  // g.addEdge(1, 3, 0);
  // g.addEdge(2, 3, 0);
  // g.addEdge(3, 4, 0);
  // g.addEdge(4, 5, 0);
  // g.addEdge(5, 3, 0);

  // weighted Graph
  Graph<char> g;
  // g.addEdge('a', 'b', 5, 0);
  // g.addEdge('a', 'c', 10, 0);
  // g.addEdge('b', 'c', 50, 0);
  // g.addEdge('c', 'd', 50, 0);
  // g.addEdge('c', 'e', 50, 0);
  // g.addEdge('e', 'f', 50, 0);

  // g.addEdge('a', 'b', 5, 0);
  // g.addEdge('a', 'c', 10, 0);

  // g.addEdge('d', 'e', 50, 0);

  // g.addEdge('f', 'f', 50, 0);

  // unordered_map<char, bool> visited;
  // for (char node = 'a'; node <= 'f'; node++)
  // {
  //   if (!visited[node])
  //   {
  //     g.bfsTraversal(node, visited);
  //   }
  // }

  // g.addEdge('a', 'b', 5, 0);
  // g.addEdge('a', 'c', 10, 0);
  // g.addEdge('c', 'd', 50, 0);
  // g.addEdge('c', 'e', 50, 0);
  // g.addEdge('d', 'e', 50, 0);
  // g.addEdge('e', 'f', 50, 0);

  // unordered_map<char, bool> vis;
  // g.dfsTraversal('a', vis);

  g.addEdge('a', 'b', 5, 0);
  g.addEdge('a', 'c', 10, 0);

  g.addEdge('d', 'e', 50, 0);

  g.addEdge('f', 'f', 50, 0);

  unordered_map<char, bool> vis;
  for (char node = 'a'; node <= 'f'; node++)
  {
    if (!vis[node])
    {
      g.dfsTraversal(node, vis);
    }
  }

  return 0;
}