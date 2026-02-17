#ifndef PROVIZORIU_H
#define PROVIZORIU_H

#include"Mcu.h"
#include"Can_43_FLEXCAN.h"
#include "CDD_Uart.h"
#include "Messaging_Types.h"

#define MASK 0x3FFFFFFF

typedef enum{
	idCanFrana = 0x00000331,
	idCanAcceleratie = 0x00000330,
	idCanInvertorStanga = 0x00000110,
	idCanInvertorDreapta = 0x00000111,
	idCanInvertoare = 0x00000112,
	idCanBaterie = 0x00000440,
	idCanBord = 0x00000220
}idCan;

typedef enum{
	idUartInvertorStanga = 0x00000010,
	idUartInvertorDreapta = 0x00000011,
	idUartInvertoare = 0x00000012,
	idUartBord = 0x00000020,
	idUartAcceleratie = 0x00000030,
	idUartFrana = 0x00000031,
	idUartBaterie = 0x000040
}idUart;

bool primesteDate(Can_HwHandleType handle, Can_IdType id, PduLengthType length, uint8_t* data);

#endif
