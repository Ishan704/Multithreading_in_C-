#include<iostream>
#include<thread>
#include<atomic>
#include<mutex>
#include<bits/stdc++.h>
using namespace std;

std::atomic<int64_t>sharedVariable_atomic(0);
void functionatomic()
{
    for(int i=0;i<10000000;i++)
    sharedVariable_atomic++;
}
int main()
{

thread t1(functionatomic);
thread t2(functionatomic);
thread t3(functionatomic);
thread t4(functionatomic);
t1.join();
t2.join();
t3.join();
t4.join();
cout<<"Value of sharedatomic int is ="<<sharedVariable_atomic;
}