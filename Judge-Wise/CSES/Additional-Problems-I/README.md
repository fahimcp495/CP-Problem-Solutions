# CSES Additional Problems I Solutions

[![CSES](https://img.shields.io/badge/CSES-Additional%20Problems%20I-blue.svg)](https://cses.fi/problemset/)
[![Language](https://img.shields.io/badge/Language-C++17-orange.svg)](https://isocpp.org/)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)

**Advanced competitive programming solutions** for CSES Additional Problems I section. Each solution includes optimized C++ implementation with detailed algorithmic hints.

## Problems List

<details open>
<summary><b>Click to expand/collapse problem list</b></summary>

| # | Problem | Solution | Hint |
|---|---------|----------|------|
| 1086 | [Writing Numbers](https://cses.fi/problemset/task/1086) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-1086-Writing-Numbers.cpp) | <details><summary>Hint 1</summary>Each digit can be used at most $n$ times. Which digit becomes the bottleneck?</details><details><summary>Hint 2</summary>If you can write all numbers up to $x$, can you also write all numbers up to $x-1$?</details><details><summary>Hint 3</summary>Binary search on the last number and compute the required count of digit $1$.</details> |
| 1087 | [Shortest Subsequence](https://cses.fi/problemset/task/1087) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-1087-Shortest-Subsequence.cpp) | <details><summary>Hint 1</summary>Consider the smallest prefix where all four characters appear. What happens when you try to match any character?</details><details><summary>Hint 2</summary>After finding all four characters, repeat the process from the next position.</details><details><summary>Hint 3</summary>Greedily build the answer by adding a character to the result whenever all 4 characters have been seen.</details> |
| 1142 | [Advertisement](https://cses.fi/problemset/task/1142) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-1142-Advertisemen.cpp) | <details><summary>Hint 1</summary>Classic maximum rectangle in histogram problem.</details><details><summary>Hint 2</summary>For each bar, find the nearest smaller bar on the left and right.</details><details><summary>Hint 3</summary>Use a monotonic stack to find these boundaries in $O(n)$ time.</details> |
| 1147 | [Maximum Building I](https://cses.fi/problemset/task/1147) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-1147-Maximum-Building-I.cpp) | <details><summary>Hint 1</summary>For each row, track the height of consecutive forest cells ending at that row.</details><details><summary>Hint 2</summary>This converts the 2D problem into multiple 1D histogram problems.</details><details><summary>Hint 3</summary>Apply the maximum rectangle in histogram algorithm for each row.</details> |
| 1162 | [Sorting Methods](https://cses.fi/problemset/task/1162) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-1162-Sorting-Methods.cpp) | <details><summary>Hint 1</summary>Method 1 (swaps): Count inversions using merge sort.</details><details><summary>Hint 2</summary>Method 2 (cycles): Decompose into cycles, answer is $n$ minus the number of cycles.</details><details><summary>Hint 3</summary>Method 3 (insert): Answer is $n$ minus the longest increasing subsequence length.</details><details><summary>Hint 4</summary>Method 4 (remove): Count elements not in their correct suffix position.</details> |
| 1188 | [Bit Inversions](https://cses.fi/problemset/task/1188) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-1188-Bit-Inversions.cpp) | <details><summary>Hint 1</summary>Build two segment trees: one for consecutive 0s, one for consecutive 1s.</details><details><summary>Hint 2</summary>Each node stores: maximum consecutive segment in range, maximum prefix, and maximum suffix.</details><details><summary>Hint 3</summary>When flipping bit $i$, update both trees and query the maximum from both.</details> |
| 1191 | [Cyclic Array](https://cses.fi/problemset/task/1191) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-1191-Cyclic-Array.cpp) | <details><summary>Hint 1</summary>Double the array to handle circular wrapping.</details><details><summary>Hint 2</summary>For each starting position, find the farthest position reachable with sum $\leq k$.</details><details><summary>Hint 3</summary>Use binary lifting on prefix sums to jump efficiently through reachable positions.</details> |
| 1670 | [Swap Game](https://cses.fi/problemset/task/1670) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-1670-Swap-Game.cpp) | <details><summary>Hint 1</summary>Model each game state as a node in a graph.</details><details><summary>Hint 2</summary>What type of graph search finds the minimum number of moves?</details><details><summary>Hint 3</summary>Use BFS to find the shortest path from the initial state to target state $123456789$.</details> |
| 1747 | [Pyramid Array](https://cses.fi/problemset/task/1747) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-1747-Pyramid-Array.cpp) | <details><summary>Hint 1</summary>At least one element will remain unchanged as the peak.</details><details><summary>Hint 2</summary>For each candidate peak, the left side should be non-decreasing and the right side non-increasing.</details><details><summary>Hint 3</summary>Count inversions on the left side and ordered pairs on the right side using a data structure like Fenwick tree.</details> |
| 2186 | [Special Substrings](https://cses.fi/problemset/task/2186) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-2186-Special-Substrings.cpp) | <details><summary>Hint 1</summary>Track the frequency array for each prefix.</details><details><summary>Hint 2</summary>Normalize frequencies by subtracting the minimum frequency from all frequencies.</details><details><summary>Hint 3</summary>Two prefixes form a valid substring if they have the same normalized state and all distinct characters have appeared.</details> |
| 2414 | [List of Sums](https://cses.fi/problemset/task/2414) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-2414-List-of-Sums.cpp) | <details><summary>Hint 1</summary>The smallest sum is $a_0 + a_1$. The second smallest is $a_0 + a_2$.</details><details><summary>Hint 2</summary>Try different candidates for $a_1 + a_2$ and derive $a_1$ from it.</details><details><summary>Hint 3</summary>Once you determine $a_0$ and $a_1$, greedily build the remaining elements and validate.</details> |
| 2422 | [Multiplication Table](https://cses.fi/problemset/task/2422) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-2422-Multiplication-Table.cpp) | <details><summary>Hint 1</summary>You need to find the $\frac{n \times n}{2}$-th smallest number in the multiplication table.</details><details><summary>Hint 2</summary>Consider the reverse problem: given value $x$, what is its position when elements are sorted?</details><details><summary>Hint 3</summary>Binary search on the answer. For each candidate $x$, count elements $\leq x$ using $\sum_{i=1}^{n} \min(n, \lfloor x/i \rfloor)$.</details> |
| 2425 | [Stack Weights](https://cses.fi/problemset/task/2425) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-2425-Stack-Weights.cpp) | <details><summary>Hint 1</summary>At any moment, the largest weight dominates the comparison.</details><details><summary>Hint 2</summary>Process weights from largest to smallest, tracking cumulative effects.</details><details><summary>Hint 3</summary>Use segment tree with range updates to maintain minimum and maximum cumulative weights.</details> |
| 3150 | [Distinct Values Sum](https://cses.fi/problemset/task/3150) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-3150-Distinct-Values-Sum.cpp) | <details><summary>Hint 1</summary>To maintain distinctness, consider only the first occurrence of each value in a subarray.</details><details><summary>Hint 2</summary>Calculate the contribution of each element to the total sum.</details><details><summary>Hint 3</summary>For position $i$, contribution is $(i - \text{last\_occurrence} + 1) \times (n - i)$ where last_occurrence tracks the previous index of $a_i$.</details> |
| 3151 | [Bubble Sort Rounds I](https://cses.fi/problemset/task/3151) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-3151-Bubble-Sort-Rounds-I.cpp) | <details><summary>Hint 1</summary>Find the initial and sorted position of each element.</details><details><summary>Hint 2</summary>If an element is not in its correct position, how many rounds until it reaches there?</details><details><summary>Hint 3</summary>In one round, each element can move left at most once. For each element, compute how far left it needs to move.</details><details><summary>Hint 4</summary>The answer is the maximum distance any element needs to move left.</details> |
| 3152 | [Bubble Sort Rounds II](https://cses.fi/problemset/task/3152) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-3152-Bubble-Sort-Rounds-II.cpp) | <details><summary>Hint 1</summary>In one round, each element can move left at most once if not in the correct position.</details><details><summary>Hint 2</summary>Consider the first $k$ largest elements. Which element should be placed first?</details><details><summary>Hint 3</summary>Process elements in decreasing order. Use policy-based data structures to count elements and place each optimally.</details> |
| 3169 | [Counting LCM Arrays](https://cses.fi/problemset/task/3169) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-3169-Counting-LCM-Arrays.cpp) | <details><summary>Hint 1</summary>Prime factorize $k = p_1^{e_1} \times p_2^{e_2} \times \ldots \times p_m^{e_m}$.</details><details><summary>Hint 2</summary>Are the prime powers independent or dependent for counting?</details><details><summary>Hint 3</summary>Count valid arrays for each prime power using DP (transition: max power seen so far to next state).</details><details><summary>Hint 4</summary>Use matrix exponentiation to optimize the DP computation.</details> |
| 3175 | [Beautiful Permutation II](https://cses.fi/problemset/task/3175) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-3175-Beautiful-Permutation-II.cpp) | <details><summary>Hint 1</summary>Greedily try to place the smallest unused number. If not possible, try the next smallest.</details><details><summary>Hint 2</summary>Do you notice any pattern in valid permutations?</details><details><summary>Hint 3</summary>Pattern-based construction: alternate between odd and even numbers with specific spacing to ensure adjacent elements differ by at least 2.</details> |
| 3190 | [Distinct Values Splits](https://cses.fi/problemset/task/3190) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-3190-Distinct-Values-Splits.cpp) | <details><summary>Hint 1</summary>Can dynamic programming help here?</details><details><summary>Hint 2</summary>Is the transition costly? The transition involves summing multiple previous DP values. How can you optimize this?</details><details><summary>Hint 3</summary>Use prefix sums to optimize the DP transitions from $O(n^2)$ to $O(n)$.</details> |
| 3193 | [Square Subsets](https://cses.fi/problemset/task/3193) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-3193-Square-Subsets.cpp) | <details><summary>Hint 1</summary>A product is a perfect square if all prime powers have even exponents.</details><details><summary>Hint 2</summary>Represent each number as a bitmask tracking the parity of its prime factors.</details><details><summary>Hint 3</summary>Find the rank of these bitmask vectors using linear XOR basis.</details><details><summary>Hint 4</summary>The answer is $2^{n-\text{rank}} - 1$.</details> |
| 3213 | [Water Containers Moves](https://cses.fi/problemset/task/3213) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-3213-Water-Containers-Moves.cpp) | <details><summary>Hint 1</summary>Model the problem as a graph where each state represents water amounts.</details><details><summary>Hint 2</summary>Treat each state $(\text{amount\_in\_A}, \text{amount\_in\_B})$ as a node and each of the six moves as an edge.</details><details><summary>Hint 3</summary>Find the weighted shortest path using Dijkstra's algorithm where edge weight is the amount of water moved.</details> |
| 3214 | [Water Containers Queries](https://cses.fi/problemset/task/3214) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-3214-Water-Containers-Queries.cpp) | <details><summary>Hint 1</summary>Find the invariant of the total water amount across operations.</details><details><summary>Hint 2</summary>What condition must the invariant satisfy?</details><details><summary>Hint 3</summary>By Bézout's identity, you can achieve any multiple of $\gcd(a, b)$.</details><details><summary>Hint 4</summary>Check if $x$ is divisible by $\gcd(a, b)$ and ensure $x \leq a$.</details> |
| 3294 | [Subarray Sum Constraints](https://cses.fi/problemset/task/3294) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-3294-Subarray-Sum-Constraints.cpp) | <details><summary>Hint 1</summary>Model as difference constraints: $\text{prefix}[v] - \text{prefix}[u] = w$.</details><details><summary>Hint 2</summary>Build a graph where edge $u \to v$ has weight $w$ and edge $v \to u$ has weight $-w$.</details><details><summary>Hint 3</summary>Use DFS to assign prefix sum values. Check for contradictions (cycles with non-zero sum).</details> |
| 3301 | [Maximum Average Subarrays](https://cses.fi/problemset/task/3301) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-3301-Maximum-Average-Subarrays.cpp) | <details><summary>Hint 1</summary>Greedily select the segment with maximum average and try to extend it.</details><details><summary>Hint 2</summary>Use a set with custom comparator to maintain segments ordered by their average.</details><details><summary>Hint 3</summary>Track which segments can be merged and maintain the answer for each ending position.</details> |
| 3302 | [Subsets with Fixed Average](https://cses.fi/problemset/task/3302) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-3302-Subsets-with-Fixed-Average.cpp) | <details><summary>Hint 1</summary>When you subtract the average from each element in a list, what becomes the new average?</details><details><summary>Hint 2</summary>After subtracting the average, find subsets with sum $= 0$.</details><details><summary>Hint 3</summary>Use DP on achievable sums. Process positive values first, then negative values. The answer is $\text{dp}[0] - 1$.</details> |
| 3306 | [Nearest Campsites I](https://cses.fi/problemset/task/3306) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-3306-Nearest-Campsites-I.cpp) | <details><summary>Hint 1</summary>Do you know the relationship between Manhattan distance and Chebyshev distance?</details><details><summary>Hint 2</summary>To find the nearest campsite in Chebyshev distance, consider 4 cases based on the signs of $dx$ and $dy$.</details><details><summary>Hint 3</summary>Use coordinate transformation and sweep line with segment tree. The answer is the maximum nearest distance.</details> |
| 3307 | [Nearest Campsites II](https://cses.fi/problemset/task/3307) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-3307-Nearest-Campsites-II.cpp) | <details><summary>Hint 1</summary>Do you know the relationship between Manhattan distance and Chebyshev distance?</details><details><summary>Hint 2</summary>To find the nearest campsite in Chebyshev distance, consider 4 cases based on the signs of $dx$ and $dy$.</details><details><summary>Hint 3</summary>Use coordinate transformation and sweep from both directions. Output individual distances instead of the maximum.</details> |
| 3361 | [Two Array Average](https://cses.fi/problemset/task/3361) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-3361-Two-Array-Average.cpp) | <details><summary>Hint 1</summary>Binary search on the maximum average value.</details><details><summary>Hint 2</summary>When you subtract the average from each element, what becomes the new average?</details><details><summary>Hint 3</summary>For candidate average $x$, transform arrays: $a_i - x$ and $b_i - x$.</details><details><summary>Hint 4</summary>Find maximum prefix sum in each transformed array. Check if their sum $\geq 0$.</details> |
| 3403 | [Permutation Subsequence](https://cses.fi/problemset/task/3403) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-3403-Permutation-Subsequence.cpp) | <details><summary>Hint 1</summary>Only consider elements from $1$ to $\min(n, m)$ since larger values can't appear in both arrays.</details><details><summary>Hint 2</summary>Can you connect this problem to the Longest Increasing Subsequence (LIS)?</details><details><summary>Hint 3</summary>Sort indices by their position in the first array, then find LIS on their positions in the second array.</details> |

</details>

## Topics Covered

<details>
<summary><b>Data Structures (Click to expand)</b></summary>

- **Stack**: Monotonic stack for histogram problems
- **Segment Tree**: Range queries and updates
- **Fenwick Tree (BIT)**: Point updates, range queries
- **Set/Map**: State tracking and ordering
- **Policy-Based Data Structures**: Order statistics tree
- **Linear Basis**: Linear algebra on XOR operations

</details>

<details>
<summary><b>Algorithms (Click to expand)</b></summary>

- **Greedy**: Optimal local choices
- **Dynamic Programming**: State-based optimization
- **Binary Search**: On answer
- **Two Pointers**: Linear scanning technique
- **Graph Algorithms**: BFS, DFS, Dijkstra
- **Sorting**: Custom comparators, merge sort

</details>

<details>
<summary><b>Advanced Techniques (Click to expand)</b></summary>

- **Prefix Sums**: Range sum queries
- **State Space Search**: BFS on configurations
- **Binary Lifting**: Fast ancestor queries
- **Matrix Exponentiation**: Fast computation
- **Difference Constraints**: System of inequalities

</details>

<details>
<summary><b>Mathematics (Click to expand)</b></summary>

- **Number Theory**: GCD, prime factorization
- **Combinatorics**: Counting techniques
- **Linear Algebra**: Basis computation

</details>

## Notes

- All solutions are **tested and accepted** on CSES judge
- Time complexity is optimized for given constraints
- Code follows competitive programming best practices

## Author

**Fahim Khandakar** - [@fahimcp495](https://codeforces.com/profile/fahimcp495)

---

### Keywords
`CSES` `competitive programming` `algorithms` `data structures` `C++` `problem solving` `coding interview` `DSA` `Additional Problems` `advanced algorithms` `segment tree` `dynamic programming` `graph algorithms` `number theory`