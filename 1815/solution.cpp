#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>

using namespace std;

vector<int> generateGrayCode(int n) {
    int size = 1 << n;
    vector<int> result;

    for (int i = 0; i < size; i++) {
        result.push_back(i ^ (i >> 1));
    }

    return result;
}

void printBinary(int num, int n) {
    string s = bitset<16>(num).to_string();
    cout << s.substr(16 - n) << " ";
}

int main() {
    int n;
    cout << "Digite o número de bits (n): ";
    cin >> n;

    vector<int> grayCode = generateGrayCode(n);

    cout << "Sequecia de Gray para " << n << " bits:" << endl;

    for (int val : grayCode) {
        printBinary(val, n);
    }

    cout << endl;

    return 0;
}