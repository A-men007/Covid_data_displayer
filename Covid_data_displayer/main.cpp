#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "record.h"

using namespace std;


// Global variables declared for use across functions, storing the method and order of sort
int method;
int order;


int main(int argc, char **argv) {
    
    if (argc != 2) {
        printf("\nUSAGE: ./assignment1 {csv_file_name} \n\n");
        exit(0);
    }
    
    // File is opened, error message printed if unsuccessful
    ifstream file;
    file.open(argv[1]);
    if (file.is_open() == false) {
        cout << "\nFile failed to open.\n" << endl;
        exit(0);
    }

    // Global Variables are initialized
    method = getMethod();
    order = getOrder();

    // Used to remove row with column headers
    string blank;
    getline(file, blank);

    // Vector initialized
    vector<Record> records;

    string line;

    // Populates vector with objects of the 'Record' class
    while(getline(file, line)) {

        Record country = Record(line);
        records.push_back(country);

    }

    // The records are sorted according to the method and order specified
    vector<Record> sortedRecords = sortRecords(records);

    // The graph is printed
    makeGraph(sortedRecords);


    return 0;
}


// This method promtps the user with a menu for method of sort selection
int getMethod() {

    int num = 0;

    cout << "\nWhich Method would you like to sort by?:" << endl;
    cout << endl;
    cout << "\t1 - New Cases" << endl;
    cout << "\t2 - New Deaths" << endl;
    cout << "\t3 - New Recovered Cases" << endl;
    cout << "\t4 - Total Cases" << endl;
    cout << "\t5 - Total Deaths" << endl;
    cout << "\t6 - Total Recovered Cases" << endl;
    cout << endl;

    do {
        cout << "Enter Selection: ";
        cin >> num;

        switch(num) {
            case 1:
                cout << "\n\'New Confirmed Cases\' Selected.\n" << endl;
                return num;
            case 2:
                cout << "\n\'New Deaths\' Selected.\n" << endl;
                return num;
            case 3:
                cout << "\n\'New Recovered Cases\' Selected.\n" << endl;
                return num;
            case 4:
                cout << "\n\'Total Confirmed Cases\' Selected.\n" << endl;
                return num;
            case 5:
                cout << "\n\'Total Deaths\' Selected.\n" << endl;
                return num;
            case 6:
                cout << "\n\'Total Recovered Cases\' Selected.\n" << endl;
                return num;
            default:
                cout << "\nInvalid Selection.\n" << endl;
                break;
        }

    } while (num < 1 || num > 6);

    return num;
}


// This function prompts the user with a menu for order of sort selection
int getOrder() {

    int num = 0;

    cout << "\nWhich Order would you like to sort by?:" << endl;
    cout << endl;
    cout << "\t1 - Ascending (Low to High)" << endl;
    cout << "\t2 - Descending (High to Low)" << endl;
    cout << endl;

    do {
        cout << "Enter Selection: ";
        cin >> num;

        switch(num) {
            case 1:
                cout << "\n\'Ascending\' Selected.\n" << endl;
                return num;
            case 2:
                cout << "\n\'Descending\' Selected.\n" << endl;
                return num;
            default:
                cout << "\nInvalid Selection.\n" << endl;
                break;
        }

    } while (num < 1 || num > 2);

    return num;
}


// This is a helper 'lambda function' used to sort according to method and order specified, called by sortRecords()
bool sortFunction(Record first, Record second) {

    if (method == 1) {
        if (order == 1) {
           return (first.getNewCases() < second.getNewCases()); 
        }
        else if (order == 2) {
            return (first.getNewCases() > second.getNewCases());
        }
    }
    else if (method == 2) {
        if (order == 1) {
            return (first.getNewDeaths() < second.getNewDeaths());
        }
        else if (order == 2) {
            return (first.getNewDeaths() > second.getNewDeaths());
        }
    }
    else if (method == 3) {
        if (order == 1) {
            return (first.getNewRecoveries() < second.getNewRecoveries());
        }
        else if (order == 2) {
            return (first.getNewRecoveries() > second.getNewRecoveries());
        }
    }
    else if (method == 4) {
        if (order == 1) {
            return (first.getTotalCases() < second.getTotalCases());
        }
        else if (order == 2) {
            return (first.getTotalCases() > second.getTotalCases());
        }
    }
    else if (method == 5) {
        if (order == 1) {
            return (first.getTotalDeaths() < second.getTotalDeaths());
        }
        else if (order == 2) {
            return (first.getTotalDeaths() > second.getTotalDeaths());
        }
    }
    else if (method == 6) {
        if (order == 1) {
            return (first.getTotalRecoveries() < second.getTotalRecoveries());
        }
        else if (order == 2) {
            return (first.getTotalRecoveries() > second.getTotalRecoveries());
        }
    }

    return true;
}


