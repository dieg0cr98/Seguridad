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

cout<<"<body  >\n";
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
	
	
   //Decodes the email and password 
   Decoder d = Decoder(t);
   string email =  d.getData()[0];
   vector<string> inputWords{d.getData()[1],d.getData()[3],d.getData()[5]};
   vector<int> keyPositions =  d.dynamicKey(inputWords);
   vector<string> inputNumbers{ d.getData()[2],d.getData()[4], d.getData()[6]} ;
   
   //Checks that the words are diff. Like the system shouldnt create A1 A1 B7
   if(keyPositions[0] != keyPositions[1] and keyPositions[0] != keyPositions[2]  and keyPositions[2] != keyPositions[3]   )  
   {
	      
	   Connector c = Connector("localhost",  "root",   "diego",    "DB_Proyecto");
	   vector<string> data = c.getIDSalt(email);
	   if(data[0] == "%")
	   {
		  
		cout<<"<script>"<<endl;
		cout<<"alert(\" Invalid Data \");"<<endl;
		
		cout<<"window.location.replace('http://"<<serverIP<<"/cgi-bin/Login/Reset');"<<endl;
		
		cout<<"</script>"<<endl;
		   
	   }
	   else
	   {
		
		   Connector c2 = Connector("localhost",  "root",   "diego",    "DB_Proyecto");
		   int check = c2.checkDynamicKey(stoi(data[0]),inputNumbers,keyPositions);
		   //Verifies is the DynamicKey values match
		   if(check)
		   {
				cout<<"<script>"<<endl;
				cout<<"alert(\" WRONG DynamicKey Values \");"<<endl;
				
				cout<<"window.location.replace('http://"<<serverIP<<"/cgi-bin/Login/Reset');"<<endl;
				
				cout<<"</script>"<<endl;
					   
		   }
		   else
		   {
				//Crea una llave temp la guarda en la bd y la envia al correo del mop
			   
				//Connector c2 = Connector("localhost",  "root",   "diego",    "DB_Proyecto");
				
				
				
				cout<<"<script>"<<endl;
				cout<<"alert(\"Successful!! Check your email for details \");"<<endl;
				cout<<"</script>"<<endl;
			   
		   }		
		
		
	   
	   }
	   
	   

		   
   }
   else
   {
	cout<<"<script>"<<endl;
	cout<<"alert(\" STOP IT HACKER \");"<<endl;
	
	cout<<"window.location.replace('http://"<<serverIP<<"/cgi-bin/Login/Reset');"<<endl;
	
	cout<<"</script>"<<endl;
	   
   } 
   

  
}
else
{
	cout<<"<script>"<<endl;
	cout<<"alert(\"You forgot to type the data\")"<<endl;
	cout<<"</script>"<<endl;   
	
}






cout<<"</body>\n";
cout<<"</html>\n";



   
   return 0;
}
