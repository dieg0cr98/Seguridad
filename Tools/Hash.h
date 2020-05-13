/*
Esta clase se encarga de generar los hash y salts. Ademas es capaz de generar numeros aleatorios

*/
#ifndef Hash_H
#define Hash_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <string.h>

#include <cryptopp/sha.h>
#include <cryptopp/osrng.h>
#include <cryptopp/filters.h>
#include <cryptopp/hex.h>


#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <cstring>
using namespace std;
using namespace CryptoPP;

   


class Hash
{
        public:
		
		Hash();
		~Hash();
		
	    /*
			Creates:	random number 
			Receive:	integer with the min number 
							integer with the max number
			Modify:
			Return:	long with the random number
		*/
		long createRandom(int,int);
		
		
	    /*
			Creates:	string with random characters, using the ones in the variable Map
			Receive:	integer with the length of the salt
			Modify:
			Return:	string with the salt
		*/
		string createSalt(int);
		
	    /*
			Creates:	hash using the SHA1 algorithm
			Receive:	string with the password
							string with the salt
			Modify:
			Return:	string with the hash 
		*/		
		string createHashSha1(string,string);	
		
		
	    /*
			Creates:	hash using the SHA256 algorithm
			Receive:	string with the password
							string with the salt
			Modify:
			Return:	string with the hash 
		*/				
		string createHashSha2(string,string);	
		
		
	    /*
			Creates:	A dynamic key for access
			Receive:	
			Modify:
			Return:	2d array (in a string formart) with the numbers
		*/			
		string createSecureKey();
		
			    /*
			Creates:	A dynamic keyWord for access. Like A1
			Receive:	integer number of keywords
			Modify:
			Return:	vector with the keywords
		*/			
		vector<string> createKeyWords(int);
		
		private:
			string Map = "abcdefghijklmnopqrstuvwxyzABCDFGHIJKLMNOPQRSTUVWXYZ1234567890"; 
			

};



#endif 
