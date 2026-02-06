/*
 * bt.c
 *
 *  Created on: Jan 28, 2026
 *      Author: appletea
 */
#include "bt.h"

uint8_t rxData[10];

extern volatile uint8_t g_day = 1;        // 1~4 (초기 DAY1)
extern volatile uint8_t g_day_next_req = 0; // BT에서 '4' 오면 1로 세팅(원샷)



extern volatile uint8_t Flag;
extern volatile uint8_t Flag1;
extern volatile uint8_t Flag2;
extern volatile uint8_t Flag3;


//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
//{
//	HAL_UART_Receive_IT(&huart1, rxData, 10);
//}

void Check()
{
		if(rxData[0] == '0')
		  {
			Flag = !Flag;
			rxData[0]=0;
		  }
		  if(rxData[0] =='1')
		  {
			 Flag1= 1;
			 rxData[0]=0;
		  }
		if(rxData[0] == '2')
		  {
			Flag2= 1;
			rxData[0]=0;
		  }
		if(rxData[0] =='3')
		  {
			 Flag3= 1;
			 rxData[0]=0;
		  }

		if(rxData[0] =='4')
						  {
			 g_day_next_req = 1;
			    rxData[0] = 0;
						  }

}
