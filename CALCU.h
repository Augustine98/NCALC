#include<ctype.h>
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#include<stdlib.h>
#include<iostream.h>
#include<graphics.h>
#include<math.h>
#include<string.h>
# define UNCLICKED 0
# define CLICKED 1
int X=0, Y=0 ;
char flag='d',flagp='0',bflagp='u';
float *mem;
int sflag=0;
int  f ,a,b,c,d;


/*
void end()
{
 cleardevice();
closegraph();
 textcolor(7);
 cprintf("       ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ \r\n");
 textcolor(7);
 cprintf("    ÜÜßÛ ");textcolor(1);cprintf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ» ");textcolor(7);cprintf("Û \r\n");
 textcolor(7);
 cprintf(" ÜÜÜß  Û ");textcolor(1);cprintf("º               º ");textcolor(7);cprintf("Û \r\n");
 textcolor(7);
 cprintf(" Û     Û ");textcolor(1);cprintf("º    ");textcolor(WHITE);cprintf("Û      Û   ");textcolor(1);cprintf("º ");textcolor(7);cprintf("Û \r\n");
 textcolor(7);
 cprintf(" Û     Û ");textcolor(1);cprintf("º               º ");textcolor(7);cprintf("Û \r\n");
 textcolor(7);
 cprintf(" Û     Û ");textcolor(1);cprintf("º    ");textcolor(RED);cprintf("ßÜ    Üß   ");textcolor(1);cprintf("º ");textcolor(7);cprintf("Û \r\n");
 textcolor(7);
 cprintf(" ÛÜÜ   Û ");textcolor(1);cprintf("º      ");textcolor(RED);cprintf("ßßßß     ");textcolor(1);cprintf("º ");textcolor(7);cprintf("Û \r\n");
 textcolor(7);
 cprintf("    ÛÜ Û ");textcolor(1);cprintf("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼ ");textcolor(7);cprintf("Û \r\n");
 textcolor(7);
 cprintf("      ßÛÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÛ \r\n\n\n");

  textcolor(15);
 cprintf("By: ");textcolor(14);cprintf("Augustine T Prince ");textcolor(15);cprintf("'\r\nThanks for using.");
 getch();
 }

*/


/************************************************************************/
/* Mouse Related Functions */
/************************************************************************/
void init_mouse()
{
    union REGS iregs, oregs;
    iregs.x.ax = 0;
    int86 (0x33, &iregs, &oregs);
    if (oregs.x.ax == 0)
    {
	cleardevice();
	cout<<"mouse not installed";
	getch();
	exit(1);
    }
    iregs.x.ax = 1;
    int86 (0x33, &iregs ,&oregs);
}
/*************************************************************/
void mouse()
{
    int button,x1,y1;
    union REGS iregs, oregs;
    iregs.x.ax = 3;
    int86 (0x33, &iregs ,&oregs);
    button = oregs.x.bx & 3;
    x1 = oregs.x.cx;
    y1 = oregs.x.dx;
    if(oregs.x.bx & 1)
    {
	X = x1 ; Y = y1;
    }
    if(button == 3)
    exit(0);
}
/*************************************************************/
void hide_mouse()
{
    union REGS ioRegs;
    ioRegs.x.ax=2;
    int86(0x33,&ioRegs,&ioRegs);
}
/*************************************************************/
void show_mouse()
{
    union REGS ioRegs;
    ioRegs.x.ax=1;
    int86(0x33,&ioRegs,&ioRegs);
}
/*************************************************************/
void remove_mouse()
{
    union REGS ioRegs;
    ioRegs.x.ax=0;
    int86(0x33,&ioRegs,&ioRegs);
}// end of mouse functions



void button(int x1,int y1,int x2,int y2,int check,char* text,int color)
{
    setfillstyle(1,8);
    bar(x1,y1,x2,y2);
    setcolor(15);
    sound(70);// turns on the speaker to 70Hz
    delay(1);
    nosound();// turns off the speaker
    int low,c;
    if(check==0) //Unclicked
      low=20,c=8;
    else
      low=8,c=7; //Clicked
    setcolor(low);
    if(strcmpi(text,"=")==0)
    {
	if(check==0)
	c=3;
	else
	c=11;
    }
    else if(strcmpi(text,"shift")==0)
    {
	if(check==0)
	c=4;
	else
	c=12;
    }
    else if((strcmpi(text,"SCIENTIFIC CALC")==0)&&(check==1))
    {
	c=3;color=15;
    }
     else if((strcmpi(text,"GRAPHING")==0)&&(check==1))
    { 
     c=2;color=15;
     } 
    else if(color==4)
    {
	color=15;c=4;
    }
    else if(color==15)
    {
	c=14;color=0;
    }
    setfillstyle(1,c);
    bar(x1,y1,x2,y2);
    if(color==0&&c!=14)
      setcolor(14);
    else
      setcolor(color);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    outtextxy(x1+(x2 - x1)/2,(y1+(y2 - y1)/2)-2, text);
}
/*********************************************************************/
/* This function makes the calculating screen                                                                         */
/*********************************************************************/
void screen(int x1, int y1, int x2, int y2)
{
    setlinestyle(0,0,1);
    setfillstyle(SOLID_FILL, 8);
    bar(x1, y1, x2, y2);
    setfillstyle(SOLID_FILL, BLACK);
    bar(x1+1, y1+1, x2-1, y2-1);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    setcolor(15);
    line(x1+1, y1+1, x1+1, y2-1);
    line(x1+1, y1+1, x2-1, y1+1);
    line(x1+2, y1+2, x1+2, y2-2);
    line(x1+2, y1+2, x2-2, y1+2);
    setcolor(8);
    line(x1+1, y2-1, x2-1, y2-1);
    line(x2-1, y1+1, x2-1, y2-1);
    line(x1+2, y2-2, x2-2, y2-2);
    line(x2-2, y1+2, x2-2, y2-2);
}



