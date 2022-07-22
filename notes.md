- `std::sort()` uses introsort: hybrid of quicksort, heapsort and insertion sort
- Types of self-balancing tress: Red-black trees, AVL trees, etc
- `std::map` uses red-black trees
- `std::unordered_map` uses hashmap/hashtable
- Comparator for `std::priority_queue` is opposite to intuition. `std::greater<int>` creates a min binary heap. Defining custom comparator is not simply using a lambda expression. Have to create an `auto` variable, give its `decltype` to the priority_queue declaration and then pass the comparator variable again. Below url has more details:
    + [Stack Overflow: C++ priority_queue with lambda comparator error](https://stackoverflow.com/questions/5807735/c-priority-queue-with-lambda-comparator-error)
- DFS: Preorder traversal
- BFS: Level-order traversal
