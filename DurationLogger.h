//
// Created by paolo on 24/03/2021.
//

#ifndef LAB1_DURATIONLOGGER_H
#define LAB1_DURATIONLOGGER_H


#include <ctime>

class DurationLogger {
    int start;
    std::string name;
public:
    DurationLogger(const std::string& name){
        this->start = std::clock();
        this->name = name;
        std::cout << "starting [" << name << "]\n";
    }
    ~DurationLogger(){
        std::cout << "ending [" << name << "]: [" << std::clock()-this->start << "] nanosec\n";
    }

};


#endif //LAB1_DURATIONLOGGER_H
