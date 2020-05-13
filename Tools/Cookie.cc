
#include "Cookie.h"
/*
	Programa genera cookie para  un usuario 
	
	UserID = 
	Password = 9 caracteres ascci entre 33 y 126 (decimal)
   Utilizar srand(time(0)) no asegura tener resultados diferentes cada vez que se ejecuta el programa, dado a que time es en segundos.
  
*/

using namespace std;




		Cookie::Cookie(int userID)
		{
			this->userID = userID;

			if(createCookie() != 1)
			{
				//cout<<"<div><a>Cookie created</a></div>"<<endl;
			}
			else
				cout<<"<div><a>Error Creating Cookie</a></div>"<<endl;
				
		};
		
		
		Cookie::Cookie(string cookie)
		{
			
			this->cookie = cookie;
			
		};


		Cookie::~Cookie(){
			
			
			
		};
				

	    /*
			Creates:	cookie for a user
			Receive:	integer with the user id
			Modify:
			Return:	int 1 if something goes wrong otherwise 0
		*/		
		int Cookie::createCookie(){
			Hash hash = Hash();
			string salt = hash.createSalt(8);
			
			if(salt.size() > 0)
			{
				string cookieHash = hash.createHashSha1(to_string(this->userID),salt);
				if(cookieHash.size() > 0)
				{
					//Save cookieHash and salt
					this->cookie.append(to_string(this->userID));
					this->cookie.append("=");
					this->cookie.append(cookieHash);
					cout<<"userID: "<< this->userID <<" Hash: "<<cookieHash<< " Cookie: "<< this->cookie <<endl;
					return 0;
					
				}
				
				else
				{
					cout<<"<div><a>Error Creating Salt</a></div>";
					return 1;
				}
			}
			else
			{
				cout<<"<div><a>Error Creating Salt</a></div>";
				return 1;
			}
			
			
							
		};
		
	    /*
			Creates:	Adds the cookie to the database
			Receive:	
			Modify:	Database tuple
			Return:	int 1 if something goes wrong otherwise 0
		*/	
		//int Cookie::saveCookie(string){return 1};
		
	    /*
			Creates: Adds the couts to the client html with the cookie, cookie is set expire in 5min
			Receive:	
			Modify:	
			Return:	int 1 if something goes wrong otherwise 0
		*/			
		int Cookie::sendCookie(){
			
			
			if(cookie.size() > 1)
			{
				cout<<"<script>\n";
				
			cout<<"var date = new Date(Date.now() + 5* 60000);\n";
			cout<< "document.cookie =\""<<this->cookie<<";expires=\" + date.toUTCString() +\";path=/cgi-bin;\""<<endl;

				cout<<"</script>\n";
				return 1;
				
				
			}
			else{
				
				cout<<"<div><a>Error Creating Salt</a></div>"<<endl;;
				return 1;
			}
			

			
			
			
		};
		
		
	    /*
			Creates:	
			Receive:	string with the cookie	
			Modify:	
			Return:	int 1 if the cookie is invalid, 2 if the cookie expired, otherwise 0
		*/			
		//int Cookie::checkCookie(string cookie){return 1};

/*
int main(){
	
	Cookie e = Cookie(20);
	e.sendCookie();
	//cout<< e.sentCookie()<<endl;
	
	
}
*/



