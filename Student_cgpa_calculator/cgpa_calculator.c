#include<stdio.h>
typedef struct student
{
    char name[50];
    int roll;
    float ct1;
    float ct2;
    float ct3;
    int attendance;
    float exam;
} Std ;
Std student[3];
float totalmark[3]={0},Cgpa[3];


int dataread(FILE *fp)
{
    int i=0,j,k,a[50];
    char ch[50][20];
  //  printf("anyhing to show");

    while(!feof(fp))
    {
        fscanf(fp,"%s %d %f %f %f %d %f",&student[i].name,&student[i].roll,&student[i].ct1,&student[i].ct2,&student[i].ct3,&student[i].attendance,&student[i].exam);
        i++;
    }

    int n=i;
    // printf("anyhing to show");



  //  write(fp,ch,a,n);

    fclose(fp);

    return n;
}

int cttaken()
{
    int i,j,k,temp=0,sum=0;

    for(int i=0;i<3;i++)
    {
        if(student[i].ct1>student[i].ct2)
        {
            temp=student[i].ct1;
            if(student[i].ct2>student[i].ct3)
            {
                 temp=temp+student[i].ct2;
            }
            else
            {
                temp=temp+student[i].ct3;
            }
        }
        else
        {
            temp=student[i].ct2;
             if(student[i].ct1>student[i].ct3)
            {
                 temp=temp+student[i].ct1;
            }
            else
            {
                temp=temp+student[i].ct3;
            }
        }

        totalmark[i]= ((float)temp/40.0)*60.00;


    }

}


int attendancetaken()
{
     int i,j,k,temp=0,sum=0;
     float total,val;

    for(int i=0;i<3;i++)
    {
       val= student[i].attendance/65.00;
       if(val>=0.9)
       {
           totalmark[i]=totalmark[i]+30.00;
       }
      else if(val>=0.85)
       {
           totalmark[i]=totalmark[i]+27.00;
       }
       else if(val>=0.80)
       {
           totalmark[i]=totalmark[i]+24.00;
       }
       else if(val>=0.75)
       {
           totalmark[i]=totalmark[i]+21.00;
       }
       else if(val>=0.70)
       {
           totalmark[i]=totalmark[i]+18.00;
       }
       else if(val>=0.65)
       {
           totalmark[i]=totalmark[i]+15.00;
       }
       else //(val>=0.60)
       {
           totalmark[i]=totalmark[i]+12.00;
       }


    }
}

int exammarktaken()
{
  int i,j,k,temp=0,sum=0;
     float total,val;

    for(int i=0;i<3;i++)
    {
      totalmark[i]=totalmark[i]+student[i].exam;

    }
}


int cgpacalculate()
{
    int i,j,k,temp=0,sum=0;
     float total,val;

    for(int i=0;i<3;i++)
    {
       val= totalmark[i]/300.00;

       if(val>=0.80)
       {
           Cgpa[i]=4.00;
       }
       else if(val>=0.75)
       {
            Cgpa[i]=3.75;
       }
       else if(val>=0.70)
       {
           Cgpa[i]=3.50;
       }
       else if(val>=0.65)
       {
            Cgpa[i]=3.25;
       }
      else if(val>=0.60)
       {
            Cgpa[i]=3.00;
       }
       else if(val>=0.55)
       {
            Cgpa[i]=2.75;
       }
        else if(val>=0.50)
       {
            Cgpa[i]=2.50;
       }
        else if(val>=0.45)
       {
            Cgpa[i]=2.25;
       }
        else if(val>=0.40)
       {
            Cgpa[i]=2.00;
       }
        else
       {
            Cgpa[i]=0.00;
       }






    }

}
int main()
{
    int i=0,j,temp=0,n;
    FILE *fp;

    fp=fopen("inputfile.txt","r+");
   // intdataread(fp);

      if(fp==NULL)
      {
           printf("nothing to show");
      }

    n=dataread(fp);
/*
    for(int i=0;i<3;i++)
        printf("%s\n",student[i].name);
*/

   cttaken();
   attendancetaken();
   exammarktaken();
   cgpacalculate();

 fclose(fp);
 fp=fopen("output.txt","w+");


    for(i=0;i<3;i++)
    {
        fprintf(fp,"%s %.3f\n",student[i].name,Cgpa[i]);
    }


/*
    for(int i=0;i<3;i++)
        printf("%f\n",totalmark[i]);

*/


    return 0;
}

