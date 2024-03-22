#pragma once
#include "GlewInitializationException.h"


const char* GlewInitializationException::what() const noexcept {
        return message.c_str();
}
