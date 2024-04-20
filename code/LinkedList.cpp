//  <TODO Filename>
//      <TODO: Describe the data structure here >
//
//  Author: <TODO: place your name here>
//  CU ID: <TODO: place your CU ID here (4 letters - 4 digits)>
//  GitHub Username: <TODO: place your GitHub user name here>
//  Hours to complete lab: <TODO: place the number of hours needed to complete
//  lab, do not count time reading or watching videos>
//

#include "LinkedList.h"

// constructor, initialize class variables and pointers here if need.
LinkedList::LinkedList() {
  // Your code here
}

// deconstructor,
LinkedList::~LinkedList() {}

node* LinkedList::init_node(int data) {
  node* ret(new node);
  // Your code here
  return ret;
}

string LinkedList::report() {
  string ret;
  // Your code here
  return ret;
}

void LinkedList::append_data(int data) {
  // Your code here
}

void LinkedList::append(node* new_node) {
  // Your code here
}

void LinkedList::insert_data(int offset, int data) {
  // Your code here
}

void LinkedList::insert(int offset, node* new_node) {
  // Your code here
}

void LinkedList::remove(int offset) {
  // Your code here
}

int LinkedList::size() {
  int ret;
  // Your code here
  return ret;
}

bool LinkedList::contains(int data) {
  bool ret;
  // Your code here
  return ret;
}

// This function is implemented for you
// It returns the top pointer
node* LinkedList::get_top() { return top_ptr_; }

// This function is implemented for you
// It sets a given pointer as the top pointer
void LinkedList::set_top(node* top_ptr) { top_ptr_ = top_ptr; }