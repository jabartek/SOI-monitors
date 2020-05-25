#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc50-cpp"
#pragma clang diagnostic ignored "-Wmissing-noreturn"

#ifndef SOIZ4_PROCESY_H
#define SOIZ4_PROCESY_H

#include "Fabryka.h"
void ProcA1(int procId, Fabryka* fab, bool randTime){
    for(unsigned char i = 0; ;i+=2){
        i%=100;
        std::cout<<"A1_"<<procId<<" chce wstawic "<<(unsigned short)i<<std::endl;
        fab->put(i);
        std::cout<<"A1_"<<procId<<" wstawilo "<<(unsigned short)i<<" do bufora"<<std::endl;
        fab->printFab();
        std::this_thread::sleep_for(std::chrono::milliseconds(!randTime ? 200 : rand() % 200));
    }
}

void ProcA2(int procId, Fabryka* fab, bool randTime){
    for(unsigned char i = 1; ;i+=2){
        i%=100;
        std::cout<<"A2_"<<procId<<" chce wstawic "<<(unsigned short)i<<std::endl;
        fab->put(i);
        std::cout<<"A2_"<<procId<<" wstawilo "<<(unsigned short)i<<" do bufora"<<std::endl;
        fab->printFab();
        std::this_thread::sleep_for(std::chrono::milliseconds(!randTime ? 200 : rand() % 200));
    }
}

void ProcB1(int procId, Fabryka* fab, bool randTime){
    for(;;){
        std::cout<<"B1_"<<procId<<" chce wyjac parzysta"<<std::endl;
        unsigned char val = fab->getEven();
        std::cout<<"B1_"<<procId<<" Wyjelo "<<(unsigned short)val<<" z bufora"<<std::endl;
        fab->printFab();
        std::this_thread::sleep_for(std::chrono::milliseconds(!randTime ? 200 : rand() % 200));
    }
}

void ProcB2(int procId, Fabryka* fab, bool randTime){
    for(;;){
        std::cout<<"B2_"<<procId<<" chce wyjac nieparzysta"<<std::endl;
        unsigned char val = fab->getOdd();
        std::cout<<"B2_"<<procId<<" Wyjelo "<<(unsigned short)val<<" z bufora"<<std::endl;
        fab->printFab();
        std::this_thread::sleep_for(std::chrono::milliseconds(!randTime ? 200 : rand() % 200));
    }
}

#endif //SOIZ4_PROCESY_H

#pragma clang diagnostic pop