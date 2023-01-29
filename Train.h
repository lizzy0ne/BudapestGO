#pragma once
#include "Transport.h"

class Train :public Transport { 
public:
    string color;
public:
    string get_color() {
        return color;
    }

    Train();

    virtual ~Train();

    Train(const Train& theOther);

    Train(int _ticketPrice, vector<string> _stations, vector<string> _timeList, string _color);

    string transportToString();
};

void addTrain(fstream& _file, vector<Train*>& _listOfTrain);
void sameNameTrains(string _station, vector<Train*>& _listOfTrains);
void timeBetweenDestinationsTrain(string _color, vector<Train*>& _listOfTrains);
