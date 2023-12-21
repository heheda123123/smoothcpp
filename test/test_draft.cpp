#include <iostream>
#include <iomanip>
#include <scpp/string/string.h>

void hexdump(const std::string& str) {
    int count = 0;
    for (unsigned char c : str) {
        if (count % 16 == 0) {
            if (count != 0) {
                std::cout << "  " << std::string(16, ' ') << "  ";
                for (int i = count - 16; i < count; ++i) {
                    if (isprint(str[i])) {
                        std::cout << str[i];
                    } else {
                        std::cout << ".";
                    }
                }
                std::cout << std::endl;
            }
            std::cout << "  ";
        }
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)c << " ";
        ++count;
    }
    if (count % 16 != 0) {
        int spaces = (16 - (count % 16)) * 3;
        if (count % 16 <= 8) {
            spaces += 2;
        }
        std::cout << std::string(spaces, ' ');
    }
    std::cout << "  " << std::string(16 - (count % 16), ' ') << "  ";
    for (int i = count - (count % 16); i < count; ++i) {
        if (isprint(str[i])) {
            std::cout << str[i];
        } else {
            std::cout << ".";
        }
    }
    std::cout << std::endl;
}

int main() {
    std::string data = "heheda我是小猪ni123";
    hexdump(data);
    std::string data1 = scpp::gbk2utf8(data);
    hexdump(data1);
    std::string data2 = scpp::utf82gbk(data1);
    hexdump(data2);
    return 0;
}