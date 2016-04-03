#include "header.h"

void main(int argc, char* argvs[]){
	Matrix* mt = new Matrix();
	string method = argvs[1];
	cout << method;
	mt->read_file(argvs[2]);
	mt->check_connector(method);
	mt->arrange_top();
	mt->write_file(argvs[3]);
}