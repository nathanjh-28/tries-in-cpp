#include <iostream>
#include "../code/Tries.h"

using namespace std;

set <char> createAlphabetSet(){
  set<char> alphabet;
  for(char c = 'a'; c <= 'z';c++){
    alphabet.insert(c);
  }
  return alphabet;
}

void demo(){
  set<char> alphabet = createAlphabetSet();
  Tries my_trie(alphabet);

  my_trie.insert("mike");
  cout << "mike inserted, Report: " << my_trie.report() << endl;
  my_trie.insert("mitch");
  cout << "mitch inserted, Report: " << my_trie.report() << endl;
  my_trie.insert("max");
  cout << "max inserted, Report: " <<my_trie.report() << endl;
  my_trie.insert("steve");
  cout << "steve inserted, Report: " <<my_trie.report() << endl;
  my_trie.insert("frank");
  cout << "frank inserted, Report: " <<my_trie.report() << endl;


  cout << "number of words: " << my_trie.num_words << endl;
  cout << "remove mitch" << endl;
  my_trie.remove("mitch");
  cout << "number of words: " << my_trie.num_words << endl;
  cout << "Report: " <<my_trie.report() << endl;

  cout << "Example of printing a node's information:" << endl;
  cout << my_trie.print_node(my_trie.get_root());

  cout << "The End" << endl;

}

int main(){
  //demo();
  
  set<char> alphabet = createAlphabetSet();
  Tries my_trie(alphabet);

  my_trie.insert("mitch");
  my_trie.insert("mike");
  my_trie.compress_trie(my_trie.get_root());

  trie_node* cursor = my_trie.get_root();

  for(auto pair = cursor->map.begin(); pair != cursor->map.end(); pair++){
    cout << my_trie.print_node(pair->second) << endl;
  }

  cursor = cursor->map.at("mi");
    for(auto pair = cursor->map.begin(); pair != cursor->map.end(); pair++){
    cout << my_trie.print_node(pair->second) << endl;
  }




    
  return 0;
}