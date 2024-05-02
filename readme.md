# Standard Tries in C++
***by Nathan Harris*** <br>
***A Final Project for CSPB 2270 Data Structures Spring 2024*** <br>

### What is the *Tries* data structure?
A trie is a treelike data structure where paths from root to leaf represent words inserted and prefix characters shared with words share nodes.  Tries are useful when matching prefixes or implementing autocomplete in a smart text editor.

## Usage
The usage for this project should look familiar since I used the linked list homework assignment as a template.  After cloning the repository and opening your terminal:

`cd build` <br>
`cmake ..` <br>
`make` <br>
`./run_app`  - For running a contrived set of print statements. <br>
`./run_tests` - To see tests executed and passed. <br>

## Invariants
-	Each node in the trie has at most 26 children corresponding to the letters of the alphabet.
-	Every path from root node to word ending node represents a unique word in the trie, ensuring unique representation and retrievability.
-	The height of the trie is equal to the longest word inserted.
-	The root node has no parent and no associated character.
-	Each node maintains a numerical count indicating how many words end at that node.
-	Words that share prefixes share nodes and separate at the end of their common prefix.
-	The trie maintains a hierarchical tree structure with parent-child relationships and no cycles.


## Outline of Implementation

### Trie Node Properties:
- is_root
- is_word_end
- word_count
- map that holds pointers to next nodes
- characters assigned to node

### Tries Class Properties
- number of words
- number of nodes
- number of characters
- set with valid characters
- root node

### Tries Class Methods
- Constructor (set of valid characters)
- Deconstructor
- insert (word)
- remove (word)
- word count (word)
- autocomplete (prefix)
- nodes
- size
- clear
- report
- print node(trie node)
- contains (word)
- get root
- set root

### Underlying Data Structures
- Hash map for storing pointers to nodes
- Sets for the alphabet
- Vector for list of autocomplete words
- Vector for stack implementation when removing nodes

### Helper Functions
- Function to create a set of the alphabet programatically
- Small Trie, making a small trie manually to compare in tests

## Motivation
For this project I simply enjoyed a similar and smaller programming assignment in CSPB 3104 and wished to expand on it. In the process I would practice using C++ as well as writing tests.  I figured by modeling our weekly homework assignments in a way I could be contributing to the library of homework assignments for 2270.

## Reflection
This has been a really challenging project mainly due to the open ended nature of the requirements.  Transitioning from weekly homework assignments with strict rules, tests, and requirements was jarring but hammered in a great learning experience.  I tried to mitigate this by sticking to the structure of the weekly assignments but still, planning the project, deciding how to go about writing tests, which methods to include, how a user would interact with the data structure really revealed to me how much time and effort can go in to just a basic project.  

Before this project, I did not have as much experience writing tests and dreaded it.  In the end, I did not enjoy writing the tests but felt that I gained a new understanding.  When writing tests I understood the philosophy of writing a test, seeing it fail, and then writing the code.  But in reality, sometimes it's okay for a test to not be perfect, and to view the tests as a work in progress.  This notion helped me move forward on the project with out getting bogged down in writing tests.  Knowing that it's a bit of a back and forth conversation, between implementation and tests, helped pave the way for a practical way to implement testing in to a project.  

## Stretch Goals
Compression tries or Radix trees and comparing using them.  I implemented the properties of the tries in a way that I could transition them in to compression tries if I wanted to.