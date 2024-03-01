#ifndef ARRAY_H
#define ARRAY_H

#include <memory>
#include "json.h"

namespace ccjson {

    class Array : public Json {
    public:
        Array();
        Array(const JSON_ARRAY& value) = delete;
        Array(JSON_ARRAY&& value);
        Array(const Array& source) = delete;
        Array(Array&& source);
        Array& operator=(const Array& source) = delete;
        Array& operator=(Array&& source);
        virtual ~Array() = default;

        virtual std::string to_string(int indent = -1) const override;

        virtual const JSON_TYPE& operator[](const std::string& key) const override {
            throw std::runtime_error("Cannot use string as array index");
        }
        virtual const JSON_TYPE& operator[](const char* key) const override {
             throw std::runtime_error("Cannot use string as array index");
        }
        virtual const JSON_TYPE& operator[](size_t index) const override {
            return value_.at(index);
        }

        virtual JSON_TYPE& operator[](const std::string& key) override {
            throw std::runtime_error("Cannot use string as array index");
        }
        virtual JSON_TYPE& operator[](const char* key) override {
            throw std::runtime_error("Cannot use string as array index");
        }
        virtual JSON_TYPE& operator[](size_t index) override {
            return value_.at(index);
        }

        virtual Json& operator=(const Json& source) override;
        virtual Json& operator=(Json&& source) override;

        virtual const JSON_ARRAY& get_array() const override {
            return value_;
        }
        virtual const JSON_OBJECT& get_object() const override {
            throw std::runtime_error("Cannot convert array to object");
        }
        virtual JSON_FLOAT get_float() const override {
            throw std::runtime_error("Cannot convert array to float");
        }
        virtual JSON_INT get_int() const override {
            throw std::runtime_error("Cannot convert array to int");
        }
        virtual JSON_STRING get_string() const override {
            throw std::runtime_error("Cannot convert array to string");
        }
        virtual JSON_BOOL get_bool() const override {
            throw std::runtime_error("Cannot convert array to bool");
        }

        virtual JSON_ARRAY& get_array() override {
            return value_;
        }
        virtual JSON_OBJECT& get_object() override {
            throw std::runtime_error("Cannot convert array to object");
        }
        virtual JSON_FLOAT& get_float() override {
            throw std::runtime_error("Cannot convert array to float");
        }
        virtual JSON_INT& get_int() override {
            throw std::runtime_error("Cannot convert array to int");
        }
        virtual JSON_STRING& get_string() override {
            throw std::runtime_error("Cannot convert array to string");
        }
        virtual JSON_BOOL& get_bool() override {
            throw std::runtime_error("Cannot convert array to bool");
        }
    private:
        JSON_ARRAY value_;
    };
} // namespace ccjson

#endif // ARRAY_H
