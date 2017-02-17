#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>

using namespace  std;
int main(int argc, char const *argv[])
{
	int out = open("package.txt",O_WRONLY|O_TRUNC |O_CREAT,0777);
	dup2(out,1);
	execlp("grep", "grep", "Package\\|Version\\|Depends\\|Description","/var/lib/dpkg/status",NULL);
	//int out1 = open("b",O_RDWR |O_CREAT |O_APPEND,0777);
	//dup2(out1,1);
	
	//cout<<"out"<<out<<" "<<"out1"<<out1<<endl;
	//execlp("uname","uname","--version", NULL);
	
	return 0;
}
