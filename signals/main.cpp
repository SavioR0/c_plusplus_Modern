#include <iostream>
#include <csignal>

void functionSignal(int signal_num){
    std::cout << "\n  ====== Para encerrar, precione CTRL + C =======" << std::endl;
    std::signal(SIGINT, std::exit ); 
}

int main() {
    int times = 0;
    std::signal(SIGINT, functionSignal);
    std::cout << "Tente encerrar esse processo..." << std::endl;
    while (true) {}
    return 0;
}