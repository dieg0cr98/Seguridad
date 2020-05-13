#ifndef Cookie_H
#define Cookie_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include "Hash.h"

using namespace std;



class Cookie
{
        public:
        
        
	    /*
			Creates:    cookie for the user	
			Receive:	integer with the userID
			Modify:	
			Return:	
		*/			
		Cookie(int);
		
		
		
		/*
			Creates:	
			Receive:	string cookie			
			Modify:	
			Return:	
		*/			
		Cookie(string);

		~Cookie();
		
		
	
		
		

	    /*
			Creates:	cookie for a user
			Receive:	integer with the user id
			Modify:
			Return:	int 1 if something goes wrong otherwise 0
		*/		
		int createCookie();
		
	    /*
			Creates:	Adds the cookie to the database
			Receive:	
			Modify:	Database tuple
			Return:	int 1 if something goes wrong otherwise 0
		*/	
		int saveCookie();
		
	    /*
			Creates: Adds the couts to the client html with the cookie
			Receive:	
			Modify:	
			Return:	int 1 if something goes wrong otherwise 0
		*/			
		int sendCookie();
		
		
	    /*
			Creates:	
			Receive:	string with the cookie	
			Modify:	
			Return:	int 1 if the cookie is invalid, 2 if the cookie expired, otherwise 0
		*/			
		int checkCookie(string cookie);
		
		
		
		
		
		
		private:
		int userID;
		string cookie;
		string name;


};



#endif 
