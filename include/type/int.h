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

        virtual std::string to_string(int indent = 0, int base_indent = 0) const override;

        // array
        virtual const JSON_TYPE& operator[](size_t index) const override {
            throw std::runtime_error("Cannot use operator[] on int");
        }
        virtual JSON_TYPE& operator[](size_t index) override {
            throw std::runtime_error("Cannot use operator[] on int");
        }
        virtual void push(JSON_TYPE&& value) override {
            throw std::runtime_error("Cannot use push() on int");
        }
        virtual void insert(size_t index, JSON_TYPE&& value) override {
            throw std::runtime_error("Cannot use insert() on int");
        }
        virtual void erase(size_t index) override {
            throw std::runtime_error("Cannot use erase() on int");
        }
        virtual const JSON_TYPE& at(size_t index) const override {
            throw std::runtime_error("Cannot use at() on int");
        }
        virtual JSON_TYPE& at(size_t index) override {
            throw std::runtime_error("Cannot use at() on int");
        }
        virtual const JSON_TYPE& front() const override {
            throw std::runtime_error("Cannot use front() on int");
        }
        virtual JSON_TYPE& front() override {
            throw std::runtime_error("Cannot use front() on int");
        }
        virtual const JSON_TYPE& back() const override {
            throw std::runtime_error("Cannot use back() on int");
        }
        virtual JSON_TYPE& back() override {
            throw std::runtime_error("Cannot use back() on int");
        }

        // object
        virtual const JSON_TYPE& operator[](const std::string& key) const override {
            throw std::runtime_error("Cannot use operator[] on int");
        }
        virtual JSON_TYPE& operator[](const std::string& key) override {
            throw std::runtime_error("Cannot use operator[] on int");
        }
        virtual const JSON_TYPE& operator[](const char* key) const override {
            throw std::runtime_error("Cannot use operator[] on int");
        }
        virtual JSON_TYPE& operator[](const char* key) override {
            throw std::runtime_error("Cannot use operator[] on int");
        }
        virtual void insert(const std::string& key, JSON_TYPE&& value) override {
            throw std::runtime_error("Cannot use insert() on int");
        }
        virtual bool contains(const std::string& key) const override {
            throw std::runtime_error("Cannot use contains() on int");
        }
        virtual void erase(const std::string& key) override {
            throw std::runtime_error("Cannot use erase() on int");
        }
        virtual const JSON_TYPE& at(const std::string& key) const override {
            throw std::runtime_error("Cannot use at() on int");
        }
        virtual JSON_TYPE& at(const std::string& key) override {
            throw std::runtime_error("Cannot use at() on int");
        }

        // both array and object
        virtual void clear() override {
            throw std::runtime_error("Cannot use clear() on int");
        }
        virtual size_t size() const override {
            throw std::runtime_error("Cannot use size() on int");
        }
        virtual bool empty() const override {
            throw std::runtime_error("Cannot use empty() on int");
        }

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
