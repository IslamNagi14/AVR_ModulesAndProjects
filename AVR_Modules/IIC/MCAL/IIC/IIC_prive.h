/*
 * IIC_prive.h
 *
 *  Created on: Nov 2, 2024
 *      Author: Islam Nagi
 */

#ifndef DIO_IIC_PRIVE_H_
#define DIO_IIC_PRIVE_H_

#define TWAR		*((volatile u8*)0x22)
#define TWBR		*((volatile u8*)0x20)
#define TWCR		*((volatile u8*)0x56)
#define TWDR		*((volatile u8*)0x23)
#define TWSR		*((volatile u8*)0x21)

/*     TWCR REG         */
#define TWINT		7
#define TWEA 		6
#define TWSTA 		5
#define TWSTO 		4
#define TWWC		3
#define TWEN		2
#define TWIE		0

/*     TWSR REG         */
#define TWS7        7
#define TWS6        6
#define TWS5        5
#define TWS4        4
#define TWS3        3
#define TWPS1       1
#define TWPS0       0
/*     TWAR REG         */
#define TWA6         7
#define TWA5         6
#define TWA4         5
#define TWA3         4
#define TWA2         3
#define TWA1         2
#define TWA0         1
#define TWGCE		 0

#define BITRATE(IIC_SPEED)  		((F_CPU - 16ul * IIC_SPEED) / (2ul * IIC_SPEED * IIC_PRES))

#define MASTER		 4
#define SLAVE		 8

#define ENABLE_RECOG_GENERALCALL	1
#define DISABLE_RECOG_GENERALCALL	0

#define WRITE		0
#define READ		1
#endif /* DIO_IIC_PRIVE_H_ */
