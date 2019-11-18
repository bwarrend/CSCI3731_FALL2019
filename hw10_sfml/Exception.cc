#include "Exception.h"

Exception::Exception(const std::string& message)
    :std::runtime_error(message){
}