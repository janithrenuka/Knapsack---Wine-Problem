#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAXSIZE 50

	int N,M;

struct barrel{
	
	int numOfBottles;
	int valOfBottle;
	
}b[MAXSIZE];

int main(){
	

	int i,j,k;
	
	
	//printf("enter number of bottles i have and & number of barrels:");
	scanf("%d",&N);  //number of bottles sadun bought
	scanf("%d",&M);  //number of barrels
	
	int barrelPrice[M]; //barrel prices array
	int bbottlePrice[M];  //one bottle price in barrel array
	
	//number of bottles in each barrel
	//printf("number of bottles in each barrel :");
	for(i=0;i<M;i++)
	   {
	   	scanf("%d",&b[i].numOfBottles); 
	   }

	//calculate price of one bottle in each barrel
	//printf("value of each barrel :");
	for(j=0;j<M;j++)
	  {
	   scanf("%d",&barrelPrice[j]); //price of each barrel
	   b[j].valOfBottle = barrelPrice[j]/b[j].numOfBottles;  //price of one bottle in each barrel
       bbottlePrice[j] = b[j].valOfBottle;
	   
	  }
	
	//printf("\n");
	  
	//print price of one bottle in each barrel
	//printf("value of one bottle in each barrel: ");
	//  for(k=0;k<M;k++)
	//    {
	//     printf("%d ",bbottlePrice[k]); 
	//  	}
	
	//sorting bottle prices and barrels according to price
	struct barrel tempb;
	int temp ;
	  for(i=0;i<M;i++)
	    {
	     for(j=i+1;j<M;j++)
	        {
	          if(bbottlePrice[i]<bbottlePrice[j])
	              {
	                temp = bbottlePrice[i];
	                bbottlePrice[i] = bbottlePrice[j]; //sort price of one bottle in each barrel to decending order
	                bbottlePrice[j] = temp;
	                
	                tempb = b[i];
	                b[i] = b[j];   //sort the barrel according to price of one bottle
	                b[j] = tempb;
 			      }
			}
	     
		}
		
	//printf("\n");
		
	//print sorted array of price of one bottle in each barrel
	//printf("sorted value of one bottle in each barrel: ");
	//     for(i=0;i<M;i++)
	//      {
	//     	printf("%d ",bbottlePrice[i]); 
	//	  }
		
	
	//calculate maximum value
	int sum=0;
	for(k=0;k<M;k++)
		{
		   if(N>=b[k].numOfBottles)
		       {
		       	sum = sum + bbottlePrice[k] * b[k].numOfBottles;
		       	N = N - b[k].numOfBottles;
		       }

		   else
		       {
		       	 sum = sum + bbottlePrice[k]*N;
		       	 break;
			   }	   
			   
		}
		   
	   
	printf("\n%d",sum); //print maximum offer
    	
	return 0;

}

