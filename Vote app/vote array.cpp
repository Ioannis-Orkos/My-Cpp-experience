#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

#define yoha(x) cout << "\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 "<< x <<"  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
#define nic(x) cout << "\n\n\t\t\xDB\xDB\xDB\xDB\xB2"<<x<<endl;
#define wor "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";

void addmenu();
int main();
void about();
int counterv=0 ,counterc=0,counterp=0, voterc[99],canidatec[99],passv,passc,pointv[99],pointc[99],rank[99],po=0;;
string votern[99],canidaten[99],jump[99], pw;

void load()
{
 ifstream lfile;
		   lfile.open("Canidate.txt");
		   if (lfile.fail()){
			   ofstream llfile;
		       llfile.open("Canidate.txt");
			   cout << "c it fail";
			   llfile << "list" <<setw(24)<< "CanidateID"<<setw(24) <<"CanidateName" <<endl;
               llfile.close();
		       lfile.close();
		   } 
		   else  {
		   
		   lfile >> jump[1] >> jump[2] >>jump[3] ;
		   
		   while(!lfile.eof()) 
		   {
			 lfile >> setw(2)>>counterc;
          	 lfile >> setw(12)>>canidatec[counterc];
			 lfile >> setw(12)>>canidaten[counterc] ;
			     counterc++;
				  }
		   
		               counterc--;
			        lfile.close();                       
		           
		   }
		 
ifstream sfile;
		   sfile.open("voter.txt");
		   if (sfile.fail()){
               ofstream ssfile;
		       ssfile.open("Voter.txt");
			   cout << "v it fail";
			   ssfile << "list"<<setw(12)<< "Voterid"<<setw(12)<<"Votername"<<endl;
               ssfile.close();
		   }
		   else  {
		   sfile >> jump[1] >> jump[2] >>jump[3] ;
		     
		   while(!sfile.eof()) 
		   {
			 
			 sfile >> setw(2)>>counterv;
			 sfile >> setw(8)>>voterc[counterv] ;
			 sfile >> setw(8)>>votern[counterv] ;
			 counterv++;  
			}  
			   		     counterv--;  
				          sfile.close();      
		                       
		                                               }

	sfile.close();
	lfile.close();

ifstream pfile;
		   pfile.open("point.txt");
		   if (pfile.fail()){
               ofstream pwfile;
		       pwfile.open("point.txt");
			   cout << "p it fail";
			   pwfile << "list"<<setw(12)<< "VoterC"<<setw(12)<<"canidateC"<<endl;
      
               pwfile.close();
		   }
		   else  {
		   pfile >> jump[1] >> jump[2] >>jump[3] ;
		   while(!pfile.eof()) 
		   {
			 pfile >> setw(2)>>counterp;
			 pfile >> setw(8)>>pointv[counterp] ;
			 pfile >> setw(8)>>pointc[counterp] ;
			 counterp++;  
			}  
			   		   
		                 counterp--;  
		                pfile.close();      
		                       
		                                               }

	pfile.close();

}
void back()
{
         char bk=getch();
		 if (bk=='\b') main();
return;
}
int password()
{
string x="goadd";
if (pw==x) return 1;
system("cls");
cout << "\n\n\n\n\t\t*********** Unlock The Admin Mode ***********\n\n";
cout <<"\t\t\xDB\xDB\xDB\xDB\xB2 Enter PassWord:->";
cin>>pw;
if (pw==x) return 1;
else { cout << "\a\n\n\t\tWrong PassWord!!Please Entered correct PassWord";
getch();
}
return 0;
}

void viewv()
{

system("cls");
yoha("Voters View Menu");
cout << "\n\n\t\t\tList"<<setw(12)<< "VotertId"<<setw(12)<<"VotertName"<<endl;
for (int x =0;x<counterv;x++)
			  {
			 cout << setw(26)<<x+1;
			 cout << setw(12)<<voterc[x] ;
			 cout << setw(12)<<votern[x]<<endl ;
			  }
                getch();
		   	    addmenu( );
			   }

 void viewc()
{
system("cls");
yoha("Canidates View Menu");
cout << "\n\n\t    List" <<setw(24)<< "canidateId"<<setw(24) <<"canidateName" << endl;
for (int x =0;x<counterc;x++)
			  {
			 cout << setw(14)<<x+1;
			 cout << setw(24)<<canidatec[x];
			 cout << setw(24)<<canidaten[x] << endl ;
			  }
getch();
addmenu( );
}

 void viewp()
{

system("cls");
yoha("Hidden View ");
cout << "\n\n\t    List" <<setw(24)<< "voterc"<<setw(24) <<"canidatec" << endl;
for (int x =0;x<counterp;x++)
			  {
			 cout << setw(14)<<x+1;
			 cout << setw(24)<<pointv[x];
			 cout << setw(24)<<pointc[x] << endl ;
			  }
getch();
addmenu( );
}

