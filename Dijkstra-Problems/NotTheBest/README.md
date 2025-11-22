# Second Shortest Path (Modified Dijkstra Algorithm)

Robin একটি গ্রামে থাকে যেখানে মোট **Nটি intersection** এবং **Rটি bidirectional রাস্তা** আছে।  
তার গন্তব্য `1 → N`, কিন্তু সে **shortest path না নিয়ে** **second-shortest path** নিতে চায়।

## 🧠 Problem Definition

Second-shortest path বলতে বোঝায়:

- এটি **shortest path এর চেয়ে বড়**
- কিন্তু **অন্য সব বড় পথের চেয়ে ছোট**
- এমনকি চাইলে **edge পুনরায় ব্যবহার** করা যেতে পারে
- গ্রাফে **positive weights**

আমাদের প্রতিটি test case-এ  
`Case X: second_shortest_path_cost`  
প্রিন্ট করতে হবে।

---

## 🔍 Algorithm Overview — Modified Dijkstra

আমরা প্রতিটি নোডের জন্য রাখব দুইটি distance:

- `dist1[v]` → shortest distance to `v`
- `dist2[v]` → second-shortest distance to `v`

Relaxation rule:

1. যদি নতুন পথ **shortest** এর থেকে ছোট হয়:
   - নতুন shortest সেট করো
   - পুরনো shortest কপি করে second-shortest বানাও

2. যদি shortest < নতুন পথ < second-shortest:
   - second-shortest আপডেট করো

Dijkstra’s priority queue নিশ্চিত করে যে  
**সবসময় ছোট দূরত্ব আগে প্রসেস হবে**,  
তাই এই দুই distance ঠিকভাবে maintain হয়।

---

## 📌 Input Format
T
N R
u v w
u v w
...

- **T** = test cases
- **N** = intersections (1–5000)
- **R** = roads (1–100000)
- **w** = weight (1–5000)

---

## 📌 Output Format

Case X: result

---

## 🧪 Example

### Input
2
3 3
1 2 100
2 3 200
1 3 50
4 4
1 2 100
2 4 200
2 3 250
3 4 100

### Output
Case 1: 150
Case 2: 450


---

## 🛠️ How to Compile

```sh
g++ -std=c++17 second_shortest.cpp -o second
```
---

## Step-By-Step Solution

# Second Shortest Path Example

This README demonstrates **how to find the second-shortest path** using a **Modified Dijkstra algorithm**.  

We will use a single test case:

---

## Test Case

1
4 4
1 2 100
2 4 200
2 3 250
3 4 100



Goal: Find the **second-shortest path from 1 → 4**.

---

## Graph (ASCII)

(1)---100---(2)---200---(4)
|
250
|
(3)
(3)---100---(4)


Edges:

- 1 → 2 = 100  
- 2 → 4 = 200  
- 2 → 3 = 250  
- 3 → 4 = 100  

---

## Initial State

dist1 = [inf, 0, inf, inf, inf] // 1-based nodes
dist2 = [inf, inf, inf, inf, inf]
Priority Queue = {(0,1)}


---

## Step-by-Step Execution

### Step 1 — Pop (0,1)

Relax neighbors of node 1:

- 1 → 2 : new_dist = 100 → update dist1[2] = 100  
- Push (100,2) into PQ

**State after step 1:**

dist1 = [inf, 0, 100, inf, inf]
dist2 = [inf, inf, inf, inf, inf]
PQ = {(100,2)}


---

### Step 2 — Pop (100,2)

Relax neighbors of node 2:

- 2 → 1 : new_dist = 200 → update dist2[1] = 200, push (200,1)  
- 2 → 4 : new_dist = 300 → update dist1[4] = 300, push (300,4)  
- 2 → 3 : new_dist = 350 → update dist1[3] = 350, push (350,3)  

**State after step 2:**

dist1 = [inf, 0, 100, 350, 300]
dist2 = [inf, 200, inf, inf, inf]
PQ = {(200,1), (300,4), (350,3)}


---

### Step 3 — Pop (200,1)

Relax neighbors:

- 1 → 2 : new_dist = 300 → update dist2[2] = 300, push (300,2)

**State after step 3:**

dist1 = [inf, 0, 100, 350, 300]
dist2 = [inf, 200, 300, inf, inf]
PQ = {(300,2), (300,4), (350,3)}


---

### Step 4 — Pop (300,2)

Relax neighbors:

- 2 → 4 : new_dist = 500 → update dist2[4] = 500, push (500,4)  
- 2 → 3 : new_dist = 550 → update dist2[3] = 550, push (550,3)  
- 2 → 1 : new_dist = 400 → no update (dist2[1]=200)

**State after step 4:**

dist1 = [inf, 0, 100, 350, 300]
dist2 = [inf, 200, 300, 550, 500]
PQ = {(300,4), (350,3), (500,4), (550,3)}


---

### Step 5 — Pop (300,4)

Relax neighbors:

- 4 → 3 : new_dist = 400 → update dist2[3]=400, push (400,3)  
- 4 → 2 : new_dist = 500 → no update (dist2[2]=300)

**State after step 5:**

dist1 = [inf, 0, 100, 350, 300]
dist2 = [inf, 200, 300, 400, 500]
PQ = {(350,3), (400,3), (500,4), (550,3)}


---

### Step 6 — Pop (350,3)

Relax neighbors:

- 3 → 2 : new_dist = 600 → no update (dist2[2]=300)  
- 3 → 4 : new_dist = 450 → update dist2[4]=450, push (450,4)

**State after step 6:**

dist1 = [inf, 0, 100, 350, 300]
dist2 = [inf, 200, 300, 400, 450]
PQ = {(400,3), (450,4), (500,4), (550,3)}


> After this step, no further updates occur. dist2[4] has stabilized.

---

## Final Result

| Type              | Path         | Cost |
|------------------|-------------|------|
| Shortest         | 1 → 2 → 4   | 300  |
| Second-shortest  | 1 → 2 → 3 → 4 | 450  |

**Observation:** No backtracking required; both paths are simple.

---

# 📎 Conclusion

- This example demonstrates **how dist1 and dist2 arrays** are updated  
- **Priority Queue** ensures nodes are processed by current shortest distance  
- After all relaxations, **dist2[N] gives the second-shortest path cost**



./second



