#include <iostream>
#include "Hash/Cookie.h"

using namespace std;



int main () {
cout << "Content-type:text/html\r\n\r\n";


cout<<"<!DOCTYPE html>\n";
cout<<"<html>\n";
cout<<"<style>\n";
cout<<"input[type=text], select {\n";
cout<<"  width: 100%;\n";
cout<<"  padding: 12px 20px;\n";
cout<<"  margin: 8px 0;\n";
cout<<"  display: inline-block;\n";
cout<<"  border: 1px solid #ccc;\n";
cout<<"  border-radius: 4px;\n";
cout<<"  box-sizing: border-box;\n";
cout<<"}\n";
cout<<"input[type=submit] {\n";
cout<<"  width: 100%;\n";
cout<<"  background-color: #4CAF50;\n";
cout<<"  color: white;\n";
cout<<"  padding: 14px 20px;\n";
cout<<"  margin: 8px 0;\n";
cout<<"  border: none;\n";
cout<<"  border-radius: 4px;\n";
cout<<"  cursor: pointer;\n";
cout<<"}\n";
cout<<"input[type=submit]:hover {\n";
cout<<"  background-color: #45a049;\n";
cout<<"}\n";
cout<<"div {\n";
cout<<"  border-radius: 5px;\n";
cout<<"  background-color: #f2f2f2;\n";
cout<<"  padding: 20px;\n";
cout<<"}\n";
cout<<"</style>\n";
cout<<"<body>\n";
cout<<"<h3>Using CSS to style an HTML Form</h3>\n";
cout<<"<div>\n";
cout<<"  <form action="<<"program"<<"  method="<<"get"<<">\n";
cout<<"    <label for="<<"fname"<<">First Name</label>\n";
cout<<"    <input type="<<"text"<<" id="<<"fname"<<" name="<<"firstname"<<" placeholder="<<"Your name.."<<">\n";
cout<<"    <label for="<<"lname"<<">Last Name</label>\n";
cout<<"    <input type="<<"text"<<" id="<<"lname"<<" name="<<"lastname"<<" placeholder="<<"Your last name.."<<">\n";
cout<<"    <label for="<<"country"<<">Country</label>\n";
cout<<"    <select id="<<"country"<<" name="<<"country"<<">\n";
cout<<"      <option value="<<"australia"<<">Australia</option>\n";
cout<<"      <option value="<<"canada"<<">Canada</option>\n";
cout<<"      <option value="<<"usa"<<">USA</option>\n";
cout<<"    </select>\n";
cout<<"  \n";
cout<<"    <input type="<<"submit"<<" value="<<"Submit"<<">\n";
cout<<"  </form>\n";
cout<<"</div>\n";

cout<<"<p id="<<"demo"<<"></p>\n";


 Cookie c = Cookie(10);
 c.sendCookie();



cout<<"</body>\n";
cout<<"</html>\n";









   
   
   
   return 0;
}
