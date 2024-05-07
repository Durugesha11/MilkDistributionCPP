#ifndef MILKDISTRIBUTIONINTERFACE_H
#define MILKDISTRIBUTIONINTERFACE_H
#define DEBUG MYDEBUG_STATUS
#include "MilkDistributor.h"
#include "customer.h"
#include <fstream>
#include <vector>
#include <regex>
#include <string>
#include <ctime>
#include <customerdetailsenum.h>
class MilkDistributionInterface
{
public:
    MilkDistributionInterface();
    ~MilkDistributionInterface();
    void startMilkDistributionWork();

private:

    std::string getCurrentDate();

   bool getExistingCustomersFromFile();
   bool startDistributionProcess();
   bool writeCustomerDetailsToFile();
   void checkCustomerDetailsFetchedFromFile(std::vector<std::string>& values,int lineNumber);
   MilkDistributor m_justin;

};

#endif // MILKDISTRIBUTIONINTERFACE_H
