#include <avr/io.h>
#include "main.h"
#include "display.h"
// #define NUMBEROFELEMENTS(x) (sizeof(x)/sizeof(*(x)))
#define COUNT 10 
int main(void)
{
	DDRD  |= ((1<<DATA) | (1<<WR) | (1<<RD) | (1<<CS) | (1<<LEDA) | (1<<LEDB));
	PORTD |= ((1<<DATA) | (1<<WR) | (1<<RD) | (1<<CS) | (1<<LEDA) | (1<<LEDB));


Delay(3000);

// Set system clock source
// Set Timer, WDT option
// Set internal LCD bias and duty
// Set system control(SYS EN)
// Clear display RAM
// Set LCD bias generator control(LCD ON)
Send_command(SYS_EN);
Send_command(BIAS_COM);
Send_command(LCD_ON);
// Send_command(TONE_4K);
// Send_command(TONE_ON);


uint8_t i,j,k,m,flags,temp;
i=j=k=m=flags=temp= 0;

Clear_display();

while(1)
{
	m++;
	Delay(1000);
	temp ++;
	if (temp == 3)
	{
		temp = 0;
		if (flags & (1<<DOTS))
		{
			flags &=~(1<<DOTS);
			Send_data(DDOT|MASK_B);
		}
		else
		{
			flags |=(1<<DOTS);
			Send_data(DDOT|MASK_A);
		}
	}

	if (m==COUNT)
	{
		m = 0;
		k++;
		if (k==COUNT)
		{
			k = 0;
			j++;
			if (j==COUNT)
			{
				j = 0;
				i++;
				if (i==COUNT)
				{
					i = 0;
					Clear_display();
				}
				else
				{
					Write_segment_data(j,1);
					Write_segment_data(i,0);
				}
			}
			else
			{
				Write_segment_data(j,1);
				Write_segment_data(k,2);
			}
		}
		else
		{
			Write_segment_data(m,3);
			Write_segment_data(k,2);
		}

	}
	else
	{
		Write_segment_data(m,3);
	}
}
return -1;
}