int checkv(int x)
{
	for (int i=0; i<counterv;i++)
		{
			if  (x == voterc[i] )  {
			                      passv=i;
			                      return 1;	
						         	}    
								  }
			return 0;
				}
				
int checkc(int x)
{
	for (int i=0; i<counterc;i++)
		{
			if  (x == canidatec[i] ) {
			                        passc=i;
			                        return 1; }
		}
			return 0;
				}

int pointcc (int x) 
{
	for (int i=0; i<counterp;i++)
		if  (pointv[i] == x ) 
			                        return 1; 
		
			return 0;
				}
  
void savep()
{
              ofstream vfile;
		      vfile.open("point.txt",ios::app);
	         
			     vfile << setw(2)<<counterp;
		     	 vfile << setw(12)<<pointv[counterp] ;
			     vfile << setw(12)<<pointc[counterp]<<endl ;
			  
			     vfile.close();
                
}
 
void point()
{
system("cls");
cout << "\n\n\n\t\t  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 VOTE MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	
if(counterv==0) {cout << "\n\n\t\t\xDB\xDB\xDB\xDB\xB2 No Voter Member in the list ";
                    getch();
					main();
					return;
               }
if(counterc==0) {cout << "  \n\n\t\t\xDB\xDB\xDB\xDB\xB2 No Canidate Member in the list ";
                    getch();
				    main();
					return;
               }
cout << "  \n\n\t\t\xDB\xB2  Enter voter code:->"  ;
cin >> pointv[counterp];
if (!(checkv(pointv[counterp])))      { cout << "  \n\n\t\t      \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2 Voter Not Exist \xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB";
                                          back();
										  point();
                                          return;
                           }
if (pointcc(pointv[counterp]))     { cout << " \n\n\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2  Already voted \xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB";
                                            back();
										   point();
                                           return;
						   }
wv:  ;
cout << "    \n\n\t\t********* What  *" << votern[passv] <<"* Want To Vote *********";                           
cout << "  \n\n\t\t\xDB\xB2 Enter Canidate Code:->";
cin >> pointc[counterp];
if (!(checkc(pointc[counterp])) )     { cout << "\n\n\t\t \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2 Canidate Not Exist \xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB";
                                          back();
										  goto wv;
                                          return;       
						   }

cout <<  "\n\t*********IF Your Vote Is Not  *" <<  canidaten[passc]  << "* Press The C Buton*********** ";
cout <<  " \n\t\t*********Else Press Any Other Key*********";

char c = getch(); 
if (c=='c')      {      point();
                        return;
                                           }

cout << "   \n\n\n\n\n\t\t^^^^^^^^^^^^  *"<< votern[passv] <<"* Voted For *" << canidaten[passc]<<"* ^^^^^^^^^^^^";

savep();
counterp++;
getch();
main();
}
				
void savev()
{
              ofstream vfile;
		      vfile.open("voter.txt",ios::app);
	       
			     vfile << setw(2)<<counterv;
		     	 vfile << setw(12)<<voterc[counterv] ;
			     vfile << setw(12)<<votern[counterv]<<endl ;
			  
			     vfile.close();
                
}
 
void savec()
{
              ofstream vfile;
		      vfile.open("canidate.txt",ios::app);
		     
			     vfile << setw(2)<<counterc;
		     	 vfile << setw(12)<<canidatec[counterc] ;
			     vfile << setw(12)<<canidaten[counterc]<<endl ;
			  
			     vfile.close();
                
}

void addvoter()
{
system("cls");
yoha("ADD VOTER MANU");
	
cout << "\n\n\t\t\xDB\xDB\xB2 Enter Voter Name:->";
cin >> votern[counterv];
cout <<"\n\t\t\xDB\xDB\xB2 Enter Voter Code:->";
cin >> voterc[counterv];

if (checkv(voterc[counterv])) { cout << "\n\t\t\xDB\xDB\xDB\xDB\xB2 Voter Existed \xB2\xDB\xDB\xDB\xDB ";
                                             back();
										    addvoter();
                                            return;
						   }
else {

savev();
counterv++;
cout << "\n\n\t\t\tSuccessfuly Added";
getch();
		 addmenu();
}
}

