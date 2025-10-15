from collections import deque

def bfs(graph, start):
    visited = set()
    queue = deque([start])
    visited.add(start)

    while queue:
        vertex = queue.popleft()
        print(vertex, end=' ')
        for neighbor in graph[vertex]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)

if __name__ == "__main__":
    n = int(input("Enter number of vertices: "))
    graph = {i: [] for i in range(n)}
    e = int(input("Enter number of edges: "))
    for _ in range(e):
        u, v = map(int, input().split())
        graph[u].append(v)
        graph[v].append(u)  # if undirected
    start = int(input("Enter start vertex: "))
    bfs(graph, start)
