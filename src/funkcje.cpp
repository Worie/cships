using namespace std;


string PLAYER[10];
int SCORE[10];


int t[10][10];
int p[10][10];
int g[10][10];
int gCOM[10][10];
int l[6],lCOM[6];
int lokal[2][6][3][3][2];
int plan[2][10][10];
int sumaP=0,sumaCOM=0;
int pozycja[2];
string name="GRACZ",cmd="";

int rezygnacja=0;
int cnd=0,cheats=0;

int points=200;
const int		GORA=72, DOL=80,LEWO=75, PRAWO=77;
char			znak;


void white(){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);}
void green(){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);}
void blue(){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);}
void red(){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);}
void hisc(){

	system("cls");
fstream high;
high.open("hsc.csh",ios::app);
if(high.good() == false){ofstream high("hsc.csh");}
if(high.good() == true){
	if(rezygnacja!=2){high<<name<<"\t"<<points<<"\n";}
}

}
void showCOM(){
cout<<"  ";for(int i=0;i<10;i++){cout<<i<<" ";}cout<<endl;

for(int i=0;i<10;i++){white();cout<<i<<" ";
	for(int j=0;j<10;j++){
		if(t[i][j]==0){blue();cout<<t[i][j]<<" ";}
		else if(t[i][j]==1){green();cout<<t[i][j]<<" ";}
		else if(t[i][j]==2){green();cout<<t[i][j]<<" ";}
		else if(t[i][j]==3){green();cout<<t[i][j]<<" ";}
		else if(t[i][j]==4){green();cout<<t[i][j]<<" ";}
		else if(t[i][j]==5){green();cout<<t[i][j]<<" ";}
		else{white();cout<<t[i][j]<<" ";}}
	cout<<endl;
}}
void rozstawCOM(){
	
int a,b;
	
	for(int s=1;s<6;s++){
		srand( time( NULL ) );
		a=rand()%10,b=rand()%10;
		
		switch(s){
case 1: 
	do{ 
		a=rand()%10,b=rand()%10;
		
		if(t[a][b]==0){
			lokal[0][s][lCOM[s]][0][0]=a;
			lokal[0][s][lCOM[s]][0][1]=b;
			t[a][b]=1;  
			lCOM[s]++;
		}else{continue;}
	}while(lCOM[s]<3);
	break;
case 2:
	do{	
		a=rand()%10,b=rand()%10;
		
		if(t[a][b]==0 && (a<9 && t[a+1][b]==0) && (t[a+2][b]==0)) {
			t[a][b]=2;
			t[a+1][b]=2;
			lokal[0][s][lCOM[s]][0][0]=a;
			lokal[0][s][lCOM[s]][0][1]=b;
			lokal[0][s][lCOM[s]][1][0]=a+1;
			lokal[0][s][lCOM[s]][1][1]=b;
			lCOM[s]++;
		}else{continue;}
	}while(lCOM[s]<2);
		break;
case 3: 
	do{	
		a=rand()%10,b=rand()%10;
		
		if(t[a][b]==0 && (a<9 && t[a+1][b]==0) && (a>0 && t[a-1][b]==0)){
			t[a-1][b]=3;
			t[a+1][b]=3;
			t[a][b]=3; 
			lokal[0][s][lCOM[s]][0][0]=a;
			lokal[0][s][lCOM[s]][0][1]=b;
			lokal[0][s][lCOM[s]][1][0]=a+1;
			lokal[0][s][lCOM[s]][1][1]=b;
			lokal[0][s][lCOM[s]][2][0]=a-1;
			lokal[0][s][lCOM[s]][2][1]=b;
			lCOM[s]++;
	}else{continue;}}while(lCOM[s]<1);
		break;
case 4:
	do{ a=rand()%10,b=rand()%10;
		if(t[a][b]==0 && (b<9 && t[a][b+1]==0)){
			lokal[0][s][lCOM[s]][0][0]=a;
			lokal[0][s][lCOM[s]][0][1]=b;
			lokal[0][s][lCOM[s]][1][0]=a;
			lokal[0][s][lCOM[s]][1][1]=b+1;
			t[a][b+1]=4;
			t[a][b]=4;
			lCOM[s]++;
		}else{continue;}
	}while(lCOM[s]<2);
		break;
case 5:
	do{ a=rand()%10,b=rand()%10;
		if(t[a][b]==0 && (b<9 && t[a][b+1]==0) && (b>0 && t[a][b-1]==0)){
			lokal[0][s][lCOM[s]][0][0]=a;
			lokal[0][s][lCOM[s]][0][1]=b;
			lokal[0][s][lCOM[s]][1][0]=a;
			lokal[0][s][lCOM[s]][1][1]=b+1;
			lokal[0][s][lCOM[s]][2][0]=a;
			lokal[0][s][lCOM[s]][2][1]=b-1;
			
			t[a][b-1]=5;
			t[a][b+1]=5;
			t[a][b]=5;
			lCOM[s]++;
		}else{continue;}
	}while(lCOM[s]<1);
		break;
default:break;	
		}
	}

}

