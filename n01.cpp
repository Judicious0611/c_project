#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXNAME  20
#define MAXADDRESS 20
#define TEL	11
#define EMAIL 30
#define BIRTH 14

struct Students{				//ѧ����Ϣ�Ľṹģ�� 
	char name[MAXNAME];               
	int studyNum;
	int studentAge;
	int studentSex;
	char address[MAXADDRESS];
	char studentTel[TEL];
	char studentEmail[EMAIL];
	char studentBirth[BIRTH];
	struct Students * next; 		//ָ�������е���һ���ṹ 
}; 
struct Students * head = NULL;//����ͷָ��
struct Students * head1 = NULL;//������������� 
struct Students * head2 = NULL;//�������������
struct Students * prev=NULL, *current=NULL;

char *s_gets(char * st,int n);	//�ַ������뺯�� 
int  menu();					//��Ŀ¼�˵� 
void addStudents();				//���ѧ����Ϣ 
void DisplayStudents(struct Students *head,int flag);//չʾѧ����Ϣ
void Save();					//���������е����ݵ��ļ��� 
void saveData(char inputName[MAXNAME], int inputNum, int inputAge, int inputSex, char inputAddress[MAXADDRESS],char inputTel[TEL], char inputEmail[EMAIL],char inputBirth[BIRTH]);//���ļ��е����ݴ��浽������ 
void load();					//���ļ��л�õ�����д�뵽������
void exit0();					//�˳� 
void deleteStudents();			//ɾ��ѧ����Ϣ 
void moditfInfo();				//�޸�ѧ����Ϣ 
int dismenu();					//��ѯ��Ŀ¼ 
void DeleteMemory(struct Students *head);
struct Students *sortbynum(struct Students *head);  //��С������ѧ������ 
struct Students *sortbyage(struct Students *head);  //��С�������������� 
void fineInName();				//������������
void fineInId();			    //����ѧ�Ų��� 
char *s_gets(char *st,int n)	//�ַ������뺯�� 
{
	char *ret_val;
	char *find;
	ret_val=fgets(st,n,stdin);
	if(ret_val)
	{
		find=strchr(st,'\n');
		if(find)
		*find='\0';
		else
		while(getchar()!='\n')
		continue;
	}
	return ret_val;
 } 

int  menu()						//��Ŀ¼�˵� 
{
	int n;
	puts("       *****************ѧ���ɼ�����ϵͳ*****************\n");
	puts("       **		1�����������Ϣ			**\n");
	puts("       **		2�������Ϣ			**\n");
	puts("       **		3��ɾ����Ϣ			**\n"); 
	puts("       **		4���޸���Ϣ			**\n");
	puts("       **		5����Ϣ����			**\n");
	puts("       **		6��������������			**\n");
	puts("       **		7������ѧ�Ų���			**\n");
	puts("       **		0���˳�				**\n");
	puts("       **		�ף�����������ѡ��		**\n");
	scanf("%d",&n);
	switch(n)
	{
		case 1:DisplayStudents(head,1);break;
		case 2:addStudents();break;
		case 3:deleteStudents();break;
		case 4:moditfInfo();break;
		case 5:dismenu();break;
		case 6:fineInName();break;
		case 7:fineInId();break;
		case 0:exit0();break;
	}
	return n; 	
 }
