#include <iostream>
#include <fstream>
#include "IntercityTransport.h"
using namespace std;

IntercityTransport::IntercityTransport() {}
IntercityTransport::IntercityTransport(const IntercityTransport& theOther) {
    ticketPrice = theOther.ticketPrice;

    stations.clear();
    for (int i = 0; i < theOther.stations.size(); i++)
        stations.push_back(theOther.stations[i]);

    timeList.clear();
    for (int i = 0; i < theOther.timeList.size(); i++)
        timeList.push_back(theOther.timeList[i]);

    passValid = theOther.passValid;
    type = theOther.type;
    number = theOther.number;
}

IntercityTransport::~IntercityTransport() {}

IntercityTransport::IntercityTransport(int _ticketPrice, vector<string> _stations, vector<string> _timeList, bool _passValid, string _type, string _number) :
    Transport(_ticketPrice, _stations, _timeList), passValid(_passValid), type(_type), number(_number) {};


string IntercityTransport::transportToString() {
    string s =
        "TYPE:             " + type + "\n" +
        "NUMBER:           " + number + "\n" +
        "TICKET PRICE:     " + to_string(ticketPrice) + " Ft\n";

    for (int i = 0; i < stations.size(); i++) 
        s.append("STATION:  " + timeList[i] + "     " + stations[i] + "\n");

    if (passValid)
        s.append("PASS VALIDATION:  true\n\n");
    else if(!passValid)
        s.append("PASS VALIDATION:  false\n\n");

    return s;
}

void addInterCityTransport(fstream& _file, vector<IntercityTransport*>& _listOfIntercityTransport) {
    string new_type, new_number;
    int new_ticketPrice;
    bool new_passValid;
    vector<string> new_stations, new_timeList;

    cout << "Enter a transport information:\nEnter a type of Intercity Transport:  ";
    cin >> new_type;
    cin.ignore();   // because of mix of cin and getline functions -> buffer problems

    cout << "List of stations separated by \" \" :  ";
    string sStations;
    getline(cin, sStations);
    splitStringToVector(sStations, new_stations);

    cout << "Enter a number of Intercity Transport:  ";
    getline(cin, new_number);

    cout << "Ticket Price:  ";
    cin >> new_ticketPrice;
    cin.ignore();

    try {
        cout << "Is the pass valid for this transport? ";
        string sPassValid;
        getline(cin, sPassValid);

        if (sPassValid == "true")
            new_passValid = true;
        else if (sPassValid == "false")
            new_passValid = false;
        else
            throw sPassValid;
    }
    catch (string sPassValid) {
        cout << "Invalid pass validation: " << sPassValid << "\nMust be true or false!\n";
        return;
    }

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

    _listOfIntercityTransport.push_back(new IntercityTransport(new_ticketPrice, new_stations, new_timeList, new_passValid, new_type, new_number));


    _file.open("transport.txt", ios::app);
    if (_file)
        _file << _listOfIntercityTransport[_listOfIntercityTransport.size() - 1]->transportToString() << endl;

    _file.close();
}

void sameNameIntercityTransport(string _station, vector<IntercityTransport*>& _listOfIntercityTransport) {
    for (int i = 0; i < _listOfIntercityTransport.size(); i++) {
        for (int j = 0; j < _listOfIntercityTransport[i]->get_stations().size(); j++) {
            if (_listOfIntercityTransport[i]->get_stations()[j] == _station) {
                cout << _listOfIntercityTransport[i]->get_timeList()[j] << "   " <<
                    _listOfIntercityTransport[i]->get_type() << "    " << _listOfIntercityTransport[i]->get_number() << endl;
            }
            //else
               // cout << "No matching!\n";
        }
    }
}

void timeBetweenDestinationsIntercity(string _type, string _number, vector<IntercityTransport*>& _listOfIntercityTransport) {
    for (int i = 0; i < _listOfIntercityTransport.size(); i++) {
        if (_listOfIntercityTransport[i]->get_type() == _type && _listOfIntercityTransport[i]->get_number() == _number) {
            timeDifference(stringToTime(_listOfIntercityTransport[i]->get_timeList()[_listOfIntercityTransport[i]->get_timeList().size() - 1]),
                stringToTime(_listOfIntercityTransport[i]->get_timeList()[0]));
        }
    }
}