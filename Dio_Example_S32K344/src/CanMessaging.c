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
#include "CanMessaging.h"
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


InvertersMonitoredValues_t invertoareCan;
PedalsMonitoredValues_t pedaleCan;
TsacMonitoredValues_t baterieCan;
DashboardMonitoredValues_t bordCan;


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

void CanMessaging_Init(void){
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
}

void CanMessaging_Test(void){
	CanMessaging_SendValue(Can_TSAC_MedianCellTemperature, Can_TSAC_MedianCellTemperature);
	CanMessaging_SendValue(Can_TSAC_HighestCellTemperature, Can_TSAC_HighestCellTemperature);
	CanMessaging_SendValue(Can_TSAC_LowestCellTemperature, Can_TSAC_LowestCellTemperature);
	CanMessaging_SendValue(Can_TSAC_MedianCellVoltage, Can_TSAC_MedianCellVoltage);
	CanMessaging_SendValue(Can_TSAC_HighestCellVoltage, Can_TSAC_HighestCellVoltage);
	CanMessaging_SendValue(Can_TSAC_LowestCellVoltage, Can_TSAC_LowestCellVoltage);
	CanMessaging_SendValue(Can_TSAC_OverallVoltage, Can_TSAC_OverallVoltage);
	CanMessaging_SendValue(Can_TSAC_OverallCurrent, Can_TSAC_OverallCurrent);
	//baterieCan.CellVoltage[CELLS_NUM];
	//baterieCan.ThermistorTemperature[THERMISTOR_NUM];
	CanMessaging_SendValue(Can_TSAC_IsAmsSafe, 1);
	CanMessaging_SendValue(Can_TSAC_IsImdSafe, 1);
	CanMessaging_SendValue(Can_TSAC_IsTransceiverWorking, 1);
	CanMessaging_SendValue(Can_TSAC_IsShuntWorking, 1);
	CanMessaging_SendValue(Can_TSAC_IsBms0Working, 1);
	CanMessaging_SendValue(Can_TSAC_IsBms1Working, 1);

	CanMessaging_SendValue(Can_PEDALS_AcceleratorSensor1Voltage, Can_PEDALS_AcceleratorSensor1Voltage);
	CanMessaging_SendValue(Can_PEDALS_AcceleratorSensor2Voltage, Can_PEDALS_AcceleratorSensor2Voltage);
	CanMessaging_SendValue(Can_PEDALS_AcceleratorSensor1TravelPercentage, Can_PEDALS_AcceleratorSensor1TravelPercentage);
	CanMessaging_SendValue(Can_PEDALS_AcceleratorSensor2TravelPercentage, Can_PEDALS_AcceleratorSensor2TravelPercentage);
	CanMessaging_SendValue(Can_PEDALS_BrakeSensor1Voltage, Can_PEDALS_BrakeSensor1Voltage);
	CanMessaging_SendValue(Can_PEDALS_BrakeSensor2Voltage, Can_PEDALS_BrakeSensor2Voltage);
	CanMessaging_SendValue(Can_PEDALS_BrakeSensor1TravelPercentage, Can_PEDALS_BrakeSensor1TravelPercentage);
	CanMessaging_SendValue(Can_PEDALS_BrakeSensor2TravelPercentage, Can_PEDALS_BrakeSensor2TravelPercentage);
	CanMessaging_SendValue(Can_PEDALS_PressureSensorVoltage, Can_PEDALS_PressureSensorVoltage);
	CanMessaging_SendValue(Can_PEDALS_PressureSensorBars, Can_PEDALS_PressureSensorBars);
	CanMessaging_SendValue(Can_PEDALS_Accel_Sensor1_ShortToGnd, 1);
	CanMessaging_SendValue(Can_PEDALS_Accel_Sensor1_ShortToVcc, 1);
	CanMessaging_SendValue(Can_PEDALS_Accel_Sensor1_OutOfRangeOutput, 1);
	CanMessaging_SendValue(Can_PEDALS_Accel_Sensor2_ShortToGnd, 1);
	CanMessaging_SendValue(Can_PEDALS_Accel_Sensor2_ShortToVcc, 1);
	CanMessaging_SendValue(Can_PEDALS_Accel_Sensor2_OutOfRangeOutput, 1);
	CanMessaging_SendValue(Can_PEDALS_Accel_Implausibility, 1);
	CanMessaging_SendValue(Can_PEDALS_Brake_Sensor1_ShortToGnd, 1);
	CanMessaging_SendValue(Can_PEDALS_Brake_Sensor1_ShortToVcc, 1);
	CanMessaging_SendValue(Can_PEDALS_Brake_Sensor1_OutOfRangeOutput, 1);
	CanMessaging_SendValue(Can_PEDALS_Brake_Sensor2_ShortToGnd, 1);
	CanMessaging_SendValue(Can_PEDALS_Brake_Sensor2_ShortToVcc, 1);
	CanMessaging_SendValue(Can_PEDALS_Brake_Sensor2_OutOfRangeOutput, 1);
	CanMessaging_SendValue(Can_PEDALS_Brake_Implausibility, 1);

	CanMessaging_SendValue(Can_INVERTERS_LeftInverterTemperature, Can_INVERTERS_LeftInverterTemperature);
	CanMessaging_SendValue(Can_INVERTERS_LeftMotorTemperature, Can_INVERTERS_LeftMotorTemperature);
	CanMessaging_SendValue(Can_INVERTERS_LeftInverterInputVoltage, Can_INVERTERS_LeftInverterInputVoltage);
	CanMessaging_SendValue(Can_INVERTERS_LeftInverterCurrent, Can_INVERTERS_LeftInverterCurrent);
	CanMessaging_SendValue(Can_INVERTERS_LeftMotorRpm, Can_INVERTERS_LeftMotorRpm);
	CanMessaging_SendValue(Can_INVERTERS_LeftMotorSpeedKmh, Can_INVERTERS_LeftMotorSpeedKmh);
	CanMessaging_SendValue(Can_INVERTERS_LeftInverterThrottle, Can_INVERTERS_LeftInverterThrottle);
	CanMessaging_SendValue(Can_INVERTERS_LeftInverterThrottleFeedback, Can_INVERTERS_LeftInverterThrottleFeedback);
	CanMessaging_SendValue(Can_INVERTERS_RightInverterTemperature, Can_INVERTERS_RightInverterTemperature);
	CanMessaging_SendValue(Can_INVERTERS_RightMotorTemperature, Can_INVERTERS_RightMotorTemperature);
	CanMessaging_SendValue(Can_INVERTERS_RightInverterInputVoltage, Can_INVERTERS_RightInverterInputVoltage);
	CanMessaging_SendValue(Can_INVERTERS_RightInverterCurrent, Can_INVERTERS_RightInverterCurrent);
	CanMessaging_SendValue(Can_INVERTERS_RightMotorRpm, Can_INVERTERS_RightMotorRpm);
	CanMessaging_SendValue(Can_INVERTERS_RightMotorSpeedKmh, Can_INVERTERS_RightMotorSpeedKmh);
	CanMessaging_SendValue(Can_INVERTERS_RightInverterSentThrottle, Can_INVERTERS_RightInverterSentThrottle);
	CanMessaging_SendValue(Can_INVERTERS_RightInverterThrottleFeedback, Can_INVERTERS_RightInverterThrottleFeedback);
	CanMessaging_SendValue(Can_INVERTERS_IsCarInReverse, 1);
	CanMessaging_SendValue(Can_INVERTERS_IsCarRunning, 1);

	CanMessaging_SendValue(Can_DASHBOARD_ActivationButtonPressed, 1);
	CanMessaging_SendValue(Can_DASHBOARD_CarReverseCommandPressed, 1);
	CanMessaging_SendValue(Can_DASHBOARD_IsDisplayWorking, 1);
	CanMessaging_SendValue(Can_DASHBOARD_IsSegmentsDriverWorking, 1);

	while(1){
		CanMessaging_Update();
	}
}

