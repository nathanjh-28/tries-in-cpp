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

// constructor, initialize class variables and pointers here if need.
Tries::Tries() {
  // Your code here
}

// deconstructor,
Tries::~Tries() {}

node* Tries::init_node(int data) {
  node* ret(new node);
  // Your code here
  return ret;
}

string Tries::report() {
  string ret;
  // Your code here
  return ret;
}

void Tries::append_data(int data) {
  // Your code here
}

void Tries::append(node* new_node) {
  // Your code here
}

void Tries::insert_data(int offset, int data) {
  // Your code here
}

void Tries::insert(int offset, node* new_node) {
  // Your code here
}

void Tries::remove(int offset) {
  // Your code here
}

int Tries::size() {
  int ret;
  // Your code here
  return ret;
}

bool Tries::contains(int data) {
  bool ret;
  // Your code here
  return ret;
}

// This function is implemented for you
// It returns the top pointer
node* Tries::get_top() { return top_ptr_; }

// This function is implemented for you
// It sets a given pointer as the top pointer
void Tries::set_top(node* top_ptr) { top_ptr_ = top_ptr; }