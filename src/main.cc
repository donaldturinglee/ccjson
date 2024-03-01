#include "json.h"
#include "int.h"
#include "object.h"
#include "string.h"
#include "float.h"
#include "bool.h"
#include "array.h"

#include <iostream>

using json = std::unique_ptr<ccjson::Json>;
template <typename T>
json make_json(T&& value) {
    return std::make_unique<T>(std::forward<T>(value));
}

int main(int argc, char* argv[]) {

    ccjson::Object obj;
    obj.get_object()["name"] = make_json<ccjson::String>(std::string("Lee"));
    obj.get_object()["age"] = make_json<ccjson::Int>(26);
    obj.get_object()["wallet"] = make_json<ccjson::Float>(0.0);
    obj.get_object()["student"] = make_json<ccjson::Bool>(false);

    ccjson::Array list;
    list.get_array().push_back(make_json<ccjson::Int>(1));
    list.get_array().push_back(make_json<ccjson::Int>(2));
    list.get_array().push_back(make_json<ccjson::Int>(3));

    obj.get_object()["list"] = make_json<ccjson::Array>(std::move(list));

    json j = make_json<ccjson::Object>(std::move(obj));

    std::cout << j->to_string() << '\n';

    return 0;
}
