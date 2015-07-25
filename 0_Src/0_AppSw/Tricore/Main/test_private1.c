/*
 * test_private1.c
 *
 *  Created on: Jul 24, 2015
 *      Author: tz68d9
 */



volatile unsigned int test_private1_count;

void test_private1(void)
{
	test_private1_count++;
}
