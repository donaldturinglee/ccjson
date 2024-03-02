#include "utility.h"

using namespace ccjson;

#include <iostream>

int main(int argc, char* argv[]) {
    
    {
        std::ifstream ifs("tests/test.json");
        try {
            json test = json::parse(ifs);
            std::cout << test.to_string(4) << '\n';
        } catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }

    {
        try {
            json test = json::parse(R"({"name": "Lee"})");
            std::cout << test.to_string(4) << '\n';
        } catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }

    json j = make_json<ccjson::Object>();
    j["name"] = "Lee";
    j["age"] = 26;
    j["wallet"] = 1.234f;
    j["nothing"] = nullptr;

    json list = make_json<ccjson::Array>();
    list.push(1);
    list.push(2);
    list.push(3);
    j["list"] = std::move(list);

    json obj = make_json<ccjson::Object>();
    obj["version"] = "0.0.1";
    j["object"] = std::move(obj);

    std::cout << j.to_string(4) << '\n';

    return 0;
}
