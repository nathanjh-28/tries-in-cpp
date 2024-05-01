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

  // TODO check that the characters are valid

  return ret;
}


void Tries::insert(string word) {
  // To do
  auto cursor = root;
  string c = "";
  for(int i = 0; i < word.size(); i++){
    c = word[i];
    if(cursor->map.find(c) == cursor->map.end()){
      trie_node* new_node = init_node(c);
      cursor->map.insert(make_pair(c,new_node));
      num_characters++;
      num_nodes++;
    }
    cursor = cursor->map.at(c);
  }
  cursor->is_word_end = true;
  cursor->word_count++;
  num_words++;
  return;
}

void Tries::remove(string word) {
  // To do
}

int Tries::word_count(string word){
  return 0;
}

vector<string> Tries::autocomplete(string prefix){
  vector<string> list;
  return list;
}

int Tries::characters(){
  return 0;
}

int Tries::nodes(){
  return 0;
}

void Tries::clear(){
  return;
}


int Tries::size() {
  int ret;
  // To do
  return ret;
}

string Tries::report() {
  string ret;
  
  // To do
  return ret;
}
bool Tries::contains(string word) {
  bool ret;
  // To do
  return ret;
}

trie_node* Tries::get_root() { return root; }


void Tries::set_root(trie_node* new_root) { root = new_root; }