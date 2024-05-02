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
  vector <trie_node*> node_list;
  trie_node* cursor = root;
  string c;
  for(int i = 0; i < word.size(); i++){
    c = word[i];
    node_list.push_back(cursor);
    if(cursor->map.find(c) == cursor->map.end()){
      // doesn't exist in trie;
      return;
    }
    cursor = cursor->map.at(c);
  }
  if(cursor->word_count > 1){
    cursor->word_count--;
    num_words--;
    return;
  }
  node_list[node_list.size()-1]->map.erase(cursor->characters);
  delete cursor;
  num_nodes--;
  num_characters = num_characters - c.size();
  for(int i = node_list.size()-1; i > 0; i--){
    if(node_list[i]->map.size() == 0 && !node_list[i]->is_word_end){
    node_list[i-1]->map.erase(node_list[i]->characters);
    delete node_list[i];
    num_nodes--;
    num_characters = num_characters - c.size();
    }
    
  }
  num_words--;
  return;
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
  vector <string> word_list = autocomplete("");

  for(int i = 0; i < word_list.size(); i++){
    remove(word_list[i]);
  }

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
  // To do
  int count = word_count(word);
  if(count < 1){
    return false;
  }
  else{
    return true;
  }
}

trie_node* Tries::get_root() { return root; }


void Tries::set_root(trie_node* new_root) { root = new_root; }