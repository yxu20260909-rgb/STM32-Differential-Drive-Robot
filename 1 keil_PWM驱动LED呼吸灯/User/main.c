#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"

uint8_t i;

int main(void)
{
	OLED_Init();//初始化OLED
	PWM_Init();//初始化PWM
	

	OLED_ShowString(1,1,"PSC:");
	OLED_ShowString(2,1,"ARR:");
	OLED_ShowString(3,1	,"CCR:");
	

	
	while (1)
	{
		OLED_ShowNum(1,5,TIM2->PSC,6);
		OLED_ShowNum(2,5,TIM2->ARR,6);
		
			
		for (i = 0; i <= 100; i++)//把CCR的数值从0递增100，pwm占空比从0到100
		{
			PWM_SetCompare1(i);
			Delay_ms(10);
			OLED_ShowNum(3,5,TIM2->CCR1,6);//CCR=50
		}
		for (i = 0; i <= 100; i++)//把CCR的数值从100递减到0，PWM占空比从100到0
		{
			PWM_SetCompare1(101 - i);
			Delay_ms(10);
			OLED_ShowNum(3,5,TIM2->CCR1,6);//CCR=50
		}
	}
}
//#include "stm32f10x.h"
//#include "OLED.h"
//#include "PWM.h"
//#include "Delay.h"

//#error MAIN_C_COMPILE_TEST

//int main(void)
//{
//    OLED_Init();
//    PWM_Init();

//    OLED_Clear();

//    OLED_ShowString(1, 1, "TEST123");
//    OLED_ShowNum(2, 1, 888888, 6);
//    OLED_ShowNum(3, 1, 123456, 6);

//    while (1)
//    {

//    }
//}


