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

## Complexity
The trie data structure is a very efficient and fast for inserting and looking up words in a corpus.  The limitations are related to the levels of the tree based on what has been inserted.  For insert the average and worst case complexity is $O(m)$ where $m$ is the length of the string that is being inserted.  Traversal would reflect the number of letters in the word.  Similarly, remove would have a worst case complexity of $O(m)$ since traversal is required.  In the worst case, no strings share prefixes.  In that case every level of the tree corresponds to a character in every word that has been inserted.  Printing a report of the trie would require iterating through all of the characters that were inserted in to the string.  If there were 26 words inserted and if each word did not share prefixes, it would be $O(26^{(26^{(26^{(26^{...})})}})$.  This is a highly unlikely scenario since there are numerous prefixes in the English language.  For spatial complexity, since each node reflects one character, and often prefixes are more than one character, the spatial complexity can be improved by compressing the trie nodes such that prefixes take up only one node.  Additional methods would be required for compressing and decompressing when inserting and removing words.


## Implementation Breakdown

### Trie Node Properties:
- is_root
    - Boolean value to keep track of nodes that are roots.
- is_word_end
    - Boolean value to note if this node marks the ending of a word.
- word_count
    - Reflects the number of times a word has been inserted in to the trie and ended on this node.
- map that holds pointers to next nodes
    - The main part of a trie, the connections between the nodes are pointers stored in a map where the key is the next character in the word.
- characters assigned to node
    - Traditionally, the single characters are *only* keys in the map but I put this property here so that I could implement a compression method later.

### Tries Class Properties
- number of words inserted
- number of nodes created
- number of characters in the trie 
    - For standard trie this would be the same as nodes but for a compressed trie it would be more as nodes can hold more than one character.
- set with valid characters
    - In our case this is just a set with all of the characters of the alphabet used to establish what are valid keys in this data structure.
- root node
    - The entry point for the trie data structure.

### Tries Class Methods
- constructor 
    - Takes in a set of valid characters.
- deconstructor
- insert (word)
    - Inserts a word in to the Trie.  Updates the properties on the class.
- remove (word)
    - Removes a word from the Trie.  Updates the properties on the class.
- word count (word)
    - Returns the number of times a specific word has been inserted in to the Trie.
- autocomplete (prefix)
    - Returns a vector of words that share the prefix.
- nodes
    - Returns the number of nodes.
- size
    - Returns the number of words inserted.
- clear
    - Removes all of the characters and nodes leaving just a root.
- report
    - Creates a string with all of the words in the Trie.
- print node(trie node)
    - Creates a multiline string with all of the properties of a given node.
- contains (word)
    - Check if a word is in the Trie.
- get root
    - The root is a private member, so access is through this method.
- set root
    - Changing the root is through this method.

### Underlying Data Structures
- Hash map for storing pointers to nodes
- Set for the alphabet
- Vector for list of autocomplete words
- Vector for stack implementation when removing nodes

### Helper Functions
- Create Alphabet, function to create a set of the alphabet programatically
- Build Small Trie, making a small trie manually to compare in tests
- Help Init Node, to save lines on initializing nodes in tests

## Motivation
For this project I simply enjoyed a similar and smaller programming assignment in CSPB 3104 and wished to expand on it. In the process I would practice using C++ as well as writing tests.  I figured by modeling our weekly homework assignments in a way I could be contributing to the library of homework assignments for 2270.

## Reflection
This has been a really challenging project mainly due to the open ended nature of the requirements.  Transitioning from weekly homework assignments with strict rules, tests, and requirements was jarring but hammered in a great learning experience.  I tried to mitigate this by sticking to the structure of the weekly assignments but still, planning the project, deciding how to go about writing tests, which methods to include, how a user would interact with the data structure really revealed to me how much time and effort can go in to just a basic project.  

Before this project, I did not have as much experience writing tests and dreaded it.  In the end, I did not enjoy writing the tests but felt that I gained a new understanding.  When writing tests I understood the philosophy of writing a test, seeing it fail, and then writing the code.  But in reality, sometimes it's okay for a test to not be perfect, and to view the tests as a work in progress.  This notion helped me move forward on the project with out getting bogged down in writing tests.  Knowing that it's a bit of a back and forth conversation, between implementation and tests, helped pave the way for a practical way to implement testing in to a project.  

For writing C++, I learned a lot of interesting techniques, for example using the unordered_map library and iterating through a map.  Using sets for the first time in C++.  I continued to polish the basic C++ skills that we acquired in this course while in the process of exploring a data structure.

## Stretch Goals or What's Next
In my proposal I discussed implementing Compression tries or Radix trees if I were to have extra time and considered comparing using them.  I implemented the properties of the tries in a way that I could transition them in to compression tries if I wanted to.  In the end, I ran out of time to implement this and left my notes as comments in the code.  If I were to continue to work on this project that is one place where I would focus my efforts.  Building up a Trie structure that contains the standard implementation, compressed, and coming up with ways to compare usage.  

I feel that I have barely scratched the surface for writing tests.  Working on this project would involve hunting down edge cases and writing better tests.  I feel that these tests are good for a first draft but really working on them so that it will handle more edge cases could be a great way to continue to strengthen my test writing skills.

One thing I keep going back and forth on is whether to add a property to the trie node called parent, that holds a pointer to the parent node.  I decided for remove to instead use a stack as a vector, and remove the nodes backtracking until we reached a node that is used by another word.  Another way to do it would be to backtrack using the parent but I felt that using a stack would be more interesting.  I feel that if I were to implement the compress trie method, I would want to use a parent attribute to easily merge parents and children that only have one key in the their map.  I also had some last minute thoughts on visualizing the trie to help show it in the terminal and I considered having a rank as an attribute on the node so that if you are printing the trie, you could insert the node's data in to a 2D vector where each vector is a level in the trie, and would reflect the ranking of the nodes in the trie.  For example, the nodes that are ranked 2 steps away from the root would be in the 2nd vector of the 2D vectors.  

## Conclusion
This has been a great project to research, explore and implement a data structure in C++ as well as practice writing tests and using the cmake makefile.  I am grateful for this opportunity and look forward to encountering Tries in the real world!