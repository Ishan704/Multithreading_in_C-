#include<iostream>
#include<thread>
using namespace std;
void function1()
{
for(int i=0;i<2000;i++)
cout<<"A";
}
void function2()
{
for(int i=0;i<2000;i++)
cout<<"B";
}
int main()
{
    thread worker1(function1);
    thread worker2(function2);
    worker1.join();
    worker2.join();
}