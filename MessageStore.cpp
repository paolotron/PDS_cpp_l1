//
// Created by paolo on 24/03/2021.
//


#include "MessageStore.h"

MessageStore::MessageStore(int n) {
    this->messages = new Message[n];
    this->n = n;
    this->dim = n;
}

bool MessageStore::remove(long id) {
    for(int i=0; i< this->dim-1; i++){
        if(this->messages[i].getId() == id){
            this->messages[i] =*(new Message());
            return true;
        }
    }
    return false;
}

void MessageStore::add(Message &m) {
    bool found = false;
    for(int i=0; i<this->dim-1; i++){
        if(this->messages[i].getId() == -1){
            this->messages[i] = m;
            found = true;
            break;
        }
    }
    if(!found){
        Message* old_message = this->messages;
        int ne = this->dim + this->n;
        Message* new_message = new Message[ne];
        for(int i=0; i < this->dim-1; i++){
            new_message[i] = old_message[i];
        }
        this->dim+=n;
        this->messages = old_message;
        delete this->messages;
    }
}

MessageStore::~MessageStore() {
    delete[] this->messages;
    this->messages = nullptr;
}

void MessageStore::compact() {
    int start = -1;
    for(int i = this->dim-1; i>=0; i--){
        if(this->messages[i].getId() != -1) {
            if (start == -1) {
                start = i;
            }
        }
        else{
            if(start != -1){
                this->messages[i] = this->messages[start];
                this->messages[start] = *(new Message());
                start = -1;
            }
        }
    }
        return;
}

std::tuple<int, int> MessageStore::stats() {
    int tot=0;
    for (int i=0; i < this->dim-1; i++)
        if(this->messages[i].getId()!=-1)
            tot++;
    return std::make_tuple(tot,this->dim-1);
}

Message MessageStore::get(long id) {
    for(int i=0; i< this->dim-1; i++){
        if(this->messages[i].getId() == id){
            return this->messages[i];
        }
    }
    return Message();
}


