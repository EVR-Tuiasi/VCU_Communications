#ifndef PROVIZORIU_H
#define PROVIZORIU_H

#include"Mcu.h"
#include"Can_43_FLEXCAN.h"
#include "CDD_Uart.h"

#define MASK 0x3FFFFFFF

#define idCanFrana 0x00000331
#define idCanAcceleratie 0x00000330
#define idCanInvertorStanga 0x00000110
#define idCanInvertorDreapta 0x00000111
#define idCanInvertoare 0x00000112
#define idCanBaterie 0x00000440
#define idCanBord 0x00000220

#define idUartInvertorStanga 0x00000010
#define idUartInvertorDreapta 0x00000011
#define idUartInvertoare 0x00000012
#define idUartBord 0x00000020
#define idUartAcceleratie 0x00000030
#define idUartFrana 0x00000031
#define idUartBaterie 0x000040

struct dateInvertoare{
	struct{
		uint16_t rpmMotor;
		uint16_t tensiuneIntrareInvertor;
		uint8_t throttleSignalFeedback;
		uint8_t vitezaMotor;
		uint8_t throttleInvertor;
		uint8_t temperaturaInvertor;
		uint8_t temperaturaMotor;
		uint8_t curentInvertor;
	}stanga;
	struct{
		uint16_t rpmMotor;
		uint16_t tensiuneIntrareInvertor;
		uint8_t throttleSignalFeedback;
		uint8_t vitezaMotor;
		uint8_t throttleInvertor;
		uint8_t temperaturaInvertor;
		uint8_t temperaturaMotor;
		uint8_t curentInvertor;
	}dreapta;
	bool isCarRunning;
	bool isCarInReverse;
};

struct dateFrana{
	uint16_t tensiune1;
	uint16_t tensiune2;
	uint8_t cursa1;
	uint8_t cursa2;
	uint8_t presiuneSenzor;
	bool implausibility;
	bool outOfRangeOutput1;
	bool shortToVCC1;
	bool shortToGND1;
	bool outOfRangeOutput2;
	bool shortToVCC2;
	bool shortToGND2;
};

struct dateAcceleratie{
	uint16_t tensiune1;
	uint16_t tensiune2;
	uint8_t cursa1;
	uint8_t cursa2;
	uint16_t tensiuneSenzorPresiune;
	bool implausibility;
	bool outOfRangeOutput1;
	bool shortToVCC1;
	bool shortToGND1;
	bool outOfRangeOutput2;
	bool shortToVCC2;
	bool shortToGND2;
};

struct dateBaterie{
	uint16_t tensiuneaMaximaDinteCelule;
	uint16_t temperaturaMaximaDintreCelule;
	uint16_t tensiunePerTotal;
	uint16_t curentPerTotal;
	//More To Come:)
};

struct dateBord{
	bool activationLogicPressed; //1-active; 0-inactive
	bool isCarInReverse;//1-reverse; 0-not in reverse
	bool idDisplayWorking;//0-working; 1-err
	bool isSegmentsDriverWorking;//0-working; 1-err
};

bool primesteDate(Can_HwHandleType handle, Can_IdType id, PduLengthType length, uint8_t* data);

#endif
