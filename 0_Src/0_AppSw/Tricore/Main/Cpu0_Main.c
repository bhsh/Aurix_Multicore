#include "Cpu0_Main.h"
#include "SysSe/Bsp/Bsp.h"
//#include "DemoApp.h"
#include "communication.h"

typedef struct
{
    float32 sysFreq;                /**< \brief Actual SPB frequency */
    float32 cpuFreq;                /**< \brief Actual CPU frequency */
    float32 pllFreq;                /**< \brief Actual PLL frequency */
    float32 stmFreq;                /**< \brief Actual STM frequency */
} AppInfo2;

#pragma section farbss "bss_cpu0"
#pragma section fardata "data_cpu0"

App_Cpu0 g_AppCpu0; /**< \brief CPU 0 global data */


#pragma section farbss "bss_cpu1"
#pragma section fardata "data_cpu1"

App_Cpu0 g_AppCpu1;


#pragma section farbss "bss_cpu2"
#pragma section fardata "data_cpu2"

AppInfo2  g_AppCpu3;



unsigned long mask=1;

//#pragma section farbss "bss_cpu2"
//#pragma section fardata "data_cpu2"

unsigned long  lock=1; // 1 means available,
//unsigned long  lock2=6; // 1 means available,

//#pragma section fardata restore
//extern  unsigned long core1_test;
//extern  unsigned long core1_test2;

volatile int __private1 test_var1;

#pragma section farbss "bss_cpu2"
#pragma section fardata "data_cpu2"

AppInfo2  g_AppCpu3;

//#pragma data_core_association  __private1  ""
volatile int __private0 test_var0;


void __private0 test_fun(void);

void __share test_share_fun(void);
void __private0 test_fun2(void);


extern void test_private0(void);
extern void test_clone(void);
extern void test_share(void);
extern void test_private1(void);

int core0_main (void)
{  // lock++;
   // lock2++;
	unsigned int i=0;

	//core1_test++;
	//core1_test2++;
	g_AppCpu1.info.pllFreq=1;
	g_AppCpu3.sysFreq=1;


	test_private0();
	test_clone();
	test_share();
	test_private1();
    /*
     * !!WATCHDOG0 AND SAFETY WATCHDOG ARE DISABLED HERE!!
     * Enable the watchdog in the demo if it is required and also service the watchdog periodically
     * */
    IfxScuWdt_disableCpuWatchdog (IfxScuWdt_getCpuWatchdogPassword ());
    IfxScuWdt_disableSafetyWatchdog (IfxScuWdt_getSafetyWatchdogPassword ());

    /* Initialise the application state */
    g_AppCpu0.info.pllFreq = IfxScuCcu_getPllFrequency();
    g_AppCpu0.info.cpuFreq = IfxScuCcu_getCpuFrequency(IfxCpu_getCoreId());
    g_AppCpu0.info.sysFreq = IfxScuCcu_getSpbFrequency();
    g_AppCpu0.info.stmFreq = IfxStm_getFrequency(&MODULE_STM0);

    /* Enable the global interrupts of this CPU */
    IfxCpu_enableInterrupts();

    /* Demo init */
    // configure P33.8 as general output
    IfxPort_setPinMode(&MODULE_P02, 0,  IfxPort_Mode_outputPushPullGeneral);
    // configure P33.9 as general output
    IfxPort_setPinMode(&MODULE_P02, 1,  IfxPort_Mode_outputPushPullGeneral);

    /* background endless loop */
    //while (1)
    {
    	//synchronizeCore0Core1();
    	//communicationCore0Core1_ptr->core0Ready = 1;
    	IfxPort_togglePin(&MODULE_P02, 0);
    	//IfxStm_waitTicks(&MODULE_STM0, g_AppCpu0.info.stmFreq/1000000);
    	//communicationCore0Core1_ptr->core0Ready = 0;
    	//IfxStm_waitTicks(&MODULE_STM0, g_AppCpu0.info.stmFreq/100);
    }

    //while(lock==0) requestLock(&lock, mask);

	 test_share_fun();
    while(1)
    {
      for(i=0;i<1000;i++)
      {
       IfxPort_togglePin(&MODULE_P02, 0);
       IfxStm_waitTicks(&MODULE_STM0, g_AppCpu0.info.stmFreq/100);
      }
    }
   // releaseLock(&lock, mask);


    //while(1);
    return (1);
}

//#pragma section protection 

volatile unsigned int test_count;
volatile unsigned int test_share_count;
void __clone test_fun_clone1(void);


#pragma protect on


void __private0 test_fun(void)
{

test_count++;
test_fun();



}

void __share test_share_fun(void)
{

test_share_count++;
test_fun2();

}

void __private0 test_fun2(void)
{

test_count++;
//test_fun();
test_fun_clone1();
//test_var1++;
test_var0++;
}

void __clone test_fun_clone1(void)
{
test_count++;
}

#pragma code_core_association share

void  test_fun_data_core_share(void)
{
test_count++;
}

#pragma code_core_association private0

void  test_fun_data_core_private0(void)
{
test_count++;
}

#pragma code_core_association private1

void  test_fun_data_core_private1(void)
{
test_count++;
}
