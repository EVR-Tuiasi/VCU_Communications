#ifndef PROVIZORIU_H
#define PROVIZORIU_H

#include"Mcu.h"
#include"Can_43_FLEXCAN.h"

bool primesteDate(Can_HwHandleType handle, Can_IdType id, PduLengthType length, uint8* data);

#endif