void showP(){

cout<<"  0 1 2 3 4 5 6 7 8 9\n";	
for(int i=0;i<10;i++){white();
char lit;	
		switch(i+1){
		case 1: lit='A';break;
		case 2: lit='B';break;
		case 3: lit='C';break;
		case 4: lit='D';break;
		case 5: lit='E';break;
		case 6: lit='F';break;
		case 7: lit='G';break;
		case 8: lit='H';break;
		case 9: lit='I';break;
		case 10: lit='J';break;}
	

cout<<lit;cout<<" ";
	for(int j=0;j<10;j++){green();
	if(plan[0][i][j]==1){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);cout<<"X ";white();continue;}
	if(plan[0][i][j]==2){red();cout<<"X ";white();continue;}
		if(p[i][j]==0){blue();cout<<"~ ";}
		else if (p[i][j]==1){cout<<"& ";}
		else if (p[i][j]==2){cout<<"v ";}
		else if (p[i][j]==3){cout<<"V ";}
		else if (p[i][j]==4){cout<<"< ";}
		else if (p[i][j]==5){cout<<"> ";}
		white();
	}
	cout<<endl;
}}
void ships(int t){

	if(t!=0 && t!=1 && t!=2){t=0;}


white();cout<<endl<<endl;
// LICZENIE STATKOW
  for(int i=0;i<10;i++){
	  for(int j=0;j<10;j++){
		  if(p[i][j]!=0){if(t==0 || t==1){cout<<"Element: "<<p[i][j]<<" znaleziony na wsp x:"<<i<<" y: "<<j<<endl;}}
		  if(p[i][j]==1){l[1]++;}
		  if(p[i][j]==2){l[2]++;}
		  if(p[i][j]==3){l[3]++;}
		  if(p[i][j]==4){l[4]++;}
		  if(p[i][j]==5){l[5]++;}
	  }
  }
  
  // USTAWIENIE ILOSCI STATKOW
  l[2]/=2; l[3]/=3; l[4]/=2; l[5]/=3;
 // WYŒWIETLANIE ILOSCI STATKOW
 if(t==0 || t==2)cout<<endl;for(int i=1;i<6;i++){cout<<"Ilosc statkow "<<i<<"="<<l[i]<<endl;}

}


