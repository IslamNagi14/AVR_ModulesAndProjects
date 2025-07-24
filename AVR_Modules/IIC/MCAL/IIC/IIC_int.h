/*
 * IIC_int.h
 *
 *  Created on: Nov 2, 2024
 *      Author: Islam Nagi
 */

#ifndef DIO_IIC_INT_H_
#define DIO_IIC_INT_H_

#include"../../LIB/StdTypes.h"
#include"../../LIB/errorStatuse.h"

ES_t IIC_enuINIT(void);

ES_t IIC_enuStartCondition(void);

ES_t IIC_enuRepeatedStartCondition(void);

ES_t IIC_enuStopCondition(void);

ES_t IIC_enuWriteSlaveAddress(u8 Copy_u8SlaveAddress, u8 Copy_u8Operation);

ES_t IIC_enuCheckMyAddress(void);

ES_t IIC_enuWriteData(u8 Copy_u8Data);

ES_t IIC_enuReadData(u8 *Copy_u8Data);


#define  ICC_MASTER		4
#define  ICC_SLAVE		8

#define IIC_ENABLE_RECOG_GENERALCALL	1
#define IIC_DISABLE_RECOG_GENERALCALL	0

#define IIC_WRITE		0
#define IIC_READ		1
#endif /* DIO_IIC_INT_H_ */
