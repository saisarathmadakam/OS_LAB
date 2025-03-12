#include<stdio.h>
int main(){
    int p[20],wt[20],bt[20],tat[20],n,i,k,temp;
    float wtavg,tatavg;
    printf("Enter the number of processes--");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        p[i]=i;
        printf("\nEnter the burst time of the process %d--",i);
        scanf("%d",&bt[i]);
    }
    for(i=0;i<n;i++){
        for(k=i+1;k<n;k++){
            if(bt[i]>bt[k]){
                temp=bt[i];
                bt[i]=bt[k];
                bt[k]=temp;
                temp=p[i];
                p[i]=p[k];
                p[k]=temp;
            }
        }
    }
    wtavg=wt[0]=0;
    tatavg=tat[0]=bt[0];
    for(i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
        tat[i]=tat[i-1]+bt[i];
        wtavg=wtavg+wt[i];
        tatavg=tatavg+tat[i];
    }
    printf("\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
    for(i=0;i<n;i++){
        printf("\n P%d \t\t %d \t\t %d \t\t %d",p[i],bt[i],wt[i],tat[i]);
    }
    printf("\n Average Waiting Time--%f",wtavg/n);
    printf("\n Average Turnaround Time--%f",tatavg/n);
    return 0;
}
