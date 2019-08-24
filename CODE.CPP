#include<fstream.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<graphics.h>
#include<iomanip.h>
#include<dos.h>

void show(char* a,int x,int y)
{
    for(int i=0;i<50;i++,a++)
    {
      *a=getch();
      if(int(*a)==13)
      {
	*a='\0';
	break;
      }
      a[1]='\0';
      outtextxy(x+i*8,y,a);
    }
    a=a-i;
}
void showl(char* a,int x,int y)
{
    for(int i=0;i<100;i++,a++)
    {
      *a=getch();
      if(*a=='.')
      {
	*a='\0';
	break;
      }
      if(int(*a)==13)
      {
	 y=y+10;
	 i=-1;
	 *a='\n';
      }
      else
      {
	a[1]='\0';
	outtextxy(x+i*8,y,a);
      }
    }
    a=a-i;
}

void show(int &a,int x,int y)
{
  char *z;
  z=NULL;
  z[0]=' ';
  z[1]=' ';
  int d=0,e=0;
  *z=getch();
  outtextxy(x,y,z);
  d=int(*z)-48;
  z++;
  *z=getch();
  outtextxy(x+8,y,z);
  e=int(*z)-48;
  a=d*10+e;

}

void show10(long &a,int x,int y)
{
  char *z,buf[11];
  z=buf;
  a=0;
  for(int i=0;i<11;i++)
    buf[i]=' ';
  buf[i]='\0';
  int v[15];
  for(i=0;i<11;i++,z++)
  {
    *z=getch();
    if(int(*z)==13)
       break;
    v[i]=int(*z)-48;
    a=a*10+v[i];
    outtextxy(x+i*8,y,z);
  }
}


class aeroplane
{
  char flightname[50],from[50],to[50];
  long charge[3],arrtime,depttime;

  public:
     char*   returnflightname()     { return flightname;   }
     char*   returnto()             { return to;           }
     char*   returnfrom()           { return from;         }
     long    returnarrtime()        { return arrtime;      }
     long    returndepttime()       { return depttime;     }
     long*   returncharge()         { return charge;       }

     void update();
     void readflight(char*,char*);
     void displayflights1()
       {
	  cout<<"\nFLIGHT NAME       -  "<<flightname;
	  cout<<"\nFROM              -  "<<from;
	  cout<<"\nTO                -  "<<to;
	  cout<<"\nDEPARTURTURE TIME -  "<<depttime;
	  cout<<"\nARRIVAL TIME      -  "<<arrtime;
	  cout<<"\nCHARGE[First]     -  "<<charge[2];
	  cout<<"\nCHARGE[Bussiness] -  "<<charge[1];
	  cout<<"\nCHARGE[Economic]  -  "<<charge[0];
       }
}oa;

class bookings
{
  char flightno[50];
  int seatno[4];
  public:	
      char* returnflightno()  { return flightno;}
      int* returnseatno()     { return seatno;  }

      void enterflightno();
      int* modifyseatno(int*,int*);
      void createflightno(int);
      void enterseatno(int*);
      bookings();

}ob;

class customer
{
  int requiredclass,noofpassengers,age[4];
  char name[4][25],address[100],requiredfrom[50],requiredto[50],requiredflightno[50],requireddate[50],gender[4][10];
  long customerno,phoneno;
  time_t ptime;

  public:
     char* returnrequiredfrom()    { return requiredfrom;    }
     char* returnrequiredto()      { return requiredto;      }
     char* returnrequiredflightno(){ return requiredflightno;}
     char* returnrequireddate()    { return requireddate;    }
      long returncustomerno()      { return customerno;      }
      long returnphoneno()         { return phoneno;         }
       int returnnoofpassengers()  { return noofpassengers;  }
       int returnrequiredclass()   { return requiredclass;   }

       int coordinates(int,int,int*);

      void entercustomerno()
      {
	 setbkcolor(9);
	 settextstyle(2,0,5);
	 setcolor(1);
	 setfillstyle(1,15);
	 show10(customerno,205,100);
	 setcolor(15);
      }
      void displayticket();
      void readcustomer(int*);

       void enterrequiredflightno(char* tflnm);
       void assign(int x)
       {
	  if(!x) customerno=0;
	  else
	  {
	    randomize();
	    customerno=99*(random(255)+1);
	  }
	  ptime=time(NULL);
       }

       void selection();

       char* displayflights(int);
}oc;

void customer :: enterrequiredflightno(char* tflnm)
       {
	  for(int i=0;i<50;i++)
	  requiredflightno[i]='\0';
	  strcat(requiredflightno,requireddate);
	  strcat(requiredflightno,tflnm);
       }


char* customer::displayflights(int i)
       {
	  ob.createflightno(1);
	  char at[10],dt[10],ch1[10],ch2[10],ch3[10];
	  for(int j=0;j<10;j++)
	  {
	    at[i] ='\0';
	    dt[i] ='\0';
	    ch1[i]='\0';
	    ch2[i]='\0';
	    ch3[i]='\0';
	  }
	  setcolor(1);
	  rectangle(10,50+i*60,620,100+i*60);
	  floodfill(11,51+i*60,1);
	  char *tflnm;
	  tflnm=oa.returnflightname();
	  outtextxy(15,60+i*60,tflnm);
	  sprintf(dt,"%ld",oa.returndepttime());
	  sprintf(at,"%ld",oa.returnarrtime());
	  sprintf(ch1,"%ld",oa.returncharge()[0]);
	  sprintf(ch2,"%ld",oa.returncharge()[1]);
	  sprintf(ch3,"%ld",oa.returncharge()[2]);
	  outtextxy(150,60+i*60,dt);
	  outtextxy(300,60+i*60,at);
	  outtextxy(400,60+i*60,ch3);
	  outtextxy(450,60+i*60,ch2);
	  outtextxy(550,60+i*60,ch1);
	  return tflnm;
       }

class enter
{
   int noofairports,traveltime;
   char airport[20][50];
   long rate;

   public:
	long returnrate()             { return rate;         }
	int returntraveltime()        { return traveltime;   }
	int returnnoofairports()      { return noofairports; }
	char(* returnairport())[50]   { return airport;      }

	void enterairports();
	void enterrate();
	void disp();

}oe;

void box()
{
	rectangle(1,1,635,475);
	rectangle(2,2,634,474);
	rectangle(3,3,633,473);
}

void loading()
{
   settextstyle(2,0,5);
   for(int i=0;i<=720;++i)
      {
	 setcolor(2);
	 for(int j=0;j<4;j++)
	 arc(300,300,i-120,i,35-j);
	 delay(10);
	 setcolor(0);
	 for(j=0;j<4;j++)
	 arc(300,300,i-120,i,35-j);
	 setcolor(4);
	 outtextxy(273,295,"Loading");
      }
}

void company()
{
  int gdriver = DETECT ,gmode;
  initgraph(&gdriver, &gmode, "C:\\TurboC3\\BGI");
  setcolor(11);
  settextstyle(2,0,7);

  for(int j=0;j<5;j++)
  for(int i=0;i<14;i++)
   {
      setfillstyle(1,i);
      outtextxy(100,400,"ACCESSING COMPANY DATABASE");
      setcolor(15);
      line(0,380,getmaxx(),380);
      floodfill(0,0,15);
      delay(100);
   }
   cleardevice();
   j=3;
   char pass[9]="password",id[5]="user",pin[15],usr[15];
   setcolor(11);
   setbkcolor(BLACK);
   time_t ptime;
begin:
   setcolor(11);
   settextstyle(2,0,5);

   box();
   ptime=time(NULL);
   outtextxy(420,10,ctime(&ptime));
   gotoxy(36,12);
   outtextxy(190,175," Username :");
   gets(usr);
   gotoxy(36,13);
   outtextxy(198,191,"Password :");
   for(i=0;;i++)
   {
      pin[i]=getch();
      if(pin[i]==13)break;
      cout<<"*";
   }
   pin[i]='\0';
   if(strcmpi(pass,pin)==0&&strcmpi(id,usr)==0)
   {
     textcolor(11);
     outtextxy(240,220,"Access Granted!");
     delay(1000);
     loading();
     cleardevice();
     outtextxy(420,10,ctime(&ptime));
     setcolor(11);
     settextstyle(2,0,20);
     outtextxy(150,200,"Login Successfull");
     outtextxy(20,250,"Ready To Modify Database");
     getch();
     closegraph();
     oa.update();
   }
   else
   {
     if(j>0)
     {
       outtextxy(8,240,"INCORRECT USERNAME OR PASSWORD");
       gotoxy(2,17);
       cout<<"You have "<<j<<" tries left";
       delay(1000);
       j--;
       cleardevice();
     }
     else if(!j)
     {
       outtextxy(145,420,"Something went wrong.Please try again later");
       getch();
       exit(0);
     }
     goto begin;
   }
   closegraph();
}



