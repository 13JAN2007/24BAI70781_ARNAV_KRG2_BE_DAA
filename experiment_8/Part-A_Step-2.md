## Step 2: Performance Measurement

### 2.1 Metric Definitions and Measurement Methodology

To empirically evaluate the scalability and efficiency of the implemented algorithms, performance data was collected during execution. The following key metrics were recorded:

**Execution Time:**  
The total wall-clock time required by the algorithm to process the input, measured in milliseconds (ms). This was captured using the high-resolution clock (`std::chrono::high_resolution_clock` in C++), ensuring high precision in measurement.

**Approximate Number of Operations:**  
A counter was incremented at each fundamental operation of the algorithm (e.g., within the `while` loop for Binary Search or at each recursive call in Subset Sum). This provides a hardware-independent estimate to validate theoretical time complexity.

**Feasibility Status:**  
To analyze computational limits and avoid excessive execution time for intractable cases, a strict timeout threshold of **2000.0 ms (2 seconds)** was enforced.

- **Completed:** The algorithm finished execution within the allowed time limit.  
- **Timeout (Infeasible):** The algorithm exceeded the 2000 ms threshold, indicating practical infeasibility for the given input size.

---

### 2.2 Experimental Environment

To ensure consistency and reproducibility, all experiments were conducted under the following conditions:

**Hardware:**  
Ryzen 7 processor, 16 GB RAM  

**Compiler:**  
Standard C++ compiler (GCC) without additional optimization flags.

---

### 2.3 Structured Execution Log

The table below summarizes the experimental results, illustrating the performance of algorithms with different time complexity classes (logarithmic, linear, exponential, and factorial) across varying input sizes.

| Algorithm                     | Complexity Class | Input Size (N) | Operations Count   | Execution Time (ms) | Feasibility Status |
|------------------------------|-----------------|----------------|--------------------|---------------------|--------------------|
| Binary Search                | O(log n)        | 1,000,000      | 20                 | 0.0012              | Completed          |
| Subset Sum (Verification)    | O(n)            | 8              | 8                  | 0.0005              | Completed          |
| Subset Sum (Decision)        | O(2^n)          | 6              | 63                 | 0.0150              | Completed          |
| Subset Sum (Decision)        | O(2^n)          | 45             | > 10,000,000       | > 2000.0000         | Timeout            |
| TSP (Brute Force)            | O(n!)           | 4              | 24                 | 0.0080              | Completed          |
| TSP (Brute Force)            | O(n!)           | 15             | > 15,000,000       | > 2000.0000         | Timeout            |
