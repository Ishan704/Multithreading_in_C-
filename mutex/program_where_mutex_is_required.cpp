#include<iostream>
#include<thread>
using namespace std;
int output=0;
void function1()
{
    for(int i=1;i<=100000;i++)
    output=output+1;
}
int main()
{
    thread t1(function1);
    thread t2(function1);
    t1.join();
    t2.join();
    cout<<"The output is ="<<output;
}