// 6_raceCondition_01.cpp
#include <iostream>
#include <thread>
#include <chrono>

int sharedVariable = 0;

void increment() {
    for (int i = 0; i < 100000; ++i) {
        int currentValue = sharedVariable;
           sharedVariable = currentValue + 1;
    }
}

int main() {
    std::thread thread1(increment);
    std::thread thread2(increment);

    thread1.join();
    thread2.join();

    std::cout << "Expected value: 200000" << std::endl;
    std::cout << "Actual value: " << sharedVariable << std::endl;

    return 0;
}