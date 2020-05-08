#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main( int argc, char *argv[]){
	char pwd[100];
	int current = open(".pwd", O_RDONLY);
	
	int n = read(current, pwd, sizeof(pwd));
	if (n > 0){
		printf(1, "%s\n", pwd[0]);
		exit();
	}
	else if (n < 0){
		printf (1, "/\n");
		exit();
	}
	
	close(current);
	exit();
}
	
