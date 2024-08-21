#include <stdio.h>
#include <stdlib.h>
#include "problem.h"
#include <unistd.h>
int main()
{
	int num_prod=3,num_con=2;
	int pi=fork();
	if(pi==0){
	char * args[]={"./producer","0"};
//	int k=fork();
	 execvp("./producer",args);
//	else{
		for(int i=0;i<num_prod-1;i++){
			//char *args[]={"./producer","0"+i+1};
			if(fork()){
				char *args[]={"./producer","0"+i+1};
				 execvp("./producer",args);
}
			exit(1);

//}
}
	}
	else{
		for(int i=0;i<num_con;i++){

			if(fork()){
				char *args[]={"./consumer","0"+i};
				execvp("./consumer",args);
				exit(1);

}

}
	}



}
