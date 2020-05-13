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
	char* serverIP  = getenv("SERVER_NAME");
	
  // string t  = getenv("QUERY_STRING");

   //Decodes the email and password 
   Decoder d = Decoder(t);
   string email =  d.getData()[0];
   string password =  d.getData()[1];
  // cout<<"<div><a>"<<email<<"</a></div>"<<endl;
   Connector c = Connector("localhost",  "root",   "diego",    "DB_Proyecto");
   vector<string> data = c.getIDSalt(email);
   
   if(data[0] == "%")
   {
	  
	cout<<"<script>"<<endl;
	cout<<"alert(\" Email Not Found \");"<<endl;
	
	cout<<"window.location.replace('http://"<<serverIP<<"/cgi-bin/login');"<<endl;
	
	cout<<"</script>"<<endl;
	   
   }
   else
   {
	   

	   int id = stoi(data[0]);
	   string salt = data[1];
	   int block = stoi(data[2]);   
	   int attempts = stoi(data[3]);  
	   int authentication = stoi(data[4]);  
	   if(authentication == 1)
	   {
	   
		   //Checks if the account authentication is completed
		   if(authentication != 0)
		   {
			   //Checks if the account is blocked
			   if(block == 1)
			   {
				   

					cout<<"<script>"<<endl;
					cout<<"alert(\" This account is block!!!Please Change the Password \");"<<endl;

					cout<<"window.location.replace('http://"<<serverIP<<"/cgi-bin/Login/Reset');"<<endl;

					cout<<"</script>"<<endl;
							   
				   
				   
			   }
			   else
			   {
				   
					//Creates the hash
					Hash hash = Hash();
					string pass = hash.createHashSha2(password,salt);	  
					//Compares hash to database
					Connector c2 = Connector("localhost",  "root",   "diego",    "DB_Proyecto");
					int check = c2.checkPassword(id,pass,attempts);
					switch(check)
					{
						case 0:
						{
							
							Cookie cookie = Cookie(id);
							cookie.createCookie();
							break;
						}
						
						
						
						
						
					}
					
					
					
					
					
			   }
		   
		   }
		   else
		   {
			   
			cout<<"<script>"<<endl;
			cout<<"alert(\" This account still needs to be authenticated  \");"<<endl;
			cout<<"window.location.replace('http://"<<serverIP<<"/cgi-bin/Register/Authenticator');"<<endl;
			cout<<"</script>"<<endl;
			   
			   
			   
		   }
		   
      }
      else
      {
		cout<<"<script>"<<endl;
		cout<<"alert(\" Your account is not authenticated \");"<<endl;
		
		cout<<"window.location.replace('http://"<<serverIP<<"/cgi-bin/Register/Authenticator');"<<endl;
		
		cout<<"</script>"<<endl;
		   
		  
		  
	  }
	}




cout<<"</body>\n";
cout<<"</html>\n";



   
   return 0;
}
}
