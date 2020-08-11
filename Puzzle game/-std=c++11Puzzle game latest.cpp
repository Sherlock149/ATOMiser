#include<iostream>
using namespace std;
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
class puzzlegame
{
	int _main[9]={0,1,1,1,0,1,1,1,0};
	public:
	int A[9]={1,1,0,1,1,0,0,0,0};
	int B[9]={1,1,1,0,0,0,0,0,0};
	int C[9]={0,1,1,0,1,1,0,0,0};
	int D[9]={1,0,0,1,0,0,1,0,0};
	int E[9]={0,1,0,1,1,1,0,1,0};
	int F[9]={0,0,1,0,0,1,0,0,1};
	int G[9]={0,0,0,1,1,0,1,1,0};
	int H[9]={0,0,0,0,0,0,1,1,1};
	int I[9]={0,0,0,0,1,1,0,1,1};
		//function to show current status of _main
		void show_status()
		{
			int i,j;
	  for(i=0;i<3;i++)
	  {
		for(j=0;j<3;j++)
		{
			if(i==0)
			cout<<"          "<<_main[j]<<"          ";
			else if(i==1)
			cout<<"          "<<_main[j+3]<<"          ";
			else
			cout<<"          "<<_main[j+6]<<"          ";
		}
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
	  }  
		}
		//func to carry out operation
		void execution(int X[])
		{
			int i;
			for(i=0;i<9;i++)
			{
				_main[i]=_main[i]+X[i];
				if(_main[i]==2)
				_main[i]=0;
			}
		}
};
//main starts here
int main ()
{
	system("cls");
	cout<<"Press 0 to close the game"<<endl<<endl;
	puzzlegame p;
	p.show_status();
	int ch;
	//int quit_status;
	for(int k=0;k<999;k++)
	{cout<<"Enter your Choice (0 to quit): ";
	cin>>ch;
	if(ch == 0)
	exit(0);
	switch(ch)
	{
		case 1:
			p.execution(p.A);
			p.show_status();
			cout<<endl;
		break;
			case 2:
			p.execution(p.B);
			p.show_status();
			cout<<endl;
		break;
			case 3:
			p.execution(p.C);
			p.show_status();
			cout<<endl;
		break;
			case 4:
			p.execution(p.D);
			p.show_status();
			cout<<endl;
		break;
			case 5:
			p.execution(p.E);
			p.show_status();
			cout<<endl;
		break;
			case 6:
			p.execution(p.F);
			p.show_status();
			cout<<endl;
		break;
			case 7:
			p.execution(p.G);
			p.show_status();
			cout<<endl;
		break;
			case 8:
			p.execution(p.H);
			p.show_status();
			cout<<endl;
		break;
			case 9:
			p.execution(p.I);
			p.show_status();
			cout<<endl;
		break;
		default:
			cout<<"Enter correctly"<<endl;
	}
	//cout<<"Press any number other than 0 to continue: ";
	//cin>>quit_status;
	//if(quit_status == 0)
	//exit(0);
}

	getch();
	return 0;
}
