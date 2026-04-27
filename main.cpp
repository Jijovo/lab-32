//Ezzat Mohamadein | ComSc 210 | Lab 33
#include <iostream>
#include <deque>
#include <array>
#include "Car.h"
using namespace std;

//print queue function prototype
void printQueue(std::deque<Car> q);
//print queue function prototype for array of queues
void printQueues(array<deque<Car>, 4> q);
//define constants
const int START = 2;
const int PAY = 46;
const int JOIN = 39;
const int SHIFT = 15;
const int PERIODS = 20;

int main() {
    //randomise seed for random number generation using current time
    srand(time(0));
    //define array containing 4 queues of cars and populate with 2 cars each
    array<deque<Car>, 4> carQueues;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < START; j++) {
            carQueues[i].push_back(Car());
        }
    }

    //print queue for testing
    cout << "Initial queues:" << endl;
    printQueues(carQueues);

    //loop that runs until 20 time periods have passed
    int t = 1;
    while (t <= PERIODS) {
        cout << "Time period " << t << ":" << endl;
        //determine operations (1 per lane per time period) and carry them out
        for (int i = 0; i < carQueues.size(); i++) {
            int operation = rand() % 100 + 1; //random number between 1 and 100
            cout << "Lane " << i + 1 << ": ";
            if (operation <= 50) { //paying operation
                if (!carQueues[i].empty()) {
                    cout << "Car paid: ";
                    carQueues[i].front().print(); //print first car in lane
                    carQueues[i].pop_front(); //remove first car in lane
                }
            }
            else { //joining operation
                cout << "Car joined: ";
                Car newCar; //create new car object
                newCar.print(); //print new car
                carQueues[i].push_back(newCar); //add new car to back of lane
            }
        
        }
        //print queues after each time period
        printQueues(carQueues);
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
//print queue function definition for array of queues
void printQueues(array<deque<Car>, 4> q) {
    for (int i = 0; i < q.size(); i++) {
        cout << "Lane " << i + 1 << ":" << endl;
        printQueue(q[i]);
        cout << endl;
    }
}