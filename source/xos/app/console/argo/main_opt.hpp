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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 9/20/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_ARGO_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_ARGO_MAIN_OPT_HPP

#include "xos/app/console/argo/version/main.hpp"
#include "xos/io/format/json/node.hpp"

#define XOS_APP_CONSOLE_ARGO_MAIN_JSON_FILE_OPT "json-file"
#define XOS_APP_CONSOLE_ARGO_MAIN_JSON_FILE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_ARGO_MAIN_JSON_FILE_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_ARGO_MAIN_JSON_FILE_OPTARG "[filename]"
#define XOS_APP_CONSOLE_ARGO_MAIN_JSON_FILE_OPTUSE "Json file"
#define XOS_APP_CONSOLE_ARGO_MAIN_JSON_FILE_OPTVAL_S "f::"
#define XOS_APP_CONSOLE_ARGO_MAIN_JSON_FILE_OPTVAL_C 'f'
#define XOS_APP_CONSOLE_ARGO_MAIN_JSON_FILE_OPTION \
   {XOS_APP_CONSOLE_ARGO_MAIN_JSON_FILE_OPT, \
    XOS_APP_CONSOLE_ARGO_MAIN_JSON_FILE_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_ARGO_MAIN_JSON_FILE_OPTARG_RESULT, \
    XOS_APP_CONSOLE_ARGO_MAIN_JSON_FILE_OPTVAL_C}, \

