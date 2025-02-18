def bfs(graph, start):
    queue = [start]  # Initialize the queue with the start node
    visited = set()  # Set to keep track of visited nodes

    while queue:
        vertex = queue.pop(0)  # Dequeue the first element
        if vertex not in visited:
            print(vertex, end=' ')  # Print the current node
            visited.add(vertex)  # Mark it as visited
            
            # Add unvisited neighbors to the queue
            unvisited_neighbors = [neighbor for neighbor in graph[vertex] if neighbor not in visited]
            queue.extend(unvisited_neighbors)
            print(f"\nĐã thêm các nút kề của {vertex} vào hàng đợi: {unvisited_neighbors}")

# Minh họa
graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': ['F'],
    'F': []
}

print("BFS từ nút A:")
bfs(graph, 'A')  # Output: A B C D E F
