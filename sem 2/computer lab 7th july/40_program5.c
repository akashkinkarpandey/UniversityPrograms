#include<stdio.h>
struct Time{
    int hh;
    int mm;
    int ss;
};
int main()
{
    struct Time T1,T2;
    char c[50];
    printf("Enter 1st Time in hh:mm:ss format\n");
    gets(c);
    int s=0;
    s=s*10+(c[0]-'0');
    s=s*10+(c[1]-'0');
    T1.hh=s;
    s=0;
    s=s*10+(c[3]-'0');
    s=s*10+(c[4]-'0');
    T1.mm=s;
    s=0;
    s=s*10+(c[6]-'0');
    s=s*10+(c[7]-'0');
    T1.ss=s;


    printf("Enter 2nd Time in hh:mm:ss format\n");
    gets(c);
    s=0;
    s=s*10+(c[0]-'0');
    s=s*10+(c[1]-'0');
    T2.hh=s;
    s=0;
    s=s*10+(c[3]-'0');
    s=s*10+(c[4]-'0');
    T2.mm=s;
    s=0;
    s=s*10+(c[6]-'0');
    s=s*10+(c[7]-'0');
    T2.ss=s;
    struct Time T3={0,0,0};
    int t=T1.ss+T2.ss;
    T3.mm+=((t/60));
    T3.ss=(t)-(t/60)*60;
    T3.mm=T1.mm+T2.mm+T3.mm;
    T3.hh+=(T3.mm/60);
    T3.mm=(T3.mm)-(T3.mm/60)*60;
    T3.hh=T1.hh+T2.hh+T3.hh;
printf("new Time is %d:%d:%d\n",T3.hh,T3.mm,T3.ss);


    
}
