/*
 * rotate.c
 *
 *  Created on: 2026. 1. 28.
 *      Author: junwoo
 */

#include"rotate.h"

//extern volatile bool Flag;
//extern volatile bool Flag1;
//extern volatile bool Flag2;
//extern volatile bool Flag3;

extern volatile uint8_t Flag;
extern volatile uint8_t Flag1;
extern volatile uint8_t Flag2;
extern volatile uint8_t Flag3;

volatile uint8_t curr = 20;
volatile uint8_t direction = 0;


//void rotate()
//{
//	  if(Flag)
//	  {
//		  if(direction==0)
//		  {
//			for(uint16_t i=curr;i<130;i++)
//			{
//				if (!Flag)
//				{
//					break;
//				}
//				curr=i;
//				TIM3->CCR1=i;
//				HAL_Delay(50);
//
//				if(i==129) direction=1;
//			}
//		  }
//		  if(direction==1)
//		  {
//			for(uint16_t i=curr;i>20;i--)
//			{
//				if (!Flag)
//				{
//					break;
//				}
//				curr=i;
//				TIM3->CCR1=i;
//				HAL_Delay(50);
//
//				if (i == 21) direction = 0;
//			}
//		  }
//		}
//}

void rotate()
{
    // static 변수는 함수가 끝나도 값을 기억합니다.
    static uint32_t last_rotate_tick = 0;
    uint32_t current_tick = HAL_GetTick();

    if (!Flag)
    {
        // 중요: 회전 안 할 때는 타이머를 현재 시간으로 계속 업데이트해서
        // 켜지는 순간 바로 움직이게 대기시킵니다.
        last_rotate_tick = current_tick;
        return;
    }

    // 50ms 지났는지 확인
    if (current_tick - last_rotate_tick >= 10)
    {
        last_rotate_tick = current_tick;

        if (direction == 0) {
            curr++;
            if (curr >= 130) direction = 1;
        } else {
            curr--;
            if (curr <= 20) direction = 0;
        }
        TIM3->CCR1 = curr;
    }
}

