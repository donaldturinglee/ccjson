#ifndef STRING_H
#define STRING_H

#include <memory>
#include <json.h>

namespace ccjson {
    class String : public JsonBase {
    public:
        String();
        String(const JSON_STRING& value);
        String(const String& source);
        String(String&& source);
        String& operator=(const String& source);
        String& operator=(String&& source);
        virtual ~String() = default;

        virtual std::string to_string(int indent = 0, int base_indent = 0) const override;
        
        // array
        virtual const JSON_TYPE& operator[](size_t index) const override {
            throw std::runtime_error("Cannot use operator[] on string");
        }
        virtual JSON_TYPE& operator[](size_t index) override {
            throw std::runtime_error("Cannot use operator[] on string");
        }
        virtual void push(JSON_TYPE&& value) override {
            throw std::runtime_error("Cannot use push() on string");
        }
        virtual void insert(size_t index, JSON_TYPE&& value) override {
            throw std::runtime_error("Cannot use insert() on string");
        }
        virtual void erase(size_t index) override {
            throw std::runtime_error("Cannot use erase() on string");
        }
        virtual const JSON_TYPE& at(size_t index) const override {
            throw std::runtime_error("Cannot use at() on string");
        }
        virtual JSON_TYPE& at(size_t index) override {
            throw std::runtime_error("Cannot use at() on string");
        }
        virtual const JSON_TYPE& front() const override {
            throw std::runtime_error("Cannot use front() on string");
        }
        virtual JSON_TYPE& front() override {
            throw std::runtime_error("Cannot use front() on string");
        }
        virtual const JSON_TYPE& back() const override {
            throw std::runtime_error("Cannot use back() on string");
        }
        virtual JSON_TYPE& back() override {
            throw std::runtime_error("Cannot use back() on string");
        }

        // object
        virtual const JSON_TYPE& operator[](const std::string& key) const override {
            throw std::runtime_error("Cannot use operator[] on string");
        }
        virtual JSON_TYPE& operator[](const std::string& key) override {
            throw std::runtime_error("Cannot use operator[] on string");
        }
        virtual const JSON_TYPE& operator[](const char* key) const override {
            throw std::runtime_error("Cannot use operator[] on string");
        }
        virtual JSON_TYPE& operator[](const char* key) override {
            throw std::runtime_error("Cannot use operator[] on string");
        }
        virtual void insert(const std::string& key, JSON_TYPE&& value) override {
            throw std::runtime_error("Cannot use insert() on string");
        }
        virtual bool contains(const std::string& key) const override {
            throw std::runtime_error("Cannot use contains() on string");
        }
        virtual void erase(const std::string& key) override {
            throw std::runtime_error("Cannot use erase() on string");
        }
        virtual const JSON_TYPE& at(const std::string& key) const override {
            throw std::runtime_error("Cannot use at() on string");
        }
        virtual JSON_TYPE& at(const std::string& key) override {
            throw std::runtime_error("Cannot use at() on string");
        }

        // both array and object
        virtual void clear() override {
            throw std::runtime_error("Cannot use clear() on string");
        }
        virtual size_t size() const override {
            throw std::runtime_error("Cannot use size() on string");
        }
        virtual bool empty() const override {
            throw std::runtime_error("Cannot use empty() on string");
        }

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
