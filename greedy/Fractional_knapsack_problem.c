#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void knapsack(int n,float profit[],float weight[],float cap){
     float used[20];
     float curr_wt , tot_p = 0;
     curr_wt = cap;
     int i;

     for (int j = 0; j < n; j++)
     {
       used[j] = 0.0;
     }
     

     for (i = 0; i < n; i++)
     {
      if (weight[i] > curr_wt)
      {
         break;
      }
      else{
         used[i] = 1.0;
         tot_p += profit[i];
         curr_wt -= weight[i];
      }
     }

     if(i < n) used[i] = curr_wt/weight[i];

     tot_p += used[i] * profit[i];

     printf("\n The total profit is :- %0.2f ", tot_p);
     
}

int main()
{
   float weight[20], profit[20], capacity;
   int num, i, j;
   float ratio[20], temp;

   printf("\nEnter the no. of objects:- ");
   scanf("%d", &num);

   printf("\nEnter the wts of each object:- ");
   for (i = 0; i < num; i++) {
      scanf("%f", &weight[i]);
   }
   
   printf("\nEnter the profits of each object:- ");
   for (i = 0; i < num; i++) {
      scanf("%f", &profit[i]);
   }

   printf("\nEnter the capacity of knapsack:- ");
   scanf("%f", &capacity);

   for (int i = 0; i < num; i++)
   {
      ratio[i] = profit[i] / weight[i];
   }

   for (int i = 0; i < num; i++)
   {
      for (int j = i+1; j < num; j++)
      {
         if(ratio[i] < ratio[j]){
            temp = ratio[i];
            ratio[i] = ratio[j];
            ratio[j] = temp;

            temp = profit[i];
            profit[i] = profit[j];
            profit[j] = temp;

            temp = weight[i];
            weight[i] = weight[j];
            weight[j] = temp;
         }
      }
      
   }
   
   knapsack(num,profit,weight,capacity);
   return 0;
}