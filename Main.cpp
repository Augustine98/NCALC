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
int  f ,a,b,c,d;
int scrx=34,scry=7,locx,locy;
float *mem;
int X=0, Y=0 ,row=17,col=5;
char dummy;
char flag='d',flagp='0',bflagp='u';
int mflag=0;
char ch,ch1,ch2,tch;
int sflag=0;
double matr[4][4];
void main();
char ginput();
# define UNCLICKED 0
# define CLICKED 1
# define PI 3.14159
int sig=2;//significant digits
struct graphing
{
private:
 int ch; float a,b,c,d,e,f,h,k,C;    /* significant digits */
 int i;  float y,x;  int t1,t2;
  int val,pos;
 char ans[15],str[10];
public:

void analyze();
void circlea(char);
void parabola(char);
void ellipsea(char);
void hyperbola(char);
void graph(int i,float d);
void creategraph();
void mainloop(char);
void horzpara();
void generalconic();
void nshyper();
void ewhyper();
void centre();
void vertex();
void focus();
void disp();
}g;

void graphing::creategraph()
{ setbkcolor(15);
  setcolor(8);
  line(320,0,320,480);
  line(0,240,640,240);
  for(int j=-7;j<7;j++)           // To plot the scale in x axis
  {
     val=320-(j*57.307);
     line(val,235,val,245);
   }

    for(j=-3;j<5;j++)              // To plot the scale in y axis
  {
     val=240-(j*57.307);
     line(315,val,325,val);
   }

 }
void graphing::generalconic()
{
 float rat,x,y;int val,pos,col=12;
    f=-1*f;
   setlinestyle(0,1,4);
  for(int i=-320;i<320;i++)
  {
  x=i*0.01745;
   for(int l=-320;l<320;l++)
   {

    y=l*0.01745;
			       //rat is equal to LHS divided by RHS
  rat=((a*x*x)+(b*x*y)+(c*y*y)+(d*x)+(e*y))/f;
    if(rat>=0.9&&rat<=1.1)
   {
      y=l*0.01745;

      val=y*57.307;

     if(y>=0)
	val=240-val;                   // To plot values above x axis
     else if(y<0)
	val=(-1*val)+240;              // To plot values below x axis

     pos=i+320;
     putpixel(pos,val,col);

    }

    }
    }

}

void graphing::horzpara()
{
 for( i=-320;i<320;i++)   // + ve loop
    {
      x=i*0.01745;x=(x-h)/(4*a);
      if(x>=0)
      {
      y=k+sqrt(x);        // +ve y
      graph(i,y);
       y=k-sqrt(x);       // -ve y
      graph(i,y);
	}
    } //end of for loop
 }
void graphing::nshyper()
{
 for( i=-320;i<320;i++)   // +ve y  loop
      { x=i*0.01745; x=(x-h)/b;
       y=k+abs(a)*sqrt(1+(x*x));
       graph(i,y);                        // y-k/a =1+(x-h)/a

    } //end of for loop
    for( i=-320;i<320;i++)   // -ve y loop
    {
      x=i*0.01745;x=(x-h)/b;
      y=k-abs(a)*sqrt(1+(x*x));
      graph(i,y);
    }
 }
void graphing::ewhyper()
{

 for( i=-320;i<320;i++)   // 2nd quad  loop
    {
     x=i*0.01745; x=(x-h)/a;
     if(x>=1||x<=-1)
     {  y=k+abs(b)*sqrt((x*x)-1);
      graph(i,y);
     }
    } //end of for loop
    for( i=-320;i<320;i++)   // 3rd quad loop
    {
      x=i*0.01745;x=(x-h)/a;
      if(x>=1||x<=-1)
    {  y=k-abs(b)*sqrt((x*x)-1);
      graph(i,y);    }

    } //end of for loop
 }
void graphing::centre()
{
	    strcpy(ans,"(");
	    gcvt(h, sig, str);
	    strcat(ans,str);
	    strcat(ans,",");
	    gcvt(k, sig, str);
	    strcat(ans,str);
	    strcat(ans,") ");
 }
 void graphing::vertex()
 {  float t1=h,t2=k;
    for(int i=0;i<2;i++)
       {
	    if(i==0)
	   {
	    if(ch==5)
	      {    if(a>b)
			h=t1+a;
		else
			k=t2+b;
	      }
	    else
	     {    if(C==1)
			h=t1+a;
		   else
			k=t2+a;

	      }

	   }
	   else
	   {
	    if(ch==5) {     if(a>b)
			h=t1-a;
		   else
			k=t2-b;}

	    else
	    { if(C==1)
		 h=t1-a;
	      else
		 k=t2-a;
		}
	    }
	    strcpy(ans,"(");
	    gcvt(h, sig, str);
	    strcat(ans,str);
	    strcat(ans,",");
	    gcvt(k, sig, str);
	    strcat(ans,str);
	    strcat(ans,") ");
	    outtextxy(25,45+i*15 ,ans);
	  }


    h=t1;k=t2;
  }
 void graphing::focus()
 {
 float c;
 float t1=h,t2=k;
    if(ch==4)
    { if(C==1)
	k=k+a;
       else
	 h=h+a;

	    strcpy(ans,"(");
	    gcvt(h, sig, str);
	    strcat(ans,str);
	    strcat(ans,",");
	    gcvt(k, sig, str);
	    strcat(ans,str);
	    strcat(ans,") ");
    }
    else if(ch==5||ch==6)
    {
    if(ch==5)
   {   if(a>b)
	 c=sqrt(a*a-b*b);
     else if(b>a)
	 c=sqrt(b*b-a*a);
    }
    else if (ch==6)
    {
	 c=sqrt(a*a+b*b);
    }
       for(int i=0;i<2;i++)
       {
	    if(i==0)      //to display the first set of foci
	   {
	     if(ch==5)       // case of ellipse
	     {
	      if(a>b)
		h=t1+c;
	      else
		k=t2+c;
	     }
	     else         //case of hyperbola
	     {
	      if(C==1)     //east-west hyperbola
		h=t1+c;
	      else         //north south hyperbola
		k=t2+c;
	     }
	   }


	   else              // Second set of foci
	   {
	     if(ch==5)      // case of ellipse
	     {
	       if(a>b)
		   h=t1-c;
	       else
		   k=t2-c;
	     }

	     else
	     {
	       if(C==1)
			h=t1-c;
	       else
			k=t2-c;
	      }
	  } // end of second set

	    strcpy(ans,"(");
	    gcvt(h, sig, str);
	    strcat(ans,str);
	    strcat(ans,",");
	    gcvt(k, sig, str);
	    strcat(ans,str);
	    strcat(ans,") ");
	    outtextxy(25,45+i*15 ,ans);
	  }

    }





     h=t1;k=t2;
  }

void graphing::disp()
{
 char op;
 setfillstyle(1,1);
 setcolor(0);
 bar(20,20,175,60);
 outtextxy(25,30," A- Analyze Curve");
 outtextxy(25,45," B- Graphing menu");
 op=getch();
 if(op=='a'||op=='A')
    analyze();
 else if( op=='b'||op=='B')
 {  cleardevice();  closegraph();
    mainloop(op);      }
 }
