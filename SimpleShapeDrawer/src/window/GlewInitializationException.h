#pragma once
#include <exception>
#include <string>



// https://metanit.com/cpp/tutorial/6.2.php
class GlewInitializationException : public std::exception {
        #pragma region Поля
        private:

        const std::string& message;
        #pragma endregion


        #pragma region Методы
        public:

        GlewInitializationException(const std::string& message) : message{ message } { }


        const char* what() const noexcept override;
        #pragma endregion
};