void exit0()					//�˳� 
{
	struct Students *p = head;
	while(p!= NULL)
	{
		free(p);
		p = p->next;		
	}
	printf("Bye!"); 
	exit(0);
}
void fineInName()				//������������ 
{
	struct Students *p = head;
    char studentName[MAXNAME] = "";
    if (head == NULL)
    {
        printf("û�����ݲ���\n");
        return;
    }
    printf("��������Ҫ���ҵ�ѧ����������");
    scanf("%s", studentName);
    while (0!=strcmp(studentName,p->name)&&p->next != NULL)
    {
        p = p->next;
    }
    if (0==strcmp(studentName,p->name))
    {
        puts("    ����        ѧ��       ����       �Ա�    ��ַ             �ֻ���\t\t����\t\t    ��������");
        printf("%10s%10d%10d%10d%10s%20s%20s%20s", p->name, p->studyNum, p->studentAge,p->studentSex, p->address, p->studentTel,p->studentEmail,p->studentBirth);
        printf("\n");
    }
    else{
        printf("û����Ҫ���ҵ�����\n");
    }
    return;
	
}
void fineInId()				//����ѧ�Ų��� 
{
	struct Students *p = head;
    int studentID=0;
    if (head == NULL)
    {
        printf("û�����ݲ���");
        return;
    }
    printf("��������Ҫ���ҵ�ѧ����ѧ�ţ�");
    scanf("%d", &studentID);
    while (studentID != p->studyNum&&p->next != NULL)
    {
        p = p->next;
    }
    if (studentID == p->studyNum)
    {
        puts("    ����        ѧ��       ����       �Ա�    ��ַ             �ֻ���\t\t����\t\t    ��������");
        printf("%10s%10d%10d%10d%10s%20s%20s%20s", p->name, p->studyNum, p->studentAge,p->studentSex, p->address, p->studentTel,p->studentEmail,p->studentBirth);
        printf("\n");
    }
    else{
        printf("û����Ҫ���ҵ�����");
    }
    return;
	
}
int dismenu()					//��ѯ��Ŀ¼ 
 {
 	int n; 
 	
	puts("       1����������С��������\n"); 
	puts("       2����ѧ����С��������\n");
	puts("       0���������˵�\n");
	printf("       ��ѡ��\n");
	scanf("%d",&n);
	switch(n)
	{
		case 0:menu();return 0;
		case 2:head1 = sortbynum(head);DisplayStudents(head1,1);break;
	    case 1:head2 = sortbyage(head);DisplayStudents(head2,1);break;
		default:printf("error!\n");break;
	}
	return n;
 }
void DeleteMemory(struct Students *head)
{
    struct Students *p = head, *pr = NULL;
    while (p != NULL)
    {
        pr = p;
        p = p->next;
        free(pr);
    }
    
}
struct Students *sortbynum(struct Students *head)  //��С������ѧ������ 
{  
    struct Students *first; 
    struct Students *t;  
    struct Students *p;   
    struct Students *q;   

    first = head->next;   
    head->next = NULL; 

    while (first != NULL)   
    {  
        for (t = first, q = head; ((q != NULL) && (q->studyNum < t->studyNum)); p = q, q = q->next);   

        first = first->next; 

        if (q == head)   
        {  
            head = t;  
        }  
        else 
        {  
            p->next = t;  
        }  
        t->next = q; 

    }  
    return head;  
}
struct Students *sortbyage(struct Students *head)  //��С�������������� 
{  
    struct Students *first; 
    struct Students *t;  
    struct Students *p;   
    struct Students *q;   

    first = head->next;   
    head->next = NULL; 

    while (first != NULL)   
    {  
        for (t = first, q = head; ((q != NULL) && (q->studentAge < t->studentAge)); p = q, q = q->next);   

        first = first->next; 

        if (q == head)   
        {  
            head = t;  
        }  
        else 
        {  
            p->next = t;  
        }  
        t->next = q; 

    }  
    return head;  
}
void addStudents()				//���ѧ����Ϣ 
{
	char ch = getchar();//�������з���Ӱ�� 
	char inputName[MAXNAME];
	char inputAddress[MAXADDRESS];
	char inputTel[TEL];
	char inputEmail[EMAIL];
	char inputBirth[BIRTH];
	int inputNum;
	int inputAge;
	int inputSex;
	int sexNum; 
	puts("Enter the first student's name!");
    while (gets(inputName) != NULL && inputName[0] != '\0')
    {

        puts("Enter student's studentNum");	//����ѧ�� 
		scanf("%d", &inputNum);
		puts("Enter student's studyAge");	//�������� 
		scanf("%d", &inputAge);
		puts("Enter student's studentSex");//�����Ա� 
		puts("1��˧��\n");
		puts("2����Ů\n");
		puts("�ף�����������ѡ��");
		scanf("%d", &sexNum);
		switch(sexNum)
		{
			case 1:
				inputSex=1; break;
			case 2:
				inputSex=2; break;
		}
		getchar();//�������з���Ӱ�� 
		puts("Enter student's address");//�����ַ 
		gets(inputAddress);

		puts("Enter student's studentTel");//����绰���� 
		gets(inputTel);

		puts("Enter student's studentEmail");//�������� 
		gets(inputEmail);

		puts("Enter student's studentBirth ,��ʽΪ ��1997/05/12��");//����������� 
		gets(inputBirth);
		
        while (getchar() != '\n')
        {
        	puts("¼��ɹ�");
			continue;
		}
           

        puts("Enter next  the student's name!(empty line to stop):");
		saveData(inputName, inputNum, inputAge, inputSex,inputAddress,inputTel,inputEmail,inputBirth);//����������ݶ�ȡ�������� 
		
    }
    Save();
	DisplayStudents(head,1);//����������ݴ��浽�ļ��� 
	
}