void mstructure() // Menu for matrix operations
{
    init_mouse(); show_mouse();
    setcolor(14);
    button(100,90,190,155,UNCLICKED,"EDIT MATRIX",0);
    button(100,165,190,230,UNCLICKED,"MATRIX PRODUCT",0); // Box Of mat prod
    button(200,165,290,230,UNCLICKED,"INVERSE",0); // Box Of inverse
    button(100,240,190,305,UNCLICKED,"MINOR",0); // Box Of Min
    button(350,165,440,230,UNCLICKED,"DETERMINANT",0); // Box Of Det
    button(450,165,540,230,UNCLICKED,"ADJOINT",0); // Box Of Adjoint
    button(200,240,290,305,UNCLICKED,"CO-FACTOR",0); // Box Of Cofactor
    button(350,240,440,305,UNCLICKED,"DOT +",0); // Box Of .+
    button(450,240,540,305,UNCLICKED,"DOT -",0); // Box Of .-
    button(350,315,440,380,UNCLICKED,"DOT x",0); // Box Of .x
    button(450,315,540,380,UNCLICKED,"DOT /",0); // Box Of ./
    button(100,315,190,380,UNCLICKED,"TRANSPOSE",0); // Box Of transpose
    button(200,315,290,380,UNCLICKED,"TRACE",0); // Box Of trace
}
void gstructure()
{
  init_mouse(); show_mouse();
    setcolor(14);settextstyle(2,0,4);
    button(100,90,290,155,UNCLICKED,"LINEAR EQUATIONS",0);
    button(100,165,290,230,UNCLICKED,"QUADRATIC EQUATIONS",0); // Box Of mat prod
    button(100,240,290,305,UNCLICKED,"CIRCLE",0); // Box Of Min
    button(350,165,540,230,UNCLICKED,"ELLIPSE",0); // Box Of Det
    button(350,240,540,305,UNCLICKED,"HYPERBOLA",0); // Box Of .+
    button(350,315,540,380,UNCLICKED,"GENERAL CONIC",0); // Box Of .x
    button(100,315,290,380,UNCLICKED,"PARABOLA",0); // Box Of transpose

 }

void minit()
{
    init_mouse();setbkcolor(0);
    cleardevice();hide_mouse();
    setfillstyle(1,0); setcolor(14);
    bar3d(50,20,600,400,1,1);
    setcolor(3);
    setfillstyle(1,8);
    bar(52,22,598,42);//header
    button(575,23,595,40,UNCLICKED,"x",0);
    setcolor(4);line(52,44,598,44); setcolor(15);
    b=4;a=c=d=0;
    button(52,22,183,42,UNCLICKED,"SCIENTIFIC CALC",a); // TAB 1
    button(183,22,314,42,CLICKED,"MATRICES",b); // TAB 2
    button(314,22,445,42,UNCLICKED,"GRAPHING",c);  // TAB 3
    button(445,22,574,42,UNCLICKED,"CONVERSIONS",d); // TAB 4
}

void ginit()
{

    init_mouse();setbkcolor(0);
    cleardevice();hide_mouse();
     settextstyle(2,0,4);
    setfillstyle(1,0); setcolor(14);
    bar3d(50,20,600,400,1,1);
    setcolor(3);
    setfillstyle(1,8);
    bar(52,22,598,42);//header
    button(575,23,595,40,UNCLICKED,"x",0);
    setcolor(2);line(52,44,598,44); setcolor(15);
    c=2;a=b=d=0;
    button(52,22,183,42,UNCLICKED,"SCIENTIFIC CALC",a); // TAB 1
    button(183,22,314,42,UNCLICKED,"MATRICES",b); // TAB 2
    button(314,22,445,42,CLICKED,"GRAPHING",c);  // TAB 3
    button(445,22,574,42,UNCLICKED,"CONVERSIONS",d); // TAB 4
 }
