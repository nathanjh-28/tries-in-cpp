// If you change anything in this file, your changes will be ignored
// in your homework submission.
// Chekout TEST_F functions bellow to learn what is being tested.
#include "../code/Tries.h"
// #include "../code/Tries.cpp"
#include <gtest/gtest.h>

#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// helper function for creating an alphabet set
set <char> createAlphabetSet(){
  set<char> alphabet;
  for(char c = 'a'; c <= 'z';c++){
    alphabet.insert(c);
  }
  return alphabet;
}

class test_Tries : public ::testing::Test {
protected:
  // This function runs only once before any TEST_F function
  static void SetUpTestCase() {
    std::ofstream outgrade("./total_grade.txt");
    if (outgrade.is_open()) {
      outgrade.clear();
      outgrade << (int)0;
      outgrade.close();
    }
  }

  // This function runs after all TEST_F functions have been executed
  static void TearDownTestCase() {
    std::ofstream outgrade("./total_grade.txt");
    if (outgrade.is_open()) {
      outgrade.clear();
      outgrade << (int)std::ceil(100 * total_grade / max_grade);
      outgrade.close();
      std::cout << "Total Grade is : "
                << (int)std::ceil(100 * total_grade / max_grade) << std::endl;
    }
  }

  void add_points_to_grade(double points) {
    if (!::testing::Test::HasFailure()) {
      total_grade += points;
    }
  }

  // this function runs before every TEST_F function
  void SetUp() override {}

  // this function runs after every TEST_F function
  void TearDown() override {
    std::ofstream outgrade("./total_grade.txt");
    if (outgrade.is_open()) {
      outgrade.clear();
      outgrade << (int)std::ceil(100 * total_grade / max_grade);
      outgrade.close();
    }
  }

  static double total_grade;
  static double max_grade;
};

double test_Tries::total_grade = 0;
double test_Tries::max_grade = 38;

// test the initialization of a new Trie
TEST_F(test_Tries, TestInitialization) {
  set <char> alpha = createAlphabetSet();
  Tries my_Tries(alpha);
  // testing the root node
  trie_node* my_root = my_Tries.get_root();
  ASSERT_EQ(my_root->is_root,true); // expect root to be true
  ASSERT_EQ(my_root->is_word_end,false); // expect root to be false
  ASSERT_EQ(my_root->word_count,0); // expect root to be 0
  ASSERT_EQ(my_root->characters,""); // expect root to be ""
  add_points_to_grade(1);
  // testing the empty trie data structure
  ASSERT_EQ(my_Tries.num_words,0); // no words yet
  ASSERT_EQ(my_Tries.num_nodes,0); // no nodes yet
  ASSERT_EQ(my_Tries.num_characters,0); // no characters yet
  ASSERT_EQ(my_Tries.alphabet, alpha); // should be the same
  add_points_to_grade(1);
}

// test a initializing a new node

// helper for helper to save a few lines
trie_node* help_init_node(trie_node* node){
  node->is_root = false;
  node->is_word_end = false;
  node->word_count = 0;
  return node;
}

// helper function to manually build a trie
trie_node* build_small_trie(){
  // make a root
  trie_node* ret(new trie_node);
  ret = help_init_node(ret);
  ret->is_root = true;

  // insert "mike"
  trie_node* m(new trie_node);
  m = help_init_node(m);
  m->characters = "m";
  ret->map.insert(make_pair("m",m));
  trie_node* i(new trie_node);
  i = help_init_node(i);
  m->map.insert(make_pair("i",i));
  i->characters = "i";
  trie_node* k(new trie_node);
  k = help_init_node(k);
  i->map.insert(make_pair("k",k));
  k->characters = "k";
  trie_node* e(new trie_node);
  e = help_init_node(e);
  k->map.insert(make_pair("e",e));
  e->characters = "e";
  e->is_word_end = true;
  e->word_count = 1;

  // insert "mitch"
  trie_node* t(new trie_node);
  t = help_init_node(t);
  i->map.insert(make_pair("t",t));
  t->characters = "t";
  trie_node* c(new trie_node);
  c = help_init_node(c);
  c->characters = "c";
  t->map.insert(make_pair("c",c));
  trie_node* h(new trie_node);
  h = help_init_node(h);
  c->map.insert(make_pair("h",h));
  h->characters = "h";
  h->is_word_end = true;
  h->word_count = 1;
  
  // insert "max"
  trie_node* a(new trie_node);
  a = help_init_node(a);
  m->map.insert(make_pair("a",a));
  a->characters = "a";
  trie_node* x(new trie_node);
  x = help_init_node(x);
  a->map.insert(make_pair("x",x));
  x->characters = "x";
  x->is_word_end = true;
  x->word_count = 1;


  return ret;
}

