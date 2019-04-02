/*A number of cats and mice inhabit a house. The cats and mice have worked out a deal where the mice can steal pieces of the cats’ food, so long as the cats never see the mice actually doing so. If the cats see the mice, then the cats must eat the mice (or else lose face with all of their cat friends). There are NumBowls cat food dishes, NumCats cats,
and NumMice mice. Your job is to synchronize the cats and mice so that the following requirements are satisfied:
No mouse should ever get eaten. You should assume that if a cat is eating at a food dish, any mouse attempting to eat from that dish or any other food dish will be seen and eaten. When cats aren’t eating, they will not see mice eating. In other words, this requirement states that if a cat is eating from any bowl, then no mouse should be eating from any bowl. Only one mouse or one cat may eat from a given dish at any one time. Neither cats nor mice should starve. A cat or mouse that wants to eat should eventually be able to eat. For example, a synchronization solution that permanently prevents all mice from eating would be unacceptable. When we actually test your solution, each simulated cat and mouse will only eat a finite number of times; however, even if the simulation were allowed to run forever, neither cats nor mice should starve.*/

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num1,num2,NumCats,NumMice,i,count,temp1=0,temp2=0;
	printf("Enter the number of cats :\n");
	scanf("%d",&NumCats);
	printf("Enter the number of mice :\n");
	scanf("%d",&NumMice);
	int Cat_count[NumCats],Mice_count[NumMice];
	for(i=0;i<NumCats;i++)
	{
		Cat_count[i]=0;
	}
	for(i=0;i<NumMice;i++)
	{
		Mice_count[i]=0;
	}
	while(temp1!=NumCats&&temp2!=NumMice)
	{
		num1=(rand()%2)+1;
		if(num1==1)
		{
			num2=(rand()%NumCats)+1;
			printf("\n%d Cat is eating : ",num2);
			count=0;
			for(i=0;i<temp1;i++)
			{
				if(Cat_count[i]==num2)
				{
					count=1;
					break;
				}
				else
				{
					continue;
				}				
			}
			if(count!=1)
			{
				Cat_count[temp1]=num2;
				temp1++;
			}
		}
		if(num1==2)
		{
			num2=(rand()%NumMice)+1;
			printf("\n%d Mouse is eating : ",num2);
			count=0;
			for(i=0;i<temp2;i++)
			{
				if(Mice_count[i]==num2)
				{
					count=1;
					break;
				}
				else
				{
					continue;
				}
				
			}
			if(count!=1)
			{
				Mice_count[temp2]=num2;
				temp2++;
			}
		}

	}
		for(i=0;i<NumCats;i++)
	{
		
		printf("%d, ",Cat_count[i]);
	}
	printf("\n");
	for(i=0;i<NumMice;i++)
	{
		
		printf("%d, ",Mice_count[i]);
	}
	
}
