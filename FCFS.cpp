// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    cout<<"enter n";
    int n;
    cin>>n;
    int AT[n],BT[n],TAT[n],WT[n],PID[n],CT[n];
    for(int i=0;i<n;i++){
        PID[i]=i+1;
        cout<<"enter AT";
        cin>>AT[i];
        cout<<"enter bt";
        cin>>BT[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(AT[j]>AT[j+1]){
                swap(AT[j],AT[j+1]);
                 swap(BT[j],BT[j+1]);
                  swap(PID[j],PID[j+1]);
            }
        }
    }
    CT[0]=AT[0]+BT[0];
    for(int i=1;i<n;i++){
        if(AT[i]<CT[i-1]){
            CT[i]=CT[i-1]+BT[i];
        }else{
            CT[i]=AT[i]+BT[i];
        }
    }
     for(int i=0;i<n;i++){
      
            TAT[i]=CT[i]-AT[i];
       
            WT[i]=TAT[i]-BT[i];

    }
    cout<<"PID\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i=0;i<n;i++){
        cout<<PID[i]<<"\t";
         cout<<AT[i]<<"\t";
          cout<<BT[i]<<"\t";
           cout<<CT[i]<<"\t";
            cout<<TAT[i]<<"\t";
             cout<<WT[i]<<"\n";
    }
    
    
    
    
    return 0;
}
