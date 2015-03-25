#include <iostream.h>	//Header Files Included
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <stdlib.h>

#define width 100	//Definitions of Variables used
#define x1 150
#define y1 90
#define margin 10

union REGS in,out;	//Declarations of Variables
int flag=1;
int win[3][3]={0,0,0,0,0,0,0,0,0};

void drawboard();	//Prototypes of Functions
void checkmouse();
void showmouse();
void hidemouse();
void menux();
void menuo();
void detect();
void checkwin();
void rematch();

void main()		//Start of Main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	setbkcolor(GREEN);
	drawboard();
	checkmouse();
	showmouse();
	detect();
	hidemouse();
	getch();
}                       //End of Main()

void drawboard()        //Function to Draw Game Window
{
	setcolor(RED);
	outtextxy(210,50,"Welcome To Tic Tac Toe");
	setcolor(BLUE);
	outtextxy(10,440,"Press Left Mouse Button to play");
	outtextxy(10,450,"Press Right Mouse Button to exit anytime");
	settextstyle(4,HORIZ_DIR,3);

	outtextxy(420,380,"Made By Dipendra ");
	outtextxy(524,400,"Sarvanan");
	outtextxy(524,420,"Surya");
	outtextxy(524,440,"Aditya");

	bar(x1+width-0.25*margin,y1,x1+width+0.25*margin,y1+3*width);
	bar(x1+2*width-0.25*margin,y1,x1+2*width+0.25*margin,y1+3*width);
	bar(x1,y1+width-0.25*margin,x1+3*width,y1+width+0.25*margin);
	bar(x1,y1+2*width-0.25*margin,x1+3*width,y1+2*width+0.25*margin);
}

void checkmouse()       //Function to check mouse availability
{
	in.x.ax=0;
	int86(0X33,&in,&out);
	if(out.x.ax==0)
	{
		cout<<"Mouse Initializiation Failed, Exiting";
		getch();
		exit(0);
	}
}

void showmouse()        //Function to display cursor
{
	in.x.ax=1;
	int86(0X33,&in,&out);
}
void hidemouse()        //Function to hide cursor
{
	in.x.ax=2;
	int86(0X33,&in,&out);
}

void detect()           //Function to detect mouse click
{
	while(!kbhit())
	{
		in.x.ax=3;
		int86(0X33,&in,&out);
		if(out.x.bx==1)
		{
			if(flag%2==1)
			menux();
			if(flag%2==0)
			menuo();
		}


		if(out.x.bx==2)
			exit(0);

		if(out.x.bx==3)
			exit(0);
	}
}

