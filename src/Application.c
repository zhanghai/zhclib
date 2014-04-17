/**
 * @file Application.c
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
