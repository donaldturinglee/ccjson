#include "json.h"
#include "int.h"
#include "object.h"
#include "string.h"
#include "float.h"
#include "bool.h"
#include "array.h"

#include <iostream>

using json = ccjson::Json;

int main(int argc, char* argv[]) {

    ccjson::Object obj;
    obj.get_object()["name"] = std::make_unique<ccjson::String>("Lee");
    obj.get_object()["age"] = std::make_unique<ccjson::Int>(26);
    obj.get_object()["wallet"] = std::make_unique<ccjson::Float>(0.0);
    obj.get_object()["student"] = std::make_unique<ccjson::Bool>(false);

    ccjson::Array list;
    list.get_array().push_back(std::make_unique<ccjson::Int>(1));
    list.get_array().push_back(std::make_unique<ccjson::Int>(2));
    list.get_array().push_back(std::make_unique<ccjson::Int>(3));

    obj.get_object()["list"] = std::make_unique<ccjson::Array>(list);

    std::unique_ptr<json> j = std::make_unique<ccjson::Object>(obj);

    std::cout << j->to_string() << '\n';

    return 0;
}
