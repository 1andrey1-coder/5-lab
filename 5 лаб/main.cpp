import heapq

graph = {
    'A': {'B': 1},
    'B': {'A': 1, 'C': 2, 'D': 2, 'E': 7},
    'C': {'B': 2, 'E': 3},
    'D': {'B': 2, 'E': 4},
    'E': {'B': 7, 'C': 3, 'D': 4}
}

def get_shortest_path(graph, start, end):
    queue = [(0, start)]
    distances = {node: float('inf') for node in graph}
    distances[start] = 0
    
    while queue:
        current_dist, current_node = heapq.heappop(queue)
        
        if current_node == end:
            return current_dist
            
        if current_dist > distances[current_node]:
            continue
            
        for neighbor, weight in graph[current_node].items():
            distance = current_dist + weight
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(queue, (distance, neighbor))
                
    return distances[end]

print(get_shortest_path(graph, 'A', 'E'))
