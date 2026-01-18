#include "provizoriu.h"

extern uint8 UART_Channel;

struct dateInvertoare invt;
struct dateFrana frana;
struct dateAcceleratie acceleratie;
struct dateBaterie baterie;
struct dateBord bord;

boolean primesteDate(Can_HwHandleType handle, Can_IdType id, PduLengthType length, uint8* data){
	//Uart_SyncSend(UART_Channel, buffer, length, 10000000);
	if((id&MASK)==idFrana){
		//extragere date
		frana.presiune = data[1];
		frana.tensiuneSenzorPresiune = ((((uint16)data[3])<<8) | data[2]) & (0x01FF);
		frana.tensiune2 = (((((uint16)data[4])<<8) | data[3]) >> 1) & (0x01FF);
		frana.tensiune1 = (((((uint16)data[5])<<8) | data[4]) >> 2) & (0x01FF);
		frana.cursa2 = (uint8)((((((uint16)data[6])<<8) | data[5]) >> 3) & (0x007F));
		frana.cursa1 = (uint8)((((((uint16)data[7])<<8) | data[6]) >> 2) & (0x007F));
		frana.erori = data[7] >> 1;
	}
	else if((id&MASK)==idAcceleratie){
		//extragere date
		acceleratie.tensiune2 = (((((uint16)data[4])<<8) | data[3]) >> 1) & (0x01FF);
		acceleratie.tensiune1 = (((((uint16)data[5])<<8) | data[4]) >> 2) & (0x01FF);
		acceleratie.cursa2 = (uint8)((((((uint16)data[6])<<8) | data[5]) >> 3) & (0x007F));
		acceleratie.cursa1 = (uint8)((((((uint16)data[7])<<8) | data[6]) >> 2) & (0x007F));
		acceleratie.erori = data[7] >> 1;
	}
	else if((id&MASK)==idInvertorSt){
		//extragere date
		invt.st.tmpMotor = data[7];
		invt.st.tmpInvertor = data[6];
		invt.st.throttleSignalFeedback = data[5];
		invt.st.curent = (((uint16)data[3])<<8) | data[4];
		invt.st.rpm = ((((uint16)data[1])<<8) | data[2]) & (0x1FFF);
		invt.st.tensiune = ((((uint16)data[0])<<8) | data[1]) >> 5;
	}
	else if((id&MASK)==idInvertorDr){
		//extragere date
		invt.dr.tmpMotor = data[7];
		invt.dr.tmpInvertor = data[6];
		invt.dr.throttleSignalFeedback = data[5];
		invt.dr.curent = (((uint16)data[3])<<8) | data[4];
		invt.dr.rpm = ((((uint16)data[1])<<8) | data[2]) & (0x1FFF);
		invt.dr.tensiune = ((((uint16)data[0])<<8) | data[1]) >> 5;
	}
	else if((id&MASK)==idBaterie){
		//extragere date
		baterie.curent = ((((uint16)data[6])<<8) | data[7]) & (0x1FFF);
		baterie.tensiuneTSAC = ((((uint16)data[4])<<8) | data[5]) & (0x07FF);
		baterie.tmpMax = ((((uint16)data[2])<<8) | data[3]) & (0x03FF);
		baterie.tensiuneMaxCelule = ((((uint16)data[0])<<8) | data[1]) & (0x03FF);
	}
	else if((id&MASK)==idBord){
		//extragere date
		bord.activationLogic = data[7] & (1<<7);
		bord.directieMasina = data[7] & (1<<6);
		bord.eroriI2C = (data[7] >> 3) & (0x0007);
		//Mai e de completat
	}
	return TRUE;
}