void graphing::circlea(char t)
{
 setfillstyle(1,1);
 setcolor(0);
 bar(20,20,175,200);
 t=toupper(t);float c;
 strcpy(ans," ");
 switch(t)
 {
  case 'A':    outtextxy(25,30," Centre ");
	      centre();
	      outtextxy(25,45,ans);
	      getch();
	      break;

  case 'B': outtextxy(25,30," Radius ");
	    gcvt(a, sig, str);
	    strcat(ans,str);
	    strcat(ans," u");

	     outtextxy(25,45,ans);
	     getch();
	     break;

  case 'C' :  c=((h*h)+(k*k)-(a*a));
	      c=2*sqrt((h*h)-c);
	    outtextxy(25,30," x-intercept ");
	    gcvt(c, sig, str);
	    strcat(ans,str);
	    strcat(ans," u");

	     outtextxy(25,45,ans);
	     getch();
	     break;
    case 'D' :  c=((h*h)+(k*k)-(a*a));
	      c=2*sqrt((k*k)-c);
	       outtextxy(25,30," y-intercept ");
	       gcvt(c, sig, str);
	       strcat(ans,str);
	      strcat(ans," u");

	     outtextxy(25,45,ans);
	     getch();
	     break;

   case 'E' : outtextxy(25,30," Eccentricity  0");
	      break;

   case 'F' : disp();

  }
  getch();
  analyze();
 }
 void graphing::parabola(char t)
 {
   setfillstyle(1,1);
 setcolor(0);
 bar(20,20,175,200);
 t=toupper(t);float c;
 strcpy(ans," ");
 switch(t)
 {
  case 'A':  outtextxy(25,30," Focus ");
	       focus();
	       outtextxy(25,45,ans);
	      getch();
	      break;

  case 'B':  outtextxy(25,30," Vertex ");
	       centre();
	      outtextxy(25,45,ans);
	     getch();
	     break;


  case 'C' :
	    outtextxy(25,30," Directrix ");
	    if(C==1)
	       strcpy(ans," y=");
	    else if(C==2)
		strcpy(ans," x=");
	    gcvt(-1*a, sig, str);
	    strcat(ans,str);
	     outtextxy(25,45,ans);
	     getch();
	     break;

    case 'D' :  c=abs(4*a);
		outtextxy(25,30," Latus rectum ");
		gcvt(c, sig, str);
		strcat(ans,str);
		strcat(ans," u");

		outtextxy(25,45,ans);
		getch();
		break;

   case 'E' : outtextxy(25,30," Eccentricity  1");
	      break;


   case 'F' : outtextxy(25,30," Axis of Sym.");
	      if(C==1)
	      { strcpy(ans," x="); c=h;  }
	      else if(C==2)
	       { strcpy(ans," y="); c=k;}
	      gcvt(c,sig,str);
	      strcat(ans,str);
	      outtextxy(25,45,ans);
		getch();
		break;


   case 'G' : disp();

  }
  getch();
  analyze();

  }
  void graphing::ellipsea(char t)
  {
    float g;
    g=sqrt(abs(a*a-b*b));
   setfillstyle(1,1);
 setcolor(0);
 bar(20,20,175,200);
 t=toupper(t);float c;
 strcpy(ans,"");
 switch(t)
 {
  case 'A':    outtextxy(25,30," Focus ");
	       focus();
	       getch();
	       break;

  case 'B':    outtextxy(25,30," Vertex ");
	       vertex();
	       getch();
	       break;


  case 'C' :
	    outtextxy(25,30," Directrix ");
	    if(a>b)
	      { strcpy(ans," x= ");
		gcvt(h,sig,str);strcat(ans,str);strcat(ans," ñ ");
	      gcvt((a*a)/g,sig,str);
	      }
	    else if(b>a)
	      {	strcpy(ans," y= ");
		gcvt(k,sig,str);strcat(ans,str);strcat(ans," ñ ");
	      gcvt((b*b)/g, sig, str);
	      }
	    strcat(ans,str);
	     outtextxy(25,45,ans);
	     getch();
	     break;

    case 'D' :   if(a>b)
		    c=2*b*b/(a);
		 else
		   c=2*a*a/(b);
		outtextxy(25,30," Latus rectum ");
		gcvt(c, sig, str);
		strcat(ans,str);
		strcat(ans," u");

		outtextxy(25,45,ans);
		getch();
		break;


   case 'E' : if(a>b)
	       g=g/a;
	       else
	       g=g/b;
	      strcpy(ans," Eccentricity ");
	      gcvt(g,sig,str);
	      strcat(ans,str);
	      outtextxy(25,30,ans);
	      break;

    case 'F' :    outtextxy(25,30," Centre ");
		centre();
		outtextxy(25,45,ans);
		getch();
		break;

   case 'G' :
	       outtextxy(25,30,"Major axis");
		if(a>b)
		       gcvt(2*a, sig, str);
		else
		       gcvt(2*b,sig,str);
		strcat(ans,str);
		strcat(ans," u");
		outtextxy(25,45,ans);
		outtextxy(25,60,"Minor axis");
		strcpy(ans,"");
		if(a>b)
		     gcvt(2*b, sig, str);
		else
		      gcvt(2*a,sig,str);

		strcat(ans,str);
		strcat(ans," u");
		outtextxy(25,75,ans);
		getch();
		 break;


   case 'H' : disp();

  }
  getch();
  analyze();
  }
 void graphing::hyperbola(char t)
  {
    float g;
    g=sqrt(abs(a*a+b*b));
   setfillstyle(1,1);
 setcolor(0);
 bar(20,20,175,200);
 t=toupper(t);float c;
 strcpy(ans,"");
 switch(t)
 {
  case 'A':    outtextxy(25,30," Focus ");
	       focus();
	       getch();
	       break;

  case 'B':    outtextxy(25,30," Vertex ");
	       vertex();
	       getch();
	       break;


  case 'C' :
	    outtextxy(25,30," Directrix ");
	    if(C==1)
	      { strcpy(ans," x=");
		gcvt(h,sig,str);
		}
	    else if(C==2)
	      {	strcpy(ans," y=");
		gcvt(k,sig,str);
		}
	      strcat(str,"ñ");strcat(ans,str);
	      gcvt((a*a)/g, sig, str);
	    strcat(ans,str);
	     outtextxy(25,45,ans);
	     getch();
	     break;

    case 'D' :
			c=2*b*b/(a);

		outtextxy(25,30," Latus rectum ");
		gcvt(c, sig, str);
		strcat(ans,str);
		strcat(ans," u");

		outtextxy(25,45,ans);
		getch();
		break;


   case 'E' :
	       g=g/a;
	      strcpy(ans," Eccentricity ");
	      gcvt(g,sig,str);
	      strcat(ans,str);
	      outtextxy(25,30,ans);
	      break;

    case 'F' :    outtextxy(25,30," Centre ");
		centre();
		outtextxy(25,45,ans);
		getch();
		break;

   case 'G' :
	       outtextxy(25,30," Transverse axis");
		       gcvt(2*a, sig, str);
		strcat(ans,str);
		strcat(ans," u");
		outtextxy(25,45,ans);
		outtextxy(25,60," Conjugate axis");
		strcpy(ans,"");
		     gcvt(2*b, sig, str);

		strcat(ans,str);
		strcat(ans," u");
		outtextxy(25,75,ans);
		getch();
		 break;

  case 'H' :  outtextxy(25,30," Asymptotes");
		strcpy(ans," y= ");
		if(k!=0)
		{
		gcvt(k,sig,str);
		strcat(ans,str);
		}
		strcat(ans,"ñ");
		if(C==1)
		       gcvt(b/a, sig, str);
		else
		       gcvt(a/b,sig,str);
		strcat(ans,str);
		strcat(ans,"(x");
	      if(h!=0){	strcat(ans,"-");gcvt(h,sig,str);strcat(ans,str);}
		strcat(ans,") ");
		outtextxy(25,45,ans);

	      break; //Asymptotes

   case 'I' : disp();

  }
  getch();
  analyze();
  }


