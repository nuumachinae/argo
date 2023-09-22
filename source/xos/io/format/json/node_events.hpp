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
///   File: node_events.hpp
///
/// Author: $author$
///   Date: 9/21/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_IO_FORMAT_JSON_NODE_EVENTS_HPP
#define XOS_IO_FORMAT_JSON_NODE_EVENTS_HPP

#include "xos/base/logger.hpp"

namespace xos {
namespace io {
namespace format {
namespace json {

/// class node_eventst
template <class TNode, class TImplements = xos::logged>
class exported node_eventst: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef node_eventst derives; 
    
    typedef TNode node_t;
    typedef typename node_t::string_t string_t;
    typedef typename string_t::char_t char_t;
    
    /// constructors / destructor
    virtual ~node_eventst() {
    }

    /// ...on...    
    virtual derives& on_begin_root_node(const node_t& node) {
        derives* forwarded_to = 0;
        LOGGER_IS_LOGGED_INFO("in...");
        if ((forwarded_to = this->forwarded_to(this))) {
            LOGGER_IS_LOGGED_INFO("forwarded_to->on_begin_root_node(node)...");
            forwarded_to->on_begin_root_node(node);
            LOGGER_IS_LOGGED_INFO("...forwarded_to->on_begin_root_node(node)");
        }
        LOGGER_IS_LOGGED_INFO("out...");
        return *this;
    }
    virtual derives& on_end_root_node(const node_t& node) {
        derives* forwarded_to = 0;
        LOGGER_IS_LOGGED_INFO("in...");
        if ((forwarded_to = this->forwarded_to(this))) {
            LOGGER_IS_LOGGED_INFO("forwarded_to->on_end_root_node(node)...");
            forwarded_to->on_end_root_node(node);
            LOGGER_IS_LOGGED_INFO("...forwarded_to->on_end_root_node(node)");
        }
        LOGGER_IS_LOGGED_INFO("out...");
        return *this;
    }
    virtual derives& on_begin_named_node(const node_t& node) {
        derives* forwarded_to = 0;
        LOGGER_IS_LOGGED_INFO("in...");
        if ((forwarded_to = this->forwarded_to(this))) {
            LOGGER_IS_LOGGED_INFO("forwarded_to->on_begin_named_node(node)...");
            forwarded_to->on_begin_named_node(node);
            LOGGER_IS_LOGGED_INFO("...forwarded_to->on_begin_named_node(node)");
        }
        LOGGER_IS_LOGGED_INFO("out...");
        return *this;
    }
    virtual derives& on_end_named_node(const node_t& node) {
        derives* forwarded_to = 0;
        LOGGER_IS_LOGGED_INFO("in...");
        if ((forwarded_to = this->forwarded_to(this))) {
            LOGGER_IS_LOGGED_INFO("forwarded_to->on_end_named_node(node)...");
            forwarded_to->on_end_named_node(node);
            LOGGER_IS_LOGGED_INFO("...forwarded_to->on_end_named_node(node)");
        }
        LOGGER_IS_LOGGED_INFO("out...");
        return *this;
    }
    virtual derives& on_begin_object_node(const node_t& node) {
        derives* forwarded_to = 0;
        LOGGER_IS_LOGGED_INFO("in...");
        if ((forwarded_to = this->forwarded_to(this))) {
            LOGGER_IS_LOGGED_INFO("forwarded_to->on_begin_object_node(node)...");
            forwarded_to->on_begin_object_node(node);
            LOGGER_IS_LOGGED_INFO("...forwarded_to->on_begin_object_node(node)");
        }
        LOGGER_IS_LOGGED_INFO("out...");
        return *this;
    }
    virtual derives& on_end_object_node(const node_t& node) {
        derives* forwarded_to = 0;
        LOGGER_IS_LOGGED_INFO("in...");
        if ((forwarded_to = this->forwarded_to(this))) {
            LOGGER_IS_LOGGED_INFO("forwarded_to->on_end_object_node(node)...");
            forwarded_to->on_end_object_node(node);
            LOGGER_IS_LOGGED_INFO("...forwarded_to->on_end_object_node(node)");
        }
        LOGGER_IS_LOGGED_INFO("out...");
        return *this;
    }
    virtual derives& on_begin_array_node(const node_t& node) {
        derives* forwarded_to = 0;
        LOGGER_IS_LOGGED_INFO("in...");
        if ((forwarded_to = this->forwarded_to(this))) {
            LOGGER_IS_LOGGED_INFO("forwarded_to->on_begin_array_node(node)...");
            forwarded_to->on_begin_array_node(node);
            LOGGER_IS_LOGGED_INFO("...forwarded_to->on_begin_array_node(node)");
        }
        LOGGER_IS_LOGGED_INFO("out...");
        return *this;
    }
    virtual derives& on_end_array_node(const node_t& node) {
        derives* forwarded_to = 0;
        LOGGER_IS_LOGGED_INFO("in...");
        if ((forwarded_to = this->forwarded_to(this))) {
            LOGGER_IS_LOGGED_INFO("forwarded_to->on_end_array_node(node)...");
            forwarded_to->on_end_array_node(node);
            LOGGER_IS_LOGGED_INFO("...forwarded_to->on_end_array_node(node)");
        }
        LOGGER_IS_LOGGED_INFO("out...");
        return *this;
    }
    virtual derives& on_string_node(const node_t& node) {
        derives* forwarded_to = 0;
        LOGGER_IS_LOGGED_INFO("in...");
        if ((forwarded_to = this->forwarded_to(this))) {
            LOGGER_IS_LOGGED_INFO("forwarded_to->on_string_node(node)...");
            forwarded_to->on_string_node(node);
            LOGGER_IS_LOGGED_INFO("...forwarded_to->on_string_node(node)");
        }
        LOGGER_IS_LOGGED_INFO("out...");
        return *this;
    }
    virtual derives& on_number_node(const node_t& node) {
        derives* forwarded_to = 0;
        LOGGER_IS_LOGGED_INFO("in...");
        if ((forwarded_to = this->forwarded_to(this))) {
            LOGGER_IS_LOGGED_INFO("forwarded_to->on_number_node(node)...");
            forwarded_to->on_number_node(node);
            LOGGER_IS_LOGGED_INFO("...forwarded_to->on_number_node(node)");
        }
        LOGGER_IS_LOGGED_INFO("out...");
        return *this;
    }
    virtual derives& on_boolean_node(const node_t& node) {
        derives* forwarded_to = 0;
        LOGGER_IS_LOGGED_INFO("in...");
        if ((forwarded_to = this->forwarded_to(this))) {
            LOGGER_IS_LOGGED_INFO("forwarded_to->on_boolean_node(node)...");
            forwarded_to->on_boolean_node(node);
            LOGGER_IS_LOGGED_INFO("...forwarded_to->on_boolean_node(node)");
        }
        LOGGER_IS_LOGGED_INFO("out...");
        return *this;
    }
    virtual derives& on_null_node(const node_t& node) {
        derives* forwarded_to = 0;
        LOGGER_IS_LOGGED_INFO("in...");
        if ((forwarded_to = this->forwarded_to(this))) {
            LOGGER_IS_LOGGED_INFO("forwarded_to->on_null_node(node)...");
            forwarded_to->on_null_node(node);
            LOGGER_IS_LOGGED_INFO("...forwarded_to->on_null_node(node)");
        }
        LOGGER_IS_LOGGED_INFO("out...");
        return *this;
    }
    
