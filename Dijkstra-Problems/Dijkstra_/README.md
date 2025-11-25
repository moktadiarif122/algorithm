Dijkstra — Shortest Path in Weighted Graph
🔍 What is the problem?

The goal of this problem is to find the minimum cost or distance path from vertex 1 to vertex n in a weighted undirected graph.

In other words, we want to know —
👉 “What is the minimum sum of edge weights needed to go from vertex 1 to vertex n, and which path should be taken?”

📥 Input Description
n m  
a1 b1 w1  
a2 b2 w2  
...  
am bm wm

Symbol	Meaning
n	Total number of vertices (2 ≤ n ≤ 10⁵)
m	Total number of edges (0 ≤ m ≤ 10⁵)
a, b	Two vertices connected by an edge
w	Weight of the edge (1 ≤ w ≤ 10⁶)

The graph may contain multiple edges and loops.

📤 Output Description

If there is no path from 1 → n, print -1

Otherwise, print the shortest path (vertices in order)

🧠 Nature of the Problem

This is a Single Source Shortest Path (SSSP) problem where all edge weights are positive.

If all edge weights were equal (e.g., = 1), then it could be solved using BFS.

But since weights vary (1 to 10⁶), Dijkstra’s Algorithm is the most efficient solution.

⚙️ Dijkstra’s Algorithm in Brief

Dijkstra’s Algorithm follows a Greedy approach.

Start from the source node (vertex 1).

Repeatedly select the vertex with the smallest distance.

Update all its neighbours if a shorter distance is found.

Continue this process until we reach the destination vertex n.

🧩 Graph Representation (Adjacency List)

Each vertex holds a list of its neighbours along with edge weights.

1 → (2, 2), (4, 1)  
2 → (1, 2), (3, 4), (5, 5)  
4 → (1, 1), (3, 3)  
3 → (2, 4), (4, 3), (5, 1)  
5 → (2, 5), (3, 1)

🧮 Variables
Variable	Description
dist[i]	Minimum distance from vertex 1 to vertex i
orig[i]	Parent of vertex i (from which vertex it came)
pq	A min-heap (priority queue) that always provides the vertex with the smallest dist
INF	A very large value, such as 1e18
## 💡 PseudoCode

```text
FUNCTION Dijkstra(n, m, edges):
    Initialize graph as adjacency list
    For each edge (a, b, w):
        Add (b, w) to graph[a]
        Add (a, w) to graph[b]
    For i = 1 to n:
        dist[i] = INF
        orig[i] = -1
    dist[1] = 0
    pq = priority_queue()
    pq.push((0, 1)) // (distance, vertex)

    WHILE pq is not empty:
        (d, u) = pq.top()
        pq.pop()
        IF d > dist[u]:
            CONTINUE
        FOR each (v, w) in graph[u]:
            IF dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                orig[v] = u
                pq.push((dist[v], v))

    IF dist[n] == INF:
        RETURN -1
    ELSE:
        BUILD path from n to 1 using orig[]
        REVERSE path
        PRINT path
```

🧩 Sample Input
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1

🧱 Step-by-Step Visualization
Step	Current Node	Neighbors (v, w)	Relaxation	Updated dist[ ]	PQ Content
Init	—	—	—	dist[1]=0, others=∞	(0,1)
1	1	(2,2), (4,1)	dist[2]=2, dist[4]=1	[0,2,∞,1,∞]	(1,4), (2,2)
2	4	(1,1), (3,3)	dist[3]=4	[0,2,4,1,∞]	(2,2), (4,3)
3	2	(1,2), (5,5), (3,4)	dist[5]=7 (temp), dist[3]=4 (same)	[0,2,4,1,7]	(4,3), (7,5)
4	3	(2,4), (4,3), (5,1)	dist[5]=5 (better!)	[0,2,4,1,5]	(5,5)
5	5	done	—	—	—
🔄 Path Reconstruction

Tracing the orig[] array gives:

5 ← 3 ← 4 ← 1


So, the path is:

1 → 4 → 3 → 5

✅ Output
1 4 3 5

⏱️ Time Complexity Analysis
Complexity	Explanation
Time Complexity	O((n + m) log n) — each edge is relaxed at most once and a priority queue is used
Space Complexity	O(n + m) — for storing adjacency list and dist/orig arrays
🧾 Summary
Topic	Explanation
Problem	Shortest path from vertex 1 to vertex n in a weighted graph
Algorithm	Dijkstra’s Algorithm
Graph Type	Undirected, Weighted
Negative Weight Edge?	Not supported
Data Structure	Priority Queue (Min-Heap)
Result	Shortest Path or -1



