#include "Cpu\Std\Ifx_Types.h"
#include "Cpu\Std\IfxCpu_Intrinsics.h"
#include "Scu\Std\IfxScuWdt.h"
#include "Port/Std/IfxPort.h"
#include "communication.h"
#include "Cpu0_Main.h"
#include "SysSe/Bsp/Bsp.h"

extern unsigned long lock;
extern unsigned long mask;

#pragma section nearbss "zbss_cpu0"
#pragma section neardata "zdata_cpu0"

 unsigned char core1_test;
 unsigned long core1_test2;

#pragma section nearbss "zbss_cpu1"
#pragma section neardata "zdata_cpu1"

 unsigned char core1_test3;
 unsigned long core1_test4;

#pragma section nearbss "zbss_cpu2"
#pragma section neardata "zdata_cpu2"

 unsigned char core1_test5;
 unsigned long core1_test6;

//#pragma section nearbss restore

extern App_Cpu0 g_AppCpu0;
//extern float32  g_AppCpu3;
extern void __private0 test_fun(void);
void __private1 test_fun3(void);
void __share test_fun4(void);
void __private1 test_fun5(void);

extern unsigned char __clone  test_count_private0;
unsigned char  core1_temp;

int core1_main (void)
{
	unsigned int i=0;

	core1_test++;
	core1_test2++;
	core1_test3++;
	core1_test4++;
	core1_test5++;
	core1_test6++;
	//test_fun();
	//test_fun3();
//	g_AppCpu3++;
    __enable ();
    /*
     * !!WATCHDOG1 IS DISABLED HERE!!
     * Enable the watchdog in the demo if it is required and also service the watchdog periodically
     * */
    IfxScuWdt_disableCpuWatchdog (IfxScuWdt_getCpuWatchdogPassword ());

   //while (1)
    {
    	//synchronizeCore0Core1();
    	//IfxPort_togglePin(&MODULE_P02, 1);
    }

   // while(lock== 0) requestLock(&lock, mask);
   while(1)
   {
     // for(i=0;i<1000;i++)
    //  {
       //IfxPort_togglePin(&MODULE_P02, 1);
       //IfxStm_waitTicks(&MODULE_STM1, g_AppCpu0.info.stmFreq/100);
     // }
	   test_fun5();
       IfxStm_waitTicks(&MODULE_STM0, 20000000);
       test_count_private0+=10;
       core1_temp=test_count_private0;
      //releaseLock(&lock, mask);
   }
   //while (1);
    return (1);
}
volatile unsigned int test_count_private1;
void __clone test_fun6(void);
#pragma protect on
void __private1 test_fun3(void)
{

//test_fun();
test_count_private1++;
//test_fun();
test_fun4();
}
void __share test_fun4(void)
{

//test_fun();
test_count_private1++;
//test_fun();
test_fun5();

}
void __private1 test_fun5(void)
{

//test_fun();
test_count_private1++;
//test_fun();
IfxPort_togglePin(&MODULE_P33, 10);

}

void __clone test_fun6(void)
{

//test_fun();
test_count_private1++;
//test_fun();
}
