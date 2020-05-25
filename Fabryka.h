#ifndef SOIZ4_FABRYKA_H
#define SOIZ4_FABRYKA_H

#include <queue>
#include "Monitor.h"
#include "Bufor.h"

class Fabryka : public Monitor{
private:
    Bufor buff;
    Condition Con10E; //even less than 10
    Condition ConOE; //more even than odd
    Condition ConS2; //size more than 2
    Condition ConS6; //size more than 6
    Condition ConEven; //last number is even
    Condition ConOdd; //last number is odd
    Condition ConBuff; //buff not empty
public:
    Fabryka()= default;

    void put(unsigned char val){
        enter();
        if(val%2 && buff.getOdd()>=buff.getEven())
                wait(ConOE);

        else if(buff.getEven()>=10)
            wait(Con10E);

        buff.put(val);

        signal(ConBuff);

        if(buff.getSize()>2)
            signal(ConS2);

        if(buff.getSize()>6)
            signal(ConS6);

        if(buff.getEven()>buff.getOdd())
            signal(ConOE);

        if(buff.getEven()<10)
            signal(Con10E);

        if(buff.getSize() == 1){
            if(buff.peek()%2)
                signal(ConOdd);
            else
                signal(ConEven);
        }
        leave();
    }

    unsigned char getOdd(){
        enter();
        unsigned char val;

        if(buff.getSize()==0)
            wait(ConBuff);

        if(!buff.peek()%2)
            wait(ConOdd);

        if(buff.getSize()<7)
            wait(ConS6);

        val = buff.get();

        if(buff.peek()%2)
            signal(ConOdd);
        else
            signal(ConEven);

        if(buff.getEven()>buff.getOdd())
            signal(ConOE);

        leave();
        return val;
    }

    unsigned char getEven(){
        enter();
        unsigned char val;

        if(buff.getSize()==0)
            wait(ConBuff);

        if(buff.peek()%2)
            wait(ConEven);

        if(buff.getSize()<=2)
            wait(ConS2);

        val = buff.get();

        if(buff.peek()%2)
            signal(ConOdd);
        else
            signal(ConEven);

        if(buff.getSize()>2)
            signal(ConS2);

        if(buff.getSize()>6)
            signal(ConS6);

        if(buff.getEven()<10)
            signal(Con10E);

        leave();
        return val;
    }

    void printFab(){
        enter();
        buff.printBuff();
        leave();
    }
};

#endif //SOIZ4_FABRYKA_H

