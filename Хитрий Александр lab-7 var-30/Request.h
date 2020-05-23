#ifndef _Request_h_
#define _Request_h_
#include <dir.h>

void aelement(Avto* a)
{
if(a==NULL)
return;
printf("   %d - %s\n",a->index,a->model);
aelement(a->next);
}

void ppelement(Person* a)
{
if(a==NULL)
return;
printf("   %d - %s\n",a->index,a->FIO);
ppelement(a->next);
}

void dataBase(Avto* avto,Person* persona)
{
Avto* avto1 = avto;
Person* persona1 = persona;
struct ffblk f; //Создаём экземпляр структуры ffblk
int done;

done = findfirst("E:\\sem#2\\C\\lb7\\Person1\\*.txt", &f, 0);
//Ищем пока есть файлы
if(!done)
	{
	ffpread(persona1, f.ff_name);
	ffpread(persona1, f.ff_name); //Пишем имя файла
	done = findnext(&f); //Ищем следующий такой файл
	}
while (!done)
{
pcr(persona1);
persona1 = persona1->next;
ffpread(persona1, f.ff_name); //Пишем имя файла
done = findnext(&f); //Ищем следующий такой файл
}

done = findfirst("E:\\sem#2\\C\\lb7\\Avto1\\*.txt", &f, 0);
if(!done)
	{
	ffaread(avto, f.ff_name);
	ffaread(avto, f.ff_name); //Пишем имя файла
	done = findnext(&f); //Ищем следующий такой файл
	}
while (!done)
{
ffaread(avto, f.ff_name); //Пишем имя файла

acr(avto1);
avto1 = avto1->next;

done = findnext(&f); //Ищем следующий такой файл
}
}

void apchoice(Avto* a)
{
Avto* b = a;
int number;
for(;;)
	{
	if(b==NULL)
		break;
	number = b->index;
	b = b->next;
	}
b = acreate();
printf("Введите желаемые данные об автомобиле.\n Если какой-либо параметр не важен, введите '0'\n ");
awrite(b);
Avto* comparison = a;
printf("Возможные варианты :\n");
for(;;)
	{
	if(comparison->model == b->model || (strlen(b->model) == 1 && b->model[0]=='0'))
	 if(comparison->ageCreate == b->ageCreate || b->ageCreate == 0)
	  if(comparison->mileAge == b->mileAge ||  b->mileAge == 0)
	if(comparison->engineSize == b->engineSize || b->engineSize == (float)0 )
	if(comparison->power == b->power || b->power == 0)
	if(comparison->transmission == b->transmission || (strlen(b->transmission) == 1 && b->transmission[0]=='0'))
	if(comparison->gearBox == b->gearBox || (strlen(b->gearBox) == 1 && b->gearBox[0]=='0'))
	if(comparison->condision == b->condision || (strlen(b->condision) == 1 && b->condision[0]=='0'))
	if(comparison->price == b->price || b->price == (float)0 )
	printf(" %d - %s\n", comparison->index, comparison->model);

	if(comparison->next==NULL)
	break;
	comparison = comparison->next;
	}
b->index = 1;
aremove(b);
}

float profit(Avto* a)
{
	float fullPrice = a->price + 250;
	if(a->ageCreate <= 3)
	fullPrice+= 0.6 * (float)a->engineSize;
	else if(a->ageCreate<=10)
	{
		if(a->engineSize < 2500)
		fullPrice += 0.35 * a->engineSize;
		else fullPrice += 0.6 * a->engineSize;
	}
	else if(a->ageCreate<=14)
	fullPrice+= 0.6 * (float)a->engineSize;
	else fullPrice+= 2.0 * (float)a->engineSize;
	fullPrice *= 1.15;
	return fullPrice;
}

void query(Avto* ayto, Person* perso)
{
int choose = 0;
printf("Выберите покупателя\n");
Person* p = perso;
Avto* a = ayto;
ppelement(p);

if(scanf("%d",&choose)!=1)
	{
	printf("Error");
	return;
	}
p=perso;
while(p!=NULL)
	{
	if(choose == p->index)
		{
		break;
		}
	p = p->next;
	}
if( p == NULL)
return;

printf("");
aelement(a);
if(scanf("%d",&choose)!=1)
	{
	printf("Error");
	return;
	}
a = ayto;
while(a!=NULL)
	{
	if(choose == a->index)
		{
		break;
		}
	a = a->next;
	}
if( a == NULL)
return;

FILE* fl = fopen("e:\\sem#2\\C\\lb7\\Request\\buyer.txt","a+");
if(fl==NULL)
	{
	printf("");
	return;
	}
fprintf(fl,"%s\n%s\n%s\n%u\n%s\n%f\n%s\n\n",p->FIO,p->contact,p->favModel,p->fageCreate,p->fcondition,p->fprise,a->model);
fclose(fl);

char aaa[] = "e:\\sem#2\\C\\lb7\\Request\\";
fl = fopen(strncat(strncat(aaa,a->model,30),".txt",6),"w");
fprintf(fl,"%s\n%u\n%u\n%f\n%u\n%s\n%s\n%s\n%f\n",a->model,a->ageCreate,a->mileAge,a->engineSize,a->power,a->transmission,a->gearBox,a->condision, profit(a));
fclose(fl);
}
#endif
