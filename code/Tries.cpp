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
  trie_node* cursor = root;
  string c;
  for(int i = 0; i < word.size(); i++){
    c = word[i];
    if(cursor->map.find(c) == cursor->map.end()){
      return 0;
    }
    cursor = cursor->map.at(c);
  }
  return cursor->word_count;
}

void autocomplete_recurse(trie_node* subtree, string prefix,vector<string>& word_list){
  if(subtree->is_word_end){
    word_list.push_back(prefix);
  }
  for(auto i = subtree->map.begin(); i != subtree->map.end(); ++i){
    autocomplete_recurse(subtree->map.at(i->first),prefix + i->first, word_list);
  }
}

vector<string> Tries::autocomplete(string prefix){
  vector<string> word_list;
  trie_node* cursor = root;
  string c;
  for(int i = 0; i < prefix.size(); i++){
    c = prefix[i];
    if(cursor->map.find(c) == cursor->map.end()){
      return word_list;
    }
    cursor = cursor->map.at(c);
  }
  autocomplete_recurse(cursor,prefix,word_list);
  return word_list;
}

int Tries::characters(){
  return num_characters;
}

int Tries::nodes(){
  return num_nodes;
}

void Tries::clear(){
  return;
}


int Tries::size() {
  // To do
  return num_words;
}

string Tries::report() {
  // To do
  vector<string> list = autocomplete("");

  if(list.size() == 1){
    return "'" + list[0] + "'";
  }

  string ret = "'" + list[0] + ",";

  for(int i = 1; i < list.size()-1; i++){
    ret = ret + " " + list[i] + ",";
  }
  ret = ret + " " + list[list.size()-1];
  
  return ret + "'";
}
bool Tries::contains(string word) {
  bool ret;
  // To do
  return ret;
}

trie_node* Tries::get_root() { return root; }


void Tries::set_root(trie_node* new_root) { root = new_root; }