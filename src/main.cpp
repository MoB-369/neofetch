#include<iostream>
#include<fstream>
#include "system_info.h"
#include "ascii_art.h"

int main(){
    std::string name = getName();
  
    displayLogo(name);

    std::cout<<"--------------------------------------------------------\n";
    std::cout<<getNodeName()<<std::endl;
    std::cout<<"--------------------------------------------------------\n";
    std::cout << "OS: " << getOSInfo() << "\n";
    std::cout << "Kernel: " << getKernelInfo() << "\n";
    std::cout << "Uptime: " << getUptime() << "\n";
    std::cout << "CPU: " << getCPUInfo();
    std::cout << "Memory: " << getMemoryInfo() << "\n";

    return 0;

}