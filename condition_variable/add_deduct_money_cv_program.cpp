#include<iostream>
#include<mutex>
#include<thread>
#include<condition_variable>
using namespace std;
mutex m;
condition_variable cv;
int balance=0;
void add_money(int money)
{
    lock_guard<mutex>l1(m);
    balance+=money;
    cout<<"Amount add and current balance is="<<balance<<"\n";
    cv.notify_all();

}
void deduct_money(int money)
{
 unique_lock<mutex>l2(m);
 //cv.wait(l2  [] { return (balance!=0) ?  true:false;});
  cv.wait(l2, []{ return (balance!=0) ?  true:false; });
 if(balance>=0)
 {
    balance-=money;
    cout<<"Amount deducted and balance is ="<<balance;
 }
 
}
int main()
{
    thread t1(add_money,500);
    thread t2(deduct_money,500);
    t1.join();
    t2.join();
}