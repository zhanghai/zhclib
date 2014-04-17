/**
 * @file Log.c
 * @author: Zhang Hai
 */

/*
 * Copyright (C) 2014 Zhang Hai
 *
 * This file is part of zhclib.
 *
 * zhclib is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * zhclib is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with zhclib.  If not, see <http://www.gnu.org/licenses/>.
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


