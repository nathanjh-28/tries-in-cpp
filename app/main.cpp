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

    my_trie.remove("mitch");
    if(my_trie.contains("mitch") == false){
        cout << "mitch gone" << endl;
    }

    cout << my_trie.report() << endl;


    return 0;
}