#define XOS_APP_CONSOLE_ARGO_MAIN_JSON_LITERAL_OPT "json-literal"
#define XOS_APP_CONSOLE_ARGO_MAIN_JSON_LITERAL_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_ARGO_MAIN_JSON_LITERAL_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_ARGO_MAIN_JSON_LITERAL_OPTARG "[string]"
#define XOS_APP_CONSOLE_ARGO_MAIN_JSON_LITERAL_OPTUSE "Json literal"
#define XOS_APP_CONSOLE_ARGO_MAIN_JSON_LITERAL_OPTVAL_S "i::"
#define XOS_APP_CONSOLE_ARGO_MAIN_JSON_LITERAL_OPTVAL_C 'i'
#define XOS_APP_CONSOLE_ARGO_MAIN_JSON_LITERAL_OPTION \
   {XOS_APP_CONSOLE_ARGO_MAIN_JSON_LITERAL_OPT, \
    XOS_APP_CONSOLE_ARGO_MAIN_JSON_LITERAL_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_ARGO_MAIN_JSON_LITERAL_OPTARG_RESULT, \
    XOS_APP_CONSOLE_ARGO_MAIN_JSON_LITERAL_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_ARGO_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_ARGO_MAIN_JSON_FILE_OPTVAL_S \
   XOS_APP_CONSOLE_ARGO_MAIN_JSON_LITERAL_OPTVAL_S \

#define XOS_APP_CONSOLE_ARGO_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_ARGO_MAIN_JSON_FILE_OPTION \
   XOS_APP_CONSOLE_ARGO_MAIN_JSON_LITERAL_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_ARGO_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_ARGO_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_ARGO_VERSION_MAIN_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_ARGO_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_ARGO_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_ARGO_VERSION_MAIN_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_ARGO_MAIN_ARGS "[{ filename | literal }]"
#define XOS_APP_CONSOLE_ARGO_MAIN_ARGV "{ filename | literal } Json file/literal source",

namespace xos {
namespace app {
namespace console {
namespace argo {

/// class main_optt
template 
<class TExtends = xos::app::console::argo::version::maint<>,  class TImplements = typename TExtends::implements>

class main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef main_optt derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    main_optt(): run_(0) {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt &copy) {
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
        int err = 0;
        return err;
    }
    virtual int before_json_file_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_json_file_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_json_file_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_json_file_run(argc, argv, env))) {
            int err2 = 0;
            err = json_file_run(argc, argv, env);
            if ((err2 = after_json_file_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_json_file_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_json_file_run;
        return err;
    }
    virtual int json_file_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = set_string_output_json_node_run(argc, argv, env))) {
            if (!(err = string_output_json_node_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int unset_json_file_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int json_file_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...json_literal_run
    virtual int json_literal_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_json_literal_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_json_literal_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_json_literal_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_json_literal_run(argc, argv, env))) {
            int err2 = 0;
            err = json_literal_run(argc, argv, env);
            if ((err2 = after_json_literal_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_json_literal_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_json_literal_run;
        return err;
    }
    virtual int json_literal_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = set_string_output_json_node_run(argc, argv, env))) {
            if (!(err = string_output_json_node_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int unset_json_literal_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int json_literal_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...json_argument_run
    virtual int json_argument_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_json_argument_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_json_argument_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_json_argument_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_json_argument_run(argc, argv, env))) {
            int err2 = 0;
            err = json_argument_run(argc, argv, env);
            if ((err2 = after_json_argument_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_json_argument_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_json_argument_run;
        return err;
    }
    virtual int json_argument_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_json_argument_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int json_argument_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...json_file_argument_run
    virtual int json_file_argument_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_json_file_argument_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_json_file_argument_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_json_file_argument_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_json_file_argument_run(argc, argv, env))) {
            int err2 = 0;
            err = json_file_argument_run(argc, argv, env);
            if ((err2 = after_json_file_argument_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_json_file_argument_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_json_file_argument_run;
        return err;
    }
    virtual int json_file_argument_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_json_file_argument_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int json_file_argument_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...json_literal_argument_run
    virtual int json_literal_argument_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_json_literal_argument_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_json_literal_argument_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_json_literal_argument_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_json_literal_argument_run(argc, argv, env))) {
            int err2 = 0;
            err = json_literal_argument_run(argc, argv, env);
            if ((err2 = after_json_literal_argument_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_json_literal_argument_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_json_literal_argument_run;
        return err;
    }
    virtual int json_literal_argument_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_json_literal_argument_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int json_literal_argument_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////

    /// ...output_json_node_run
    int (derives::*output_json_node_run_)(const io::format::json::node& node, int argc, char_t** argv, char_t** env);
    virtual int output_json_node_run(const io::format::json::node& node, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_json_node_run_) {
            if (!(err = (this->*output_json_node_run_)(node, argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_output_json_node_run(node, argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_output_json_node_run(const io::format::json::node& node, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_output_json_node_run(const io::format::json::node& node, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_json_node_run(const io::format::json::node& node, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_json_node_run(const io::format::json::node& node, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_json_node_run(node, argc, argv, env))) {
            int err2 = 0;
            err = output_json_node_run(node, argc, argv, env);
            if ((err2 = after_output_json_node_run(node, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...string_output_json_node_run
    virtual int string_output_json_node_run(const io::format::json::node& node, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_string_output_json_node_run(const io::format::json::node& node, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_string_output_json_node_run(const io::format::json::node& node, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_string_output_json_node_run(const io::format::json::node& node, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_string_output_json_node_run(node, argc, argv, env))) {
            int err2 = 0;
            err = string_output_json_node_run(node, argc, argv, env);
            if ((err2 = after_string_output_json_node_run(node, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_string_output_json_node_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_json_node_run_ = &derives::all_string_output_json_node_run;
        return err;
    }
    virtual int string_output_json_node_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_string_output_json_node_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_json_node_run_ = 0;
        return err;
    }
    virtual int string_output_json_node_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////

    /// on...json_file_option...
    virtual int on_get_json_file_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_json_file_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_json_file_run(argc, argv, env))) {
            if (!(err = json_file_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_json_file_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            this->set_json_file(optarg);
        } else {
        }
        return err;
    }
    virtual int on_json_file_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_json_file_run(argc, argv, env))) {
            if (!(err = json_file_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_json_file_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_json_file_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_json_file_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_json_file_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_json_file_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* json_file_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_ARGO_MAIN_JSON_FILE_OPTUSE;
        optarg = XOS_APP_CONSOLE_ARGO_MAIN_JSON_FILE_OPTARG;
        return chars;
    }

    /// on...json_literal_option...
    virtual int on_get_json_literal_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_json_literal_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_json_literal_run(argc, argv, env))) {
            if (!(err = json_literal_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_json_literal_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            this->set_json_literal(optarg);
        } else {
        }
        return err;
    }
    virtual int on_json_literal_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_json_literal_run(argc, argv, env))) {
            if (!(err = json_literal_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_json_literal_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_json_literal_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_json_literal_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_json_literal_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_json_literal_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* json_literal_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_ARGO_MAIN_JSON_LITERAL_OPTUSE;
        optarg = XOS_APP_CONSOLE_ARGO_MAIN_JSON_LITERAL_OPTARG;
        return chars;
    }

    /// on_option
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {

        case XOS_APP_CONSOLE_ARGO_MAIN_JSON_FILE_OPTVAL_C:
            err = this->on_json_file_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_ARGO_MAIN_JSON_LITERAL_OPTVAL_C:
            err = this->on_json_literal_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    
    /// option_usage
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {

        case XOS_APP_CONSOLE_ARGO_MAIN_JSON_FILE_OPTVAL_C:
            chars = this->json_file_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_ARGO_MAIN_JSON_LITERAL_OPTVAL_C:
            chars = this->json_literal_option_usage(optarg, longopt);
            break;

        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }

    /// options
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_ARGO_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_ARGO_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// arguments
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_ARGO_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_ARGO_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

    /// ...json_file
    virtual string_t& set_json_file(const string_t& to) {
        string_t& json_file = this->json_file();
        json_file.assign(to);
        return json_file;
    }
    virtual string_t& set_json_file(const char_t* to) {
        string_t& json_file = this->json_file();
        json_file.assign(to);
        return json_file;
    }
    virtual string_t& json_file() const {
        string_t& json_file = (string_t&)json_file_;
        return json_file;
    }
    
    /// ...json_literal
    virtual string_t& set_json_literal(const string_t& to) {
        string_t& json_literal = this->json_literal();
        json_literal.assign(to);
        return json_literal;
    }
    virtual string_t& set_json_literal(const char_t* to) {
        string_t& json_literal = this->json_literal();
        json_literal.assign(to);
        return json_literal;
    }
    virtual string_t& json_literal() const {
        string_t& json_literal = (string_t&)json_literal_;
        return json_literal;
    }
    
protected:
    string_t json_file_, json_literal_;
}; /// class main_optt 
typedef main_optt<> main_opt;

} /// namespace argo 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_ARGO_MAIN_OPT_HPP
