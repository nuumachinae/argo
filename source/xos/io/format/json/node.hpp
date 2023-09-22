//////////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2023 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: node.hpp
///
/// Author: $author$
///   Date: 9/21/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_IO_FORMAT_JSON_NODE_HPP
#define XOS_IO_FORMAT_JSON_NODE_HPP

#include "xos/io/format/json/node_events.hpp"
#include "xos/io/format/json/string.hpp"
#include "xos/io/reader.hpp"
#include "xos/base/logger.hpp"
#include <sstream>
#include <list>

namespace xos {
namespace io {
namespace format {
namespace json {

typedef double number;
typedef bool boolean;
class exported node;
typedef ::std::list<node> node_list;

/// enum node_type
enum node_type {
    unknown_node = 0,
    
    object_node,
    array_node,
    named_node,
    string_node,
    number_node,
    boolean_node,
    null_node,

    first_node_type = object_node,
    last_node_type = null_node,
    node_types = last_node_type - first_node_type + 1
}; /// enum node_type

/// class node
class exported node: virtual public xos::logged, public xos::extended::logged {
public:
    typedef implement implements;
    typedef extend extends;
    typedef node derives;

    typedef node_eventst<derives> node_events;
    typedef node_events node_events_t;
    typedef string string_t;
    typedef string::char_t char_t;
    
    /// constructor / destructor
    node(const string& name, const node_type& type, const string& value) {
        assign(name, type, value);
    }
    node(const string& name, const char_t* value) {
        assign(name, value);
    }
    node(const string& name, const string& value) {
        assign(name, value);
    }
    node(const string& name, const int& value) {
        assign(name, value);
    }
    node(const string& name, const float& value) {
        assign(name, value);
    }
    node(const string& name, const double& value) {
        assign(name, value);
    }
    node(const string& name, const bool& value) {
        assign(name, value);
    }
    node(const string& name, const node& value) {
        assign(name, value);
    }
    node(const char_t* value): type_(null_node), string_(name_null()), number_(0), boolean_(false) {
        this->operator = (value);
    }
    node(const string& value): type_(null_node), string_(name_null()), number_(0), boolean_(false) {
        this->operator = (value);
    }
    node(const int& value): type_(null_node), string_(name_null()), number_(0), boolean_(false) {
        this->operator = (value);
    }
    node(const float& value): type_(null_node), string_(name_null()), number_(0), boolean_(false) {
        this->operator = (value);
    }
    node(const double& value): type_(null_node), string_(name_null()), number_(0), boolean_(false) {
        this->operator = (value);
    }
    node(const bool& value): type_(null_node), string_(name_null()), number_(0), boolean_(false) {
        this->operator = (value);
    }
    node(const node_type& type, const node_list& values)
    : type_(type), string_(name_null()), number_(0), boolean_(false), values_(values) {
    }
    node(const node_type& type, const string& value)
    : type_(type), string_(value), number_(0), boolean_(false) {
    }
    node(const node_type& type)
    : type_(type), string_(name_null()), number_(0), boolean_(false) {
    }
    node(const node& copy)
    : type_(copy.type_), string_(copy.string_), number_(copy.number_), boolean_(copy.boolean_), values_(copy.values_) {
    }
    node(): type_(null_node), string_(name_null()), number_(0), boolean_(false) {
    }
    virtual ~node() {
    }

    /// assign
    virtual node& assign(const string& name, const node_type& type, const string& value) {
        clear();
        type_ = named_node;
        string_ = name;
        values_.push_back(node(type, value));
        return *this;
    }
    virtual node& assign(const string& name, const char_t* value) {
        clear();
        type_ = named_node;
        string_ = name;
        values_.push_back(node(value));
        return *this;
    }
    virtual node& assign(const string& name, const string& value) {
        clear();
        type_ = named_node;
        string_ = name;
        values_.push_back(node(value));
        return *this;
    }
    virtual node& assign(const string& name, const int& value) {
        clear();
        type_ = named_node;
        string_ = name;
        values_.push_back(node(value));
        return *this;
    }
    virtual node& assign(const string& name, const float& value) {
        clear();
        type_ = named_node;
        string_ = name;
        values_.push_back(node(value));
        return *this;
    }
    virtual node& assign(const string& name, const double& value) {
        clear();
        type_ = named_node;
        string_ = name;
        values_.push_back(node(value));
        return *this;
    }
    virtual node& assign(const string& name, const bool& value) {
        clear();
        type_ = named_node;
        string_ = name;
        values_.push_back(node(value));
        return *this;
    }
    virtual node& assign(const string& name, const node& value) {
        clear();
        type_ = named_node;
        string_ = name;
        if ((value.values().size())) {
            values_.push_back(node(value.type(), value.values()));
        } else {
            values_.push_back(node(value.name()));
        }
        return *this;
    }

