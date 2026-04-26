// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    cout<<"enter n";
    int n;
    cin>>n;
    int AT[n],BT[n],CT[n],WT[n],RT[n],PID[n],TAT[n];
    for(int i=0;i<n;i++){
        PID[i]=i+1;
         cout<<"enter at";
        cin>>AT[i];
         cout<<"enter bt";
         cin>>BT[i];
         RT[i]=BT[i];
    }
    int tq;
    cout<<"enter tq";
    cin>>tq;
    int completed=0;int time=0;
    bool done;
    while(completed<n){
        done =true;
        for(int i=0;i<n;i++){
            if(AT[i]<=time  &&  RT[i]>0 ){
                done=false;
                if(RT[i]>tq){
                    RT[i]-=tq;
                    time+=tq;
            }else{
                time+=RT[i];
                RT[i]=0;
                CT[i]=time;
                TAT[i]=CT[i]-AT[i];
                WT[i]=TAT[i]-BT[i];
                completed++;
            }
            
        }
        }
        if(done){
            time++;
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