void graphing::analyze()
{
  char op;
  setfillstyle(1,1);
 setcolor(0);
 bar(20,20,175,200);
   if(ch==3)
 {
 outtextxy(25,30," CIRCLE");
 outtextxy(25,45," A- Centre");
 outtextxy(25,60," B- Radius");
 outtextxy(25,75," C- x-intercept");
 outtextxy(25,90," D- y-intercept");
 outtextxy(25,105," E- Eccentricity");
 outtextxy(25,175," F- Back ");
 }
 else if(ch==4)
 {
 outtextxy(25,30," PARABOLA");
 outtextxy(25,45," A- Focus");
 outtextxy(25,60," B- Vertex");
 outtextxy(25,75," C- Directrix");
 outtextxy(25,90," D- Latus Rectum");
 outtextxy(25,105," E- Eccentricity");
 outtextxy(25,120," F- Axis of Sym.");
 outtextxy(25,175," G- Back");
 }
 else if(ch==5)
 {
  outtextxy(25,30," ELLIPSE");
 outtextxy(25,45," A- Foci");
 outtextxy(25,60," B- Vertex");
 outtextxy(25,75," C- Directrix");
 outtextxy(25,90," D- Latus Rectum");
 outtextxy(25,105," E- Eccentricity");
 outtextxy(25,120," F- Centre");
 outtextxy(25,135," G- Maj/Min axis");
 outtextxy(25,175," H- Back");

  }
  else if(ch==6)
 {
  outtextxy(25,30," HYPERBOLA");
 outtextxy(25,45," A- Foci");
 outtextxy(25,60," B- Vertex");
 outtextxy(25,75," C- Directrix");
 outtextxy(25,90," D- Latus Rectum");
 outtextxy(25,105," E- Eccentricity");
 outtextxy(25,120," F- Centre");
 outtextxy(25,135," G- Trans/Conj axis");
 outtextxy(25,150," H- Asymptotes");
 outtextxy(25,175," I- Back");

  }
   op=getch();
   if(ch==3)
    circlea(op);
   else if(ch==4)
     parabola(op);
   else if(ch==5)
      ellipsea(op);
   else if(ch==6)
      hyperbola(op);

 }

void graphing::graph(int i,float d)
{
    float val;
   setcolor(4);
   setlinestyle(0,1,4);


    val=d*57.307;
     if(d>=0)
	val=240-val;                   // To plot values above x axis
     else if(d<0)
	val=(-1*val)+240;              // To plot values below x axis


     putpixel(i+320,val,4);

   // if((a>=0&&a<=640)&&i!=0&&(i>-320)&&(b>=0&&b<=480))
    //		lineto(a,b);				    // To connect individual points
      a=i+320;b=val;
}

void graphing::mainloop(char cho)
{
 do
  {
//  menu:
       clrscr();
  // cout<< "   \n\n EQUATION MENU";
  // cout<<"\n\n1. LINEAR EQUATIONS \n\n2. QUADRATIC EQUATIONS\n\n3. CIRCLE \n\n4. PARABOLA\n\n5. ELLIPSE\n\n6. HYPERBOLA\n\n7. GENERAL CONIC\n\n8. EXIT";
  // cin>>ch;
   switch(cho)
   {
    case '1' :  clrscr();
	      cout<< "\n\n ENTER THE EQUATION ax + by + c =0 \n\n a :";cin>>a;
	      cout<<"\n b :";cin>>b;cout<<"\n c :";cin>>c;
	       break;


   case '2':    clrscr();
	      cout<< "\n\n ENTER THE  EQUATION y = ax^2 + bx + c \n\n a :";cin>>a;
	      cout<<"\n b :";cin>>b;cout<<"\n c :";cin>>c;
	      break;

   case '3':    clrscr();        // alt+253   ý
	      cout<<"\n\n ENTER THE EQUATION (x-h)ý +(y-k)ý = aý \n\n h:";cin>>h;
	      cout<<"\n k :";cin>>k;cout<<"\n a :";cin>>a;

	      break;


   case '4':   clrscr();
	       cout<<"\n\n 1. Vertical \n\n 2. Horizontal ";
	       cin>>C;
	       clrscr();
	       if(C==1)
	       {
	       cout<<"\n\n ENTER THE EQUATION (y-k) =4*a*(x-h)ý \n\n h:";cin>>h;
	      cout<<"\n k :";cin>>k;cout<<"\n a :";cin>>a;
	      }
	      else if(C==2)
	      {
	      cout<<"\n\n ENTER THE EQUATION (x-h) =4*a*(y-k)ý \n\n h:";cin>>h;
	      cout<<"\n k :";cin>>k;cout<<"\n a :";cin>>a;
	       }
	       break;

   case '5':    clrscr();
	      cout<<"\n\n ENTER THE EQUATION (x-h)ý/aý + (y-k)ý/bý =1 \n\n h:";cin>>h;
	      cout<<"\n k :";cin>>k;cout<<"\n a :";cin>>a;cout<<"\n b :";cin>>b;
	      break;

   case '6':    clrscr();
	       cout<<"\n 1. East - West \n 2. North - South ";
	       cin>>C;
	       clrscr();
	       if(C==1)
	       {
	       cout<<"\n\n ENTER THE EQUATION (x-h)ý/aý - (y-k)ý/bý = 1 \n\n h:";cin>>h;
	      cout<<"\n k :";cin>>k;cout<<"\n a :";cin>>a;cout<<"\n b :";cin>>b;
	      }
	      else if(C==2)
	      {
	      cout<<"\n\n ENTER THE EQUATION (y-k)ý/aý - (x-h)ý/bý = 1 \n\n h:";cin>>h;
	      cout<<"\n k :";cin>>k;cout<<"\n a :";cin>>a;cout<<"\n b :";cin>>b;
	       }
	       break;

   case '7':  clrscr();
	    cout<<"\n\nENTER THE EQUATION OF CONIC SECTION axý+bxy+ cyý+dx+ey+f=0";
	    cout<<"\n a:";cin>>a; cout<<"\n b:";cin>>b; cout<<"\n c:";cin>>c; cout<<"\n d:";cin>>d;
	     cout<<"\n e:";cin>>e; cout<<"\n f:";cin>>f;
	     break;

   case '8':   exit(0);


 //  default : goto menu;
    }


    int gdriver = DETECT, gmode, errorcode;
  initgraph(&gdriver, &gmode, "\\tc\\bgi");
   creategraph();
   setcolor(4);
     setlinestyle(0,1,4);
    if(cho=='3')
    {
       circle((h*57)+320,-1*(k*57)+240,a*57);

    }
    else if (cho=='5')
      { ellipse((h*57)+320,-1*(k*57)+240,0,360,a*57,b*57);
	  //sound(320);delay(30);sound(256);nosound();
	 }
  if((cho=='4'&&C==2))          //horizontal parabola
  {
     horzpara();

  }
   else if(cho=='6'&&C==1)      //EW hyper
   {
     ewhyper();
     }


     else if(cho=='6'&&C==2)   //NS Hyperbola
   {
   nshyper();


     }

  else if(cho=='7')
  {
   generalconic();
   }

  else if(cho=='1'||cho=='2'||(cho=='4'&&C==1))
  {
  for( i=-320;i<320;i++)
  {
    x=i*0.01745;
    if(cho=='1')                        // Case of straight line
    {
      if(b==0)
      {
       line(320-(57*c),0,320-(57*c),480);
       break;
       }
      else
	y=((-a*x/b)-(c/b));
     }
    else if(cho=='2')
	  y=(a*x*x)+(b*x)+c;     // The function

    else if(cho=='4'&&C==1)
       y=4*a*(pow(x-h,2))+k;


    val=y*57.307;
     if(y>=0)
	val=240-val;                   // To plot values above x axis
     else if(y<0)
	val=(-1*val)+240;              // To plot values below x axis

     pos=i+320;
     putpixel(pos,val,4);

    if((t1!=0&&t1!=320&&t1<640)&&(i>-320)&&(t2!=0&&t2!=480))

		lineto(t1,t2);     			    // To connect individual points
      t1=pos;t2=val;

    } //end of for loop

   }                // end of else condition
    disp();

   closegraph();
  //    goto menu;

  }while(cho!='10');
 }

