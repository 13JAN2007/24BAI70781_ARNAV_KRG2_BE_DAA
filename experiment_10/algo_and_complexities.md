# Distinct Subsequences

## Problem
Given two strings `s` and `t`, return the number of distinct subsequences of `s` which equals `t`.

---

## Approach: Dynamic Programming

### Idea
We define:

```
dp[i][j] = number of ways to form first j characters of t using first i characters of s
```

---

## Transition

- If characters match:

```
dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
```

- If characters do not match:

```
dp[i][j] = dp[i-1][j]
```

---

## Base Cases

```
dp[i][0] = 1
```
(Empty string `t` can always be formed)

```
dp[0][j] = 0
```
(Non-empty `t` cannot be formed from empty `s`)

---

## Optimized Space (1D DP)

Instead of a 2D table, we use a 1D array:

- Traverse `s` forward
- Traverse `t` backward

---

## Code (Python)

```python
def numDistinct(s: str, t: str) -> int:
    m, n = len(s), len(t)
    
    dp = [0] * (n + 1)
    dp[0] = 1
    
    for i in range(1, m + 1):
        for j in range(n, 0, -1):
            if s[i - 1] == t[j - 1]:
                dp[j] += dp[j - 1]
    
    return dp[n]
```

---

## Key Points

- We count subsequences, not generate them.
- Backward iteration is necessary to avoid overwriting values.
- Time Complexity: `O(m * n)`
- Space Complexity: `O(n)`