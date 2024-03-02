#include "utility.h"

using namespace ccjson;

#include <iostream>

int main(int argc, char* argv[]) {
    
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

    std::cout << j << '\n';

    float wallet{j["wallet"]};
    std::cout << wallet << '\n';
    
    return 0;
}
