♞ Knight Moves (BFS in 2D Grid) — Knight’s Shortest Path
🔍 What is the Problem?

The task of this problem is to solve a classic shortest path scenario.
The specific objective is: given two squares a and b on a chessboard,
determine the minimum number of moves a knight needs to go from a to b.

This problem can be modeled as a shortest path problem in an unweighted graph.

🎯 Modeling
Concept	Description
Nodes	The 64 squares of the chessboard represent the nodes
Edges	A valid knight move between two squares represents an edge
Cost	Each move has equal cost (i.e., 1 move)

Therefore, the most ideal algorithm to find the shortest path in such a graph is
Breadth-First Search (BFS).

🧠 What is BFS?

BFS (Breadth-First Search) is a graph traversal algorithm that starts from a source node and explores
the graph level by level based on distance.

It uses a Queue data structure and guarantees that a longer path is never explored before a shorter one.

For unweighted graphs (like this knight movement problem), BFS is the most effective method to find the shortest path.

🎲 Representing the Board and Knight Moves

Before applying BFS, we must represent how a knight can move from one square to another.

♘ The 8 Possible Knight Moves

From a position (i, j), a knight can move to at most 8 different squares:

(i-2, j+1)
(i-2, j-1)
(i-1, j+2)
(i-1, j-2)
(i+1, j+2)
(i+1, j-2)
(i+2, j+1)
(i+2, j-1)

💻 Implementation in Code
// kr[] array stores the possible row changes 
const int kr[] = {2, 2, -2, -2, 1, 1, -1, -1}; 

// kc[] array stores the possible column changes 
const int kc[] = {1, -1, 1, -1, 2, -2, 2, -2}; 


By running a loop from i = 0 to 7 and calculating:
new_r = r + kr[i] and new_c = c + kc[i],
we can obtain all possible reachable squares from position (r, c).

⚙️ Using Breadth-First Search (BFS)

BFS is perfect for this problem because it explores the graph layer by layer.

Layer 0: Starting square (distance 0)

Layer 1: Squares reachable in 1 move

Layer 2: Squares reachable in 2 moves
... and so on.

The moment we first reach the destination square,
we can be sure that this is the shortest path.

🧩 Required Arrays
Name	Purpose
dist[8][8]	Stores the minimum number of moves from the start square to each square
color[8][8]	Tracks the visiting state of each square
queue<pair<int,int>> q	Holds squares to be processed next
🎨 Meaning of Color Values

-1 → White (Not visited)

1 → Gray (In queue)

2 → Black (Processing completed)

## 🧮 PseudoCode

```cpp
FUNCTION bfs_knight(startR, startC, endR, endC):
    N = 8
    DEFINE dist[N][N], color[N][N]
    DEFINE Queue Q

    FOR r FROM 0 TO N-1:
        FOR c FROM 0 TO N-1:
            dist[r][c] = INFINITY
            color[r][c] = -1

    dist[startR][startC] = 0
    color[startR][startC] = 1
    ENQUEUE (startR, startC)

    WHILE Q IS NOT EMPTY:
        (r, c) = DEQUEUE()

        IF (r, c) == (endR, endC):
            RETURN dist[r][c]

        FOR i FROM 0 TO 7:
            newR = r + kr[i]
            newC = c + kc[i]

            IF newR,newC IS ON BOARD AND color[newR][newC] == -1:
                color[newR][newC] = 1
                dist[newR][newC] = dist[r][c] + 1
                ENQUEUE(newR, newC)

        color[r][c] = 2

    RETURN -1
