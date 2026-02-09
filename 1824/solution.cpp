#include <iostream>
#include <vector>

using namespace std;

class KnightTourSolver {

private: 
    int N;
    const int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    const int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

   long long solve(int x, int y, int count, vector<vector<bool>>& visited) {
    if(count == N * N) return 1;

    long long totalTours = 0;

    for(int i = 0; i < 8; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if(nextX >= 0 && nextX < N && nextY >= 0 && nextY < N && !visited[nextX][nextY]) {
            visited[nextX][nextY] = true;
            totalTours += solve(nextX, nextY, count + 1, visited);
            visited[nextX][nextY] = false;
        }
    }

    return totalTours;
   }

public:
    KnightTourSolver(int size) : N(size) {}

    long long countTotalTours() {
        if (N <= 0) return 0;
        if (N == 1) return 1;

        long long total = 0;
        vector<vector<bool>> visited(N, vector<bool>(N, false));

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                visited[i][j] = true;
                total += solve(i, j, 1, visited);
                visited[i][j] = false;
            }
        }

        return total;
    }
};

int main() {
    int n;
    cout << "Digite o tamanho do tabuleiro (N): ";
    cin >> n;

    KnightTourSolver solver(n);
    cout << "Calculando tours para " << n << "x" << n << "...\n";

    long long result = solver.countTotalTours();
    cout << "Total de tours encontrados: " << result << endl;

    return 0;
}