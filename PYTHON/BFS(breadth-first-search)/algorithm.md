# BFS Algorithm

1. Create a queue Q
2. Mark all vertices as unvisited
3. Enqueue the starting vertex and mark as visited
4. While Q is not empty:
   a. Dequeue a vertex u
   b. Print u
   c. For each neighbor v of u:
      - If v is unvisited, mark visited and enqueue v
