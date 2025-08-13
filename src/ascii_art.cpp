#include<iostream>
#include<fstream>
#include<string>

void displayLogo(const std::string& distro){
    std::string logoPath = "logos/"+distro+".txt";
    std::ifstream file(logoPath);
    if(file.is_open()){
        std::string line;
        while(getline(file,line)){
            std::cout<<line<<std::endl;
        }
    }
    else{
        std::cout<<"Logo not found for "<<distro<<"!\n";
    }
}