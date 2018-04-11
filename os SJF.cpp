

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
int n,i,j,temp;
int bt[10],at[10],st[10],ft[10],wt[10],ta[10];//  burst,arrival,static,waiting 
//and turnaround time respextivly

int totwt=0,totta=0; //total waiting time n total turnaroundtime
float awt,ata; //avg waiting time n avg turnaroundtime
char pn[10][10],t[10]; // process name
    
    printf("Enter the No. of process:\n");
    scanf("%d",&n);    
    
for(i=0; i<n; i++)
{
    printf("Enter %d th process name, arrival time & burst time:\n",i+1);
    scanf("%s \t %d \t %d",pn[i],&at[i],&bt[i]);
 }
for(i=0; i<n; i++)
   for(j=0; j<n; j++)
   {
    if(bt[i]<bt[j])
{
	temp=at[i];
	at[i]=at[j];
    at[j]=temp;
    temp=bt[i];
	bt[i]=bt[j];
    bt[j]=temp;
    
	strcpy(t,pn[i]);
	strcpy(pn[i],pn[j]);
	strcpy(pn[j],t);
}
}
	
for(i=0; i<n; i++)
{
if(i==0)
   st[i]=at[i];
else
    st[i]=ft[i-1];
    wt[i]=st[i]-at[i];
    ft[i]=st[i]+bt[i];
    ta[i]=ft[i]-at[i];
    totwt+=wt[i];
    totta+=ta[i];
}
    awt=(float)totwt/n;
    ata=(float)totta/n;
    
    
    printf("\nPname \t Arrivaltime \t Bursttime \t Waitingtime \t Turn arond time\n");
    
    for(i=0; i<n; i++)
    printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d \n",pn[i],at[i],bt[i],wt[i],ta[i]);
    printf("\n\nAverage waiting time is:%f\n",awt);
    printf("\nAverage turnaroundtime is:%f\n",ata);
    getch();
}