// Used built-in sort() functoin and sortFunction() 'lambda' to sort the vector
vector<Record> sortRecords(vector<Record> records) {

    vector<Record> result = records;

    sort(result.begin(), result.end(), sortFunction);

    return result;
}


// Uses the sorted vectore to display the results in a graph
void makeGraph(vector<Record> records) {

    float numCases;
    int numHash;
    int maxHash;
    string legend;

    for (int i = 0; i < 10; i++) {

        switch(method) {

            case 1:
                switch(order) {
                    case 1:

                        if (records[9].getNewCases() > 70) {
                            maxHash = 70;
                        } else {
                            maxHash = records[9].getNewCases();
                            if (maxHash == 0) {
                                maxHash = 1;
                            }
                        }

                        numCases = (float)records[9].getNewCases() / (float)maxHash;
                        cout << records[i].getCode() << " | ";
                        numHash = records[i].getNewCases() / numCases;

                        if (numHash > 0) {
                           for (int x = 0; x < records[i].getNewCases() / numCases; x++) {
                            cout << "#";
                            } 
                        }
                        cout << endl;
                        legend = "New Confirmed Cases;";

                        break;

                    case 2:

                        if (records[0].getNewCases() > 70) {
                            maxHash = 70;
                        } else {
                            maxHash = records[0].getNewCases();
                        }

                        numCases = records[0].getNewCases() / maxHash;
                        cout << records[i].getCode() << " | ";
                        for (int x = 0; x < records[i].getNewCases() / numCases; x++) {
                            cout << "#";
                        }
                        cout << endl;
                        legend = "New Confirmed Cases;";

                        break;
                        
                    default:
                        break;
                }

                break;

            case 2:
                switch(order) {
                    case 1:

                        if (records[9].getNewDeaths() > 70) {
                            maxHash = 70;
                        } else {
                            maxHash = records[9].getNewDeaths();
                            if (maxHash == 0) {
                                maxHash = 1;
                            }
                        }

                        numCases = (float)records[9].getNewDeaths() / (float)maxHash;
                        cout << records[i].getCode() << " | ";
                        numHash = records[i].getNewDeaths() / numCases;

                        if (numHash > 0) {
                           for (int x = 0; x < records[i].getNewDeaths() / numCases; x++) {
                            cout << "#";
                            } 
                        }
                        cout << endl;
                        legend = "New Deaths;";

                        break;

                    case 2:

                        if (records[0].getNewDeaths() > 70) {
                            maxHash = 70;
                        } else {
                            maxHash = records[0].getNewDeaths();
                        }

                        numCases = records[0].getNewDeaths() / maxHash;
                        cout << records[i].getCode() << " | ";
                        for (int x = 0; x < records[i].getNewDeaths() / numCases; x++) {
                            cout << "#";
                        }
                        cout << endl;
                        legend = "New Deaths;";

                        break;
                        
                    default:
                        break;
                }

                break;

            case 3:
                switch(order) {
                    case 1:

                        if (records[9].getNewRecoveries() > 70) {
                            maxHash = 70;
                        } else {
                            maxHash = records[9].getNewRecoveries();
                            if (maxHash == 0) {
                                maxHash = 1;
                            }
                        }

                        numCases = (float)records[9].getNewRecoveries() / (float)maxHash;
                        cout << records[i].getCode() << " | ";
                        numHash = records[i].getNewRecoveries() / numCases;

                        if (numHash > 0) {
                           for (int x = 0; x < records[i].getNewRecoveries() / numCases; x++) {
                            cout << "#";
                            } 
                        }
                        cout << endl;
                        legend = "New Recovered Cases;";

                        break;

                    case 2:

                        if (records[0].getNewRecoveries() > 70) {
                            maxHash = 70;
                        } else {
                            maxHash = records[0].getNewRecoveries();
                        }

                        numCases = records[0].getNewRecoveries() / maxHash;
                        cout << records[i].getCode() << " | ";
                        for (int x = 0; x < records[i].getNewRecoveries() / numCases; x++) {
                            cout << "#";
                        }
                        cout << endl;
                        legend = "New Recovered Cases;";

                        break;

                    default:
                        break;
                }

                break;


            case 4:
                switch(order) {
                    case 1:

                        if (records[9].getTotalCases() > 70) {
                            maxHash = 70;
                        } else {
                            maxHash = records[9].getTotalCases();
                            if (maxHash == 0) {
                                maxHash = 1;
                            }
                        }

                        numCases = (float)records[9].getTotalCases() / (float)maxHash;
                        cout << records[i].getCode() << " | ";
                        numHash = records[i].getTotalCases() / numCases;

                        if (numHash > 0) {
                           for (int x = 0; x < records[i].getTotalCases() / numCases; x++) {
                            cout << "#";
                            } 
                        }
                        cout << endl;
                        legend = "Total Confirmed Cases;";

                        break;

                    case 2:

                        if (records[0].getTotalCases() > 70) {
                            maxHash = 70;
                        } else {
                            maxHash = records[0].getTotalCases();
                        }

                        numCases = records[0].getTotalCases() / maxHash;
                        cout << records[i].getCode() << " | ";
                        for (int x = 0; x < records[i].getTotalCases() / numCases; x++) {
                            cout << "#";
                        }
                        cout << endl;
                        legend = "Total Confirmed Cases;";

                        break;
                        
                    default:
                        break;
                }

                break;

            case 5:
                switch(order) {
                    case 1:

                        if (records[9].getTotalDeaths() > 70) {
                            maxHash = 70;
                        } else {
                            maxHash = records[9].getTotalDeaths();
                            if (maxHash == 0) {
                                maxHash = 1;
                            }
                        }

                        numCases = (float)records[9].getTotalDeaths() / (float)maxHash;
                        cout << records[i].getCode() << " | ";
                        numHash = records[i].getTotalDeaths() / numCases;

                        if (numHash > 0) {
                           for (int x = 0; x < records[i].getTotalDeaths() / numCases; x++) {
                            cout << "#";
                            } 
                        }
                        cout << endl;
                        legend = "Total Deaths;";

                        break;

                    case 2:

                        if (records[0].getTotalDeaths() > 70) {
                            maxHash = 70;
                        } else {
                            maxHash = records[0].getTotalDeaths();
                        }

                        numCases = records[0].getTotalDeaths() / maxHash;
                        cout << records[i].getCode() << " | ";
                        for (int x = 0; x < records[i].getTotalDeaths() / numCases; x++) {
                            cout << "#";
                        }
                        cout << endl;
                        legend = "Total Deaths;";

                        break;
                        
                    default:
                        break;
                }

                break;

            case 6:
                switch(order) {
                    case 1:

                        if (records[9].getTotalRecoveries() > 70) {
                            maxHash = 70;
                        } else {
                            maxHash = records[9].getTotalRecoveries();
                            if (maxHash == 0) {
                                maxHash = 1;
                            }
                        }

                        numCases = (float)records[9].getTotalRecoveries() / (float)maxHash;
                        cout << records[i].getCode() << " | ";
                        numHash = records[i].getTotalRecoveries() / numCases;

                        if (numHash > 0) {
                           for (int x = 0; x < records[i].getTotalRecoveries() / numCases; x++) {
                            cout << "#";
                            } 
                        }
                        cout << endl;
                        legend = "Total Recovered Cases;";

                        break;

                    case 2:

                        if (records[0].getTotalRecoveries() > 70) {
                            maxHash = 70;
                        } else {
                            maxHash = records[0].getTotalRecoveries();
                        }

                        numCases = records[0].getTotalRecoveries() / maxHash;
                        cout << records[i].getCode() << " | ";
                        for (int x = 0; x < records[i].getTotalRecoveries() / numCases; x++) {
                            cout << "#";
                        }
                        cout << endl;
                        legend = "Total Recovered Cases;";

                        break;
                        
                    default:
                        break;
                }

                break;

            deafult:
                break;
        }
    }

    if (numCases == 0) {
        numCases = 1;
    }

    cout << "-------------------------------------------------------" << endl;
    cout << legend << " Each # is approx " << numCases << " case(s).\n" << endl;

    return;
}