void rozstawP(){
int statek=1,suma=0,a=0,b=0;

  	 

do
{
	

	system("cls");
	
	cout<<"  0 1 2 3 4 5 6 7 8 9\n";
for(int i=0;i<10;i++){

	char lit;	
		switch(i+1){
		case 1: lit='A';break;
		case 2: lit='B';break;
		case 3: lit='C';break;
		case 4: lit='D';break;
		case 5: lit='E';break;
		case 6: lit='F';break;
		case 7: lit='G';break;
		case 8: lit='H';break;
		case 9: lit='I';break;
		case 10: lit='J';break;}
	

cout<<lit;cout<<" ";


	for(int j=0;j<10;j++){
		if(pozycja[0]==i && pozycja[1]==j){
			if(p[i][j]!=0 || (statek==2 && p[i-1][j]!=0)){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED);}
			else{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);}
			
		}

		if(statek==2 && pozycja[0]==i  && pozycja[1]==j){
			if(  p[i][j]!=0){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);}
		}
		else if(statek==2 && i==pozycja[0]-1 && pozycja[1]==j){
			if(p[pozycja[0]][pozycja[1]]!=0 || p[pozycja[0]-1][pozycja[1]]!=0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);}
			else{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);}
		}

			
		if(statek==3 && pozycja[0]==i && pozycja[1]==j){
			if(  p[i][j]!=0 || p[i-1][j]!=0 || p[i-2][j]!=0){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);}
		}
		else if(statek==3 && (i==pozycja[0]-1 || i==pozycja[0]-2) && pozycja[1]==j){
			if(p[pozycja[0]][pozycja[1]]!=0 || p[pozycja[0]-1][pozycja[1]]!=0 || p[pozycja[0]-2][pozycja[1]]!=0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);}
			else{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);}
		}

	
		if(statek==4 && (j==pozycja[1]-1 || j==pozycja[1]) && pozycja[0]==i){
			if(p[pozycja[0]][pozycja[1]]!=0 || p[pozycja[0]][pozycja[1]-1]!=0 ){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);}
			else{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);}
		}

			if(statek==5 && (j==pozycja[1]-1 || j==pozycja[1] || j==pozycja[1]-2) && pozycja[0]==i){
			if(p[pozycja[0]][pozycja[1]]!=0 || p[pozycja[0]][pozycja[1]-1]!=0 || p[pozycja[0]][pozycja[1]-2]!=0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);}
			else{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);}
		}
			
		if(p[i][j]==0){cout<<"~ ";}//else{cout<<p[i][j]<<" ";}
		else if (p[i][j]==1){cout<<"& ";}
		else if (p[i][j]==2){cout<<"v ";}
		else if (p[i][j]==3){cout<<"V ";}
		else if (p[i][j]==4){cout<<"< ";}
		else if (p[i][j]==5){cout<<"> ";}
	white();
	}
	cout<<endl;	
}

cout<<"\nRozstaw swoje statki. \n\nRozstawiasz statek:\t";
if (statek==1){cout<<"& ";}
else if (statek==2){cout<<"v\n\t\t\tv ";}
else if (statek==3){cout<<"V\n\t\t\tV\n\t\t\tV ";}
else if (statek==4){cout<<"<< ";}
else if (statek==5){cout<<">>> ";}