class matrix
{
    private:
    int x,y,i,j;
    public:
    double min[4][4];//min is the answer
    void getinput(int n,int n1, double mat[4][4]); //to get input
    double det(int n, double mat[4][4]); //to calculate determinant
    void mino(int n, double mat[4][4]); //to find minor matrix
    void cofact(int n, double[4][4]);//to find cofactor matrix
    void trans(int n, double mat[4][4]);//to find transpose
    void adj(int n, double mat[4][4]); // to find adjoint
    void inv(int n, double mat[4][4]);//to find the inv
    void output(int n,int n1, double mat[4][4]);//to display
    double trace(int no, double mat[4][4]);//to find the trace
};
double du = 0;
void matrix::getinput(int n,int n1, double mat[4][4]) //function to get the input
{
    int i,j,x=9,y=10,z,a;
    gotoxy(8,8);
    cout<<" Enter the elements of the matrix ";
    gotoxy(x,y);
    setcolor(15);
    a=8*n*5;
    setlinestyle(0,1,10);
    line(85,135,85,135+a);
    z=2*n1*27;
    line(85+z,135,85+z,135+a);
    line(85,135,90,135);line(85+z,135,80+z,135); line(85,135+a,90,135+a);line(85+z,135+a,80+z,135+a);
    for(i=0;i<n;i++)
    {
	for(j=0;j<n1;j++)
	{
	    gotoxy(x+=6,y);
	    cin>>mat[i][j];
	}
	gotoxy(x,y+=2); x=9;
    }
}
void matrix::output(int n,int n1, double mat[4][4]) //function to get the input
{
    int i,j,x=9,y=10,z,a;
    gotoxy(x,y);
    setcolor(15);
    a=5*n*8;
    setlinestyle(0,1,10);
    line(85,135,85,135+a);
    z=2*n1*27;
    line(85+z,135,85+z,135+a);
    line(85,135,90,135);line(85+z,135,80+z,135); line(85,135+a,90,135+a);line(85+z,135+a,80+z,135+a);
    for(i=0;i<n;i++)
    {
	for(j=0;j<n1;j++)
	{
	    gotoxy(x+=6,y);
	    cout<<mat[i][j];
	}
	gotoxy(x,y+=2); x=9;
    }
}
double matrix::det(int n,double mat[4][4])//function to find determinant
{
    int c, subi, i, j, subj;
    double submat[4][4];
    if (n == 2)
    {
	return( (mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]));
    }
    else
    {
	for(c = 0; c < n; c++)
	{
	    subi = 0;
	    for(i = 1; i < n; i++)
	    {
		subj = 0;
		for(j = 0; j < n; j++)
		{
		    if (j == c)
		    {
			continue;
		    }
		    submat[subi][subj] = mat[i][j];
		    subj++;
		}  	//end of for j
		subi++;
	    } 	    //end of for i
	    du = du + (pow(-1 ,c) * mat[0][c] * det(n - 1 ,submat));
	} 	//end of for c
    }      //end of else
    return du;
}
void matrix:: mino(int n, double mat[4][4])// function to find minor
{
    int c, subi, i, j, subj;
    double submat[4][4];
    if (n == 2)
    {
	min[0][0]=mat[1][1];
	min[1][1]=mat[0][0];
	min[1][0]=mat[0][1];
	min[0][1]=mat[1][0];
    }
    else
    {
	for(int r=0; r<n;r++)
	{
	    for(c = 0; c < n; c++)
	    {
		subi = 0;
		for(i = 0; i < n; i++)
		{
		    if(i==r)
		    continue;  // continue;
		    subj = 0;
		    for(j = 0; j < n; j++)
		    {
			if (j == c)
			{
			    continue;//continue goes to the next iterative loop like break
			}
			submat[subi][subj] = mat[i][j];//submat is always a matrix of order n-1
			subj++;
		    }		    //end of for j
		    subi++;
		}		//end of for i
		min[r][c]=det(n-1,submat);
	    } 	    //end of for c
	}	//end of for r
    } 	   //end of else
}// end of function
void matrix::cofact(int no,double mat[4][4]) // to find cofactor of a matrix
{
    mino(no,mat);
    for(int i=0;i<no;i++)
    {
	for(int j=0;j<no;j++)
	{
	    min[i][j]=(pow(-1,(i+j)))*min[i][j];
	}
    }
}
void matrix::trans(int no, double mat[4][4])
{
    for(int i=0;i<no;i++)
    {
	for(int j=0;j<no;j++)
	{
	    min[i][j]=mat[j][i];
	}
    }
}
void matrix::adj(int no, double mat[4][4])
{
    double ten[4][4];
    cofact(no,mat);
    for(int i=0;i<no;i++)
    {
	for(int j=0;j<no;j++)
	{
	    ten[i][j]=min[i][j];
	}
    }
    trans(no,ten);
}
double matrix::trace(int no, double mat[4][4])
{
    double trac=0;
    for(int i=0;i<no;i++)
    {
	trac=trac+mat[i][i];
    }
    return trac;
}
void matrix::inv(int no,double mat[4][4])
{
    double deta;du=0;
    deta=det(no,mat);
    adj(no,mat);
    for(int i=0;i<no;i++)
    {
	for(int j=0;j<no;j++)
	min[i][j]=((min[i][j])/deta);
    }
    du=0;
}
unsigned long factorial(int n);
char input();
char minput();
double add(double,double,char);
double angle_conv(double);
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
/************************************************************/
/* THIS FUNCTION DRAWS THE BUTTONS OF THE CALCULATOR        */
/************************************************************/
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
    setcolor(14);
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
    setfillstyle(1,0); setcolor(14);
    bar3d(50,20,600,400,1,1);
    setcolor(3);
    setfillstyle(1,8);
    bar(52,22,598,42);//header
    button(575,23,595,40,UNCLICKED,"x",0);
    setcolor(2);line(52,44,598,44); setcolor(15);
    c=2;a=b=d=0;
    button(52,22,183,42,UNCLICKED,"SCIENTIFIC CALC",a); // TAB 1
    button(183,22,314,42,CLICKED,"MATRICES",b); // TAB 2
    button(314,22,445,42,UNCLICKED,"GRAPHING",c);  // TAB 3
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
/*********************************************************/
/* Main starts */
/*********************************************************/
void main()
{
    clrscr();
    matrix mt;
    double y=0,z=0,pnt,pnt1=0,x=0,temp;
    int gdriver = DETECT, gmode, errorcode;
    int i;
    initgraph(&gdriver, &gmode, "\\tc\\bgi");
    scicalc:
    structure();
    gotoxy(row,col);
    cout<<"\t\t\t\t\t";
    gotoxy(row,col);
    cout<<"0";
    mem=(float*)malloc(y*sizeof(float));
    while( ch!=27&&ch1!=27) //While Escape is not pressed
    {
	//and if base is not 10
	pnt1=0;//no doubleing point entered Yet
	ch2='0';
	while(ch2!=27)
	{
	    if(bflagp!='u')
	    {
		dummy=input();
		if(dummy!='o')
		{
		    gotoxy(row,col);
		    input();
		    gotoxy(row,col);
		    cout<<"\t\t\t\t\t\t";
		}
		y=0;z=0;ch='0';
		gotoxy(row,col);
		cout<<"\t\t\t\t\t\t";
		gotoxy(row,col);
		cout<<"0";
	    }
	    ch=input();
	    if(ch=='Ý')
	    {
		goto scicalc;
	    }
	    else if (ch==' ')
	    {
		goto matrix;
	    }
	    else if (ch=='ô')
	    {
		cleardevice();
		goto grapher;
	     }
	    if(ch=='>'||ch=='<'||ch=='?')
	    {
		sflag=0;
		if(ch=='>') //M+
		*mem+=y;
		if(ch=='<') //M-
		*mem-=y;
		if(ch=='?') //MR
		{
		    y=*mem;
		    gotoxy(row,col);
		    cout<<"\t\t\t\t\t";
		    gotoxy(row,col);
		    printf("%g",y);
		}
		if(*mem==0)
		mflag=0;
		if(*mem!=0)
		mflag=1;
	    }
	    if(mflag==0)
	    {
		gotoxy(row,7);
		cout<<"";
	    }
	    else if(mflag!=0)
	    {
		gotoxy(row,7);
		cout<<"M";
	    }
	    gotoxy(row,col);
	    if(ch=='a')
	    {
		sflag=0;
		y=0;
		gotoxy(row,col);
		cout<<"\t\t\t\t\t";
		gotoxy(scrx,scry);cout<<"\t\t\t\t ";
		gotoxy(row,col);
		cout<<'0';
	    }
	    else if(ch=='o') //for clearing the screen of the calculator
	    {
		sflag=0;
		y=0;z=0;
		gotoxy(row,col);
		cout<<"\t\t\t\t ";
		gotoxy(row,col);
		cout<<'0';
		gotoxy(scrx,scry);cout<<"\t\t\t\t ";
		gotoxy(row,col);
		break;
	    }
	    else if(ch=='q')
	    {
		if(sflag==1) //cube root function
		{
		    gotoxy(scrx,scry);
		    cout<<" 3û("<<y<<")";
		    locx=wherex();locy=wherey();
		    y=pow(y,0.333333);
		    gotoxy(row,col);
		    cout<<"\t\t\t\t ";
		    gotoxy(row,col);
		    printf("%g",y);
		}
		else
		{
		    gotoxy(34,7);
		    cout<<" û("<<y<<")";
		    locx=wherex();locy=wherey();
		    y=sqrt(y);
		    gotoxy(row,col);
		    cout<<"\t\t\t\t ";
		    gotoxy(row,col);
		    printf("%g",y);
		}
	    }
	    else if(ch=='m')
	    {
		sflag=0;
		gotoxy(34,7);
		cout<<" 1/"<<y<<"";
		locx=wherex();locy=wherey();
		y=1/y;
		gotoxy(row,col);
		cout<<"\t\t\t\t ";
		gotoxy(row,col);
		printf("%g",y);
	    }
	    else if(ch=='!')
	    {
		sflag=0;
		gotoxy(34,7);
		cout<<" "<<y<<"!";
		locx=wherex();locy=wherey();
		y=factorial(y);
		gotoxy(row,col);
		cout<<"\t\t\t\t ";
		gotoxy(row,col);
		printf("%g",y);
	    }
	    if(ch=='+'||ch=='-'||ch=='/'||ch=='*'||ch=='P'||ch=='C'||ch=='^')
	    {
		sflag=0;
		gotoxy(locx,locy);
		cout<<ch;
		locx=wherex();locy=wherey();
		break;
	    }
	    if(ch=='=')
	    break;
	    //////////////////////
	    if(ch=='.') //case for a decimal point
	    {
		sflag=0;
		if(pnt1==0) //i.e. no decimal has been entered yet
		{
		    gotoxy(row,col);
		    cout<<"\t\t\t\t ";//double
		    gotoxy(row,col);
		    printf("%g.",y);
		    gotoxy(34,7);
		    cout<<" "<<y<<".";
		    locx=wherex();locy=wherey();
		    pnt1=0.1; //i.e. one decimal point no has been entered
		    continue; //go back to the beginning and get the next number
		}
		else //decimal point has already been entered and thus no change in the screen
		{
		    sflag=0;
		    continue; //go back to the beginning
		}
	    }//out of the '.' condition
	    
	    if(pnt1!=0) //i.e. we have a doubleing point
	    {
		sflag=0;
		if(ch<='9'&&ch>='0') //input integer
		{
		    x=(double)ch;//type cast the character into double to perform further operations
		    x-=48; //since character digit indoubling -48 gives the corresponding ASCII
		    x=x*pnt1; //make it a decimal
		    y=x+y; //add it in result
		    pnt1*=0.1; //shift to the second doubling point
		    gotoxy(row,col);
		    printf("%g",y);
		    gotoxy(34,7);
		    cout<<" "<<y<<"";
		    locx=wherex();locy=wherey();
		    gotoxy(row,col);
		    continue; //back to the top
		}
	    }
		    
	    if(ch<='9'&&ch>='0') //if no decimal point number then proceed
	    {
		sflag=0;
		x=(double)ch; //typecast to double
		x-=48; //get corresponding ASCII
		y=(y*10)+x; //add to right of result
		gotoxy(row,col); //go back to start of the calc screen
		cout<<"\t\t\t\t "; //clear the screen
		gotoxy(row,col);
		printf("%g",y); //print the number
		gotoxy(34,7);
		cout<<" "<<y<<"";
		locx=wherex();locy=wherey();
	    }
	    if(ch=='d'||ch=='r'||ch=='g')
	    {
		sflag=0;
		y=angle_conv(y);
		gotoxy(row,col);
		cout<<"\t\t\t\t ";
		gotoxy(row,col);
		printf("%g",y);
	    }
	    if(ch=='s'||ch=='c'||ch=='t'||ch=='i'||ch=='j'||ch=='k'||ch=='n'||ch=='l'||ch=='p'||ch=='h')
	    //ie the user opted for a function
	    {   gotoxy(34,7);
		if(ch=='s'||ch=='c'||ch=='t') //sin /cos/tan
		{
		    if(sflag==1) ////// HYPERBOLIC FUNCTIONS
		    {
			switch(ch)
			{
			    case 's':   cout<<" sinh("<<y<<")";
				      locx=wherex();locy=wherey();y=sinh(y);
				      break;
			    case 'c':   cout<<" cosh("<<y<<")";
				      locx=wherex();locy=wherey();y=cosh(y);
				      break;
			    case 't':   cout<<" tanh("<<y<<")";
				      locx=wherex();locy=wherey();y=tanh(y);
				      break;
			}
		    }
		    //end of hyperbolic functions
		    else  //circular functions
		    {
			if(flag!='r')
			{
			    flagp=flag;
			    flag='r';
			    y=angle_conv(y);
			    flag=flagp;
			}
			switch(ch)
			{
			    case 's':    cout<<" sin("<<y<<")";
				      locx=wherex();locy=wherey();
				      y=sin(y); break;
			    case 'c':   cout<<" cos("<<y<<")";
				      locx=wherex();locy=wherey();
				      y=cos(y); break;
			    case 't': 
				      cout<<" tan("<<y<<")";
				      locx=wherex();locy=wherey();
				      y=tan(y); break;
			}
		    }
		}

		if(ch=='i'||ch=='j'||ch=='k') // Inverse trigonometric functions
		{
		    if( sflag==1)//Inverse hyperbolic functions
		    {
			double e; 
			switch(ch)
			{
			    case 'i':   cout<<" sinh^-1("<<y<<")";
			    	     locx=wherex();locy=wherey();
			    	     e=sqrt((y*y)+1);	    y=log(y+e);
			   	    break;

			    case 'j':  cout<<" cosh^-1("<<y<<")";
			    	locx=wherex();locy=wherey();
			    	e=sqrt((y*y)-1);   y=log(y+e);
			    	break;

			    case 'k':  cout<<" tanh^-1("<<y<<")";
			    	     locx=wherex();locy=wherey();
			    	     e=log((y+1)/(1-y));   	 y=e/2;
			    	     break;
			}
		    }
		    else //Inverse Circular Functios
		    {
			if(flag!='r')
			{
			    flagp='r';
			}

			switch(ch)
			{
			    case 'i': cout<<" sin^-1("<<y<<")";
			    	  locx=wherex();locy=wherey();y=asin(y); break;

			    case 'j':  cout<<" cos^-1("<<y<<")";
			    	  locx=wherex();locy=wherey();y=acos(y); break;

			    case 'k':    cout<<" tan^-1("<<y<<")";
			    	locx=wherex();locy=wherey();
			    	y=atan(y); break;
			}
			if(flag!='r')
			y=angle_conv(y);
		    }
		}
		
		else if(ch=='n')// For exponential and natural log functions
		{     if(sflag==1)
		    {
			cout<<" e^("<<y<<")";
			locx=wherex();locy=wherey();
			y=exp(y);
			sflag=0;
		    }
		    else  // ln(x)
		    {
			cout<<" ln("<<y<<")";
			locx=wherex();locy=wherey();
			y=log(y); 
		    }
		}

		else if(ch=='l')
		{ 
   if(sflag==1)// 10^x
		    {
			cout<<" 10^("<<y<<")";
			locx=wherex();locy=wherey();
			y=pow(10,y);
			sflag=0;
		    }
		    else  // ln(x)
		    {
			cout<<" log("<<y<<")";
			locx=wherex();locy=wherey();
			y=log10(y); //log
		    }
		}
		else if(ch=='p')
		{
		    if(sflag==1)
		    {
			cout<<" ("<<y<<")^3";
			locx=wherex();locy=wherey();
			y=pow(y,3);
			sflag=0;
		    }
		    else
		    {
			cout<<" ("<<y<<")^2";
			locx=wherex();locy=wherey();
			y=pow(y,2); //square
		    }
		}
		else if(ch=='h')
		{
		    sflag=0;
		    gotoxy(34,7); cout<<" pi";
		    locx=wherex();locy=wherey();
		    y=PI; //pi
		}
		gotoxy(row,col);
		cout<<"\t\t\t\t ";//Clear the screen
		gotoxy(row,col);
		printf("%g",y);
	    }
	    //else condition //end of if
	}
	//end of inner while//out of second condition i.e. we now have the first no. or function or operator
	for(;ch!=27&&ch1!='='&&ch!='=';)//i.e. the characters input are not ESC or Equal to 
	{
	    pnt1=0;z=0;
	    if(ch=='o'||ch1=='o') // For Clear The Screen
	    {
		sflag=0; y=0;z=0;
		gotoxy(row,col); cout<<"\t\t\t\t ";
		gotoxy(row,col); cout<<"0";
		gotoxy(row,col);
		break;
	    }
	    for(;ch1!=27;)
	    {
		gotoxy(row,col);
		ch1=input();
		if(ch1=='>'||ch1=='<'||ch1=='?')
		{
		    if(ch1=='>') //M+
		    *mem+=z;
		    if(ch1=='<') //M-
		    *mem-=z;
		    if(ch1=='?') //MR
		    {
			z=*mem;
			gotoxy(row,col); cout<<"\t\t\t\t ";
			gotoxy(row,col); printf("%g",z);
		    }
		    if(*mem==0)
		    mflag=0;
		    if(*mem!=0)
		    mflag=1;
		}
		if(mflag==0)
		{
		    gotoxy(row,7);
		    cout<<"";
		}
		if(mflag!=0)
		{
		    gotoxy(row,7);
		    cout<<"M";
		}
		gotoxy(row,col);
		if(ch1=='a')
		{
		    z=0;
		    gotoxy(row,col); cout<<"\t\t\t\t ";
		    gotoxy(row,col); cout<<'0';
		}
		if(ch=='o'||ch1=='o') // For Clear The Screen
		{
		    y=0;z=0;
		    gotoxy(row,col); cout<<"\t\t\t\t ";
		    gotoxy(row,col); cout<<'0';
		    gotoxy(row,col);
		    break;
		}
		if(ch1=='q')
		{ gotoxy(locx,locy);
		    if(sflag==1)
		    {
			cout<<" 3û("<<z<<")";
			z=pow(z,0.333333);
			gotoxy(row,col); cout<<"\t\t\t\t ";
			gotoxy(row,col); printf("%g",z);
		    }
		    else
		    {
			cout<<"û("<<z<<")";
			z=sqrt(z);
			gotoxy(row,col); cout<<"\t\t\t\t ";
			gotoxy(row,col); printf("%g",z);
		    }
		}
		if(ch1=='m')
		{
		    gotoxy(locx,locy);cout<<" 1/"<<z<<"";
		    z=1/z;
		    gotoxy(row,col); cout<<"\t\t\t\t ";
		    gotoxy(row,col); printf("%g",z);
		}
		if(ch1=='.')
		{
		    if(pnt1==0)
		    {
			gotoxy(row,col); cout<<"\t\t\t\t ";
			gotoxy(row,col); printf("%g.",z);
			gotoxy(locx,locy); cout<<""<<z<<".";
			pnt1=0.1;
			continue;
		    }
		    else
		    continue;
		}
		if(pnt1!=0)
		{
		    if(ch1<='9'&&ch1>='0')
		    {
			x=(double)ch1;		x-=48;
			x=x*pnt1;		z=x+z;
			pnt1=pnt1*0.1;
			gotoxy(row,col); cout<<"\t\t\t\t ";
			gotoxy(row,col); printf("%g",z);
			gotoxy(locx,locy); cout<<""<<z<<"";locx=wherex();locy=wherey();
			continue;
		    }
		}
		if(ch1=='+'||ch1=='-'||ch1=='*'||ch1=='/'||ch1=='^'||ch1=='P'||ch1=='C')
		{
		    gotoxy(locx,locy);
		    cout<<ch1;
		    locx=wherex();locy=wherey();
		    break;
		}
		if(ch1=='=')
		break;
		if(ch1>='0'&&ch1<='9')
		{
		    x=(double)ch1;
		    x=x-48;
		    gotoxy(row,col); cout<<"\t\t\t\t";
		    gotoxy(row,col); z=(z*10)+x; printf("%g",z);
		    gotoxy(locx,locy); cout<<z<<"";
		}
		if(ch=='u')
		if(ch=='d'||ch=='r'||ch=='g')
		{
		    z=angle_conv(z);
		    gotoxy(row,col); cout<<"\t\t\t\t ";
		    gotoxy(row,col); printf("%g",z);
		}
		if(ch1=='s'||ch1=='c'||ch1=='t'||ch1=='i'||ch1=='j'||ch1=='k'||ch1=='n'||ch1=='l'||ch1=='p'||ch1=='h')
		//i.e. the user opted for a function
		{ gotoxy(locx,locy);
		    if(ch1=='s'||ch1=='c'||ch1=='t') 
		    {
			if(sflag==1)  ///Hyperbolic functions
			{
			    switch(ch1)
			    {
				case 's':  cout<<" sinh("<<z<<")";
					z=sinh(z); break;
				case 'c':  cout<<" cosh("<<z<<")";
					z=cosh(z); break;
				case 't':  cout<<" tanh("<<z<<")";
					z=tanh(z); break;
			    }
			}
			else // Circular functions
			{
			    if(flag!='r')// Case when the angle is not in radians
			    {
				flagp=flag; 	flag='r';
				z=angle_conv(z);
				flag=flagp;
			    }
			    switch(ch1)
			    {
				case 's': cout<<" sin("<<z<<")";
					z=sin(z); break;
				case 'c': cout<<" cos("<<z<<")";
					z=cos(z); break;
				case 't': cout<<" tan("<<z<<")";
					z=tan(z); break;
			    }
			}
		    }
		    if(ch1=='i'||ch1=='j'||ch1=='k')// Inverse Trigonometric functions
		    {
			if (sflag==1)// Inverse Hyperbolic functions
			{
			    double e;
			    switch(ch)
			    {
				case 'i':   cout<<" sinh^-1("<<z<<")";
				              e=sqrt((z*z)+1); z=log(z+e);
                                                                      	break;
				case 'j':  cout<<" cosh^-1("<<y<<")";
					e=sqrt((z*z)-1); z=log(z+e);
					 break;
				case 'k':  cout<<" tanh^-1("<<z<<")";
					 e=log((z+1)/(1-z)); z=e/2;
					 break;
			    }
			}
			else  // Inverse Circular Functions
			{
			    if(flag!='r')
			    flagp='r';
			    switch(ch1)
			    {
				case 'i': cout<<" sin^-1("<<z<<")";
				               z=asin(z); break;
				case 'j': cout<<" cos^-1("<<z<<")";
				              z=acos(z); break;
				case 'k': cout<<" tan^-1("<<z<<")";
				               z=atan(z); break;
			    }
			    z=angle_conv(z);
			}
		    }
		    else if(ch1=='n') //ln
		    {
			if(sflag==1)
			{
			    gotoxy(locx,locy); cout<<" e^("<<z<<")";
			    z=exp(z);
			}
			else
			{
			    gotoxy(locx,locy); cout<<" ln("<<z<<")";
			    z=log(z);
			}
		    }
		    else if(ch1=='l')
		    {
			if(sflag==1)
			{
			    cout<<" 10^("<<z<<")";
			    z=pow(10,z);
			}
			else
			{
			cout<<" log("<<z<<")";
			    z=log10(z); //log
			}
		    }
		    else if(ch1=='p')
		    {
			if(sflag==1)
			{
			     cout<<" "<<z<<"^3";
			    z=pow(z,3);
			}
			else
			{
			    cout<<" "<<z<<"^2";
			    z=pow(z,2); //square
			}
		    }
		    else if(ch1=='h')
		    {
			cout<<" pi";
			z=PI; //pi
		    }
		    gotoxy(row,col);
		    cout<<"\t\t\t\t ";
		    gotoxy(row,col);
		    printf("%g",z);
		    gotoxy(row,col);
		}
	    }
	    if((ch1=='*'||ch1=='/'||ch1=='^'||ch1=='P'||ch1=='C')&&(ch=='+'||ch=='-'))
	    {
		temp=y;y=z;
		gotoxy(34,7);cout<<temp<<ch<<y<<ch1;
		tch=ch;
		locx=wherex();locy=wherey();
		f=1;
	    }
	    if(ch1=='+'||ch1=='-'||ch1=='=')
	    {
		y=add(y,z,ch);
		gotoxy(34,7); cout<<"\t\t\t\t ";gotoxy(34,7);
		if(ch1!='=')
		cout<<y<<" "<<ch1;
		else
		cout<<y;
		locx=wherex();locy=wherey();
	    }
	    else if(ch=='*'||ch=='/')
	    y=add(y,z,ch);
	    else if(ch=='^')
	    {
		if(sflag==1) //check this
		{
		    gotoxy(34,7); cout<<" "<<y<<"^1/"<<z;
		    y=add(y,(1/z),ch);
		}
		else
		{
		    y=add(y,z,ch);
		}
	    }
	    else if(ch=='P'||ch=='C')
	    {
		y=add(y,z,ch);
	    }
	    gotoxy(row,col);
	    cout<<"\t\t\t\t ";
	    gotoxy(row,col);
	    printf("%g",y);
	    ch=ch1;
	    ch1='0';
	    if(ch=='='||ch1=='=')
	    {
		break;
	    }
	}
	if(f==1)
	{
	    y=add(temp,y,tch); gotoxy(34,7);cout<<"\t\t\t\t ";
	    gotoxy(34,7);cout<<y;
	    locx=wherex();locy=wherey();
	    f=0;
	}
	if(ch=='o'||ch1=='o') // For Clear The Screen
	{
	    y=0;z=0;
	    gotoxy(row,col);
	    cout<<"\t\t\t\t ";
	    gotoxy(row,col);
	    cout<<'0';
	    gotoxy(34,7);
	    cout<<"\t\t\t\t ";
	    gotoxy(row,col);
	    continue;
	}
	gotoxy(row,col);
	cout<<"\t\t\t\t ";
	gotoxy(row,col);
	printf("%g",y);
	z=0;
    }
    grapher:
    
      ginit();
     
      while(ch!='Ý'&&tch!='Ý'&&ch!=' '&&tch!=' ')
      {
	setfillstyle(1,0);bar(54,45,600,398);
       gstructure();
       tch=ginput();
       g.mainloop(tch);
       }


    matrix:                             //matrix label
    minit();
    int no,no1;
    gotoxy(8,4);cout<<" Press any key to create matrix";
    ch=minput();
    double det;
    while(ch!='Ý'&&tch!='Ý')
    {
	mat:               //creating matrix block
	gotoxy(8,4);
	cout<<" Enter the order of the Matrix (Max 4x4)";
	cin>>no>>no1;gotoxy(8,6);
	mt.getinput(no,no1,matr);
	submenu:
	setfillstyle(1,0);bar(54,45,600,398);
	mstructure();
	du=0;
	tch=minput();
        
	if((tch=='1'||tch=='5'||tch=='6'||tch=='2'||tch=='3')&&(no!=no1))
	{
	    minit();
	    gotoxy(8,4);
	    cout<<" The given function is defined only for a square matrix";
	    tch='0';
	    gotoxy(8,20);cout<<" Press any key to return to mat menu";
	    getch();
	    goto submenu;
	}
        else if(tch=='ô')
              goto grapher;             
 
	if(tch=='1')
	{
	    minit();
	    gotoxy(8,4);
	    cout<<"The Minor matrix is ";
	    mt.mino(no,matr);
	    mt.output(no,no,mt.min);
	    gotoxy(8,20);cout<<" Press any key to return to mat menu";
	    getch();
	    goto submenu;
	}
	else if(tch=='2')
	{
	    minit();
	    gotoxy(8,5);
	    du=0;cout<<" Determinant is "<<mt.det(no,matr);
	    gotoxy(8,20);cout<<" Press any key to return to mat menu";
	    getch();
	    goto submenu;
	}
	else if(tch=='ß')//To edit the matrix
	{
	    minit();
	    goto mat;
	}
	else if(tch=='3')
	{
	    minit();
	    gotoxy(8,5);
	    du=0;
	    det=mt.det(no,matr);
	    if(det==0)
	    {
		cout<< " The inverse is undefined! The determinant is zero.";
	    }
	    else
	    {
		mt.inv(no,matr);
		cout<<" The inverse of the matrix is : ";
		mt.output(no,no,mt.min);
	    }
	    gotoxy(8,20);
	    cout<<" Press any key to continue";
	    getch();
	    goto submenu;
	}
	else if(tch=='4')
	{
	    minit();
	    gotoxy(8,5);
	    int x,y; double c[4][4];
	    cout<<" Enter the order of the new matrix :";
	    cin>>x>>y;gotoxy(8,6);
	    if(no1==x)
	    {
		cout<<" Matrix multiplication possible";
		gotoxy(8,7);
		cout<<"";
		mt.getinput(x,y,mt.min);
		cleardevice();
		for(int i=0;i<no;i++)
		{
		    for(int j=0;j<y;j++)
		    {
			c[i][j]=0;
			for(int o=0;o<no1;o++)
			{
			    c[i][j]=c[i][j]+(matr[i][o]*mt.min[o][j]);
			}
		    }
		}
		minit();gotoxy(8,6);
		cout<<" The product of the two matrices is :";
		mt.output(no,y,c);
	    }
	    //end of if
	    else
	    cout<<" Matrix multiplication not possible!";
	    gotoxy(8,20);
	    cout<<" Press any key to return to mat menu";
	    getch();
	    goto submenu;
	}
	else if(tch=='5')
	{
	    minit();
	    gotoxy(8,5);
	    du=0;cout<<" The adjoint matrix is ";
	    mt.adj(no,matr);
	    mt.output(no,no,mt.min);
	    gotoxy(8,20);cout<<" Press any key to return to mat menu";
	    getch();
	    goto submenu;
	}
	else if(tch=='6') //co fact
	{
	    minit();
	    gotoxy(8,5);
	    du=0;cout<<" The cofactor matrix is ";
	    mt.cofact(no,matr);
	    mt.output(no,no,mt.min);
	    gotoxy(8,20);cout<<" Press any key to return to mat menu";
	    getch();
	    goto submenu;
	}
	else if(tch=='7') //transpose
	{
	    minit();
	    gotoxy(8,5);
	    du=0;cout<<" The transpose is ";
	    mt.trans(no,matr);
	    mt.output(no,no,mt.min);
	    gotoxy(8,20);cout<<" Press any key to return to mat menu";
	    getch();
	    goto submenu;
	}
	else if(tch=='A') //transpose
	{
	    minit();
	    gotoxy(8,5);
	    du=0;cout<<" The trace is "<<mt.trace(no,matr);
	    gotoxy(8,20);cout<<" Press any key to return to mat menu";
	    getch();
	    goto submenu;
	}
	else if(tch=='–'||tch=='›'||tch=='š'||tch=='œ')
	{
	    cleardevice();
	    minit();
	    gotoxy(8,5);
	    cout<<"";
	    mt.getinput(no,no1,mt.min);
	    minit();
	    if(tch=='š')
	    {
		for(int i=0;i<no;i++)
		{
		    for(int j=0;j<no1;j++)
		    mt.min[i][j]=matr[i][j]+mt.min[i][j];
		}
	    }
	    else if(tch=='›')
	    {
		for(int i=0;i<no;i++)
		{
		    for(int j=0;j<no1;j++)
		    mt.min[i][j]=matr[i][j]-mt.min[i][j];
		}
	    }
	    else if(tch=='œ')
	    {
		for(int i=0;i<no;i++)
		{
		    for(int j=0;j<no1;j++)
		    mt.min[i][j]=(matr[i][j])*(mt.min[i][j]);
		}
	    }
	    else if(tch=='–')
	    {
		for(int i=0;i<no;i++)
		{
		    for(int j=0;j<no1;j++)
		    mt.min[i][j]=(matr[i][j])/(mt.min[i][j]);
		}
	    }
	    gotoxy(8,6);
	    cout<<" The resultant of the two matrices is ";
	    mt.output(no,no1,mt.min);
	    locy=wherey();
	    gotoxy(8,20);cout<<" Press any key to return to mat menu";
	    getch();
	    goto submenu;
	}
    }
    ch='0';tch='0';
    goto scicalc;
    closegraph();
    remove_mouse();nosound();
    exit(0);
}
//////////////////////////////////////////////////////////
// Function to get input   in the matrix menu                 //
//////////////////////////////////////////////////////////
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
	    hide_mouse(); //alt+ 989 Ý
	    button(52,22,183,42,UNCLICKED,"SCIENTIFIC CALC",15); // TAB 1
	    show_mouse(); 	ch='Ý';
	    return ch;
	}
	else if (X>=575&&X<=595&&Y>=23&&Y<=40) //OFF
	{
	    end();
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


           else if(X>=100&&X<=290&&Y>=240&&Y<=305)
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
	    hide_mouse(); //alt+ 989 Ý
	    button(52,22,183,42,UNCLICKED,"SCIENTIFIC CALC",15); // TAB 1
	    show_mouse(); 	ch='Ý';
	    return ch;
	}
	else if (X>=575&&X<=595&&Y>=23&&Y<=40) //OFF
	{
	    end();
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
	    hide_mouse(); //alt ß 223
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
	    hide_mouse(); //alt+ 666 š
	    button(350,240,440,305,UNCLICKED,"DOT +",0); // Box Of .+
	    show_mouse();       ch='š';
	    return ch;
	}
	else if(X>=450&&X<=540&&Y>=240&&Y<=305)
	{
	    hide_mouse();
	    button(450,240,540,305,CLICKED,"DOT -",0); // Box Of .-
	    show_mouse();       delay(250);
	    hide_mouse(); //alt+ 667  ›
	    button(450,240,540,305,UNCLICKED,"DOT -",0); // Box Of .-
	    show_mouse();  	ch='›';
	    return ch;
	}
	else if(X>=450&&X<=540&&Y>=315&&Y<=380)
	{
	    hide_mouse();
	    button(450,315,540,380,UNCLICKED,"DOT /",0); // Box Of ./
	    show_mouse();        delay(250);
	    hide_mouse(); //alt+ 662  –
	    button(450,315,540,380,UNCLICKED,"DOT /",0); // Box Of ./
	    show_mouse();         ch='–';
	    return ch;
	}
	else if(X>=350&&X<=440&&Y>=315&&Y<=380)
	{
	    hide_mouse();
	    button(350,315,440,380,CLICKED,"DOT x",0); // Box Of .x
	    show_mouse();         delay(250);
	    hide_mouse(); //alt+ 668  œ
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

	    show_mouse();  	    ch='ô';//change ch
	    return ch;
	}

    }
    while(kbhit() == 0);// while no key has been pressed
    ch=getch();
    return ch;
}

