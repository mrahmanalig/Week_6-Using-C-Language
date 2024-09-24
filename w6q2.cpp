#include <stdio.h>
#include <stdlib.h>

int main(){
	int process[5][2]={{0,4},{1,3},{2,1},{4,2},{6,5}}; //{arrivalTime,burstTime}
	int waiting_time[5],turn_around_time[5],completion[5];
	completion[0]=process[0][0]+process[0][1];
	turn_around_time[0]=completion[0]-process[0][0];
	waiting_time[0]=turn_around_time[0]-process[0][1];
	for (int i=1;i<5;i++){
		int max=process[i][0]>completion[i-1]?process[i][0]:completion[i-1];
		completion[i]=max+process[i][1];
		turn_around_time[i]=completion[i]-process[i][0];
		waiting_time[i]=turn_around_time[i]-process[i][1];
	}
	printf("at\t|\tbt\t|\tct\t|\ttat\t|\twt\n");
	for (int i=0;i<5;i++){
		printf("%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n",process[i][0],process[i][1],completion[i],turn_around_time[i],waiting_time[i]);
	}
}