union REGS in,out;
int callmouse()
{
  in.x.ax=1;
  int86(51,&in,&out);
  return 1;
}
void mouseposi(int &xpos,int &ypos,int &click)
{
  in.x.ax=3;
  int86(51,&in,&out);
  click=out.x.bx;
  xpos=out.x.cx;
  ypos=out.x.dx;
}
int mousehide()
{
  in.x.ax=2;
  int86(51,&in,&out);
  return 1;
}
void setposi(int &xpos,int &ypos)
{
  in.x.ax=4;
  in.x.cx=xpos;
  in.x.dx=ypos;
  int86(51,&in,&out);
}

void load()
{
  int gd=DETECT,gm;
  initgraph(&gd,&gm,"C:\\TurboC3\\BGI");

  int j=-50;
  int k,l;
  setbkcolor(15);
  settextstyle(3,0,1);
  setcolor(8);
  for(int p=0;p<6;p++)
  {
    if(p==0){k=200;l=450;}
    if(p==1){k=400;l=0;}
    if(p==2){k=200;l=200;}
    if(p==3){k=400;l=400;}
    if(p==4){k=100;l=10;}
    if(p==5){k=0;l=100;}
    setfillstyle(1,YELLOW);
    circle(350,120,17);
    floodfill(350,120,8);
    setfillstyle(1,11);
    arc(52+k,40+l,150,320,10);
    arc(70+k,45+l,150,350,10);
    arc(87+k,40+l,180,350,10);
    arc(42+k,30+l,75,270,10);
    arc(102+k,35+l,220,70,10);
    arc(102+k,20+l,320,140,10);
    arc(52+k,20+l,0,180,10);
    arc(70+k,20+l,0,150,10);
    arc(85+k,18+l,0,150,10);
    floodfill(85+k,18+l,8);
  }
  settextstyle(7,0,4);
  setcolor(BLUE);
  outtextxy(100,5,"Welcome To EMIRATES");
  outtextxy(130,50,"online booking portal");
  settextstyle(2,0,7);
  setcolor(8);
  for(int i=-250;i<700;i=i+3)
  {
    for(int z=0;z<2;z++)
    {
      if(z==0) setcolor(4);
      if(z==1) setcolor(15);
      outtextxy(100+i,448-j,"EMIRATES");
      if(z==0) setcolor(8);
      line(0+i,440-j,220+i,440-j);          //top
      line(50+i,470-j,133+i,470-j);         //bottom
      line(173+i,470-j,220+i,470-j);        //bottom
      line(50+i,470-j,0+i,440-j);           //left
      line(220+i,470-j,270+i,455-j);        //bottom right
      line(220+i,440-j,270+i,455-j);        //top right
      line(20+i,445-j,220+i,445-j);         //top window
      line(33+i,450-j,235+i,450-j);         //bottom window
      line(20+i,445-j,33+i,450-j);          //left window
      line(220+i,445-j,235+i,450-j);        //right window
      line(180+i,440-j,100+i,400-j);        //top right wing
      line(140+i,440-j,60+i,400-j);         //top left wing
      line(100+i,400-j,60+i,400-j);         //top top wing
      line(185+i,460-j,120+i,520-j);        //bottom right wing
      line(145+i,460-j,80+i,520-j);         //bottom left wing
      line(120+i,520-j,80+i,520-j);         //bottom bottom wing
      arc(52+i,400-j,210,270,40);           //bottom tail
      arc(-20+i,435-j,20,90,40);            //top tail
      line(0+i,440-j,-20+i,395-j);          //tail
      sound(j+200);
      delay(10);
      nosound();
    }
    j++;
  }
  closegraph();
}

void clickeffect(int x,int y)
{
	settextstyle(2,0,5);
	setcolor(15);
	outtextxy(300,450,"please wait");
	sound(300);
	mousehide();
	setfillstyle(1,7);
	floodfill(x,y,1);
	callmouse();
	delay(100);
	nosound();
	delay(500);
	mousehide();
	setfillstyle(1,15);
	floodfill(x,y,1);
	callmouse();
	setcolor(1);
}

int coordinatew(int x,int y)
{
  int a,z=1;
  char b[2];
  for(int i=1;i<3;i++)
  {
    for(int j=1;j<3;j++)
    {
      a=0;
      if(x>((i*250)-150))
      if(y>((j*150)-50))
      if(x<(50+(i*250)))
      if(y<(50+(j*150)))
      {
	a=1;
	clickeffect(45+(i*250),45+(j*150));
	sleep(1);
	return z;
      }
      if(!a) z++;
    }
  }
  if(!a) z=0;
  return z;
}

int coordinatecn(int x,int y)
{
   int z=1,a=0;
   for(int i=0;i<4;i++)
   {
      if(x>(300+i*63))
      if(y>223)
      if(x<(363+i*63))
      if(y<243)
      {
	a=1;
	clickeffect((301+i*63),225);
      }
      if(!a)   z++;
   }
   if(!a) z=0;
   return z;
}

int coordinateca(int x,int y)
{
   int z=1,a=0,k=1;
   for(int i=0;i<5;i++)
   for(int j=0;j<7;j++)
   {
     if(k<32)
     {
	    if(x>(300+j*25))
	    if(y>(275+i*25))
	    if(x<(325+j*25))
	    if(y<(295+i*25))
	    {
	      a=1;
	      clickeffect((301+j*25),(276+i*25));
	    }
	    if(!a)   z++;
	    k++;
     }
   }
   if(!a) z=0;
   return z;
}

int coordinatecam(int x,int y)
{
   int z=1,a=0;
   for(int i=0;i<6;i++)
   for(int j=0;j<2;j++)
   {
      if(x>(340+j*90))
      if(y>(275+i*20))
      if(x<(430+j*90))
      if(y<(295+i*20))
      {
	 a=1;
	 clickeffect((341+j*90),(276+i*20));
      }
      if(!a)  z++;
   }
   if(!a) z=0;
   return z;
}

int coordinatecay(int x,int y)
{
   int a=0,z=1;
   for(int i=0;i<5;i++)
   {
      if(x>500)
      if(y>(275+i*20))
      if(x<550)
      if(y<(295+i*20))
      {
	a=1;
	clickeffect(501,(276+i*20));
      }
      if(!a)  z++;
   }
   if(!a) z=0;
   return z;
}

int coordinatef(int x,int y,int s)
{
   int z=1,a=0;
   if(s==1)
   for(int i=0;i<oe.returnnoofairports();i++)
   {
      if(x>555)
      if(y>(60+i*20))
      if(x<(getmaxx()-2))
      if(y<(80+i*20))
      {
	a=1;
	clickeffect(556,(61+i*20));
      }
      if(!a)   z++;
   }
   if(s==2)
   for(int i=0;i<oe.returnnoofairports();i++)
   {
      if(x>555)
      if(y>(80+i*20))
      if(x<(getmaxx()-2))
      if(y<(100+i*20))
      {
	a=1;
	clickeffect(556,(81+i*20));
      }
      if(!a)   z++;
   }
   if(!a)   z=0;
   return z;
}

