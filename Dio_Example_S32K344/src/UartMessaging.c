#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "stdint.h"
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
#include "UartMessaging.h"
#include "Messaging_Types.h"
#include "provizoriu.h"

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

InvertersMonitoredValues_t invertoareUart;
PedalsMonitoredValues_t pedaleUart;
TsacMonitoredValues_t baterieUart;
DashboardMonitoredValues_t bordUart;

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

void UartMessaging_Init(void){
	Uart_Init(NULL_PTR);
}

void UartMessaging_Test(void){
	baterieUart.MedianCellTemperature = Uart_TSAC_MedianCellTemperature;
	baterieUart.HighestCellTemperature = Uart_TSAC_HighestCellTemperature;
	baterieUart.LowestCellTemperature = Uart_TSAC_LowestCellTemperature;
	baterieUart.MedianCellVoltage = Uart_TSAC_MedianCellVoltage;
	baterieUart.HighestCellVoltage = Uart_TSAC_HighestCellVoltage;
	baterieUart.LowestCellVoltage = Uart_TSAC_LowestCellVoltage;
	baterieUart.OverallVoltage = Uart_TSAC_OverallVoltage;
	baterieUart.OverallCurrent = Uart_TSAC_OverallCurrent;
	//baterieUart.CellVoltage[CELLS_NUM];
	//baterieUart.ThermistorTemperature[THERMISTOR_NUM];
	baterieUart.AmsError = 1;
	baterieUart.ImdError = 1;
	baterieUart.TransceiverError = 1;
	baterieUart.ShuntError = 1;
	baterieUart.Bms0Error = 1;
	baterieUart.Bms1Error = 1;

	pedaleUart.AcceleratorSensor1Voltage = Uart_PEDALS_AcceleratorSensor1Voltage;
	pedaleUart.AcceleratorSensor2Voltage = Uart_PEDALS_AcceleratorSensor2Voltage;
	pedaleUart.AcceleratorSensor1TravelPercentage = Uart_PEDALS_AcceleratorSensor1TravelPercentage;
	pedaleUart.AcceleratorSensor2TravelPercentage = Uart_PEDALS_AcceleratorSensor2TravelPercentage;
	pedaleUart.BrakeSensor1Voltage = Uart_PEDALS_BrakeSensor1Voltage;
	pedaleUart.BrakeSensor2Voltage = Uart_PEDALS_BrakeSensor2Voltage;
	pedaleUart.BrakeSensor1TravelPercentage = Uart_PEDALS_BrakeSensor1TravelPercentage;
	pedaleUart.BrakeSensor2TravelPercentage = Uart_PEDALS_BrakeSensor2TravelPercentage;
	pedaleUart.PressureSensorVoltage = Uart_PEDALS_PressureSensorVoltage;
	pedaleUart.PressureSensorBars = Uart_PEDALS_PressureSensorBars;
	pedaleUart.Accel_Sensor1_ShortToGnd = 1;
	pedaleUart.Accel_Sensor1_ShortToVcc = 1;
	pedaleUart.Accel_Sensor1_OutOfRangeOutput = 1;
	pedaleUart.Accel_Sensor2_ShortToGnd = 1;
	pedaleUart.Accel_Sensor2_ShortToVcc = 1;
	pedaleUart.Accel_Sensor2_OutOfRangeOutput = 1;
	pedaleUart.Accel_Implausibility = 1;
	pedaleUart.Brake_Sensor1_ShortToGnd = 1;
	pedaleUart.Brake_Sensor1_ShortToVcc = 1;
	pedaleUart.Brake_Sensor1_OutOfRangeOutput = 1;
	pedaleUart.Brake_Sensor2_ShortToGnd = 1;
	pedaleUart.Brake_Sensor2_ShortToVcc = 1;
	pedaleUart.Brake_Sensor2_OutOfRangeOutput = 1;
	pedaleUart.Brake_Implausibility = 1;

	invertoareUart.LeftInverterTemperature = Uart_INVERTERS_LeftInverterTemperature;
	invertoareUart.LeftMotorTemperature = Uart_INVERTERS_LeftMotorTemperature;
	invertoareUart.LeftInverterInputVoltage = Uart_INVERTERS_LeftInverterInputVoltage;
	invertoareUart.LeftInverterCurrent = Uart_INVERTERS_LeftInverterCurrent;
	invertoareUart.LeftMotorRpm = Uart_INVERTERS_LeftMotorRpm;
	invertoareUart.LeftMotorSpeedKmh = Uart_INVERTERS_LeftMotorSpeedKmh;
	invertoareUart.LeftInverterThrottle = Uart_INVERTERS_LeftInverterThrottle;
	invertoareUart.LeftInverterThrottleFeedback = Uart_INVERTERS_LeftInverterThrottleFeedback;
	invertoareUart.RightInverterTemperature = Uart_INVERTERS_RightInverterTemperature;
	invertoareUart.RightMotorTemperature = Uart_INVERTERS_RightMotorTemperature;
	invertoareUart.RightInverterInputVoltage = Uart_INVERTERS_RightInverterInputVoltage;
	invertoareUart.RightInverterCurrent = Uart_INVERTERS_RightInverterCurrent;
	invertoareUart.RightMotorRpm = Uart_INVERTERS_RightMotorRpm;
	invertoareUart.RightMotorSpeedKmh = Uart_INVERTERS_RightMotorSpeedKmh;
	invertoareUart.RightInverterSentThrottle = Uart_INVERTERS_RightInverterSentThrottle;
	invertoareUart.RightInverterThrottleFeedback = Uart_INVERTERS_RightInverterThrottleFeedback;
	invertoareUart.IsCarInReverse = 1;
	invertoareUart.IsCarRunning = 1;

	bordUart.ActivationButtonPressed = 1;
	bordUart.CarReverseCommandPressed = 1;
	bordUart.IsDisplayWorking = 1;
	bordUart.IsSegmentsDriverWorking = 1;
	//E OK SA FIE ACELEASI STRUCTURI SAU SA FAC UNELE SPECIFICE PT TEST?
	while(1){
		//DE COMPLETAT
	}
}

