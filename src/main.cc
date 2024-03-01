#include "json.h"
#include "int.h"
#include "object.h"
#include "string.h"
#include "float.h"
#include "bool.h"
#include "array.h"

#include "utility.h"

using namespace ccjson;

#include <iostream>

int main(int argc, char* argv[]) {

    ccjson::Object obj;
    obj["name"] = make_json<ccjson::String>(std::string("Lee"));
    obj["age"] = make_json<ccjson::Int>(26);
    obj["wallet"] = make_json<ccjson::Float>(0.0);

    json j = make_json<ccjson::Object>(std::move(obj));

    std::cout << j->to_string() << '\n';

    return 0;
}
