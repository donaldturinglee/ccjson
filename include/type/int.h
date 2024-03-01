#ifndef INT_H
#define INT_H

#include "json.h"
#include <memory>

namespace ccjson {
    class Int : public Json {
    public:
        Int();
        Int(JSON_INT value);
        Int(const Int& source);
        Int(Int&& source);
        Int& operator=(const Int& source);
        Int& operator=(Int&& source);
        virtual ~Int() = default;

        virtual std::string to_string(int indent = -1) const override;

        virtual const Json& operator[](const std::string& key) const override {
            throw std::runtime_error("Cannot use index operator in a non-iterable type");
        }
        virtual const Json& operator[](const char* key) const override {
            throw std::runtime_error("Cannot use index operator in a non-iterable type");
        }
        virtual const Json& operator[](size_t index) const override {
            throw std::runtime_error("Cannot use index operator in a non-iterable type");
        }

        virtual Json& operator[](const std::string& key) override {
            throw std::runtime_error("Cannot use index operator in a non-iterable type");
        }
        virtual Json& operator[](const char* key) override {
            throw std::runtime_error("Cannot use index operator in a non-iterable type");
        }
        virtual Json& operator[](size_t index) override {
            throw std::runtime_error("Cannot use index operator in a non-iterable type");
        }

        virtual Json& operator=(const Json& source) override;
        virtual Json& operator=(Json&& source) override;

        virtual const JSON_ARRAY& get_array() const override {
            throw std::runtime_error("Cannot convert int to array");
        }
        virtual const JSON_OBJECT& get_object() const override {
            throw std::runtime_error("Cannot convert int to object");
        }
        virtual JSON_FLOAT get_float() const override {
            throw std::runtime_error("Cannot convert int to float");
        }
        virtual JSON_INT get_int() const override {
            return value_;
        }
        virtual JSON_STRING get_string() const override {
            throw std::runtime_error("Cannot convert int to string");
        }
        virtual JSON_BOOL get_bool() const override {
            throw std::runtime_error("Cannot convert int to boolean");
        }

        virtual JSON_ARRAY& get_array() override {
            throw std::runtime_error("Cannot convert int to array");
        }
        virtual JSON_OBJECT& get_object() override {
            throw std::runtime_error("Cannot convert int to object");
        }
        virtual JSON_FLOAT& get_float() override {
            throw std::runtime_error("Cannot convert int to float");
        }
        virtual JSON_INT& get_int() override {
            return value_;
        }
        virtual JSON_STRING& get_string() override {
            throw std::runtime_error("Cannot convert int to string");
        }
        virtual JSON_BOOL& get_bool() override {
            throw std::runtime_error("Cannot convert int to boolean");
        }

    private:
        JSON_INT value_;
        
    };
} // namespace ccjson

#endif // INT_H
