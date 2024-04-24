#ifndef TRIES_H__
#define TRIES_H__

#include <memory>
#include <string>

using namespace std;

struct node {
  int data;   // value of this node
  node* next; // points to the next node, or NULL if this is the last node.
};

// Linked List Invariant: following the 'next' links must eventually lead to a
// NULL reference signifying the end of the list. (E.g. no circular references
// are allowed.)
class Tries {
public:
  // Constructor. Initialize class variables and pointers here if need.
  // Initially set top pointer to null.
  Tries();

  // Deconstructor. Can probably leave this empty because we use bare pointers
  // (node*), and you must reclaim heap memory immediately when that memory is
  // no longer used.
  ~Tries();

  // Creates a new node structure from heap memory. It points to NULL and holds
  // the provided integer. The function returns a pointer to that new node.
  node* init_node(int data);

  // Creates a space-separated string representing the contents of the list, in
  // the same order they are found beginning from the top of the list. Return
  // that string object. For example, this might return "" (the empty string) if
  // the list is empty, or it might return "1 7 3 " (note the space at the end).
  string report();

  // AppendData adds a node to the end of the list pointed to by top. The
  // resulting list is one element longer, and the newly appended node has the
  // given data value. Consider using the Append function to help - just create
  // a new node* and let Append do the work.
  void append_data(int data);

  // Append is the same as AppendData, except we're adding a node, rather than a
  // value.
  void append(node* new_node);

  // InsertData inserts a new node that contains the given data value, so the
  // new node occupies the offset indicated. Any nodes that were already in the
  // list at that offset and beyond are shifted down by one. For example if the
  // list contains 23, 74, 93, and we insert 42 at index 1, the resulting list
  // should be 23, 42, 74, 93.
  //
  // If an offset is beyond the end (or beginning) of the list, this function
  // should have no effect.
  //
  // Inserting at the end of the list should have the same effect as appending.
  void insert_data(int offset, int data);

  // This is the same as insert_data, except we're inserting a node, rather than
  // a value. This closely mirrors Append and AppendData.
  void insert(int offset, node* new_node);

  // Removes the node indicated by the given offset and frees its memory. For
  // example if our list contains 23, 74, 93, and we remove offset 1, the
  // resulting list should then contain 23, 93.
  //
  // If an invalid offset is given (e.g. negative or beyond the end of the
  // list), this function has no effect.
  void remove(int offset);

  // Returns the number of nodes in the linked list reachable by head
  // before (but not including) the terminating NULL link. E.g., an empty list
  // has size 0, a list with one item has size 1, etc.
  int size();

  // Returns true if this linked list contains a node with the specified value,
  // false otherwise.
  bool contains(int data);

  // This function is implemented for you. Returns the top pointer.
  node* get_top();

  // This is implemented for you. It sets a given pointer as the top pointer.
  void set_top(node* top_ptr);

  // You can declare more public member variables and member functions here if
  // you need them. Implement them in the cpp file.

private:
  node* top_ptr_;

  // you can add add more private member variables and member functions here if
  // you need
};

#endif // TRIES_H__