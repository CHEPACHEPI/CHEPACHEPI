#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter number of resources: ";
    cin >> m;

    int alloc[10][10], max[10][10], need[10][10], avail[10];


    cout << "\nEnter Allocation Matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> alloc[i][j];

    cout << "\nEnter Max Matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> max[i][j];


    cout << "\nEnter Available Resources:\n";
    for(int j = 0; j < m; j++)
        cin >> avail[j];

    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    bool finish[10] = {false};
    int safe[10], k = 0;


    for(int count = 0; count < n; count++) {
        for(int i = 0; i < n; i++) {

            if(!finish[i]) {
                bool canRun = true;

                for(int j = 0; j < m; j++) {
                    if(need[i][j] > avail[j]) {
                        canRun = false;
                        break;
                    }
                }

                if(canRun) {
              
                    for(int j = 0; j < m; j++)
                        avail[j] += alloc[i][j];

                    safe[k++] = i;
                    finish[i] = true;
                }
            }
        }
    }

 
    if(k == n) {
        cout << "\nSAFE STATE\nSequence: ";
        for(int i = 0; i < n; i++)
            cout << "P" << safe[i] << " ";
    } else {
        cout << "\nNOT SAFE STATE";
    }

    return 0;
}
