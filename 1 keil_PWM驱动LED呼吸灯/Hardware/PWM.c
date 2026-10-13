//#include "stm32f10x.h"                  // Device header

//void PWM_Init(void)
//{
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
//	
////	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
////	GPIO_PinRemapConfig(GPIO_PartialRemap1_TIM2, ENABLE);
////	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
//	
//	GPIO_InitTypeDef GPIO_InitStructure;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;//复用推挽输出
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;		//GPIO_Pin_15;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOA, &GPIO_InitStructure);
//	
//	TIM_InternalClockConfig(TIM2);//内部时钟源选择
//	
//	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;             //时基单元配置
//	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;    //时钟分频 
//	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;//向上计数模式
//	TIM_TimeBaseInitStructure.TIM_Period = 100 - 1;		//ARR
//	TIM_TimeBaseInitStructure.TIM_Prescaler = 720 - 1;	//PSC
//	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;//重复计数器
//	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure); //把配置好的结构体地址給
//	
//	TIM_OCInitTypeDef TIM_OCInitStructure;//输出比较寄存器配置
//	
//	TIM_OCStructInit(&TIM_OCInitStructure);//将定时器输出比较结构体TIM_OCInitStructure中
//										   //的所有成员初始化为标准外设库规定的默认值。
//										   //成员太多只用几个但是要吧别的结构体成员初始化。
//										   
//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;//模式选择PWM1
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;//设置输出比较通道为高电平有效
//															//也就是输出不反相，就是高电平就是高电平，不是低电平
//	
//															
//	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;//使能输出比较通道
//	TIM_OCInitStructure.TIM_Pulse = 50;		//CCR，决定CCR初始值，从而决定占空比。
//	TIM_OC1Init(TIM2, &TIM_OCInitStructure);	//把结构体的值
//	
//	TIM_Cmd(TIM2, ENABLE);//使能TIM2定时器
//}

//void PWM_SetCompare1(uint16_t Compare)
//{
//	TIM_SetCompare1(TIM2, Compare);//修改输出比较寄存器1 上面的数值
//	
//}

#include "stm32f10x.h"                  // Device header

void main()
{
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

}
