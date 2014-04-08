/**
 * @file Time.c
 * @author: Zhang Hai
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