    /// clear...
    virtual node& clear_named(const string& name) {
        clear();
        type_ = named_node;
        string_ = name;
        return *this;
    }
    virtual node& clear_object() {
        clear();
        type_ = object_node;
        return *this;
    }
    virtual node& clear_array() {
        clear();
        type_ = array_node;
        return *this;
    }
    virtual node& clear() {
        type_ = null_node;
        string_.clear();
        number_ = 0;
        boolean_ = false;
        values_.clear();
        return *this;
    }

    /// put
    virtual node& put(const string& name, const char_t* value) {
        string svalue(value);
        values_.push_back(node(name, svalue));
        return *this;
    }
    virtual node& put(const string& name, const string& value) {
        values_.push_back(node(name, value));
        return *this;
    }
    virtual node& put(const string& name, const int& value) {
        values_.push_back(node(name, value));
        return *this;
    }
    virtual node& put(const string& name, const float& value) {
        values_.push_back(node(name, value));
        return *this;
    }
    virtual node& put(const string& name, const double& value) {
        values_.push_back(node(name, value));
        return *this;
    }
    virtual node& put(const string& name, const bool& value) {
        values_.push_back(node(name, value));
        return *this;
    }
    virtual node& put(const string& name, const node& value) {
        values_.push_back(node(name, value));
        return *this;
    }

    /// get
    virtual int& get(int& value, const string& name) const {
        const node* v = 0;
        if ((v = find(name))) {
            node_list::const_iterator begin = v->values_.begin(), end = v->values_.end();
            if (begin != end) {
                if (!(begin->values_.size())) {
                    char_string s(begin->string_.chars());
                    ::std::stringstream ss(s);
                    ss >> value;
                }
            }
        }
        return value;
    }
    virtual float& get(float& value, const string& name) const {
        const node* v = 0;
        if ((v = find(name))) {
            node_list::const_iterator begin = v->values_.begin(), end = v->values_.end();
            if (begin != end) {
                if (!(begin->values_.size())) {
                    char_string s(begin->string_.chars());
                    ::std::stringstream ss(s);
                    ss >> value;
                }
            }
        }
        return value;
    }
    virtual double& get(double& value, const string& name) const {
        const node* v = 0;
        if ((v = find(name))) {
            node_list::const_iterator begin = v->values_.begin(), end = v->values_.end();
            if (begin != end) {
                if (!(begin->values_.size())) {
                    char_string s(begin->string_.chars());
                    ::std::stringstream ss(s);
                    ss >> value;
                }
            }
        }
        return value;
    }
    virtual bool& get(bool& value, const string& name) const {
        const node* v = 0;
        if ((v = find(name))) {
            node_list::const_iterator begin = v->values_.begin(), end = v->values_.end();
            if (begin != end) {
                if (!(begin->values_.size())) {
                    value = !(begin->string_.compare(json::node::name_true()));
                }
            }
        }
        return value;
    }
    virtual string& get(string& value, const string& name) const {
        const node* v = 0;
        if ((v = find(name))) {
            node_list::const_iterator begin = v->values_.begin(), end = v->values_.end();
            if (begin != end) {
                if (!(begin->values_.size())) {
                    value = begin->string_;
                }
            }
        }
        return value;
    }
    virtual node& get(node& value, const string& name) const {
        const node* v = 0;
        if ((v = find(name))) {
            node_list::const_iterator begin = v->values_.begin(), end = v->values_.end();
            if (begin != end) {
                if (!(begin->values_.size())) {
                    value = *begin;
                }
            }
        }
        return value;
    }

    /// put
    virtual node& put(const string& name, const node_type& type, const char_t* value) {
        string svalue(value);
        values_.push_back(node(name, type, svalue));
        return *this;
    }
    virtual node& put(const string& name, const node_type& type, const string& value) {
        values_.push_back(node(name, type, value));
        return *this;
    }
    virtual node& put(const node_type& type, const char_t* name) {
        string sname(name);
        values_.push_back(node(type, sname));
        return *this;
    }
    virtual node& put(const node_type& type, const string& name) {
        values_.push_back(node(type, name));
        return *this;
    }
    virtual node& put(const char_t* value) {
        values_.push_back(node(value));
        return *this;
    }
    virtual node& put(const string& value) {
        values_.push_back(node(value));
        return *this;
    }
    virtual node& put(const int& value) {
        values_.push_back(node(value));
        return *this;
    }
    virtual node& put(const float& value) {
        values_.push_back(node(value));
        return *this;
    }
    virtual node& put(const double& value) {
        values_.push_back(node(value));
        return *this;
    }
    virtual node& put(const bool& value) {
        values_.push_back(node(value));
        return *this;
    }
    virtual node& put(const node& value) {
        values_.push_back(node(value));
        return *this;
    }

