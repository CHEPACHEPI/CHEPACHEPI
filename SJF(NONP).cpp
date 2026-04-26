// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    cout<<"enter n";
    int n;
    cin>>n;
    int AT[n],BT[n],WT[n],CT[n],PID[n],TAT[n];
    bool vis[n]={false};
    for(int i=0;i<n;i++){
        PID[i]=i+1;
        cout<<"AT"<<"\n";
        cin>>AT[i];
         cout<<"BT"<<"\n";
        cin>>BT[i];
    }
    int completed=0;
    int time=0;
    while(completed<n){
        int idx=-1;
        int minBT=1e9;
        for(int i=0;i<n;i++){
            if(!vis[i] && AT[i]<=time && BT[i]<minBT){
                minBT=BT[i];
                idx=i;
            }
        }
        if(idx==-1){
            time++;
        }else{
            CT[idx]=time+BT[idx];
            time=CT[idx];
            TAT[idx]=CT[idx]-AT[idx];
            WT[idx]=TAT[idx]-BT[idx];
             vis[idx] = true;
            completed++;
        }
        
    }
      cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i=0;i<n;i++){
        cout<<PID[i]<<"\t";
         cout<<AT[i]<<"\t";
          cout<<BT[i]<<"\t";
           cout<<CT[i]<<"\t";
            cout<<TAT[i]<<"\t";
             cout<<WT[i]<<endl;
        
        
        
        
    }
    

    return 0;
}
