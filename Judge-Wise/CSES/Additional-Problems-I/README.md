# CSES Additional Problems I Solutions

[![CSES](https://img.shields.io/badge/CSES-Additional%20Problems%20I-blue.svg)](https://cses.fi/problemset/)
[![Language](https://img.shields.io/badge/Language-C++17-orange.svg)](https://isocpp.org/)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)

**Advanced competitive programming solutions** for CSES Additional Problems I section. Each solution includes optimized C++ implementation with detailed algorithmic hints.

## Problems List

| # | Problem | Solution | Hint |
|---|---------|----------|------|
| 1087 | [Shortest Subsequence](https://cses.fi/problemset/task/1087) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-1087-Shortest-Subsequence.cpp) | <details><summary>Hint 1</summary>Consider the smallest prefix where all four characters appear. What happens when you try to match any character?</details><details><summary>Hint 2</summary>After finding all four characters, repeat the process from the next position.</details><details><summary>Hint 3</summary>Greedily build the answer by adding a character to the result whenever all 4 characters have been seen.</details> |
| 3150 | [Distinct Values Sum](https://cses.fi/problemset/task/3150) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-3150-Distinct-Values-Sum.cpp) | <details><summary>Hint 1</summary>To maintain distinctness, consider only the first occurrence of each value in a subarray.</details><details><summary>Hint 2</summary>Calculate the contribution of each element to the total sum.</details><details><summary>Hint 3</summary>For position $i$, contribution is $(i - \text{last\_occurrence} + 1) \times (n - i)$ where last_occurrence tracks the previous index of $a_i$.</details> |
| 3190 | [Distinct Values Splits](https://cses.fi/problemset/task/3190) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-3190-Distinct-Values-Splits.cpp) | <details><summary>Hint 1</summary>Can dynamic programming help here?</details><details><summary>Hint 2</summary>Is the transition costly? The transition involves summing multiple previous DP values. How can you optimize this?</details><details><summary>Hint 3</summary>Use prefix sums to optimize the DP transitions from $O(n^2)$ to $O(n)$.</details> |
| 1670 | [Swap Game](https://cses.fi/problemset/task/1670) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-1670-Swap-Game.cpp) | <details><summary>Hint 1</summary>Model each game state as a node in a graph.</details><details><summary>Hint 2</summary>What type of graph search finds the minimum number of moves?</details><details><summary>Hint 3</summary>Use BFS to find the shortest path from the initial state to target state $123456789$.</details> |
| 3175 | [Beautiful Permutation II](https://cses.fi/problemset/task/3175) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-3175-Beautiful-Permutation-II.cpp) | <details><summary>Hint 1</summary>Greedily try to place the smallest unused number. If not possible, try the next smallest.</details><details><summary>Hint 2</summary>Do you notice any pattern in valid permutations?</details><details><summary>Hint 3</summary>Pattern-based construction: alternate between odd and even numbers with specific spacing to ensure adjacent elements differ by at least 2.</details> |
| 2422 | [Multiplication Table](https://cses.fi/problemset/task/2422) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-2422-Multiplication-Table.cpp) | <details><summary>Hint 1</summary>You need to find the $\frac{n \times n}{2}$-th smallest number in the multiplication table.</details><details><summary>Hint 2</summary>Consider the reverse problem: given value $x$, what is its position when elements are sorted?</details><details><summary>Hint 3</summary>Binary search on the answer. For each candidate $x$, count elements $\leq x$ using $\sum_{i=1}^{n} \min(n, \lfloor x/i \rfloor)$.</details> |
| 3151 | [Bubble Sort Rounds I](https://cses.fi/problemset/task/3151) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-3151-Bubble-Sort-Rounds-I.cpp) | <details><summary>Hint 1</summary>Find the initial and sorted position of each element.</details><details><summary>Hint 2</summary>If an element is not in its correct position, how many rounds until it reaches there?</details><details><summary>Hint 3</summary>In one round, each element can move left at most once. For each element, compute how far left it needs to move.</details><details><summary>Hint 4</summary>The answer is the maximum distance any element needs to move left.</details> |
| 3152 | [Bubble Sort Rounds II](https://cses.fi/problemset/task/3152) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-3152-Bubble-Sort-Rounds-II.cpp) | <details><summary>Hint 1</summary>In one round, each element can move left at most once if not in the correct position.</details><details><summary>Hint 2</summary>Consider the first $k$ largest elements. Which element should be placed first?</details><details><summary>Hint 3</summary>Process elements in decreasing order. Use policy-based data structures to count elements and place each optimally.</details> |
| 3306 | [Nearest Campsites I](https://cses.fi/problemset/task/3306) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-3306-Nearest-Campsites-I.cpp) | <details><summary>Hint 1</summary>Do you know the relationship between Manhattan distance and Chebyshev distance?</details><details><summary>Hint 2</summary>To find the nearest campsite in Chebyshev distance, consider 4 cases based on the signs of $dx$ and $dy$.</details><details><summary>Hint 3</summary>Use coordinate transformation and sweep line with segment tree. The answer is the maximum nearest distance.</details> |
| 3307 | [Nearest Campsites II](https://cses.fi/problemset/task/3307) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-3307-Nearest-Campsites-II.cpp) | <details><summary>Hint 1</summary>Do you know the relationship between Manhattan distance and Chebyshev distance?</details><details><summary>Hint 2</summary>To find the nearest campsite in Chebyshev distance, consider 4 cases based on the signs of $dx$ and $dy$.</details><details><summary>Hint 3</summary>Use coordinate transformation and sweep from both directions. Output individual distances instead of the maximum.</details> |
| 1142 | [Advertisement](https://cses.fi/problemset/task/1142) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-1142-Advertisemen.cpp) | <details><summary>Hint 1</summary>Classic maximum rectangle in histogram problem.</details><details><summary>Hint 2</summary>For each bar, find the nearest smaller bar on the left and right.</details><details><summary>Hint 3</summary>Use a monotonic stack to find these boundaries in $O(n)$ time.</details> |
| 2186 | [Special Substrings](https://cses.fi/problemset/task/2186) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-2186-Special-Substrings.cpp) | <details><summary>Hint 1</summary>Track the frequency array for each prefix.</details><details><summary>Hint 2</summary>Normalize frequencies by subtracting the minimum frequency from all frequencies.</details><details><summary>Hint 3</summary>Two prefixes form a valid substring if they have the same normalized state and all distinct characters have appeared.</details> |
| 3169 | [Counting LCM Arrays](https://cses.fi/problemset/task/3169) | [Code](https://github.com/fahimcp495/CP-Problem-Solutions/blob/main/Judge-Wise/CSES/Additional-Problems-I/CSES-3169-Counting-LCM-Arrays.cpp) | <details><summary>Hint 1</summary>Prime factorize $k = p_1^{e_1} \times p_2^{e_2} \times \ldots \times p_m^{e_m}$.</details><details><summary>Hint 2</summary>Are the prime powers independent or dependent for counting?</details><details><summary>Hint 3</summary>Count valid arrays for each prime power using DP (transition:

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
- **Disjoint Set Union**: Component tracking

</details>

<details>
<summary><b>Algorithms (Click to expand)</b></summary>

- **Greedy**: Optimal local choices
- **Dynamic Programming**: State-based optimization
- **Binary Search**: On answer, parametric search
- **Two Pointers**: Linear scanning technique
- **Graph Algorithms**: BFS, DFS, Dijkstra
- **Sorting**: Custom comparators, merge sort

</details>

<details>
<summary><b>Advanced Techniques (Click to expand)</b></summary>

- **Sliding Window**: Subarray problems
- **Prefix Sums**: Range sum queries
- **Bitmask DP**: Subset enumeration
- **State Space Search**: BFS on configurations
- **Binary Lifting**: Fast ancestor queries
- **Coordinate Compression**: Discrete optimization
- **Matrix Exponentiation**: Fast computation
- **Difference Constraints**: System of inequalities

</details>

<details>
<summary><b>Mathematics (Click to expand)</b></summary>

- **Digit DP**: Counting by digit position
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