#include "provizoriu.h"

extern uint8 UART_Channel;

boolean primesteDate(Can_HwHandleType handle, Can_IdType id, PduLengthType length, uint8* data){
	//Uart_SyncSend(UART_Channel, buffer, length, 10000000);
	uint8 buffer[length];
	if((id&MASK)==idFrana){
		//extragere date
		uint8 presiune = ((data>>8) | (1<<8));
		uint16 tensiuneSenzorPresiune = ((data>>16) | (1<<16)) & (0x01FF);
		uint16 tensiune2 = ((data>>25) | (1<<16)) & (0x01FF);
		uint16 tensiune1 = ((data>>34) | (1<<16)) & (0x01FF);
		uint8 cursa2 = ((data>>43) | (1<<8)) & (0x7F);
		uint8 cursa1 = ((data>>50) | (1<<8)) & (0x7F);
		uint8 erori = ((data>>57) | (1<<8)) & (0x7F);
		//trimitere date
	}
	else if((id&MASK)==idAcceleratie){
		//extragere date
		uint16 tensiune2 = ((data>>25) | (1<<16)) & (0x01FF);
		uint16 tensiune1 = ((data>>34) | (1<<16)) & (0x01FF);
		uint8 cursa2 = ((data>>43) | (1<<8)) & (0x7F);
		uint8 cursa1 = ((data>>50) | (1<<8)) & (0x7F);
		uint8 erori = ((data>>57) | (1<<8)) & (0x7F);
		//trimitere date
	}
	else if((id&MASK)==idInvertorSt){
		//extragere date
		uint8 tmpMotor = data | (1<<8);
		uint8 tmpInvertor = (data>>8) | (1<<8);
		uint8 throttleSignalFeedback = (data>>16) | (1<<8);
		uint16 curent = (data>>24) | (1<<16);
		uint16 rpm = (data>>40 | (1<<16)) & (0x1FFF);
		uint16 tensiune = (data>>53);
		//trimitere date UART
	}
	else if((id&MASK)==idInvertorDr){
		//extragere date
		uint8 tmpMotor = data | (1<<8);
		uint8 tmpInvertor = (data>>8) | (1<<8);
		uint8 throttleSignalFeedback = (data>>16) | (1<<8);
		uint16 curent = (data>>24) | (1<<16);
		uint16 rpm = (data>>40 | (1<<16)) & (0x1FFF);
		uint16 tensiune = (data>>53);
		//trimitere date UART
	}
	else if((id&MASK)==idBaterie){
		//extragere date
		uint16 curent = data | (1<<16);
		uint16 tensiuneTSAC = (data>>16) | (1<<16);
		uint16 tmpMax = (data>>32) | (1<<16);
		uint16 tensiuneMaxCelule = (data>>48) | (1<<16);
		//trimitere date
	}
	else if((id&MASK)==idBord){
		//extragere date
		bool activationLogic = data & (1ULL<<63);
		bool directieMasina = data & (1ULL<<62);
		uint8 eroriI2C = (data>>59) | (1<<8);
		//Mai e de completat
		//trimitere date
	}
	return TRUE;
}
