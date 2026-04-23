# DP Algorithm (Minimum Subset Sum Difference)

## Idea
Split the array into two subsets such that their sum difference is minimized.

We try to find a subset whose sum is as close as possible to half of the total sum.

---

## Steps

1. Compute total sum `S`

2. Set:
```
target = S / 2
```

3. Create a DP array `dp` of size `target + 1`

- `dp[j] = true` → subset with sum `j` is achievable

4. Initialize:
```
dp[0] = true
```

5. For each element `num` in array:

- Traverse `j` from `target` down to `num`
- Update:
```
dp[j] = dp[j] OR dp[j - num]
```

6. Find the largest `s1 ≤ target` such that:
```
dp[s1] == true
```

7. Compute final answer:
```
Answer = S - 2 * s1
```

---

## Pseudocode

```
function minDifference(arr):
    S = sum(arr)
    target = S / 2

    dp = array of size (target + 1) filled with false
    dp[0] = true

    for num in arr:
        for j from target down to num:
            dp[j] = dp[j] OR dp[j - num]

    for s1 from target down to 0:
        if dp[s1] == true:
            return S - 2 * s1
```

---

## Complexity

- Time Complexity: `O(n * S)`
- Space Complexity: `O(S)`

---

## Key Insight

We are not directly finding two subsets.

Instead:
- Find one subset with sum closest to `S/2`
- The other subset automatically gets the remaining sum

```
Difference = |S1 - S2|
           = S - 2 * S1
```