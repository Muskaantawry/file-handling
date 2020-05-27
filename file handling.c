#include<stdio.h>
int main()
{
	FILE *original;
	FILE *copy;
	int i, pos;
	char ch;
	char  x;
	original= fopen("original.txt","w");
	fprintf(original,"My Captain");
	fclose(original);
	
	original = fopen("original.txt","r");
	fseek(original, 0 , SEEK_END);
	pos=ftell(original);
	i=0;
	while(i<pos)
	{
		i++;
		fseek(original, -i , SEEK_END);
		ch= getc(original);
		printf("%c",ch);

	}
	fclose(original);
	
	original= fopen("original.txt","r");
	copy= fopen("copy.txt","w");
	x = getc(original);
	while(x!=EOF)
	{
		fputc(x,copy);
		x=getc(original);
	}
	fclose(original);
	fclose(copy);
	
}
