#include "Hash.h"
using namespace std;
using namespace CryptoPP;




		Hash::Hash()
		{
			
		};


		Hash::~Hash(){
			
			
		};
		

		
		long Hash::createRandom(int min, int max){
			
			AutoSeededRandomPool rng;
			return Integer(rng,min,max).ConvertToLong();
			
		
		};
		
		
		string Hash::createSalt(int length){
			string salt = "";
			for(int x=0; x < length; x++)// Genera length caracteres diferentes
			{
				long randomNumber = createRandom(0,60); //60 es el total de caracteres disponibles en la variable Map
				//cout<<randomNumber <<" :" <<Map[randomNumber]<<endl;
				salt += Map[randomNumber];
					
			}
	
			return  salt;
		};
		


		string Hash::createHashSha1(string password,string salt){
			CryptoPP::SHA1 sha1;
			string hash = "";
			StringSource(password+salt, true, new CryptoPP::HashFilter(sha1, new CryptoPP::HexEncoder(new CryptoPP::StringSink(hash))));
			
			
			return hash;
		};	
		

		string Hash::createHashSha2(string password,string salt){
			CryptoPP::SHA256 sha2;
			string hash = "";
			StringSource(password+salt, true, new CryptoPP::HashFilter(sha2, new CryptoPP::HexEncoder(new CryptoPP::StringSink(hash))));

			return hash;
		};	
		
		
		string Hash::createSecureKey(){
			
			string key = "";

			
			
			for(int x=0 ; x< 5; x++)
			{
				for(int y=0 ; y<5;y++)
				{
					long random = createRandom(1,99);
					if(random < 10)
						key+= string("0") + to_string(random) + string(";");
					else
						key+= to_string(random) + string(";");
				}
				
			}
		
			
			return key;
			
		};
		
		
		vector<string> Hash::createKeyWords(int numberWords)
		{
				vector<string> words;
				for(int x=0 ; x<numberWords; x++)
				{
					long randomChar = createRandom(65,69);
					long randomNumber = createRandom(1,5);
					string word = (char)randomChar + to_string(randomNumber);
					words.push_back(word);

				
				}
				for(int x=0 ; x<numberWords; x++)
				{
					for(int y=x+1 ; y<numberWords; y++)
					{
						//cout<<words[x]<<words[y]
						if(words[x].compare(words[y]) == 0)
						{
							long randomChar = createRandom(65,69);
							long randomNumber = createRandom(1,5);
							string word = (char)randomChar + to_string(randomNumber);
							while(words[x].compare(word) == 0)
							{
								randomChar = createRandom(65,69);
								randomNumber = createRandom(1,5);
								word = (char)randomChar + to_string(randomNumber);
							}
							words[x] = word;
							
						}
						
						
					
					}
					
					
				}
					
					

					
				

			return words;
		};
		
		
/*
int main(){
	
	Hash r = Hash();

	string salt1 = r.createSalt(8);
	string salt2 = r.createSalt(9);
	cout<<"Salt pass: "<<salt1 <<endl;
	cout<<"Salt cookie: "<<salt2 <<endl;
	
	cout<<r.createHashSha1("diego",salt2)<<endl;
	cout<<r.createHashSha2("curso01seguridad",salt1)<<endl;
	
	vector<string> key = r.createKeyWords(3);
	cout<<key[0]<<endl;
cout<<key[1]<<endl;
		
cout<<key[2]<<endl;
	
	
	
}
*/