int customer::coordinates(int x,int y,int *cntrl)
{
   int z=1,a=0,d;
   char c[5];
   for(int i=0;i<3;i++)
   {
      if(x>300)
      if(y>(100+i*50))
      if(x<550)
      if(y<(120+i*50))
	a=1;
      if(!a)   z++;
   }
   if(!a)
   for(i=0;i<3;i++)
   {
     if(x>300+i*100)
     if(y>250)
     if(x<350+i*100)
     if(y<270)
	  a=1;
     if(!a) z++;
    }
    if(!a)
    {
      if(x>(getmaxx()-100))
      if(y>(getmaxy()-25))
      if(x<(getmaxx()-5))
      if(y<(getmaxy()-5))
	a=1;
      if(!a) z++;
    }
    if(a)
    {
      setcolor(1);
      setfillstyle(1,15);
      if(z==1)
      {
	cntrl[z-1]=1;
	int cl=0;
	fstream e;
	e.open("base",ios::in|ios::out|ios::binary);
	e.read((char*)&oe,sizeof(oe));
	e.close();
	char (*stations)[50]=oe.returnairport();
	mousehide();
	for(i=0;i<oe.returnnoofairports();i++)
	{
	    rectangle(555,60+i*20,getmaxx()-2,80+i*20);
	    floodfill(556,61+i*20,1);
	    outtextxy(560,60+i*20,stations[i]);
	}
	callmouse();
	do
	{
	  mouseposi(x,y,cl);
	  char a[2];
	  if(cl==1)
	  {
	    mousehide();
	    a[0]=char(219);
	    setcolor(15);
	    for(i=0;i<70;i++)
	    for(int j=0;j<5;j++)
	    outtextxy(350+i,102+j,a);
	    setcolor(1);
	    callmouse();
	    d=coordinatef(x,y,1);
	    if(d)
	    {
	      strcpy(requiredfrom,stations[d-1]);
	      outtextxy(350,102,requiredfrom);
	      setcolor(15);
	      outtextxy(300,450,"please wait");
	      delay(500);
	      setcolor(9);
	      setfillstyle(1,9);
	      mousehide();
	      setcolor(9);
	      setfillstyle(1,9);
	      for(i=0;i<oe.returnnoofairports();i++)
	      {
		 outtextxy(560,60+i*20,stations[i]);
		 floodfill(556,61+i*20,1);
	      }
	      for(i=0;i<oe.returnnoofairports();i++)
		rectangle(555,60+i*20,getmaxx()-2,80+i*20);
	      callmouse();
	      outtextxy(300,450,"please wait");
	      setcolor(15);
	      break;
	    }
	  }
	}while(1);
      }
      if(z==2)
      {
	cntrl[z-1]=1;
	int cl=0;
	fstream e;
	e.open("base",ios::in|ios::out|ios::binary);
	e.read((char*)&oe,sizeof(oe));
	e.close();
	char (*stations)[50]=oe.returnairport();
	mousehide();
	for(i=0;i<oe.returnnoofairports();i++)
	{
	    rectangle(555,80+i*20,getmaxx()-2,100+i*20);
	    floodfill(556,81+i*20,1);
	    outtextxy(560,80+i*20,stations[i]);
	}
	callmouse();
	do
	{
	  mouseposi(x,y,cl);
	  char a[2];
	  if(cl==1)
	  {
	      mousehide();
	      a[0]=char(219);
	      setcolor(15);
	      for(i=0;i<70;i++)
	      for(int j=0;j<5;j++)
	      outtextxy(350+i,152+j,a);
	      setcolor(1);
	      callmouse();

	    d=coordinatef(x,y,2);
	    if(d)
	    {
	      strcpy(requiredto,stations[d-1]);
	      outtextxy(350,152,requiredto);
	      setcolor(15);
	      outtextxy(300,450,"please wait");
	      delay(500);
	      setcolor(9);
	      setfillstyle(1,9);
	      mousehide();
	      setcolor(9);
	      setfillstyle(1,9);
	      for(i=0;i<oe.returnnoofairports();i++)
	      {
		 outtextxy(560,80+i*20,stations[i]);
		 floodfill(556,81+i*20,1);
	      }
	      for(i=0;i<oe.returnnoofairports();i++)
		rectangle(555,80+i*20,getmaxx()-2,100+i*20);
	      callmouse();
	      outtextxy(300,450,"please wait");
	      setcolor(15);
	      break;
	    }
	  }
	}while(1);
      }

      if(z==3)
      {
	cntrl[z-1]=1;
	mousehide();
	for(i=0;i<4;i++)
	{
	  rectangle(300+i*63,223,363+i*63,243);      //no of customers
	  floodfill(305+i*62,230,1);
	  sprintf(c,"%d",i+1);
	  outtextxy(350+i*63,223,c);
	}
	callmouse();
	int cl=0;
	do
	{
	  cl=0;
	  mouseposi(x,y,cl);
	  if(cl==1)
	  {
	    c[0]=char(219);
	    setcolor(15);
	    outtextxy(340,202,c);
	    outtextxy(341,202,c);
	    setcolor(1);
	    d=coordinatecn(x,y);
	    if(d)
	    {
	      noofpassengers=d;
	      sprintf(c,"%d",noofpassengers);
	      outtextxy(340,202,c);
	      setcolor(15);
	      outtextxy(300,450,"please wait");
	      delay(500);
	      setcolor(9);
	      setfillstyle(1,9);
	      mousehide();
	      d++;
	      for(i=0;i<4;i++)
	      { 				      //no of customers
		 sprintf(c,"%d",i+1);
		 outtextxy(350+i*63,223,c);
		 floodfill(304+i*62,230,1);
	      }
	      for(i=0;i<4;i++)
	      {
		 rectangle(300+i*63,223,363+i*63,243);
	      }
	      callmouse();
	      outtextxy(300,450,"please wait");
	      setcolor(15);
	      break;
	    }
	  }
	}while(1);
      }
      if(z==4)
      {
	cntrl[z-1]=1;
	int k=1;
	mousehide();
	for(i=0;i<5;i++)
	for(int j=0;j<7;j++)
	{
	  if(k<32)
	  {
	    rectangle(300+j*25,275+i*25,325+j*25,295+i*25);
	    floodfill(310+j*25,276+i*25,1);
	    sprintf(c,"%d",k);
	    outtextxy(305+j*25,280+i*25,c);
	    k++;
	  }
	}
	callmouse();
	int cl;
	do
	{
	  cl=0;
	  mouseposi(x,y,cl);
	  if(cl==1)
	  {
	    c[0]=char(219);
	    setcolor(15);
	    for(i=0;i<10;i++)
	    outtextxy(310+i,252,c);
	    setcolor(1);
	    d=coordinateca(x,y);
	    if(d)
	    {
	      char c3[3];
	      sprintf(c3,"%d",d);
	      sprintf(requireddate,"%d",d);
	      if(d<10)
	      {
		requireddate[1]=requireddate[0];
		requireddate[0]='0';
	      }
	      outtextxy(310,252,c3);
	      setcolor(15);
	      outtextxy(300,450,"please wait");
	      delay(500);
	      setcolor(9);
	      setfillstyle(1,9);
	      mousehide();
	      int k=1;
	      setcolor(9);
	      setfillstyle(1,9);
	      for(i=0;i<5;i++)
	      for(int j=0;j<7;j++)
	      {
		if(k<32)
		{
		  sprintf(c,"%d",k);
		  outtextxy(305+j*25,280+i*25,c);
		  floodfill(310+j*25,276+i*25,1);
		  k++;
		}
	      }
	      setcolor(9);
	      k=0;
	      for(i=0;i<5;i++)
	      for(j=0;j<7;j++)
	      {
		if(k<32)
		{
		  rectangle(300+j*25,275+i*25,325+j*25,295+i*25);
		  k++;
		}
	      }
	      callmouse();
	      outtextxy(300,450,"please wait");
	      setcolor(15);
	      break;
	    }
	  }
	}while(1);
      }
      if(z==5)
      {
	cntrl[z-1]=1;
	int cl=0;
	int k=1;
	char c9[20];
	mousehide();
	for(i=0;i<6;i++)
	for(int j=0;j<2;j++)
	{
	    rectangle(340+j*90,275+i*20,430+j*90,295+i*20);
	    floodfill(341+j*90,276+i*20,1);
	    switch(k)
	    {
	      case 1 :strcpy(c9,"january");break;
	      case 2 :strcpy(c9,"february");break;
	      case 3 :strcpy(c9,"march");break;
	      case 4 :strcpy(c9,"april");break;
	      case 5 :strcpy(c9,"may");break;
	      case 6 :strcpy(c9,"june");break;
	      case 7 :strcpy(c9,"july");break;
	      case 8 :strcpy(c9,"august");break;
	      case 9 :strcpy(c9,"september");break;
	      case 10:strcpy(c9,"october");break;
	      case 11:strcpy(c9,"november");break;
	      case 12:strcpy(c9,"december");break;
	    }
	    outtextxy(348+j*100,275+i*20,c9);
	    k++;
	}
	callmouse();
	do
	{
	  mouseposi(x,y,cl);
	  char a[2];
	  if(cl==1)
	  {
	    mousehide();
	    a[0]=char(219);
	    setcolor(15);
	    for(i=0;i<30;i++)
	    for(int j=0;j<5;j++)
	    outtextxy(405+i,252+j,a);
	    setcolor(1);
	    callmouse();
	    d=coordinatecam(x,y);
	    if(d)
	    {
	      char c1[3];
	      sprintf(c1,"%d",d);
	      if(d<10)
	      {
		requireddate[2]='0';
		requireddate[3]=c1[0];
	      }
	      if(d>9)
	      {
		requireddate[2]=c1[0];
		requireddate[3]=c1[1];
	      }
	      switch(d)
	      {
		case 1 :strcpy(c1,"jan");break;
		case 2 :strcpy(c1,"feb");break;
		case 3 :strcpy(c1,"mar");break;
		case 4 :strcpy(c1,"apr");break;
		case 5 :strcpy(c1,"may");break;
		case 6 :strcpy(c1,"jun");break;
		case 7 :strcpy(c1,"jul");break;
		case 8 :strcpy(c1,"aug");break;
		case 9 :strcpy(c1,"sep");break;
		case 10:strcpy(c1,"oct");break;
		case 11:strcpy(c1,"nov");break;
		case 12:strcpy(c1,"dec");break;
	      }

	      outtextxy(410,252,c1);
	      setcolor(15);
	      outtextxy(300,450,"please wait");
	      delay(500);
	      setfillstyle(1,9);
	      mousehide();
	      setcolor(9);
	      setfillstyle(1,9);
	      int k=1;
	      for(i=0;i<6;i++)
	      for(int j=0;j<2;j++)
	      {
		 switch(k)
		 {
		    case 1 :strcpy(c9,"january");break;
		    case 2 :strcpy(c9,"february");break;
		    case 3 :strcpy(c9,"march");break;
		    case 4 :strcpy(c9,"april");break;
		    case 5 :strcpy(c9,"may");break;
		    case 6 :strcpy(c9,"june");break;
		    case 7 :strcpy(c9,"july");break;
		    case 8 :strcpy(c9,"august");break;
		    case 9 :strcpy(c9,"september");break;
		    case 10:strcpy(c9,"october");break;
		    case 11:strcpy(c9,"november");break;
		    case 12:strcpy(c9,"december");break;
		 }
		 outtextxy(348+j*100,275+i*20,c9);
		 floodfill(341+j*90,276+i*20,1);
		 k++;
	      }
	      for(i=0;i<6;i++)
	      for(j=0;j<2;j++)
		rectangle(340+j*90,275+i*20,430+j*90,295+i*20);
	      callmouse();
	      outtextxy(300,450,"please wait");
	      setcolor(15);
	      break;
	    }
	  }
	}while(1);
      }
      if(z==6)
      {
	cntrl[z-1]=1;
	mousehide();
	for(i=0;i<5;i++)
	{
	    rectangle(500,275+i*20,550,295+i*20);
	    floodfill(501,276+i*20,1);
	    sprintf(c,"%d",i+2016);
	    outtextxy(510,278+i*20,c);
	}
	callmouse();
	int cl=0;
	do
	{
	  cl=0;
	  mouseposi(x,y,cl);
	  if(cl==1)
	  {
	      c[0]=char(219);
	      mousehide();
	      setcolor(15);
	      for(i=0;i<10;i++)
	      outtextxy(510+i,252,c);
	      callmouse();
	      setcolor(1);

	    d=coordinatecay(x,y);
	    if(d)
	    {
	      char a[8];
	      sprintf(a,"%d",d+2015);
	      for(i=4;i<8;i++)
		requireddate[i]=a[i-4];
	      outtextxy(510,252,a);
	      setcolor(15);
	      outtextxy(300,450,"please wait");
	      delay(500);
	      setcolor(9);
	      setfillstyle(1,9);
	      mousehide();
	      for(i=0;i<5;i++)
	      {
		 sprintf(c,"%d",i+2016);
		 outtextxy(510,278+i*20,c);
		 floodfill(501,276+i*20,1);
	      }
	      for(i=0;i<5;i++)
		 rectangle(500,275+i*20,550,295+i*20);
	      callmouse();
	      outtextxy(300,450,"please wait");
	      setcolor(15);
	      break;
	    }
	  }
	}while(1);
      }
      a=0;
      for(i=0;i<10;i++)
	if(cntrl[i]==1) a++;
      setfillstyle(1,15);
      setcolor(1);
      if(a==6)
      {
	 rectangle(getmaxx()-100,getmaxy()-25,getmaxx()-5,getmaxy()-5);
	 floodfill(getmaxx()-10,getmaxy()-10,1);
	 for(i=0;i<3;i++)
	 outtextxy(getmaxx()-92+i,getmaxy()-22,"S U B M I T");
	 if(z==7) return 1;
      }
   }
   return 0;
}