    /// ...forward...
    virtual derives* forward_to(derives* to) {
        return ((derives*)0);
    }
    virtual derives* forwarded_to(derives* from) const {
        return ((derives*)0);
    }

}; /// class node_eventst

namespace extended {
/// class node_eventst
template 
<class TNode, class TEvents, 
 class TExtends = xos::extended::logged, class TImplements = typename TExtends::implements>
class exported node_eventst: virtual public TEvents, virtual public TImplements {
public:
    typedef TImplements implements;
    typedef node_eventst derives; 
    
    typedef TEvents events_t;
    typedef TNode node_t;
    typedef typename node_t::string_t string_t;
    typedef typename string_t::char_t char_t;
    
    /// constructors / destructor
    node_eventst(events_t &events): forwarded_to_(&events) {
    }
    node_eventst(): forwarded_to_(0) {
    }
    virtual ~node_eventst() {
    }
private:
    node_eventst(const node_eventst& copy): forwarded_to_(0) {
    }
public:
    
    /// ...forward...
    virtual events_t* forward_to(events_t* to) {
        events_t* forwarded_to = this->forwarded_to(this);
        forwarded_to = to;
        return forwarded_to;
    }
    virtual events_t* forwarded_to(events_t* from) const {
        return ((events_t*)forwarded_to_);
    }

protected:
    events_t* forwarded_to_;
}; /// class node_eventst
} /// namespace extended

} /// namespace json 
} /// namespace format 
} /// namespace io 
} /// namespace xos 

#endif /// ndef XOS_IO_FORMAT_JSON_NODE_EVENTS_HPP