/*************************************************************************/
/* THIS FUNCTION DRAWS THE CALCULATOR ON THE SCREEN                                                  */
/*************************************************************************/
void structure()
{
    init_mouse();
    setbkcolor(0);
    cleardevice();
    hide_mouse();
    // Buttons Making
    settextstyle(2,0,4);
    setfillstyle(1,0);
    setcolor(14);
    bar3d(50,20,600,400,1,1); // main box
    setcolor(3);
    screen(100,50,545,120); // screen
    setfillstyle(1,8);
    bar(52,22,598,42);//header
    button(575,23,595,40,UNCLICKED,"x",0);
    setlinestyle(0,1,4);
    setcolor(3);line(52,44,598,44);
    setcolor(15);
    a=3;b=c=d=0;
    button(52,22,183,42,CLICKED,"SCIENTIFIC CALC",a); // TAB 1
    button(183,22,314,42,UNCLICKED,"MATRICES",b); // TAB 2
    button(314,22,445,42,UNCLICKED,"GRAPHING",c);  // TAB 3
    button(445,22,574,42,UNCLICKED,"CONVERSIONS",d); // TAB 4
    button(350,205,380,225,UNCLICKED,"7",0); // Box Of 7
    button(390,205,420,225,UNCLICKED,"8",0); // Box Of 8
    button(430,205,460,225,UNCLICKED,"9",0); // Box Of 9
    button(350,230,380,250,UNCLICKED,"4",0); // Box Of 4
    button(390,230,420,250,UNCLICKED,"5",0); // Box Of 5
    button(430,230,460,250,UNCLICKED,"6",0); // Box Of 6
    button(480,230,510,250,UNCLICKED,"*",0); // Box Of *
    button(515,230,545,250,UNCLICKED,"/",0); // Box Of /
    button(480,205,510,225,UNCLICKED,"AC",4); //Box Of AllClear (AC)
    button(515,205,545,225,UNCLICKED,"CE",4); //Box Of Clear (C)
    button(350,255,380,275,UNCLICKED,"1",0); // Box Of 1
    button(390,255,420,275,UNCLICKED,"2",0); // Box Of 2
    button(430,255,460,275,UNCLICKED,"3",0); // Box Of 3
    button(350,280,380,300,UNCLICKED,"0",0); // Box Of Zero (0)
    button(390,280,420,300,UNCLICKED,".",0); // Box Of Period (.)
    button(430,280,460,300,UNCLICKED,"pi",0); // Box Of Pi 
    button(480,255,510,275,UNCLICKED,"-",0); // Box Of -
    button(515,255,545,275,UNCLICKED,"+",0); // Box Of +
    button(350,305,460,325,UNCLICKED,"=",0); // Box Of Equality
    button(480,280,545,325,UNCLICKED,"shift",BLUE); // Box Of shift
    button(100,205,140,230,UNCLICKED,"sin",0); // Box Of Sin Function
    button(150,205,190,230,UNCLICKED,"cos",0); // Box Of CosFunction
    button(200,205,240,230,UNCLICKED,"tan",0); // Box Of Tan Function
    button(250,205,290,230,UNCLICKED,"fact",0); // Box Of Factorial Function
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    setcolor(RED);
    settextstyle(2,0,4);
    outtextxy(120,195,"sinh");
    outtextxy(170,195,"cosh");
    outtextxy(220,195,"tanh");
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    setcolor(RED);
    settextstyle(2,0,4);
    outtextxy(120,240,"sinh^-1");
    outtextxy(170,240,"cosh^-1");
    outtextxy(220,240,"tanh^-1");
    button(100,250,140,275,UNCLICKED,"sin^-1",0); // Box Of sin^-1
    button(150,250,190,275,UNCLICKED,"cos^-1",0); // Box Of cos^-1
    button(200,250,240,275,UNCLICKED,"tan^-1",0); // Box Of tan^-1
    button(250,250,290,275,UNCLICKED,"nPr",0); // Box Of permutation
    button(100,295,140,320,UNCLICKED,"ln",0); // Box Of ln
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    setcolor(RED);
    settextstyle(2,0,4);
    outtextxy(120,285,"e^x");
    outtextxy(170,285,"10^x");
    outtextxy(220,285,"x^3");
    button(150,295,190,320,UNCLICKED,"log",0); // Box Of log
    button(200,295,240,320,UNCLICKED,"xý",0); // Box Of x^2
    button(250,295,290,320,UNCLICKED,"nCr",0); // Box Of Combination
    setcolor(RED);
    outtextxy(120,330,"x^1/y");
    outtextxy(170,330,"x^1/3");
    outtextxy(220,330,"");
    button(100,340,140,365,UNCLICKED,"x^y",0); // Box Of x^y
    button(150,340,190,365,UNCLICKED,"ûx",0); // Box Of x^1/2
    button(200,340,240,365,UNCLICKED,"1/x",0); // Box Of 1/x
    button(100,165,140,185,UNCLICKED,"deg",15);
    button(150,165,190,185,UNCLICKED,"rad",0);
    button(200,165,240,185,UNCLICKED,"gra",0);
    button(480,350,545,370,UNCLICKED,"Off",4);
    button(350,350,380,370,UNCLICKED,"M+",0);
    button(390,350,420,370,UNCLICKED,"M-",0);
    button(430,350,460,370,UNCLICKED,"MR",0);
}







