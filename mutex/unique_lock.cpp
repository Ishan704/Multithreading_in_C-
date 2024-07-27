#include<iostream>
#include<mutex>
#include<thread>
using namespace std;
int buffer=0;
mutex m;
void unique_lock_mechanism(const char *ptr ,int point)
{
    unique_lock<mutex>lock(m);
    for(int i=0;i<point;i++)
    {
        buffer++;
        cout<<ptr<<" "<<buffer<<"\n";

    }
    
}
int main()
{
thread t1(unique_lock_mechanism,"Ishan",1000000);
thread t2(unique_lock_mechanism,"Ayush",1000000);
t1.join();
t2.join();
cout<<"Final value of buffer"<<buffer;
}