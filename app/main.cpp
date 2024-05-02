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

int main(){

    // Do some printing
    int var;
    cout << "Hello World, please enter a number " << endl;
    cin >> var;
    cout << "your number was : " << var << endl;

    set<char> alphabet = createAlphabetSet();
    Tries my_trie(alphabet);

    my_trie.insert("mike");
    string report = my_trie.report();
    cout << report << endl;
    my_trie.insert("mitch");
    report = my_trie.report();
    cout << report << endl;
    my_trie.insert("max");
    report = my_trie.report();
    cout << report << endl;

    if(my_trie.contains("mitch") == true){
        cout << "got mitch" << endl;
    }
    if(my_trie.contains("steve") == false){
        cout << "don't have steve" << endl;
    }

    cout << "number of words: " << my_trie.num_words << endl;
    my_trie.remove("mitch");
    if(my_trie.contains("mitch") == false){
        cout << "mitch gone" << endl;
    }
    cout << "number of words: " << my_trie.num_words << endl;

    cout << my_trie.report() << endl;


    // usage, user enters a paragraph or sentence.  
    // Parse each word and have it insert in to the trie.
    // cli interface for the methods?

    // how can I visualize trie in list form...

    cout << my_trie.print_node(my_trie.get_root());

    return 0;
}