void CanMessaging_Update(void){

}

void CanMessaging_SendValue(CanMonitoredValue_t DesiredValueType, uint32_t Value){
	switch(DesiredValueType){
		case Can_TSAC_MedianCellTemperature:
			baterieCan.MedianCellTemperature = Value;
			break;
		case Can_TSAC_HighestCellTemperature:
			baterieCan.HighestCellTemperature = Value;
			break;
		case Can_TSAC_LowestCellTemperature:
			baterieCan.LowestCellTemperature = Value;
			break;
		case Can_TSAC_MedianCellVoltage:
			baterieCan.MedianCellVoltage = Value;
			break;
		case Can_TSAC_HighestCellVoltage:
			baterieCan.HighestCellVoltage = Value;
			break;
		case Can_TSAC_LowestCellVoltage:
			baterieCan.LowestCellVoltage = Value;
			break;
		case Can_TSAC_OverallVoltage:
			baterieCan.OverallVoltage = Value;
			break;
		case Can_TSAC_OverallCurrent:
			baterieCan.OverallCurrent = Value;
			break;
		case Can_TSAC_IsAmsSafe:
			baterieCan.AmsError = Value;
			break;
		case Can_TSAC_IsImdSafe:
			baterieCan.ImdError = Value;
			break;
		case Can_TSAC_IsTransceiverWorking:
			baterieCan.TransceiverError = Value;
			break;
		case Can_TSAC_IsShuntWorking:
			baterieCan.ShuntError = Value;
			break;
		case Can_TSAC_IsBms0Working:
			baterieCan.Bms0Error = Value;
			break;
		case Can_TSAC_IsBms1Working:
			baterieCan.Bms1Error = Value;
			break;
		case Can_PEDALS_AcceleratorSensor1Voltage:
			pedaleCan.AcceleratorSensor1Voltage = Value;
			break;
		case Can_PEDALS_AcceleratorSensor2Voltage:
			pedaleCan.AcceleratorSensor2Voltage = Value;
			break;
		case Can_PEDALS_AcceleratorSensor1TravelPercentage:
			pedaleCan.AcceleratorSensor1TravelPercentage = Value;
			break;
		case Can_PEDALS_AcceleratorSensor2TravelPercentage:
			pedaleCan.AcceleratorSensor2TravelPercentage = Value;
			break;
		case Can_PEDALS_BrakeSensor1Voltage:
			pedaleCan.BrakeSensor1Voltage = Value;
			break;
		case Can_PEDALS_BrakeSensor2Voltage:
			pedaleCan.BrakeSensor2Voltage = Value;
			break;
		case Can_PEDALS_BrakeSensor1TravelPercentage:
			pedaleCan.BrakeSensor1TravelPercentage = Value;
			break;
		case Can_PEDALS_BrakeSensor2TravelPercentage:
			pedaleCan.BrakeSensor2TravelPercentage = Value;
			break;
		case Can_PEDALS_PressureSensorVoltage:
			pedaleCan.PressureSensorVoltage = Value;
			break;
		case Can_PEDALS_PressureSensorBars:
			pedaleCan.PressureSensorBars = Value;
			break;
		case Can_PEDALS_Accel_Sensor1_ShortToGnd:
			pedaleCan.Accel_Sensor1_ShortToGnd = Value;
			break;
		case Can_PEDALS_Accel_Sensor1_ShortToVcc:
			pedaleCan.Accel_Sensor1_ShortToVcc = Value;
			break;
		case Can_PEDALS_Accel_Sensor1_OutOfRangeOutput:
			pedaleCan.Accel_Sensor1_OutOfRangeOutput = Value;
			break;
		case Can_PEDALS_Accel_Sensor2_ShortToGnd:
			pedaleCan.Accel_Sensor2_ShortToGnd = Value;
			break;
		case Can_PEDALS_Accel_Sensor2_ShortToVcc:
			pedaleCan.Accel_Sensor2_ShortToVcc = Value;
			break;
		case Can_PEDALS_Accel_Sensor2_OutOfRangeOutput:
			pedaleCan.Accel_Sensor2_OutOfRangeOutput = Value;
			break;
		case Can_PEDALS_Accel_Implausibility:
			pedaleCan.Accel_Implausibility = Value;
			break;
		case Can_PEDALS_Brake_Sensor1_ShortToGnd:
			pedaleCan.Brake_Sensor1_ShortToGnd = Value;
			break;
		case Can_PEDALS_Brake_Sensor1_ShortToVcc:
			pedaleCan.Brake_Sensor1_ShortToVcc = Value;
			break;
		case Can_PEDALS_Brake_Sensor1_OutOfRangeOutput:
			pedaleCan.Brake_Sensor1_OutOfRangeOutput = Value;
			break;
		case Can_PEDALS_Brake_Sensor2_ShortToGnd:
			pedaleCan.Brake_Sensor2_ShortToGnd = Value;
			break;
		case Can_PEDALS_Brake_Sensor2_ShortToVcc:
			pedaleCan.Brake_Sensor2_ShortToVcc = Value;
			break;
		case Can_PEDALS_Brake_Sensor2_OutOfRangeOutput:
			pedaleCan.Brake_Sensor2_OutOfRangeOutput = Value;
			break;
		case Can_PEDALS_Brake_Implausibility:
			pedaleCan.Brake_Implausibility = Value;
			break;
		case Can_INVERTERS_LeftInverterTemperature:
			invertoareCan.LeftInverterTemperature = Value;
			break;
		case Can_INVERTERS_LeftMotorTemperature:
			invertoareCan.LeftMotorTemperature = Value;
			break;
		case Can_INVERTERS_LeftInverterInputVoltage:
			invertoareCan.LeftInverterInputVoltage = Value;
			break;
		case Can_INVERTERS_LeftInverterCurrent:
			invertoareCan.LeftInverterCurrent = Value;
			break;
		case Can_INVERTERS_LeftMotorRpm:
			invertoareCan.LeftMotorRpm = Value;
			break;
		case Can_INVERTERS_LeftMotorSpeedKmh:
			invertoareCan.LeftMotorSpeedKmh = Value;
			break;
		case Can_INVERTERS_LeftInverterThrottle:
			invertoareCan.LeftInverterThrottle = Value;
			break;
		case Can_INVERTERS_LeftInverterThrottleFeedback:
			invertoareCan.LeftInverterThrottleFeedback = Value;
			break;
		case Can_INVERTERS_RightInverterTemperature:
			invertoareCan.RightInverterTemperature = Value;
			break;
		case Can_INVERTERS_RightMotorTemperature:
			invertoareCan.RightMotorTemperature = Value;
			break;
		case Can_INVERTERS_RightInverterInputVoltage:
			invertoareCan.RightInverterInputVoltage = Value;
			break;
		case Can_INVERTERS_RightInverterCurrent:
			invertoareCan.RightInverterCurrent = Value;
			break;
		case Can_INVERTERS_RightMotorRpm:
			invertoareCan.RightMotorRpm = Value;
			break;
		case Can_INVERTERS_RightMotorSpeedKmh:
			invertoareCan.RightMotorSpeedKmh = Value;
			break;
		case Can_INVERTERS_RightInverterSentThrottle:
			invertoareCan.RightInverterSentThrottle = Value;
			break;
		case Can_INVERTERS_RightInverterThrottleFeedback:
			invertoareCan.RightInverterThrottleFeedback = Value;
			break;
		case Can_INVERTERS_IsCarInReverse:
			invertoareCan.IsCarInReverse = Value;
			break;
		case Can_INVERTERS_IsCarRunning:
			invertoareCan.IsCarRunning = Value;
			break;
		case Can_DASHBOARD_ActivationButtonPressed:
			bordCan.ActivationButtonPressed = Value;
			break;
		case Can_DASHBOARD_CarReverseCommandPressed:
			bordCan.CarReverseCommandPressed = Value;
			break;
		case Can_DASHBOARD_IsDisplayWorking:
			bordCan.IsDisplayWorking = Value;
			break;
		case Can_DASHBOARD_IsSegmentsDriverWorking:
			bordCan.IsSegmentsDriverWorking = Value;
			break;
	}
}

