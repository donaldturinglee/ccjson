#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <map>

#include "json.h"
#include "type.h"
#include "array.h"
#include "object.h"
#include "bool.h"
#include "float.h"
#include "int.h"
#include "string.h"

namespace ccjson {
    using json = JSON_TYPE;
    template<typename T>
    json make_json(T&& value) {
        return std::make_unique<T>(std::forward<T>(value));
    }
} // namespace ccjson

#endif // UTILITY_H