#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int AT[100], BT[100], RT[100], CT[100], TAT[100], WT[100], PID[100];


    for(int i = 0; i < n; i++) {
        PID[i] = i + 1;

        cout << "Enter AT for P" << PID[i] << ": ";
        cin >> AT[i];

        cout << "Enter BT for P" << PID[i] << ": ";
        cin >> BT[i];

        RT[i] = BT[i]; // remaining time
    }

    int completed = 0, time = 0;


    while(completed < n) {
        int idx = -1;
        int minRT = 1e9;
        for(int i = 0; i < n; i++) {
            if(AT[i] <= time && RT[i] > 0 && RT[i] < minRT) {
                minRT = RT[i];
                idx = i;
            }
        }

        if(idx == -1) {
            time++; // CPU idle
        } else {
            RT[idx]--;  // run for 1 unit
            time++;

            // if process finished
            if(RT[idx] == 0) {
                CT[idx] = time;
                TAT[idx] = CT[idx] - AT[idx];
                WT[idx] = TAT[idx] - BT[idx];
                completed++;
            }
        }
    }

    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";

    for(int i = 0; i < n; i++) {
        cout << "P" << PID[i] << "\t"
             << AT[i] << "\t"
             << BT[i] << "\t"
             << CT[i] << "\t"
             << TAT[i] << "\t"
             << WT[i] << endl;
    }

    return 0;
}
