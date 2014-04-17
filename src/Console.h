/**
 * @file Console.h
 * @author Zhang Hai
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

#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include "Common.h"


void Console_print(string format, ...);

void Console_printLine(string format, ...);

void Console_printSeparator();

void Console_prompt(string message);

void Console_printError(string format, ...);

void Console_printErrorLine(string format, ...);

string Console_readLine(string message);

size_t Console_readChoice(string message, string choices[],
        size_t choicesSize);

bool Console_readChoiceYN(string message);

bool Console_readChoiceBoolean(string message);

void Console_pause();

void Console_clear();


#endif /* _CONSOLE_H_ */
