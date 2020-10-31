#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include<windows.h>

    using namespace std;
	float convert (string a,float b);
int main()
{
	  float x[99],y[99],k,l;
	  string name[99],save,ext;
	  string subra[99][99];
	  string subna[99][99];
	  int entered,subc[99];
	 
	  float gpa[99][99],subcr[99][99];
	  float Gpa;
	  char stop,wa;
	  
 
   entered=0;
   do{ 
    		  
system("cls");
		      ++entered;
  
cout << " \n " ;
 
	cout << " \t\t\t              ::::           :::: \n";
	cout << "\t\t            ::::::::Cumulative GPA calculator::::: \n" ;
	cout << " \t\t\t              ::::           :::: \n";
	  
	cout << "\nEnter The Student's Name:->" ;
          	      cin >> name[entered];
		  
	cout << "\nHow many Subject do you want to calculate\nHere:->";
                   cin >> subc[entered]; 
				  
				   for (int co=1;co<=subc[entered];co++){
					            cout << "\n###################################################";
					            cout << "\n\nEnter Number" << co <<" subject name\nHere:->";
								cin >> subna[co][entered];   
				                cout << "\nEnter the "<< subna[co][entered]<<" cradit hour\nHere:->";
				                cin >> subcr[co][entered];
				                cout << "\nType your Rank Using Leter  \nHere:->";
				                cin >> subra[co][entered];
								gpa[co][entered] = convert(subra[co][entered],subcr[co][entered]);
					            system("cls");
				   
				    cout << " \t\t              ::::           :::: \n";
					cout << "\t\t            ::::::::Cumulative GPA calculator::::: \n" ;
	                cout << " \t\t              ::::           :::: \n";
	  
					cout << "\nThe " << entered <<" Student's Name is:->" << name[entered];
				    cout <<"\n\nTotal amount of subject is " << subc[entered] <<endl<<endl ;
					cout <<"No"<<setw(14)<<"Subject(CH)"<<setw(12)<<"Entered"<<setw(20)<<" Your Rank Point\n";
					k=0; l=0;
 					for(int rep=1;rep<=co;rep++) {
						   cout <<rep<<setw(12)<<subna[rep][entered]<<"("<<subcr[rep][entered]<<")"<<setw(10)<<subra[rep][entered]<<setw(14);
					           convert (subra[rep][entered],subcr[rep][entered]);    
					          
							          
					           k+=gpa[rep][entered];
					           l+=subcr[rep][entered];
					
					x[entered]=k;
					y[entered]=l;
					}
				   }
				   
				   if (subc[entered]==1) {	   Gpa =(gpa[1][entered])/(subcr[1][entered]) ;
				   cout << "\n\t\t\tYour Total GPA is " << (gpa[1][entered]) << " / "<< (subcr[1][entered])<<" = "<<Gpa;
				   }else {
					   Gpa =(x[entered])/(y[entered]) ;
				   cout << "\n\t\t\tYour Total GPA is " << (x[entered]) << " / "<< (y[entered])<<" = "<<Gpa;
				   }
				  
				   
				   
				   cout << " \n\n     ######################################################## ";
				   cout << "\nNumber Of The Student Added:->"<< entered;
	               cout << "\nEnter 'f' If You Finsh Or Any Thing Else & Enter To Contiue:" ;
    			    
                             } while((stop=getche()) != 'f'||entered>99);

//.......................................................................................................


dis :
                 system("cls");   
                    cout << " \t\t\t              ::::           :::: \n";
					cout << "\t\t            ::::::::Cumulative GPA calculator::::: \n" ;
	                cout << " \t\t\t              ::::           :::: \n";
	  
   for (int co=1;co<=entered;co++){
					cout << "\nThe " << co <<" Student's Name is:->" << name[co];
				    cout << "\n\nTotal amount of subject is " << subc[co] <<endl ;
					cout <<"No"<<setw(14)<<"Subject(CH)"<<setw(12)<<"Entered"<<setw(20)<<" Your Rank Point\n";
					for(int rep=1;rep<=subc[co];rep++) {
						  cout <<rep<<setw(12)<<subna[rep][co]<<"("<<subcr[rep][co]<<")"<<setw(10)<<subra[rep][co]<<setw(14);
					           convert (subra[rep][co],subcr[rep][co]);    
					          
					   
					 }              
				             
				   if (subc[co]==1) {	   Gpa =((gpa[1][co]))/(subcr[1][co]) ;
				   cout << "\n\t\t\tYour Total GPA is " << ((gpa[1][co])) << " / "<< (subcr[1][co])<<" = "<<Gpa;
				   }else {  Gpa = ((x[co]) /(y[co]));
					   cout << "\n\t\t\tYour Total GPA is " << (x[co]) << " / "<< (y[co])<<" = "<<Gpa;
				       cout << "\n\n"; 
				   }
   }
    cout << "\n###############################################";
   cout<< "\nIf you to save press 's' or any key for not to";
		   
		   if ((wa=getche()) == 's') goto save;
	       return 0;  
//.....................................................................................................
save:
                
	system ("cls");

	cout << "\n\n\tType name to your file\n";
	cout << "\tHere:->";
	cin >> save;
		   ext = ".doc";
   
                ifstream Datacheck;
	           Datacheck.open(save+ext,ios::in); 
		if (!Datacheck.fail()) {
               cout << "\a\n\tSorry the file already exist Try using another Name\n ";
			  Sleep(500);
			   goto save;
		}       
   
       ofstream Datafile;
	   Datafile.open(save+ext,ios::out);
	   if (Datafile.fail())  {
               cout << "Sorry the file won't save. ";
			   cout << "\a\n\tFile cann't include '\' / | ? * < > '' :  ";
			   Sleep(500);
			   goto save;
		}

                    Datafile << " \t\t              ::::           :::: \n";
					Datafile << "\t\t            ::::::::Cumulative GPA calculator::::: \n" ;
	                Datafile << " \t\t              ::::           :::: \n";
	  
   for (int co=1;co<=entered;co++){
					Datafile << "\nThe " << co <<" Student's Name is:->" << name[co];
				    Datafile << "\n\nTotal amount of subject is " << subc[co]  ;
					Datafile <<"\nNo"<<setw(14)<<"Subject(CH)"<<setw(12)<<"Entered"<<setw(20)<<" Your Rank Point\n";
					for(int rep=1;rep<=subc[co];rep++) {
						  Datafile <<rep<<setw(12)<<subna[rep][co]<<"("<<subcr[rep][co]<<")"<<setw(10)<<subra[rep][co]<<setw(14);
						  {      
						string a = subra[rep][co] ;
						float b= subcr[rep][co];
							  float po =0 ;       
		       if ((a=="A")||(a=="a")) {Datafile << "  A"<< setw(6)<< 4*b;  po = 4*b; }
			   else if ((a=="A+")||(a=="a+")) {Datafile << "  A+"<< setw(6)<< 4*b;  po = 4*b; }
          else if ((a=="A-")||(a=="a-")) {Datafile << "  A-"<< setw(6)<< 3.7*b;  po = 3.7*b; }
		  else if ((a=="B+")||(a=="b+")) {Datafile << "  B+"<< setw(6)<< 3.3*b;  po = 3.3*b; }
         else if ((a=="B")||(a=="b")) {Datafile << "  B"<< setw(6)<< 3*b;  po = 3*b; }
		 else if ((a=="B-")||(a=="b-")) {Datafile << "  B-"<< setw(6)<< 2.7*b;  po = 2.7*b; }
		 else if ((a=="C+")||(a=="c+")) {Datafile << "  C+"<< setw(6)<< 2.3*b;  po = 2.3*b; }
		 else if ((a=="C")||(a=="c")) {Datafile << "  C"<< setw(6)<< 2*b;  po = 2*b; }
		 else if ((a=="C-")||(a=="c-")) {Datafile << "  C-"<< setw(6)<< 1.7*b;  po = 1.7*b; }
		 else if ((a=="D+")||(a=="d+")) {Datafile << "  D+"<< setw(6)<< 1.3*b;  po=  1.3*b; }
		 else if ((a=="D")||(a=="d")) {Datafile << "  D"<< setw(6)<< 1*b;  po=  1*b; }
		 else if ((a=="D-")||(a=="d-")) {Datafile << "  D-"<< setw(6)<< 0.7*b;  po=  0.7*b; }
		 else if ((a=="F")||(a=="f")) {Datafile << "  F"<< setw(6)<< 0 ;   po=  0; }
		  Datafile<< endl;	   

		    }
						      
					          
						}        
					               
				             
				   if (subc[co]==1) {	   Gpa =((gpa[1][co]))/(subcr[1][co]) ;
				   Datafile << "\n\t\t\tYour Total GPA is " << ((gpa[1][co])) << " / "<< (subcr[1][co])<<" = "<<Gpa;
				   }else {  Gpa = ((x[co]) /(y[co]));
					   Datafile << "\n\t\tYour Total GPA is " << (x[co]) << " / "<< (y[co])<<" = "<<Gpa;
				      } 
				   Datafile << "\n/////////////////////////////////////////////////\n"; 
				  
   }
   
                   Datafile.close();
			       cout << "\a\n\n\tThe Data Saved successfully"; 
  Sleep(500); 
           
   
   
   
   
   
   
   return 0;
}


