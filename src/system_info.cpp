#include<iostream>
#include<fstream>
#include<string>
#include<sys/utsname.h>
#include <unistd.h> // for sysconf
#include <sys/sysinfo.h> // For sysinfo
#include <cstdlib>
#include <cstdio>
#include <memory>
#include <array>
#include <sstream>



std::string getOSInfo(){
    struct utsname sysInfo;
    std::string osName;
    if(uname(&sysInfo) == 0){
        osName =  sysInfo.sysname;
    }
    else {
        std::cerr << "Failed to get OS information." << std::endl;
    }

    return osName;
    

}

std::string getName(){
    std::ifstream file("/etc/os-release");
    std::string line;
    std::string name;
    while (std::getline(file, line)) {
        if (line.find("NAME=") != std::string::npos ) {
            if(line.find("PRETTY_NAME=") != std::string::npos) continue;
            name = line.substr(line.find("=")+2);
            name.pop_back();
            break;
        }
    }
    return name;
}

std::string getNodeName(){
    struct utsname sysInfo;
    std::string nodeName;
    if(uname(&sysInfo) == 0){
        nodeName = sysInfo.nodename;
    }
    else {
        std::cerr << "Failed to get node information." << std::endl;
    }
    return nodeName;
}
std::string getKernelInfo(){
    struct utsname sysInfo;
    std::string kernelName;

    if(uname(&sysInfo) == 0){
        kernelName =  sysInfo.release;
    }
    else {
        std::cerr << "Failed to get kernel information." << std::endl;
    }
    return kernelName;
}

std::string getUptime() {
    struct sysinfo info;
    double uptime;
    if (sysinfo(&info) == 0) {
        uptime = info.uptime;
    } else {
        std::cerr << "Failed to get uptime information." << std::endl;
    }
    
    int hours = static_cast<int>(uptime) / 3600;
    int minutes = (static_cast<int>(uptime) % 3600) / 60;
    return std::to_string(hours) + "h " + std::to_string(minutes) + "m";
    
}
std::string trimLeadingSpaces(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\n\r");
    return (start == std::string::npos) ? "" : str.substr(start);
}

std::string getCPUInfo() {
    std::array<char, 128> buffer;
    std::string result;
    
    // Open a pipe to execute the command
    auto pipe = std::unique_ptr<FILE, decltype(&pclose)>(popen("lscpu | grep 'Model name'", "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }

    // Read the output line
    if (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result = buffer.data();
    }

    // Extract the CPU model name from the output
    size_t colonPos = result.find(":");
    if (colonPos != std::string::npos) {
        result = result.substr(colonPos + 2); // Remove "Model name: " prefix
    }
    result = trimLeadingSpaces(result);
    return result;
}

std::string getMemoryInfo() {
    struct sysinfo info;
    std::string memTotal{""};
    std::string memAvailable{""};
    if (sysinfo(&info) == 0) {
        auto tRam = info.totalram / (1024 * 1024);
        memTotal = std::to_string(tRam)+" MB";
        auto fRam = info.freeram / (1024 * 1024);
        memAvailable = std::to_string(fRam)+ " MB"; 
        
    } else {
        std::cerr << "Failed to get system memory information." << std::endl;
    }
    return "Total: " + memTotal + " Available: " + memAvailable;
}


