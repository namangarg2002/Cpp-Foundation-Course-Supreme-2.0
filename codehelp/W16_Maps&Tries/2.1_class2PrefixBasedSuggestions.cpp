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

void insertWord(TrieNode *root, string word, int index = 0)
{
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
  insertWord(child, word, index + 1);
}

void collectWords(TrieNode *node, string prefix)
{
  if (node->isTerminal)
  {
    cout << prefix << endl;
  }
  for (int i = 0; i < 26; i++)
  {
    if (node->children[i] != NULL)
    {
      collectWords(node->children[i], prefix + node->children[i]->value);
    }
  }
}

void PrefixBasedSuggestions(TrieNode *root, string prefix)
{

  TrieNode *node = root;

  for (int i = 0; i < prefix.length(); i++)
  {
    char ch = prefix[i];
    int childIndex = ch - 'a';
    if (node->children[childIndex] == NULL)
    {
      cout << "No words found with the prefix \"" << prefix << "\"." << endl;
      return;
    }
    node = node->children[childIndex];
  }
  // rest recursion will handle to collect words
  collectWords(node, prefix);
}

int main()
{

  TrieNode *root = new TrieNode('-');

  insertWord(root, "code");
  insertWord(root, "care");
  insertWord(root, "ccna");
  insertWord(root, "ccnop");
  insertWord(root, "raana");
  insertWord(root, "ro");

  cout << "Insertion Done" << endl;

  string prefix = "c";
  cout << "Words with prefix \"" << prefix << "\":" << endl;
  PrefixBasedSuggestions(root, prefix);

  return 0;
}