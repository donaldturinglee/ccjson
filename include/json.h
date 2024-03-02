#ifndef JSON_H
#define JSON_H

#include "type.h"

namespace ccjson {
    class JsonPtr;
    class Array;
    class Object;
    class Bool;
    class Float;
    class Int;
    class String;
    class Null;

    class Json {
    public:
        class Error : public std::exception {
        public:
            Error(const std::string& message);
            virtual const char* what() const noexcept override;
        protected:
            std::string message_;
        };

        virtual ~Json() = default;

        virtual std::string to_string(int indent = 0, int base_indent = 0) const = 0;
        
        // array
        virtual const JSON_TYPE& operator[](size_t index) const = 0;
        virtual JSON_TYPE& operator[](size_t) = 0;
        virtual void push(JSON_TYPE&& value) = 0;
        virtual void insert(size_t index, JSON_TYPE&& value) = 0;
        virtual void erase(size_t index) = 0;
        virtual const JSON_TYPE& at(size_t index) const = 0;
        virtual JSON_TYPE& at(size_t index) = 0;
        virtual const JSON_TYPE& front() const = 0;
        virtual JSON_TYPE& front() = 0;
        virtual const JSON_TYPE& back() const = 0;
        virtual JSON_TYPE& back() = 0;

        // object
        virtual const JSON_TYPE& operator[](const std::string& key) const = 0;
        virtual JSON_TYPE& operator[](const std::string& key) = 0;
        virtual const JSON_TYPE& operator[](const char* key) const = 0;
        virtual JSON_TYPE& operator[](const char* key) = 0;

        virtual void insert(const std::string& key, JSON_TYPE&& value) = 0;
        virtual bool contains(const std::string& key) const = 0;
        virtual void erase(const std::string& key) = 0;
        virtual const JSON_TYPE& at(const std::string& key) const = 0;
        virtual JSON_TYPE& at(const std::string& key) = 0;

        // both array and object
        virtual void clear() = 0;
        virtual size_t size() const = 0;
        virtual bool empty() const = 0;

        virtual const JSON_ARRAY& get_array() const = 0;
        virtual const JSON_OBJECT& get_object() const = 0;
        virtual JSON_FLOAT get_float() const = 0;
        virtual JSON_INT get_int() const = 0;
        virtual JSON_STRING get_string() const = 0;
        virtual JSON_BOOL get_bool() const = 0;

        virtual JSON_ARRAY& get_array() = 0;
        virtual JSON_OBJECT& get_object() = 0;
        virtual JSON_FLOAT& get_float() = 0;
        virtual JSON_INT& get_int() = 0;
        virtual JSON_STRING& get_string() = 0;
        virtual JSON_BOOL& get_bool() = 0;
    };
    
    class JsonPtr : public Json {
    public:
        JsonPtr();
        JsonPtr(JsonPtr&& source);
        JsonPtr(std::unique_ptr<Json>&& source);

        JsonPtr(Array&& value);
        JsonPtr(Object&& value);
        JsonPtr(Bool&& value);
        JsonPtr(Float&& value);
        JsonPtr(Int&& value);
        JsonPtr(String&& value);
        JsonPtr(JSON_ARRAY&& value);
        JsonPtr(JSON_OBJECT&& value);
        JsonPtr(JSON_BOOL value);
        JsonPtr(JSON_FLOAT value);
        JsonPtr(JSON_INT value);
        JsonPtr(JSON_STRING value);
        JsonPtr(const char* value);

        JsonPtr& operator=(JsonPtr&& source);
        JsonPtr& operator=(std::unique_ptr<Json>&& source);

        JsonPtr& operator=(Array&& value);
        JsonPtr& operator=(Object&& value);
        JsonPtr& operator=(Bool&& value);
        JsonPtr& operator=(Float&& value);
        JsonPtr& operator=(Int&& value);
        JsonPtr& operator=(String&& value);
        JsonPtr& operator=(JSON_ARRAY&& value);
        JsonPtr& operator=(JSON_OBJECT&& value);
        JsonPtr& operator=(JSON_BOOL value);
        JsonPtr& operator=(JSON_FLOAT value);
        JsonPtr& operator=(JSON_INT value);
        JsonPtr& operator=(JSON_STRING value);
        JsonPtr& operator=(const char* value);

