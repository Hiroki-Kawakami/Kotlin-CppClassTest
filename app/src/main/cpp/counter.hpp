//
// Created by hiroki on 2020/03/31.
//

#include <string>

using std::string;

class counter {
public:
    counter();

    int count;
    string description();
    void increment();
};