void addcanidate()
{
system("cls");
yoha("Add Canidate Menu");	
cout << "\n\n\t\t\xDB\xDB\xDB\xDB\xB2 Enter Canidate Name:->";
cin >> canidaten[counterc];
cout << "\n\t\t\xDB\xDB\xDB\xDB\xB2 Enter Canidate Code:->";
cin >> canidatec[counterc];

if (checkc(canidatec[counterc])) {cout << "\n\t\t\xDB\xDB\xDB\xDB\xB2 Canidate Existed \xB2\xDB\xDB\xDB\xDB";
                                         back();
										addcanidate();
                                        return;                       
						   }
else {
savec();
counterc++;
cout << "\n\n\t\t\tSuccessfuly Added";
getch();
addmenu();
}

}

int sort(int rankc[])
{

for (int x =0 ;x<counterc;x++)
      {
if (rankc[po] < rankc[x] )   {
                           po=x;
                           
					          }	   
							}

return po;
}

void ranker()
 {
   
   for(int i=0;i<counterc;i++)
	 {
  		if (rank[i]<0) rank[i]=0;
 		int  z=0;
   		for(int j=0;j<counterp;j++)
   		if ( canidatec[i]== pointc[j]  ) { z++;
                                           rank[i] = z; 
               
                                           }  
											 }
	system("cls");
	cout << "\n\n\n\t    \xB2\xB2 Press BackSpace To Return To The Main Manu \xB2\xB2";
	yoha("Rank Menu");
	cout << "\n\n\tRank" <<setw(24)<< "CanidateName"<<setw(24) <<"Point" << endl;
    if (counterp==0) {  cout << "    \n\n\t\t    ********* No Vote  *********";
                       getch();
					   main();
	}
		for (int x =0 ;x<counterc;x++)
			   {
			 int po =sort(rank);
			 
			 cout << setw(10)<<x+1;
			 cout << setw(24)<<canidaten[po];
			 if (rank[po]==-10)  cout << setw(24)<<0 << endl ;
			 else cout << setw(24)<<rank[po] << endl ;
			 rank[po]=-10;
    }
	     getch();
		 main();
         
 }

void addmenu()
{

system("cls");
	if (!password()) {main();}
	starta :
	system("cls");
	cout << "\n\t\t\xB2\xB2 Press BackSpace To Return To The Main Manu \xB2\xB2";
	yoha("Add Menu");  
	nic(" 1. To Add  Voter");
	nic(" 2. To Add  Canidate");
	nic(" 3. To view Voter ");
	nic(" 4. To view Canidate ");
	nic(" 5. To Lock Admin Mode");
	nic(" 6. To Exit");
cout <<  "\n\n\t\t"<<  wor;
	cout << "\n\n\t\tEnter your choice:";
   	
    	switch(getch()) {
            case '1':
                 addvoter();
                 break; 
            case '2':
                addcanidate();
                break;
			case '3':
                viewv();
                break; 
            case '4':
                viewc();
                break;
            case 'h' :
			  viewp();		
			case '5':
			    pw="none";
			    main();
				break;
			case '6':
			   exit(0);	
			   break;	  
		    case '\b':
                 main();
				 break;
			default:
                cout << "\a\n\n\t\t\tsyntax error try again";
                getch();
                goto starta;
                               	}
}

int main ()
{
load();
 {

startm :
	system("cls");
	yoha("Main Menu");
	nic(" 1. To Vote");
	nic(" 2. To Add Members");
	nic(" 3. To View Canidate Status");
	nic(" 4. About");
	nic(" 5. To Exit");
	cout <<  "\n\n\t\t"<<  wor;
	cout << "\n\n\t\tEnter your choice:";
	switch(getch()) {
            case '1':
                point();
                break; 
            case '2':
                addmenu();
                break;
            case '3':
                ranker();
                break;
			case '4' :
				about();
				break;
			case '5' :
			   exit(0);
			   break;
			default:
            	cout << "\a\n\n\t\tWrong Entry!!Please re-entered correct option";
                getch();
				goto startm;
		
		  
	
	} 	

 getch();
 
}
return 0;
}

void about()
	{
	system("cls");	
	cout << "\n\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 PROGRAMER \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	cout << "\n\n\t\t\xDB\xDB\xDB\xDB\xB2";
    Sleep(1000); cout <<"\aY";  Sleep(500); cout <<"\aO";Sleep(500); cout <<"\aH";Sleep(500); cout <<"\aA";  
	Sleep(500); cout <<"\aN";Sleep(500); cout <<"\aN"; Sleep(500); cout <<"\aI"; Sleep(500); cout <<"\aS"; Sleep(500);cout <<"  "; Sleep(500);
	Sleep(1000); cout <<"\aN";  Sleep(500); cout <<"\aI";Sleep(500); cout <<"\aC";Sleep(500); cout <<"\aO"; Sleep(500);cout <<"\aS (Ioannis Orkos)";Sleep(500); 

	cout << "\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	Sleep(3500);
	main();
	}
                                                                                                                      



