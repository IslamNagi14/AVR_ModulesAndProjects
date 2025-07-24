/*
 * IIC_prog.c
 *
 *  Created on: Nov 2, 2024
 *      Author: Islam Nagi
 */

#include"../../LIB/StdTypes.h"
#include"../../LIB/errorStatuse.h"

#include"IIC_prive.h"
#include"IIC_Config.h"


ES_t IIC_enuINIT(void)
{
	ES_t Local_enuErrorState = ES_NOK;

#if IIC_MODE == ICC_MASTER
	TWBR = (u8)BITRATE(IIC_CLOCK_SPEED);
	#if IIC_PRES == 1
		TWSR &= ~(MASK_NUM<<TWPS0);
		TWSR &= ~(MASK_NUM<<TWPS1);
	#elif IIC_PRES == 4
		TWSR |= (MASK_NUM<<TWPS0);
		TWSR &= ~(MASK_NUM<<TWPS1);
	#elif IIC_PRES == 16
		TWSR &= ~(MASK_NUM<<TWPS0);
		TWSR |= (MASK_NUM<<TWPS1);
	#elif IIC_PRES == 16
		TWSR |= (MASK_NUM<<TWPS0);
		TWSR |= (MASK_NUM<<TWPS1);
	#else "Wrong PRESACLAR"

	#endif

	TWAR &= ~(MASK_NUM<<TWGCE);
					TWAR = (IIC_NODE_ADDRESS<<MASK_NUM) | IIC_RECOG_GENERALCALL;

			TWCR |= (MASK_NUM<<TWCR);//clear flag

			TWCR |= (MASK_NUM<<TWEN);//enable IIC
			TWCR |= (MASK_NUM<<TWEA);//enable Aknowledge



#elif IIC_MODE == ICC_SLave

		TWAR = 0;
	 	TWAR = (IIC_NODE_ADDRESS<<MASK_NUM) | IIC_RECOG_GENERALCALL;

		TWCR |= (MASK_NUM<<TWINT);//clear flag

		TWCR |= (MASK_NUM<<TWEN);//enable IIC


#endif

		TWAR &= ~(MASK_NUM<<TWGCE);
				TWAR = (IIC_NODE_ADDRESS<<MASK_NUM) | IIC_RECOG_GENERALCALL;

				TWCR |= (MASK_NUM<<TWCR);//clear flag

				TWCR |= (MASK_NUM<<TWEN);//enable IIC
				TWCR |= (MASK_NUM<<TWEA);//enable Aknowledge

	return Local_enuErrorState;
}

ES_t IIC_enuStartCondition(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	TWCR |=(MASK_NUM<<TWSTA);
	TWCR |= (MASK_NUM<<TWINT);//clear flag
	while(! ((TWCR>>TWINT) & 1) );

	if((TWSR & 0xF8) == 0x08)
		Local_enuErrorState = ES_OK;


	return Local_enuErrorState;
}

ES_t IIC_enuRepeatedStartCondition(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	TWCR |=(MASK_NUM<<TWSTA);
		TWCR |= (MASK_NUM<<TWINT);//clear flag
		while(! ((TWCR>>TWINT) & 1) );

		if((TWSR & 0xF8) == 0x10)
			Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}

ES_t IIC_enuStopCondition(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	TWCR |= (MASK_NUM<<TWINT);//clear flag
	TWCR |= (MASK_NUM<<TWSTO);

	TWCR &= ~(MASK_NUM<< TWSTA);// clear start condition


	return Local_enuErrorState;
}

ES_t IIC_enuWriteSlaveAddress(u8 Copy_u8SlaveAddress, u8 Copy_u8Operation)
{
	ES_t Local_enuErrorState = ES_NOK;

	TWDR = ( (Copy_u8SlaveAddress << 1) | Copy_u8Operation);

	TWCR &= ~(MASK_NUM<< TWSTA);// clear start condition

	TWCR |= (MASK_NUM<<TWINT);//clear flag

	while(! ((TWCR>>TWINT) & 1) );

	if( (TWSR & 0xF8) == 0x18  && Copy_u8Operation == WRITE)
		Local_enuErrorState = ES_OK;
	else if( (TWSR & 0xF8) == 0x40  && Copy_u8Operation == READ)
		Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}

ES_t IIC_enuCheckMyAddress(void)
{
	ES_t Local_enuErrorState = ES_NOK;


	TWCR |=(MASK_NUM<<TWEA);// enable acknowledge

	TWCR |= (MASK_NUM<<TWINT);//clear flag
	while(! ((TWCR>>TWINT) & 1) );
	if ((TWSR & 0xF8) == 0x60)
		Local_enuErrorState = ES_OK;
	else if((TWSR & 0xF8) == 0xA8)
		Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}

ES_t IIC_enuWriteData(u8 Copy_u8Data)
{
	ES_t Local_enuErrorState = ES_NOK;

	TWDR = Copy_u8Data;
	TWCR |= (MASK_NUM<<TWINT);//clear flag

		while(! ((TWCR>>TWINT) & 1) );

		if ((TWSR & 0xF8) == 0x28)
			Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}

ES_t IIC_enuReadData(u8 *Copy_u8Data)
{
	ES_t Local_enuErrorState = ES_NOK;
	TWCR |= (MASK_NUM<<TWINT);//clear flag
		while(! ((TWCR>>TWINT) & 1) );
		if ((TWSR & 0xF8) == 0x58)
		{
			*Copy_u8Data = TWDR;
			Local_enuErrorState = ES_OK;
		}
		else if((TWSR & 0xF8) == 0x80)
		{
			*Copy_u8Data = TWDR;
			Local_enuErrorState = ES_OK;
		}

	return Local_enuErrorState;
}
