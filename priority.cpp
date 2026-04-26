// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    cout<<"enter n";
    int n;
    cin>>n;
    int AT[n],BT[n],CT[n],WT[n],RT[n],PID[n],TAT[n],PQ[n];
    for(int i=0;i<n;i++){
        PID[i]=i+1;
         cout<<"enter at";
        cin>>AT[i];
         cout<<"enter bt";
         cin>>BT[i];
         cout<<"enter priority";
         cin>>PQ[i];
         RT[i]=BT[i];
    }
    int completed=0;int time=0;
    while(completed<n){
        int idx=-1;
        int maxp=1e9;
        for(int i=0;i<n;i++){
            if(AT[i]<=time  &&  RT[i]>0 && maxp>PQ[i]){
                idx=i;
                maxp=PQ[i];
            }
        }
        if(idx==-1){
            time++;
        }else{
            RT[idx]--;
            time++;
            if(RT[idx]==0){
                CT[idx]=time;
                TAT[idx]=CT[idx]-AT[idx];
                WT[idx]=TAT[idx]-BT[idx];
                completed++;
            }
        }
        
        
    }
      cout << "\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n";

    for(int i = 0; i < n; i++) {
        cout << "P" << PID[i] << "\t"
             << AT[i] << "\t"
             << BT[i] << "\t"
             << PQ[i] << "\t"
             << CT[i] << "\t"
             << TAT[i] << "\t"
             << WT[i] << endl;
    }


    return 0;
}
