/**
 * @file Log.c
 * @author: Zhang Hai
 */


#include "Log.h"

#include <stdarg.h>
#include <stdio.h>

#include "Time.h"


static string LOG_FILE = "log.txt";


static FILE *Log_getLogFile() {
    static FILE* file = null;
    if (file == null) {
        file = fopen(LOG_FILE, "a");
        fprintf(file, "\n========================================\n");
        fprintf(file, "LOG BEGIN AT %s\n", Time_currentAsString());
        fprintf(file, "========================================\n");
    }
    return file;
}

static void Log_log(string message, string format,
        va_list arguments) {
#ifndef NDEBUG
    FILE *file = Log_getLogFile();
    fprintf(file, "%f: %s ", Time_secondsSinceStart(), message);
    vfprintf(file, format, arguments);
    fprintf(file, "\n");
#endif
}

void Log_info(string format, ...) {
    va_list arguments;
    va_start(arguments, format);
    Log_log("[INFO]", format, arguments);
    va_end(arguments);
}

void Log_warning(string format, ...) {
    va_list arguments;
    va_start(arguments, format);
    Log_log("[WARNING]", format, arguments);
    va_end(arguments);
}

void Log_error(string format, ...) {
    va_list arguments;
    va_start(arguments, format);
    Log_log("[ERROR]", format, arguments);
    va_end(arguments);
}


