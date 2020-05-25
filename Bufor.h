#ifndef SOIZ4_BUFOR_H
#define SOIZ4_BUFOR_H

class Bufor{
    std::queue<unsigned char> Q;
    unsigned int even=0;
    unsigned int odd=0;
public:
    void put(unsigned char val){
        (val % 2) ? odd++ : even++;
        Q.push(val);
    }
    unsigned char get(){
        unsigned char val = Q.front();
        (val % 2) ? odd-- : even--;
        Q.pop();
        return val;
    }
    unsigned char peek(){
        return Q.front();
    }
    unsigned int getEven(){
        return even;
    }
    unsigned int getOdd(){
        return odd;
    }
    unsigned int getSize(){
        return odd+even;
    }

    void printBuff()
    {
        std::queue<unsigned char> q = Q;
        while (!q.empty())
        {
            std::cout << (unsigned short)q.front() << " ";
            q.pop();
        }
        std::cout << std::endl;
    }
};

#endif //SOIZ4_BUFOR_H
