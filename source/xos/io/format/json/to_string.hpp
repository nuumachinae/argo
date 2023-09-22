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
///   File: to_string.hpp
///
/// Author: $author$
///   Date: 9/21/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_IO_FORMAT_JSON_TO_STRING_HPP
#define XOS_IO_FORMAT_JSON_TO_STRING_HPP

#include "xos/io/format/json/node.hpp"

namespace xos {
namespace io {
namespace format {
namespace json {

/// class to_stringt
template <class TExtends = string, class TImplements = typename TExtends::implements>
class exported to_stringt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef to_stringt derives;

    /// constructor / destructor
    to_stringt(const node& from) {
        from.to(*this);
    }
    to_stringt(const to_stringt& copy): extends(copy) {
    }
    to_stringt() {
    }
    virtual ~to_stringt() {
    }
}; /// class to_stringt
typedef to_stringt<> to_string;

} /// namespace json 
} /// namespace format 
} /// namespace io 
} /// namespace xos 

#endif /// ndef XOS_IO_FORMAT_JSON_TO_STRING_HPP
