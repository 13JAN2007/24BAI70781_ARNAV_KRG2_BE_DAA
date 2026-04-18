#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;
using namespace std::chrono;

const double LIMIT_MS = 2000.0;

struct Data {
    string name;
    double timeMs = 0.0;
    long long count = 0;
    string state = "Completed";
};

int bsFunc(const vector<int>& v, int key, Data& d) {
    auto t1 = high_resolution_clock::now();
    d.name = "Binary Search";
    d.count = 0;
    
    int l = 0;
    int r = v.size() - 1;
    int res = -1;

    while (l <= r) {
        d.count++;
        int m = l + (r - l) / 2;

        if (v[m] == key) {
            res = m;
            break;
        }
        if (v[m] < key) l = m + 1;
        else r = m - 1;
    }

    auto t2 = high_resolution_clock::now();
    d.timeMs = duration<double, milli>(t2 - t1).count();
    return res;
}

bool checkSubset(const vector<int>& v, int tgt, Data& d) {
    auto t1 = high_resolution_clock::now();
    d.name = "Subset Sum (Verification)";
    d.count = 0;
    
    long long sum = 0;
    for (int x : v) {
        d.count++;
        sum += x;
    }

    auto t2 = high_resolution_clock::now();
    d.timeMs = duration<double, milli>(t2 - t1).count();
    return sum == tgt;
}

bool recSubset(const vector<int>& v, int n, int tgt, Data& d, time_point<high_resolution_clock> st) {
    d.count++;
    
    auto now = high_resolution_clock::now();
    if (duration<double, milli>(now - st).count() > LIMIT_MS) {
        d.state = "Timeout";
        return false;
    }

    if (tgt == 0) return true;
    if (n == 0 && tgt != 0) return false;

    if (v[n - 1] > tgt) {
        return recSubset(v, n - 1, tgt, d, st);
    }

    return recSubset(v, n - 1, tgt, d, st) || 
           recSubset(v, n - 1, tgt - v[n - 1], d, st);
}

bool subsetSolve(const vector<int>& v, int tgt, Data& d) {
    auto t1 = high_resolution_clock::now();
    d.name = "Subset Sum (Decision)";
    d.count = 0;
    d.state = "Completed";

    bool ans = recSubset(v, v.size(), tgt, d, t1);

    auto t2 = high_resolution_clock::now();
    d.timeMs = duration<double, milli>(t2 - t1).count();
    return ans;
}

int tspFunc(const vector<vector<int>>& g, Data& d) {
    auto t1 = high_resolution_clock::now();
    d.name = "TSP (Brute Force)";
    d.count = 0;
    d.state = "Completed";

    int n = g.size();
    if (n <= 1) return 0;

    vector<int> nodes;
    for (int i = 1; i < n; i++) nodes.push_back(i);

    int best = INT_MAX;

    do {
        d.count++;
        
        auto now = high_resolution_clock::now();
        if (duration<double, milli>(now - t1).count() > LIMIT_MS) {
            d.state = "Timeout";
            break;
        }

        int cost = 0;
        int cur = 0;
        
        for (int i = 0; i < nodes.size(); i++) {
            cost += g[cur][nodes[i]];
            cur = nodes[i];
        }
        cost += g[cur][0];
        best = min(best, cost);

    } while (next_permutation(nodes.begin(), nodes.end()));

    auto t2 = high_resolution_clock::now();
    d.timeMs = duration<double, milli>(t2 - t1).count();
    return best;
}

void logPrint(const Data& d) {
    cout << left << setw(30) << d.name 
         << setw(15) << d.state 
         << setw(20) << d.count 
         << fixed << setprecision(4) << d.timeMs << " ms" << "\n";
}

int main() {
    cout << string(85, '-') << "\n";
    cout << left << setw(30) << "Algorithm" 
         << setw(15) << "Status" 
         << setw(20) << "Operations Count" 
         << "Execution Time\n";
    cout << string(85, '-') << "\n";

    vector<int> arr(1000000);
    iota(arr.begin(), arr.end(), 1); 
    Data d1;
    bsFunc(arr, 999999, d1);
    logPrint(d1);

    vector<int> sub = {15, 22, 14, 26, 32, 9, 16, 8};
    Data d2;
    checkSubset(sub, 142, d2);
    logPrint(d2);

    vector<int> s1 = {3, 34, 4, 12, 5, 2};
    Data d3;
    subsetSolve(s1, 9, d3);
    logPrint(d3);

    vector<int> s2(45, 10); 
    Data d4;
    subsetSolve(s2, 999, d4);
    logPrint(d4);

    vector<vector<int>> g1 = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    Data d5;
    tspFunc(g1, d5);
    logPrint(d5);

    vector<vector<int>> g2(15, vector<int>(15, 10));
    Data d6;
    tspFunc(g2, d6);
    logPrint(d6);

    cout << string(85, '-') << "\n";
    return 0;
}