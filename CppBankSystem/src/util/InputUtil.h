#ifndef INPUT_UTIL_H
#define INPUT_UTIL_H

#include <string>

class InputUtil {
    public:
        static std::string readLine(const std::string& msg);
        static int readInt(const std::string& msg);
        static double readDouble(const std::string& msg);
};

#endif