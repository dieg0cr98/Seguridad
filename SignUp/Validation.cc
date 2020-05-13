#include <iostream>
#include <stdlib.h>
#include "Post.h"
#include <algorithm>
#include <iterator>
#include <sstream>
#include <vector>
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
   cout << "<title>Hello World - First CGI Program</title>\n";
   cout << "</head>\n";
   cout << "<body>\n";
   cout << "<h2>Hello World! This is my first CGI program</h2>\n";

    cout << "<table border = \"0\" cellspacing = \"2\">";

   for ( int i = 0; i < 26; i++ ) {
      cout << "<tr><td>" << ENV[ i ] << "</td><td>";
      
      // attempt to retrieve value of environment variable
      char *value = getenv( ENV[ i ].c_str() );  
      if ( value != 0 ) {
         cout << value;                                 
      } else {
         cout << "Environment variable does not exist.";
      }
      cout << "</td></tr>\n";
   }
   

   cout << "</table>\n";

  
 
  // string str = "Hola+Diego&Contr%25eras+Es%26trada+Q*iros";
   string t  = getenv("QUERY_STRING");
   char* t2  = getenv("HTTP_COOKIE");
   cout<<"<div><a>"<<t<<"</div></a>"<<endl;
   if(t2 != NULL)
	cout<<"<a>"<<t2<<"</a>"<<endl;
    else
    cout<<"<div><a>"<<"No hay cookie"<<"</div></a>"<<endl;
   Decoder d = Decoder(t);
   d.getData();
	
   
   cout << "</body>\n";
   cout << "</html>\n";
   

return 0;

   
   
}
