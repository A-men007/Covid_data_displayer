#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include "record.h"

using namespace std;


// Constructor; where the processing is done for each row/line in the csv file
Record::Record(string line) {

    // Used to store the country name, since this value is a 'special case' (since not comma-delimited)
    string name = line.substr(1, line.find("\",")-1);
    countryName = name;

    // Creates a new line with the country name removed, making it easy to use commas as the delimeter
    string newLine = line.substr(line.find("\",") + 2, line.length());

    istringstream ss(newLine);
    string token;

    string arr[10];

    // String 'line' is tokenized
    int i = 0;
    while(getline(ss, token, ',')) {
        arr[i] = token;
        i++;
    }

    // Values are assigned to their correspinding data members
    countryCode = arr[0].substr(1, 2);
    newCases = stoi(arr[2]);
    newDeaths = stoi(arr[3]);
    newRC = stoi(arr[4]);
    totalCases = stoi(arr[7]);
    totalDeaths = stoi(arr[8]);
    totalRC = stoi(arr[9]);

}

// Pubic 'getter' methods for the class
string Record::getName() {
    return countryName;
}
string Record::getCode() {
    return countryCode;
}
int Record::getNewCases() {
    return newCases;
}
int Record::getNewDeaths() {
    return newDeaths;
}
int Record::getNewRecoveries() {
    return newRC;
}
int Record::getTotalCases() {
    return totalCases;
}
int Record::getTotalDeaths() {
    return totalDeaths;
}
int Record::getTotalRecoveries() {
    return totalRC;
}

// Destructor
Record::~Record() {
    ; // Do Nothing
}