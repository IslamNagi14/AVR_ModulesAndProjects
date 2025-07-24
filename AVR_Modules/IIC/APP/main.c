/*
 * main.c
 *
 *  Created on: Nov 2, 2024
 *      Author: Islam Nagi
 */

#include"../LIB/StdTypes.h"
#include"../LIB/errorStatuse.h"
#include"../MCAL/IIC/IIC_Config.h"
#include"../MCAL/IIC/IIC_int.h"
#include"../MCAL/DIO/DIO_prive.h"


#define code 1

#if code == 0
int main(void)
{
	IIC_enuINIT();
	while(1)
	{

		if(ES_OK == IIC_enuStartCondition())
		{
			if(ES_OK == IIC_enuWriteSlaveAddress(5,IIC_WRITE))
			{
				if(ES_OK == IIC_enuWriteData(0xf5))
				{
					IIC_enuStopCondition();
				}
			}
			else
			{
				DDRB = 0x11;
			}
		}

	}
	return 0;
}
#elif code == 1
int main()
{
	u8 data;

		IIC_enuINIT();
			while(1)
			{

				if(ES_OK == IIC_enuCheckMyAddress())
				{
					if(ES_OK == IIC_enuReadData(&data) )
					{
						DDRA = data;
					}
					else
					{
						DDRC = 0x11;
					}
				}
			}
			return 0;
}
#endif
