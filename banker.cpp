#include <iostream>
using namespace std;

int main() {
    int n = 3;

    int alloc[3] = {1, 2, 3};
    int max[3]   = {3, 3, 3};
    int need[3];

    int available = 2;

    bool fin[3] = {false};

    // Need calculation
    for(int i = 0; i < n; i++) {
        need[i] = max[i] - alloc[i];
        cout << "Need[" << i << "] = " << need[i] << endl;
    }

    // Banker logic
    for(int count = 0; count < n; count++) {
        for(int j = 0; j < n; j++) {

            if(!fin[j] && need[j] <= available) {

                cout << "Process P" << j << " executed\n";

                available += alloc[j];
                fin[j] = true;
            }
        }
    }

    // Check safe
    bool safe = true;
    for(int i = 0; i < n; i++) {
        if(!fin[i]) safe = false;
    }

    if(safe)
        cout << "System is SAFE\n";
    else
        cout << "DEADLOCK\n";

    return 0;
}
