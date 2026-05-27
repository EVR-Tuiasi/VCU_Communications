
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
uint8_t dataDeTrimisTSAC1[8]={0xFF, 0x3F, 0xBF, 0x67, 0x40, 0xBB, 0xBD, 0xE8}; //TSAC1
uint8_t dataDeTrimisTSAC2_0[8]={0xF8, 0x43, 0xE7, 0xF9, 0xFE, 0x7F, 0x9F, 0xE7}; //TSAC2 index 0
uint8_t dataDeTrimisTSAC2_1[8]={0xF9, 0x43, 0xE7, 0xF9, 0xFE, 0x7F, 0x9F, 0xE7}; //TSAC2 index 1
uint8_t dataDeTrimisTSAC3[8]={0xF8, 0x13, 0xE7, 0xF9, 0xFE, 0x7F, 0x9F, 0xE7}; //TSAC3
uint8_t dataDeTrimisTSAC4[8]={0x8A, 0xE2, 0xBF, 0xC1, 0xF8, 0x2F, 0xF8, 0x2F}; //TSAC4
uint8_t dataDeTrimisComm[8]={0xF0, 0x00, 0x00, 0x00, 0x00, 0x0C, 0xFF, 0xE8}; //comunicatii

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
	volatile int i = 1000000;
	while(i--);
	//UartMessaging_SetValue(Uart_TSAC_OverallCurrent, 123);
	//Uart_SyncSend(UART_Channel, dataDeTrimis, 10, 10000000);
	Can_PduType pduInfoInvSt;
	pduInfoInvSt.swPduHandle=0;
	pduInfoInvSt.length=8;
	pduInfoInvSt.sdu=dataDeTrimisInvStDr;
	pduInfoInvSt.id=idCanInvertorStanga | ID_MASK;

	Can_PduType pduInfoInvDr;
	pduInfoInvDr.swPduHandle=0;
	pduInfoInvDr.length=8;
	pduInfoInvDr.sdu=dataDeTrimisInvStDr;
	pduInfoInvDr.id=idCanInvertorDreapta | ID_MASK;

	Can_PduType pduInfoInv;
	pduInfoInv.swPduHandle=0;
	pduInfoInv.length=8;
	pduInfoInv.sdu=dataDeTrimisInv;
	pduInfoInv.id=idCanInvertoare | ID_MASK;


	Can_PduType pduInfoBord;
	pduInfoBord.swPduHandle=0;
	pduInfoBord.length=8;
	pduInfoBord.sdu=dataDeTrimisBord;
	pduInfoBord.id=idCanBord | ID_MASK;

	Can_PduType pduInfoAcc;
	pduInfoAcc.swPduHandle=0;
	pduInfoAcc.length=8;
	pduInfoAcc.sdu=dataDeTrimisAcc;
	pduInfoAcc.id=idCanAcceleratie | ID_MASK;

	Can_PduType pduInfoFrana;
	pduInfoFrana.swPduHandle=0;
	pduInfoFrana.length=8;
	pduInfoFrana.sdu=dataDeTrimisFrana;
	pduInfoFrana.id=idCanFrana | ID_MASK;

	Can_PduType pduInfoTSAC1;
	pduInfoTSAC1.swPduHandle=0;
	pduInfoTSAC1.length=8;
	pduInfoTSAC1.sdu=dataDeTrimisTSAC1;
	pduInfoTSAC1.id=idCanBaterie1 | ID_MASK;

	Can_PduType pduInfoTSAC2_0;
	pduInfoTSAC2_0.swPduHandle=0;
	pduInfoTSAC2_0.length=8;
	pduInfoTSAC2_0.sdu=dataDeTrimisTSAC2_0;
	pduInfoTSAC2_0.id=idCanBaterie2 | ID_MASK;

	Can_PduType pduInfoTSAC2_1;
	pduInfoTSAC2_1.swPduHandle=0;
	pduInfoTSAC2_1.length=8;
	pduInfoTSAC2_1.sdu=dataDeTrimisTSAC2_1;
	pduInfoTSAC2_1.id=idCanBaterie2 | ID_MASK;

	Can_PduType pduInfoTSAC3;
	pduInfoTSAC3.swPduHandle=0;
	pduInfoTSAC3.length=8;
	pduInfoTSAC3.sdu=dataDeTrimisTSAC3;
	pduInfoTSAC3.id=idCanBaterie3 | ID_MASK;

	Can_PduType pduInfoTSAC4;
	pduInfoTSAC4.swPduHandle=0;
	pduInfoTSAC4.length=8;
	pduInfoTSAC4.sdu=dataDeTrimisTSAC4;
	pduInfoTSAC4.id=idCanBaterie4 | ID_MASK;

	Can_PduType pduInfoComm;
	pduInfoComm.swPduHandle=0;
	pduInfoComm.length=8;
	pduInfoComm.sdu=dataDeTrimisComm;
	pduInfoComm.id=idCanComunicatii | ID_MASK;


	//CanMessaging_Test();
	//UartMessaging_Test();

	//Can_43_FLEXCAN_Write(CAN_HTH_HANDLE, &pduInfoInvSt);

	/*Can_43_FLEXCAN_Write(CAN_HTH_HANDLE, &pduInfoInvDr);
	i=400000;
	while(i--);
	Can_43_FLEXCAN_Write(CAN_HTH_HANDLE, &pduInfoInv);
	i=400000;
	while(i--);
	Can_43_FLEXCAN_Write(CAN_HTH_HANDLE, &pduInfoBord);
	i=400000;
	while(i--);
	Can_43_FLEXCAN_Write(CAN_HTH_HANDLE, &pduInfoAcc);
	i=400000;
	while(i--);
	Can_43_FLEXCAN_Write(CAN_HTH_HANDLE, &pduInfoFrana);
	i=400000;
	while(i--);*/
	/*Can_43_FLEXCAN_Write(CAN_HTH_HANDLE, &pduInfoTSAC1);
	i=400000;
	while(i--);
	Can_43_FLEXCAN_Write(CAN_HTH_HANDLE, &pduInfoTSAC2);
	i=400000;
	while(i--);*/
	Can_43_FLEXCAN_Write(CAN_HTH_HANDLE, &pduInfoTSAC2_0);
	i=400000;
	while(i--);
	Can_43_FLEXCAN_Write(CAN_HTH_HANDLE, &pduInfoTSAC2_1);
	i=400000;
	while(i--);
	CanMessaging_AppTest();
    return (0U);
}


#ifdef __cplusplus
}
#endif

/** @} */
