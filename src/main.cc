#include "ccjson.h"

using namespace ccjson;

int main(int argc, char* argv[]) {

    Json json = Object();
    json["name"] = "Lee";

    json["list"] = Array();
    json["list"].push(1);
    json["list"].push(2);


    json["object"] = Object();
    json["object"]["group"] = "backend";

    std::cout << json << '\n';

    return 0;
}