znak=getch();

  switch (znak){
			 case GORA:(pozycja[0]<1) ? pozycja[0]=9:pozycja[0]--;break;
			 case DOL:(pozycja[0]>8) ? pozycja[0]=0:pozycja[0]++;;break;
			 case LEWO:(pozycja[1]<1) ? pozycja[1]=9:pozycja[1]--;break;
			 case PRAWO:(pozycja[1]>8) ? pozycja[1]=0:pozycja[1]++;break;
  }

  
 
  if(pozycja[0]==0 && statek==2){pozycja[0]=9;}
  if(pozycja[0]<2 && statek==3){pozycja[0]=9;}
  if(pozycja[1]==0 && statek==4){pozycja[1]=9;}
  if(pozycja[1]<2 && statek==5){pozycja[1]=9;}
  

  // WARUNEK PRZYPISYWANIA WARTOSCI DO POSZCZEGOLNYCH ELEMENTOW TABLICY                     
  if(statek==1 && znak==13 && p[pozycja[0]][pozycja[1]]==0){p[pozycja[0]][pozycja[1]]=statek;l[statek]++;}
  else if(statek==1 && znak==13 &&  p[pozycja[0]][pozycja[1]]!=0){ p[pozycja[0]][pozycja[1]]=0;l[statek]--;}
  
  if(statek==2 && znak==13 && p[pozycja[0]][pozycja[1]]==0 && p[pozycja[0]-1][pozycja[1]]==0){p[pozycja[0]][pozycja[1]]=statek;p[pozycja[0]-1][pozycja[1]]=statek;l[statek]++;}
  else if(statek==2 && znak==13 &&  p[pozycja[0]][pozycja[1]]!=0 && p[pozycja[0]-1][pozycja[1]]!=0){ p[pozycja[0]][pozycja[1]]=0;p[pozycja[0]-1][pozycja[1]]=0;l[statek]--;}
   
  if(statek==3 && znak==13 && p[pozycja[0]][pozycja[1]]==0 && p[pozycja[0]-1][pozycja[1]]==0 && p[pozycja[0]-2][pozycja[1]]==0){
	  p[pozycja[0]][pozycja[1]]=statek;p[pozycja[0]-1][pozycja[1]]=statek;p[pozycja[0]-2][pozycja[1]]=statek;l[statek]++;}

  if(statek==4 && znak==13 && p[pozycja[0]][pozycja[1]]==0 && p[pozycja[0]][pozycja[1]-1]==0){p[pozycja[0]][pozycja[1]]=statek;p[pozycja[0]][pozycja[1]-1]=statek;l[statek]++;}
  else if(statek==4 && znak==13 &&  p[pozycja[0]][pozycja[1]]!=0 && p[pozycja[0]][pozycja[1]-1]!=0){ p[pozycja[0]][pozycja[1]]=0;p[pozycja[0]][pozycja[1]-1]=0;l[statek]--;}

  if(statek==5 && znak==13 && p[pozycja[0]][pozycja[1]]==0 && p[pozycja[0]][pozycja[1]-1]==0  && p[pozycja[0]][pozycja[1]-2]==0 ){p[pozycja[0]][pozycja[1]]=statek;p[pozycja[0]][pozycja[1]-1]=statek;p[pozycja[0]][pozycja[1]-2]=statek;l[statek]++;}
  else if(statek==5 && znak==13 &&  p[pozycja[0]][pozycja[1]]!=0 && p[pozycja[0]][pozycja[1]-1]!=0  && p[pozycja[0]][pozycja[1]-2]!=0){ p[pozycja[0]][pozycja[1]]=0;p[pozycja[0]][pozycja[1]-1]=0;p[pozycja[0]][pozycja[1]-2]=0;l[statek]--;}

  // SUMOWANIE ELEMENTOW TABLICY GRACZA
  suma=0;for(int i=0;i<10;i++){for(int j=0;j<10;j++){suma+=p[i][j];}}

   // JEŒLI SUMA TABLIC JEST WIEKSZA NIZ 2, ZMIEN STATEK
  
  if(l[1]<3 && znak==13){statek=1;znak=0;}
  if(l[1]>2 && l[2]<2 && znak==13){statek=2;znak=0;}
  if(l[2]>1 && l[3]<1 && znak==13){statek=3;znak=0;}
  if(l[3]>0 && l[4]<2 && znak==13){statek=4;znak=0;}
  if(l[4]>0 && l[5]<1 && znak==13){statek=5;znak=0;}
  if(l[5]>0 && znak==13){znak=27;statek=0;}

}while(znak!=27 && znak!=127);  system("cls");

}
void shotP(){



do{

POWROT:
	system("cls");

	white();cout<<"  ";for(int i=0;i<10;i++){cout<<i<<" ";}cout<<endl;
for(int i=0;i<10;i++){

	char lit;	
		switch(i+1){
		case 1: lit='A';break;
		case 2: lit='B';break;
		case 3: lit='C';break;
		case 4: lit='D';break;
		case 5: lit='E';break;
		case 6: lit='F';break;
		case 7: lit='G';break;
		case 8: lit='H';break;
		case 9: lit='I';break;
		case 10: lit='J';break;}
	

cout<<lit;cout<<" ";



	for(int j=0;j<10;j++){
		if(pozycja[0]==i && pozycja[1]==j){ SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);}else{white();}			
		if(cheats==1 && t[pozycja[0]][pozycja[1]]!=0 && pozycja[0]==i && pozycja[1]==j){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN);}
		if(plan[1][i][j]==0){cout<<"~ ";}else{
			if(plan[1][i][j]==2){red();}
			if(plan[1][i][j]==2 && pozycja[0]==i && pozycja[1]==j){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);}cout<<"X ";white();}
		
	}
