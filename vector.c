#include <stdio.h>

int main(){
	int inputs[] = { 9, 4, 6, 3, 2, 10, 7, 5 };

	for(int i = 0; i < sizeof(inputs) / sizeof(inputs[0]); i++){
		printf("%d\n", inputs[i]);
	}
	
	return 0;
}
