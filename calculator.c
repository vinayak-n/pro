
void reverse(char *str, int len)
{
    int i=0, j=len-1, temp;
    while (i<j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++; j--;
    }
}
 
 // Converts a given integer x to string str[].  d is the number
 // of digits required in output. If d is more than the number
 // of digits in x, then 0s are added at the beginning.
int intToStr(int x, char str[], int d)
{
    int i = 0;
    while (x)
    {
        str[i++] = (x%10) + '0';
        x = x/10;
    }
 
    // If number of digits required is more, then
    // add 0s at the beginning
    while (i < d)
        str[i++] = '0';
 
    reverse(str, i);
    str[i] = '\0';
    return i;
}
 
// Converts a floating point number to string.
void ftoa(float n, char *res, int afterpoint)
{
    // Extract integer part
    int ipart = (int)n;
 
    // Extract floating part
    float fpart = n - (float)ipart;
 
    // convert integer part to string
    int i = intToStr(ipart, res, 0);                              
 
    // check for display option after point
     if (afterpoint != 0)
    {
        res[i] = '.';  // add dot
 
        // Get the value of fraction part upto given no.
        // of points after dot. The third parameter is needed
        // to handle cases like 233.007
        n=n*pow(10,afterpoint);
        int x=pow(10,afterpoint)+0.5;              
               
        fpart = fpart *x;
        //printf("%f",fpart);
        //printf("\n");
        int n1=fpart;
        //LCD_Integer(n1);
        if((fpart+0.5)>(n1+1))
n1;
        //printf("%d",n1);
        //printf("\n");
       
        intToStr(n1, res + i + 1, afterpoint);
       
    }
} 
void LCD_Float(float data)
{
char st[8]="";
ftoa(data,st,2);
//LCD_Message(st);
}

int main(void)
{
Circ_Init(); // Initialize the circuit
LCD_Init(); // initialize LCD controller
LCD_Startup();
LCD_Clear();
while(1)
{

key=get_key();
switch(key)
{
case '1':
case '2':
case '3':
case '4':
case '5':
case '6':
case '7':
case '8':
case '9':
case '0':cur=10*cur+get_num(key);
    LCD_Char(key);
    break;
   case 'c':LCD_Clear();
   
ans=0;
cur=0;
break;
case '+':
case '-':
case '*':
case '/':if(keybuf!='n')
op(keybuf);
keybuf=key;
cur=0;
LCD_Char(key);
break;
case '=':if(keybuf!='n')
op(keybuf);

cur=0;
LCD_Cmd(0xC0);
LCD_Integer(ans);
break;
}
_delay_ms(500);
}
}
   
   
   

   





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