int lockcoordinate10(int x,int y)
{
     if(x>0)
     if(y>200)
     if(x<50)
     if(y<250)
	return 1;
     return 0;
}
int lockcoordinate9(int x,int y)
{
   int d=0;
     if(x>300)
     if(y>200)
     if(x<350)
     if(y<250)
     do
   {
     int cl=0;
     mouseposi(x,y,cl);
     if(cl==1)
     d=lockcoordinate10(x,y);
     if(d)
      return 1;
   }while(!d);
   return 0;
}
int lockcoordinate8(int x,int y)
{
   int d=0;
     if(x>600)
     if(y>200)
     if(x<650)
     if(y<250)
     do
   {
     int cl=0;
     mouseposi(x,y,cl);
     if(cl==1)
     d=lockcoordinate9(x,y);
     if(d)
      return 1;
   }while(!d);
   return 0;
}


int lockcoordinate7(int x,int y)
{
   int d=0;
     if(x>600)
     if(y>370)
     if(x<650)
     if(y<450)
     do
   {
     int cl=0;
     mouseposi(x,y,cl);
     if(cl==1)
     d=lockcoordinate8(x,y);
     if(d)
      return 1;
   }while(!d);
   return 0;
}

int lockcoordinate6(int x,int y)
{
   int d=0;
     if(x>300)
     if(y>370)
     if(x<350)
     if(y<420)
     do
   {
     int cl=0;
     mouseposi(x,y,cl);
     if(cl==1)
     d=lockcoordinate7(x,y);
     if(d)
      return 1;
   }while(!d);
   return 0;
}

int lockcoordinate5(int x,int y)
{
   int d=0;
     if(x>0)
     if(y>370)
     if(x<50)
     if(y<450)
     do
   {
     int cl=0;
     mouseposi(x,y,cl);
     if(cl==1)
     d=lockcoordinate6(x,y);
     if(d)
      return 1;
   }while(!d);
   return 0;
}

int lockcoordinate4(int x,int y)
{
   int d=0;
     if(x>0)
     if(y>200)
     if(x<50)
     if(y<250)
     do
   {
     int cl=0;
     mouseposi(x,y,cl);
     if(cl==1)
     d=lockcoordinate5(x,y);
     if(d)
      return 1;
   }while(!d);
   return 0;
}

int lockcoordinate3(int x,int y)
{
   int d=0;
     if(x>0)
     if(y>20)
     if(x<50)
     if(y<100)
     do
   {
     int cl=0;
     mouseposi(x,y,cl);
     if(cl==1)
     d=lockcoordinate4(x,y);
     if(d)
      return 1;
   }while(!d);
   return 0;
}

int lockcoordinate2(int x,int y)
{
   int d=0;
     if(x>300)
     if(y>20)
     if(x<350)
     if(y<100)
     do
     {
       int cl=0;
       mouseposi(x,y,cl);
       if(cl==1)
       d=lockcoordinate3(x,y);
       if(d)
	 return 1;
     }while(!d);
   return 0;
}

int lockcoordinate1(int x,int y)
{
   int d=0;
   if(x>600)
   if(y>20)
   if(x<650)
   if(y<100)
   do
   {
     int cl=0;
     mouseposi(x,y,cl);
     if(cl==1)
     d=lockcoordinate2(x,y);
     if(d)
      return 1;
   }while(!d);
   return 0;
}

int welcome()
{
  int gd=DETECT,gm;
  initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
  cleardevice();

    int x=10,y=100,cl;
  begin:
    setposi(x,y);
    callmouse();
    setbkcolor(9);
    setcolor(14);
    settextstyle(2,0,7);
    outtextxy(0,0,"Welcome To EMIRATES Online Booking Portal");
    setcolor(4);
    for(int i=1;i<3;i++)
    for(int j=1;j<3;j++)
    {
      for(int k=10;k;k=k-2)
      {
	if(k==2) setcolor(1);
	else setcolor(4);
	rectangle((i*250)-150-k,(j*150)-50+k,50+(i*250)-k,50+(j*150)+k);
      }
      setfillstyle(1,15);
      floodfill((i*250),(j*150),1);
    }
    setcolor(1);
    for(i=0;i<getmaxx();i++)
    outtextxy(i,10,"-");
    for(i=0;i<3;i++)
    {
      outtextxy(20+i*300,50,".");
      outtextxy(20+i*300,220,".");
      outtextxy(20+i*300,400,".");
    }
    settextstyle(2,0,10);
    for(int k=5;k;k--)
    {
      if(k<4) setcolor(1);
      else setcolor(9);
      outtextxy(150-k,120+k,"BOOK");
      outtextxy(390-k,120+k,"CANCEL");
      outtextxy(130-k,270+k,"TICKET");
      outtextxy(400-k,270+k,"EXIT");
    }
    int d=0;
    do
    {
      cl=0;
      mouseposi(x,y,cl);
      if(cl==1)
      {
	if(lockcoordinate1(x,y))
	{
	   getch();
	   break;
	}
	else
	{
	  d=coordinatew(x,y);
	  setcolor(9);
	  outtextxy(300,450,"please wait");
	  setcolor(15);
	}
      }
    }while(!d);
    mousehide();
    closegraph();
    return d;
}

int coordinate(int x,int y,int *bs)
{
  int s=1;
  for(int i=14;i<17;i++)                                      //first class
  for(int j=1;j<5;j++)
  {
    if(x>(10+(30*i)))
    if(y>(70+(45*j)))
    if(x<(25+(30*i)))
    if(y<(100+(45*j)))
    {
      int z=0;
      for(int k=0;k<100;k++)if(bs[k]==s)z=1;
      if(!z)    return s;
    }
    s++;
  }
  for(i=11;i<19;i++)                                     //bussiness up
  for(j=1;j<3;j++)
  {
    if(x>(10+(20*i)))
    if(y>(80+(j*35)))
    if(x<(25+(20*i)))
    if(y<(105+(j*35)))
    {
      int z=0;
      for(int k=0;k<100;k++)if(bs[k]==s)z=1;
      if(!z)    return s;
    }
    s++;
  }
  for(i=11;i<19;i++)                                    //bussiness down
  for(j=3;j<5;j++)
  {
    if(x>(10+(20*i)))
    if(y>(120+(j*35)))
    if(x<(25+(20*i)))
    if(y<(145+(j*35)))
    {
      int z=0;
      for(int k=0;k<100;k++)if(bs[k]==s)z=1;
      if(!z)    return s;
    }
    s++;
  }
  for(i=1;i<10;i++)                                   //economic up
  for(j=1;j<4;j++)
  {
    if(x>(10+(20*i)))
    if(y>(80+(j*25)))
    if(x<(25+(20*i)))
    if(y<(100+(j*25)))
    {
      int z=0;
      for(int k=0;k<100;k++)if(bs[k]==s)z=1;
      if(!z)    return s;
    }
    s++;
  }
  for(i=1;i<10;i++)                                      //economic down
  for(j=4;j<7;j++)
  {
    if(x>(10+(20*i)))
    if(y>(120+(j*25)))
    if(x<(25+(20*i)))
    if(y<(140+(j*25)))
    {
      int z=0;
      for(int k=0;k<100;k++)if(bs[k]==s)z=1;
      if(!z)    return s;
    }
    s++;
  }
  return 0;
}

