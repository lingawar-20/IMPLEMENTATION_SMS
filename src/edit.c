//C Language
//
// Project: Student Management System
//
// Program: Editing The student details
// Author: Dhanyashree V Reddy
//
//Update Time Spread:
//1 - 21 August 2021



void edit()
{
    student a,b;                          // Declearing Structure Type Variable //
    r a1,b1; 
    lm *s,*p,*n;                    // Declearing Pointer Type Variable //
    lr *m,*w,*k;
    char reg[10],op;
    char newe[100];
    int flag;
    s=p=n=NULL;
    flag=0;
    clrscr();
    printf("-----------------------------------");
    printf("| Edit Profile Of A Student |");
    printf("-----------------------------------");
    
    //f1=fopen("c:\\student/main.dat","rb");            //Edit with the main.dat file path
    
    
    if (f1==NULL)
    {printf("Databse not exist"); getch(); exit(0);}

    printf("| Enter Reg No Of Student :-"); fflush(stdin); gets(reg);
    
    while(fread(&a,size1,1,f1)==1)
    {
        n=(lm*)malloc(sizeof(lm));
        strcpy(n->lmregn,a.regn);
        strcpy(n->lmname,a.name);
        strcpy(n->lmf_name,a.f_name);
        strcpy(n->lmaddress,a.address);
        strcpy(n->lmcourse,a.course);
        strcpy(n->lmdoa,a.doa);
        n->next=NULL;
        if (s==NULL)
        {
            s=n;
        }
        else
        {
        for(p=s;p->next!=NULL;p=p->next);p->next=n;
        }
    }
    
    fclose(f1);
 
    //f1=fopen("c:\\student/main.dat","rb");        //Edit with the main.dat file path

    while(fread(&a,size1,1,f1)==1)
    {
        if(strcmp(a.regn,reg)==0)
        {
            printf("| |");
            printf("| |");
            printf("|-----------------------------Details------------------------------");
            printf("| Student Name :- %s",a.name);
            printf("| Student Father`s Name :- %s",a.f_name);
            printf("| Student Address :- %s",a.address);
            printf("| Course :- %s",a.course);
            printf("| Date of Addmission :- %s",a.doa);
            printf("|-----------------------------------------------------------------");
        }
        else
        {
            printf("Record Was Not Found");
        }
    }
    
    printf("|--------------------------Choose Any Option----------------------");
    printf("| Edit Name Press A |");
    printf("| Edit Father Name Press B |");
    printf("| Edit Address Press C |");
    printf("| Edit Course Press D |");
    printf("| Edit Date Of Admission Press E |");
    printf("|-----------------------------------------------------------------|");
    printf(" | Type your option:- ");
    
    fflush(stdin);scanf("%c",&op);
    
    for(p=s;p!=NULL;p=p->next)
    {
        if(strcmp(p->lmregn,reg)==0)
    {
        if (op=='A'||op=='a')
        {
            printf("Enter New Name :-");fflush(stdin);gets(newe);
            strcpy(p->lmname,newe);
            flag=0;
            break;
        }
        else if(op=='b'||op=='B')
        {
            printf("Enter New Father Name :-");fflush(stdin);gets(newe);
            strcpy(p->lmf_name,newe);
            flag=0;
            break;
        }
        else if(op=='c'||op=='C')
        {
            printf("Enter New Address :-");fflush(stdin);gets(newe);
            strcpy(p->lmaddress,newe);
            flag=0;
            break;
        }
        else if(op=='d'||op=='D')
        {
            printf("Enter New Course :-");fflush(stdin);gets(newe);
            strcpy(p->lmcourse,newe);
            flag=0;
            break;
        }
        else if (op=='e'||op=='E')
        {
            printf("Enter New Date of Addmission :-");fflush(stdin);gets(newe);
            strcpy(p->lmdoa,newe);
            flag=0;
            break;
        }
        else    
        {
        flag=2;
        break;
        }
    }
    else
    {
        flag=1;
    }
    }
 
    if(flag==1)
    { for(p=s;p!=NULL;p=p->next)
        {
            free(p);
        }
        printf("The Record was not found press any key to continue..");getch();
    }
    else if(flag==2)
    {
    for(p=s;p!=NULL;p=p->next)
    {
    free(p);
    }
    printf("You have enter wrong option press any key to continue ..");getch();
    }
    else
    {
    f2=fopen("c:\\student/main.dat","wb");
    for(p=s;p!=NULL;p=p->next)
    {
    strcpy(b.regn,p->lmregn);
    strcpy(b.name,p->lmname);
    strcpy(b.f_name,p->lmf_name);
    strcpy(b.address,p->lmaddress);
    strcpy(b.course,p->lmcourse);
    strcpy(b.doa,p->lmdoa);
    fwrite(&b,size1,1,f2);
    free(p);
    }
    fclose(f2);
    }
    getch();
    form1();
}
