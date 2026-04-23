# Minimum Subset Sum Difference - Dry Run

## Problem
Given an array `arr`, divide it into two subsets such that the absolute difference of their sums is minimized.

---

## Approach
- Total sum = `S`
- Target = `S / 2`
- Use DP to find the closest subset sum to `S/2`
- Final answer = `S - 2 * s1`

---

## Example

### Input
```
arr = [1, 6, 11, 5]
```

---

## Step 1: Compute Total Sum
```
S = 1 + 6 + 11 + 5 = 23
target = S / 2 = 11
```

---

## Step 2: Initialize DP Array

```
dp[0...11] = [true, false, false, false, false, false, false, false, false, false, false, false]
```

- `dp[j] = true` means subset with sum `j` is possible
- `dp[0] = true` (empty subset)

---

## Step 3: Process Each Element

### 🔹 Processing `1`

```
dp[1] = dp[1] OR dp[0] → true
```

```
dp = [T, T, F, F, F, F, F, F, F, F, F, F]
```

---

### 🔹 Processing `6`

```
dp[6] = dp[6] OR dp[0] → true
dp[7] = dp[7] OR dp[1] → true
```

```
dp = [T, T, F, F, F, F, T, T, F, F, F, F]
```

---

### 🔹 Processing `11`

```
dp[11] = dp[11] OR dp[0] → true
```

```
dp = [T, T, F, F, F, F, T, T, F, F, F, T]
```

---

### 🔹 Processing `5`

```
dp[5] = dp[5] OR dp[0] → true
dp[6] = dp[6] OR dp[1] → true
dp[7] = dp[7] OR dp[2] → true
dp[10] = dp[10] OR dp[5] → true
dp[11] = dp[11] OR dp[6] → true
```

Final DP:

```
dp = [T, T, F, F, F, T, T, T, F, F, T, T]
```

---

## Step 4: Find Closest Sum to Target

Start from `target = 11` and move backward:

```
dp[11] = true → s1 = 11
```

---

## Step 5: Compute Result

```
Result = S - 2 * s1
       = 23 - 2 * 11
       = 1
```

---

## Final Output
```
Minimum Difference = 1
```

---

## Key Insight

We try to split the array into two subsets such that:

```
subset1 ≈ subset2
```

So we aim for:

```
subset1 ≈ S / 2
```

---

## Time & Space Complexity

- Time: `O(n * S)`
- Space: `O(S)`

---

## Summary

- Use subset sum DP
- Find closest sum ≤ `S/2`
- Compute difference using formula

```
Answer = S - 2 * s1
```