////////To get the input from calculator menu
char input()
{
    X=0;Y=0;
    char ch;
    show_mouse();
    do
    {
	mouse();
	if (X>=350 && X<=380 && Y>=205 && Y<=225) // Condition For 7
	{
	    hide_mouse();
	    button(350,205,380,225,CLICKED,"7",0);
	    show_mouse();  	    delay(250);
	    hide_mouse();
	    button(350,205,380,225,UNCLICKED,"7",0);
	    show_mouse();  	    ch='7';
	    return ch;
	}
       else  if (X>=390 && X<=420 && Y>=205 && Y<=225) // Condition For 8
	{
	    hide_mouse();
	    button(390,205,420,225,CLICKED,"8",0);
	    show_mouse();  	    delay(250);
	    hide_mouse();
	    button(390,205,420,225,UNCLICKED,"8",0);
	    show_mouse();           ch='8';
	    return ch;
	}
       else if (X>=430 && X<=460 && Y>=205 && Y<=225) // Condition For 9
	{
	    hide_mouse();
	    button(430,205,460,225,CLICKED,"9",0);
	    show_mouse();  	    delay(250);
	    hide_mouse();
	    button(430,205,460,225,UNCLICKED,"9",0);
	    show_mouse();  	    ch='9';
	    return ch;
	}
	else if (X>=350 && X<=380 && Y>=230 && Y<=250) // Condition For 4
	{
	    hide_mouse();
	    button(350,230,380,250,CLICKED,"4",0);
	    show_mouse();  	    delay(250);
	    hide_mouse();
	    button(350,230,380,250,UNCLICKED,"4",0);
	    show_mouse();  	    ch='4';
	    return ch;
	}
	else if (X>=390 && X<=420 && Y>=230 && Y<=250) // Condition For 5
	{
	    hide_mouse();
	    button(390,230,420,250,CLICKED,"5",0);
	    show_mouse();           delay(250);
	    hide_mouse();
	    button(390,230,420,250,UNCLICKED,"5",0);
	    show_mouse();  	    ch='5';
	    return ch;
	}
	else if (X>=430 && X<=460 && Y>=230 && Y<=250) // Condition For 6
	{
	    hide_mouse();
	    button(430,230,460,250,CLICKED,"6",0);
	    show_mouse();    	    delay(250);
	    hide_mouse();
	    button(430,230,460,250,UNCLICKED,"6",0);
	    show_mouse();           ch='6';
	    return ch;
	}
	else if (X>=480 && X<=510 && Y>=230 && Y<=250) // Condition For *
	{
	    hide_mouse();
	    button(480,230,510,250,CLICKED,"*",0);
	    show_mouse();          delay(250);
	    hide_mouse();
	    button(480,230,510,250,UNCLICKED,"*",0);
	    show_mouse();          ch='*';
	    return ch;
	}
	else if (X>=515 && X<=545 && Y>=230 && Y<=250) // Condition For /
	{
	    hide_mouse();
	    button(515,230,545,250,CLICKED,"/",0);
	    show_mouse();      	    delay(250);
	    hide_mouse();
	    button(515,230,545,250,UNCLICKED,"/",0);
	    show_mouse();      	    ch='/';
	    return ch;
	}
	else if (X>=350 && X<=380 && Y>=255 && Y<=275) // Condition For 1
	{
	    hide_mouse();
	    button(350,255,380,275,CLICKED,"1",0);
	    show_mouse();      	    delay(250);
	    hide_mouse();
	    button(350,255,380,275,UNCLICKED,"1",0);
	    show_mouse();      	    ch='1';
	    return ch;
	}
	else if (X>=390 && X<=420 && Y>=255 && Y<=275) // Condition For 2
	{
	    hide_mouse();
	    button(390,255,420,275,CLICKED,"2",0);
	    show_mouse();      	    delay(250);
	    hide_mouse();
	    button(390,255,420,275,UNCLICKED,"2",0);
	    show_mouse();      	    ch='2';
	    return ch;
	}
	else if (X>=430 && X<=460 && Y>=255 && Y<=275) // Condition For 3
	{
	    hide_mouse();
	    button(430,255,460,275,CLICKED,"3",0);
	    show_mouse();      	    delay(250);
	    hide_mouse();
	    button(430,255,460,275,UNCLICKED,"3",0);
	    show_mouse();      	    ch='3';
	    return ch;
	}
	else if (X>=350 && X<=380 && Y>=280 && Y<=300) // Condition For 0
	{
	    hide_mouse();
	    button(350,280,380,300,CLICKED,"0",0);
	    show_mouse();      	    delay(250);
	    hide_mouse();
	    button(350,280,380,300,UNCLICKED,"0",0);
	    show_mouse();      	    ch='0';
	    return ch;
	}
	else if (X>=390 && X<=420 && Y>=280 && Y<=300) // Condition For .
	{
	    hide_mouse();
	    button(390,280,420,300,CLICKED,".",0);
	    show_mouse();      	    delay(250);
	    hide_mouse();
	    button(390,280,420,300,UNCLICKED,".",0);
	    show_mouse();      	    ch='.';
	    return ch;
	}
	else if (X>=430 && X<=460 && Y>=280 && Y<=300) // Condition For pi
	{
	    hide_mouse();
	    button(430,280,460,300,CLICKED,"pi",0);
	    show_mouse();      	    delay(250);
	    hide_mouse();
	    button(430,280,460,300,UNCLICKED,"pi",0);
	    show_mouse();      	    ch='h';
	    return ch;
	}
	else if (X>=480 && X<=510 && Y>=255 && Y<=275) // Condition For -
	{
	    hide_mouse();
	    button(480,255,510,275,CLICKED,"-",0);
	    show_mouse();      	    delay(250);
	    hide_mouse();
	    button(480,255,510,275,UNCLICKED,"-",0);
	    show_mouse();      	    ch='-';
	    return ch;
	}
	else if (X>=515 && X<=545 && Y>=255 && Y<=275) // Condition For +
	{
	    hide_mouse();
	    button(515,255,545,275,CLICKED,"+",0);
	    show_mouse();      	    delay(250);
	    hide_mouse();
	    button(515,255,545,275,UNCLICKED,"+",0);
	    show_mouse();      	    ch='+';
	    return ch;
	}
       else if (X>=350 && X<=460 && Y>=305 && Y<=325) // Condition For =
	{
	    hide_mouse();
	    button(350,305,460,325,CLICKED,"=",0);
	    show_mouse();                  delay(250);
	    hide_mouse();
	    button(350,305,460,325,UNCLICKED,"=",0);
	    show_mouse();      	    ch='=';
	    return ch;
	}
	else if (X>=480 && X<=510 && Y>=205 && Y<=225) // Condition For AC
	{
	    hide_mouse();
	    button(480,205,510,225,CLICKED,"AC",4);
	    show_mouse();      	    delay(250);
	    hide_mouse();
	    button(480,205,510,225,UNCLICKED,"AC",4);
	    show_mouse();      	    ch='o';
	    return ch;
	}
	else if (X>=515 && X<=545 && Y>=205 && Y<=225) // Condition For C
	{
	    hide_mouse();
	    button(515,205,545,225,CLICKED,"CE",4);
	    show_mouse();           delay(250);
	    hide_mouse();
	    button(515,205,545,225,UNCLICKED,"CE",4);
	    show_mouse();      	    ch='a';
	    return ch;
	}
	else if (X>=100 && X<=140 && Y>=205 && Y<=230) // Condition For Sin
	{
	    hide_mouse();
	    button(100,205,140,230,CLICKED,"Sin",0);
	    show_mouse();           delay(250);
	    hide_mouse();
	    button(100,205,140,230,UNCLICKED,"Sin",0);
	    show_mouse();  	    ch='s';
	    return ch;
	}
	else if (X>=150 && X<=190 && Y>=205 && Y<=230) // Condition For Cos
	{
	    hide_mouse();
	    button(150,205,190,230,CLICKED,"Cos",0);
	    show_mouse();           delay(250);
	    hide_mouse();
	    button(150,205,190,230,UNCLICKED,"Cos",0);
	    show_mouse();  	    ch='c';
	    return ch;
	}
	else if (X>=200 && X<=240 && Y>=205 && Y<=230) // Condition For Tan
	{
	    hide_mouse();
	    button(200,205,240,230,CLICKED,"Tan",0);
	    show_mouse();           delay(250);
	    hide_mouse();
	    button(200,205,240,230,UNCLICKED,"Tan",0);
	    show_mouse();           ch='t';
	    return ch;
	}
	else if (X>=100 && X<=140 && Y>=250 && Y<=275) // Condition For sin^-1
	{
	    hide_mouse();
	    button(100,250,140,275,CLICKED,"sin^-1",0);
	    show_mouse();           delay(150);
	    hide_mouse();
	    button(100,250,140,275,UNCLICKED,"sin^-1",0);
	    show_mouse();           ch='i';
	    return ch;
	}
	else if (X>=150 && X<=190 && Y>=250 && Y<=275) // Condition For cos^-1
	{
	    hide_mouse();
	    button(150,250,190,275,CLICKED,"cos^-1",0);
	    show_mouse();         	    delay(250);
	    hide_mouse();
	    button(150,250,190,275,UNCLICKED,"cos^-1",0);
	    show_mouse();         	    ch='j';
	    return ch;
	}
	else if (X>=430 && X<=460 && Y>=350 && Y<=370) // Condition For MR
	{
	    hide_mouse();
	    button(430,350,460,370,CLICKED,"MR",0);
	    show_mouse();         	    delay(250);
	    hide_mouse();
	    button(430,350,460,370,UNCLICKED,"MR",0);
	    show_mouse();         	    ch='?';
	    return ch;
	}
	else if (X>=390 && X<=420 && Y>=350 && Y<=370) // Condition For M-
	{
	    hide_mouse();
	    button(390,350,420,370,CLICKED,"M-",0);
	    show_mouse();           delay(250);
	    hide_mouse();
	    button(390,350,420,370,UNCLICKED,"M-",0);
	    show_mouse();     	    ch='<';
	    return ch;
	}
	else if (X>=350 && X<=380 && Y>=350 && Y<=370) // Condition For M+
	{
	    hide_mouse();
	    button(350,350,380,370,CLICKED,"M+",0);
	    show_mouse(); 	    delay(250);
	    hide_mouse();
	    button(350,350,380,370,UNCLICKED,"M+",0);
	    show_mouse(); 	    ch='>';
	    return ch;
	}
	else if (X>=200 && X<=240 && Y>=250 && Y<=275) // Condition For tan^-1
	{
	    hide_mouse();
	    button(200,250,240,275,CLICKED,"tan^-1",0);
	    show_mouse();             delay(250);
	    hide_mouse();
	    button(200,250,240,275,UNCLICKED,"tan^-1",0);
	    show_mouse();             ch='k';
	    return ch;
	}
	else if (X>=100 && X<=140 && Y>=295 && Y<=320) // Condition For ln
	{
	    hide_mouse();
	    button(100,295,140,320,CLICKED,"ln",0);
	    show_mouse();             delay(250);
	    hide_mouse();
	    button(100,295,140,320,UNCLICKED,"ln",0);
	    show_mouse();             ch='n';
	    return ch;
	}
	else if (X>=150 && X<=190 && Y>=295 && Y<=320) // Condition For log
	{
	    hide_mouse();
	    button(150,295,190,320,CLICKED,"log",0);
	    show_mouse();              delay(150);
	    hide_mouse();
	    button(150,295,190,320,UNCLICKED,"log",0);
	    show_mouse();              ch='l';
	    return ch;
	}
	else if (X>=200 && X<=240 && Y>=295 && Y<=320) // Condition For X^2
	{
	    hide_mouse();
	    button(200,295,240,320,CLICKED,"x^2",0);
	    show_mouse();              delay(250);
	    hide_mouse();
	    button(200,295,240,320,UNCLICKED,"x^2",0);
	    show_mouse();              ch='p';
	    return ch;
	}
	else if (X>=250 && X<=290 && Y>=295 && Y<=320) // Condition For nCr
	{
	    hide_mouse();
	    button(250,295,290,320,CLICKED,"nCr",0);
	    show_mouse();              delay(250);
	    hide_mouse();
	    button(250,295,290,320,UNCLICKED,"nCr",0);
	    show_mouse();              ch='C';
	    return ch;
	}
	else if (X>=250 && X<=290 && Y>=250 && Y<=275) // Condition For nPr
	{
	    hide_mouse();
	    button(250,250,290,275,CLICKED,"nPr",0);
	    show_mouse();              delay(250);
	    hide_mouse();
	    button(250,250,290,275,UNCLICKED,"nPr",0);
	    show_mouse();              ch='P';
	    return ch;
	}
	else if (X>=100 && X<=140 && Y>=340 && Y<=365) // Condition For x^y
	{
	    hide_mouse();
	    button(100,340,140,365,CLICKED,"x^y",0);
	    show_mouse();              delay(250);
	    hide_mouse();
	    button(100,340,140,365,UNCLICKED,"x^y",0);
	    show_mouse();              ch='^';
	    return ch;
	}
	else if (X>=150 && X<=190 && Y>=340 && Y<=365) // Condition For x^1/2
	{
	    hide_mouse();
	    button(150,340,190,365,CLICKED,"ûx",0);
	    show_mouse();              delay(250);
	    hide_mouse();
	    button(150,340,190,365,UNCLICKED,"ûx",0);
	    show_mouse();              ch='q';
	    return ch;
	}
	else if (X>=200 && X<=240 && Y>=340 && Y<=365) // Condition For 1/x
	{
	    hide_mouse();
	    button(200,340,240,365,CLICKED,"1/x",0);
	    show_mouse();              delay(250);
	    hide_mouse();
	    button(200,340,240,365,UNCLICKED,"1/x",0);
	    show_mouse();              ch='m';
	    return ch;
	}
	else if (X>=100 && X<=140 && Y>=165 && Y<=185) // Condition For deg
	{
	    hide_mouse();
	    button(100,165,140,185,CLICKED,"deg",15);
	    button(150,165,190,185,UNCLICKED,"rad",0);
	    button(200,165,240,185,UNCLICKED,"gra",0);
	    show_mouse();   	    delay(250);
	    hide_mouse();
	    button(100,165,140,185,UNCLICKED,"deg",15);
	    show_mouse();   	    ch='d';
	    flagp=flag;             flag=ch;
	    return ch;
	}
	else if (X>=150 && X<=190 && Y>=165 && Y<=185) // Condition For rad
	{
	    hide_mouse();
	    button(100,165,140,185,UNCLICKED,"deg",0);
	    button(150,165,190,185,CLICKED,"rad",15);
	    button(200,165,240,185,UNCLICKED,"gra",0);
	    show_mouse();  	    delay(250);
	    hide_mouse();
	    button(150,165,190,185,UNCLICKED,"rad",15);
	    show_mouse();   	    ch='r';
	    flagp=flag; 	    flag=ch;
	    return ch;
	}
	else if (X>=200 && X<=240 && Y>=165 && Y<=185) // Condition For gra
	{
	    hide_mouse();
	    button(100,165,140,185,UNCLICKED,"deg",0);
	    button(150,165,190,185,UNCLICKED,"rad",0);
	    button(200,165,240,185,CLICKED,"gra",15);
	    show_mouse();    	    delay(250);
	    hide_mouse();
	    button(200,165,240,185,UNCLICKED,"gra",15);
	    show_mouse();           ch='g';
	    flagp=flag;        	    flag=ch;
	    return ch;
	}
	else if ((X>=480 && X<=545 &&Y>=350 &&Y <=370)||(X>=575&&X<=595&&Y>=23&&Y<=40)) //OFF
	{
	   // end();
	    free(mem);
	    exit(0);
	}
	else if(X>=480&&X<=545&&Y>=280&&Y<=325) //shift
	{
	    hide_mouse();
	    button(480,280,545,325,CLICKED,"shift",1);
	    show_mouse();      	    delay(250);
	    hide_mouse();
	    button(480,280,545,325,UNCLICKED,"shift",0);
	    show_mouse();           ch='~';
	    sflag=1;
	    return ch;
	}
	else if (X>=250 && X<=290 && Y>=205 && Y<=230) // Condition For Factorial
	{
	    hide_mouse();
	    button(250,205,290,230,CLICKED,"fact",0);
	    show_mouse();          delay(250);
	    hide_mouse();
	    button(250,205,290,230,UNCLICKED,"fact",0);
	    show_mouse();          ch='!';
	    return ch;
	}
	else if(X>=183&&X<=314&&Y>=22&&Y<=42)
	{
	    hide_mouse();
	    button(183,22,314,42,CLICKED,"MATRICES",b); // TAB 2
	    show_mouse();  	    delay(250);
	    hide_mouse(); //alt+ 798
	    button(183,22,314,42,UNCLICKED,"MATRICES",b); // TAB 2
	    show_mouse();  	    ch=' ';
	    return ch;
	}
	else if(X>=183&&X<=314&&Y>=22&&Y<=42)
	{
	    hide_mouse();
	    button(52,22,183,42,CLICKED,"SCIENTIFIC CALC",a); // TAB 1
	    show_mouse();  	    delay(250);
	    hide_mouse(); //alt+ 989 Ã 
	    button(52,22,183,42,UNCLICKED,"SCIENTIFIC CALC",a); // TAB 1
	    show_mouse();           ch='Ý';
	    return ch;
	}
else if(X>=314&&X<=445&&Y>=22&&Y<=42)
	{
	    hide_mouse();


	    button(314,22,445,42,CLICKED,"GRAPHING",c);  // TAB 3
	    show_mouse();  	    delay(250);
	    hide_mouse(); //alt+ 798

	    button(314,22,445,42,UNCLICKED,"GRAPHING",c);  // TAB 3

	    show_mouse();  	    ch=' ';//change ch
	    return ch;
	}
    }
    while(kbhit() == 0);
    ch=getch();
    return ch;
}



