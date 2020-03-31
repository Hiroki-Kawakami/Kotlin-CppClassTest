//
// Created by hiroki on 2020/03/31.
//

#include "counter.hpp"

counter::counter() {
    count = 0;
}

string counter::description() {
    return std::to_string(count) + "回実行されました";
}

void counter::increment() {
    count++;
}