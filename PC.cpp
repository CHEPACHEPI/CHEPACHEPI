#include <thread>
#include <unistd.h>
#include <mutex>

#include <iostream>
using namespace std;
int buffer=0;
mutex mtx;
void producer(){
    for(int i=0;i<5;i++){
        mtx.lock();
        buffer++;
        cout<<"produced:"<<buffer<<endl;
         usleep(1000);
        mtx.unlock();
    }
}
void consumer(){
    for(int i=0;i<5;i++){
        mtx.lock();
        buffer--;
        cout<<"consumed:"<<buffer<<endl;
        usleep(1000);
        mtx.unlock();
    }
}

int main() {
   thread t1(producer);
   thread t2(consumer);
   t1.join();
   t2.join();
  

    return 0;
}
