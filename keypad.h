#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "LCD.h"



void LCD_Float(float data);
char get_key (void);
char READ_SWITCHES(void);
void Circ_Init(void);
float ans=0;
float cur=0;
char key;
char keybuf='n';
int get_num(char ch);
void LCD_Display(void);
void op(char key);
void LCD_Startup(void);


   
   
   

   





void op(char key)
{
switch(key)
{
case '+':ans+=cur;
break;
case '-':ans-=cur;
break;
case '*':ans*=cur;
break;
case '/':ans/=cur;
break;
}
}


void LCD_Display()
{
LCD_Clear();
LCD_Cmd(0x80);
LCD_Float(cur);
}
 
void Circ_Init(void)
{

// Use PB pins for LCD interface
// Use PD pins for rows
// Use PC pins for coloumns
 
DDRB = 0xFF; // 1111.1111; set PB0-PB7 as outputs
DDRD=0b00000000; // Set PD4-PD7 as i/p
DDRC=0xFF;// Set PC0-PC5 as o/p
PORTD = 0xFF;    //enable all internal pull-ups  
return;

}


void LCD_Startup(void)
{
LCD_Clear();
LCD_Message("Hello World");

}

char READ_SWITCHES()
{
PORTC = 0b00000000;// Turn all rows to LOW
PORTD = 0b11110000;// Enable Pull-ups

//Check which coloumn has LOW i/p
if (!(PIND & (1<<PD4)))
{
// Change corresponding rows and check the i/p
PORTC=0b00001110;
PORTC=PORTC;
if (!(PIND & (1<<PD4)))
return '1';
PORTC=0b00001101;
PORTC=PORTC;
if (!(PIND & (1<<PD4)))
return '2';
PORTC=0b00001011;
PORTC=PORTC;
if (!(PIND & (1<<PD4)))
return '3';
PORTC=0b00000111;
PORTC=PORTC;
if (!(PIND & (1<<PD4)))
return '+';
}
else if (!(PIND & (1<<PD5)))
{
PORTC=0b00001110;
PORTC=PORTC;
if (!(PIND & (1<<PD5)))
return '4';
PORTC=0b00001101;
PORTC=PORTC;
if (!(PIND & (1<<PD5)))
return '5';
PORTC=0b00001011;
PORTC=PORTC;
if (!(PIND & (1<<PD5)))
return '6';
PORTC=0b00000111;
PORTC=PORTC;
if (!(PIND & (1<<PD5)))
return '-';
}

else if (!(PIND & (1<<PD6)))
{
PORTC=0b00001110;
PORTC=PORTC;
if (!(PIND & (1<<PD6)))
return '7';
PORTC=0b00001101;
PORTC=PORTC;
if (!(PIND & (1<<PD6)))
return '8';
PORTC=0b00001011;
PORTC=PORTC;
if (!(PIND & (1<<PD6)))
return '9';
PORTC=0b00000111;
PORTC=PORTC;
if (!(PIND & (1<<PD6)))
return '*';
}

else if (!(PIND & (1<<PD7)))
{
PORTC=0b00001110;
PORTC=PORTC;
if (!(PIND & (1<<PD7)))
return '=';
PORTC=0b00001101;
PORTC=PORTC;
if (!(PIND & (1<<PD7)))
return '0';
PORTC=0b00001011;
PORTC=PORTC;
if (!(PIND & (1<<PD7)))
return 'c';
PORTC=0b00000111;
PORTC=PORTC;
if (!(PIND & (1<<PD7)))
return '/';
}



return 'n';           // Means no key has been pressed
}

int get_num(char ch)         //convert char into int
{
switch(ch)
{
case '0': return 0; break;
case '1': return 1; break;
case '2': return 2; break;
case '3': return 3; break;
case '4': return 4; break;
case '5': return 5; break;
case '6': return 6; break;
case '7': return 7; break;
case '8': return 8; break;
case '9': return 9; break;
//case 'C': writecmd(0x01); return Error; break;  //this is used as a clear screen and then reset by setting error
//default: DispError(0); return Error; break;     //it means wrong input
}
return 21;
}


char get_key(void)
{
char key = 'n';
while(key=='n')
{
key=READ_SWITCHES();
}
return key;
}

void LCD_Float(float data)
{
char st[8]="";
ftoa(data,st,2);
LCD_Message(st);
}
