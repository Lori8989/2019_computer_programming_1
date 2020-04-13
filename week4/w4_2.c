#include<stdio.h>

int main(){
	int n = 0;
	int w[200000] = {0};
	// int eaten_value = 0;

	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int k = 0;
		scanf("%d", &k);
		w[k] = i;
		// if(i == 0){
		// 	eaten_value = k;
		// }
	}


	// int b[200000] = {0};
	int b = 0;
	int eaten_idx = -1;
	
	for(int i = 0; i < n; i++){
		scanf("%d", &b);

		int current_value = b;
		int eating_target  = w[current_value];
		int eating = eating_target - eaten_idx;

		// printf("[%d]: %d from [%d]: %d | %d\n", eating_target, current_value, eaten_idx, eaten_value, eating);

		if(eating > 0 ){	
			eaten_idx = eating_target;
			// eaten_value = current_value;
			printf("%d", eating);
		}else{
			printf("0");
		}

		if(i < n - 1){
			printf(" ");
		}
	}

	printf("\n");


	return 0;
}
