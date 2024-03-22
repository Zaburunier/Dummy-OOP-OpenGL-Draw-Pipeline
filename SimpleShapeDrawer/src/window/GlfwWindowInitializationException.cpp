#pragma once
#include "GlfwWindowInitializationException.h"


const char* GlfwWindowInitializationException::what() const noexcept {
        return message.c_str();
}
