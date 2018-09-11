#include<iostream>
#include<fstream>
int main() {
    std::ofstream file("/tmp/file.txt", std::ios::out|std::ios::ate);
    if (!file) {
        std::cout<<"Can not open file!"<<std::endl;
    }
    else {
        file<<"Test write file!\n";
        file.close();
    }
}
