#include "provizoriu.h"

uint8 dataTrimisa[8];

boolean primesteDate(Can_HwHandleType handle, Can_IdType id, PduLengthType length, uint8* data){
	for(int i=0;i<8;i++)
		dataTrimisa[i]=data[i];
	return TRUE;
}
