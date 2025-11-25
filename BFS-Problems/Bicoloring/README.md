🌟 Bicoloring (BFS) Problem Analysis
Problem: Graph Bicoloring

Can a graph be colored using two colors? We need to determine whether a graph can be colored with only two colors (e.g., white and black) such that no two adjacent nodes have the same color.

Core Concept (Bipartite Graph)

If a graph can be colored using two colors, then it is called a "Bipartite Graph". In a bipartite graph, the nodes can be divided into two separate disjoint sets (Set A, Set B), where all edges go from Set A to Set B.

🚫 When is Bicoloring Not Possible?

Condition: If a graph contains an "Odd-Length Cycle", then bicoloring is not possible.
Example: A triangle (3-cycle) cannot be bicolored, because if the first node is given one color, the third node must be given the opposite color of the first node. But since the third node is also adjacent to the first node, a conflict occurs.

🔍 Solution Algorithm: Breadth-First Search (BFS)

To solve this problem, we will use the graph traversal algorithm BFS. Using BFS, we will assign two colors (0 and 1) to nodes level by level and check whether two adjacent nodes have the same color.

Algorithm Steps:

Start: Mark all nodes as Uncolored (-1).

Start BFS: Use a Queue and begin from node 0, assigning it color 0.

Traversal: Remove a node u from the queue. For each neighbor v of u, try to assign the opposite color (1 - color[u]).

Conflict Check: If a neighbor v is already colored and its color is the same as u (color[v] == color[u]), then an Odd Cycle is found and the graph is NOT BICOLORABLE.

If BFS finishes successfully, then the graph is BICOLORABLE.

## 💻Pseudocode

```pseudocode
FUNCTION isBicolorable(n, adjList):
    
    DECLARE colors[n]
    FOR i FROM 0 TO n-1:
        colors[i] = -1  // -1: Uncolored
    DECLARE queue

    colors[0] = 0  // Start node gets Color 0
    queue.push(0)

    WHILE queue is not empty:
        u = queue.pop()
        neighborColor = 1 - colors[u]

        FOR each neighbor v in adjList[u]:
            
            IF colors[v] == -1:
                colors[v] = neighborColor
                queue.push(v)        
            
            ELSE IF colors[v] == colors[u]:
                RETURN false // Conflict detected

    RETURN true
