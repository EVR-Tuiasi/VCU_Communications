#include "provizoriu.h"

extern uint8 UART_Channel;

struct dateInvertoare invertoare;
struct dateFrana frana;
struct dateAcceleratie acceleratie;
struct dateBaterie baterie;
struct dateBord bord;

boolean primesteDate(Can_HwHandleType handle, Can_IdType id, PduLengthType length, uint8_t* data){
	//Uart_SyncSend(UART_Channel, buffer, length, 10000000);
	switch((id&MASK)){
		case idCanFrana:
			//extragere date
			frana.tensiune1 = ((((uint16_t)data[6])<<8) | data[7]) & (0x1FFF);
			frana.tensiune2 = ((((((uint16_t)data[4])<<8) | data[5]) & (0x0FFF)) << 2) | (data[6]>>6);
			frana.cursa1 = (((uint8_t)(data[3]<<4)) | (data[4]>>4)) & (0x7F);
			frana.cursa2 = (((uint8_t)(data[2]<<6)) | (data[3]>>3)) & (0x7F);
			frana.presiuneSenzor = ((uint8_t)(data[1]<<6)) | (data[2]>>2);
			frana.implausibility = data[0] & (1<<1);
			frana.outOfRangeOutput1 = data[0] & (1<<5);
			frana.shortToVCC1 = data[0] & (1<<6);
			frana.shortToGND1 = data[0] & (1<<7);
			frana.outOfRangeOutput2 = data[0] & (1<<2);
			frana.shortToVCC2 = data[0] & (1<<3);
			frana.shortToGND2 = data[0] & (1<<4);
			break;

		case idCanAcceleratie:
			//extragere date
			acceleratie.tensiune1 = ((((uint16_t)data[6])<<8) | data[7]) & (0x1FFF);
			acceleratie.tensiune2 = ((((((uint16_t)data[4])<<8) | data[5]) & (0x0FFF)) << 2) | (data[6]>>6);
			acceleratie.cursa1 = (((uint8_t)(data[3]<<4)) | (data[4]>>4)) & (0x7F);
			acceleratie.cursa2 = (((uint8_t)(data[2]<<6)) | (data[3]>>3)) & (0x7F);
			acceleratie.tensiuneSenzorPresiune = ((((uint16_t)data[1]<<8)) | (data[2]>>2)) & (0x01FF);
			acceleratie.implausibility = data[0] & (1<<1);
			acceleratie.outOfRangeOutput1 = data[0] & (1<<5);
			acceleratie.shortToVCC1 = data[0] & (1<<6);
			acceleratie.shortToGND1 = data[0] & (1<<7);
			acceleratie.outOfRangeOutput2 = data[0] & (1<<2);
			acceleratie.shortToVCC2 = data[0] & (1<<3);
			acceleratie.shortToGND2 = data[0] & (1<<4);
			break;

		case idCanInvertorStanga:
			//extragere date
			invertoare.stanga.temperaturaMotor = data[7];
			invertoare.stanga.temperaturaInvertor = data[6];
			invertoare.stanga.throttleInvertor = data[5];
			invertoare.stanga.vitezaMotor = data[4];
			invertoare.stanga.throttleSignalFeedback = data[3];
			invertoare.stanga.tensiuneIntrareInvertor = ((((uint16_t)data[1])<<8) | data[2]) & (0x7FF);
			invertoare.stanga.rpmMotor = ((((uint16_t)data[0])<<8) | data[1]) >> 3;
			break;

		case idCanInvertorDreapta:
			//extragere date
			invertoare.dreapta.temperaturaMotor = data[7];
			invertoare.dreapta.temperaturaInvertor = data[6];
			invertoare.dreapta.throttleInvertor = data[5];
			invertoare.dreapta.vitezaMotor = data[4];
			invertoare.dreapta.throttleSignalFeedback = data[3];
			invertoare.dreapta.tensiuneIntrareInvertor = ((((uint16_t)data[1])<<8) | data[2]) & (0x7FF);
			invertoare.dreapta.rpmMotor = ((((uint16_t)data[0])<<8) | data[1]) >> 3;
			break;

		case idCanInvertoare:
			invertoare.isCarRunning = data[0] & (1<<7);
			invertoare.isCarInReverse = data[0] & (1<<6);
			invertoare.stanga.curentInvertor = ((((uint16_t)data[6])<<8) | data[7]) & (0x0FFF);
			invertoare.dreapta.curentInvertor = ((((uint16_t)data[5])<<8) | data[6]) >> 4;
			break;

		case idCanBaterie:
			//extragere date
			baterie.curentPerTotal = ((((uint16_t)data[6])<<8) | data[7]) & (0x1FFF);
			baterie.tensiunePerTotal = ((((uint16_t)data[5])<<8) | data[6]) >> 5;
			baterie.temperaturaMaximaDintreCelule = ((((uint16_t)data[3])<<8) | data[4]) & (0x03FF);
			baterie.tensiuneaMaximaDinteCelule = (((((uint16_t)data[2])<<8) | data[3]) >> 2) & (0x03FF);
			//More To Come:)
			break;

		case idCanBord:
			//extragere date
			bord.activationLogicPressed = data[0] & (1<<7);
			bord.isCarInReverse = data[0] & (1<<6);
			bord.idDisplayWorking = data[0] & (1<<5);
			bord.isSegmentsDriverWorking = data[0] & (1<<4);
			break;
	}
	return TRUE;
}
