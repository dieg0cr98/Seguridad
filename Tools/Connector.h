#ifndef Connector_H
#define Connector_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <mysql.h>
#include "config.h"
#include <vector>
#include <sstream>

using namespace std;



class Connector
{
        public:
        
        
	
		Connector(string,string,string,string);
		~Connector();
		
		
		vector<string> getIDSalt(string); 
		
		
	
		//Return 0 if pass is correct 1 if not 2 number attempts is 3
		int checkPassword(int,string,int); 
		
		//Return 0 if the key is correct, 1 if not
		int checkDynamicKey(int,vector<string>,vector<int>);
		
		int createTempPass(int,string);
	
		
		
		private:
		MYSQL *mysql = NULL;
		


};



#endif 