void menux()            //Function to draw move of x
{
	if(out.x.cx>x1&&out.x.cx<x1+width)
	{
		if(out.x.dx>y1&&out.x.dx<y1+width&&win[0][0]==0)
		{
			hidemouse();
			line(x1+margin,y1+margin,x1+width-margin,y1+width-margin);
			line(x1+width-margin,y1+margin,x1+margin,y1+width-margin);
			win[0][0]=1;
			showmouse();
		}
		if(out.x.dx>y1+width&&out.x.dx<y1+2*width&&win[0][1]==0)
		{
			hidemouse();
			line(x1+margin,y1+width+margin,x1+width-margin,y1+2*width-margin);
			line(x1+width-margin,y1+width+margin,x1+margin,y1+2*width-margin);
			win[0][1]=1;
			showmouse();
		}
		if(out.x.dx>y1+2*width&&out.x.dx<y1+3*width&&win[0][2]==0)
		{
			hidemouse();
			line(x1+margin,y1+2*width+margin,x1+width-margin,y1+3*width-margin);
			line(x1+width-margin,y1+2*width+margin,x1+margin,y1+3*width-margin);
			win[0][2]=1;
			showmouse();
		}
	}

	if(out.x.cx>x1+width&&out.x.cx<x1+2*width)
	{
		if(out.x.dx>y1&&out.x.dx<y1+width&&win[1][0]==0)
		{
			hidemouse();
			line(x1+width+margin,y1+margin,x1+2*width-margin,y1+width-margin);
			line(x1+2*width-margin,y1+margin,x1+width+margin,y1+width-margin);
			win[1][0]=1;
			showmouse();
		}
		if(out.x.dx>y1+width&&out.x.dx<y1+2*width&&win[1][1]==0)
		{
			hidemouse();
			line(x1+width+margin,y1+width+margin,x1+2*width-margin,y1+2*width-margin);
			line(x1+2*width-margin,y1+width+margin,x1+width+margin,y1+2*width-margin);
			win[1][1]=1;
			showmouse();
		}
		if(out.x.dx>y1+2*width&&out.x.dx<y1+3*width&&win[1][2]==0)
		{
			hidemouse();
			line(x1+width+margin,y1+2*width+margin,x1+2*width-margin,y1+3*width-margin);
			line(x1+2*width-margin,y1+2*width+margin,x1+width+margin,y1+3*width-margin);
			win[1][2]=1;
			showmouse();
		}
	}
	if(out.x.cx>x1+2*width&&out.x.cx<x1+3*width)
	{
		if(out.x.dx>y1&&out.x.dx<y1+width&&win[2][0]==0)
		{
			hidemouse();
			line(x1+2*width+margin,y1+margin,x1+3*width-margin,y1+width-margin);
			line(x1+3*width-margin,y1+margin,x1+2*width+margin,y1+width-margin);
			win[2][0]=1;
			showmouse();
		}
		if(out.x.dx>y1+width&&out.x.dx<y1+2*width&&win[2][1]==0)
		{
			hidemouse();
			line(x1+2*width+margin,y1+width+margin,x1+3*width-margin,y1+2*width-margin);
			line(x1+3*width-margin,y1+width+margin,x1+2*width+margin,y1+2*width-margin);
			win[2][1]=1;
			showmouse();
		}
		if(out.x.dx>y1+2*width&&out.x.dx<y1+3*width&&win[2][2]==0)
		{
			hidemouse();
			line(x1+2*width+margin,y1+2*width+margin,x1+3*width-margin,y1+3*width-margin);
			line(x1+3*width-margin,y1+2*width+margin,x1+2*width+margin,y1+3*width-margin);
			win[2][2]=1;
			showmouse();
		}
	}
	checkwin();
}

void menuo()            //Function to draw move of o
{
	if(out.x.cx>x1&&out.x.cx<x1+width)
	{
		if(out.x.dx>y1&&out.x.dx<y1+width&&win[0][0]==0)
		{
			hidemouse();
			circle(x1+0.5*width,y1+0.5*width,0.5*width-margin);
			win[0][0]=-1;
			showmouse();
		}
		if(out.x.dx>y1+width&&out.x.dx<y1+2*width&&win[0][1]==0)
		{
			hidemouse();
			circle(x1+0.5*width,y1+1.5*width,0.5*width-margin);
			win[0][1]=-1;
			showmouse();
		}
		if(out.x.dx>y1+2*width&&out.x.dx<y1+3*width&&win[0][2]==0)
		{
			hidemouse();
			circle(x1+0.5*width,y1+2.5*width,0.5*width-margin);
			win[0][2]=-1;
			showmouse();
		}
	}

	if(out.x.cx>x1+width&&out.x.cx<x1+2*width)
	{
		if(out.x.dx>y1&&out.x.dx<y1+width&&win[1][0]==0)
		{
			hidemouse();
			circle(x1+1.5*width,y1+0.5*width,0.5*width-margin);
			win[1][0]=-1;
			showmouse();
		}
		if(out.x.dx>y1+width&&out.x.dx<y1+2*width&&win[1][1]==0)
		{
			hidemouse();
			circle(x1+1.5*width,y1+1.5*width,0.5*width-margin);
			win[1][1]=-1;
			showmouse();
		}
		if(out.x.dx>y1+2*width&&out.x.dx<y1+3*width&&win[1][2]==0)
		{
			hidemouse();
			circle(x1+1.5*width,y1+2.5*width,0.5*width-margin);
			win[1][2]=-1;
			showmouse();
		}
	}

	if(out.x.cx>x1+2*width&&out.x.cx<x1+3*width)
	{
		if(out.x.dx>y1&&out.x.dx<y1+width&&win[2][0]==0)
		{
			hidemouse();
			circle(x1+2.5*width,y1+0.5*width,0.5*width-margin);
			win[2][0]=-1;
			showmouse();
		}
		if(out.x.dx>y1+width&&out.x.dx<y1+2*width&&win[2][1]==0)
		{
			hidemouse();
			circle(x1+2.5*width,y1+1.5*width,0.5*width-margin);
			win[2][1]=-1;
			showmouse();
		}
		if(out.x.dx>y1+2*width&&out.x.dx<y1+3*width&&win[2][2]==0)
		{
			hidemouse();
			circle(x1+2.5*width,y1+2.5*width,0.5*width-margin);
			win[2][2]=-1;
			showmouse();
		}
	}
	checkwin();
}


