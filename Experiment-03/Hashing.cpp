#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;

    cout << "Enter number of keys: ";
    cin >> n;

    vector<int> keys(n);

    cout << "Enter the keys:\n";
    for(int i = 0; i < n; i++) {
        cin >> keys[i];
    }

    cout << "Enter hash table size: ";
    cin >> m;

    vector<int> hashTable(m, -1);

    cout << "\nHashing using k mod m:\n";
    for(int i = 0; i < n; i++) {
        int index = keys[i] % m;

        cout << keys[i] << " mod " << m << " = " << index << endl;

        while(hashTable[index] != -1) {
            index = (index + 1) % m;
        }

        hashTable[index] = keys[i];
    }

    cout << "\nHash Table:\n";
    for(int i = 0; i < m; i++) {
        if(hashTable[i] != -1)
            cout << "Index " << i << " : " << hashTable[i] << endl;
        else
            cout << "Index " << i << " : Empty" << endl;
    }

    return 0;
}

