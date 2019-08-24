# AirTicketReservation
class 12 project- based on turbo c++

The Air Ticket Reservation also includes features like ticket cancelation, viewing the ticket which is more user friendly and simple to use.
It involves graphics and mouse makes it easy to use.


Acknowledgement
I sincerely thank all those who helped me to make this project a success. I would like to thank our computer teachers Ms.Jeesha, Mr.Satish for their invaluable support to accomplish this project.
I would also like to thank my teammate and all our friends for helping out with our project.

 
Contents
	Introduction
	Working Environment
	System Analysis
	Header Files
	System Design
	Source Code
	Output Screens
	Conclusion
	Bibliography
 
Introduction
This project is about air ticket reservation system, allowing the user to book ticket at ease, which is user friendly, developed using C++ which is a common OOP and GUI language.
It includes options like ADD, MODIFY, and DELETE ….etc which can be accessed ONLY by the reservation company (2 layer protection – pattern lock & password) to make the desired changes to the available flight details and add or delete an existing flight.
It also includes features such as RESERVATION, CANCELLATION, VIEW a ticket which too comes with full protection (only the customer who has booked can delete his/her ticket).

 
Working Environment 
HARDWARE
    Processor                            : INTEL i3 2120
    Speed                                  : 3.30 GHZ
    RAM                                   : 1.96 GB 
    Hard Disk Capacity         : 500 GB
    Keyboard                           : Logitech PS/II
    Mouse                                 : Microsoft Optical
SOFTWARE
    Operating system             :   UBUNTU 14.04 lts
    Programming Language   :   DOS BOX
            EMULATOR
 
System Analysis
Advantages 
1.	User friendly.
2.	Successfull implementation of real world features like booking, cancellation, viewing a ticket.
3.	Highest possible security both for company deatails and customer details.
4.	Double layer security for company details (pattern lock using mouse & password).
5.	Only the customer with the ticket can delete the ticket. 
6.	Looks good with high end graphics.
7.	Includes mouse.
8.	Customers can select the seat they required.
9.	Large no of flights (1900).
10.	Large no of airports (20).
11.	Includes some videos (with sound) for fun.
12.	Company can edit/add/delete a flight.
13.	All the class variables are in private (so accidental modification is prevented successfully).
14.	Easy to update and have used the principles of code reusability.
Disadvantages 
1.	Lengthy source code and requires some memory for files.
2.	Can hack the pattern lock.
3.	Can get hanged at some points (if instructions are not followed).
4.	Real time date is accessed from system date but it still shows the dates which have passed.
5.	Dates count upto 31 even though some months donot have 31 dates.
 
Header Files
fstream.h
string.h
conio.h
stdio.h
stdlib.h
time.h
graphics.h
iomanip.h
dos.h

System Design
Files used:
plane    - a
tplane   - tempa
booked   - b
tbooked  - tempb
client   - c
tclient  - tempc
base     - e 

Classes used:
class aeroplane  - oa
class bookings   - ob
class customer   - oc
class enter      - oe
Functions used:
class aeroplane 
char*   returnflightname();     
char*   returnto();             
char*   returnfrom();           
long    returnarrtime();          
long    returndepttime();
long*   returncharge(); 
void    update();
void    readflight(char*,char*);
void    displayflights1();

class bookings
char*   returnflightno(); 
int*    returnseatno(); 
void    enterflightno();
int*    modifyseatno(int*,int*);
void    createflightno(int);
void    enterseatno(int*);
        bookings();
class customer 
char*   returnrequiredfrom();    
char*   returnrequiredto();      
char*   returnrequiredflightno();
char*   returnrequireddate();    
long    returncustomerno();      
long    returnphoneno();         
int     returnnoofpassengers();  
int     returnrequiredclass();   
int     coordinates(int,int,int*);
void    entercustomerno();
void    displayticket();
void    readcustomer(int*);
void    enterrequiredflightno(char* tflnm);
void    assign(int x);
void selection();
char* displayflights(int);

class enter 
long    returnrate();             
int     returntraveltime();        
int     returnnoofairports();      
char    (* returnairport())[50];
void   enterairports();
void   enterrate();
void   disp();
 
Non member funtions
void   show(char* a,int x,int y);
void   showl(char* a,int x,int y);
void   show(int &a,int x,int y);
void   show10(long &a,int x,int y);
void   box();
void   loading();
void   company();
int    callmouse();
void   mouseposi(int &xpos,int &ypos,int &click);
int    mousehide();
void   setposi(int &xpos,int &ypos);
void   load();
void   clickeffect(int x,int y);
int    coordinatew(int x,int y);
int    coordinatecn(int x,int y);
int    coordinateca(int x,int y);
int    coordinatecam(int x,int y);
int    coordinatecay(int x,int y);
int    coordinatef(int x,int y,int s);
int    lockcoordinate10(int x,int y);
int    lockcoordinate9(int x,int y);
int    lockcoordinate8(int x,int y);
int    lockcoordinate7(int x,int y);
int    lockcoordinate6(int x,int y);
int    lockcoordinate5(int x,int y);
int    lockcoordinate4(int x,int y);
int    lockcoordinate3(int x,int y);
int    lockcoordinate2(int x,int y);
int    lockcoordinate1(int x,int y);
int    welcome();
int    coordinate(int x,int y,int *bs);
void   display(int *bs);
void   seatsavailable(int *s);
void   bkflight();
int    coordinatefs(int x,int y,int j);
void   bank();
void   book();
int    coordinatect(int x,int y);
int    cancel(int z);
void   view();
void   exit();
void   onetime();
void   main();
int    coordinatec(int x,int y); 

Conclusion
The Air Ticket Reservation also includes features like ticket cancelation, viewing the ticket which is more user friendly and simple to use.
It involves graphics and mouse makes it easy to use.
