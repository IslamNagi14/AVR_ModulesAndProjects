/*
 * IIC_Config.h
 *
 *  Created on: Nov 2, 2024
 *      Author: Islam Nagi
 */

#ifndef DIO_IIC_CONFIG_H_
#define DIO_IIC_CONFIG_H_

#include"IIC_int.h"


#define IIC_MODE  ICC_MASTER

#define IIC_CLOCK_SPEED/*100K Hz-->400K Hz*/		100000ul

#define IIC_PRES/*1 - 4 - 16 - 64*/		1ul

#define IIC_NODE_ADDRESS/*2-->118*/		5
#define IIC_RECOG_GENERALCALL		 	IIC_DISABLE_RECOG_GENERALCALL

#endif /* DIO_IIC_CONFIG_H_ */
