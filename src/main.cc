#include "utility.h"

using namespace ccjson;

#include <iostream>

int main(int argc, char* argv[]) {

    ccjson::Object obj;
    obj["name"] = make_json<ccjson::String>(std::string("Lee"));
    obj["age"] = make_json<ccjson::Int>(26);
    obj["wallet"] = make_json<ccjson::Float>(0.0);

    json j = make_json<ccjson::Object>(std::move(obj));
    std::cout << *j << '\n';

    return 0;
}
