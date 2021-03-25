//
// Created by paolo on 24/03/2021.
//

#include "Message.h"


char* mkMessage(int n){
    std::string vowels = "aeiou";
    std::string consonants = "bcdfghlmnpqrstvz";
    char* m = new (std::nothrow) char[n+1];
    if(m != nullptr){
        for (int i = 0; i < n; i++){
            m[i] = i%2 ? vowels[rand()%vowels.size()] : consonants[rand()%consonants.size()];
        }
        m[n] = '\0';
    }
    return m;
}

Message::Message(int n) {
    static long id = 0;
    this->id = id;
    this->data = mkMessage(n);
    this->size = n;
    id++;
}


Message::Message(void) {
    this->id = -1;
    this->data = nullptr;
    this->size = 0;
}

Message::Message(const Message &m):size(m.size),id(m.id)
{
    if(this->id != m.id) {
        if (this->data != nullptr)
            delete this->data;
        this->data = new char[size + 1];
        memcpy(this->data, m.data, this->size + 1);
    }

}

Message::Message(Message &&source):size(source.size),id(source.id) {
    delete[] this->data;
    this->data = source.data;
    source.data = nullptr;
}


Message Message::operator=(const Message &m){
    this->id = m.id;
    this->size = m.size;
    if(m.id==-1){
        this->data = nullptr;
        return *this;
    }
    this->data = new char[this->size+1];
    memcpy(this->data,m.data,m.getSize()+1);
    return *this;
}

Message Message::operator=(Message &&m){

    delete[] this->data;
    this->data = m.data;
    this->size = m.size;
    this->id = m.id;
    m.data = nullptr;

    return *this;
}

std::ostream& operator<<(std::ostream &out, const Message &m) {
    std::string s(m.getMessage());
    out << " [id:" << m.getId() << " ]" << " [size:" << m.getSize() << " ]" << " [data:" << s.substr(0, 5) << " ]";
    return out;
}


char* Message::getMessage() const {
    if (id==-1)
        return "";
    return this->data;
}


long Message::getId() const{
    return this->id;
}


int Message::getSize() const{
    return this->size;
}

Message::~Message() {
    if(this->data!= nullptr) {
        delete[] this->data;
        this->data = nullptr;
    }
    this->size = -1;
    this->id = -1;
}

