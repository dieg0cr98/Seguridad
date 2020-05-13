#ifndef Decoder_H
#define Decoder_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <cstring>


using namespace std;


class Decoder
{
        public:
		
		Decoder(string);
		~Decoder();
		
		
		/*
			Creates:	Handles the data from a post or get methods
			Receive:	
			Modify:	Data from the string str, removing all the caracters that are unnecessary
			Return:	vector with the data 
		*/						
        vector<string> getData();
        
		/*
			Creates:	Translate the dynamicKey words (A1) into position of the array (0)
			Receive:	
			Modify:	
			Return:	position of the dynamicKey words
		*/	        
        vector<int> dynamicKey(vector<string>);
        
        
        string createEmailDynamicKey(string);
        
        
      
        
        
        
	private:
		string str;
		string cardWord[5][5] = {  {"A1","A2","A3","A4","A5"}, {"B1","B2","B3","B4","B5"},{"C1","C2","C3","C4","C5"},{"D1","D2","D3","D4","D5"},{"E1","E2","E3","E4","E5"} };
		};



#endif 
