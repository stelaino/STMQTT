#include <stm32f10x.h>


void LED_Init(void)

{

   GPIO_InitTypeDef   GPIO_InitStructure;                  //����ṹ�����

   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);    //ʱ��ʹ��

   GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12;                 //�ĸ��˿ڣ�

   GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;          //�������

   GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;         //�ٶ�

   GPIO_Init(GPIOB, &GPIO_InitStructure);                  //��ʼ��

   GPIO_SetBits(GPIOB,GPIO_Pin_12);                         //��λ ����

 

}

void Delay_ms(u32 time)  
{  
  u32 i=8000*time;  
  while(i--);  
}  

int main(void)

{ 

	LED_Init();		         //LED������ʼ��������������

	while(1)

	{

		GPIO_ResetBits(GPIOB,GPIO_Pin_12);  //����λ������   0   ��   ��
		Delay_ms(6000);  		   
		Delay_ms(6000);    
		GPIO_SetBits(GPIOB,GPIO_Pin_12);	   // �ظ���λ              ��
		Delay_ms(6000);    
		Delay_ms(6000);    
		
	}

} 

