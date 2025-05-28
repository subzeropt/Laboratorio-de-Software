 Block of codes to be used in other projects 

The "8rainhas" code implements:
Depth-First Search (DFS) using a stack. The algorithm explicitly uses a stack<vector> stack; 
- the stack is the typical DFS data structure. The expansion of the nodes (or board states) is done within the while loop (!stack.empty()),
 and the new valid states are added to the stack to be explored. DFS goes through the states until it finds a solution or exhausts the possibilities,
 without considering the cost of the path or using heuristics (that's why it's blind search).


"Arvores binarias" represented by a vector with the particularity of being a HeapMinimum:
Block to put the smallest value always on the left-hand side
Block moves up one element in the vector to maintain the min heap property
drops an element to reorganize the heap after removal
Block to read user input and call the insert function
Block to insert an item into the heap

