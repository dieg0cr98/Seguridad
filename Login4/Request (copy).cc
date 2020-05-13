#include <iostream>
#include "../Tools/Cookie.h"
#include "../Tools/Decoder.h"
#include "../Tools/Connector.h"
#include "../Tools/Hash.h"
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;



int main () {
cout << "Content-type:text/html\r\n\r\n";


cout<<"<!DOCTYPE html>\n";
cout<<"<html>\n";
cout<<"<body>\n";
cout<<"<h3></h3>\n";

char * te = getenv("CONTENT_LENGTH");


if(te != NULL)
{
	
	int postDataLength = atoi(te);
	char * data2 = new char[postDataLength];
	fread((void*) data2, 1, postDataLength,  stdin  );
	string t = data2;
	delete[] data2;
	
	
  // string t  = getenv("QUERY_STRING");
   char* t2  = getenv("HTTP_COOKIE");
  /*cout<<"<div><a>"<<t<<"</div></a>"<<endl;
   if(t2 != NULL)
	cout<<"<a>"<<t2<<"</a>"<<endl;
    else
     cout<<"<div><a>"<<"No hay cookie"<<"</div></a>"<<endl;
    
    */
   //Decodes the email and password 
   Decoder d = Decoder(t);
   string email =  d.getData()[0];
   string password =  d.getData()[1];
  // cout<<"<div><a>"<<email<<"</a></div>"<<endl;
   Connector c = Connector("localhost",  "root",   "diego",    "DB_Proyecto");
   vector<string> data = c.getIDSalt(email);
   
   if(data[0] == "%")
   {
	   cout<<data[0]<<endl;
	   
   }
   else
   {
	   

   int id = stoi(data[0]);
   string salt = data[1];
   int block = stoi(data[2]);   
   int attempts = stoi(data[3]);  

   //Checks if the account is blocked
   if(block == 1)
   {
	   cout<<"<div><h5>"<<"This account is block please check your email"<<"<h5></div>"<<endl;	
	   
   }
   else
   {
	   
		//Creates the hash
		Hash hash = Hash();
		string pass = hash.createHashSha2(password,data[1]);	  
		//Compares hash to database
		
		int check = c.checkPassword(id,pass,attempts);
		switch(check)
		{
			
			case 0:
			{
			
	             cout<<"<div><h5>"<<"Hi User"<<"<h5></div>"<<endl;	
	             break;			
			};
			
			case 1:
			{
			
				cout<<"<div><h5>"<<"Password Incorrect"<<"<h5></div>"<<endl;	
				break;			
			};
			
			case 2:
			{
			
				cout<<"<div><h5>"<<"Looks like u tried more than 3 times!! Your accound is blocked"<<"<h5></div>"<<endl;	
				break;		
			};			
			
			
		}
		
	}
	   
   }
   
   
	
}
else
{
	
	
}






   
   //Recupera el ID y salt del Correo
   
   



   
   
   
/*
   Cookie c = Cookie(10);
   c.sendCookie();
*/


cout<<"</body>\n";
cout<<"</html>\n";



   
   return 0;
}