void deleteStudents()			//ɾ��ѧ����Ϣ 
{
	struct Students *p = head, *pr = head;
    char studentName[10] = "";
    if (head == NULL) {
        printf("�Բ���û�����ݿ���ɾ��");
        return;
    }
    printf("��������Ҫɾ����ѧ��������:");
    scanf("%s", studentName);
    while (0!=strcmp(studentName,p->name)&&p->next != NULL)
    {
        pr = p;
        p = p->next;
    }
    if (0==strcmp(studentName, p->name))
    {
        if (p == head) {
            head = p->next;//����ͷָ�� 
        }
        else
        {
            pr->next = p->next;//��������ڴ� 
        }
        free(p);//�ͷ��ڴ� 
        Save();
		puts("ɾ���ɹ���"); 
    }
    else
    {
        printf("��Ҫ���ҵ��������δ�ҵ�");
    }
    return;
	
}

void moditfInfo()				//�޸�ѧ����Ϣ 
{
	struct Students *p = head, *pr = head;
    char studentName[MAXNAME] = "";
    char inputName[MAXNAME];
	char inputAddress[MAXADDRESS];
	char inputTel[TEL];
	char inputEmail[EMAIL];
	char inputBirth[BIRTH];
	int inputNum;
	int inputAge;
	int inputSex;
	int sexNum; 
	
    if (head == NULL) {
        printf("�Բ���û�����ݿ����޸ģ������ѧ����Ϣ\n");
        return;
    }
    printf("��������Ҫ�޸ĵ�ѧ��������:");
    scanf("%s", studentName);
    while (0!=strcmp(studentName,p->name)&&p->next != NULL)
    {
        pr = p;
        p = p->next;
    }
    if (0==strcmp(studentName, p->name))
    {
    	//�ҵ�ƥ���ѧ����׼���޸�
		 
        puts("���ҳɹ����������޸ĸ�������");
        getchar();//����\n��Ӱ�� 
        puts("Enter student's name");	//�������� 
        gets(inputName);
        strcpy(p->name, inputName);  
		puts("Enter student's studentNum");	//����ѧ�� 
		scanf("%d", &p->studyNum);
		puts("Enter student's studyAge");	//�������� 
		scanf("%d", &p->studentAge);
		puts("Enter student's studentSex");//�����Ա� 
		puts("1��˧��\n");
		puts("2����Ů\n");
		puts("�ף�����������ѡ��");
		scanf("%d", &sexNum);
		switch(sexNum)
		{
			case 1:
				p->studentSex=1; break;
			case 2:
				p->studentSex=2; break;
		}
		getchar();//�������з���Ӱ�� 
		puts("Enter student's address");//�����ַ 
		gets(inputAddress);
		strcpy(p->address, inputAddress);
		puts("Enter student's studentTel");//����绰���� 
		gets(inputTel);
		strcpy(p->studentTel, inputTel);
		puts("Enter student's studentEmail");//�������� 
		gets(inputEmail);
		strcpy(p->studentEmail, inputEmail);
		puts("Enter student's studentBirth ,��ʽΪ ��1997/05/12��");//����������� 
		gets(inputBirth); 
		strcpy(p->studentBirth, inputBirth);
		puts("�޸ĳɹ�!");
		Save(); 
    }
    else
    {
        printf("��Ҫ���ҵ��������δ�ҵ�");
    }
    return;
}

