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

// trie_node* build_three_node_list_helper(int one, int two, int three) {
//   trie_node* top(new node);
//   top->data = one;
//   top->next = new node;
//   top->next->data = two;
//   top->next->next = new node;
//   top->next->next->data = three;
//   top->next->next->next = (NULL);
//   return top;
// }

trie_node* help_init_node(trie_node* node){
  node->is_root = false;
  node->is_word_end = false;
  node->word_count = 0;
  return node;
}

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

TEST_F(test_Tries,insert){
  trie_node* small_trie_root = build_small_trie();
  set<char> alphabet = createAlphabetSet();
  Tries my_trie(alphabet);
  trie_node* my_trie_root = my_trie.get_root();

  my_trie.insert("mike");
  my_trie.insert("mitch");
  my_trie.insert("max");
  
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

// TEST_F(test_Tries, TestReport) {
//   Tries mylist;

//   string exp("");
//   ASSERT_EQ("", mylist.report());
//   add_points_to_grade(2);

//   // create a three node list and test the report result
//   node* top = build_three_node_list_helper(1, 2, 3);
//   // replace mylist top_ptr_ with this new top
//   mylist.set_top(top);
//   ASSERT_EQ("1 2 3 ", mylist.report());
//   add_points_to_grade(2);
// }

// TEST_F(test_Tries, TestAppendData) {
//   Tries mylist;
//   node* top = build_three_node_list_helper(42, 74, 51);
//   mylist.set_top(top);
//   mylist.append_data(10);

//   // get a cursor for appended data
//   node* cursor = mylist.get_top()->next->next->next;
//   ASSERT_TRUE(cursor);
//   add_points_to_grade(1);

//   ASSERT_FALSE(cursor->next); // expect to be NULL
//   add_points_to_grade(1);

//   ASSERT_EQ(10, cursor->data);
//   add_points_to_grade(1);

//   // try appending one more node
//   mylist.append_data(102);
//   // update cursor to point to fifth member
//   cursor = mylist.get_top()->next->next->next->next;
//   ASSERT_TRUE(cursor); // expect not to be NULL
//   add_points_to_grade(1);

//   ASSERT_FALSE(cursor->next); // expect to be NULL
//   add_points_to_grade(1);

//   ASSERT_EQ(102, cursor->data);
//   add_points_to_grade(1);
// }

// TEST_F(test_Tries, TestAppendNode) {

//   Tries mylist;

//   // test appending to empty list
//   node* ap_five = mylist.init_node(5);
//   // add node 15 to an empty list
//   mylist.append(ap_five);
//   // ensure the list has a non-null top
//   ASSERT_TRUE(mylist.get_top()); // expect not to be NULL
//   add_points_to_grade(1);
//   // ensure first element is the ap_nd node by coparing addresses
//   // ASSERT_EQ(ap_five.get(), mylist.GetTop().get());
//   ASSERT_EQ(ap_five, mylist.get_top());
//   add_points_to_grade(1);
//   // ensure first element's value is 15
//   ASSERT_EQ(5, mylist.get_top()->data);
//   add_points_to_grade(1);

//   // insert another node and test
//   node* ap_ten = mylist.init_node(10);
//   mylist.append(ap_ten);
//   ASSERT_EQ(10, mylist.get_top()->next->data);
//   add_points_to_grade(1);
//   ASSERT_FALSE(mylist.get_top()->next->next); // expect to be NULL
//   add_points_to_grade(1);

//   // try appending one more
//   node* ap_nn = mylist.init_node(99);
//   mylist.append(ap_nn);
//   ASSERT_EQ(99, mylist.get_top()->next->next->data);
//   add_points_to_grade(1);
//   ASSERT_FALSE(mylist.get_top()->next->next->next); // expect to b NULL
//   add_points_to_grade(1);
// }

// bool expect_all_helper(int vals[], int size, node* top) {
//   bool ret = true;
//   node* cursor = top;
//   for (int i = 0; i < size; i++) {
//     if (cursor == NULL || cursor->data != vals[i]) {
//       if (cursor == NULL) {
//         cout << "Cursor became null." << endl;
//       } else if (cursor->data != vals[i]) {
//         cout << cursor->data << " != " << vals[i] << endl;
//       }
//       ret = false;
//       break;
//     }
//     cursor = cursor->next;
//   }
//   return ret;
// }

// TEST_F(test_Tries, TestInsertData) {
//   Tries mylist;

//   node* threenode = build_three_node_list_helper(30, 20, 10);
//   mylist.set_top(threenode); // list is now 30, 20, 10

//   int initvals[] = {30, 20, 10};
//   ASSERT_TRUE(expect_all_helper(initvals, 3, mylist.get_top()));

//   mylist.insert_data(0, 4); // list is now 4, 30, 20, 10
//   int vals[] = {4, 30, 20, 10};
//   ASSERT_TRUE(expect_all_helper(vals, 4, mylist.get_top()));
//   add_points_to_grade(1);

//   mylist.insert_data(2, -78); // list is now 4, 30, -78, 20, 10
//   int vals2[] = {4, 30, -78, 20, 10};
//   ASSERT_TRUE(expect_all_helper(vals2, 5, mylist.get_top()));
//   add_points_to_grade(1);

//   mylist.insert_data(5, 99); // list is now 4, 30, -78, 20, 10, 99
//   int vals3[] = {4, 30, -78, 20, 10, 99};
//   ASSERT_TRUE(expect_all_helper(vals3, 6, mylist.get_top()));
//   add_points_to_grade(1);
// }

// TEST_F(test_Tries, TestInsertNode) {
//   Tries mylist;

//   node* threenode = build_three_node_list_helper(7, 98, -34);
//   mylist.set_top(threenode);

//   // add at beginning
//   node* nd_five = mylist.init_node(5);
//   mylist.insert(0, nd_five);
//   int vals[] = {5, 7, 98, -34};
//   ASSERT_TRUE(expect_all_helper(vals, 4, mylist.get_top()));
//   add_points_to_grade(1);

//   // add in middle
//   node* nd_middle = mylist.init_node(20);
//   mylist.insert(2, nd_middle);
//   int vals2[] = {5, 7, 20, 98, -34};
//   ASSERT_TRUE(expect_all_helper(vals2, 5, mylist.get_top()));
//   add_points_to_grade(1);

//   // add at end
//   node* nd_ending = mylist.init_node(800);
//   mylist.insert(5, nd_ending);
//   int vals3[] = {5, 7, 20, 98, -34, 800};
//   ASSERT_TRUE(expect_all_helper(vals3, 6, mylist.get_top()));
//   add_points_to_grade(1);
// }

// TEST_F(test_Tries, TestRemove) {
//   Tries mylist;

//   node* threenode = build_three_node_list_helper(7, 86, 210);
//   mylist.set_top(threenode);

//   int vals[] = {7, 86, 210};
//   ASSERT_TRUE(expect_all_helper(vals, 3, mylist.get_top()));

//   // remove start
//   mylist.remove(0);
//   int vals2[] = {86, 210};
//   ASSERT_TRUE(expect_all_helper(vals2, 2, mylist.get_top()));
//   add_points_to_grade(1);

//   // reset and remove mid
//   threenode = build_three_node_list_helper(7, 86, 210);
//   mylist.set_top(threenode);
//   mylist.remove(1);
//   int vals3[] = {7, 210};
//   ASSERT_TRUE(expect_all_helper(vals3, 2, mylist.get_top()));
//   add_points_to_grade(1);

//   // reset and remove end
//   threenode = build_three_node_list_helper(7, 86, 210);
//   mylist.set_top(threenode);
//   mylist.remove(2);
//   int vals4[] = {7, 86};
//   ASSERT_TRUE(expect_all_helper(vals4, 2, mylist.get_top()));
//   add_points_to_grade(1);
// }

// TEST_F(test_Tries, TestSize) {
//   Tries mylist;
//   ASSERT_EQ(0, mylist.size());
//   add_points_to_grade(2);

//   node* threenode = build_three_node_list_helper(76, 12, 423);
//   mylist.set_top(threenode);
//   ASSERT_EQ(3, mylist.size());
//   add_points_to_grade(2);
// }

// TEST_F(test_Tries, TestContains) {
//   Tries mylist;
//   node* threenode = build_three_node_list_helper(7, 0, -210);
//   mylist.set_top(threenode);

//   ASSERT_TRUE(mylist.contains(-210));
//   add_points_to_grade(0.8);
//   ASSERT_TRUE(mylist.contains(0));
//   add_points_to_grade(0.8);
//   ASSERT_TRUE(mylist.contains(7));
//   add_points_to_grade(0.8);
//   ASSERT_FALSE(mylist.contains(12));
//   add_points_to_grade(0.8);
//   ASSERT_FALSE(mylist.contains(-120));
//   add_points_to_grade(0.8);
// }