        virtual ~JsonPtr() = default;

        virtual std::string to_string(int indent = 0, int base_indent = 0) const override;

        // array
        virtual const JSON_TYPE& operator[](size_t index) const override {
            return (*value_)[index];
        }
        virtual JSON_TYPE& operator[](size_t index) override {
            return (*value_)[index];
        }
        virtual void push(JSON_TYPE&& value) override {
            value_->push(std::move(value));
        }
        virtual void insert(size_t index, JSON_TYPE&& value) override {
            value_->insert(index, std::move(value));
        }
        virtual void erase(size_t index) override {
            value_->erase(index);
        }
        virtual const JSON_TYPE& at(size_t index) const override {
            return value_->at(index);
        }
        virtual JSON_TYPE& at(size_t index) override {
            return value_->at(index);
        }
        virtual const JSON_TYPE& front() const override {
            return value_->front();
        }
        virtual JSON_TYPE& front() override {
            return value_->front();
        }
        virtual const JSON_TYPE& back() const override {
            return value_->back();
        }
        virtual JSON_TYPE& back() override {
            return value_->back();
        }

        // object
        virtual const JSON_TYPE& operator[](const std::string& key) const override {
            return (*value_)[key];
        }
        virtual JSON_TYPE& operator[](const std::string& key) override {
            return (*value_)[key];
        }
        virtual const JSON_TYPE& operator[](const char* key) const override {
            return (*value_)[key];
        }
        virtual JSON_TYPE& operator[](const char* key) override {
            return (*value_)[key];
        }
        virtual void insert(const std::string& key, JSON_TYPE&& value) override {
            value_->insert(key, std::move(value));
        }
        virtual bool contains(const std::string& key) const override {
            return value_->contains(key);
        }
        virtual void erase(const std::string& key) override {
            value_->erase(key);
        }
        virtual const JSON_TYPE& at(const std::string& key) const override {
            return value_->at(key);
        }
        virtual JSON_TYPE& at(const std::string& key) override {
            return value_->at(key);
        }

        // both array and object
        virtual void clear() override {
            value_->clear();
        }
        virtual size_t size() const override {
            return value_->size();
        }
        virtual bool empty() const override {
            return value_->empty();
        }

        // conversion
        virtual const JSON_ARRAY& get_array() const override {
            return value_->get_array();
        }
        virtual const JSON_OBJECT& get_object() const override {
            return value_->get_object();
        }
        virtual JSON_FLOAT get_float() const override {
            return value_->get_float();
        }
        virtual JSON_INT get_int() const override {
            return value_->get_int();
        }
        virtual JSON_STRING get_string() const override {
            return value_->get_string();
        }
        virtual JSON_BOOL get_bool() const override {
            return value_->get_bool();
        }

        virtual JSON_ARRAY& get_array() override {
            return value_->get_array();
        }
        virtual JSON_OBJECT& get_object() override {
            return value_->get_object();
        }
        virtual JSON_FLOAT& get_float() override {
            return value_->get_float();
        }
        virtual JSON_INT& get_int() override {
            return value_->get_int();
        }
        virtual JSON_STRING& get_string() override {
            return value_->get_string();
        }
        virtual JSON_BOOL& get_bool() override {
            return value_->get_bool();
        }

        operator const JSON_ARRAY&() const {
            return get_array();
        }
        operator const JSON_OBJECT&() const {
            return get_object();
        }
        operator JSON_FLOAT() const {
            return get_float();
        }
        operator JSON_INT() const {
            return get_int();
        }
        operator JSON_STRING() const {
            return get_string();
        }
        operator JSON_BOOL() const {
            return get_bool();
        }

    private:
        std::unique_ptr<Json> value_;
    };
} // namespace ccjson

std::ostream& operator<<(std::ostream& os, const ccjson::Json& json);
std::ostream& operator<<(std::ostream& os, const ccjson::JsonPtr& json);
#endif // JSON_H