void display(int *bs)
{
  int s=1,y=0;
  char a[5];
  setcolor(15);
  setfillstyle(1,4);
  for(int i=14;i<17;i++)                                      //first class
  for(int j=1;j<5;j++)
  {
    rectangle(10+(30*i),70+(j*45),25+(30*i),100+(j*45));
    floodfill(11+(30*i),71+(j*45),15);
    setcolor(1);
    sprintf(a,"%d",s);
    outtextxy(12+i*30,77+j*45,a);
    y=0;
    for(int k=0;k<100;k++)if(bs[k]==s)y=1;
    if(y) outtextxy(12+i*30,77+j*45,"±");
    s++;
    setcolor(15);
  }
  setfillstyle(1,2);
  for(i=11;i<19;i++)                                     //bussiness up
  for(j=1;j<3;j++)
  {
    rectangle(10+(20*i),80+(j*35),25+(20*i),105+(j*35));
    floodfill(11+(20*i),81+(j*35),15);
    y=0;
    for(int k=0;k<100;k++)if(bs[k]==s)y=1;
    if(y) outtextxy(12+i*20,85+j*35,"±");
    sprintf(a,"%d",s);
    setcolor(1);
    outtextxy(12+i*20,85+j*35,a);
    s++;
    setcolor(15);
  }
  for(i=11;i<19;i++)                                    //bussiness down
  for(j=3;j<5;j++)
  {
    rectangle(10+(20*i),120+(j*35),25+(20*i),145+(j*35));
    floodfill(11+(20*i),121+(j*35),15);
    y=0;
    for(int k=0;k<100;k++)if(bs[k]==s)y=1;
    if(y) outtextxy(12+i*20,125+j*35,"±");
    sprintf(a,"%d",s);
    setcolor(1);
    outtextxy(12+i*20,125+j*35,a);
    s++;
    setcolor(15);
  }
  setfillstyle(1,15);
  for(i=1;i<10;i++)                                   //economic up
  for(j=1;j<4;j++)
  {
    rectangle(10+(20*i),80+(j*25),25+(20*i),100+(j*25));
    floodfill(11+(20*i),81+(j*25),15);
    y=0;
    for(int k=0;k<100;k++)if(bs[k]==s)y=1;
    setcolor(4);
    if(y)  outtextxy(12+i*20,85+j*25,"±");
    sprintf(a,"%d",s);
    setcolor(1);
    outtextxy(12+i*20,85+j*25,a);
    s++;
    setcolor(15);
  }
  for(i=1;i<10;i++)                                      //economic down
  for(j=4;j<7;j++)
  {
    rectangle(10+(20*i),120+(j*25),25+(20*i),140+(j*25));
    floodfill(11+(20*i),121+(j*25),15);
    y=0;
    for(int k=0;k<100;k++)if(bs[k]==s)y=1;
    setcolor(4);
    if(y) outtextxy(12+i*20,125+j*25,"±");
    sprintf(a,"%d",s);
    setcolor(1);
    outtextxy(12+i*20,125+j*25,a);
    s++;
    setcolor(15);
  }
  setfillstyle(1,9);
  floodfill(getmaxx(),getmaxy(),15);
  floodfill(0,0,15);
  floodfill(getmaxx(),0,15);
  floodfill(0,getmaxy(),15);
  setcolor(1);
  setfillstyle(1,15);
}

void seatsavailable(int *s)
{
  int x,y,cl,a1,b;
  cleardevice();
  setbkcolor(0);
  a1=300;
  b=0;
  setcolor(15);
  setposi(a1,b);
  callmouse();
  settextstyle(3,0,3);
  outtextxy(30,180,"economic class");
  outtextxy(230,180,"bussiness class");
  settextstyle(3,0,2);
  outtextxy(530,180,"FIRST");
  outtextxy(530,200,"CLASS");
  settextstyle(2,0,4);
  line(25,100,500,100);     //top
  line(25,300,500,300);     //bottom
  arc(200,200,149,211,200); //left
  line(500,100,640,200);
  line(230,0,250,100);
  line(380,0,400,100);
  line(230,getmaxy(),250,300);
  line(380,getmaxy(),400,300);
  line(500,300,640,200);
  rectangle(210,98,230,102);
  rectangle(210,302,230,298);
  rectangle(400,302,420,298);
  rectangle(400,98,420,102);
  display(s);
   int d=0,seats[4],i=0;
   char c[3];
   do
   {
     cl=0;
     mouseposi(x,y,cl);
     if(cl==1)
     {
	d=coordinate(x,y,s);
	if(d)
	{
	  if(i<oc.returnnoofpassengers())
	  {
	    seats[i]=d;
	    settextstyle(2,0,5);
	    setcolor(15);
	    outtextxy(100,400,"SEATS SELECTED");
	    sprintf(c,"%d",d);
	    outtextxy(100,410+i*10,c);
	    outtextxy(300,450,"please wait");
	    delay(500);
	    setcolor(0);
	    outtextxy(300,450,"please wait");
	    setcolor(15);
	    i++;
	  }
	}
     }
     if(i==oc.returnnoofpassengers())  break;
   }while(1);
   mousehide();
   ob.enterseatno(seats);
}

void bkflight()
{
   cleardevice();
   setbkcolor(9);
   settextstyle(2,0,5);
   setcolor(15);
   outtextxy(10,10,"FLIGHT NAME");
   outtextxy(150,10,"Dept Time");
   outtextxy(300,10,"Arr Time");
   outtextxy(460,10,"RATE");
   outtextxy(400,30,"First");
   outtextxy(450,30,"Bussiness");
   outtextxy(550,30,"Economic");
}

int coordinatefs(int x,int y,int j)
{
   int z=1;
   for(int i=0;i<j;i++)
   {
      if(x>10)
      if(y>50+i*60)
      if(x<620)
      if(y<100+i*60)
	return z;
      z++;
   }
   return 0;
}

void bank()
{
   cleardevice();
   setbkcolor(0);
   setcolor(11);
   settextstyle(2,0,7);
   outtextxy(100,100,"REDIRECTING to BANK...");
   loading();
   cleardevice();
   settextstyle(2,0,7);
   setcolor(11);
   outtextxy(100,100,"ENTER OTP CODE...");
   for(int i=0;i<5;i++)
   {
     outtextxy(100+i*10,150,"*");
     delay(200);
   }
   loading();
   cleardevice();
   settextstyle(2,0,7);
   setcolor(11);
   outtextxy(100,100,"MATCH FOUND");
   delay(1000);
   cleardevice();
   settextstyle(2,0,7);
   setcolor(11);
   outtextxy(100,100,"COMPLETING TRANSACTION");
   loading();
}

void book()
{
   int gd=DETECT,gm;
   initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
   setbkcolor(9);
   settextstyle(2,0,8);
   setcolor(15);
   fstream a,b,c;
   int found=0,flights=0,i=0;
   oc.selection();
   bkflight();
   char tflnm[10][10],*tt;
   for(int j=0;j<10;j++)
   for(int k=0;k<10;k++)
   tflnm[j][k]='\0';
   a.open("plane",ios::in|ios::out|ios::binary);
   while(a.read((char*)&oa,sizeof(oa)))
   {
     if((strcmp(oa.returnfrom(),oc.returnrequiredfrom())||strcmp(oa.returnto(),oc.returnrequiredto()))==0)
     {
       flights=1;
       tt=oc.displayflights(i);
       for(j=0;j<9;j++,tt++)
	 tflnm[i][j]=*tt;
       tt=tt-j;
       i++;
     }
   }
   a.close();
   if(!flights)
   {
     cout<<"\n\nno flights available";
     getch();
     goto skip;
   }
   else
   {
     int x1=0,y1=0,cl;
     setposi(x1,y1);
     callmouse();
     do
     {
       cl=0;
       mouseposi(x1,y1,cl);
       int d=0;
       if(cl==1)
       {
	 d=coordinatefs(x1,y1,i);
	 if(d)
	 {
	   clickeffect(x1,y1);
	   oc.enterrequiredflightno(tflnm[d-1]);
	   break;
	 }
       }
     }while(1);
     mousehide();
     b.open("booked",ios::in|ios::out|ios::binary);
     c.open("client",ios::in|ios::out|ios::binary);
     int x[100];
     i=0;
     for(int k=0;k<100;k++) x[k]=0;
     while(b.read((char*)&ob,sizeof(ob)))
     {
	if(strcmp(oc.returnrequiredflightno(),ob.returnflightno())==0)
	{
	  found=1;
	  for(;i<100;)
	  {
	     for(int j=0;j<4;j++)
	     {
	       if(ob.returnseatno()[j])
	       {
		  x[i]=ob.returnseatno()[j];
		  i++;
	       }
	     }
	     break;
	  }
	}
     }
     b.close();
     c.close();
     seatsavailable(x);
     ob.createflightno(2);
     b.open("booked",ios::in|ios::out|ios::binary|ios::app);
     b.write((char*)&ob,sizeof(ob));
     b.close();
     int *h;
     h[0]=100;
     oc.readcustomer(h);
     c.open("client",ios::in|ios::out|ios::binary|ios::app);
     c.write((char*)&oc,sizeof(oc));
     c.close();
     bank();
     oc.displayticket();
     if(!found) cout<<"\ninvalid flight no";
     closegraph();
   }
   skip:
}

