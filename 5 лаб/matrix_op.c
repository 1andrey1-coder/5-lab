# --- ЗАДАНИЕ 2 ---
print("--- ЗАДАНИЕ 2 ---")
v_count = int(input("Введите количество вершин (n): "))
edges_complete = v_count * (v_count - 1) // 2
edges_tree = v_count - 1 if v_count > 0 else 0
print(f"Количество ребер для полного графа: {edges_complete}")
print(f"Количество ребер для дерева: {edges_tree}\n")

# --- ЗАДАНИЕ 3 ---
print("--- ЗАДАНИЕ 3 ---")
deg_seq = sorted(list(map(int, input("Введите степенную последовательность через пробел: ").split())), reverse=True)
is_graphical = True
if sum(deg_seq) % 2 != 0:
    is_graphical = False
else:
    # Алгоритм Гавела-Хакими для проверки последовательности степеней
    seq = deg_seq[:]
    while seq and seq[0] >= 0:
        if seq[0] == 0:
            break
        d = seq.pop(0)
        if d > len(seq):
            is_graphical = False
            break
        for i in range(d):
            seq[i] -= 1
        seq.sort(reverse=True)
    if any(x < 0 for x in seq):
        is_graphical = False

if is_graphical:
    print("Граф возможен")
else:
    print("Граф невозможен: нарушена теорема о рукопожатиях или критерий Эрдеша-Галлаи")

# --- ЗАДАНИЕ 4 ---
print("\n--- ЗАДАНИЕ 4 ---")
n_v = int(input("Введите n для графов: "))
print(f"Хроматическое число пустого графа: {1 if n_v > 0 else 0}")
print(f"Хроматическое число полного графа: {n_v}")
print(f"Хроматическое число дерева: {2 if n_v > 1 else 1}")
print(f"Хроматическое число цикла Cn: {2 if n_v % 2 == 0 else 3}")

# --- ЗАДАНИЕ 5 ---
print("\n--- ЗАДАНИЕ 5 (Граф с картинки) ---")
# Вершины: A=0, B=1, C=2, D=3
vertices = ['A', 'B', 'C', 'D']
# Матрица смежности для четырехугольника со средней диагональю BD
adj = [
    [0, 1, 0, 1],  # A
    [1, 0, 1, 1],  # B
    [0, 1, 0, 1],  # C
    [1, 1, 1, 0]   # D
]
print("2. Матрица смежности:")
for row in adj:
    print(row)

# Ребра графа для матрицы инцидентности
edges = [('A','B'), ('A','D'), ('B','C'), ('B','D'), ('C','D')]
inc = [[0]*len(edges) for _ in range(4)]
for e_idx, (u, v) in enumerate(edges):
    inc[vertices.index(u)][e_idx] = 1
    inc[vertices.index(v)][e_idx] = 1

print("\n3. Матрица инцидентности:")
for row in inc:
    print(row)

# Матрица Кирхгофа (D - A, где D - матрица степеней)
laplacian = []
for i in range(4):
    deg = sum(adj[i])
    row = [-adj[i][j] if i != j else deg for j in range(4)]
    laplacian.append(row)

print("\n4. Матрица Кирхгофа:")
for row in laplacian:
    print(row)

# Поиск эксцентриситетов и радиуса через алгоритм BFS
def bfs_distances(start_idx, matrix):
    dist = {i: float('inf') for i in range(len(matrix))}
    dist[start_idx] = 0
    queue = [start_idx]
    while queue:
        curr = queue.pop(0)
        for neighbor, connected in enumerate(matrix[curr]):
            if connected and dist[neighbor] == float('inf'):
                dist[neighbor] = dist[curr] + 1
                queue.append(neighbor)
    return dist

eccentricities = {}
for i, v in enumerate(vertices):
    dists = bfs_distances(i, adj)
    eccentricities[v] = max(dists.values())

print(f"\n5. Эксцентриситеты: {eccentricities}")
print(f"Радиус графа: {min(eccentricities.values())}")

# Дейкстра для поиска кратчайшего пути между А и Е (из Задания 1)
print("\n6. Кратчайший путь А -> Е (из таблицы первого задания):")
graph_weighted = {
    'A': {'B': 1},
    'B': {'A': 1, 'C': 2, 'D': 2, 'E': 7},
    'C': {'B': 2, 'E': 3},
    'D': {'B': 2, 'E': 4},
    'E': {'B': 7, 'C': 3, 'D': 4}
}

def dijkstra(graph, start, end):
    distances = {node: float('inf') for node in graph}
    distances[start] = 0
    unvisited = list(graph.keys())
    
    while unvisited:
        curr = min(unvisited, key=lambda node: distances[node])
        if distances[curr] == float('inf') or curr == end:
            break
        unvisited.remove(curr)
        
        for neighbor, weight in graph[curr].items():
            new_dist = distances[curr] + weight
            if new_dist < distances[neighbor]:
                distances[neighbor] = new_dist
                
    return distances[end]

print(f"Длина кратчайшего расстояния между А и Е: {dijkstra(graph_weighted, 'A', 'E')}")
