#include <iostream>
#include <stdlib.h>
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


   string cookie  = getenv("HTTP_COOKIE");
   
   
   cout << "Content-type:text/html\r\n\r\n";
   cout << "<html>\n";
   cout << "<head>\n";
   
   
   
   
   cout << "<title>Bienvenido al muro de </title>\n";
   cout << "</head>\n";
   cout << "<body>\n";
   cout << "</body>\n";
   cout << "</html>\n";
   

return 0;

   
   
}