int coordinatect(int x,int y)
{
  int *z;
  z=ob.returnseatno();
  for(int i=0;i<oc.returnnoofpassengers()&&z[i];i++)
  {
    if(y>200+i*20)
    if(y<220+i*20)
    {
      cout<<"\t"<<z[i];
      clickeffect(100,201+i*20);
      sleep(1);
      return z[i];
    }
  }
  if(x>(getmaxx()-100))
  if(y>(getmaxy()-25))
  if(x<(getmaxx()-5))
  if(y<(getmaxy()-5))
    return -1;
  return 0;
}

int cancel(int z)
{
   int gd=DETECT,gm;
   initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
   setbkcolor(9);
   settextstyle(2,0,5);
   setcolor(15);
   setfillstyle(1,15);
   fstream b,c,tempb,tempc;
   bookings tempob;
   customer tempoc;
   int found=0,a[5],*seats,position,unavailablecustomerno=1,unavailableflightno=1;
   for(int i=0;i<5;i++) a[i]=0;
   outtextxy(50,100,"CONSUMER NO");
   setcolor(1);
   rectangle(200,100,500,120);
   floodfill(201,101,1);
   setcolor(15);
   tempoc.entercustomerno();
   outtextxy(50,150,"FLIGHT NO");
   setcolor(1);
   rectangle(200,150,500,170);
   floodfill(201,151,1);
   setcolor(15);
   tempob.enterflightno();
   b.open("booked",ios::in|ios::out|ios::binary);
   c.open("client",ios::in|ios::out|ios::binary);
   int k=0,j=0;
   while(c.read((char*)&oc,sizeof(oc)))
   {
       j++;
       if(oc.returncustomerno()==tempoc.returncustomerno())
       {
	  unavailablecustomerno=0;
	  break;
       }
   }
   c.close();
   while(b.read((char*)&ob,sizeof(ob)))
   {
      k++;
      if(k==j)
      {
	 if(strcmp(ob.returnflightno(),tempob.returnflightno())==0)
	 {
	     unavailableflightno=0;
	     break;
	 }
      }
   }
   b.close();
   if(!(unavailablecustomerno)&&!(unavailableflightno))
   {
	    oc.displayticket();
	    if(z) return 1;
	 seat:
	    setcolor(1);
	    setfillstyle(1,15);
	    rectangle(getmaxx()-100,getmaxy()-25,getmaxx()-5,getmaxy()-5);
	    floodfill(getmaxx()-10,getmaxy()-10,1);
	    setcolor(1);
	    settextstyle(2,0,5);
	    for(i=0;i<3;i++)
	    outtextxy(getmaxx()-92+i,getmaxy()-22,"S U B M I T");
	    int x=0,y=0;
	    cout<<"select the seats to be cancelled";
	    setposi(x,y);
	    callmouse();
	    int d=0,i=0;
	    do
	    {
	       int cl=0;
	       mouseposi(x,y,cl);
	       if(cl==1 && i<=oc.returnnoofpassengers())
	       {
		 d=0;
		 d=coordinatect(x,y);      //returns -1 when clicked in submit
		 if(d>0)
		 {
		   a[i]=d;
		   i++;
		   setcolor(9);
		   outtextxy(300,450,"please wait");
		   setcolor(15);
		 }
		 if(d==-1) break;
	       }
	    }while(1);
	    mousehide();
	    cleardevice();
	    seats=ob.returnseatno();
	    for(i=0;a[i];i++)
	    {
	      found=0;
	      for(int j=0;j<5&&seats[j];j++)  if(a[i]==seats[j])  found=1;
	      if(!found)
	      {
		cout<<"\ninvalid seat no";
		getch();
		goto seat;
	      }
	    }
   }
   else
   {
      cout<<"invalid customer no or flight no";
      getch();
      return 0;
   }
   int *s;
   s=ob.modifyseatno(a,seats);
   tempob=ob;
   oc.readcustomer(s);
   tempoc=oc;
   if(!ob.returnseatno()[0])
   {
      i=0;j=0;
      tempc.open("tclient",ios::in|ios::out|ios::binary);
      c.open("client",ios::in|ios::out|ios::binary);
      while(c.read((char*)&oc,sizeof(oc)))
      {
	 i++;
	 if(tempoc.returncustomerno()!=oc.returncustomerno())
	 tempc.write((char*)&oc,sizeof(oc));
      }
      tempc.close();
      c.close();
      remove("client");
      rename("tclient","client");
      tempb.open("tbooked",ios::in|ios::out|ios::binary);
      b.open("booked",ios::in|ios::out|ios::binary);
      while(b.read((char*)&ob,sizeof(ob)))
      {
	 j++;
	 if(j!=i)
	   if(strcmp(tempob.returnflightno(),ob.returnflightno()))
	      tempb.write((char*)&ob,sizeof(ob));
      }
      tempb.close();
      b.close();
      remove("booked");
      rename("tbooked","booked");
   }
   else if(ob.returnseatno()[0])
   {
      b.open("booked",ios::in|ios::out|ios::binary);
      int pos;
      c.open("client",ios::in|ios::out|ios::binary);
      i=0;j=0;
      while(!c.eof())
      {
	 i++;
	 pos=c.tellg();
	 c.read((char*)&oc,sizeof(oc));
	 if(tempoc.returncustomerno()==oc.returncustomerno())
	 {
	    c.seekg(pos);
	    c.write((char*)&tempoc,sizeof(tempoc));
	    break;
	 }
      }
      c.close();
      while(!b.eof())
      {
	      j++;
	      pos=b.tellg();
	      b.read((char*)&ob,sizeof(ob));
	      if(strcmp(tempob.returnflightno(),ob.returnflightno())==0)
	      {
		if(j==i)
		{
		  b.seekg(pos);
		  b.write((char*)&tempob,sizeof(tempob));
		  break;
		}
	      }
      }
      b.close();
   }
   setbkcolor(9);
   setcolor(15);
   settextstyle(2,0,6);
   outtextxy(100,100,"ticket has been successfully cancelled");
   getch();
   closegraph();
   return 0;
}

void view()
{
   cancel(1);
}

void exit()
{

  int gd=DETECT,gm;
  initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
  int j=-50;
  setcolor(8);
  int k,l;
  for(int p=0;p<6;p++)
  {
     if(p==0){k=200;l=450;}
     if(p==1){k=400;l=0;}
     if(p==2){k=10;l=300;}
     if(p==3){k=400;l=400;}
     if(p==4){k=100;l=10;}
     if(p==5){k=300;l=100;}
     arc(52+k,40+l,150,320,10);
     arc(70+k,45+l,150,350,10);
     arc(87+k,40+l,180,350,10);
     arc(42+k,30+l,75,270,10);
     arc(102+k,35+l,220,70,10);
     arc(102+k,20+l,320,140,10);
     arc(52+k,20+l,0,180,10);
     arc(70+k,20+l,0,150,10);
     arc(85+k,18+l,0,150,10);
     setfillstyle(1,7);
     floodfill(85+k,18+l,8);
     outtextxy(k,l,"*");
     setfillstyle(1,15);
     circle(5,5,17);
     circle(10,10,17);
     floodfill(20,20,8);
     setfillstyle(1,7);
   }
   int y,x;
   for(int i=-250;i<700;i=i+3)
   {
    for(int z=0;z<2;z++)
    {
      if(z==0){ y=8; setcolor(8); x=15;}
      if(z==1){ y=0; setcolor(0); x=0; }
      settextstyle(6,0,1);
      if(x==15)
      setcolor(4);
      else
      setcolor(x);
      outtextxy(60+i,445+j-300,"EMIRATES");
      setcolor(y);
      line(0+i,440+j-300,220+i,440+j-300);          //top
      line(50+i,470+j-300,133+i,470+j-300);         //bottom
      line(173+i,470+j-300,220+i,470+j-300);        //bottom
      line(50+i,470+j-300,0+i,440+j-300);           //left
      line(220+i,470+j-300,270+i,455+j-300);        //bottom right
      line(220+i,440+j-300,270+i,455+j-300);        //top right
      line(20+i,445+j-300,220+i,445+j-300);         //top window
      line(33+i,450+j-300,235+i,450+j-300);         //bottom window
      line(20+i,445+j-300,33+i,450+j-300);          //left window
      line(220+i,445+j-300,235+i,450+j-300);        //right window
      line(180+i,440+j-300,100+i,400+j-300);        //top right wing
      line(140+i,440+j-300,60+i,400+j-300);         //top left wing
      line(100+i,400+j-300,60+i,400+j-300);         //top top wing
      line(185+i,460+j-300,120+i,520+j-300);        //bottom right wing
      line(145+i,460+j-300,80+i,520+j-300);         //bottom left wing
      line(120+i,520+j-300,80+i,520+j-300);         //bottom bottom wing
      arc(52+i,400+j-300,210,270,40);               //bottom tail
      arc(-20+i,435+j-300,20,90,40);                //top tail
      line(0+i,440+j-300,-20+i,395+j-300);          //tail
      setfillstyle(1,x);
      floodfill(100+i,447+j-300,y);
      sound(400-j);
      delay(10);
      nosound();
    }
    j++;
    setcolor(11);
    settextstyle(2,0,8);
    outtextxy(50,400,"THANK YOU FOR USING OUR SERVICE");
  }
  closegraph();
}
void onetime()
{
   fstream e,a;
   e.open("base",ios::in|ios::out|ios::binary);
   oe.enterairports();
   oe.enterrate();
   e.write((char*)&oe,sizeof(oe));
   e.read((char*)&oe,sizeof(oe));
   oe.disp();
   e.close();
   getch();
   a.open("plane",ios::in|ios::out|ios::binary);
   int z=0;
   while(a.read((char*)&oa,sizeof(oa)))
   {
    if(z==1899)
    oa.displayflights1();
    z++;
   }
   a.close();
   getch();
}