// test insert
TEST_F(test_Tries,insert){
  trie_node* small_trie_root = build_small_trie();
  set<char> alphabet = createAlphabetSet();
  Tries my_trie(alphabet);
  trie_node* my_trie_root = my_trie.get_root();

  my_trie.insert("mike");
  ASSERT_EQ(my_trie.num_characters,4);
  ASSERT_EQ(my_trie.num_words,1);
  ASSERT_EQ(my_trie.num_nodes,4);

  my_trie.insert("mitch");
  ASSERT_EQ(my_trie.num_characters,7);
  ASSERT_EQ(my_trie.num_words,2);
  ASSERT_EQ(my_trie.num_nodes,7);

  my_trie.insert("max");
  ASSERT_EQ(my_trie.num_characters,9);
  ASSERT_EQ(my_trie.num_words,3);
  ASSERT_EQ(my_trie.num_nodes,9);
  
  // test for "mike"
  auto x = small_trie_root->map.at("m");
  auto y = my_trie_root->map.at("m");
  ASSERT_EQ(x->characters,y->characters);

  x = x->map.at("i");
  y = y->map.at("i");
  ASSERT_EQ(x->characters,y->characters);

  x = x->map.at("k");
  y = y->map.at("k");
  ASSERT_EQ(x->characters,y->characters);

  x = x->map.at("e");
  y = y->map.at("e");
  ASSERT_EQ(x->characters,y->characters);
  ASSERT_EQ(x->is_word_end,y->is_word_end);
  ASSERT_EQ(x->word_count,y->word_count);

  // test for "mitch"
  x = small_trie_root->map.at("m");
  y = my_trie_root->map.at("m");
  x = x->map.at("i");
  y = y->map.at("i");
  x = x->map.at("t");
  y = y->map.at("t");
  ASSERT_EQ(x->characters,y->characters);
  x = x->map.at("c");
  y = y->map.at("c");
  ASSERT_EQ(x->characters,y->characters);
  x = x->map.at("h");
  y = y->map.at("h");
  ASSERT_EQ(x->characters,y->characters);
  ASSERT_EQ(x->is_word_end,y->is_word_end);
  ASSERT_EQ(x->word_count,y->word_count);

  // test for "max"
  x = small_trie_root->map.at("m");
  y = my_trie_root->map.at("m");
  x = x->map.at("a");
  y = y->map.at("a");
  ASSERT_EQ(x->characters,y->characters);
  x = x->map.at("x");
  y = y->map.at("x");
  ASSERT_EQ(x->characters,y->characters);
  ASSERT_EQ(x->is_word_end,y->is_word_end);
  ASSERT_EQ(x->word_count,y->word_count);

}

// test remove

// test word count
TEST_F(test_Tries, word_count){
  set<char> alphabet = createAlphabetSet();
  Tries my_trie(alphabet);

  my_trie.insert("mike");
  my_trie.insert("mitch");
  my_trie.insert("mitch");
  my_trie.insert("max");
  my_trie.insert("max");
  my_trie.insert("max");

  ASSERT_EQ(my_trie.word_count("mike"),1);
  ASSERT_EQ(my_trie.word_count("mitch"),2);
  ASSERT_EQ(my_trie.word_count("max"),3);

}

// test autocomplete
TEST_F(test_Tries,autocomplete){
  set<char> alphabet = createAlphabetSet();
  Tries my_trie(alphabet);

  my_trie.insert("mike");
  my_trie.insert("mitch");
  my_trie.insert("max");

  vector<string> a = my_trie.autocomplete("mi");
  vector<string> b = {"mitch","mike"};
  ASSERT_EQ(a,b);

  a = my_trie.autocomplete("m");
  b = {"max","mitch","mike"};
  ASSERT_EQ(a,b);


  a = my_trie.autocomplete("ma");
  b = {"max"};
  ASSERT_EQ(a,b);
}

// test get characters count

// test size

// test report

// test contains