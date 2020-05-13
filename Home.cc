#include <iostream>
using namespace std;

int main () {
cout << "Content-type:text/html\r\n\r\n";
cout<<"<!DOCTYPE html>\n";
cout<<"<html>\n";
cout<<"<head>\n";
cout<<"</head>\n";
cout<<"<body>\n";


cout<<"<div>  <h1  style=\" text-align:center \">Welcome to Feibuk</h1></div>   \n";

cout<<"<div><ul>\n";
//cout<<"  <li ><a class="<<"active"<<" href="<<"Home"<<">Home</a></li>\n";
cout<<"  <li style="<<"float:right"<<"><a href="<<"/cgi-bin/login"<<"><h3> Login</h3></a></li>\n";
cout<<"</ul></div>\n";




 char* t2  = getenv("HTTP_COOKIE");
   if(t2 != NULL)
	cout<<"<div><a>"<<t2<<"</div></a>"<<endl;
 /*   else
    cout<<"<div><a>"<<"No hay cookie"<<"</a></div>"<<endl;*/
cout<<"</body>\n";
cout<<"</html>\n";




  

   
   
   
   return 0;
}
