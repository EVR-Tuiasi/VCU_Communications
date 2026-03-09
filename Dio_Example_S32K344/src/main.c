
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
uint8_t dataDeTrimisInvStDr[8]={0xBB, 0x7F, 0x08, 0xFA, 0xFB, 0x32, 0xFD, 0xFE}; //invertoare stanga si dreapta
uint8_t dataDeTrimisInv[8]={0x80, 0x00, 0x00, 0x00, 0x00, 0xFa, 0x0E, 0xD9}; //invert
uint8_t dataDeTrimisBord[8]={0xD0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}; //bord
uint8_t dataDeTrimisAcc[8]={0x54, 0x07, 0x2B, 0x23, 0x2F, 0x23, 0x3E, 0x80}; //acceleratie
uint8_t dataDeTrimisFrana[8]={0x54, 0x03, 0x2B, 0x23, 0x2F, 0x23, 0x3E, 0x80}; //frana
uint8_t dataDeTrimisTSAC[8]={0x00, 0x00, 0x0F, 0x67, 0x40, 0xBB, 0xBD, 0xE8}; //TSAC

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
	Can_43_FLEXCAN_Init(NULL_PTR);
	CanIf_Init(NULL_PTR);

	CanMessaging_Init();
	UartMessaging_Init();
	//UartMessaging_SetValue(Uart_TSAC_OverallCurrent, 123);
	//Uart_SyncSend(UART_Channel, dataDeTrimis, 10, 10000000);
	Can_PduType pduInfoInvSt;
	pduInfoInvSt.swPduHandle=0;
	pduInfoInvSt.length=8;
	pduInfoInvSt.sdu=dataDeTrimisInvStDr;
	pduInfoInvSt.id=0x110 | 0x80000000U;

	Can_PduType pduInfoInvDr;
	pduInfoInvDr.swPduHandle=0;
	pduInfoInvDr.length=8;
	pduInfoInvDr.sdu=dataDeTrimisInvStDr;
	pduInfoInvDr.id=0x111 | 0x80000000U;

	Can_PduType pduInfoInv;
	pduInfoInv.swPduHandle=0;
	pduInfoInv.length=8;
	pduInfoInv.sdu=dataDeTrimisInv;
	pduInfoInv.id=0x112 | 0x80000000U;


	Can_PduType pduInfoBord;
	pduInfoBord.swPduHandle=0;
	pduInfoBord.length=8;
	pduInfoBord.sdu=dataDeTrimisBord;
	pduInfoBord.id=0x113 | 0x80000000U;

	Can_PduType pduInfoAcc;
	pduInfoAcc.swPduHandle=0;
	pduInfoAcc.length=8;
	pduInfoAcc.sdu=dataDeTrimisAcc;
	pduInfoAcc.id=0x330 | 0x80000000U;

	Can_PduType pduInfoFrana;
	pduInfoFrana.swPduHandle=0;
	pduInfoFrana.length=8;
	pduInfoFrana.sdu=dataDeTrimisFrana;
	pduInfoFrana.id=0x331 | 0x80000000U;

	Can_PduType pduInfoTSAC;
	pduInfoTSAC.swPduHandle=0;
	pduInfoTSAC.length=8;
	pduInfoTSAC.sdu=dataDeTrimisTSAC;
	pduInfoTSAC.id=0x114 | 0x80000000U;

	volatile int j;
	while(1){
		Can_43_FLEXCAN_Write(CAN_HTH_HANDLE, &pduInfoInvSt);
		j=100000;
		while(j--);
	}

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
