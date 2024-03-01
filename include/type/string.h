#ifndef STRING_H
#define STRING_H

#include <memory>
#include <json.h>

namespace ccjson {
    class String : public Json {
    public:
        String();
        String(const JSON_STRING& value);
        String(const String& source);
        String(String&& source);
        String& operator=(const String& source);
        String& operator=(String&& source);
        ~String() = default;

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
            throw std::runtime_error("Cannot convert string to array");
        }
        virtual const JSON_OBJECT& get_object() const override {
            throw std::runtime_error("Cannot convert string to object");
        }
        virtual JSON_FLOAT get_float() const override {
            throw std::runtime_error("Cannot convert string to float");
        }
        virtual JSON_INT get_int() const override {
            throw std::runtime_error("Cannot convert string to int");
        }
        virtual JSON_STRING get_string() const override {
            return value_;
        }
        virtual JSON_BOOL get_bool() const override {
            throw std::runtime_error("Cannot convert string to boolean");
        }

        virtual JSON_ARRAY& get_array() override {
            throw std::runtime_error("Cannot convert string to array");
        }
        virtual JSON_OBJECT& get_object() override {
            throw std::runtime_error("Cannot convert string to object");
        }
        virtual JSON_FLOAT& get_float() override {
            throw std::runtime_error("Cannot convert string to float");
        }
        virtual JSON_INT& get_int() override {
            throw std::runtime_error("Cannot convert string to int");
        }
        virtual JSON_STRING& get_string() override {
            return value_;
        }
        virtual JSON_BOOL& get_bool() override {
            throw std::runtime_error("Cannot convert string to boolean");
        }
    private:
        JSON_STRING value_;
    };
} // namespace ccjson

#endif // STRING_H
