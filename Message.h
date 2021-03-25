//
// Created by paolo on 24/03/2021.
//

#ifndef LAB1_MESSAGE_H
#define LAB1_MESSAGE_H

#include <string.h>
#include <iostream>



class Message {
    long id;
    char *data;
    int size;
public:
    Message(int n);
    Message(void);
    char* getMessage() const;
    Message(const Message &m);
    Message(Message&& source);
    long getId() const;
    int getSize() const;
    Message operator=(const Message &m);
    Message operator=(Message &&m);
    ~Message();
};

std::ostream& operator<<(std::ostream &out, const Message &m);


#endif //LAB1_MESSAGE_H
