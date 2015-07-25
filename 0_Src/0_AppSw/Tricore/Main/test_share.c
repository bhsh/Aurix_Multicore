/*
 * test.c
 *
 *  Created on: Jul 24, 2015
 *      Author: tz68d9
 */



//test shared , privated  and cloned by compiler options

volatile unsigned int test_share_count2;

void test_share(void)
{
	test_share_count2++;
}