white(); cout<<endl;	
	}
	
	cout<<endl;showP();
	znak=getch();

  switch (znak){
			 case GORA:(pozycja[0]<1) ? pozycja[0]=9:pozycja[0]--;break;
			 case DOL:(pozycja[0]>8) ? pozycja[0]=0:pozycja[0]++;;break;
			 case LEWO:(pozycja[1]<1) ? pozycja[1]=9:pozycja[1]--;break;
			 case PRAWO:(pozycja[1]>8) ? pozycja[1]=0:pozycja[1]++;break;
  }

  if(znak==13){
	   if(plan[1][pozycja[0]][pozycja[1]]==0){plan[1][pozycja[0]][pozycja[1]]=1;cout<<endl;
	   if(t[pozycja[0]][pozycja[1]]!=0){white();
		   if(t[pozycja[0]][pozycja[1]]==1){plan[1][pozycja[0]][pozycja[1]]=2;green();points++;cout<<"Ha! Trafiony zatopiony!\n";t[pozycja[0]][pozycja[1]]=0;}
		   
		   if(t[pozycja[0]][pozycja[1]]==2){			   
			   for(int i=0;i<2;i++){
			   if(lokal[0][2][i][0][0]==pozycja[0] && lokal[0][2][i][0][1]==pozycja[1]){
				   if(t[lokal[0][2][i][1][0]][lokal[0][2][i][1][1]]!=0){plan[1][pozycja[0]][pozycja[1]]=2;green();cout<<"Trafiony!\n";}else{plan[1][pozycja[0]][pozycja[1]]=2;points+=2;green();cout<<"Ha! Trafiony zatopiony!\n";}
				   t[pozycja[0]][pozycja[1]]=0;}
			   else if(lokal[0][2][i][1][0]==pozycja[0] && lokal[0][2][i][1][1]==pozycja[1]){
				   if(t[lokal[0][2][i][0][0]][lokal[0][2][i][0][1]]!=0){plan[1][pozycja[0]][pozycja[1]]=2;green();cout<<"Trafiony!\n";}else{plan[1][pozycja[0]][pozycja[1]]=2;points+=2;green();cout<<"Ha! Trafiony zatopiony!\n";}
				   t[pozycja[0]][pozycja[1]]=0;}
			   }
		   }
		   
		   if(t[pozycja[0]][pozycja[1]]==3){
			   plan[1][pozycja[0]][pozycja[1]]=2;
		     green();cout<<"Trafiony!\n";
			 t[pozycja[0]][pozycja[1]]=0;
			   if(t[lokal[0][3][0][0][0]][lokal[0][3][0][0][1]]==0 && t[lokal[0][3][0][1][0]][lokal[0][3][0][1][1]]==0 && t[lokal[0][3][0][2][0]][lokal[0][3][0][2][1]]==0){plan[1][pozycja[0]][pozycja[1]]=2;points+=5;green();cout<<"Ha! Trafiony zatopiony!\n";}
		   
		   }
		   		   
		   if(t[pozycja[0]][pozycja[1]]==4){
		   	   for(int i=0;i<2;i++){
			   if(lokal[0][4][i][0][0]==pozycja[0] && lokal[0][4][i][0][1]==pozycja[1]){
				   if(t[lokal[0][4][i][1][0]][lokal[0][4][i][1][1]]!=0){plan[1][pozycja[0]][pozycja[1]]=2;green();cout<<"Trafiony!\n";}else{plan[1][pozycja[0]][pozycja[1]]=2;points+=2;green();cout<<"Ha! Trafiony zatopiony!\n";}
				   t[pozycja[0]][pozycja[1]]=0;}
			   else if(lokal[0][4][i][1][0]==pozycja[0] && lokal[0][4][i][1][1]==pozycja[1]){
				   if(t[lokal[0][4][i][0][0]][lokal[0][4][i][0][1]]!=0){plan[1][pozycja[0]][pozycja[1]]=2;green();cout<<"Trafiony!\n";}else{plan[1][pozycja[0]][pozycja[1]]=2;points+=2;green();cout<<"Ha! Trafiony zatopiony!\n";}
				   t[pozycja[0]][pozycja[1]]=0;		   }
			   }
		   }
		   if(t[pozycja[0]][pozycja[1]]==5){
		   plan[1][pozycja[0]][pozycja[1]]=2;
			green();    cout<<"Trafiony!\n";
			 t[pozycja[0]][pozycja[1]]=0;
			   if(t[lokal[0][5][0][0][0]][lokal[0][5][0][0][1]]==0 && t[lokal[0][5][0][1][0]][lokal[0][5][0][1][1]]==0 && t[lokal[0][5][0][2][0]][lokal[0][5][0][2][1]]==0){plan[1][pozycja[0]][pozycja[1]]=2;points+=5;cout<<"Ha! Trafiony zatopiony!\n";}
		   }			   

		   /*int s=t[pozycja[0]][pozycja[1]],limit;
		   for(i=0;i<3;i++){
			  
				   switch(s){
				   case 1:limit=3;break;
				   case 2:limit=2;break;
				   case 3:limit=1;break;
				   case 4:limit=2;break;
				   case 5:limit=1;break;}
					 for(j=0;j<limit;j++){	
						 if(lokal[0][s][i][j][0]==pozycja[0] && lokal[0][s][i][j][0]==pozycja[1]){
							if(int }
			   }
		   }*/
		  // cout<<"Shot!\n";

	   }else{white();cout<<"Pudlo! \n";points--;}}else{white();cout<<"\nJuz tutaj strzeales!\n";}
		

  
  }
  
  if(znak==27){
	  
	  char pick;
	  int choice=0;
	  
	  do{
		  system("cls"); white();
	  cout<<"Czy na pewno chcesz opuscic gre?\n";
		 
		  if(choice==0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);}
		  cout<<"TAK";white();cout<<"\t";
		  if(choice==1){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);}
		  cout<<"NIE";white();


		  pick=getch();
		  switch(pick){
		  case LEWO: choice=0; break;
		  case PRAWO: choice=1; break;}
	  }while(pick!=13 && pick !=27);

	  if((pick==13 && choice ==1) || pick==27){goto POWROT;}
	  
