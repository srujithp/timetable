#include<stdio.h>
#include<conio.h>
#include<string.h>

struct sec
{
    char week[7][6][20];

}s[10];

int main()
{
	char br[20],ntteachers[10][10],nlteachers[10][10],tsubs[10][10],lsubs[10][10];

	int nsec,dur,nthe,nlab,i,j,k,l,m;

    printf("-------------This is a time table generator program----------------\nEnter your branch  :  ");

	scanf("%s",br);

	printf("Enter the no. of sections");

	scanf("%d",&nsec);


	printf("Enter no. of theory subjects : ");

	scanf("%d",&nthe);

	printf("Enter no. of lab subjects : ");

	scanf("%d",&nlab);


    printf("enter %d no of theory teacher names and their subjects",nthe);

    for(i=0;i<nthe;i++)
        scanf("%s %s",ntteachers[i],tsubs[i]);

    printf("enter %d no of lab teacher names and their subjects",nlab);

    for(i=0;i<nlab;i++)
        scanf("%s %s",nlteachers[i],lsubs[i]);


    for(i=0,l=0;i<nsec;i+=2,l++)
    {

        for(j=0,m=0;j<nlab;j++,m++)
        {
            for(k=0;k<3;k++)
            {
              if((m+l)<nlab)
            strcpy(s[i].week[j][k],lsubs[m+l]);
            else
            {
                m=-l;
                strcpy(s[i].week[j][k],lsubs[m+l]);
            }

            }
        }

    }

     for(i=1,l=0;i<nsec;i+=2,l++)
    {
        for(j=0,m=0;j<nlab;j++,m++)
        {
            for(k=3;k<6;k++)
            {
            if((m+l)<nlab)
            strcpy(s[i].week[5-j][k],lsubs[m+l]);
            else
            {
                m=-l;
                strcpy(s[i].week[5-j][k],lsubs[m+l]);
            }

            }

        }

    }

   for(i=0;i<nsec;i++)
   {
       printf("\nsection %d\n",i);
       for(j=0;j<6;j++)
       {
           for(k=0;k<6;k++)
           {
                printf("%s   ",s[i].week[j][k]);
           }
           printf("\n");
       }
        printf("\n");
   }



    _getch();
    return 1;

}
