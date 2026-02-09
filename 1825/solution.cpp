#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

class WordGraph {
    vector<int> adj[26];
    int inDegree[26] = { 0 };
    int outDegree[26] = { 0 };
    bool present[26] = { false };

public:
    void addWord(const string& w) {
        int u = w.front() - 'a';
        int v = w.back() - 'a';

        adj[u].push_back(v);
        outDegree[u]++;
        inDegree[v]++;

        present[u] = present[v] = true;
    }

    void dfs(int u, vector<bool>& visited) {
        visited[u] = true;

        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(v, visited);
            }
        }
    }

    bool canFormCircle() {
        for(int i = 0; i < 26; i++) {
            if(inDegree[i] != outDegree[i]) return false;
        }

        int startNode = -1;
        for(int i = 0; i < 26; i++) {
            if(outDegree[i] > 0) {
                startNode = i;
                break;
            }
        }

        if(startNode == -1) return true;

        vector<bool> visited(26, false);
        dfs(startNode, visited);

        for(int i = 0; i < 26; i++) {
            if(present[i] && !visited[i]) return false;
        }

        return true;
    }
};

int main() {
    vector<string> words = {"chair", "height", "racket", "touch", "tunic"};
    WordGraph graph;

    for (const string& w : words) {
        graph.addWord(w);
    }

    if (graph.canFormCircle()) {
        cout << "Sim, as palavras podem formar um circulo!" << endl;
    } else {
        cout << "Nao, as palavras nao podem formar um circulo!" << endl;
    }

    return 0;
}