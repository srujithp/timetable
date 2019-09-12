#include<stdio.h>
#include<conio.h>
#include<string.h>

struct sec
{
    char week[7][6][20];
    char week1[7][6][20];

}s[10];
char weekdays[10][10]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

int main()
{
	char br[20],ntteachers[10][10],nlteachers[10][10],tsubs[10][10],lsubs[10][10];

	int nsec,dur,nthe,nlab,i,j,k,l,m;

    printf("-------------This is a time table generator program----------------\nEnter your branch  :  ");

	scanf("%s",br);

	printf("Enter the no. of sections (MAX of 6) : ");

	scanf("%d",&nsec);


	printf("Enter no. of theory subjects (MIN of 6) : ");

	scanf("%d",&nthe);

	printf("Enter no. of lab subjects (MAX of 6) : ");

	scanf("%d",&nlab);


    printf("enter %d no of theory teacher names and their subjects\n",nthe);

    for(i=0;i<nthe;i++)
        scanf("%s %s",ntteachers[i],tsubs[i]);

    printf("enter %d no of lab teacher names and their subjects\n",nlab);

    for(i=0;i<nlab;i++)
        scanf("%s %s",nlteachers[i],lsubs[i]);


    for(i=0,l=0;i<nsec;i+=2,l++)
    {

        for(j=0,m=0;j<nlab;j++,m++)
        {
            for(k=0;k<3;k++)
            {
              if((m+l)<nlab)
              {
                    strcpy(s[i].week[j][k],lsubs[m+l]);
                    strcpy(s[i].week1[j][k],nlteachers[m+l]);
              }
            else
            {
                m=-l;
                strcpy(s[i].week[j][k],lsubs[m+l]);
                strcpy(s[i].week1[j][k],nlteachers[m+l]);
            }

            }
        }

    }
    int p=0;
    for(i=0;i<nsec;i+=2)
    {
        p=i;


        for(j=nlab;j<6;j++)
        {
            for(k=0;k<6;k++)
            {
                if(p<nthe)
                {
                strcpy(s[i].week[j][k],tsubs[p]);
                strcpy(s[i].week1[j][k],ntteachers[p]);
                p++;
                }
                else
                {
                    p=0;
                    strcpy(s[i].week[j][k],tsubs[p]);
                    strcpy(s[i].week1[j][k],ntteachers[p]);
                    p++;
                }
            }

        }

         for(j=0;j<nlab;j++)
        {
            for(k=3;k<6;k++)
            {
                if(p<nthe)
                {
                strcpy(s[i].week[j][k],tsubs[p]);
                strcpy(s[i].week1[j][k],ntteachers[p]);
                p++;
                }
                else
                {
                    p=0;
                    strcpy(s[i].week[j][k],tsubs[p]);
                    strcpy(s[i].week1[j][k],ntteachers[p]);
                    p++;
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
            {
                strcpy(s[i].week[5-j][k],lsubs[m+l]);
                strcpy(s[i].week1[5-j][k],nlteachers[m+l]);
            }
            else
            {
                m=-l;
                strcpy(s[i].week[5-j][k],lsubs[m+l]);
                strcpy(s[i].week1[5-j][k],nlteachers[m+l]);
            }

            }

        }

    }

    for(i=1;i<nsec;i+=2)
    {
        p=i;
        for(j=0;j<nlab;j++)
        {
            for(k=0;k<3;k++)
            {
                if(p<nthe)
                {
                strcpy(s[i].week[5-j][k],tsubs[p]);
                strcpy(s[i].week1[5-j][k],ntteachers[p]);
                p++;
                }
                else
                {
                    p=0;
                    strcpy(s[i].week[5-j][k],tsubs[p]);
                    strcpy(s[i].week1[5-j][k],ntteachers[p]);
                    p++;
                }
            }
        }

        for(j=nlab;j<6;j++)
        {
            for(k=0;k<6;k++)
            {
                if(p<nthe)
                {
                strcpy(s[i].week[5-j][k],tsubs[p]);
                strcpy(s[i].week1[5-j][k],ntteachers[p]);
                p++;
                }
                else
                {
                    p=0;
                    strcpy(s[i].week[5-j][k],tsubs[p]);
                    strcpy(s[i].week1[5-j][k],ntteachers[p]);
                    p++;
                }
            }
        }

    }

   for(i=0;i<nsec;i++)
   {
       printf("\nsection %c\n\n",i+65);
       printf("             09:00        09:55        10:50        11:45        12:15        01:10        02:05        03:00\n");
       printf("________________________________________________________________________________________________________________\n\n");
       for(j=0;j<6;j++)
       {
           printf("%10s       ",weekdays[j]);
           for(k=0;k<3;k++)
           {
                printf("%10s   ",s[i].week[j][k]);
           }
           printf("     lunch   ");
           for(k=3;k<6;k++)
           {
                printf("%10s   ",s[i].week[j][k]);
           }
           printf("\n                 ");
            for(k=0;k<3;k++)
           {
                printf("%10s   ",s[i].week1[j][k]);
           }
             printf("             ");
           for(k=3;k<6;k++)
           {
                printf("%10s   ",s[i].week1[j][k]);
           }
           printf("\n\n");
       }
        printf("\n\n\n");
   }



    _getch();
    return 1;

}
