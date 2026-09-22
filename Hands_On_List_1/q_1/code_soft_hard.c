#include <unistd.h>
#include <stdio.h>

int main() {
	const char *soft_target = "./soft_link.txt";
	const char *hard_target = "./hard_link.txt";
	
	const char *soft_linkpath = "./s_link";
	const char *target_linkpath ="./h_link";
	
	if (symlink(soft_target,soft_linkpath) == -1){
		perror("symlink");
	} else {
		printf("Soft Link Created./n");
	}
		
	if (link(hard_target, target_linkpath) == -1){
		perror("link");
	} else {
		printf("Hard Link Created./n");
	}
	
	if (unlink("s_link") == -1) {
		perror("s_link unlinking fail");
	} else {
		printf("Soft Unlinking Successfull./n");
	}

	if (unlink("h_link") == -1) {
		perror("h_link unlinking failed");
	} else {
		printf("Hard Unlinking Successfull./n");
	}	 
	return 0;
}
