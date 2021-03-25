//
// Created by paolo on 24/03/2021.
//

#ifndef LAB1_MESSAGESTORE_H
#define LAB1_MESSAGESTORE_H


#include "Message.h"
#include <tuple>
#include <vector>

class MessageStore {
    Message* messages;
    int dim;
    int n;
public:
    MessageStore(int n);
    ~MessageStore();
    void add(Message &m);
    std::tuple<int, int> stats();
    Message get(long id);
    bool remove(long id);
    void compact();
};


#endif //LAB1_MESSAGESTORE_H
