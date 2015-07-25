/*
 * test_clone.c
 *
 *  Created on: Jul 24, 2015
 *      Author: tz68d9
 */


//test shared , privated  and cloned by compiler options

volatile unsigned int test_clone_count;

void test_clone(void)
{
	test_clone_count++;
}