//..............................................................................................


float convert (string a,float b)
{
 float po =0 ;       
		     if ((a=="A")||(a=="a")) {cout << "  A"<< setw(6)<< 4*b;  po = 4*b; }
			else if ((a=="A+")||(a=="a+")) {cout << "  A+"<< setw(6)<< 4*b;  po = 4*b; }
          else if ((a=="A-")||(a=="a-")) {cout << "  A-"<< setw(6)<< 3.7*b;  po = 3.7*b; }
		  else if ((a=="B+")||(a=="b+")) {cout << "  B+"<< setw(6)<< 3.3*b;  po = 3.3*b; }
         else if ((a=="B")||(a=="b")) {cout << "  B"<< setw(6)<< 3*b;  po = 3*b; }
		 else if ((a=="B-")||(a=="b-")) {cout << "  B-"<< setw(6)<< 2.7*b;  po = 2.7*b; }
		 else if ((a=="C+")||(a=="c+")) {cout << "  C+"<< setw(6)<< 2.3*b;  po = 2.3*b; }
		 else if ((a=="C")||(a=="c")) {cout << "  C"<< setw(6)<< 2*b;  po = 2*b; }
		 else if ((a=="C-")||(a=="c-")) {cout << "  C-"<< setw(6)<< 1.7*b;  po = 1.7*b; }
		 else if ((a=="D+")||(a=="d+")) {cout << "  D+"<< setw(6)<< 1.3*b;  po=  1.3*b; }
		 else if ((a=="D")||(a=="d")) {cout << "  D"<< setw(6)<< 1*b;  po=  1*b; }
		 else if ((a=="D-")||(a=="d-")) {cout << "  D-"<< setw(6)<< 0.7*b;  po=  0.7*b; }
		 else if ((a=="F")||(a=="f")) {cout << "  F"<< setw(6)<< 0 ;   po=  0; } 
		   cout<< endl;	   

return po ;
}