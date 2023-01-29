#include <iostream>
#include <vector>   
#include <string>
#include <sstream>
#include "Transport.h"
using namespace std;


Time stringToTime(string _sTime) {
    string s_hour;
    for (int i = 0; i < 2; i++)
        s_hour += _sTime[i];

    string s_minute;
    for (int i = 3; i < 5; i++)
        s_minute += _sTime[i];

    Time _time;
    _time.hour = stoi(s_hour);
    _time.minute = stoi(s_minute);
    return _time;
}

void timeDifference(Time _t1, Time _t2) {
    Time diff;
    if (_t2.minute > _t1.minute)
    {
        --_t1.hour;
        _t1.minute += 60;
    }
    diff.minute = _t1.minute - _t2.minute;
    diff.hour = _t1.hour - _t2.hour;

    cout << diff.hour << ":" << diff.minute << endl;
}

void printMenu() { 
    cout << "\n\n---------------------------------------------------------------------------------\n";
    cout << "1 - Show all transport information that are in the file on the screen.\n";
    cout << "2 - Add a transport\n";       
    cout << "3 - Show the travel time of a particular transport line.\n";
    cout << "4 - Show all transports that stop at a given station.\n";
    cout << "5 - Stop the program\n"; 
    cout << "---------------------------------------------------------------------------------\n\n";
}

Transport::Transport() {}   // Default constructor
Transport::~Transport() {}   // Destructor       

Transport::Transport(const Transport& theOther) {       // copyConstructor
    ticketPrice = theOther.ticketPrice;
        
    stations.clear();
    for (int i = 0; i < theOther.stations.size(); i++)
        stations.push_back(theOther.stations[i]);

    timeList.clear();
    for (int i = 0; i < theOther.timeList.size(); i++)
        timeList.push_back(theOther.timeList[i]);
}
   

Transport::Transport(int _ticketPrice, vector<string> _stations, vector<string> _timeList) :   //parametrized Constructor
        ticketPrice(_ticketPrice), stations(_stations), timeList(_timeList) {}  // Initialization List


void splitStringToVector(string s, vector<string>& v) {

    string temp = "";
    for (int i = 0; i < s.length(); ++i) {

        if (s[i] == ' ') {
            v.push_back(temp);
            temp = "";
        }
        else {
            temp.push_back(s[i]);
        }

    }
    v.push_back(temp);
}