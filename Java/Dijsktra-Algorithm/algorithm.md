Problem: Find the shortest path from a source vertex to all other vertices in a weighted graph with non-negative weights.

Algorithm (Stepwise / Pseudocode):

Input: Graph G(V, E), source vertex s
Output: dist[] – shortest distance from s to all vertices

1. Initialize dist[v] = ∞ for all vertices v except dist[s] = 0
2. Create a set of unvisited vertices U = V
3. While U is not empty:
    a. Select vertex u from U with minimum dist[u]
    b. Remove u from U
    c. For each neighbor v of u:
        i. If v is in U and dist[u] + weight(u, v) < dist[v]:
            - Update dist[v] = dist[u] + weight(u, v)
4. Return dist[]


Time Complexity: O(V²) (can be reduced to O((V + E) log V) with a priority queue)

