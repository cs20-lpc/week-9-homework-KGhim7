#include <iostream>
#include <cstdlib>
#include <ctime>
#include "QueueFactory.hpp"
using namespace std;

int main() {
    srand(static_cast<unsigned>(time(0)));

    Queue<int>* ticketLine = QueueFactory<int>::GetQueue(10);

    int turnedAway = 0, enqueued1 = 0, dequeued1 = 0;

    for (int i = 0; i < 100; i++) {
        int r = (rand() % 3) - 1;
        if (r < 0) {
            try {
                ticketLine->dequeue();
                dequeued1++;
            } catch (string&) {
            }
        } else {
            try {
                ticketLine->enqueue(1);
                enqueued1++;
            } catch (string&) {
                turnedAway++;
            }
        }
    }

    cout << "Simulation 1 (Ticket Counter, capacity = 10):\n";
    cout << "  Enqueued: " << enqueued1
         << "  Dequeued: " << dequeued1
         << "  Turned Away: " << turnedAway
         << "  Remaining in line: " << ticketLine->getLength() << endl;

    if (ticketLine->isEmpty())
        cout << "  Line is empty.\n";
    else {
        try {
            cout << "  Front customer: " << ticketLine->front() << endl;
            cout << "  Back customer: "  << ticketLine->back()  << endl;
        } catch (string& e) {
            cout << e << endl;
        }
    }

    delete ticketLine;
    cout << "---------------------------------------------\n\n";

    Queue<int>* bankLine = QueueFactory<int>::GetQueue();

    int enqueued2 = 0, dequeued2 = 0;

    for (int i = 0; i < 100; i++) {
        int r = (rand() % 4) - 1;
        if (r < 0) {
            try {
                bankLine->dequeue();
                dequeued2++;
            } catch (string&) {
            }
        } else {
            bankLine->enqueue(1);
            enqueued2++;
        }
    }

    cout << "Simulation 2 (Bank Service Line, unbounded):\n";
    cout << "  Enqueued: " << enqueued2
         << "  Dequeued: " << dequeued2
         << "  Remaining in line: " << bankLine->getLength() << endl;

    if (bankLine->isEmpty())
        cout << "  Line is empty.\n";
    else {
        try {
            cout << "  Front customer: " << bankLine->front() << endl;
            cout << "  Back customer: "  << bankLine->back()  << endl;
        } catch (string& e) {
            cout << e << endl;
        }
    }

    delete bankLine;
    cout << "\nSimulation complete.\n";
    return 0;
}