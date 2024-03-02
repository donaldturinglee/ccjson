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

        // array
        virtual const JSON_TYPE& operator[](size_t index) const override {
            return value_[index];
        }
        virtual JSON_TYPE& operator[](size_t index) override {
            return value_[index];
        }
        virtual void push(JSON_TYPE&& value) override {
            value_.push_back(std::move(value));
        }
        virtual void insert(size_t index, JSON_TYPE&& value) override {
            value_.insert(value_.begin() + index, std::move(value));
        }
        virtual void erase(size_t index) override {
            value_.erase(value_.begin() + index);
        }
        virtual const JSON_TYPE& at(size_t index) const override {
            return value_.at(index);
        }
        virtual JSON_TYPE& at(size_t index) override {
            return value_.at(index);
        }
        virtual const JSON_TYPE& front() const override {
            return value_.front();
        }
        virtual JSON_TYPE& front() override {
            return value_.front();
        }
        virtual const JSON_TYPE& back() const override {
            return value_.back();
        }
        virtual JSON_TYPE& back() override {
            return value_.back();
        }

        // object
        virtual const JSON_TYPE& operator[](const std::string& key) const override {
            throw std::runtime_error("Cannot use string as array index");
        }
        virtual JSON_TYPE& operator[](const std::string& key) override {
            throw std::runtime_error("Cannot use string as array index");
        }
        virtual const JSON_TYPE& operator[](const char* key) const override {
            throw std::runtime_error("Cannot use string as array index");
        }
        virtual JSON_TYPE& operator[](const char* key) override {
            throw std::runtime_error("Cannot use string as array index");
        }
        virtual void insert(const std::string& key, JSON_TYPE&& value) override {
            throw std::runtime_error("Cannot use insert() on array");
        }
        virtual bool contains(const std::string& key) const override {
            throw std::runtime_error("Cannot use contains() on array");
        }
        virtual void erase(const std::string& key) override {
            throw std::runtime_error("Cannot use erase() on array");
        }
        virtual const JSON_TYPE& at(const std::string& key) const override {
            throw std::runtime_error("Cannot use string as array index");
        }
        virtual JSON_TYPE& at(const std::string& key) override {
            throw std::runtime_error("Cannot use string as array index");
        }

        // both array and object
        virtual void clear() override {
            value_.clear();
        }
        virtual size_t size() const override {
            return value_.size();
        }
        virtual bool empty() const override {
            return value_.empty();
        }

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
