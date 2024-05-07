#include "milkdistributioninterface.h"
#include <sstream>
MilkDistributionInterface::MilkDistributionInterface()
{
    std::cout<<"shop opened!"<<std::endl;
}

MilkDistributionInterface::~MilkDistributionInterface()
{
    std::cout<<"Milk distribution shop closed"<<std::endl;
}

void MilkDistributionInterface::startMilkDistributionWork()
{
    if(this->getExistingCustomersFromFile())
    {
        std::cout<<"error when file access check file and try again"<<std::endl;
        return;

    }

    if(this->startDistributionProcess())
    {
        std::cout<<"error: while distributing milk"<<std::endl;
    }else
    {
        std::cout<<"distribution done!"<<std::endl;
    }
    //writing customer details  to file
    if(this->writeCustomerDetailsToFile())
    {
        std::cout<<"Error: while writing customer details to file"<<std::endl;
    }else
    {
        std::cout<<"writting customer details to file is successful"<<std::endl;
    }

}

std::string MilkDistributionInterface::getCurrentDate()
{
    std::time_t now=std::time(nullptr);
    std::tm* localTime=std::localtime(&now);
    std::stringstream ss;
    ss<<(localTime->tm_year + 1900)<<'-'
       <<(localTime->tm_mon +1)<<'-'
       <<localTime->tm_mday;
    return ss.str();

}



bool MilkDistributionInterface::getExistingCustomersFromFile()
{

    using namespace customerDetailsLine;


    std::ifstream customerSourceFile("customerDetails.txt");
    std::string currentDate=getCurrentDate();
    std::string debugFileName="DebugLogfile"+currentDate+".txt";

    //file pointers
    std::ofstream debugFile(debugFileName);

    if(!customerSourceFile)
    {
        std::cout<<"Error: unable to open file\n";
        return 1;
    }
    else
    {
        std::cout<<"file opened successfully\n";

        if(!debugFile.is_open())
        {
            std::cout<<"error: when debug file opening"<<std::endl;
        }else
        {
            std::cout<<"Success: when debug file opening"<<std::endl;

        }

        int lineNumber=0;
        bool lineErrorStatus=0;
        std::string line;
        while (std::getline(customerSourceFile, line))
        {
            // Create a stringstream to parse the line
            std::istringstream iss(line);
            std::string token;
            std::vector<std::string> values;
            lineNumber++;

            // Tokenize the line by commas and store each value in a vector
            while (std::getline(iss, token, ','))
            {
                values.push_back(token);
            }

            //checking the fetched line for input validation and adding to the respective files,


            std::regex namePattern("^[a-zA-Z]+(?: [a-zA-Z]+)*$");
            if(!std::regex_match(values[CustomerName],namePattern))
            {
                debugFile<<lineNumber<<":Invalid name"<<std::endl;

            }
            std::regex phonePattern("^[1-9]\\d{9}$");
            if(!std::regex_match(values[PhoneNumber],phonePattern))
            {
                debugFile<<lineNumber<<":Invalid PhoneNumer"<<std::endl;

            }
            std::regex milkQty("^[1-9]$");
            if(!std::regex_match(values[MilkQuantity],milkQty))
            {
                debugFile<<lineNumber<<":Invalid Milk Quantity"<<std::endl;

                values[MilkQuantity]="0"; //taking wrong entry default to zero

            }
            std::regex houseNumberPattern("^[0-9]+$");
            if (!std::regex_match(values[HouseNumber], houseNumberPattern))
            {
                debugFile<<lineNumber<<":Invalid House Number"<<std::endl;

            }
            if(!std::regex_match(values[Area],namePattern))
            {
                debugFile<<lineNumber<<":Invalid Area name"<<std::endl;

            }
            if(!std::regex_match(values[City],namePattern))
            {
                debugFile<<lineNumber<<":Invalid City name"<<std::endl;
                }

            std::regex pincodePattern("^[0-9]{6}$");
            if(!std::regex_match(values[Pincode],pincodePattern))
            {
                debugFile<<lineNumber<<":Invalid Pincode"<<std::endl;

            }
            //check whether current customer data is valid or not
            if(!DEBUG)
            {
                debugFile<<lineNumber<<":valid entry="<<values[CustomerName]<<","<<values[PhoneNumber]<<","<<values[MilkQuantity]<<","<<values[HouseNumber]<<","<<values[Area]<<","<<values[City]<<","<<values[Pincode]<<std::endl;

            }
            //log entry coompleted here


            m_justin.addCustomer(values);


        }

    }

    customerSourceFile.close();
    debugFile.close();

    return 0;
}


bool MilkDistributionInterface::startDistributionProcess()
{
    std::cout<<"welcome to Home page\n";
    int choose{1};
    while(choose)
    {
        std::cout<<"\t\t 1.add Customer\n \
                2.display all Customers\n \
                3.calculate total Milk needed today\n \
                4.buy milk from head Distributors\n \
                5.start distribution \n \
                6.milkBalance\n \
                9.logout========";

                            std::cin>>choose;
        static int totalMilkNeeded{0};
        static int totalMilkReceived{0};

        switch(choose)
        {
        case 1:m_justin.addCustomer(); //add customer details to distributor container

            break;
        case 2:m_justin.displayAllCustomer(); // view all customers details at once
            break;
        case 3:
            //calculate how much milk needed before buying today stock
            totalMilkNeeded=m_justin.CalculateHowMuchMilkRequireToday();
            std::cout<<"total milk needed today="<<totalMilkNeeded<<std::endl;
            break;
        case 4:
            //get milk from head distributors and fill to our milk container
            if(totalMilkNeeded<=0)
            {
                std::cout<<"calculate how much milk needed today"<<std::endl;
                break;
            }
            totalMilkReceived=m_justin.getMilkFromHeadDistributors(totalMilkNeeded);
            std::cout<<"total milk Received="<<totalMilkReceived<<std::endl;
            break;
        case 5:
            //check milk availability before distribute
            if(m_justin.milkBalance()<=0)
            {
                std::cout<<"milk not available for distribute\n";
                break;
            }else
            {
                m_justin.startDistribution();
                std::cout<<"milk Distribution completed\n";
                break;}
        case 6: std::cout<<"milk Balance with distributor="<<m_justin.milkBalance()<<std::endl;
            break;
        case 9: choose=0;
            break;
        default:std::cout<<"try again\n";
        }
    }
    return 0;
}

bool MilkDistributionInterface::writeCustomerDetailsToFile()
{
    int choose=1;
    std::cout<<"do you want to add customer data to file\n1(yes)\n0(no)=";
    std::cin>>choose;
    if(choose==0){
        std::cout<<"Data not added to file"<<std::endl;
        return 1;
    }
    std::ofstream outputFile("customerDetails.txt");
    if(!outputFile)
    {
        std::cout<<"Error: unable to open file\n";
    }else
    {
        std::cout<<"file opened successfully\n";
        //std::list<Customer*> customerDetailsTemp=m_justin.customerDetails();
        for(auto& customerData:m_justin.customerDetails())
        {

            outputFile<<customerData->name()<<","<<customerData->phoneNumber()<<","<<customerData->milkOrderedQuantity();

            auto address=customerData->address();
            outputFile<<","<<address->houseNumber()<<","<<address->streetName()<<","<<address->city()<<","<<address->pincode()<<"\n";


        }

        outputFile.close();
    }
    return 0;


}
