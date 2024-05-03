//
//  _______________________________________________
//
//  STANDARD AND COMPRESSED TRIES IN C++
//  By Nathan J Harris
//  Spring 2024 CSPB 2270 - CU Boulder
//  cu id: naha3153
//  github: nathanjh-28
//  https://github.com/nathanjh-28/tries-in-cpp
//
//  _______________________________________________
//



#ifndef TRIES_H__
#define TRIES_H__

#include <memory>
#include <string>
#include <unordered_map>
#include <set>
#include <vector>

using namespace std;

struct trie_node {
  bool is_root;
  bool is_word_end;
  int word_count;
  // this is a map where the key is a string and values are pointers to trienodes
  unordered_map<string,trie_node*> map;
  // optional for standard tries but we will store the characters in the node as well.
  string characters;
};

// Invariants
//	Each node in the trie has at most 26 children corresponding to the letters of the alphabet.
//	Every path from root node to word ending node represents a unique word in the trie, ensuring unique representation and retrievability.
//	The height of the trie is equal to the longest word inserted.
//	The root node has no parent and no associated character.
//	Each node maintains a numerical count indicating how many words end at that node.
//	Words that share prefixes share nodes and separate at the end of their common prefix.
//	The trie maintains a hierarchical trie structure with parent-child relationships and no cycles.
class Tries {
public:
  // Constructor for Tries 
  Tries(set<char> alphabet);

  // Deconstructor. 
  ~Tries();

  // Creates a new node structure from heap memory. 
  // The function returns a pointer to that new node.
  trie_node* init_node(string characters);

  // adds a word in to the Trie
  void insert(string word);

  // removes a word
  void remove(string word);

  // Returns the number of times a word has been inserted
  // Can be modified as a search, 0 would return false and 1 or more would return true.
  int word_count(string word);

  // Returns a list of words that match that prefix
  // Extend this method for the longest word matching the prefix, the longest word in the list.
  // Extend this method with the number of items in the list for number of words with that prefix.
  vector<string> autocomplete(string prefix);

  // Return the number of characters stored in the trie
  int characters();

  // Return the number of nodes in the trie (could be interesting for the radix trie where nodes and character counts would not be the same).
  int nodes();

  // Removes all words and nodes from the trie
  void clear();

  // returns the number of words inserted
  int size();

  // create a string with all the words in the Trie
  string report();

  // print a single node's information
  string print_node(trie_node* node);

  // Returns true if this Trie contains a node with the specified value,
  // false otherwise.
  bool contains(string word);

  // This function is getting the private member root
  trie_node* get_root();

  // This is is a helper function for manually building tries in tests
  void set_root(trie_node* root);

  // if a node can be compressed, it's characters and maps are merged
  trie_node* compress_node(trie_node* parent);

  // if a node can be decompressed, it's characters and maps are separated
  trie_node* decompress_node(trie_node* node);

  //recursively call compress_node on all nodes that are eligible
  void compress_trie(trie_node* subtrie);

  //recursively call decompress_node on all nodes that are eligible
  void decompress_trie(trie_node* subtrie);

  void update_maps_keys(trie_node* subtrie);

  // additional public variables
  int num_words;
  int num_nodes;
  int num_characters;
  set<char> alphabet;

private:
  trie_node* root;

};

#endif // TRIES_H__