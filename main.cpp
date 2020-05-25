#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc50-cpp"
#include <iostream>
#include <thread>
#include "Procesy.h"

int main() {
    unsigned int a1, a2, b1, b2;
    bool randTime;
    std::cout<<"Please enter the number of respective processes to spawn\nA1\tA2\tB1\tB2\n";
    std::cin>>a1>>a2>>b1>>b2;
    std::cout<<"Use random timing (0-200ms)? (0-N, 1-Y)\n";
    std::cin>>randTime;
    auto* fab = new Fabryka;
    std::vector<std::thread> vP;

    for(unsigned int i=0; i<a1; i++){
        vP.emplace_back(std::thread(ProcA1, i+1, fab, randTime));
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 100));
    }

    for(unsigned int i=0; i<a2; i++){
        vP.emplace_back(std::thread(ProcA2, i+1, fab, randTime));
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 100));
    }

    for(unsigned int i=0; i<b1; i++){
        vP.emplace_back(std::thread(ProcB1, i+1, fab, randTime));
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 100));
    }

    for(unsigned int i=0; i<b2; i++){
        vP.emplace_back(std::thread(ProcB2, i+1, fab, randTime));
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 100));
    }

    for(auto & t : vP){
        t.join();
    }

    return 1;
}
#pragma clang diagnostic pop