// JESLI UZYTKOWNIK WYBIERZE, ZE CHCE ZAKONCZYC GRE

	  if(pick==13 && choice ==0){
		  char pick;	  int choice=0;
		  
		  do{
			  system("cls"); white();
			  cout<<"Czy chcesz zapisac swoja gre?\n";

			  if(choice==0){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);}
			  cout<<"TAK";white();cout<<"\t";
			  if(choice==1){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);}
			  cout<<"NIE";white();


			  pick=getch();
			  switch(pick){
		  case LEWO: choice=0; break;
		  case PRAWO: choice=1; break;}
		  }while(pick!=13 && pick !=27);

		  // JESLI NIE CHCE ZAPISAC, REZGYDNUJEMY

		if(pick==13 && choice ==1){rezygnacja=2;}
		// JESLI CHCE ZAPISAC, ZAPISUJEMY...
		if(pick==13 && choice ==0){		
			 ofstream save("cships.csh");
			 if(save.good() == true ){
			cout<<"\n\nZapis pomyslny\n\n";
			
			
			

for(int i=0;i<10;i++){for(int j=0;j<10;j++){save<<p[i][j]<<" ";}}
save<<"\n";
for(int i=0;i<10;i++){for(int j=0;j<10;j++){save<<t[i][j]<<" ";}}

for(int i=0;i<2;i++){
	for(int j=0;j<6;j++){
		for(int h=0;h<3;h++){
			for(int k=0;k<3;k++){
				for(int z=0;z<2;z++){
					save<<lokal[i][j][h][k][z]<<" ";
				}
			}
		}
	}
}
save<<"\n";
for(int i=0;i<2;i++){
	for(int j=0;j<10;j++){
		for(int h=0;h<10;h++){
			save<<plan[i][j][h]<<" ";
		}
	}
}



			
			


save<<"\n";
save<<pozycja[0]<<" "<<pozycja[1]<<"\n";
save<<points<<"\n";
save.close(); rezygnacja=2;
			 }

			
		}
		
	  }
