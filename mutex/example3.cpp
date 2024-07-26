#include<iostream>
#include<mutex>
#include<list>
#include<algorithm>
#include<thread>
using namespace std;
std::list<int> myList;
mutex mymutex;
void addtolist(int start,int end )
{
    lock_guard<mutex>guard(mymutex);
    for(int i=start;i<end;i++)
    {
        myList.push_back(i);
    }

}
void printlist()
{
 for (auto itr = myList.begin(), end_itr = myList.end(); itr != end_itr; ++itr) {
        cout << *itr << " ";
    }
}
int main()
{
    thread t1(addtolist,1,100);
    thread t2(addtolist,101,200);
    t1.join();
    t2.join();
    thread t3(printlist);
    t3.join();
}