/************************************************************/
/* This function gets the user's Input                                                                  */
/************************************************************/
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
	    end();
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
	    hide_mouse(); //alt+ 989 Ý
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

	    show_mouse();  	    ch='ô';//change ch
	    return ch;
	}
    }
    while(kbhit() == 0);
    ch=getch();
    return ch;
}
/*************************************************************************/
/* This function performs the Calculations */
/*************************************************************************/
double add(double x,double y,char ch)
{
    switch(ch)
    {
	case '+': y=x+y;break;
	case '-': y=x-y;break;
	case '*': y=x*y;break;
	case '^': y=pow(x,y); break;
	case 'P': y=(factorial(x))/(factorial(x-y));break;
	case 'C': y=(factorial(x))/(factorial(x-y)*factorial(y));break;
	case '/': y=x/y;
    }
    return y;
}
double angle_conv(double no)
{
    if(flagp=='d')
    {
	if(flag=='r')
	{
	    no=no*PI/180;
	}
	if(flag=='g')
	{
	    no=no*1.1111111;
	}
    }
    else if(flagp=='r')
    {
	if(flag=='d')
	{
	    no=no*180/PI;
	}
	if(flag=='g')
	{
	    no=no*180/PI*1.1111111;
	}
    }
    else if(flagp=='g')
    {
	if(flag=='r')
	{
	    no=no/(180*1.1111111)*PI;
	}
	if(flag=='d')
	{
	    no=no/1.1111111;
	}
    }
    return(no);
}
unsigned long factorial(int n)
{
    unsigned long fact = 1;
    int i;
    for(i = n; i > 0; i--)
    {
	fact = fact*i;
    }
    return fact;
}