void checkwin()         //Function to check win,draw and display result
{
	int s1,s2,s3,s4,s5,s6,sd1,sd2;
	s1=win[0][0]+win[0][1]+win[0][2];
	s2=win[1][0]+win[1][1]+win[1][2];
	s3=win[2][0]+win[2][1]+win[2][2];
	s4=win[0][0]+win[1][0]+win[2][0];
	s5=win[0][1]+win[1][1]+win[2][1];
	s6=win[0][2]+win[1][2]+win[2][2];
	sd1=win[0][0]+win[1][1]+win[2][2];
	sd2=win[2][0]+win[1][1]+win[0][2];
	flag=win[0][0]+win[0][1]+win[0][2]+win[1][0]+win[1][1]+win[1][2]+win[2][0]+win[2][1]+win[2][2]+1;

	if(s1==3||s2==3||s3==3||s4==3||s5==3||s6==3||sd1==3||sd2==3)
	{
		settextstyle(1,0,1);
		setcolor(4);
		outtextxy(x1+width+0.25*margin+15,y1+3*width+0.5*margin,"X wins ");
		rematch();
	}
	if(s1==-3||s2==-3||s3==-3||s4==-3||s5==-3||s6==-3||sd1==-3||sd2==-3)
	{
		settextstyle(1,0,1);
		setcolor(4);
		outtextxy(x1+width+0.25*margin+15,y1+3*width+0.5*margin,"O wins ");
		rematch();
	}
	if(win[0][0]!=0&&win[1][0]!=0&&win[2][0]!=0&&win[0][1]!=0&&win[1][1]!=0&&win[2][1]!=0&&win[0][2]!=0&&win[1][2]!=0&&win[2][2]!=0)
	{
		settextstyle(1,0,1);
		setcolor(4);
		outtextxy(x1+width+0.25*margin+15,y1+3*width+0.5*margin,"Draw");
		rematch();
	}
}

void rematch()          //Function to ask user for rematch
{
	setcolor(BROWN);
	outtextxy(10,10,"Would you like to play again");
	setcolor(BLUE);
	outtextxy(362,10,"No");
	outtextxy(312,10,"Yes");
	setcolor(8);
	rectangle(310,13,345,30);
	rectangle(360,13,395,30);

	while(!kbhit())
	{
		in.x.ax=3;
		int86(0X33,&in,&out);
		if(out.x.bx==1)
		{
			if(out.x.cx>310&&out.x.cx<345&&out.x.dx>13&&out.x.dx<30)
			{
				flag=1;
				win[0][0]=0;win[0][1]=0;win[0][2]=0;win[1][0]=0;win[1][1]=0;win[1][2]=0;win[2][0]=0;win[2][1]=0;win[2][2]=0;
				delay(300);
				main();
			}
			if(out.x.cx>360&&out.x.cx<395&&out.x.dx>13&&out.x.dx<30)
			{
				exit(0);
			}
		}


		if(out.x.bx==2)
			exit(0);

		if(out.x.bx==3)
			exit(0);
	}

}                       //End of Program