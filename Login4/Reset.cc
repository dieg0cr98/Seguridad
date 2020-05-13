#include <iostream>
#include <stdlib.h>
#include <iterator>
#include <sstream>
#include <vector>

#include "../Tools/Hash.h"

using namespace std;

const string ENV[ 26] = {
   "COMSPEC", "DOCUMENT_ROOT", "GATEWAY_INTERFACE",   
   "HTTP_ACCEPT", "HTTP_ACCEPT_ENCODING",             
   "HTTP_ACCEPT_LANGUAGE", "HTTP_CONNECTION",         
   "HTTP_HOST", "HTTP_USER_AGENT", "PATH",            
   "QUERY_STRING", "REMOTE_ADDR", "REMOTE_PORT",      
   "REQUEST_METHOD", "REQUEST_URI", "SCRIPT_FILENAME",
   "SCRIPT_NAME", "SERVER_ADDR", "SERVER_ADMIN",      
   "SERVER_NAME","SERVER_PORT","SERVER_PROTOCOL",     
   "SERVER_SIGNATURE","SERVER_SOFTWARE","CONTENT_LENGTH","HTTP_COOKIE" };   

int main () {


	cout << "Content-type:text/html\r\n\r\n";
	cout << "<html>\n";
	cout << "<head>\n";


	//cout<<"<meta http-equiv=\"cache-control\" content=\"no-cache\"/>"<<endl;
	cout<<"<script>"<<endl;
	cout<<"function refresh(){  location.reload(); }"<<endl;
	cout<<"</script>"<<endl;   

cout<<"<style>\n";
cout<<"* {\n";
cout<<"  box-sizing: border-box;\n";
cout<<"}\n";
cout<<"/* Create three equal columns that floats next to each other */\n";
cout<<".column {\n";
cout<<"  float: left;\n";
cout<<"  width: 33.33%;\n";
cout<<"  padding: 10px;\n";
cout<<"}\n";
cout<<"/* Clear floats after the columns */\n";
cout<<".row:after {\n";
cout<<"  content: "<<""<<";\n";
cout<<"  display: table;\n";
cout<<"  clear: both;\n";
cout<<"}\n";
cout<<"</style>\n";




	cout << "</head>\n";
cout<<"<body  onload=(\"refresh()\")  >\n";

	cout<<"<center>"<<endl;


	cout << "<h1>Password Reset</h1>\n";

	



	//Creates the form
	cout<<"<form action="<<"/cgi-bin/Login/PasswordReset"<<" method='post' >\n";
	cout<<"<div class=\"row\">"<<endl;
	cout<<"<label for="<<"email"<<">Email:</label>\n";
	cout<<"<input required type="<<"email"<<" id="<<"email"<<" name="<<"email"<<"><br><br>\n";
	cout<<"</div>"<<endl;


	cout<<"<div><h3>Dynamic Key</h3></div>"<<endl;
	cout<<"<div class=\"row\">"<<endl;
	Hash hash = Hash();
	vector<string> keyWords = hash.createKeyWords(3);


	
	for(int x=0 ; x< 3 ;x++)
	{
		cout<<"<div class=\"column\" style=\"height:100px\" >"<<endl;
			
		//Creates the dynamic key word labels and input

		//Sends it to the server
		cout<<"  <input type="<<"hidden"<<"  value=\""<<keyWords[x]<<"\"     id="<<"w"<<x+1<<" name="<<"w"<<x+1<<"><br><br>\n";	
		
		
		
			cout<<"<div class=\"row\">"<<endl;
				cout<<"  <label for="<<"d"<<x+1<<">"<<keyWords[x]<<"</label>\n";
			cout<<"</div>"<<endl;
			cout<<"<div class=\"row\">"<<endl;
				cout<<"  <input  required type="<<"number"<<" id="<<"d"<<x+1<<"  min=\"1\"  max=\"99\"    name="<<"d"<<x+1<<"><br><br>\n";	
			cout<<"</div>"<<endl;	

		cout<<"</div>"<<endl;
	}

	cout<<"</div>"<<endl;


	cout<<"<div  class=\"row\"><input  style=\"witdh:50px; height:50px \"  value=\"Submit\" type="<<"submit"<<"></div>\n";
	cout<<"</form>\n";

	

	cout<<"</center>"<<endl;
	//Go back  
	cout<<"<div><button onclick=\"goBack()\">Go back</button></div>"<<endl;
	cout<<"<script>"<<endl;
	cout<<"function goBack(){ window.history.back(); }"<<endl;
	cout<<"</script>"<<endl;   

	cout << "</body>\n";
	cout << "</html>\n";
   
   
   
   
   
   
   

return 0;

   
   
}
