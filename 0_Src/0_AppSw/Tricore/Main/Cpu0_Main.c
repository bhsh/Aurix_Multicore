#include "Cpu0_Main.h"
#include "SysSe/Bsp/Bsp.h"
//#include "DemoApp.h"
#include "communication.h"
App_Cpu0 g_AppCpu0; /**< \brief CPU 0 global data */
unsigned long  lock=1; // 1 means available,
unsigned long mask=1;


#pragma protect on
void __private0 test_fun_private0(void)
{
 IfxPort_togglePin(&MODULE_P33, 9);
}

void __share test_fun_share(void)
{
   IfxPort_togglePin(&MODULE_P33, 8);
// test_fun_private0();
}

void __clone test_func_clone(void)
{
   IfxPort_togglePin(&MODULE_P33, 8);
}

unsigned char __clone test_count_private0;
unsigned char  core0_temp;

#pragma protect off


int core0_main (void)
{
	unsigned int i=0;

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
    IfxPort_setPinMode(&MODULE_P33, 8,  IfxPort_Mode_outputPushPullGeneral);
    // configure P33.9 as general output
    IfxPort_setPinMode(&MODULE_P33, 9,  IfxPort_Mode_outputPushPullGeneral);

    IfxPort_setPinMode(&MODULE_P33, 10,  IfxPort_Mode_outputPushPullGeneral);
    // configure P33.9 as general output
    IfxPort_setPinMode(&MODULE_P33, 11,  IfxPort_Mode_outputPushPullGeneral);

    /* background endless loop */
    //while (1)
    {
    	//synchronizeCore0Core1();
    	//communicationCore0Core1_ptr->core0Ready = 1;
    	//IfxPort_togglePin(&MODULE_P33, 8);
    	//IfxPort_togglePin(&MODULE_P33, 9);
    	//IfxPort_togglePin(&MODULE_P33, 10);
    	//IfxPort_togglePin(&MODULE_P33, 11);
    	//IfxStm_waitTicks(&MODULE_STM0, g_AppCpu0.info.stmFreq/1000000);
    	//communicationCore0Core1_ptr->core0Ready = 0;
    	//IfxStm_waitTicks(&MODULE_STM0, g_AppCpu0.info.stmFreq/100);
    }

   // while(lock==0) requestLock(&lock, mask);
   // for(i=0;i<1000;i++)
    while(1)
    {
       //IfxPort_togglePin(&MODULE_P33, 8);
       //IfxPort_togglePin(&MODULE_P33, 9);

       test_fun_share();
      // IfxStm_waitTicks(&MODULE_STM0, g_AppCpu0.info.stmFreq/100);
   	   test_count_private0++;
       core0_temp=test_count_private0;
       IfxStm_waitTicks(&MODULE_STM0, 30000000);
    }
    //releaseLock(&lock, mask);

    while(1);
    return (1);
}
