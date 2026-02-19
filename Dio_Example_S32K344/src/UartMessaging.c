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
	int cnt = 0;
	volatile int i;
	while(1){
		UartMessaging_SetValue(Uart_TSAC_MedianCellTemperature, Uart_TSAC_MedianCellTemperature + cnt);
		UartMessaging_SetValue(Uart_TSAC_HighestCellTemperature, Uart_TSAC_HighestCellTemperature + cnt);
		UartMessaging_SetValue(Uart_TSAC_LowestCellTemperature, Uart_TSAC_LowestCellTemperature + cnt);
		UartMessaging_SetValue(Uart_TSAC_MedianCellVoltage, Uart_TSAC_MedianCellVoltage + cnt);
		UartMessaging_SetValue(Uart_TSAC_HighestCellVoltage, Uart_TSAC_HighestCellVoltage + cnt);
		UartMessaging_SetValue(Uart_TSAC_LowestCellVoltage, Uart_TSAC_LowestCellVoltage + cnt);
		UartMessaging_SetValue(Uart_TSAC_OverallVoltage, Uart_TSAC_OverallVoltage + cnt);
		UartMessaging_SetValue(Uart_TSAC_OverallCurrent, Uart_TSAC_OverallCurrent + cnt);
		//baterieUart.CellVoltage[CELLS_NUM];
		//baterieUart.ThermistorTemperature[THERMISTOR_NUM];
		UartMessaging_SetValue(Uart_TSAC_IsAmsSafe, 1);
		UartMessaging_SetValue(Uart_TSAC_IsImdSafe, 1);
		UartMessaging_SetValue(Uart_TSAC_IsTransceiverWorking, 1);
		UartMessaging_SetValue(Uart_TSAC_IsShuntWorking, 1);
		UartMessaging_SetValue(Uart_TSAC_IsBms0Working, 1);
		UartMessaging_SetValue(Uart_TSAC_IsBms1Working, 1);

		UartMessaging_SetValue(Uart_PEDALS_AcceleratorSensor1Voltage, Uart_PEDALS_AcceleratorSensor1Voltage + cnt);
		UartMessaging_SetValue(Uart_PEDALS_AcceleratorSensor2Voltage, Uart_PEDALS_AcceleratorSensor2Voltage + cnt);
		UartMessaging_SetValue(Uart_PEDALS_AcceleratorSensor1TravelPercentage, Uart_PEDALS_AcceleratorSensor1TravelPercentage + cnt);
		UartMessaging_SetValue(Uart_PEDALS_AcceleratorSensor2TravelPercentage, Uart_PEDALS_AcceleratorSensor2TravelPercentage + cnt);
		UartMessaging_SetValue(Uart_PEDALS_BrakeSensor1Voltage, Uart_PEDALS_BrakeSensor1Voltage + cnt);
		UartMessaging_SetValue(Uart_PEDALS_BrakeSensor2Voltage, Uart_PEDALS_BrakeSensor2Voltage + cnt);
		UartMessaging_SetValue(Uart_PEDALS_BrakeSensor1TravelPercentage, Uart_PEDALS_BrakeSensor1TravelPercentage + cnt);
		UartMessaging_SetValue(Uart_PEDALS_BrakeSensor2TravelPercentage, Uart_PEDALS_BrakeSensor2TravelPercentage + cnt);
		UartMessaging_SetValue(Uart_PEDALS_PressureSensorVoltage, Uart_PEDALS_PressureSensorVoltage + cnt);
		UartMessaging_SetValue(Uart_PEDALS_PressureSensorBars, Uart_PEDALS_PressureSensorBars + cnt);
		UartMessaging_SetValue(Uart_PEDALS_Accel_Sensor1_ShortToGnd, cnt & 1);
		UartMessaging_SetValue(Uart_PEDALS_Accel_Sensor1_ShortToVcc, cnt & 1);
		UartMessaging_SetValue(Uart_PEDALS_Accel_Sensor1_OutOfRangeOutput, cnt & 1);
		UartMessaging_SetValue(Uart_PEDALS_Accel_Sensor2_ShortToGnd, cnt & 1);
		UartMessaging_SetValue(Uart_PEDALS_Accel_Sensor2_ShortToVcc, cnt & 1);
		UartMessaging_SetValue(Uart_PEDALS_Accel_Sensor2_OutOfRangeOutput, cnt & 1);
		UartMessaging_SetValue(Uart_PEDALS_Accel_Implausibility, cnt & 1);
		UartMessaging_SetValue(Uart_PEDALS_Brake_Sensor1_ShortToGnd, cnt & 1);
		UartMessaging_SetValue(Uart_PEDALS_Brake_Sensor1_ShortToVcc, cnt & 1);
		UartMessaging_SetValue(Uart_PEDALS_Brake_Sensor1_OutOfRangeOutput, cnt & 1);
		UartMessaging_SetValue(Uart_PEDALS_Brake_Sensor2_ShortToGnd, cnt & 1);
		UartMessaging_SetValue(Uart_PEDALS_Brake_Sensor2_ShortToVcc, cnt & 1);
		UartMessaging_SetValue(Uart_PEDALS_Brake_Sensor2_OutOfRangeOutput, cnt & 1);
		UartMessaging_SetValue(Uart_PEDALS_Brake_Implausibility, cnt & 1);

		UartMessaging_SetValue(Uart_INVERTERS_LeftInverterTemperature, Uart_INVERTERS_LeftInverterTemperature + cnt);
		UartMessaging_SetValue(Uart_INVERTERS_LeftMotorTemperature, Uart_INVERTERS_LeftMotorTemperature + cnt);
		UartMessaging_SetValue(Uart_INVERTERS_LeftInverterInputVoltage, Uart_INVERTERS_LeftInverterInputVoltage + cnt);
		UartMessaging_SetValue(Uart_INVERTERS_LeftInverterCurrent, Uart_INVERTERS_LeftInverterCurrent + cnt);
		UartMessaging_SetValue(Uart_INVERTERS_LeftMotorRpm, Uart_INVERTERS_LeftMotorRpm + cnt);
		UartMessaging_SetValue(Uart_INVERTERS_LeftMotorSpeedKmh, Uart_INVERTERS_LeftMotorSpeedKmh + cnt);
		UartMessaging_SetValue(Uart_INVERTERS_LeftInverterThrottle, Uart_INVERTERS_LeftInverterThrottle + cnt);
		UartMessaging_SetValue(Uart_INVERTERS_LeftInverterThrottleFeedback, Uart_INVERTERS_LeftInverterThrottleFeedback + cnt);
		UartMessaging_SetValue(Uart_INVERTERS_RightInverterTemperature, Uart_INVERTERS_RightInverterTemperature + cnt);
		UartMessaging_SetValue(Uart_INVERTERS_RightMotorTemperature, Uart_INVERTERS_RightMotorTemperature + cnt);
		UartMessaging_SetValue(Uart_INVERTERS_RightInverterInputVoltage, Uart_INVERTERS_RightInverterInputVoltage + cnt);
		UartMessaging_SetValue(Uart_INVERTERS_RightInverterCurrent, Uart_INVERTERS_RightInverterCurrent + cnt);
		UartMessaging_SetValue(Uart_INVERTERS_RightMotorRpm, Uart_INVERTERS_RightMotorRpm + cnt);
		UartMessaging_SetValue(Uart_INVERTERS_RightMotorSpeedKmh, Uart_INVERTERS_RightMotorSpeedKmh + cnt);
		UartMessaging_SetValue(Uart_INVERTERS_RightInverterSentThrottle, Uart_INVERTERS_RightInverterSentThrottle + cnt);
		UartMessaging_SetValue(Uart_INVERTERS_RightInverterThrottleFeedback, Uart_INVERTERS_RightInverterThrottleFeedback + cnt);
		UartMessaging_SetValue(Uart_INVERTERS_IsCarInReverse, cnt & 1);
		UartMessaging_SetValue(Uart_INVERTERS_IsCarRunning, cnt & 1);

		UartMessaging_SetValue(Uart_DASHBOARD_ActivationButtonPressed, cnt & 1);
		UartMessaging_SetValue(Uart_DASHBOARD_CarReverseCommandPressed, cnt & 1);
		UartMessaging_SetValue(Uart_DASHBOARD_IsDisplayWorking, cnt & 1);
		UartMessaging_SetValue(Uart_DASHBOARD_IsSegmentsDriverWorking, cnt & 1);

		cnt++;
		UartMessaging_Update();
		i=100000;
		while(i--);
	}
}

void UartMessaging_Update(void){

}

void UartMessaging_SetValue(UartMonitoredValue_t DesiredValueType, uint32_t Value){
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
