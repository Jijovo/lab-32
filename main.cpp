//Ezzat Mohamadein | ComSc 210 | Lab 32
#include <iostream>
#include <deque>
#include "Car.h"
using namespace std;

//print queue function prototype
void printQueue(std::deque<Car> q);

int main() {
    //define queue of cars and populate with 2 cars
    const int START = 2;
    deque<Car> carQueue;
    for (int i = 0; i < START; i++) {
        carQueue.push_back(Car());
    }

    //print queue for testing
    cout << "Initial queue:" << endl;
    printQueue(carQueue);

    return 0;
}

//print queue function definition
void printQueue(std::deque<Car> q) {
    for (Car c : q) {
        c.print();
    }
}