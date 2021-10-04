#include <iostream>
#include <string>
#include "SimpleDatabase.h"


int main(int argc, char* argv[]) {
    
    zlimbo::SimpleDatabase sdb;

    // block
    int res = sdb.loop();

    return res;
}