#include "json/json.h"
#include <iostream>
#include <memory>
/** \brief Write the Value object to a stream.
 * Example Usage:
 * $g++ streamWrite.cpp -ljsoncpp -std=c++11 -o streamWrite
 * $./streamWrite
 * {
 *     "Age" : 20,
 *     "Name" : "robin"
 * }
 */

int main() {

    Json::Value root;
    Json::StreamWriterBuilder builder;
    const std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());

    root["Name"] = "robin";
    root["Age"] = 20;
    root["lession"]["class"] = "化学";
    root["lession"]["section"] = "高中";
    root["scope"].append(123);
    root["scope"].append(234);
    writer->write(root, &std::cout);

    return EXIT_SUCCESS;
}
