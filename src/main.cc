#include "utility.h"

using namespace ccjson;

#include <iostream>

int main(int argc, char* argv[]) {

    json j = make_json<ccjson::Object>();
    j["name"] = make_json<ccjson::String>(std::string("Lee"));
    j["age"] = make_json<ccjson::Int>(26);
    j["wallet"] = make_json<ccjson::Float>(0.0);

    ccjson::Array list;
    list.push(make_json<ccjson::Int>(1));
    list.push(make_json<ccjson::Int>(2));


    ccjson::Object obj;
    obj["value"] = make_json<ccjson::Float>(42.99);

    j["obj"] = make_json<ccjson::Object>(std::move(obj));
    j["list"] = make_json<ccjson::Array>(std::move(list));

    std::cout << j << '\n';

    return 0;
}
