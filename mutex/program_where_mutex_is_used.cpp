#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
int shared_variable=0;
mutex obj_mutex;
void function1()
{
    
for(int i=1;i<=100000;i++)
{
obj_mutex.lock();
shared_variable=shared_variable+1;
obj_mutex.unlock();
}
}
int main()
{
    thread t1(function1);
    thread t2(function1);
    t1.join();
    t2.join();
     cout<<"The output is ="<<shared_variable;

}