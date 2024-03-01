#ifndef BOOL_H
#define BOOL_H

#include <memory>
#include "json.h"

namespace ccjson {
    class Bool : public Json {
    public:
        Bool();
        Bool(JSON_BOOL value);
        Bool(const Bool& source);
        Bool(Bool&& source);
        Bool& operator=(const Bool& source);
        Bool& operator=(Bool&& source);
        ~Bool() = default;

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
            throw std::runtime_error("Cannot convert bool to array");
        }
        virtual const JSON_OBJECT& get_object() const override {
            throw std::runtime_error("Cannot convert bool to object");
        }
        virtual JSON_FLOAT get_float() const override {
            throw std::runtime_error("Cannot convert bool to float");
        }
        virtual JSON_INT get_int() const override {
            throw std::runtime_error("Cannot convert bool to int");
        }
        virtual JSON_STRING get_string() const override {
            throw std::runtime_error("Cannot convert bool to string");
        }
        virtual JSON_BOOL get_bool() const override {
            return value_;
        }

        virtual JSON_ARRAY& get_array() override {
            throw std::runtime_error("Cannot convert bool to array");
        }
        virtual JSON_OBJECT& get_object() override {
            throw std::runtime_error("Cannot convert bool to object");
        }
        virtual JSON_FLOAT& get_float() override {
            throw std::runtime_error("Cannot convert bool to float");
        }
        virtual JSON_INT& get_int() override {
            throw std::runtime_error("Cannot convert bool to int");
        }
        virtual JSON_STRING& get_string() override {
            throw std::runtime_error("Cannot convert bool to string");
        }
        virtual JSON_BOOL& get_bool() override {
            return value_;
        }
            
    private:
        JSON_BOOL value_;
    };
} // namespace ccjson

#endif // BOOL_H