void main()
{

  clrscr();
  onetime();
  load();
  start:
      int z;
      z=welcome();
      switch(z)
      {
	case 0: company(); goto start;
	case 1: book();    goto start;
	case 2: view();    goto start;
	case 3: cancel(0); goto start;
	case 4: exit();
      }
}

void bookings::enterflightno()
{
   setbkcolor(9);
   settextstyle(2,0,5);
   setcolor(1);
   setfillstyle(1,15);
   show(flightno,205,150);
   setcolor(15);
}

void bookings::createflightno(int x)
{
  if(x==2)  strcpy(flightno,oc.returnrequiredflightno());

  else if(x==1)
  {
    char requireddate[25];
    strcpy(requireddate,oc.returnrequireddate());
    strcat(requireddate,oa.returnflightname());
    strcpy(flightno,requireddate);
  }
  else if(x==0)
    strcpy(flightno,"0");
}

int coordinatec(int x,int y)
{
   int a=0,z=1;
   if(x>(getmaxx()-100))
   if(y>(getmaxy()-25))
   if(x<(getmaxx()-5))
   if(y<(getmaxy()-5))
      a=1;
   if(!a)
   {
     z++;
     if(x>(getmaxx()-100))
     if(y>(getmaxy()-50))
     if(x<(getmaxx()-5))
     if(y<(getmaxy()-30))
       a=1;
     if(!a) z=0;
   }
   return z;
}

void customer::readcustomer(int*s)
{
  if(s[0]==100)
  {
    assign(1);
  reread:
    cleardevice();
    setbkcolor(9);
    settextstyle(1,0,5);
    setcolor(1);
    for(int i=0;i<3;i++)
    outtextxy(10,20,"CUSTOMER DETAILS");
    for(i=0;i<getmaxx();i++)
    outtextxy(i,40,"-");
    settextstyle(2,0,7);
    setcolor(15);
    outtextxy(50,100,"NAME");
    outtextxy(400,100,"AGE(00-99)");
    outtextxy(550,100,"GENDER");
    for(i=0;i<getmaxx();i++)
    outtextxy(i,110,"-");
    setcolor(1);
    setfillstyle(1,15);
    settextstyle(2,0,5);
    for(i=0;i<oc.returnnoofpassengers();i++)
    {
      rectangle(50,130+i*50,400,150+i*50);
      floodfill(53,132+i*50,1);
      show(name[i],100,130+i*50);

      rectangle(450,130+i*50,500,150+i*50);
      floodfill(451,131+i*50,1);
      age[i]=0;
      show(age[i],455,130+i*50);

      rectangle(550,130+i*50,600,150+i*50);
      floodfill(551,131+i*50,1);
      show(gender[i],555,130+i*50);
    }

    for(;i<4;i++)
    {
      strcpy(name[i]," ");
      age[i]=0;
      strcpy(gender[i]," ");
    }
    setcolor(15);
    outtextxy(10,350,"ADDRESS(when done press '.')");
    setcolor(1);
    rectangle(3,370,400,420);
    floodfill(4,371,1);
    showl(address,10,375);
    setcolor(15);
    outtextxy(10,450,"PHONE NO");
    setcolor(1);
    rectangle(100,450,400,470);
    floodfill(101,451,1);
    phoneno=0;
    show10(phoneno,105,451);
    setcolor(1);
    settextstyle(2,0,5);
    rectangle(getmaxx()-100,getmaxy()-25,getmaxx()-5,getmaxy()-5);
    floodfill(getmaxx()-10,getmaxy()-10,1);
    rectangle(getmaxx()-100,getmaxy()-50,getmaxx()-5,getmaxy()-30);
    floodfill(getmaxx()-10,getmaxy()-40,1);
    for(i=0;i<3;i++)
    outtextxy(getmaxx()-92+i,getmaxy()-22,"S U B M I T");
    outtextxy(getmaxx()-80,getmaxy()-47,"BACK");
    int a=0,b=0;
    setposi(a,b);
    callmouse();
    int cl,x,y,d=0;;
    do
    {
      cl=0;
      mouseposi(x,y,cl);
      if(cl==1)
      {
	d=coordinatec(x,y);
	outtextxy(300,450,"please wait");
	delay(500);
	setcolor(0);
	outtextxy(300,450,"please wait");
	setcolor(15);
	if(d==2) goto reread;
      }
    }while(d!=1);
    mousehide();
  }
  else
  {
    for(int i=0;s[i];i++)
    {
      strcpy(name[s[i]-1],"  ");
      age[s[i]-1]=0;
      strcpy(gender[s[i]-1],"  ");
    }
    int m;
    for(i=0;i<4;i++)
    {
      if(age[i]==0)
      {
	 for(m=1;m<5;)
	 {
	   if(age[i+m]!=0)   break;
	   m++;
	 }
	 if((i+m)<4)
	 {
	   strcpy(name[i],name[i+m]);
	   strcpy(name[i+m],"    ");
	   age[i]=age[i+m];
	   age[i+m]=0;
	   strcpy(gender[i],gender[i+m]);
	   strcpy(gender[i+m],"  ");
	 }
      }
    }
  }
}

void customer::displayticket()
{
  int gd=DETECT,gm;
  initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
  cleardevice();
  setbkcolor(9);
  settextstyle(2,0,5);
  setcolor(4);
  setfillstyle(1,15);
  for(int i=0;i<3;i++)
  {
    if(i==2) setcolor(1);
    rectangle(10+i*2,20+i*2,630+i*2,400+i*2);
  }
  floodfill(100,100,1);
  setfillstyle(1,1);
  for(i=0;i<400;i=i+50)
  for(int j=0;j<2;j++)
  {
    circle(30+j*590,i+50,5);
    floodfill(30+j*590,i+50,1);
  }
  fstream a;
  a.open("plane",ios::in|ios::out|ios::binary);

  if(!customerno)  outtextxy(100,100,"unavilable");
  else
  {
	int *x,seat[4];
	x=seat;
	char y[5];
	for(i=0;i<oc.returnnoofpassengers();i++)
	  seat[i]=ob.returnseatno()[i];
	for(i=0;i<5;i++)  y[i]=ob.returnflightno()[i+8];
	while(a.read((char*)&oa,sizeof(oa)))
	{
	   if(strcmp(y,oa.returnflightname())==0) break;
	}
	a.close();
	outtextxy(300,70,"date of booking");
	outtextxy(420,70,ctime(&ptime));
	outtextxy(50,70,"customer no");
	char cno[15];
	sprintf(cno,"%ld",customerno);
	outtextxy(170,70,cno);
	outtextxy(300,90,"flight no");
	outtextxy(400,90,ob.returnflightno());
	outtextxy(50,90,"flight name");
	outtextxy(170,90,y);
	outtextxy(50,110,"from");
	outtextxy(170,110,requiredfrom);
	outtextxy(300,110,"to");
	outtextxy(400,110,requiredto);
	outtextxy(50,130,"departure time");
	char dtm[6],atm[6];
	sprintf(dtm,"%ld",oa.returndepttime());
	outtextxy(170,130,dtm);
	outtextxy(300,130,"arrival time");
	sprintf(atm,"%ld",oa.returnarrtime());
	outtextxy(400,130,atm);
	outtextxy(50,150,"date of journey");
	outtextxy(170,150,oc.requireddate);
	outtextxy(100,170,"#NO  CUSTOMER NAME  SEAT NO  AGE  GENDER");
	outtextxy(100,180,"___  _____________  _______  ___  _______");
	char no[1],sno[2],ag[2];
	for(i=0;i<noofpassengers&&x[i];i++)
	{
	  rectangle(50,200+i*20,450,220+i*20);
	  sprintf(no,"%d",i+1);
	  outtextxy(100,200+i*20,no);
	  outtextxy(150,200+i*20,name[i]);
	  sprintf(sno,"%d",x[i]);
	  outtextxy(280,200+i*20,sno);
	  sprintf(ag,"%d",age[i]);
	  outtextxy(340,200+i*20,ag);
	  outtextxy(380,200+i*20,gender[i]);
	}
	outtextxy(50,300,"address");
	outtextxy(50,320,address);
	outtextxy(50,380,"phone no");
	char ph[10];
	sprintf(ph,"%ld",phoneno);
	outtextxy(170,380,ph);
  }
  for(i=0;i<5;i++)
  {
    ellipse(500+i,320+i,0,360,50,30);
    outtextxy(510+i,300+i,"i***");
    outtextxy(470,310,"cash");
    outtextxy(480,320,"received");
  }

  setcolor(1);
  for(i=0;i<616;i++)
    outtextxy(14+i,50,"_");
  setfillstyle(1,4);
  floodfill(150,25,1);
  setcolor(15);
  settextstyle(2,0,10);
  for(i=0;i<4;i++)
  outtextxy(100+i,20+i,"EMIRATES");
  getch();
}

