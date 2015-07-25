/*
 * test_private.c
 *
 *  Created on: Jul 24, 2015
 *      Author: tz68d9
 */


/*
 * test.c
 *
 *  Created on: Jul 24, 2015
 *      Author: tz68d9
 */

//test shared , privated  and cloned by compiler options

volatile unsigned int test_private0_count;
volatile unsigned int test_private0_1_count=5;
volatile unsigned int test_private0_array[5];

void test_private0(void)
{
	test_private0_count++;
	test_private0_1_count++;
	test_private0_array[0]=100;
}
