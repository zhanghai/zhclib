/**
 * @file Console.h
 * @author Zhang Hai
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
