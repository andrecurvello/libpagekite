/******************************************************************************
utils.c - Utility functions for pagekite.

This file is Copyright 2011, 2012, The Beanstalks Project ehf.

This program is free software: you can redistribute it and/or modify it under
the terms  of the  Apache  License 2.0  as published by the  Apache  Software
Foundation.

This program is distributed in the hope that it will be useful,  but  WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
details.

You should have received a copy of the Apache License along with this program.
If not, see: <http://www.apache.org/licenses/>

Note: For alternate license terms, see the file COPYING.md.

******************************************************************************/
#include <arpa/inet.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>

#include "utils.h"


int utils_test(void)
{
  char buffer1[60];

  strcpy(buffer1, "\r\n\r\n");
  assert(2 == zero_first_crlf(4, buffer1));

  strcpy(buffer1, "abcd\r\n\r\ndefghijklmnop");
  int length = zero_first_crlf(strlen(buffer1), buffer1);

  assert(length == 6);
  assert((buffer1[4] == '\0') && (buffer1[5] == '\0') && (buffer1[6] == '\r'));
  assert(strcmp(buffer1, "abcd") == 0);

  return 1;
}
