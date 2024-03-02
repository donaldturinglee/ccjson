#ifndef OBJECT_H
#define OBJECT_H

#include "json.h"
#include <memory>

namespace ccjson {
    class Object : public Json {
    public:
        Object();
        Object(const JSON_OBJECT& value) = delete;
        Object(JSON_OBJECT&& value);
        Object(const Object& source) = delete;
        Object(Object&& source);
        Object& operator=(const Object& source) = delete;
        Object& operator=(Object&& source);
        virtual ~Object() = default;

        virtual std::string to_string(int indent = 0, int base_indent = 0) const override;

        // array
        virtual const JSON_TYPE& operator[](size_t index) const override {
            throw std::runtime_error("Cannot use int as object key");
        }
        virtual JSON_TYPE& operator[](size_t index) override {
            throw std::runtime_error("Cannot use int as object key");
        }
        virtual void push(JSON_TYPE&& value) override {
            throw std::runtime_error("Cannot use push() on object");
        }
        virtual void insert(size_t index, JSON_TYPE&& value) override {
            throw std::runtime_error("Cannot use insert() on object");
        }
        virtual void erase(size_t index) override {
            throw std::runtime_error("Cannot use erase() on object");
        }
        virtual const JSON_TYPE& at(size_t index) const override {
            throw std::runtime_error("Cannot use int as object key");
        }
        virtual JSON_TYPE& at(size_t index) override {
            throw std::runtime_error("Cannot use int as object key");
        }
        virtual const JSON_TYPE& front() const override {
            throw std::runtime_error("Cannot use front() on object");
        }
        virtual JSON_TYPE& front() override {
            throw std::runtime_error("Cannot use front() on object");
        }
        virtual const JSON_TYPE& back() const override {
            throw std::runtime_error("Cannot use back() on object");
        }
        virtual JSON_TYPE& back() override {
            throw std::runtime_error("Cannot use back() on object");
        }

        // object
        virtual const JSON_TYPE& operator[](const std::string& key) const override {
            return value_.at(key);
        }
        virtual JSON_TYPE& operator[](const std::string& key) override {
            return value_[key];
        }
        virtual const JSON_TYPE& operator[](const char* key) const override {
            return value_.at(key);
        }
        virtual JSON_TYPE& operator[](const char* key) override {
            return value_[key];
        }
        virtual void insert(const std::string& key, JSON_TYPE&& value) override {
            value_.insert(std::make_pair(key, std::move(value)));
        }
        virtual bool contains(const std::string& key) const override {
            return value_.find(key) != value_.end();
        }
        virtual void erase(const std::string& key) override {
            value_.erase(key);
        }
        virtual const JSON_TYPE& at(const std::string& key) const override {
            return value_.at(key);
        }
        virtual JSON_TYPE& at(const std::string& key) override {
            return value_.at(key);
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
            throw std::runtime_error("Cannot convert object to array");
        }
        virtual const JSON_OBJECT& get_object() const override {
            return value_;
        }
        virtual JSON_FLOAT get_float() const override {
            throw std::runtime_error("Cannot convert object to float");
        }
        virtual JSON_INT get_int() const override {
            throw std::runtime_error("Cannot convert object to int");
        }
        virtual JSON_STRING get_string() const override {
            throw std::runtime_error("Cannot convert object to string");
        }
        virtual JSON_BOOL get_bool() const override {
            throw std::runtime_error("Cannot convert object to boolean");
        }

        virtual JSON_ARRAY& get_array() override {
            throw std::runtime_error("Cannot convert object to array");
        }
        virtual JSON_OBJECT& get_object() override {
            return value_;
        }
        virtual JSON_FLOAT& get_float() override {
            throw std::runtime_error("Cannot convert object to float");
        }
        virtual JSON_INT& get_int() override {
            throw std::runtime_error("Cannot convert object to int");
        }
        virtual JSON_STRING& get_string() override {
            throw std::runtime_error("Cannot convert object to string");
        }
        virtual JSON_BOOL& get_bool() override {
            throw std::runtime_error("Cannot convert object to boolean");
        }
    private:
        JSON_OBJECT value_;
    };
} // namespace ccjson

#endif // OBJECT_H
