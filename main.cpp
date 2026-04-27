//Ezzat Mohamadein | ComSc 210 | Lab 33
#include <iostream>
#include <deque>
#include "Car.h"
using namespace std;

//print queue function prototype
void printQueue(std::deque<Car> q);
//define constants
const int START = 2;
const int PAY = 46;
const int JOIN = 39;
const int SHIFT = 15;

int main() {
    //randomise seed for random number generation using current time
    srand(time(0));
    //define queue of cars and populate with 2 cars
    deque<Car> carQueue;
    for (int i = 0; i < START; i++) {
        carQueue.push_back(Car());
    }

    //print queue for testing
    cout << "Initial queue:" << endl;
    printQueue(carQueue);

    //while loop that runs until queue is empty
    int t = 1;
    while (!carQueue.empty()) {
        //print current time period
        cout << endl << "Time:" << t << endl;
        //55% chance of first car in the queue leaving, 45% chance of a new car arriving at the back
        if (rand() % 100 < 55) {
            cout << "Car paid: ";
            carQueue.front().print();
            carQueue.pop_front();
        }
        else {
            carQueue.push_back(Car());
            cout << "New car arrived: ";
            carQueue.back().print();
        }
        //print current queue
        cout << "Current queue:" << endl;
        printQueue(carQueue);
        //increment time period
        t++;
            
    }

    return 0;
}

//print queue function definition
void printQueue(std::deque<Car> q) {
    for (Car c : q) {
        c.print();
    }
    if (q.empty()) {
        cout << "[Empty]" << endl;
    }
}