void bookings::enterseatno(int *s)
{
   for(int i=0;i<oc.returnnoofpassengers();i++)
     seatno[i]=s[i];
   for(;i<4;i++) seatno[i]=0;
}

bookings::bookings()  { for(int i=0;i<4;i++)seatno[i]=0; }

int* bookings::modifyseatno(int *a,int *seats)
{
  int j=0,y=0;
  static int z[4];
  for(int k=0;k<5;k++) z[k]=0;
  for(k=0;k<4&&seats[k];k++)
  {
    int cancelled=0;
    for(int i=0;i<4&&a[i];i++)
    {
      if(a[i]==seats[k])
      {
	z[y]=k+1;
	y++;
	cancelled=1;
	break;
      }
    }
    if(!cancelled)
    {
      seatno[j]=seats[k];
      j++;
    }
  }
  for(;j<4;j++)  seats[j]=0;
  return z;
}

void aeroplane::readflight(char *f,char *t)
{
   if(strcmp(f,"aa")==0)
  {
     for(int i=0;i<50;i++)
     {
       flightname[i]='\0';
	     from[i]='\0';
	       to[i]='\0';
     }
     cout<<"\nEnter new flight name-";
     gets(flightname);
     cout<<"Enter from           - ";
     gets(from);
     cout<<"Enter to             - ";
     gets(to);
     cout<<"Enter departure time - ";
     cin>>depttime;
     cout<<"Enter arrival time   - ";
     cin>>arrtime;
     cout<<"Enter rate of economic class  - ";
     cin>>charge[0];
     cout<<"Enter rate of bussiness class - ";
     cin>>charge[1];
     cout<<"Enter rate of first class     - ";
     cin>>charge[2];
  }
  else
  {
    int i,j;
    fstream a;
    for(i=1;i<11;i++)
    {
      if(i<6)
      {
	strcpy(from,f);
	strcpy(to,t);
      }
      else
      {
	strcpy(from,t);
	strcpy(to,f);
      }
      char x[5];
      for(int k=0;k<5;k++)  x[k]='\0';
      char y='\0';
      x[0]=from[0];
      x[1]=to[0];
      switch(i)
      {
	 case 1:y='1';break;
	 case 2:y='2';break;
	 case 3:y='3';break;
	 case 4:y='4';break;
	 case 5:y='5';break;
	 case 6:y='1';break;
	 case 7:y='2';break;
	 case 8:y='3';break;
	 case 9:y='4';break;
	case 10:y='5';break;
      }
      x[2]=y;
      strcpy(flightname,x);
      depttime=20000+(i*50000);
      if(depttime>240000) depttime=depttime-240000;
      if(depttime>240000) depttime=depttime-240000;
      long time;
      time=oe.returntraveltime();
      arrtime=depttime+time*10000;
      if(arrtime>240000) arrtime=arrtime-240000;
      long rate;
      rate=oe.returnrate();
      for(j=0;j<3;j++) charge[j]=rate*(j+1);
      a.open("plane",ios::in|ios::out|ios::binary|ios::app);
      a.write((char*)&oa,sizeof(oa));
      a.close();
    }
  }
}


void enter::enterairports()
{
  cout<<"\nEnter no of airports required(max 20)\n";
  cin>>noofairports;
  cout<<"\nEnter the airports available\n";
  for(int i=0;i<noofairports;i++)
    gets(airport[i]);
}

void enter::enterrate()
{
  for(int i=0;i<noofairports;i++)
  for(int j=i+1;j<noofairports;j++)
  {
    if(i>9||j>9)
    {
       rate=50000;
       traveltime=10;
    }
    else
    {
       rate=5000;
       traveltime=2;
    }
    oa.readflight(airport[i],airport[j]);
  }
}

void customer::selection()
{
   int a=0,b=0,cl,x,y;
   setposi(a,b);
   callmouse();
   settextstyle(2,0,5);
   setcolor(1);
   setfillstyle(1,15);
   for(int i=0;i<3;i++)
   {
	    rectangle(300,100+i*50,550,120+i*50);
	    floodfill(310,110+i*50,1);
   }
   for(i=0;i<3;i++)
   {
	    rectangle(300+i*100,250,350+i*100,270);
	    floodfill(310+i*100,260,1);
   }
   setcolor(15);
   outtextxy(10,100,"departure station");
   outtextxy(10,150,"Enter the arrival station");
   outtextxy(10,250,"Enter the date of journey(yyyymmdd)");
   outtextxy(10,200,"Enter the no of passengers(max 4)");
   int cntrl[10];
   for(i=0;i<10;i++) cntrl[i]=0;
   int d=0;
   do
   {
     cl=0;
     mouseposi(x,y,cl);
     if(cl==1)
	d=coordinates(x,y,cntrl);
   }
   while(d!=1);
   mousehide();
}

void enter::disp()
{
  cout<<"\nno"<<noofairports;
  cout<<"\ntime"<<traveltime;
  cout<<"\nrate"<<rate<<endl;
  for(int i=0;i<20;i++)
    cout<<airport[i]<<endl;
}

void aeroplane::update()
{
   start:
	long posi,ch=0;
	fstream a;
	clrscr();
	cout<<"Enter the Changes you want to make";
	cout<<"\n1.Edit Details\n2.Delete Details\n3.ADD\n4.VIEW\nanyother to exit";
	cout<<"\nselect your choice:";
	cin>>ch;
	int found=0;
	char tflight[50];
	for(int i=0;i<50;i++)  tflight[i]='\0';
	if(ch<5 && ch>0  &&  ch!=3)
	{
	  cout<<"Enter the flight name:";
	  gets(tflight);
	}
	switch(ch)
	{
		case 1:a.open("plane",ios::in|ios::out|ios::binary);
		       while(!a.eof())
		       {
			 posi=a.tellg();
			 a.read((char*)&oa,sizeof(oa));
			 if(strcmp(tflight,flightname)==0)
			 {
			    oa.displayflights1();
			    oa.readflight("aa","aa");
			    a.seekp(posi);
			    a.write((char*)&oa,sizeof(oa));
			    found=1;
			    getch();
			    goto start;
			  }
		       }
		       if(!found)
		       cout<<"Record does not exists";
		       a.close();
		       getch();
		       goto start;
		case 2:a.open("plane",ios::in|ios::out|ios::binary);
		       fstream tempa;
		       tempa.open("tplane",ios::in|ios::out|ios::binary);
		       while(a.read((char*)&oa,sizeof(oa)))
		       {
			 if(strcmp(tflight,flightname)==0)
			 {
			    oa.displayflights1();
			    getch();
			    cout<<"\nThe record is deleted";
			    found=1;
			  }
			  else
			  tempa.write((char*)&oa,sizeof(oa));
		       }
		       if(!found)  cout<<"Record not found";
		       a.close();
		       tempa.close();
		       remove("plane");
		       rename("tplane","plane");
		       getch();
		       goto start;

		case 3:a.open("plane",ios::in|ios::out|ios::app|ios::binary);
		       oa.readflight("aa","aa");
		       a.write((char*)&oa,sizeof(oa));
		       a.close();
		       getch();
		       goto start;
		case 4:a.open("plane",ios::out|ios::in|ios::binary);
		       while(a.read((char*)&oa,sizeof(oa)))
		       {
			 found=0;
			 if(strcmp(tflight,oa.returnflightname())==0)
			 {
			   oa.displayflights1();
			   found=1;
			   getch();
			   goto start;
			 }
		       }
		       a.close();
		       if(!found) cout<<"Record does not exist";
		       getch();
		       goto start;
	     default  :cout<<"exitting";
	}
	getch();
}
