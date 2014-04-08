/**
 * @file Time.h
 * @author: Zhang Hai
 */

#ifndef _TIME_H_
#define _TIME_H_


#include "primitives.h"

#include <time.h>


time_t Time_current();

string Time_currentAsString();

void Time_start();

double Time_secondsSinceStart();


#endif /* _TIME_H_ */
