/*
Let's build a very small library "libtest" which provide a single API "get_test"

reference link: https://blog.fesnel.com/blog/2009/08/19/hiding-whats-exposed-in-a-shared-library/
*/

/* test.h - External API for libtest */

#ifndef __TEST_H__
#define  __TEST_H__

int get_test(void);

#endif /* ! __TEST_H__ */

/*  End of test.h  */




/* test.c -- Internal functions for libtest */

#include <stdio.h>

/* Include public API definitions. */
#include "test.h"


/* Simple function internal to this file only. */
static int get_internal_test(void)
{
	return 3;
}

/* Exported API function. */
int get_test(void)
{

	return 4;
}

/* End of test.c  */


/* 
Exposed functions:

objdump -t libab.so | grep get
00000000000005dc l     F .text  000000000000000b              get_internal_test
0000000000000634 l     F .text  000000000000000b              get_test

*/

/* 
We've seen that static internal functions are also exposed in the .h file. 

To hide the internal implementation functions (static functions) we can use "strip" command.

*/



