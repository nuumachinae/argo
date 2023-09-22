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
///   File: string.hpp
///
/// Author: $author$
///   Date: 9/21/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_IO_FORMAT_JSON_STRING_HPP
#define XOS_IO_FORMAT_JSON_STRING_HPP

#include "xos/base/to_string.hpp"

namespace xos {
namespace io {
namespace format {
namespace json {

/// class stringt
template <class TExtends = xos::char_string, class TImplements = typename TExtends::implements>
class exported stringt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef stringt derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };

    /// constructor / destructor
    stringt(const char_t* chars, size_t length): extends(chars, length) {
    }
    stringt(const char_t* chars): extends(chars) {
    }
    stringt(const stringt& copy): extends(copy) {
    }
    stringt() {
    }
    virtual ~stringt() {
    }

    /// ...to...
    virtual stringt& assign_to(stringt& to) const {
        to.clear();
        append_to(to);
        return to;
    }
    virtual stringt& append_to(stringt& to) const {
        const char_t* chars = 0; size_t length = 0;
        if ((chars = this->has_chars(length))) {
            to.append(chars, length);
        }
        return to;
    }
    virtual stringt& assign_literal_to(stringt& to) const {
        to.clear();
        append_literal_to(to);
        return to;
    }
    virtual stringt& append_literal_to(stringt& to) const {
        const char_t* chars = 0; size_t length = 0;
        to.append("\"");
        if ((chars = this->has_chars(length))) {
            for (char c = 0; (0 < length); ++chars, --length) {
                switch (c = ((char)(*chars))) {
                case '"':
                    to.append("\\", 1);
                default:
                    to.append(chars, 1);
                    break;
                }
            }
        }
        to.append("\"");
        return to;
    }
}; /// class stringt

typedef stringt<> string;
typedef string string_t;
typedef string::char_t char_t;

} /// namespace json 
} /// namespace format 
} /// namespace io 
} /// namespace xos 

#endif /// ndef XOS_IO_FORMAT_JSON_STRING_HPP
