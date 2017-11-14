#pragma warning(disable:4996)

#include <iostream>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include <string>

#include "funkcje.cpp"
int main(){

MAIN:
	rezygnacja=0;cheats=0;
srand( time( NULL ) );
for(int i=0;i<6;i++){l[i]=0;}
for(int i=0;i<6;i++){lCOM[i]=0;}
pozycja[0]=0;pozycja[1]=0;

for(int a=0;a<2;a++){
	for(int b=0;b<7;b++){
		for(int c=0;c<3;c++){
			for(int d=0;d<3;d++){
				for(int e=0;e<1;e++){
					lokal[a][b][c][d][e]=0;
				}
			}
		}
	}
}


// DEFINICJA ELEMENTOW TABLIC NA 0
for(int i=0;i<10;i++){
	for(int j=0;j<10;j++){
		t[i][j]=0;
		p[i][j]=0;
		g[i][j]=0;
		gCOM[i][j]=0;
		PLAYER[i]="";
		SCORE[i]=0;
		for(int h=0;h<2;h++){plan[h][i][j]=0;}
	}
}


rozstawCOM();

char pick;
int choice=0;

do{


system("cls");
cout<<"CSHIPS. WORIE PRODUCTIONS\n\n";
if(choice==0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);}
cout<<"NOWA GRA\t\n";white();
if(choice==1){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);}
cout<<"KONTYNUUJ\t\n";white();
if(choice==2){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);}
cout<<"NAJLEPSZE WYNIKI\n";white();
if(choice==3){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);}
cout<<"WYJSCIE\t\t\n";white();
pick=getch();

switch(pick){
case GORA: (choice==0) ? choice=3:choice--;break;
case DOL: (choice==3) ? choice=0:choice++;break;}

  if(pick==96){cout<<"Konsola otwarta. Wpisz polecenie: ";getline(cin,cmd);
  if(cmd=="/cheat"){ cout<<((cheats==0) ? "Kody zostaly aktywowane.":"Kody zostaly wylaczone");(cheats==0) ? cheats=1:cheats=0;cin.get();}
  if(cmd=="/hscr"){ofstream high("hsc.csh");}}

}while(pick!=13);

if(pick==13 && choice ==0){cnd=0;play();}
if(pick==13 && choice ==1){cnd=1;cont();}
if(pick==13 && choice ==2){system("cls");wyniki();getch();}
if(pick==13 && choice ==3){return 0;}


goto MAIN;
	return 0;
}