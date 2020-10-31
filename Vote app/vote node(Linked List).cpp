#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <fstream>
#include <windows.h>
#include <stdlib.h>

using namespace std;

#define yoha(x) cout << "\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 "<< x <<"  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
#define nic(x) cout << "\n\n\t\t\xDB\xDB\xDB\xDB\xB2"<<x<<endl;
#define wor "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";



struct vcnode
{
int id;
string name;
int age;
string city;
vcnode *nxt;
};

struct pnode
{
int vid;
int cid;
string name;
pnode *nxt;
};

void addmenu(); 
void about();
int main();
void displayp ( pnode *hdp,char x );
void insertlp (pnode *&hd, pnode *temp);

string pw;
pnode  *heads =    NULL;
pnode  *headr =    NULL;
vcnode *headv =    NULL;
vcnode *headc  =   NULL;
pnode  *headp =    NULL;
//int jump[5]; 
/*
void sort (pnode *hdr )
{
pnode *y = hdr;
heads=NULL;

pnode *x = hdr;
while(x!=NULL)
{
 pnode *po = new pnode;
 int q=0,s=0;

pnode *y1 = heads;
while( y1 != NULL)
{

if (y1->vid==x->vid)  {    	q=1; 
                            break; 							
							}   
                        
                         po->cid=x->cid;
            	         po->vid=x->vid;  
				         po->name=x->name;
						 po->nxt=NULL;
y1=y1->nxt;
}
                            if (q==1) {     x=x->nxt; 
                                            continue;}

while(y!=NULL)
{

if ( po->cid < y->cid  )  { po->cid=y->cid;
            	            po->vid=y->vid;  
				            po->name=y->name; 
						    po->nxt=NULL;
			                y->cid=-1;
                            s=1;				   
				   }
				   y=y->nxt;			             
}

insertlp(heads,po);
if (s==1) continue;
x=x->nxt;
}

displayp(heads , 'r' );
return ;
}
*/

void sort (pnode *hdr )
{

pnode *x = hdr;
heads=NULL;


while(x!=NULL)
{
pnode *y1 = heads;
while( y1 != NULL)
{
if (y1->vid==x->vid)    x->cid=-1; 	
y1=y1->nxt;
}

                            pnode *po = new pnode;
                         	po->cid=x->cid;
            	            po->vid=x->vid;  
				            po->name=x->name;
						    po->nxt=NULL;

pnode *y = hdr;
while(y!=NULL)
{
pnode *y2 = heads;
while( y2 != NULL)
{
if (y2->vid==y->vid)    y->cid=-1; 	
y2=y2->nxt;
}
if ( x->cid < y->cid  )  { 	po->cid=y->cid;
            	            po->vid=y->vid;  
				            po->name=y->name;
						    po->nxt=NULL;			   
			             
				   }
				   y=y->nxt;			             
}

insertlp(heads,po);
x=x->nxt;
}

displayp(heads , 'r' );
return ;
}


int rank(vcnode *hdc, pnode *hdp)
{
if (hdp==NULL) {   cout << "/nList Empty ";
                               return 0;                }
vcnode *i=hdc;
while (i!=NULL )
{
int x=0;
pnode *z = new pnode;

pnode *j=hdp;
while( j!=NULL)
{
if ( i->id == j->cid)     x++;
                          
                           z->vid=i->id;
                           z->name=i->name; 
						   z->cid=x;
                           z->nxt=NULL;					  	   
j=j->nxt;
}
i=i->nxt;
insertlp(headr,z);
}
sort(headr);

return 0;
}

void insertl (vcnode *&hd, vcnode *temp)
{
vcnode *temp1=hd;
if ( hd  == NULL ) hd =temp;
else {
while(temp1->nxt!=NULL)
temp1=temp1->nxt;
temp1->nxt=temp;

}

return;
}

void insertlp (pnode *&hd, pnode *temp)
{
pnode *temp1 = new pnode;
if ( hd  == NULL ) hd =temp;
else {
temp1=hd;
while(temp1->nxt!=NULL)
temp1=temp1->nxt;
temp1->nxt=temp;
}
return;
}

void back()
{
         char bk=getch();
		 if (bk=='\b') main();
return;
}

