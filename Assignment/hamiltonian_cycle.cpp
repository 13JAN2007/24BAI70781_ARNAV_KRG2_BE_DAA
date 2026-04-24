#include <bits/stdc++.h>
using namespace std;

int numVertices;

bool canPlaceVertex(int vertex, vector<vector<int>> &adjMatrix, vector<int> &cyclePath, int position) {
    if (adjMatrix[cyclePath[position - 1]][vertex] == 0)
        return false;

    for (int i = 0; i < position; i++)
        if (cyclePath[i] == vertex)
            return false;

    return true;
}

bool solveHamiltonian(vector<vector<int>> &adjMatrix, vector<int> &cyclePath, int position) {
    if (position == numVertices) {
        return adjMatrix[cyclePath[position - 1]][cyclePath[0]] == 1;
    }

    for (int vertex = 1; vertex < numVertices; vertex++) {
        if (canPlaceVertex(vertex, adjMatrix, cyclePath, position)) {
            cyclePath[position] = vertex;

            if (solveHamiltonian(adjMatrix, cyclePath, position + 1))
                return true;

            cyclePath[position] = -1;
        }
    }

    return false;
}

bool findHamiltonianCycle(vector<vector<int>> &adjMatrix) {
    vector<int> cyclePath(numVertices, -1);

    cyclePath[0] = 0;

    if (!solveHamiltonian(adjMatrix, cyclePath, 1)) {
        return false;
    }

    cout << "\nHamiltonian Cycle Exists:\n";
    for (int i = 0; i < numVertices; i++)
        cout << cyclePath[i] << " -> ";
    cout << cyclePath[0] << "\n";

    return true;
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> numVertices;

    vector<vector<int>> adjMatrix(numVertices, vector<int>(numVertices));

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < numVertices; i++)
        for (int j = 0; j < numVertices; j++)
            cin >> adjMatrix[i][j];

    if (!findHamiltonianCycle(adjMatrix)) {
        cout << "\nNo Hamiltonian Cycle Found\n";
    }

    return 0;
}