uint32_t CanMessaging_ReadValue(CanMonitoredValue_t DesiredValueType){
	switch(DesiredValueType){
		case Can_TSAC_MedianCellTemperature:
			return baterieCan.MedianCellTemperature;
	    case Can_TSAC_HighestCellTemperature:
	    	return baterieCan.HighestCellTemperature;
	    case Can_TSAC_LowestCellTemperature:
	    	return baterieCan.LowestCellTemperature;
	    case Can_TSAC_MedianCellVoltage:
	    	return baterieCan.MedianCellVoltage;
	    case Can_TSAC_HighestCellVoltage:
	    	return baterieCan.HighestCellVoltage;
	    case Can_TSAC_LowestCellVoltage:
	    	return baterieCan.LowestCellVoltage;
	    case Can_TSAC_OverallVoltage:
	    	return baterieCan.OverallVoltage;
	    case Can_TSAC_OverallCurrent:
	    	return baterieCan.OverallCurrent;
	    case Can_TSAC_IsAmsSafe:
	    	return baterieCan.AmsError;
	    case Can_TSAC_IsImdSafe:
	    	return baterieCan.ImdError;
	    case Can_TSAC_IsTransceiverWorking:
	    	return baterieCan.TransceiverError;
	    case Can_TSAC_IsShuntWorking:
	    	return baterieCan.ShuntError;
	    case Can_TSAC_IsBms0Working:
	    	return baterieCan.Bms0Error;
	    case Can_TSAC_IsBms1Working:
	    	return baterieCan.Bms1Error;
	    case Can_PEDALS_AcceleratorSensor1Voltage:
	    	return pedaleCan.AcceleratorSensor1Voltage;
	    case Can_PEDALS_AcceleratorSensor2Voltage:
	    	return pedaleCan.AcceleratorSensor2Voltage;
		case Can_PEDALS_AcceleratorSensor1TravelPercentage:
			return pedaleCan.AcceleratorSensor1TravelPercentage;
		case Can_PEDALS_AcceleratorSensor2TravelPercentage:
			return pedaleCan.AcceleratorSensor2TravelPercentage;
		case Can_PEDALS_BrakeSensor1Voltage:
			return pedaleCan.BrakeSensor1Voltage;
		case Can_PEDALS_BrakeSensor2Voltage:
			return pedaleCan.BrakeSensor2Voltage;
		case Can_PEDALS_BrakeSensor1TravelPercentage:
			return pedaleCan.BrakeSensor1TravelPercentage;
		case Can_PEDALS_BrakeSensor2TravelPercentage:
			return pedaleCan.BrakeSensor2TravelPercentage;
		case Can_PEDALS_PressureSensorVoltage:
			return pedaleCan.PressureSensorVoltage;
		case Can_PEDALS_PressureSensorBars:
			return pedaleCan.PressureSensorBars;
		case Can_PEDALS_Accel_Sensor1_ShortToGnd:
			return pedaleCan.Accel_Sensor1_ShortToGnd;
		case Can_PEDALS_Accel_Sensor1_ShortToVcc:
			return pedaleCan.Accel_Sensor1_ShortToVcc;
		case Can_PEDALS_Accel_Sensor1_OutOfRangeOutput:
			return pedaleCan.Accel_Sensor1_OutOfRangeOutput;
		case Can_PEDALS_Accel_Sensor2_ShortToGnd:
			return pedaleCan.Accel_Sensor2_ShortToGnd;
		case Can_PEDALS_Accel_Sensor2_ShortToVcc:
			return pedaleCan.Accel_Sensor2_ShortToVcc;
		case Can_PEDALS_Accel_Sensor2_OutOfRangeOutput:
			return pedaleCan.Accel_Sensor2_OutOfRangeOutput;
		case Can_PEDALS_Accel_Implausibility:
			return pedaleCan.Accel_Implausibility;
		case Can_PEDALS_Brake_Sensor1_ShortToGnd:
			return pedaleCan.Brake_Sensor1_ShortToGnd;
		case Can_PEDALS_Brake_Sensor1_ShortToVcc:
			return pedaleCan.Brake_Sensor1_ShortToVcc;
		case Can_PEDALS_Brake_Sensor1_OutOfRangeOutput:
			return pedaleCan.Brake_Sensor1_OutOfRangeOutput;
		case Can_PEDALS_Brake_Sensor2_ShortToGnd:
			return pedaleCan.Brake_Sensor2_ShortToGnd;
		case Can_PEDALS_Brake_Sensor2_ShortToVcc:
			return pedaleCan.Brake_Sensor2_ShortToVcc;
		case Can_PEDALS_Brake_Sensor2_OutOfRangeOutput:
			return pedaleCan.Brake_Sensor2_OutOfRangeOutput;
		case Can_PEDALS_Brake_Implausibility:
			return pedaleCan.Brake_Implausibility;
		case Can_INVERTERS_LeftInverterTemperature:
			return invertoareCan.LeftInverterTemperature;
		case Can_INVERTERS_LeftMotorTemperature:
			return invertoareCan.LeftMotorTemperature;
		case Can_INVERTERS_LeftInverterInputVoltage:
			return invertoareCan.LeftInverterInputVoltage;
		case Can_INVERTERS_LeftInverterCurrent:
			return invertoareCan.LeftInverterCurrent;
		case Can_INVERTERS_LeftMotorRpm:
			return invertoareCan.LeftMotorRpm;
		case Can_INVERTERS_LeftMotorSpeedKmh:
			return invertoareCan.LeftMotorSpeedKmh;
		case Can_INVERTERS_LeftInverterThrottle:
			return invertoareCan.LeftInverterThrottle;
		case Can_INVERTERS_LeftInverterThrottleFeedback:
			return invertoareCan.LeftInverterThrottleFeedback;
		case Can_INVERTERS_RightInverterTemperature:
			return invertoareCan.RightInverterTemperature;
		case Can_INVERTERS_RightMotorTemperature:
			return invertoareCan.RightMotorTemperature;
		case Can_INVERTERS_RightInverterInputVoltage:
			return invertoareCan.RightInverterInputVoltage;
		case Can_INVERTERS_RightInverterCurrent:
			return invertoareCan.RightInverterCurrent;
		case Can_INVERTERS_RightMotorRpm:
			return invertoareCan.RightMotorRpm;
		case Can_INVERTERS_RightMotorSpeedKmh:
			return invertoareCan.RightMotorSpeedKmh;
		case Can_INVERTERS_RightInverterSentThrottle:
			return invertoareCan.RightInverterSentThrottle;
		case Can_INVERTERS_RightInverterThrottleFeedback:
			return invertoareCan.RightInverterThrottleFeedback;
		case Can_INVERTERS_IsCarInReverse:
			return invertoareCan.IsCarInReverse;
		case Can_INVERTERS_IsCarRunning:
			return invertoareCan.IsCarRunning;
		case Can_DASHBOARD_ActivationButtonPressed:
			return bordCan.ActivationButtonPressed;
		case Can_DASHBOARD_CarReverseCommandPressed:
			return bordCan.CarReverseCommandPressed;
		case Can_DASHBOARD_IsDisplayWorking:
			return bordCan.IsDisplayWorking;
		case Can_DASHBOARD_IsSegmentsDriverWorking:
			return bordCan.IsSegmentsDriverWorking;
	}
	return 0;
}




#ifdef __cplusplus
}
#endif
