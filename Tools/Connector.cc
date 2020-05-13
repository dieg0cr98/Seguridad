
#include "Connector.h"


using namespace std;




		Connector::Connector( string ip, string user, string password, string databaseName )
		{

 
			mysql = mysql_init(mysql);

			if (!mysql) {
					cout<<"ISSUE"<<endl;
			}
			else
			{
				mysql_options(mysql, MYSQL_READ_DEFAULT_FILE, (void *)"./my.cnf");
				if( !mysql_real_connect(mysql,  ip.c_str(),  user.c_str(),  password.c_str(), databaseName.c_str() , 0,  NULL,       CLIENT_FOUND_ROWS ))
				{	
						cout<<"Connection with the database Failed"<<endl;
				
				}
				
				
				
				
		
			}
        
			
			


			
		};
		
		

		Connector::~Connector()
		{
			mysql_close(mysql);
		};

		


		vector<string> Connector::getIDSalt(string email){
			
		   vector<string> data;
		   string quarry = string("call login(\"")+email+string("\");");
		   //cout<<quarry<<endl;
		   mysql_query(mysql, quarry.c_str());		   
		   MYSQL_RES *result = mysql_store_result(mysql);
		  
		   
		   if(mysql_num_rows(result) < 1)//Checks is we got results
		   {
			   //If not then print the issue
				//cout<<"<div><h5>"<<"Email not found"<<"<h5></div>"<<endl;	
				data.push_back("%");
			 
		   }
		   else
		   {
			   
			   
			   MYSQL_ROW row  = mysql_fetch_row(result);
			    data.push_back(row[0]); //id
			    data.push_back(row[1]); //salt
			    data.push_back(row[2]); //block
			    data.push_back(row[3]); //attempts
			    data.push_back(row[4]); //authentication
			  
		   }
			
		   mysql_free_result(result);
		   return data;	
		
		
		}; 

		//-1 error in the sql quarry ,0 password checks, 1 account blocked, 2 wrong password
		int Connector::checkPassword(int id , string inputPassword, int attempts){
		
		
			string query = "call checkPassword(";
			query.append(to_string(id));
			query.append(",\"");
			query.append(inputPassword);
			query.append("\",");
			query.append(to_string(attempts));
			query.append(");");
			
		    int x = mysql_query(mysql, query.c_str());
			if(x != -1)
			{
				MYSQL_RES *result = mysql_store_result(mysql);
				MYSQL_ROW row  = mysql_fetch_row(result);
				return atoi(row[0]);

			}
			else
				return -1;
			
			
			
			
			
			

		}
		
		
		//-1 email not found,
		int Connector::checkDynamicKey(int id, vector<string> inputNumbers, vector<int> positions){
			
			string quarry = string("Select card From secureCard where idFK =") + to_string(id)+string(";");
		    mysql_query(mysql, quarry.c_str());		   
		    MYSQL_RES *result = mysql_store_result(mysql);			
			MYSQL_ROW row  = mysql_fetch_row(result);
			
			string temp =  row[0];//"74;36;31;08;83;79;29;99;50;82;85;62;33;71;91;63;44;60;22;23;69;06;74;42;74;";
			char delim = ';';
			vector<string> cont;
			std::stringstream ss(temp);
			std::string token;
			int counter=0;
			while (std::getline(ss, token, delim)) {
				
				if(counter == positions[0] and inputNumbers[0].compare(token) != 0)
				{	

						return 1;		
				}
				
				cont.push_back(token);
				counter++;
			}
			
			for(int x=1 ; x < positions.size(); x++)
			{
				if(cont[positions[x]].compare(inputNumbers[x]) != 0)
				{
					return 1;
				}
			}
			return 0;
			
		};

/*
int main(){
	
	Connector c = Connector("localhost",  "root",   "diego",    "DB_Proyecto");
	string quarry = "call login('dieg0cr98@gmail.com','8054EC4A85B659BCB31F22F5FC6756DC9F9AD51ED4B3E4EE09D38E1869C26627')";
	mysql_query(c.mysql, quarry.c_str());
	MYSQL_RES *result = mysql_store_result(c.mysql);

						  if (!result) {
							printf("Couldn't get results set: %s\n", mysql_error(c.mysql));
						  } else
						  {
							  
							  
								unsigned int num_fields;
								unsigned int i;
								MYSQL_FIELD *fields;

								num_fields = mysql_num_fields(result);
								fields = mysql_fetch_fields(result);
								for(i = 0; i < num_fields; i++)
								{
								   printf("Field %u is %s\n", i, fields[i].name);
								}
							  
							  
								MYSQL_ROW row;
								int u;
								unsigned int num_fields2 = mysql_num_fields(result);
																						
								while ((row = mysql_fetch_row(result))) {
								  for (u = 0; u < num_fields2; u++) {
									printf("%s, ", row[u]);
								  }
								  putchar('\n');
								}

								mysql_free_result(result);
						  }
	
	return 1;
	
}
*/



