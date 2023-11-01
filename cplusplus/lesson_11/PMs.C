#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>

void find_first(std::string str, std::vector<std::string> list1, std::vector<std::string> list2) {
    int num = std::count(list1.begin(), list1.end(), str);
    if (num>0) {
        std::vector<std::string>::iterator listIter = std::find(list1.begin(), list1.end(), str);
        size_t posnStr = listIter - list1.begin();
        std::cout << "The first " << str << " was: " << str << " " << list2[posnStr] << ", the " << posnStr+1 << "th PM." << std::endl;
    }
    else {
        std::cout << "There was never a "<< str << " at No. 10." << std::endl;
    }
}

int main(){
    std::ifstream inputFile("./PMs.txt"); // Open file
    std::vector<std::string> firstNames;
    std::vector<std::string> lastNames;
    std::string first, last;
    inputFile >> first >> last;
    firstNames.push_back(first);
    lastNames.push_back(last);
    while (std::getline(inputFile, last)) {
        inputFile >> first >> last;
        firstNames.push_back(first);
        lastNames.push_back(last);
    }
    inputFile.close();
    find_first("George",firstNames,lastNames);
    find_first("Richard",firstNames,lastNames);
}