void UartMessaging_Update(void){

}

void UartMessaging_SendValue(UartMonitoredValue_t DesiredValueType, uint32_t Value){
	switch(DesiredValueType){
		case Uart_TSAC_MedianCellTemperature:
			baterieUart.MedianCellTemperature = Value;
			break;
		case Uart_TSAC_HighestCellTemperature:
			baterieUart.HighestCellTemperature = Value;
			break;
		case Uart_TSAC_LowestCellTemperature:
			baterieUart.LowestCellTemperature = Value;
			break;
		case Uart_TSAC_MedianCellVoltage:
			baterieUart.MedianCellVoltage = Value;
			break;
		case Uart_TSAC_HighestCellVoltage:
			baterieUart.HighestCellVoltage = Value;
			break;
		case Uart_TSAC_LowestCellVoltage:
			baterieUart.LowestCellVoltage = Value;
			break;
		case Uart_TSAC_OverallVoltage:
			baterieUart.OverallVoltage = Value;
			break;
		case Uart_TSAC_OverallCurrent:
			baterieUart.OverallCurrent = Value;
			break;
		case Uart_TSAC_IsAmsSafe:
			baterieUart.AmsError = Value;
			break;
		case Uart_TSAC_IsImdSafe:
			baterieUart.ImdError = Value;
			break;
		case Uart_TSAC_IsTransceiverWorking:
			baterieUart.TransceiverError = Value;
			break;
		case Uart_TSAC_IsShuntWorking:
			baterieUart.ShuntError = Value;
			break;
		case Uart_TSAC_IsBms0Working:
			baterieUart.Bms0Error = Value;
			break;
		case Uart_TSAC_IsBms1Working:
			baterieUart.Bms1Error = Value;
			break;
		case Uart_PEDALS_AcceleratorSensor1Voltage:
			pedaleUart.AcceleratorSensor1Voltage = Value;
			break;
		case Uart_PEDALS_AcceleratorSensor2Voltage:
			pedaleUart.AcceleratorSensor2Voltage = Value;
			break;
		case Uart_PEDALS_AcceleratorSensor1TravelPercentage:
			pedaleUart.AcceleratorSensor1TravelPercentage = Value;
			break;
		case Uart_PEDALS_AcceleratorSensor2TravelPercentage:
			pedaleUart.AcceleratorSensor2TravelPercentage = Value;
			break;
		case Uart_PEDALS_BrakeSensor1Voltage:
			pedaleUart.BrakeSensor1Voltage = Value;
			break;
		case Uart_PEDALS_BrakeSensor2Voltage:
			pedaleUart.BrakeSensor2Voltage = Value;
			break;
		case Uart_PEDALS_BrakeSensor1TravelPercentage:
			pedaleUart.BrakeSensor1TravelPercentage = Value;
			break;
		case Uart_PEDALS_BrakeSensor2TravelPercentage:
			pedaleUart.BrakeSensor2TravelPercentage = Value;
			break;
		case Uart_PEDALS_PressureSensorVoltage:
			pedaleUart.PressureSensorVoltage = Value;
			break;
		case Uart_PEDALS_PressureSensorBars:
			pedaleUart.PressureSensorBars = Value;
			break;
		case Uart_PEDALS_Accel_Sensor1_ShortToGnd:
			pedaleUart.Accel_Sensor1_ShortToGnd = Value;
			break;
		case Uart_PEDALS_Accel_Sensor1_ShortToVcc:
			pedaleUart.Accel_Sensor1_ShortToVcc = Value;
			break;
		case Uart_PEDALS_Accel_Sensor1_OutOfRangeOutput:
			pedaleUart.Accel_Sensor1_OutOfRangeOutput = Value;
			break;
		case Uart_PEDALS_Accel_Sensor2_ShortToGnd:
			pedaleUart.Accel_Sensor2_ShortToGnd = Value;
			break;
		case Uart_PEDALS_Accel_Sensor2_ShortToVcc:
			pedaleUart.Accel_Sensor2_ShortToVcc = Value;
			break;
		case Uart_PEDALS_Accel_Sensor2_OutOfRangeOutput:
			pedaleUart.Accel_Sensor2_OutOfRangeOutput = Value;
			break;
		case Uart_PEDALS_Accel_Implausibility:
			pedaleUart.Accel_Implausibility = Value;
			break;
		case Uart_PEDALS_Brake_Sensor1_ShortToGnd:
			pedaleUart.Brake_Sensor1_ShortToGnd = Value;
			break;
		case Uart_PEDALS_Brake_Sensor1_ShortToVcc:
			pedaleUart.Brake_Sensor1_ShortToVcc = Value;
			break;
		case Uart_PEDALS_Brake_Sensor1_OutOfRangeOutput:
			pedaleUart.Brake_Sensor1_OutOfRangeOutput = Value;
			break;
		case Uart_PEDALS_Brake_Sensor2_ShortToGnd:
			pedaleUart.Brake_Sensor2_ShortToGnd = Value;
			break;
		case Uart_PEDALS_Brake_Sensor2_ShortToVcc:
			pedaleUart.Brake_Sensor2_ShortToVcc = Value;
			break;
		case Uart_PEDALS_Brake_Sensor2_OutOfRangeOutput:
			pedaleUart.Brake_Sensor2_OutOfRangeOutput = Value;
			break;
		case Uart_PEDALS_Brake_Implausibility:
			pedaleUart.Brake_Implausibility = Value;
			break;
		case Uart_INVERTERS_LeftInverterTemperature:
			invertoareUart.LeftInverterTemperature = Value;
			break;
		case Uart_INVERTERS_LeftMotorTemperature:
			invertoareUart.LeftMotorTemperature = Value;
			break;
		case Uart_INVERTERS_LeftInverterInputVoltage:
			invertoareUart.LeftInverterInputVoltage = Value;
			break;
		case Uart_INVERTERS_LeftInverterCurrent:
			invertoareUart.LeftInverterCurrent = Value;
			break;
		case Uart_INVERTERS_LeftMotorRpm:
			invertoareUart.LeftMotorRpm = Value;
			break;
		case Uart_INVERTERS_LeftMotorSpeedKmh:
			invertoareUart.LeftMotorSpeedKmh = Value;
			break;
		case Uart_INVERTERS_LeftInverterThrottle:
			invertoareUart.LeftInverterThrottle = Value;
			break;
		case Uart_INVERTERS_LeftInverterThrottleFeedback:
			invertoareUart.LeftInverterThrottleFeedback = Value;
			break;
		case Uart_INVERTERS_RightInverterTemperature:
			invertoareUart.RightInverterTemperature = Value;
			break;
		case Uart_INVERTERS_RightMotorTemperature:
			invertoareUart.RightMotorTemperature = Value;
			break;
		case Uart_INVERTERS_RightInverterInputVoltage:
			invertoareUart.RightInverterInputVoltage = Value;
			break;
		case Uart_INVERTERS_RightInverterCurrent:
			invertoareUart.RightInverterCurrent = Value;
			break;
		case Uart_INVERTERS_RightMotorRpm:
			invertoareUart.RightMotorRpm = Value;
			break;
		case Uart_INVERTERS_RightMotorSpeedKmh:
			invertoareUart.RightMotorSpeedKmh = Value;
			break;
		case Uart_INVERTERS_RightInverterSentThrottle:
			invertoareUart.RightInverterSentThrottle = Value;
			break;
		case Uart_INVERTERS_RightInverterThrottleFeedback:
			invertoareUart.RightInverterThrottleFeedback = Value;
			break;
		case Uart_INVERTERS_IsCarInReverse:
			invertoareUart.IsCarInReverse = Value;
			break;
		case Uart_INVERTERS_IsCarRunning:
			invertoareUart.IsCarRunning = Value;
			break;
		case Uart_DASHBOARD_ActivationButtonPressed:
			bordUart.ActivationButtonPressed = Value;
			break;
		case Uart_DASHBOARD_CarReverseCommandPressed:
			bordUart.CarReverseCommandPressed = Value;
			break;
		case Uart_DASHBOARD_IsDisplayWorking:
			bordUart.IsDisplayWorking = Value;
			break;
		case Uart_DASHBOARD_IsSegmentsDriverWorking:
			bordUart.IsSegmentsDriverWorking = Value;
			break;
	}
}

uint32_t UartMessaging_ReadValue(UartMonitoredValue_t DesiredValueType){

}


#ifdef __cplusplus
}
#endif
