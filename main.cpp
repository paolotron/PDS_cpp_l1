#include <iostream>
#include "Message.h"
#include "DurationLogger.h"
#include "MessageStore.h"

char* mkMessage(int n);


void foo(){
    Message m2 = Message(10);
    Message m3 = Message(m2);
    std::cout << m3;
}

void test_constructors(){
    Message v[10];
    DurationLogger *a = new DurationLogger("ciao");
    for (int i=0; i<10; i++) {
        Message m = Message(1024 * 1024* 10);
        v[i] = m;
    }
    delete a;
    DurationLogger *b = new DurationLogger("miao");
    for (int i=0; i<10; i++) {
        v[i] = Message(1024);
    }
    delete b;
}
void printStats(std::tuple<int, int> t){
    int a1 = std::get<0>(t);
    int a2 = std::get<1>(t);
    std::cout << "valid messages: " << a1 << " available space: "<< a2 << "\n";
}

int main() {
    MessageStore* store = new MessageStore(3);
    Message* x = new Message(20);

    store->add(*x);
    store->add(*x);
    printStats(store->stats());
    store->add(*new Message(29));
    printStats(store->stats());
    store->add(*new Message(29));
    store->add(*new Message(29));
    std::cout << store->get(1) << "\n";
    printStats(store->stats());
    store->remove(2);
    store->compact();
    printStats(store->stats());
    printStats(store->stats());
    return 0;
}



