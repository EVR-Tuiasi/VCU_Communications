
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
#include "provizoriu.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

#define CAN_TARGET_ID 0x0CF11A12
#define CAN_HTH_HANDLE 0x00000001

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
	//Uart_Init(NULL_PTR);
	Can_43_FLEXCAN_Init(NULL_PTR);
	CanIf_Init(NULL_PTR);

	Dio_WriteChannel(32, STD_HIGH); //CAN3_EN
	volatile uint64 i = 1000000;
	while(i--);
	Dio_WriteChannel(33, STD_HIGH); //CAN3_STB_N
	i = 1000000;
	while(i--);
	Dio_WriteChannel(100, STD_HIGH); //CAN2_EN
	i = 1000000;
	while(i--);
	Dio_WriteChannel(118, STD_HIGH); //CAN2_STB_N
	i = 1000000;
	while(i--);
	Can_43_FLEXCAN_SetControllerMode(Can_43_FLEXCANConf_CanController_CanController_0, CAN_CS_STARTED);
	Can_43_FLEXCAN_SetControllerMode(Can_43_FLEXCANConf_CanController_CanController_1, CAN_CS_STARTED);
	Can_43_FLEXCAN_EnableControllerInterrupts(0);

	Can_PduType pduInfo;
	pduInfo.swPduHandle=0;
	pduInfo.length=8;
	pduInfo.sdu=dataDeTrimis;
	pduInfo.id=CAN_TARGET_ID | 0x80000000U;
	while(1){
		Can_43_FLEXCAN_Write(CAN_HTH_HANDLE, &pduInfo);
		i=400000;
		while(i--);
		/*while(1){
			unsigned int len=sizeof(dataTrimisa)/sizeof(uint8);
			Uart_SyncSend(UART_Channel, dataTrimisa, len, 50000000);
		}*/
	}
    return (0U);
}


#ifdef __cplusplus
}
#endif

/** @} */