void Save()						//���������е�����
{ 
    FILE *fp;
    struct Students *p = head;
    if ((fp = fopen("data.txt", "w")) == NULL)
    {
        printf("���ļ�ʧ��");
        return;
    }
    while (p != NULL)
    {
        fprintf(fp, "%20s%20d%20d%20d%20s%20s%20s%20s", p->name, p->studyNum, p->studentAge,p->studentSex, p->address, p->studentTel,p->studentEmail,p->studentBirth);
		
        p = p->next;
    }
    fclose(fp);
    return;
}

void DisplayStudents(struct Students *head,int flag)	//��ӡ�����е����� 
{
    struct Students *p = head;
    if (p == NULL)
    {
        return;
    }
    if(flag == 1)
    {
    	puts("    ����        ѧ��       ����       �Ա�    ��ַ             �ֻ���\t\t����\t\t    ��������");
	}
    printf("%10s%10d%10d%10d%10s%20s%20s%20s", p->name, p->studyNum, p->studentAge,p->studentSex, p->address, p->studentTel,p->studentEmail,p->studentBirth);
    printf("\n");
    DisplayStudents(p->next,0);
}

void load()						//���ļ��л�õ�����д�뵽������
{
    char inputName[MAXNAME];
	char inputAddress[MAXADDRESS];
	char inputTel[TEL];
	char inputEmail[EMAIL];
	char inputBirth[BIRTH];
	int inputNum;
	int inputAge;
	int inputSex;
	int sexNum; 
    FILE *fp;
    char c;
    if ((fp = fopen("data.txt", "r")) == NULL)
    {
        printf("�ļ���ʧ��");
        return;
    }
    while ((c = fgetc(fp))!=EOF)
    {
        fscanf(fp, "%20s", &inputName);
        fscanf(fp, "%20d", &inputNum);
        fscanf(fp, "%20d",  &inputAge);
        fscanf(fp, "%20d",  &inputSex);
        fscanf(fp, "%20s", &inputAddress);
        fscanf(fp, "%20s", &inputTel);
        fscanf(fp, "%20s", &inputEmail);
        fscanf(fp, "%20s", &inputBirth);
        saveData(inputName, inputNum, inputAge, inputSex,inputAddress,inputTel,inputEmail,inputBirth);//���ļ��е����ݶ�ȡ�������� 
    }
    fclose(fp);
}

void saveData(char inputName[MAXNAME], int inputNum, int inputAge, int inputSex, char inputAddress[MAXADDRESS],char inputTel[TEL], char inputEmail[EMAIL],char inputBirth[BIRTH])//���ļ��е����ݶ�ȡ�������� 
{
	struct Students *p = NULL, *pr = head;
    p = (struct Students *) malloc(sizeof(struct Students));
    if (p == NULL)
    {
        printf("�����ڴ�ʧ��");
        return;
    }
    if (head == NULL)
    {
        head = p;
    }
    else {
        while (pr->next != NULL)
        {
            pr = pr->next;
        }
        pr->next = p;
    }
    strcpy(p->name, inputName);              
	p->studyNum = inputNum;
	p->studentAge = inputAge;
	p->studentSex = inputSex;
	strcpy(p->address, inputAddress);
	strcpy(p->studentTel, inputTel);
	strcpy(p->studentEmail, inputEmail);
	strcpy(p->studentBirth, inputBirth);
    
    p->next = NULL;
    return;
} 


int main(){
	

	system("color 3f");											//������ɫ���� 
 	puts("       ***********************************************************");
 	puts("       ***********************************************************");
 	puts("       ***********************************************************");
 	puts("                       ***************************"); 
 	printf("                         ��ӭʹ��ѧ����Ϣ����ϵͳ\n");
 	puts("                       ***************************");
 	puts("       ***********************************************************");
 	puts("       ***********************************************************");
 	puts("       ***********************************************************");
 	printf("\n");
 	printf("\n");
	load();//�����ϴα�������� 
	while(menu())
 	{
 			
	}
	return 0;
} 

