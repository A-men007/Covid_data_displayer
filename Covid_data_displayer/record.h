#ifndef record_h
#define record_h
#include <string>
#include <vector>


// Declarations for 'record.cpp' file
class Record {
    private:
        std::string countryName;
        std::string countryCode;
        int newCases, newDeaths, newRC;
        int totalCases, totalDeaths, totalRC;

    public:
        Record(std::string line);

        std::string getName();
        std::string getCode();
        int getNewCases();
        int getNewDeaths();
        int getNewRecoveries();
        int getTotalCases();
        int getTotalDeaths();
        int getTotalRecoveries();

        ~Record();
};


// Declarations for 'main.cpp' file
int getMethod(void);
int getOrder(void);
bool sortFunction(Record, Record);
std::vector<Record> sortRecords(std::vector<Record>);
void makeGraph(std::vector<Record>);


#endif