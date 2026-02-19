
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
uint8 UART_Channel;
extern uint8 dataTrimisa[8];
uint8 dataDeTrimis[8]={1, 2, 3, 4, 5, 6, 7, 8};

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

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

	Can_PduType pduInfo;
	pduInfo.swPduHandle=0;
	pduInfo.length=8;
	pduInfo.sdu=dataDeTrimis;
	pduInfo.id=CAN_TARGET_ID | 0x80000000U;
	volatile int i;
	while(1){
		Uart_SyncReceive(UART_Channel, pduInfo.sdu, 8, 10000000);
		Can_43_FLEXCAN_Write(CAN_HTH_HANDLE, &pduInfo);
		i=400000;
		while(i--);
	}
    return (0U);
}


#ifdef __cplusplus
}
#endif

/** @} */
