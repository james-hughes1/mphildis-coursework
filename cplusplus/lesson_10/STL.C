#include<iostream>
#include<vector>
#include<list>
#include<algorithm>

void numbers_vec() {
    std::vector<float> a;
    std::cout << "Please enter a list of positive numbers, ending with a negative one:" << std::endl;
    float input;
    while (input >= 0) {
        std::cin >> input;
        a.push_back(input);
    }
    std::sort(a.begin(), a.end());
    std::cout << "Sorted vector, every other element:" << std::endl;
    for( auto vecIter = a.begin()+1 ; vecIter != a.end(); vecIter+=2 ){
        std::cout << *vecIter << std::endl;
    }
}

void numbers_list() {
    std::list<float> a;
    std::cout << "Please enter a list of positive numbers, ending with a negative one:" << std::endl;
    float input;
    while (input >= 0) {
        std::cin >> input;
        a.push_back(input);
    }
    a.sort();
    std::cout << "Sorted vector, every other element:" << std::endl;
    auto listIter = ++ a.begin();
    float lastElt = *listIter;
    while ( listIter != a.end() & lastElt <= *listIter){
        std::cout << *listIter << std::endl;
        float lastElt = *listIter;
        std::advance(listIter, 2);
    }
}

int main() {
    numbers_list();
}