#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 8

void insertSort(char a[],int n){
	int i,j;
	char temp;
	for(i = 1;i < n;i++){
		if(a[i] < a[i - 1]){
			temp = a[i];
			for(j = i - 1;temp < a[j];j--)
				a[j + 1] = a[j];
			a[j + 1] = temp;
		}
	}
}
void dfs(char input[],char path[],int visited[],int n,int index){
	if(index == n){
		path[index] = '\0';
		printf("%s\n",path);
		return;
	}
	for(int i = 0;i < n;i++){
		if(visited[i] == 1)
			continue;
		visited[i] = 1;
		path[index] = input[i];
		dfs(input,path,visited,n,index+1);
		visited[i] = 0;
	}
}
int main(){
	char input[MAXSIZE];
	char path[MAXSIZE];
	int visited[MAXSIZE];
	int len;
	while(scanf("%s",input) != EOF){
		len = strlen(input);
		for(int i = 0;i < len;i++)
			visited[i] = 0;
		insertSort(input,len);
		printf("After sorted: %s \n",input);
		dfs(input,path,visited,len,0);
	}
	return 0;
}
