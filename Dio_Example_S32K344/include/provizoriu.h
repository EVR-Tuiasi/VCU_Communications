#ifndef PROVIZORIU_H
#define PROVIZORIU_H

#include"Mcu.h"
#include"Can_43_FLEXCAN.h"
#include "CDD_Uart.h"

#define MASK 0x3FFFFFFF

#define idFrana 0x00000001
#define idAcceleratie 0x00000002
#define idInvertorSt 0x00000003
#define idInvertorDr 0x00000004
#define idBaterie 0x0CF11A05
#define idBord 0x00000005

#define CELL_TEMP 10
#define CELL_VOLTAGE 11
#define BMS_VOLTAGE 12
#define BMS_CURRENT 13
#define ACCELERATOR_PEDALS 14
#define BRAKE_PEDAL 15
#define SEVEN_SEGMENT 16
#define INVERTERS_RPM 17
#define INVERTERS_CURRENT 18
#define INVERTERS_VOLTAGE 19
#define INVERTERS_PEDALS 20
#define INVERTERS_CONTROLLER_TEMPERATURE 21
#define INVERTERS_MOTORS_TEMPERATURE 22
#define ERROR 100

struct dateInvertoare{
	struct{
		uint8 tmpMotor;
		uint8 tmpInvertor;
		uint8 throttleSignalFeedback;
		uint16 curent;
		uint16 rpm;
		uint16 tensiune;
	}st;
	struct{
		uint8 tmpMotor;
		uint8 tmpInvertor;
		uint8 throttleSignalFeedback;
		uint16 curent;
		uint16 rpm;
		uint16 tensiune;
	}dr;
};

struct dateFrana{
	uint8 presiune;
	uint16 tensiuneSenzorPresiune;
	uint16 tensiune2;
	uint16 tensiune1;
	uint8 cursa2;
	uint8 cursa1;
	uint8 erori;
};

struct dateAcceleratie{
	uint16 tensiune2;
	uint16 tensiune1;
	uint8 cursa2;
	uint8 cursa1;
	uint8 erori;
};

struct dateBaterie{
	uint16 curent;
	uint16 tensiuneTSAC;
	uint16 tmpMax;
	uint16 tensiuneMaxCelule;
};

struct dateBord{
	bool activationLogic;
	bool directieMasina;
	uint8 eroriI2C;
	//de completat
};

bool primesteDate(Can_HwHandleType handle, Can_IdType id, PduLengthType length, uint8* data);

#endif