// W PRZECIWNYM WYPADKU
	  
  }

  if(znak==96){cout<<"Konsola otwarta. Wpisz polecenie: ";getline(cin,cmd);
  if(cmd=="/cheat"){ cout<<((cheats==0) ? "Kody zostaly aktywowane.":"Kody zostaly wylaczone");(cheats==0) ? cheats=1:cheats=0;cin.get();}
  if(cmd=="/lose"){rezygnacja=1;}
  if(cmd=="/hscr"){ofstream high("hsc.csh");}
  
  }
 
}while(znak!=13 && znak!=27 && znak!=127);
}
void shotCOM(){
	int a,b;
	
	for(;;){
		srand( time( NULL ) );
		a=rand()%10,b=rand()%10;
	if(plan[0][a][b]==1){continue;}else{
		int c=a;
		char lit;
		switch(c+1){
		case 1: lit='A';break;
		case 2: lit='B';break;
		case 3: lit='C';break;
		case 4: lit='D';break;
		case 5: lit='E';break;
		case 6: lit='F';break;
		case 7: lit='G';break;
		case 8: lit='H';break;
		case 9: lit='I';break;
		case 10: lit='J';break;}
		if(p[a][b]==0){white();cout<<"Przeciwnik strzela w punkt "<<lit<<":"<<b<<" i nie trafia w zaden obiekt!";plan[0][a][b]=1;}else{red();cout<<"Przeciwnik strzela w punkt "<<lit<<":"<<b<<" i trafia!";p[a][b]=0;points-=3;plan[0][a][b]=2;}
		break;}
	}
	
}
void play(){
	if(cnd==0){rozstawP();}


do{
	shotP();
	if(rezygnacja==0){
	shotCOM();
	cin.get();}
	
	sumaP=0;sumaCOM=0;
	//shotCOM();
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			sumaCOM+=t[i][j];
			sumaP+=p[i][j];
		}
	}
	white();
	if(rezygnacja==1){sumaP=0;}
	if(cmd=="/win"){sumaCOM=0;cmd="";}
	
	
}while(sumaCOM>0 && sumaP>0 && rezygnacja!=2);system("cls");

if(sumaCOM>0 && rezygnacja!=2){cout<<"Przegrales!";}else{cout<<"Gratuluje! Wygrales!";}


if(rezygnacja!=2){cout<<"Twoj wynik to: "<<points;cout<<"\n\nPodaj swoje imie: ";getline(cin,name);
if(name==""){name="GRACZ";}
if(name.length()>5){name.resize(5);}

hisc();rezygnacja=0;}




}

void cont(){

	fstream plik;
	plik.open( "cships.csh", std::ios::in | std::ios::out );

	if(plik.good() == true)
	{	
		/*		t[10][10];
p[10][10];
lokal[2][6][3][3][2];
plan[2][10][10];
pozycja[2];*/

for(int i=0;i<10;i++){for(int j=0;j<10;j++){plik>>p[i][j];}}
for(int i=0;i<10;i++){for(int j=0;j<10;j++){plik>>t[i][j];}}

for(int i=0;i<2;i++){
	for(int j=0;j<6;j++){
		for(int h=0;h<3;h++){
			for(int k=0;k<3;k++){
				for(int z=0;z<2;z++){
					plik>>lokal[i][j][h][k][z];
				}
			}
		}
	}
}

for(int i=0;i<2;i++){
	for(int j=0;j<10;j++){
		for(int h=0;h<10;h++){
			plik>>plan[i][j][h];
		}
	}
}

plik>>pozycja[0];
plik>>pozycja[1];
plik>>points;
	}
				plik.close();
				play();

}

void wyniki(){
	string GRACZ[2][10];
	int WYNIK[2][10];
	int max=0;

	for(int i=0;i<2;i++){for(int j=0;j<10;j++){GRACZ[i][j]="";WYNIK[i][j]=0;}}


	fstream high;
	high.open("hsc.csh");
if(high.good() == true){
	for(int i=0;i<10;i++){high>>GRACZ[0][i];
	high>>WYNIK[0][i];}
	


	
	

	
	for(int j=0;j<10;j++){
		for(int i=0;i<10;i++){if(WYNIK[0][i]>max){max=WYNIK[0][i];}}
		for(int i=0;i<10;i++){if(WYNIK[0][i]==max ){WYNIK[0][i]=0;break;}}

		

		
		

		
		WYNIK[1][j]=max;
		max=0;}






	for(int i=0;i<10;i++){cout<<i+1<<".\t"<<WYNIK[1][i]<<"\t"<<GRACZ[0][i]<<endl;}
}
}