    /// operator =
    virtual node& operator = (const string& value) {
        string_ = value;
        number_ = 0;
        boolean_ = false;
        type_ = string_node;
        return *this;
    }
    virtual node& operator = (const char_t* value) {
        string_ = value;
        number_ = 0;
        boolean_ = false;
        type_ = string_node;
        return *this;
    }
    virtual node& operator = (const int& value) {
        ::std::stringstream ss;
        ss << value;
        string_ = ss.str().c_str();
        number_ = value;
        boolean_ = false;
        type_ = number_node;
        return *this;
    }
    virtual node& operator = (const float& value) {
        ::std::stringstream ss;
        ss << value;
        string_ = ss.str().c_str();
        number_ = value;
        boolean_ = false;
        type_ = number_node;
        return *this;
    }
    virtual node& operator = (const double& value) {
        ::std::stringstream ss;
        ss << value;
        string_ = ss.str().c_str();
        number_ = value;
        boolean_ = false;
        type_ = number_node;
        return *this;
    }
    virtual node& operator = (const bool& value) {
        string_ = (value)?(name_true()):(name_false());
        number_ = 0;
        boolean_ = value;
        type_ = boolean_node;
        return *this;
    }
    virtual operator string() const {
        return string_;
    }
    virtual operator number() const {
        return number_;
    }
    virtual operator boolean() const {
        return boolean_;
    }

    /// type / name / values / value
    virtual string type_name() const {
        return name_type(type_);
    }
    virtual const node_type& type() const {
        return type_;
    }
    virtual const string& name() const {
        return string_;
    }
    virtual const node_list& values() const {
        return values_;
    }
    virtual const node& value() const {
        node_list::const_iterator begin = values_.begin(), end = values_.end();
        if ((begin != end)) {
            return *begin;
        }
        return value_null();
    }

    /// name...
    static string name_type(const node_type& type) {
        switch (type) {
        case object_node:  return "object";
        case array_node:   return "array";
        case named_node:   return "named";
        case string_node:  return "string";
        case number_node:  return "number";
        case boolean_node: return "boolean";
        case null_node:    return "null";
        }
        return "unknown";
    }
    static string name_true() {
        return "true";
    }
    static string name_false() {
        return "false";
    }
    static string name_null() {
        return "null";
    }
    static const node& value_null() {
        static const node null_node;
        return null_node;
    }

    /// from
    virtual node& from(char_reader& from) {
        return *this;
    }
    virtual node& from(const char_string& from) {
        return *this;
    }
    
