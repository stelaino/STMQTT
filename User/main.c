#include <stm32f10x.h>


void LED_Init(void)

{

   GPIO_InitTypeDef   GPIO_InitStructure;                  //定义结构体变量

   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);    //时钟使能

   GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12;                 //哪个端口？

   GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;          //推挽输出

   GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;         //速度

   GPIO_Init(GPIOB, &GPIO_InitStructure);                  //初始化

   GPIO_SetBits(GPIOB,GPIO_Pin_12);                         //置位 点亮

 

}

void Delay_ms(u32 time)  
{  
  u32 i=8000*time;  
  while(i--);  
}  

int main(void)

{ 

	LED_Init();		         //LED函数初始化（函数声明）

	while(1)

	{

		GPIO_ResetBits(GPIOB,GPIO_Pin_12);  //（复位函数）   0   低   亮
		Delay_ms(6000);  		   
		Delay_ms(6000);    
		GPIO_SetBits(GPIOB,GPIO_Pin_12);	   // 重复复位              灭
		Delay_ms(6000);    
		Delay_ms(6000);    
		
	}

} 

