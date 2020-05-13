
all: Home login
.PHONY: all
	

Home: Home.cc 
	g++ -o Home Home.cc

login: Login.cc 
	g++ -o login Login.cc


