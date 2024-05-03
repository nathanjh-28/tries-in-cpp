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
  return ret;
}


void Tries::insert(string word) {
  // To do
  auto cursor = root;
  string c = "";

  // iterate through all of the characters in the word
  // and nodes in the trie (with cursor)
  // adding keys to maps if needed
  for(int i = 0; i < word.size(); i++){

    c = tolower(word[i]);

    // test if c is valid by checking if it is in the set
    if(alphabet.find(tolower(word[i])) == alphabet.end()){
      return;
    }

    
    // if the key does not exist in the map, add it
    if(cursor->map.find(c) == cursor->map.end()){
      trie_node* new_node = init_node(c);
      cursor->map.insert(make_pair(c,new_node));
      num_characters++;
      num_nodes++;
    }
    
    cursor = cursor->map.at(c);
  }
  // we reached the word ending node, update properties
  cursor->is_word_end = true;
  cursor->word_count++;
  num_words++;
  return;
}

void Tries::remove(string word) {
  // To do
  // create a stack vector to keep track of all the nodes traversed
  // so that we can backtrack and delete
  vector <trie_node*> node_list;
  
  trie_node* cursor = root;
  string c;
  
  // iterate through the word's characters and the trie's nodes
  for(int i = 0; i < word.size(); i++){
    c = word[i];
    node_list.push_back(cursor);
    
    // check if word is in the trie
    if(cursor->map.find(c) == cursor->map.end()){
      // doesn't exist in trie;
      return;
    }
    cursor = cursor->map.at(c);
  }
  // if word ending node is more than one, we only need to decrement
  if(cursor->word_count > 1){
    cursor->word_count--;
    num_words--;
    return;
  }
  // if word ending node has only one word count, we delete the whole node
  node_list[node_list.size()-1]->map.erase(cursor->characters);
  delete cursor;
  num_nodes--; 
  num_characters = num_characters - c.size();
  
  // loop through the stack we created and remove nodes that are not shared
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
  // iterate through the word's characters and the trie's nodes
  for(int i = 0; i < word.size(); i++){
    c = word[i];
    // if it's not there, return a count of 0
    if(cursor->map.find(c) == cursor->map.end()){
      return 0;
    }
    cursor = cursor->map.at(c);
  }
  return cursor->word_count;
}

// helper function for autocomplete that recursively maintains
// prefixes and a vector of words
void autocomplete_recurse(trie_node* subtrie, string prefix,vector<string>& word_list){
  if(subtrie->is_word_end){
    word_list.push_back(prefix);
  }
  for(auto i = subtrie->map.begin(); i != subtrie->map.end(); ++i){
    autocomplete_recurse(subtrie->map.at(i->first),prefix + i->first, word_list);
  }
}

vector<string> Tries::autocomplete(string prefix){
  vector<string> word_list;
  trie_node* cursor = root;
  string c;
  // iterate through the trie and the prefix to find where the 
  // subtrie for the prefix starts
  for(int i = 0; i < prefix.size(); i++){
    c = prefix[i];
    if(cursor->map.find(c) == cursor->map.end()){
      return word_list;
    }
    cursor = cursor->map.at(c);
  }
  // call helper function on the subtrie where the prefix ended
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
  // make a vector of the words in the trie
  vector <string> word_list = autocomplete("");

  // iterate through and delete one by one
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
  // creating a list by just calling 
  // autocomplete on a prefix of an empty string
  vector<string> list = autocomplete("");

  // edge case if it's just one
  if(list.size() == 1){
    return "'" + list[0] + "'";
  }

  // experimented with formatting and this is what I landed on...

  string ret = "'" + list[0] + ",";

  // concatenate with the output string every word in the list
  for(int i = 1; i < list.size()-1; i++){
    ret = ret + " " + list[i] + ",";
  }
  ret = ret + " " + list[list.size()-1];
  
  return ret + "'";
}
bool Tries::contains(string word) {
  // To do

  // we call word count and if it's more than 0, it's in the trie
  int count = word_count(word);
  if(count < 1){
    return false;
  }
  else{
    return true;
  }
}

