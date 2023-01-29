#include <iostream>
#include <fstream>
#include "Train.h"
using namespace std;

Train::Train() {}
Train::~Train() {}
Train::Train(const Train& theOther) {
    ticketPrice = theOther.ticketPrice;

    stations.clear();
    for (int i = 0; i < theOther.stations.size(); i++)
        stations.push_back(theOther.stations[i]);

    timeList.clear();
    for (int i = 0; i < theOther.timeList.size(); i++)
        timeList.push_back(theOther.timeList[i]);

    color = theOther.color;
}

Train::Train(int _ticketPrice, vector<string> _stations, vector<string> _timeList, string _color) :
    Transport(_ticketPrice, _stations, _timeList), color(_color) {};

string Train::transportToString() {
    string s =
        "COLOR:            " + color + "\n" +
        "TICKET PRICE:     " + to_string(ticketPrice) + " Ft\n";

    for (int i = 0; i < stations.size(); i++)
        s.append("STATION:  " + timeList[i] + "     " + stations[i] + "\n");

    return s;
}

void addTrain(fstream& _file, vector<Train*>& _listOfTrain) {
    string new_color;
    int new_ticketPrice;
    vector<string> new_stations, new_timeList;

    cout << "Enter a transport information:\nTicket Price:  ";
    cin >> new_ticketPrice;
    cin.ignore();

    cout << "Enter a color of a train:  ";
    getline(cin, new_color);  

    cout << "List of stations separated by \" \" :  ";
    string sStations;
    getline(cin, sStations);
    splitStringToVector(sStations, new_stations);

    try {
        cout << "List of times in every station separated by \" \" :  ";
        string sTimeList;
        getline(cin, sTimeList);
        splitStringToVector(sTimeList, new_timeList);

        for (int i = 0; i < new_timeList.size(); i++) {
            Time time = stringToTime(new_timeList[i]);

            if (time.hour > 23 || time.minute > 59)
                throw time;
        }
    }
    catch (Time time) {
        cout << "\nInvalid time: " << time.hour << ":" << time.minute << endl;
        return;
    }

    _listOfTrain.push_back(new Train(new_ticketPrice, new_stations, new_timeList, new_color));


    _file.open("transport.txt", ios::app);
    if (_file)
        _file << _listOfTrain[_listOfTrain.size() - 1]->transportToString() << endl;

    _file.close();
}

void sameNameTrains(string _station, vector<Train*>& _listOfTrains) {
    for (int i = 0; i < _listOfTrains.size(); i++) {
        for (int j = 0; j < _listOfTrains[i]->get_stations().size(); j++) {
            if (_listOfTrains[i]->get_stations()[j] == _station) {
                cout << _listOfTrains[i]->get_timeList()[j] << "   " <<
                    _listOfTrains[i]->get_color() << "    " << endl;
            }
           // else
              //  cout << "No matching!\n";
        }
    }
}

void timeBetweenDestinationsTrain(string _color, vector<Train*>& _listOfTrains) {
    for (int i = 0; i < _listOfTrains.size(); i++) {
        if (_listOfTrains[i]->get_color() == _color) {
            timeDifference(stringToTime(_listOfTrains[i]->get_timeList()[_listOfTrains[i]->get_timeList().size() - 1]),
                stringToTime(_listOfTrains[i]->get_timeList()[0]));
        }
    }
}