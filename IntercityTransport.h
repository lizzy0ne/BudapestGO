#pragma once
#include "Transport.h"

class IntercityTransport : public Transport {
public:
    bool passValid;    // not valid for 100E
    string type;       //bus, metro, tram
    string number;     //e.g. "133E", "914A"
public:
    bool get_passValid() {
        return passValid;
    }
    string get_type() {
        return type;
    }
    string get_number() {
        return number;
    }

    IntercityTransport();

    IntercityTransport(const IntercityTransport& theOther);
    virtual ~IntercityTransport();

    IntercityTransport(int _ticketPrice, vector<string> _stations, vector<string> _timeList, bool _passValid, string _type, string _number);


    string transportToString();
};

void timeBetweenDestinationsIntercity(string _type, string _number, vector<IntercityTransport*>& _listOfIntercityTransport);
void addInterCityTransport(fstream& _file, vector<IntercityTransport*>& _listOfIntercityTransport);
void sameNameIntercityTransport(string _station, vector<IntercityTransport*>& _listOfIntercityTransport);