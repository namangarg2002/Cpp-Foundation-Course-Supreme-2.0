#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{

  // creation
  unordered_map<string, int> mapping;

  // insertion
  pair<string, int> p = make_pair("love", 25);
  pair<string, int> q("dipansh", 24);
  pair<string, int> r;
  q.first = "arun";
  q.second = 21;

  unordered_map<string, int> s = {
      {"ram", 20},
      {"mohan", 19}};

  mapping.insert(p);
  mapping.insert(q);
  mapping.insert(r);

  mapping["baabar"] = 51;

  // size
  cout << "Size of Mapp : " << mapping.size() << endl;

  // accessing
  cout << mapping.at("love") << endl;

  cout << mapping["love"] << endl;

  // searching
  cout << mapping.count("love") << endl;

  if (mapping.find("babbar") != mapping.end())
  {
    cout << "Found" << endl;
  }
  else
  {
    cout << "Not Found" << endl;
  }
  cout << "Size of Mapp : " << mapping.size() << endl;
  cout << mapping["kumar"] << endl;
  cout << "Size of Mapp : " << mapping.size() << endl;

  return 0;
}