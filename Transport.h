#pragma once

/* Information about objects should be stored in file
   I didn't separate program into files for better understanding of my project
   "Budapest Go" project

  base:                         Transport
  derived:       IntercityTransport    Train
*/

#include <iostream>
#include <vector>   
#include <string>
#include <sstream>
using namespace std;


void printMenu();


typedef struct Time{  
    int hour;
    int minute;
} Time;

Time stringToTime(string _sTime);

void timeDifference(Time _t1, Time _t2);

class Transport {
protected:
    int ticketPrice;
    vector<string> stations;     //stations.push_back("UjBuda")
    vector<string> timeList;    

public:
    int get_ticketPrice() {
        return ticketPrice;
    }
    vector<string> get_stations() {
        return stations;
    }
       
    vector<string> get_timeList() {
        return timeList;
    }

    Transport();    // default constructor

    virtual ~Transport();   // destructor    virtual to avoid memory leak;

    Transport(const Transport& theOther);  //copyConstructor

    Transport(int _ticketPrice, vector<string> _stations, vector<string> _timeList);  // Initialization List

 
    virtual string transportToString() = 0;
};

void splitStringToVector(string s, vector<string>& v);