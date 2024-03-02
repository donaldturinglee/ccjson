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
        virtual Json& operator=(const Json& source) override;
        virtual Json& operator=(Json&& source) override;
        virtual ~Bool() = default;

        virtual std::string to_string(int indent = -1) const override;

        // array
        virtual const JSON_TYPE& operator[](size_t index) const override {
            throw std::runtime_error("Cannot use operator[] on bool");
        }
        virtual JSON_TYPE& operator[](size_t index) override {
            throw std::runtime_error("Cannot use operator[] on bool");
        }
        virtual void push(JSON_TYPE&& value) override {
            throw std::runtime_error("Cannot use push() on bool");
        }
        virtual void insert(size_t index, JSON_TYPE&& value) override {
            throw std::runtime_error("Cannot use insert() on bool");
        }
        virtual void erase(size_t index) override {
            throw std::runtime_error("Cannot use erase() on bool");
        }
        virtual const JSON_TYPE& at(size_t index) const override {
            throw std::runtime_error("Cannot use at() on bool");
        }
        virtual JSON_TYPE& at(size_t index) override {
            throw std::runtime_error("Cannot use at() on bool");
        }
        virtual const JSON_TYPE& front() const override {
            throw std::runtime_error("Cannot use front() on bool");
        }
        virtual JSON_TYPE& front() override {
            throw std::runtime_error("Cannot use front() on bool");
        }
        virtual const JSON_TYPE& back() const override {
            throw std::runtime_error("Cannot use back() on bool");
        }
        virtual JSON_TYPE& back() override {
            throw std::runtime_error("Cannot use back() on bool");
        }

        // object
        virtual const JSON_TYPE& operator[](const std::string& key) const override {
            throw std::runtime_error("Cannot use operator[] on bool");
        }
        virtual JSON_TYPE& operator[](const std::string& key) override {
            throw std::runtime_error("Cannot use operator[] on bool");
        }
        virtual const JSON_TYPE& operator[](const char* key) const override {
            throw std::runtime_error("Cannot use operator[] on bool");
        }
        virtual JSON_TYPE& operator[](const char* key) override {
            throw std::runtime_error("Cannot use operator[] on bool");
        }
        virtual void insert(const std::string& key, JSON_TYPE&& value) override {
            throw std::runtime_error("Cannot use insert() on bool");
        }
        virtual bool contains(const std::string& key) const override {
            throw std::runtime_error("Cannot use contains() on bool");
        }
        virtual void erase(const std::string& key) override {
            throw std::runtime_error("Cannot use erase() on bool");
        }
        virtual const JSON_TYPE& at(const std::string& key) const override {
            throw std::runtime_error("Cannot use at() on bool");
        }
        virtual JSON_TYPE& at(const std::string& key) override {
            throw std::runtime_error("Cannot use at() on bool");
        }

        // both array and object
        virtual void clear() override {
            throw std::runtime_error("Cannot use clear() on bool");
        }
        virtual size_t size() const override {
            throw std::runtime_error("Cannot use size() on bool");
        }
        virtual bool empty() const override {
            throw std::runtime_error("Cannot use empty() on bool");
        }

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