int password()
{
string x="g";
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

void load()
{

heads =    NULL;
headr =    NULL;
headv =    NULL;
headc  =   NULL;
headp =    NULL;

 ifstream lfile;
		   lfile.open("Canidate.txt");
		   if (lfile.fail()){
			   ofstream llfile;
		       llfile.open("Canidate.txt");
			   cout << "c it fail";
			   //llfile <<setw(12)<<"ID"<<setw(12)<< "Name"<<setw(12)<<"Age"<<setw(12)<<"City"<<endl;
               llfile.close();
		       lfile.close();
		   } 
		   else  {
		   
		 //  lfile >> jump[1] >> jump[2] >>jump[3] >> jump[4];
		   
		   
		   
		   while(!lfile.eof()) 
		   {
		
			 vcnode *temp=new vcnode;
		     
			 lfile >> setw(2)>>temp->id;
          	 lfile >> setw(12)>>temp->name;
			 lfile >> setw(12)>>temp->age ;
			 lfile >> setw(12)>>temp->city ;
			 temp->nxt=NULL;
			 if (temp->age > 0) insertl(headc,temp); 
			 
				  }
		   
			        lfile.close();                       
		           
		   }
	 
ifstream sfile;
		   sfile.open("voter.txt");
		   if (sfile.fail()){
               ofstream ssfile;
		       ssfile.open("Voter.txt");
			   cout << "v it fail";
			   //ssfile  <<setw(12)<<"ID"<<setw(12)<< "Name"<<setw(12)<<"Age"<<setw(12)<<"City"<<endl;
               ssfile.close();
		   }
		   else  {
		//   sfile >> jump[1] >> jump[2] >>jump[3] >> jump[4];
		     
			 
		   
		   while(!sfile.eof()) 
		   {
			 vcnode *tempp=new vcnode;
			  
			 sfile >> setw(2)>>tempp->id;
          	 sfile >> setw(12)>>tempp->name;
			 sfile >> setw(12)>>tempp->age ;
			 sfile >> setw(12)>>tempp->city ;
			 tempp->nxt=NULL;
			 if (tempp->age > 0) insertl(headv,tempp);
			 			}  
			   		    
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
			  // pwfile << "list"<<setw(12)<< "VoterC"<<setw(12)<<"canidateC"<<endl;
      
               pwfile.close();
		   }
		   else  {
		 //  pfile >> jump[2] >>jump[3] ;
		   
		   
		   
		   while(!pfile.eof()) 
		   {
		 	 pnode *ptemp=new pnode;
			 pfile >> setw(8)>>ptemp->vid;
			 pfile >> setw(8)>>ptemp->cid ;
			 ptemp->nxt=NULL;
		     if (ptemp->cid > 0)	insertlp(headp,ptemp);
			}  
			   		   
		               
		                pfile.close();      
		                       
		                                               }

	pfile.close();

}

void savev(vcnode *hdp,int x)
{
              ofstream vfile;
		     if ( x == 1) { vfile.open("Canidate.txt",ios::app);  }
             else {vfile.open("voter.txt",ios::app);             }

if (hdp==NULL) {   cout << "/nList Empty ";
                            return;                }	       
			     vfile << setw(2)<<hdp->id ;
		     	 vfile << setw(12)<<hdp->name ;
			     vfile << setw(12)<<hdp->age ;
			     vfile << setw(12)<<hdp->city ;
			     vfile << setw(12)<<endl ;
				 vfile.close();
                
}
 
void savep ( pnode *hdp )
{

	ofstream vfile; 
	vfile.open("point.txt",ios::app);
if (hdp==NULL) {   cout << "/nList Empty ";
                            return;                }

                 vfile << setw(12)<<hdp->vid ;
			     vfile << setw(12)<<hdp->cid ;
			     vfile << setw(12)<<endl ;
				 vfile.close();
}

void displayvc ( vcnode *hd )
{
system("cls");
if (hd==NULL) {            cout << "/nList Empty ";
                            return;                }
cout << "\n"<<setw(13)<<"ID"<<setw(12)<< "Name"<<setw(12)<<"Age"<<setw(12)<<"City\n"<<endl;
while( hd !=NULL )
{
cout << setw(12)<<hd->id<< setw(12)<< hd->name<< setw(12)<<hd->age <<setw(12) <<hd->city <<"\n";
hd=hd->nxt;
}
getch();
addmenu();
return;
}

void displayp ( pnode *hdp , char x)
{
int z = 1;
system("cls");
if (hdp==NULL) {  cout << "    \n\n\t\t    ********* No Vote  *********";
                       getch();
					   main();                }
if (x=='p') {   yoha("Hidden View ");
                cout << "\n\n\t    List" <<setw(24)<< "voterc"<<setw(24) <<"canidatec" << endl;  
while( hdp!=NULL )
{
cout <<setw(14)<<z++ <<setw(24)<<hdp->vid<< setw(24)<< hdp->cid <<endl;
hdp=hdp->nxt;
}
 getch();
 addmenu();
  return;       
} 


if (x=='r') { 	yoha("Rank Menu");
               	cout << "\n\n\t    Rank" <<setw(24)<< "CanidateName"<<setw(24) <<"Point" << endl;
while( hdp!=NULL )
{
cout <<setw(14)<<z++ <<setw(24)<<hdp->name<< setw(24)<< hdp->cid <<endl;
hdp=hdp->nxt;
}
}

         getch();
		 main();
  return;       
}

int check ( vcnode *hd, vcnode *hde )
{
while( hd!=NULL )
{
if(hd->id==hde->id ) 			 return 1;  
hd=hd->nxt;
}
return 0;
}

int checkpa (vcnode *hd, vcnode *hde,pnode *hdp )
{
while( hdp!=NULL )
{
if(hdp->vid==hde->id)  return 1;  
hdp=hdp->nxt;
}
return 0;
}

void vote ( pnode *&head )
{
system("cls");
cout << "\n\n\n\t\t  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 VOTE MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";


if(headv==NULL) {cout << "\n\n\t\t\xDB\xDB\xDB\xDB\xB2 No Voter Member in the list ";
                    getch();
					main();
					return;
               }
if(headc==NULL) {cout << "  \n\n\t\t\xDB\xDB\xDB\xDB\xB2 No Canidate Member in the list ";
                    getch();
				    main();
					return;
               }
pnode  *temp = new pnode;
pnode  *temp1 = new pnode;
vcnode *tempv = new vcnode;


cout << "  \n\n\t\t\xDB\xB2  Enter voter code:->"  ;
cin >> tempv->id ;

if ((check(headv,tempv)) && !(checkpa(headv,tempv,headp)) )   temp->vid=tempv->id;  

else  {
	if  (!check(headv,tempv))  {cout << "  \n\n\t  ******************* Voter Not Existt ******************* ";
                                          back();
										  vote(headp);
                                          return; }
	if  (checkpa(headv,tempv,headp))  { cout << " \n\n\t  *******************  Already voted ******************* ";
                                            back();
										   vote(headp);
                                           return;
						   }
		} 
wv:
cout << "  \n\n\t\t\xDB\xB2 Enter Canidate Code:->";
cin >> tempv->id ;

if (check(headc,tempv))  { temp->cid=tempv ->id; 
                                  temp->nxt=NULL; 
								                      } 
else   { cout << "\n\n\t  ******************* Canidate Not Exist ******************* ";
                                          back();
										  goto wv;
                                          return;       
						   }
		

savep(temp);
insertlp(head,temp);
getch();
main();
}

void insert ( vcnode *&head , int x )
{

vcnode *temp  = new vcnode;
vcnode *temp1 = new vcnode;
 
if (x==1)  {  system("cls");
               yoha("Add Canidate Menu");  
			   cout <<"\n\n\t\t\xDB\xDB\xB2 Enter Canidate Code:->";
             }
          else { system("cls");
                 yoha("ADD VOTER MANU");      
				 cout <<"\n\n\t\t\xDB\xDB\xB2 Enter Voter Code:->";
          }
cin >> temp->id;


cout << "\n\t\t\xDB\xDB\xB2 Enter Age:->";
cin >> temp->age;

if (temp->age < 18) {  cout << "\n\n\t\t   **** Sorry You Cann't participate Under age **** ";
                                 getch();
                                 addmenu();
							     return; 
						        }
cout << "\n\t\t\xDB\xDB\xB2 Enter City:->";
cin >> temp->city;

cout << "\n\t\t\xDB\xDB\xB2 Enter Name:->";
cin >> temp->name;
temp->nxt=NULL;

a:
if (x==1) {
if (check(headc,temp)) {   cout << "\n\n\t\t   **** Sorry"<< temp->name <<" Code Aready existed ****";
                                     cout <<"\n\n\t\t\xDB\xDB\xB2 Enter Another Code:->";
									 cin >> temp->id;
                                     goto a;
                                              } 
											  }
else {
if (check(headv,temp))   {   cout << "\n\n\t\t   **** Sorry "<< temp->name <<" Code Aready existed ****";
                                     cout <<"\n\n\t\t\xDB\xDB\xB2 Enter Another Code:->";
									 cin >> temp->id;
                                     goto a;
                                              } 
											  }

savev(temp,x);
insertl(head,temp);

cout << "\n\n\t\t\tSuccessfuly Added" ;
getch();
addmenu();
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
                 insert(headv,0);
                 break; 
            case '2':
                 insert(headc,1);
                 break;
			case '3':
               displayvc ( headv );
                break; 
            case '4':
               displayvc ( headc );
                break;
            case 'h' :
			   displayp ( headp,'p' );		
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
                vote(headp);
                break; 
            case '2':
                addmenu();
                break;
            case '3':
                rank(headc,headp );
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
	cout << "\n\n\t\t\xDB\xDB\xDB\xDB\xB2 ";
    Sleep(1000); cout <<"\aY";  Sleep(500); cout <<"\aO";Sleep(500); cout <<"\aH";Sleep(500); cout <<"\aA";  
	Sleep(500); cout <<"\aN";Sleep(500); cout <<"\aN"; Sleep(500); cout <<"\aI"; Sleep(500); cout <<"\aS"; Sleep(500);cout <<"  "; Sleep(500);
	Sleep(1000); cout <<"\aN";  Sleep(500); cout <<"\aI";Sleep(500); cout <<"\aC";Sleep(500); cout <<"\aO"; Sleep(500);cout <<"\aS (Ioannis Orkos)";Sleep(500); 
	Sleep(3500);
	main();
	}






