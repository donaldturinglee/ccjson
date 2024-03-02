#include "null.h"

using namespace ccjson;

std::string Null::to_string(int indent, int base_indent) const {
    return "null";
}
