#ifndef CAN_MESSAGING_H
#define CAN_MESSAGING_H

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

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

typedef enum{
    /* TSAC */
    Can_TSAC_MedianCellTemperature,
    Can_TSAC_HighestCellTemperature,
    Can_TSAC_LowestCellTemperature,
    Can_TSAC_MedianCellVoltage,
    Can_TSAC_HighestCellVoltage,
    Can_TSAC_LowestCellVoltage,
    Can_TSAC_OverallVoltage,
    Can_TSAC_OverallCurrent,
    Can_TSAC_IsAmsSafe,
    Can_TSAC_IsImdSafe,
    Can_TSAC_IsTransceiverWorking,
    Can_TSAC_IsShuntWorking,
    Can_TSAC_IsBms0Working,
    Can_TSAC_IsBms1Working,
    /* PEDALS */
    Can_PEDALS_AcceleratorSensor1Voltage,
    Can_PEDALS_AcceleratorSensor2Voltage,
    Can_PEDALS_AcceleratorSensor1TravelPercentage,
    Can_PEDALS_AcceleratorSensor2TravelPercentage,
    Can_PEDALS_BrakeSensor1Voltage,
    Can_PEDALS_BrakeSensor2Voltage,
    Can_PEDALS_BrakeSensor1TravelPercentage,
    Can_PEDALS_BrakeSensor2TravelPercentage,
    Can_PEDALS_PressureSensorVoltage,
    Can_PEDALS_PressureSensorBars,
    Can_PEDALS_Accel_Sensor1_ShortToGnd,
    Can_PEDALS_Accel_Sensor1_ShortToVcc,
    Can_PEDALS_Accel_Sensor1_OutOfRangeOutput,
    Can_PEDALS_Accel_Sensor2_ShortToGnd,
    Can_PEDALS_Accel_Sensor2_ShortToVcc,
    Can_PEDALS_Accel_Sensor2_OutOfRangeOutput,
    Can_PEDALS_Accel_Implausibility,
    Can_PEDALS_Brake_Sensor1_ShortToGnd,
    Can_PEDALS_Brake_Sensor1_ShortToVcc,
    Can_PEDALS_Brake_Sensor1_OutOfRangeOutput,
    Can_PEDALS_Brake_Sensor2_ShortToGnd,
    Can_PEDALS_Brake_Sensor2_ShortToVcc,
    Can_PEDALS_Brake_Sensor2_OutOfRangeOutput,
    Can_PEDALS_Brake_Implausibility,
    /* INVERTERS */
    Can_INVERTERS_LeftInverterTemperature,
    Can_INVERTERS_LeftMotorTemperature,
    Can_INVERTERS_LeftInverterInputVoltage,
    Can_INVERTERS_LeftInverterCurrent,
    Can_INVERTERS_LeftMotorRpm,
    Can_INVERTERS_LeftMotorSpeedKmh,
    Can_INVERTERS_LeftInverterThrottle,
    Can_INVERTERS_LeftInverterThrottleFeedback,
    Can_INVERTERS_RightInverterTemperature,
    Can_INVERTERS_RightMotorTemperature,
    Can_INVERTERS_RightInverterInputVoltage,
    Can_INVERTERS_RightInverterCurrent,
    Can_INVERTERS_RightMotorRpm,
    Can_INVERTERS_RightMotorSpeedKmh,
    Can_INVERTERS_RightInverterSentThrottle,
    Can_INVERTERS_RightInverterThrottleFeedback,
    Can_INVERTERS_IsCarInReverse,
    Can_INVERTERS_IsCarRunning,
    /* DASHBOARD */
    Can_DASHBOARD_ActivationButtonPressed,
    Can_DASHBOARD_CarReverseCommandPressed,
    Can_DASHBOARD_IsDisplayWorking,
    Can_DASHBOARD_IsSegmentsDriverWorking
}CanMonitoredValue_t;

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

#define CAN_TARGET_ID 0x0CF11A12
#define CAN_HTH_HANDLE 0x00000001

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

void CanMessaging_Init(void);
void CanMessaging_Test(void);
void CanMessaging_Update(void);
void CanMessaging_SendValue(CanMonitoredValue_t DesiredValueType, uint32_t Value);
uint32_t CanMessaging_ReadValue(CanMonitoredValue_t DesiredValueType);

#ifdef __cplusplus
}
#endif

#endif