string Tries::print_node(trie_node* node){
  
  string print_string = "==========\n";
  print_string += "PRINT NODE:\n";
  print_string += "==========\n";

  if(node->is_root == true){
    print_string += "This node is the root.\n";
  }
  else {
    print_string += "This node is NOT the root.\n";
  }
  if(node->is_word_end == true){
    print_string += "This node is a word ending node.\n";
  } else {
    print_string += "This node is NOT a word ending node.\n";
  }
  print_string += "The word count is " + to_string(node->word_count) + ".\n";

  print_string += "The node's characters are '" + node->characters + "'\n";

  print_string += "The node has the following keys in it's map: \n";

  for(auto i = node->map.begin(); i != node->map.end(); ++i){
    print_string += i->first + "\n";
  }

  return print_string + "\n==========\n";
}

trie_node* Tries::compress_node(trie_node* parent){
  // if the node can't be compressed just return it
  if(parent->map.size() != 1 || parent->is_root == true){
    return parent;
  }
  trie_node* child = parent->map.begin()->second;

  // compressing word ending nodes will be a nightmare to 
  // decompress later
  if(child->is_word_end == true || parent->is_word_end == true){
    return parent;
  }

  string child_characters = parent->map.begin()->first;

  // concatenate parents characters with child's characters
  parent->characters += child_characters;

  // replace the parent's map with the child's map
  parent->map = child->map;

  // update the number nodes in the trie
  num_nodes--;

  // return the newly compressed node
  return parent;


}

trie_node* Tries::decompress_node(trie_node* original_node){
  // we don't decompress these kinds of nodes
  if(original_node->is_word_end == true || original_node->characters.size() == 1){
    return original_node;
  }
  // variables for this process
  string c;
  vector <trie_node*> node_list;
  trie_node* new_node;
  auto original_map = original_node->map;
  
  // delete the map from the original node
  original_node->map.clear();

  // push the original into the list for easy linking later
  node_list.push_back(original_node);
  
  // make new nodes and put them in a list
  for(int i = 1; i < original_node->characters.size(); i++){
    c = original_node->characters[i];
    new_node = init_node(c);
    num_nodes++;
    node_list.push_back(new_node);
  }

  // update the new node's characters to just be the first character
  original_node->characters = original_node->characters[0];

  // iterate through our list of nodes and link them together
  for(int i = 1; i < node_list.size()-1; i++ ){
  node_list[i]->map.insert(make_pair(node_list[i+1]->characters,node_list[i+1]));
  }

  // the original map is attached to the last node in the decompressed list
  node_list[node_list.size()-1]->map = original_map;

  return original_node;

}

void Tries::compress_trie(trie_node* subtrie){

  if(subtrie->map.size() == 1 && 
  subtrie->is_word_end == false && 
  subtrie->map.begin()->second->is_word_end == false &&
  subtrie->is_root == false
  ){
    compress_node(subtrie);
  }
  for(auto i = subtrie->map.begin(); i != subtrie->map.end(); i++ ){
    compress_trie(i->second);
  }

  if(subtrie->is_root){
    update_maps_keys(subtrie);
  }
  return;

}

void Tries::decompress_trie(trie_node* subtrie){
  if(subtrie->characters.size() > 1){
    decompress_node(subtrie);
  }
  for(auto i = subtrie->map.begin(); i != subtrie->map.end(); i++ ){
    decompress_trie(i->second);
  }
  return;

}

void Tries::update_maps_keys(trie_node* subtrie){
  vector <string> remove_list;
  for(auto pair = subtrie->map.begin(); pair != subtrie->map.end(); pair++){
    if(pair->first != pair->second->characters){
      subtrie->map.insert(make_pair(pair->second->characters,pair->second));
      remove_list.push_back(pair->first);
    }
  }
  for(int i = 0; i < remove_list.size(); i++){
    subtrie->map.erase(remove_list[i]);
  }
  for(auto pair = subtrie->map.begin(); pair != subtrie->map.end(); pair++){
    update_maps_keys(pair->second);
  }
  return;
}

trie_node* Tries::get_root() { return root; }


void Tries::set_root(trie_node* new_root) { root = new_root; }