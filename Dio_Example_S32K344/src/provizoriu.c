#include "provizoriu.h"

extern uint8 UART_Channel;

InvertersMonitoredValues_t invertoare;
PedalsMonitoredValues_t pedale;
TsacMonitoredValues_t baterie;
DashboardMonitoredValues_t bord;

boolean primesteDate(Can_HwHandleType handle, Can_IdType id, PduLengthType length, uint8_t* data){
	//Uart_SyncSend(UART_Channel, buffer, length, 10000000);
	switch((id&MASK)){
		case idCanFrana:
			//extragere date
			pedale.BrakeSensor1Voltage = ((((uint16_t)data[6])<<8) | data[7]) & (0x3FFF);
			pedale.BrakeSensor2Voltage = ((((((uint16_t)data[4])<<8) | data[5]) & (0x0FFF)) << 2) | (data[6]>>6);
			pedale.BrakeSensor1TravelPercentage = (((uint8_t)(data[3]<<4)) | (data[4]>>4)) & (0x7F);
			pedale.BrakeSensor2TravelPercentage = (((uint8_t)(data[2]<<6)) | (data[3]>>3)) & (0x7F);
			pedale.PressureSensorBars = ((uint8_t)(data[1]<<6)) | (data[2]>>2);
			pedale.Brake_Implausibility = (data[0] & (1<<1)) >> 1;
			pedale.Brake_Sensor1_OutOfRangeOutput = (data[0] & (1<<5)) >> 5;
			pedale.Brake_Sensor1_ShortToVcc = (data[0] & (1<<6)) >> 6;
			pedale.Brake_Sensor1_ShortToGnd = (data[0] & (1<<7)) >> 7;
			pedale.Brake_Sensor2_OutOfRangeOutput = (data[0] & (1<<2)) >> 2;
			pedale.Brake_Sensor2_ShortToVcc = (data[0] & (1<<3)) >> 3;
			pedale.Brake_Sensor2_ShortToGnd = (data[0] & (1<<4)) >> 4;
			break;

		case idCanAcceleratie:
			//extragere date
			pedale.AcceleratorSensor1Voltage = ((((uint16_t)data[6])<<8) | data[7]) & (0x3FFF);
			pedale.AcceleratorSensor2Voltage = ((((((uint16_t)data[4])<<8) | data[5]) & (0x0FFF)) << 2) | (data[6]>>6);
			pedale.AcceleratorSensor1TravelPercentage = (((uint8_t)(data[3]<<4)) | (data[4]>>4)) & (0x7F);
			pedale.AcceleratorSensor2TravelPercentage = (((uint8_t)(data[2]<<6)) | (data[3]>>3)) & (0x7F);
			pedale.PressureSensorVoltage = ((((uint16_t)data[1]<<8)) | (data[2]>>2)) & (0x01FF);
			pedale.Accel_Implausibility = (data[0] & (1<<1)) >> 1;
			pedale.Accel_Sensor1_OutOfRangeOutput = (data[0] & (1<<5)) >> 5;
			pedale.Accel_Sensor1_ShortToVcc = (data[0] & (1<<6)) >> 6;
			pedale.Accel_Sensor1_ShortToGnd = (data[0] & (1<<7)) >> 7;
			pedale.Accel_Sensor2_OutOfRangeOutput = (data[0] & (1<<2)) >> 2;
			pedale.Accel_Sensor2_ShortToVcc = (data[0] & (1<<3)) >> 3;
			pedale.Accel_Sensor2_ShortToGnd = (data[0] & (1<<4)) >>4;
			break;

		case idCanInvertorStanga:
			//extragere date
			invertoare.LeftMotorTemperature = data[7];
			invertoare.LeftInverterTemperature = data[6];
			invertoare.LeftInverterThrottle = data[5];
			invertoare.LeftMotorSpeedKmh = data[4];
			invertoare.LeftInverterThrottleFeedback = data[3];
			invertoare.LeftInverterInputVoltage = ((((uint16_t)data[1])<<8) | data[2]) & (0x7FF);
			invertoare.LeftMotorRpm = ((((uint16_t)data[0])<<8) | data[1]) >> 3;
			break;

		case idCanInvertorDreapta:
			//extragere date
			invertoare.RightMotorTemperature = data[7];
			invertoare.RightInverterTemperature = data[6];
			invertoare.RightInverterSentThrottle = data[5];
			invertoare.RightMotorSpeedKmh = data[4];
			invertoare.RightInverterThrottleFeedback = data[3];
			invertoare.RightInverterInputVoltage = ((((uint16_t)data[1])<<8) | data[2]) & (0x7FF);
			invertoare.RightMotorRpm = ((((uint16_t)data[0])<<8) | data[1]) >> 3;
			break;

		case idCanInvertoare:
			invertoare.IsCarRunning = (data[0] & (1<<7)) >> 7;
			invertoare.IsCarInReverse = (data[0] & (1<<6)) >> 6;
			invertoare.LeftInverterCurrent = ((((uint16_t)data[6])<<8) | data[7]) & (0x0FFF);
			invertoare.RightInverterCurrent = ((((uint16_t)data[5])<<8) | data[6]) >> 4;
			break;

		case idCanBaterie:
			//extragere date
			baterie.OverallCurrent = ((((uint16_t)data[6])<<8) | data[7]) & (0x1FFF);
			baterie.OverallVoltage = ((((uint16_t)data[5])<<8) | data[6]) >> 5;
			baterie.HighestCellTemperature = ((((uint16_t)data[3])<<8) | data[4]) & (0x03FF);
			baterie.HighestCellVoltage = (((((uint16_t)data[2])<<8) | data[3]) >> 2) & (0x03FF);
			//More To Come:)
			break;

		case idCanBord:
			//extragere date
			bord.ActivationButtonPressed = (data[0] & (1<<7)) >> 7;
			bord.CarReverseCommandPressed = (data[0] & (1<<6)) >> 6;
			bord.IsDisplayWorking = (data[0] & (1<<5)) >> 5;
			bord.IsSegmentsDriverWorking = (data[0] & (1<<4)) >> 4;
			break;
	}
	return TRUE;
}
