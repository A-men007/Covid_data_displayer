/*
CS3307: Assign 1
Date : Oct 5, 2020
Name: Amanpreet Gill
Student Number : 250964445
uwo: agill292@uwo.ca
Program's description : Reads and outputs Coronavirus data from different countries in decending/acending order
*/
#ifndef COUNTRY_CLASS_H
#define COUNTRY_CLASS_H
//#pragma once
#include <string>
#include <iostream>
#include <sstream> 
#include <vector> 
class Country{
    private:
        std::string Cname;
        std::string Ccode;
        int nConfirmed, nDeaths, nRecovered;
        int tConfirmed, tDeaths, tRecovered;

    public:
        //constructor
        Country(std::string);
        //setters
        void setname(std::string);
        void setcode(std::string);
        void setNC(int);
        void setND(int);
        void setNR(int);
        void setTC(int);
        void setTD(int);
        void setTR(int);
        //getters
        std::string getname();
        std::string getcode();
        int getNC();
        int getND();
        int getNR();
        int getTC();
        int getTD();
        int getTR();


          
        //destructor
        ~Country();
};
#endif