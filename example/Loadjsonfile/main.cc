
#include <iostream>

#include "jsontool.h"

int main(){
    std::cout << "hello world" << std::endl;
    Json::Value value;
    Loadjsonfile("./data.json", value);
    std::cout << "end" << std::endl;
    return 0;
}
