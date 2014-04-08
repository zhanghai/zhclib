/**
 * @file Application.c
 * @author Zhang Hai
 */

#include "Application.h"

#include <stdio.h>
#include <stdlib.h>

#include "Log.h"


void Application_exit(int status) {
    exit(status);
}

void Application_fatalError(string message) {
    fprintf(stderr, "Fatal error: %s\n", message);
    Log_error("Application: Fatal error: %s", message);
    Application_exit(1);
}
