#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;



int main () {
	
	
char * ipClient = getenv("REMOTE_ADDR");


cout << "Content-type:text/html\r\n\r\n";

cout<<"<!DOCTYPE html>\n";
cout<<"<html>\n";
cout<<"<body>\n";



cout<<"<h1>Authenticate Your Account</h1>\n";
cout<<"<h3>"<<"We need to sent you a email with a Temporary Password in order to validate your account"<<"</h3>"<<endl;
cout<<"<form action="<<"/cgi-bin/Login/Request"<<" method='post' >\n";
cout<<"  <label for="<<"email"<<">Confirm Email:</label>\n";
cout<<"  <input type="<<"email"<<" id="<<"email"<<" name="<<"email"<<"><br><br>\n";
cout<<"  <input value=\"Submit\" type="<<"submit"<<">\n";
cout<<"</form>\n";



cout<<"</body>\n";
cout<<"</html>\n";




   
   return 0;
}
