#pragma once

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <json/json.h>

using namespace std;

bool Loadjsonfile(string name, Json::Value& jsonroot){

    std::stringstream buffer;

    {
        std::ifstream ifs;
        ifs.open(name);
        buffer << ifs.rdbuf();
        ifs.close();
    }

    auto str = buffer.str();
    Json::Reader reader;
    if(reader.parse(str, jsonroot))
        return false;

    return true;        
}
