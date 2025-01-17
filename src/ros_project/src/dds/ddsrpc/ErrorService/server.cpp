#include "xtypes/state_and_error.hpp"
using namespace state_and_error;

class ErrorHandleImpl : public state_and_error::ErrorHandle {
public:
    state_and_error::ErrorCodeReply analyze_error(const ErrorCode& error)  {
        ErrorCodeReply reply;
        if (error.code() == "1001") {
            reply.description("Unreachable goal");  // 使用 setter 方法
            reply.suggestion("Select a reachable target");  // 使用 setter 方法
        } else {
            reply.description("Unknown error");
            reply.suggestion("Contact support");
        }
        return reply;
    }
};