    /// to
    virtual string& to(string& to) const {
        switch(type_) {
    
        case number_node:
        case boolean_node:
        case null_node:
            if (0 < (string_.length())) {
                LOGGER_IS_LOGGED_INFO("...literal " << string_.chars());
                string_.append_to(to);
            } else {
                LOGGER_IS_LOGGED_ERROR("...unexpected empty literal");
            }
            break;
    
        case string_node:
            if (0 < (string_.length())) {
                LOGGER_IS_LOGGED_INFO("...literal \"" << string_.chars() << "\"");
                string_.append_literal_to(to);
            } else {
                to.append("\"");
                to.append("\"");
                LOGGER_IS_LOGGED_INFO("...literal \"\"");
            }
            break;
    
        case named_node:
        case array_node:
        case object_node:
            if (0 < (values_.size())) {
                node_list::const_iterator b = values_.begin(), e = values_.end();
    
                if (named_node != (type_)) {
                    LOGGER_IS_LOGGED_INFO(((array_node != (type_))?("object {"):("array [")) << "...");
                    to.append((array_node != (type_))?("{"):("["));
                    for (node_list::const_iterator i = b; i != e; ++i) {
                        const node& v = *i;
                        if ((i != b)) {
                            to.append(",");
                        }
                        LOGGER_IS_LOGGED_DEBUG("v.to(to)...");
                        v.to(to);
                        LOGGER_IS_LOGGED_DEBUG("...v.to(to)");
                    }
                    to.append((array_node != (type_))?("}"):("]"));
                    LOGGER_IS_LOGGED_INFO("..." << ((array_node != (type_))?("} object"):("] array")));
                } else {
                    const node& v = *b;
                    to.append("\"");
                    to.append(string_);
                    to.append("\":");
                    LOGGER_IS_LOGGED_INFO("...named \"" << string_.chars() << "\":");
                    LOGGER_IS_LOGGED_DEBUG("v.to(to)...");
                    v.to(to);
                    LOGGER_IS_LOGGED_DEBUG("...v.to(to)");
                }
            } else {
                LOGGER_IS_LOGGED_ERROR("...unexpected empty values");
            }
            break;
    
        default:
            LOGGER_IS_LOGGED_ERROR("...unexpected type = " << type_);
            break;
        }
        return to;
    }
    virtual node_events& to(node_events& to) const {
        switch(type_) {
    
        case number_node:
        case boolean_node:
        case null_node:
            if (0 < (string_.length())) {
                LOGGER_IS_LOGGED_INFO("...literal " << string_.chars());
                switch(type_) {

                case number_node:
                    to.on_number_node(*this);
                    break;
                case boolean_node:
                    to.on_boolean_node(*this);
                    break;
                case null_node:
                    to.on_null_node(*this);
                    break;

                default:                    
                    LOGGER_IS_LOGGED_ERROR("...unexpected type = " << type_);
                }
            } else {
                LOGGER_IS_LOGGED_ERROR("...unexpected empty literal");
            }
            break;
    
        case string_node:
            LOGGER_IS_LOGGED_INFO("...literal \"" << string_.chars() << "\"");
            to.on_string_node(*this);
            break;
    
        case named_node:
        case array_node:
        case object_node:
            if (0 < (values_.size())) {
                node_list::const_iterator b = values_.begin(), e = values_.end();
    
                if (named_node != (type_)) {
                    LOGGER_IS_LOGGED_INFO(((array_node != (type_))?("object {"):("array [")) << "...");
                    if (array_node != (type_)) {
                        to.on_begin_object_node(*this);
                    } else {
                        to.on_begin_array_node(*this);
                    }
                    for (node_list::const_iterator i = b; i != e; ++i) {
                        const node& v = *i;
                        if ((i != b)) {
                        }
                        LOGGER_IS_LOGGED_DEBUG("v.to(to)...");
                        v.to(to);
                        LOGGER_IS_LOGGED_DEBUG("...v.to(to)");
                    }
                    if (array_node != (type_)) {
                        to.on_end_object_node(*this);
                    } else {
                        to.on_end_array_node(*this);
                    }
                    LOGGER_IS_LOGGED_INFO("..." << ((array_node != (type_))?("} object"):("] array")));
                } else {
                    const node& v = *b;
                    LOGGER_IS_LOGGED_INFO("...named \"" << string_.chars() << "\":");
                    to.on_begin_named_node(*this);
                    LOGGER_IS_LOGGED_DEBUG("v.to(to)...");
                    v.to(to);
                    LOGGER_IS_LOGGED_DEBUG("...v.to(to)");
                    to.on_end_named_node(*this);
                }
            } else {
                LOGGER_IS_LOGGED_ERROR("...unexpected empty values");
            }
            break;
    
        default:
            LOGGER_IS_LOGGED_ERROR("...unexpected type = " << type_);
            break;
        }
        return to;
    }

    /// ...get...
    virtual const node_type& get_type() const {
        return type_;
    }
    virtual const string& get_string() const {
        return string_;
    }
    virtual const number& get_number() const {
        return number_;
    }
    virtual const boolean& get_boolean() const {
        return boolean_;
    }
    
protected:
    /// find
    virtual const node* find(const string& name) const {
        node_list::const_iterator begin = values_.begin(), end = values_.end();
        if (begin != end) {
            if (0 < (begin->string_.length())) {
                for (node_list::const_iterator i = begin; i != end; ++i) {
                    const node& n = (*i);
                    if (!(name.compare(n.string_))) {
                        return &n;
                    }
                }
            }
        }
        return 0;
    }

protected:
     node_type type_;
     string string_;
     number number_;
     boolean boolean_;
     node_list values_;
}; /// class node
typedef node::node_events node_events;

namespace extended {
typedef json::extended::node_eventst<json::node, json::node::node_events>  node_events;
} /// namespace extended

} /// namespace json 
} /// namespace format 
} /// namespace io 
} /// namespace xos 

#endif /// ndef XOS_IO_FORMAT_JSON_NODE_HPP
