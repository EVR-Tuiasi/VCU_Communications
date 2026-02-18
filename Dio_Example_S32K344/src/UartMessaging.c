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
	UartMessaging_SendValue(Uart_TSAC_MedianCellTemperature, Uart_TSAC_MedianCellTemperature);
	UartMessaging_SendValue(Uart_TSAC_HighestCellTemperature, Uart_TSAC_HighestCellTemperature);
	UartMessaging_SendValue(Uart_TSAC_LowestCellTemperature, Uart_TSAC_LowestCellTemperature);
	UartMessaging_SendValue(Uart_TSAC_MedianCellVoltage, Uart_TSAC_MedianCellVoltage);
	UartMessaging_SendValue(Uart_TSAC_HighestCellVoltage, Uart_TSAC_HighestCellVoltage);
	UartMessaging_SendValue(Uart_TSAC_LowestCellVoltage, Uart_TSAC_LowestCellVoltage);
	UartMessaging_SendValue(Uart_TSAC_OverallVoltage, Uart_TSAC_OverallVoltage);
	UartMessaging_SendValue(Uart_TSAC_OverallCurrent, Uart_TSAC_OverallCurrent);
	//baterieUart.CellVoltage[CELLS_NUM];
	//baterieUart.ThermistorTemperature[THERMISTOR_NUM];
	UartMessaging_SendValue(Uart_TSAC_IsAmsSafe, 1);
	UartMessaging_SendValue(Uart_TSAC_IsImdSafe, 1);
	UartMessaging_SendValue(Uart_TSAC_IsTransceiverWorking, 1);
	UartMessaging_SendValue(Uart_TSAC_IsShuntWorking, 1);
	UartMessaging_SendValue(Uart_TSAC_IsBms0Working, 1);
	UartMessaging_SendValue(Uart_TSAC_IsBms1Working, 1);

	UartMessaging_SendValue(Uart_PEDALS_AcceleratorSensor1Voltage, Uart_PEDALS_AcceleratorSensor1Voltage);
	UartMessaging_SendValue(Uart_PEDALS_AcceleratorSensor2Voltage, Uart_PEDALS_AcceleratorSensor2Voltage);
	UartMessaging_SendValue(Uart_PEDALS_AcceleratorSensor1TravelPercentage, Uart_PEDALS_AcceleratorSensor1TravelPercentage);
	UartMessaging_SendValue(Uart_PEDALS_AcceleratorSensor2TravelPercentage, Uart_PEDALS_AcceleratorSensor2TravelPercentage);
	UartMessaging_SendValue(Uart_PEDALS_BrakeSensor1Voltage, Uart_PEDALS_BrakeSensor1Voltage);
	UartMessaging_SendValue(Uart_PEDALS_BrakeSensor2Voltage, Uart_PEDALS_BrakeSensor2Voltage);
	UartMessaging_SendValue(Uart_PEDALS_BrakeSensor1TravelPercentage, Uart_PEDALS_BrakeSensor1TravelPercentage);
	UartMessaging_SendValue(Uart_PEDALS_BrakeSensor2TravelPercentage, Uart_PEDALS_BrakeSensor2TravelPercentage);
	UartMessaging_SendValue(Uart_PEDALS_PressureSensorVoltage, Uart_PEDALS_PressureSensorVoltage);
	UartMessaging_SendValue(Uart_PEDALS_PressureSensorBars, Uart_PEDALS_PressureSensorBars);
	UartMessaging_SendValue(Uart_PEDALS_Accel_Sensor1_ShortToGnd, 1);
	UartMessaging_SendValue(Uart_PEDALS_Accel_Sensor1_ShortToVcc, 1);
	UartMessaging_SendValue(Uart_PEDALS_Accel_Sensor1_OutOfRangeOutput, 1);
	UartMessaging_SendValue(Uart_PEDALS_Accel_Sensor2_ShortToGnd, 1);
	UartMessaging_SendValue(Uart_PEDALS_Accel_Sensor2_ShortToVcc, 1);
	UartMessaging_SendValue(Uart_PEDALS_Accel_Sensor2_OutOfRangeOutput, 1);
	UartMessaging_SendValue(Uart_PEDALS_Accel_Implausibility, 1);
	UartMessaging_SendValue(Uart_PEDALS_Brake_Sensor1_ShortToGnd, 1);
	UartMessaging_SendValue(Uart_PEDALS_Brake_Sensor1_ShortToVcc, 1);
	UartMessaging_SendValue(Uart_PEDALS_Brake_Sensor1_OutOfRangeOutput, 1);
	UartMessaging_SendValue(Uart_PEDALS_Brake_Sensor2_ShortToGnd, 1);
	UartMessaging_SendValue(Uart_PEDALS_Brake_Sensor2_ShortToVcc, 1);
	UartMessaging_SendValue(Uart_PEDALS_Brake_Sensor2_OutOfRangeOutput, 1);
	UartMessaging_SendValue(Uart_PEDALS_Brake_Implausibility, 1);

	UartMessaging_SendValue(Uart_INVERTERS_LeftInverterTemperature, Uart_INVERTERS_LeftInverterTemperature);
	UartMessaging_SendValue(Uart_INVERTERS_LeftMotorTemperature, Uart_INVERTERS_LeftMotorTemperature);
	UartMessaging_SendValue(Uart_INVERTERS_LeftInverterInputVoltage, Uart_INVERTERS_LeftInverterInputVoltage);
	UartMessaging_SendValue(Uart_INVERTERS_LeftInverterCurrent, Uart_INVERTERS_LeftInverterCurrent);
	UartMessaging_SendValue(Uart_INVERTERS_LeftMotorRpm, Uart_INVERTERS_LeftMotorRpm);
	UartMessaging_SendValue(Uart_INVERTERS_LeftMotorSpeedKmh, Uart_INVERTERS_LeftMotorSpeedKmh);
	UartMessaging_SendValue(Uart_INVERTERS_LeftInverterThrottle, Uart_INVERTERS_LeftInverterThrottle);
	UartMessaging_SendValue(Uart_INVERTERS_LeftInverterThrottleFeedback, Uart_INVERTERS_LeftInverterThrottleFeedback);
	UartMessaging_SendValue(Uart_INVERTERS_RightInverterTemperature, Uart_INVERTERS_RightInverterTemperature);
	UartMessaging_SendValue(Uart_INVERTERS_RightMotorTemperature, Uart_INVERTERS_RightMotorTemperature);
	UartMessaging_SendValue(Uart_INVERTERS_RightInverterInputVoltage, Uart_INVERTERS_RightInverterInputVoltage);
	UartMessaging_SendValue(Uart_INVERTERS_RightInverterCurrent, Uart_INVERTERS_RightInverterCurrent);
	UartMessaging_SendValue(Uart_INVERTERS_RightMotorRpm, Uart_INVERTERS_RightMotorRpm);
	UartMessaging_SendValue(Uart_INVERTERS_RightMotorSpeedKmh, Uart_INVERTERS_RightMotorSpeedKmh);
	UartMessaging_SendValue(Uart_INVERTERS_RightInverterSentThrottle, Uart_INVERTERS_RightInverterSentThrottle);
	UartMessaging_SendValue(Uart_INVERTERS_RightInverterThrottleFeedback, Uart_INVERTERS_RightInverterThrottleFeedback);
	UartMessaging_SendValue(Uart_INVERTERS_IsCarInReverse, 1);
	UartMessaging_SendValue(Uart_INVERTERS_IsCarRunning, 1);

	UartMessaging_SendValue(Uart_DASHBOARD_ActivationButtonPressed, 1);
	UartMessaging_SendValue(Uart_DASHBOARD_CarReverseCommandPressed, 1);
	UartMessaging_SendValue(Uart_DASHBOARD_IsDisplayWorking, 1);
	UartMessaging_SendValue(Uart_DASHBOARD_IsSegmentsDriverWorking, 1);

	while(1){
		UartMessaging_Update();
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
