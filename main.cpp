#include <iostream>
#include <fstream>
#include "Transport.h"
#include "IntercityTransport.h"
#include "Train.h"
using namespace std;


int main() {
    vector<IntercityTransport*> listOfIntercityTransport;  // stores the intercity transport objects
    vector<Train*> listOfTrains;             // stores train objects

    // Creation of ofstream class object
    fstream file;

    string newStation, type, number, color;

    while (true) {
        printMenu();
        int choice;
        cin >> choice;
        switch (choice) {
        case 1:
            file.open("transport.txt", ios::in);
            if (file) {
                char c;

                while (!file.eof()) {
                    file.get(c);
                    cout << c;
                }

                file.close();
            }
            else if (!file) {
                cout << "File is empty!" << endl;
            }

            break;
        case 2:
            cout << "Which kind of transport: IntercityTransport(1), Trains(2)\n";
            int choice2;
            cin >> choice2;
            switch (choice2) {
            case 1:

                addInterCityTransport(file, listOfIntercityTransport);

                break;
            case 2:
                addTrain(file, listOfTrains);

                break;
            }

            break;
        case 3:
            cout << "Which kind of transport: IntercityTransport(1), Trains(2)\n";
            int choice3;
            cin >> choice3;

            switch (choice3) {
            case 1:
                cout << "Enter a type of Intercity Transport:  ";
                cin >> type;
                cout << "Enter a number of Intercity Transport: ";
                cin >> number;

                timeBetweenDestinationsIntercity(type, number, listOfIntercityTransport);
                break;

            case 2:
                cout << "Enter a color of the train:  ";
                cin >> color;

                timeBetweenDestinationsTrain(color, listOfTrains);
                break;
            }
            break;

        case 4:
            cout << "Enter a station name:  ";
            cin >> newStation;
            sameNameIntercityTransport(newStation, listOfIntercityTransport);
            sameNameTrains(newStation, listOfTrains);

            break;
        case 5:
            for (int i = 0; i < listOfIntercityTransport.size(); i++) {    //memory release
                delete listOfIntercityTransport[i];
            }
            for (int i = 0; i < listOfTrains.size(); i++) {
                delete listOfTrains[i];
            }
            return 0;
        }
    }
}