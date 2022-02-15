#pragma once


#include "Precompiled.hpp"
#include "Debug/Color.hpp"

namespace Feather {
    class Log {
    public:
        enum class Level { TRACE, INFO, WARN, ERROR, FATAL };
        static void SetPriority(Level level) { priority = level; }

        static void Print(Level level, const char* message, ...);
    private:
        static std::mutex mtx;
        static Level priority;
        static const char* bagdes[];
        static std::pair<Color::Foreground, Color::Background> colors[];
    };
}

#ifdef LOGGING
    #define Trace(message, ...) Feather::Log::Print(Feather::Log::Level::TRACE, message __VA_OPT__(,) __VA_ARGS__)
    #define Info(message, ...)  Feather::Log::Print(Feather::Log::Level::INFO,  message __VA_OPT__(,) __VA_ARGS__)
    #define Warn(message, ...)  Feather::Log::Print(Feather::Log::Level::WARN,  message __VA_OPT__(,) __VA_ARGS__)
    #define Error(message, ...) Feather::Log::Print(Feather::Log::Level::ERROR, message __VA_OPT__(,) __VA_ARGS__)
    #define Fatal(message, ...) Feather::Log::Print(Feather::Log::Level::FATAL, message __VA_OPT__(,) __VA_ARGS__)
#else
    #define Trace(...)
    #define Info(...)
    #define Warn(...)
    #define Error(...)
    #define Fatal(...)
#endif