char minput()
{
    X=0;Y=0;
    int ch;
    show_mouse();
    do
    {
	mouse();

	if(X>=52&&X<=183&&Y>=22&&Y<=42)
	{
	    hide_mouse();
	    button(52,22,183,42,CLICKED,"SCIENTIFIC CALC",15); // TAB 1
	    show_mouse();	delay(250);
	    hide_mouse(); //alt+ 989 Ã 
	    button(52,22,183,42,UNCLICKED,"SCIENTIFIC CALC",15); // TAB 1
	    show_mouse(); 	ch='Ý';
	    return ch;
	}
	else if (X>=575&&X<=595&&Y>=23&&Y<=40) //OFF
	{
	  //  end();
	    free(mem);
	    exit(0);
	}
	else if(X>=100&&X<=190&&Y>=240&&Y<=305)
	{
	    hide_mouse();
	    button(100,240,190,305,CLICKED,"MINOR",0); // Box for minor mat
	    show_mouse();	delay(250);
	    hide_mouse();
	    button(100,240,190,305,UNCLICKED,"MINOR",0); // Box for minor mat
	    show_mouse();	ch='1';
	    return ch;
	}
	else if(X>=100&&X<=190&&Y>=165&&Y<=230)
	{
	    hide_mouse();
	    button(100,165,190,230,CLICKED,"MATRIX PRODUCT",0); // Box for matrix prod
	    show_mouse();	delay(250);
	    hide_mouse();
	    button(100,165,190,230,UNCLICKED,"MATRIX PRODUCT",0); // Box for matrix prod
	    show_mouse();	ch='4';
	    return ch;
	}
	else if(X>=100&&X<=190&&Y>=90&&Y<=155)
	{
	    hide_mouse();
	    button(100,90,190,155,CLICKED,"EDIT MATRIX",0); // Box to edit the entered matrix
	    show_mouse();	delay(250);
	    hide_mouse(); //alt ÃŸ 223
	    button(100,90,190,155,UNCLICKED,"EDIT MATRIX",0); // Box to edit the entered matrix
	    show_mouse();  	ch='ß';
	    return ch;
	}
	else if(X>=200&&X<=290&&Y>=165&&Y<=230)
	{
	    hide_mouse();
	    button(200,165,290,230,CLICKED,"INVERSE",0); // Box for inverse of a matrix
	    show_mouse();       delay(250);
	    hide_mouse();
	    button(200,165,290,230,UNCLICKED,"INVERSE",0); // Box for inverse of a matrix
	    show_mouse();       ch='3';
	    return ch;
	}
	else if(X>=350&&X<=440&&Y>=165&&Y<=230)
	{
	    hide_mouse();
	    button(350,165,440,230,CLICKED,"DETERMINANT",0); // Box for Determinant
	    show_mouse();       delay(250);
	    hide_mouse();
	    button(350,165,440,230,UNCLICKED,"DETERMINANT",0); // Box for Determinant
	    show_mouse();       ch='2';
	    return ch;
	}
	else if(X>=450&&X<=540&&Y>=165&&Y<=230)
	{
	    hide_mouse();
	    button(450,165,540,230,CLICKED,"ADJOINT",0); // Box for Adjoint matrix
	    show_mouse();       delay(250);
	    hide_mouse();
	    button(450,165,540,230,UNCLICKED,"ADJOINT",0); // Box for Adjoint matrix
	    show_mouse();       ch='5';
	    return ch;
	}
	else if(X>=200&&X<=290&&Y>=240&&Y<=305)
	{
	    hide_mouse();
	    button(200,240,290,305,CLICKED,"CO-FACTOR",0); // Box for cofactor matrix
	    show_mouse();       delay(250);
	    hide_mouse();
	    button(200,240,290,305,UNCLICKED,"CO-FACTOR",0); // Box for cofactor matrix
	    show_mouse();       ch='6';
	    return ch;
	}
	else if(X>=100&&X<=190&&Y>=315&&Y<=380)
	{
	    hide_mouse();
	    button(100,315,190,380,CLICKED,"TRANSPOSE",0); // Box for transpose
	    show_mouse();       delay(250);
	    hide_mouse();
	    button(100,315,190,380,UNCLICKED,"TRANSPOSE",0); // Box for transpose
	    show_mouse();   	ch='7';
	    return ch;
	}
		else if(X>=200&&X<=290&&Y>=315&&Y<=380)
	{
	    hide_mouse();
	    button(200,315,290,380,CLICKED,"TRACE",0); // Box for trace
	    show_mouse();         delay(250);
	    hide_mouse();
	    button(200,315,290,380,UNCLICKED,"TRACE",0); // Box for trace
	    show_mouse();         ch='A';
	    return ch;
	}


	// Element operations
	else if(X>=350&&X<=440&&Y>=240&&Y<=305)
	{
	    hide_mouse();
	    button(350,240,440,305,CLICKED,"DOT +",0); // Box Of .+
	    show_mouse();       delay(250);
	    hide_mouse(); //alt+ 666 Å¡
	    button(350,240,440,305,UNCLICKED,"DOT +",0); // Box Of .+
	    show_mouse();       ch='š';
	    return ch;
	}
	else if(X>=450&&X<=540&&Y>=240&&Y<=305)
	{
	    hide_mouse();
	    button(450,240,540,305,CLICKED,"DOT -",0); // Box Of .-
	    show_mouse();       delay(250);
	    hide_mouse(); //alt+ 667  â€º
	    button(450,240,540,305,UNCLICKED,"DOT -",0); // Box Of .-
	    show_mouse();  	ch='›';
	    return ch;
	}
	else if(X>=450&&X<=540&&Y>=315&&Y<=380)
	{
	    hide_mouse();
	    button(450,315,540,380,UNCLICKED,"DOT /",0); // Box Of ./
	    show_mouse();        delay(250);
	    hide_mouse(); //alt+ 662  â€“
	    button(450,315,540,380,UNCLICKED,"DOT /",0); // Box Of ./
	    show_mouse();         ch='–';
	    return ch;
	}
	else if(X>=350&&X<=440&&Y>=315&&Y<=380)
	{
	    hide_mouse();
	    button(350,315,440,380,CLICKED,"DOT x",0); // Box Of .x
	    show_mouse();         delay(250);
	    hide_mouse(); //alt+ 668  Å“
	    button(350,315,440,380,UNCLICKED,"DOT x",0); // Box Of .x
	    show_mouse();         ch='œ';
	    return ch;
	}
	else if(X>=314&&X<=445&&Y>=22&&Y<=42)
	{
	    hide_mouse();


	    button(314,22,445,42,CLICKED,"GRAPHING",c);  // TAB 3
	    show_mouse();  	    delay(250);
	    hide_mouse(); //alt+ 798

	    button(314,22,445,42,UNCLICKED,"GRAPHING",c);  // TAB 3

	    show_mouse();  	    ch=' ';//change ch
	    return ch;
	}

    }
    while(kbhit() == 0);// while no key has been pressed
    ch=getch();
    return ch;
}
char ginput()
{
  X=0;Y=0;
    int ch;
    show_mouse();
    do
    {
	mouse();

	if(X>=52&&X<=183&&Y>=22&&Y<=42)
	{
	    hide_mouse();
	    button(52,22,183,42,CLICKED,"SCIENTIFIC CALC",15); // TAB 1
	    show_mouse();	delay(250);
	    hide_mouse(); //alt+ 989 Ã 
	    button(52,22,183,42,UNCLICKED,"SCIENTIFIC CALC",15); // TAB 1
	    show_mouse(); 	ch='Ý';
	    return ch;
	}
	else if (X>=575&&X<=595&&Y>=23&&Y<=40) //OFF
	{
	    //end();
	    free(mem);
	    exit(0);
	}

        else if(X>=100&&X<=290&&Y>=90&&Y<=155)
	{
	    hide_mouse();
            button(100,90,290,155,CLICKED,"LINEAR EQUATIONS",0);
	    show_mouse();	delay(250);
	    hide_mouse(); 
            button(100,90,290,155,UNCLICKED,"LINEAR EQUATIONS",0);
	    
	    show_mouse(); 	ch='1';
	    return ch;
	}

        else if(X>=100&&X<=290&&Y>=165&&Y<=230)
	{
	    hide_mouse();
            button(100,165,290,230,CLICKED,"QUADRATIC EQUATIONS",0); // Box Of quad
	   
	    show_mouse();	delay(250);
	    hide_mouse(); 
            button(100,165,290,230,UNCLICKED,"QUADRATIC EQUATIONS",0); // Box Of quad
	
	    show_mouse(); 	ch='2';
	    return ch;
	}

          else if(X>=100&&X<=290&&Y>=240&&Y<=305)
	{
	    hide_mouse();
            button(100,240,290,305,CLICKED,"CIRCLE",0); // Box Of Circle
            
	    show_mouse();	delay(250);
	    hide_mouse(); 
           button(100,240,290,305,UNCLICKED,"CIRCLE",0); // Box Of Circle
	    
	    show_mouse(); 	ch='3';
	    return ch;
	}

          else if(X>=100&&X<=290&&Y>=315&&Y<=380)
	{
	    hide_mouse();
           button(100,315,290,380,UNCLICKED,"PARABOLA",0); // Box Of para
            
	    show_mouse();	delay(250);
	    hide_mouse(); 
           button(100,315,290,380,UNCLICKED,"PARABOLA",0); // Box Of para
	    
	    show_mouse(); 	ch='4';
	    return ch;
	}

        else if(X>=350&&X<=540&&Y>=165&&Y<=230)
	{
	    hide_mouse();
            button(350,165,540,230,CLICKED,"ELLIPSE",0); // Box Of Ellipse   
	    show_mouse();	delay(250);
	    hide_mouse(); 
            button(350,165,540,230,UNCLICKED,"ELLIPSE",0); // Box Of Ellipse
	    show_mouse(); 	ch='5';
	    return ch;
	}


           else if(X>=350&&X<=540&&Y>=240&&Y<=305)
	{
	    hide_mouse(); 
            button(350,240,540,305,CLICKED,"HYPERBOLA",0); // Box Of hyp            
	    show_mouse();	delay(250);
	    hide_mouse(); 
            button(350,240,540,305,UNCLICKED,"HYPERBOLA",0); // Box Of hyp
	    show_mouse(); 	ch='6';
	    return ch;
	}

        else if(X>=350&&X<=540&&Y>=315&&Y<=380)
	{
	    hide_mouse();
            button(350,315,540,380,CLICKED,"GENERAL CONIC",0); // Box Of gen con  
	    show_mouse();	delay(250);
	    hide_mouse(); 
           button(350,315,540,380,UNCLICKED,"GENERAL CONIC",0); // Box Of gen con
	    show_mouse(); 	ch='7';
	    return ch;
	}

		else if(X>=183&&X<=314&&Y>=22&&Y<=42)
	{
	    hide_mouse();


	      button(183,22,314,42,CLICKED,"MATRICES",b); // TAB 2
	    show_mouse();  	    delay(250);
	    hide_mouse(); 

	      button(183,22,314,42,UNCLICKED,"MATRICES",b); // TAB 2

	    show_mouse();  	    ch=' ';//change ch
	    return ch;
	}

    }
    while(kbhit() == 0);// while no key has been pressed
    ch=getch();
    return ch;
 }
