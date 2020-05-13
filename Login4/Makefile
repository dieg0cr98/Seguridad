
all: Request Reset PasswordReset
.PHONE:all


Request:  Request.cc   ../Tools/Decoder.cc  ../Tools/Hash.cc ../Tools/Cookie.cc ../Tools/Connector.cc
	g++ -o Request Request.cc  ../Tools/Decoder.cc  ../Tools/Hash.cc ../Tools/Cookie.cc ../Tools/Connector.cc -l:libcryptopp.a `mariadb_config --cflags --libs`


Reset: Reset.cc
	g++ -o Reset Reset.cc ../Tools/Hash.cc -l:libcryptopp.a 
	
PasswordReset: PasswordReset.cc
	g++ -o PasswordReset PasswordReset.cc ../Tools/Decoder.cc  ../Tools/Hash.cc ../Tools/Cookie.cc ../Tools/Connector.cc -l:libcryptopp.a `mariadb_config --cflags --libs`	
