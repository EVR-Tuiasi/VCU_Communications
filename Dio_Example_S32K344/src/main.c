
#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu.h"
#include "Port.h"
#include "Platform.h"
#include "Can_GeneralTypes.h"
#include "Can_43_FLEXCAN.h"
#include "CanIf.h"
#include "SchM_Can_43_FLEXCAN.h"
#include "CDD_Uart.h"
#include "check_example.h"
#include "Dio.h"
#include "Mcl.h"
#include "CanMessaging.h"
#include "UartMessaging.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

uint8_t dataDeTrimis[8]={0, 0, 0, 0, 0, 0, 0x13, 0x88};

int main(void)
{
	Mcu_Init(NULL_PTR);
	Mcu_InitClock(McuModeSettingConf_0);
	while(MCU_PLL_LOCKED != Mcu_GetPllStatus())
	{
		 ;
	}
	Mcu_DistributePllClock();
	Mcu_SetMode(McuModeSettingConf_0);
	Mcl_Init(NULL_PTR);
	Port_Init(NULL_PTR);
	Platform_Init(NULL_PTR);
	CanMessaging_Init();
	UartMessaging_Init();

	/*Can_PduType pduInfo;
	pduInfo.swPduHandle=0;
	pduInfo.length=8;
	pduInfo.sdu=dataDeTrimis;
	pduInfo.id=0x114 | 0x80000000U;
	Can_43_FLEXCAN_Write(CAN_HTH_HANDLE, &pduInfo);*/
	UartMessaging_SetValue(Uart_TSAC_OverallCurrent, 123);
	//Uart_SyncSend(UART_Channel, dataDeTrimis, 10, 10000000);
	volatile int i;
	while(1){
		UartMessaging_Update();
		i=400000;
		while(i--);
	}
    return (0U);
}


#ifdef __cplusplus
}
#endif

/** @} */
