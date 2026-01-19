#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

string alphabet = "01";
unordered_set<string> visited_edges;
string result = "";

void findDeBruijn(string node, int k) {
    for (char c : alphabet) {
        string next_edge = node + c;

        if (visited_edges.find(next_edge) == visited_edges.end()) {
            visited_edges.insert(next_edge);

            string next_node = next_edge.substr(1);
            findDeBruijn(next_node, k);

            result += c;
        }
    }
}

string solveDeBruijn(int k, string C) {
    alphabet = C;
    visited_edges.clear();
    result = "";

    string start_node = string(k - 1, alphabet[0]);

    findDeBruijn(start_node, k);

    reverse(result.begin(), result.end());

    return result;
}

int main() {
    int k = 6;
    string C = "01";
    
    string sequence = solveDeBruijn(k, C);

    cout << " Sequência de De Bruijn para k=" << k << ": " << sequence << endl;
    cout << "Tamanho total: " << sequence.length() << " (esperado: n^k + k-1)" << endl;

    return 0;
}