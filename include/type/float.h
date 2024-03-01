#ifndef FLOAT_H
#define FLOAT_H

#include <memory>
#include "json.h"

namespace ccjson {
    class Float : public Json {
    public:
        Float();
        Float(JSON_FLOAT value);
        Float(const Float& source);
        Float(Float&& source);
        Float& operator=(const Float& source);
        Float& operator=(Float&& source);
        virtual ~Float() = default;

        virtual std::string to_string(int indent = -1) const override;

        virtual const JSON_TYPE& operator[](const std::string& key) const override {
            throw std::runtime_error("Cannot use index operator in a non-iterable type");
        }
        virtual const JSON_TYPE& operator[](const char* key) const override {
            throw std::runtime_error("Cannot use index operator in a non-iterable type");
        }
        virtual const JSON_TYPE& operator[](size_t index) const override {
            throw std::runtime_error("Cannot use index operator in a non-iterable type");
        }

        virtual JSON_TYPE& operator[](const std::string& key) override {
            throw std::runtime_error("Cannot use index operator in a non-iterable type");
        }
        virtual JSON_TYPE& operator[](const char* key) override {
            throw std::runtime_error("Cannot use index operator in a non-iterable type");
        }
        virtual JSON_TYPE& operator[](size_t index) override {
            throw std::runtime_error("Cannot use index operator in a non-iterable type");
        }

        virtual Json& operator=(const Json& source) override;
        virtual Json& operator=(Json&& source) override;

        virtual const JSON_ARRAY& get_array() const override {
            throw std::runtime_error("Cannot convert float to array");
        }
        virtual const JSON_OBJECT& get_object() const override {
            throw std::runtime_error("Cannot convert float to object");
        }
        virtual JSON_FLOAT get_float() const override {
            return value_;
        }
        virtual JSON_INT get_int() const override {
            throw std::runtime_error("Cannot convert float to int");
        }
        virtual JSON_STRING get_string() const override {
            throw std::runtime_error("Cannot convert float to string");
        }
        virtual JSON_BOOL get_bool() const override {
            throw std::runtime_error("Cannot convert float to boolean");
        }

        virtual JSON_ARRAY& get_array() override {
            throw std::runtime_error("Cannot convert float to array");
        }
        virtual JSON_OBJECT& get_object() override {
            throw std::runtime_error("Cannot convert float to object");
        }
        virtual JSON_FLOAT& get_float() override {
            return value_;
        }
        virtual JSON_INT& get_int() override {
            throw std::runtime_error("Cannot convert float to int");
        }
        virtual JSON_STRING& get_string() override {
            throw std::runtime_error("Cannot convert float to string");
        }
        virtual JSON_BOOL& get_bool() override {
            throw std::runtime_error("Cannot convert float to boolean");
        }
    private:
        JSON_FLOAT value_;
    };
} // namespace json

#endif // FLOAT_H
