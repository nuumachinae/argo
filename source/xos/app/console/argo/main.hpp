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
///   File: main.hpp
///
/// Author: $author$
///   Date: 9/20/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_ARGO_MAIN_HPP
#define XOS_APP_CONSOLE_ARGO_MAIN_HPP

#include "xos/app/console/argo/main_opt.hpp"
#include "xos/io/format/json/libjson/to_node.hpp"
#include "xos/io/crt/file/reader.hpp"

namespace xos {
namespace app {
namespace console {
namespace argo {

/// class maint
template 
<class TEvents = io::format::json::node_events,
 class TExtends = xos::app::console::argo::main_optt<>,  class TImplements = typename TExtends::implements>

class maint: virtual public TEvents, virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    maint()
    : run_(0),
      json_events_(*this),
      json_string_("{\"object\": \"method\", \"arguments\": [{\"argument\": 1},{\"argument\": 2},{\"argument\": \"...\"}]}"), 
      json_arg_(json_string_.has_chars()) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint &copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

    /// run
    int (derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((run_)) {
            err = (this->*run_)(argc, argv, env);
        } else {
            err = extends::run(argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////

    /// ...json_file_run
    virtual int json_file_run(int argc, char_t** argv, char_t** env) {
        int err = 0, argind = 0;
        const char_t* arg = 0;
 
        if (!(arg = this->json_file().has_chars())) {
            if ((argc > (argind = optind)) && (argv)) {
                arg = argv[argind];
            }
        }
        if ((arg) && (arg[0])) {
            io::crt::file::char_reader file;
            
            LOGGER_IS_LOGGED_INFO("file.open(\"" << arg << "\")...");
            if ((file.open(arg))) {
                io::format::json::node node;
                io::format::json::libjson::to_node to_node;
                
                LOGGER_IS_LOGGED_INFO("to_node.to(node, file)...");
                to_node.to(node, file);
                this->all_output_json_node_run(node, argc, argv, env);
                file.close();
            } else {
                LOGGER_IS_LOGGED_ERROR("...failed on file.open(\"" << arg << "\")");
            }
        }
        return err;
    }

    /// ...json_literal_run
    virtual int json_literal_run(int argc, char_t** argv, char_t** env) {
        int err = 0, argind = 0;
        const char_t* arg = 0;
 
        if (!(arg = this->json_literal().has_chars())) {
            if ((argc > (argind = optind)) && (argv)) {
                arg = argv[argind];
            }
        }
        if ((arg) && (arg[0])) {
            io::format::json::libjson::to_node to_node;
            io::format::json::node node;
            char_string to(arg);
            
            LOGGER_IS_LOGGED_INFO("to_node.to(node, \"" << to << "\")...");
            to_node.to(node, to);
            LOGGER_IS_LOGGED_INFO("...to_node.to(node, \"" << to << "\")");
            this->all_output_json_node_run(node, argc, argv, env);
        } else {
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////

    /// ...output_json_node_run
    /// ...
    /// default_output_json_node_run
    virtual int default_output_json_node_run(const io::format::json::node& node, int argc, char_t** argv, char_t** env) {
        int err = 0;
        io::format::json::node_events& events = this->json_events();

        LOGGER_IS_LOGGED_INFO("events.on_begin_root_node(node)...");
        events.on_begin_root_node(node);
        LOGGER_IS_LOGGED_INFO("node.to(events)...");
        node.to(events);
        LOGGER_IS_LOGGED_INFO("...node.to(events)");
        events.on_end_root_node(node);
        LOGGER_IS_LOGGED_INFO("events.on_end_root_node(node)...");
        return err;
    }
    /// string_output_json_node_run
    virtual int string_output_json_node_run(const io::format::json::node& node, int argc, char_t** argv, char_t** env) {
        int err = 0;
        io::format::json::string_t& string = this->json_string();
        const io::format::json::char_t* chars = 0;

        LOGGER_IS_LOGGED_INFO("string.clear()...");
        string.clear();
        LOGGER_IS_LOGGED_INFO("node.to(string)...");
        node.to(string);
        LOGGER_IS_LOGGED_INFO("...node.to(string)");
        if ((chars = string.has_chars())) {
            this->outlln("", chars, "", null);
        } else {
        }
        return err;
    }
    /// ...
    /// ...output_json_node_run

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////

    /// ...json_events
    virtual io::format::json::node_events& json_events() const {
        return (io::format::json::node_events&) json_events_;
    }

    /// ...json_string
    virtual io::format::json::string_t& set_json_string(io::format::json::string_t& to) {
        io::format::json::string_t& json_string = this->json_string();
        json_string = to;
        return json_string;
    }
    virtual io::format::json::string_t& json_string() const {
        return (io::format::json::string_t&) json_string_;
    }

    /// ...json_arg
    virtual const char_t*& set_json_arg(const char_t*& to) {
        const char_t*& json_arg = this->json_arg();
        json_arg = to;
        return json_arg;
    }
    virtual const char_t*& json_arg() const {
        return (const char_t*&) json_arg_;
    }

protected:
    io::format::json::extended::node_events json_events_;
    io::format::json::string_t json_string_;
    const char_t* json_arg_;
}; /// class maint 
typedef maint<> main;

} /// namespace argo 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_ARGO_MAIN_HPP
