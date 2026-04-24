# Dry Run: Distinct Subsequences

## Example
**Input:**
```
s = "babgbag"
t = "bag"
```

**Output:**
```
5
```

---

## Step 1: Initialize DP

- Length of `t` = 3 → `dp` size = 4

```
Initial:
dp = [1, 0, 0, 0]
```

### Index Meaning:
- `dp[0]` → ""
- `dp[1]` → "b"
- `dp[2]` → "ba"
- `dp[3]` → "bag"

---

## Step 2: Process Each Character in `s`

### i = 1 → s[0] = 'b'
- j = 3 → no match
- j = 2 → no match
- j = 1 → match ('b')

```
dp[1] += dp[0] → 1
dp = [1, 1, 0, 0]
```

---

### i = 2 → s[1] = 'a'
- j = 3 → no match
- j = 2 → match ('a')

```
dp[2] += dp[1] → 1
```

- j = 1 → no match

```
dp = [1, 1, 1, 0]
```

---

### i = 3 → s[2] = 'b'
- j = 3 → no match
- j = 2 → no match
- j = 1 → match

```
dp[1] += dp[0] → 2
dp = [1, 2, 1, 0]
```

---

### i = 4 → s[3] = 'g'
- j = 3 → match

```
dp[3] += dp[2] → 1
```

- j = 2 → no match  
- j = 1 → no match  

```
dp = [1, 2, 1, 1]
```

---

### i = 5 → s[4] = 'b'
- j = 3 → no match  
- j = 2 → no match  
- j = 1 → match  

```
dp[1] += dp[0] → 3
dp = [1, 3, 1, 1]
```

---

### i = 6 → s[5] = 'a'
- j = 3 → no match  
- j = 2 → match  

```
dp[2] += dp[1] → 4
```

- j = 1 → no match  

```
dp = [1, 3, 4, 1]
```

---

### i = 7 → s[6] = 'g'
- j = 3 → match  

```
dp[3] += dp[2] → 5
```

- j = 2 → no match  
- j = 1 → no match  

```
dp = [1, 3, 4, 5]
```

---

## Final Answer

```
dp[3] = 5
```

---

## Key Observation

- Each match adds new subsequences using previous results.
- We accumulate counts instead of generating subsequences.
- Backward iteration prevents overwriting values.