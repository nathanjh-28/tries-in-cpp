//  <TODO Filename>
//      <TODO: Describe the data structure here >
//
//  Author: <TODO: place your name here>
//  CU ID: <TODO: place your CU ID here (4 letters - 4 digits)>
//  GitHub Username: <TODO: place your GitHub user name here>
//  Hours to complete lab: <TODO: place the number of hours needed to complete
//  lab, do not count time reading or watching videos>
//

#include "Tries.h"




// constructor, initialize class variables and pointers here if need.
Tries::Tries(set<char> alpha) {
  // Your code here
  root = init_node("");
  root->is_root = true;
  num_words = 0;
  num_nodes = 0;
  num_characters = 0;
  // alphabet will help check valid inputs
  alphabet = alpha;
}

// deconstructor,
Tries::~Tries() {}

trie_node* Tries::init_node(string characters) {
  trie_node* ret(new trie_node);
    // default values for trie nodes
  ret->is_root = false;
  ret->is_word_end = false;
  ret->word_count = 0;
  ret->characters = characters;
  // Your code here
  return ret;
}

string Tries::report() {
  string ret;
  // Your code here
  return ret;
}

void Tries::append_data(int data) {
  // Your code here
}

void Tries::append(trie_node* new_trie_node) {
  // Your code here
}

void Tries::insert_data(int offset, int data) {
  // Your code here
}

void Tries::insert(int offset, trie_node* new_trie_node) {
  // Your code here
}

void Tries::remove(int offset) {
  // Your code here
}

int Tries::size() {
  int ret;
  // Your code here
  return ret;
}

bool Tries::contains(int data) {
  bool ret;
  // Your code here
  return ret;
}

// // This function is implemented for you
// // It returns the top pointer
trie_node* Tries::get_root() { return root; }

// // This function is implemented for you
// // It sets a given pointer as the top pointer
void Tries::set_root(trie_node* new_root) { root = new_root; }