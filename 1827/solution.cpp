#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class EggDroppingSolver {
private:
    vector<vector<int>> memo;

    int solveRecursive(int n, int k) {
        if (k == 0 || k == 1) return k;
        if (n == 1) return k;

        if (memo[n][k] != -1) return memo[n][k];

        int min_drops = 1e9;

        for (int x = 1; x <= k; x++) {
            int worst_case = 1 + max(solveRecursive(n - 1, x - 1), solveRecursive(n, k - x));

            min_drops = min(min_drops, worst_case);
        }

        return memo[n][k] = min_drops;
    }

public:
    int findMinDrops(int eggs, int floors) {
        memo.assign(eggs + 1, vector<int>(floors + 1, -1));

        return solveRecursive(eggs, floors);
    }
};

int main() {
    EggDroppingSolver solver;

    int eggs = 1;
    int floors = 5;

    int result = solver.findMinDrops(eggs, floors);

    cout << "-- Resultado do Desafio --" << endl;
    cout << "Ovos: " << eggs << " | Andares: " << floors << endl;
    cout << "Mínimo de tentativas (pior caso): " << result << endl;
}