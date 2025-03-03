#include <iostream>
using namespace std;

class TrieNode
{
public:
  char value;
  TrieNode *children[26];
  bool isTerminal;

  TrieNode(char val)
  {
    this->value = val;
    for (int i = 0; i < 26; i++)
    {
      children[i] = NULL;
    }
    this->isTerminal = false;
  }
};
// insertion
void insertWord(TrieNode *root, string word, int index = 0)
{
  // cout << "received word: " << word << " for insertion " << endl;
  // base case
  if (index == word.length())
  {
    root->isTerminal = true;
    return;
  }
  char ch = word[index];
  int childindex = ch - 'a';
  TrieNode *child;
  if (root->children[childindex] != NULL)
  {
    // child present
    child = root->children[childindex];
  }
  else
  {
    // absent
    child = new TrieNode(ch);
    root->children[childindex] = child;
  }

  // recurssion will handle further
  insertWord(child, word, index + 1); // here word.substr(1) remove the first character each time like string s = 'Geeks' i., s.substr(1) = 'eeks'
}

// searching
bool searchWord(TrieNode *root, string word, int index = 0)
{
  // base case
  if (index == word.length())
  {
    return root->isTerminal;
  }
  char ch = word[index];
  int childindex = ch - 'a';
  TrieNode *child;

  if (root->children[childindex] != NULL)
  {
    // present
    child = root->children[childindex];
  }
  else
  {
    // not found
    return false;
  }

  bool recussionKaAnswer = searchWord(child, word, index + 1);

  return recussionKaAnswer;
}

// deletion
void deleteWord(TrieNode *root, string word, int index = 0)
{
  if (index == word.length())
  {
    root->isTerminal = false;
    return;
  }
  // 1 case solve
  char ch = word[index];
  int childIndex = ch - 'a';
  TrieNode *child;
  if (root->children[childIndex] != NULL)
  {
    // present
    child = root->children[childIndex];
  }
  else
  {
    return;
  }
  // rest recusssion will hande it
  deleteWord(child, word, index + 1);
}

int main()
{
  TrieNode *root = new TrieNode('-');

  insertWord(root, "cater");
  insertWord(root, "care");
  insertWord(root, "com");
  insertWord(root, "lover");
  insertWord(root, "load");
  insertWord(root, "bat");
  insertWord(root, "car");
  insertWord(root, "cat");
  insertWord(root, "lov");

  cout << "Insertion Done" << endl;

  if (searchWord(root, "lov"))
  {
    cout << "Found" << endl;
  }
  else
  {
    cout << "Not Found " << endl;
  }

  deleteWord(root, "lov");

  if (searchWord(root, "lov"))
  {
    cout << "Found" << endl;
  }
  else
  {
    cout << "Not Found " << endl;
  }

  return 0;
}
