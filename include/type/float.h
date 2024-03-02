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

        // array
        virtual const JSON_TYPE& operator[](size_t index) const override {
            throw std::runtime_error("Cannot use operator[] on float");
        }
        virtual JSON_TYPE& operator[](size_t index) override {
            throw std::runtime_error("Cannot use operator[] on float");
        }
        virtual void push(JSON_TYPE&& value) override {
            throw std::runtime_error("Cannot use push() on float");
        }
        virtual void insert(size_t index, JSON_TYPE&& value) override {
            throw std::runtime_error("Cannot use insert() on float");
        }
        virtual void erase(size_t index) override {
            throw std::runtime_error("Cannot use erase() on float");
        }
        virtual const JSON_TYPE& at(size_t index) const override {
            throw std::runtime_error("Cannot use at() on float");
        }
        virtual JSON_TYPE& at(size_t index) override {
            throw std::runtime_error("Cannot use at() on float");
        }
        virtual const JSON_TYPE& front() const override {
            throw std::runtime_error("Cannot use front() on float");
        }
        virtual JSON_TYPE& front() override {
            throw std::runtime_error("Cannot use front() on float");
        }
        virtual const JSON_TYPE& back() const override {
            throw std::runtime_error("Cannot use back() on float");
        }
        virtual JSON_TYPE& back() override {
            throw std::runtime_error("Cannot use back() on float");
        }

        // object
        virtual const JSON_TYPE& operator[](const std::string& key) const override {
            throw std::runtime_error("Cannot use operator[] on float");
        }
        virtual JSON_TYPE& operator[](const std::string& key) override {
            throw std::runtime_error("Cannot use operator[] on float");
        }
        virtual const JSON_TYPE& operator[](const char* key) const override {
            throw std::runtime_error("Cannot use operator[] on float");
        }
        virtual JSON_TYPE& operator[](const char* key) override {
            throw std::runtime_error("Cannot use operator[] on float");
        }
        virtual void insert(const std::string& key, JSON_TYPE&& value) override {
            throw std::runtime_error("Cannot use insert() on float");
        }
        virtual bool contains(const std::string& key) const override {
            throw std::runtime_error("Cannot use contains() on float");
        }
        virtual void erase(const std::string& key) override {
            throw std::runtime_error("Cannot use erase() on float");
        }
        virtual const JSON_TYPE& at(const std::string& key) const override {
            throw std::runtime_error("Cannot use at() on float");
        }
        virtual JSON_TYPE& at(const std::string& key) override {
            throw std::runtime_error("Cannot use at() on float");
        }

        // both array and object
        virtual void clear() override {
            throw std::runtime_error("Cannot use clear() on float");
        }
        virtual size_t size() const override {
            throw std::runtime_error("Cannot use size() on float");
        }
        virtual bool empty() const override {
            throw std::runtime_error("Cannot use empty() on float");
        }

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
