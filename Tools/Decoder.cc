#include "Decoder.h"

using namespace std;




	Decoder::Decoder(string h)
	{
		this->str = h;
		
		
		
	}
	Decoder::~Decoder()
	{
		 
	
	}
	

	vector<string> Decoder::getData(){
		
		char delim = '&';
		vector<string> cont;
		std::stringstream ss(str);
		std::string token;
		while (std::getline(ss, token, delim)) {
			
			int n = token.length();
			
			
			//Replace + with space
			int pos = token.find('+') ;
			while(pos != -1)
			{
				token[pos] = 32;
				pos = token.find('+',pos+1);
			}
			
			
			//Hexadecimals to decimal to char
			int pos2 = token.find('%');
			while(pos2 != -1)
			{
				string hexa="";
				hexa += token[pos2+1];
				hexa += token[pos2+2];
				int y = (int)strtol(hexa.c_str(),NULL,16);
				
				//Erase the hexadecimal from the string
				token.erase(pos2,3);
				//Insert the character
				token.insert(token.begin()+pos2,(char)y);
				
				
				
			    pos2 = token.find('%',pos2+1) ;
			}
			
			
			/*
			  Remove the name of the data. 
			  Example the post data retrieve  is email=example@gmail
              Then this part remove (email=)
              Leaving a string with just (example@gmail)

			*/
			int pos3 = token.find('=');		
			token = token.substr(pos3+1);	
			
			

			cont.push_back(token);
			//std::cout<<"<div><a>" <<token<<"</a></div>\n";
		}

		

			
		return cont;
	};

		vector<int> Decoder::dynamicKey(vector<string> inputKey){
			
			vector<int> position;
			
			for(int x=0 ;x < inputKey.size(); x++)
			{
				int col =  (int)inputKey[x].at(0);
				int row = (int)inputKey[x].at(1);
				
				position.push_back((5 * (col-65) +  (row-48)  ) -1);
				
			}
			
			return position;			
		};
		
		
		
	 string Decoder::createEmailDynamicKey(string){
		 
		 for(int x=0 ; x < 5; x++)
		 {

			 for(int y=0 ; y < 5; y++)
			 {
				 
			 }
			 
		 }
		 
		 
	};
		

/*
int main()
{
	 int len = 48;
	 string h = "firstname=dieg%3Do&lastname=Casas&country=australia";
	
	 Decoder p = Decoder(h);
	 vector<string> test = p.getData();
	 cout<<test[0]<<": "<<test[0].length()<<endl;
	 
	 vector<string> t;
	 t.push_back("D3");
	 t.push_back("D4");
	 t.push_back("D5");
	 vector<int> tes =  p.dynamicKey(t);
	 
	cout<<tes[0]<<endl;
	cout<<tes[1]<<endl;
	cout<<tes[2]<<endl;
	return 1;
}
*/

