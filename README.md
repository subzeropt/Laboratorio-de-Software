The code implements:

Depth-First Search (DFS) using a stack. The algorithm explicitly uses a stack<vector> stack; 
- the stack is the typical DFS data structure. The expansion of the nodes (or board states) is done within the while loop (!stack.empty()),
  and the new valid states are added to the stack to be explored. DFS goes through the states until it finds a solution or exhausts the possibilities,
  without considering the cost of the path or using heuristics (that's why it's blind search).



