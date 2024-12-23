#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>

void processLedger(const std::vector<std::string>& names, const std::vector<int>& amounts, const std::vector<std::string>& dates){
    int totalAmount = 0;
    std::string maxRecipient;
    int maxAmount = -1;

    for(size_t i = 0; i < amounts.size(); ++i){
        totalAmount += amounts[i];
        if(amounts[i] > maxAmount){
            maxAmount = amounts[i];
            maxRecipient = names[i];
        }
    } 
    std::cout << "Total amount of payments :"<< totalAmount <<"\n";
    std::cout << "Highest payout :" << maxAmount << "(" << maxRecipient <<")\n";
}
int main(){
    std::vector<std::string> names;
    std::vector<int> amounts;
    std::vector<std::string> dates;
    std::string line;
    std::ifstream inputFile("payments.txt");

    if(!inputFile){
        std::cerr << "Could not open the file payments.txt";
        return 1;
    }
    while(std::getline(inputFile, line)){
        std::istringstream iss(line);
        std::string name, surname, date;
        int amount;

        iss >> name >> surname >> amount;
        std::getline(iss , date);

        names.push_back(name +" "+surname);
        amounts.push_back(amount);
        dates.push_back(date);
    }
    inputFile.close();

    if(!names.empty()){
        processLedger(names, amounts, dates);
    } else {
        std::cout << "The file is empty of contains incorrect data";
    }
    return 0;
}
