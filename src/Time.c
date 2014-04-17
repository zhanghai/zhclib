/**
 * @file Time.c
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

#include "Time.h"

#include "string.h"


static time_t Time_startTime = 0;


time_t Time_current() {
    return time(null);
}

/**
 * Get the current time as string.
 * @note The returned string is static and not thread-safe.
 * @return The current time as string.
 */
string Time_currentAsString() {
    time_t current = Time_current();
    string currentString = ctime(&current);
    currentString[string_length(currentString) - 1] = '\0';
    return currentString;
}

/**
 * Record the start time for {@link Time_secondsSinceStart}.
 * @note The start time defaults to 0 if this function is never
 *       called.
 */
void Time_start() {
    Time_startTime = Time_current();
}

double Time_secondsSinceStart() {
    return difftime(Time_current(), Time_startTime);
}

