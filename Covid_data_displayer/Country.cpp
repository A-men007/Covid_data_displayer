/*
CS3307: Assign 1
Date : Oct 5, 2020
Name: Amanpreet Gill
Student Number : 250964445
uwo: agill292@uwo.ca
Program's description : Reads and outputs Coronavirus data from different countries in decending/acending order
arg 1: cvs file location
*/
#include "Country.h"
#include <string>
using namespace std;

Country::Country(string name) {
	Cname = name;
}
void Country::setname(string x) { Cname = x; }
void Country::setcode(string x) { Ccode = x; }
void Country::setNC(int x) { nConfirmed = x; }
void Country::setND(int x) { nDeaths = x; }
void Country::setNR(int x) { nRecovered = x; }
void Country::setTC(int x) { tConfirmed = x; }
void Country::setTD(int x) { tDeaths = x; }
void Country::setTR(int x) { tRecovered = x; }

string Country::getname() { return Cname; }
string Country::getcode() { return Ccode; }
int Country::getNC() { return nConfirmed; }
int Country::getND() { return nDeaths; }
int Country::getNR() { return nRecovered; }
int Country::getTC() { return tConfirmed; }
int Country::getTD() { return tDeaths; }
int Country::getTR() { return tRecovered; }


Country::~Country(){}
