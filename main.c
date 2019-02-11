#include <stdio.h>
#include <stdlib.h>


//Return colour White, Black , Grey
char whatsColour(char * colour_ar,int k){
    return *(colour_ar+k);
}
//Change colour in colour_array
void change_colour(char * colour_ar,int k,char colour){
    *(colour_ar+k)=colour;
}

//Сичтаем как двумерный массив с индексами от 0 до N, индекс позиции измеряется с 0 до N*N
//Recursive passage throught ribs_array
int rec_found(int * ar,int * colour_ar,int index,int const N,int count){
    int line=index/N;
    int column=0;

    if(whatsColour(colour_ar,line)=='W'){
        change_colour(colour_ar,line,'G');
        for(column = 0 ;column<N;column++){
            if(*(ar+line*N+column)==1){
                rec_found(ar,colour_ar,column*N,N,0);
            }
            if(column==N-1){
                change_colour(colour_ar,line,'B');
                printf("%d ",line+1);
                return 0;
            }
        }
    }
    if(whatsColour(colour_ar,line)=='G'){
//Should exit form program(TODO)
        printf("Incorrect values");
        return -1;
    }
    if(whatsColour(colour_ar,line)=='B'){
       // return 0;
    }
}

//Zeroing array
void zeroing_array(int *ar,int N){
    for(int i=0;i<N;i++){
        for(int j = 0 ;j<N;j++){
            *(ar+i*N+j)=0;
        }
    }
}


int main(){

//Scanning values of vertexis
    int N=getchar()-48;
    getchar();
    if(N < 0 || N > 10000){
        printf("bad number of vertices");
        return 0;
    }

    char * colour_ar=(char*)malloc(sizeof(char)*N);
    for(int i = 0;i<N;i++){
        *(colour_ar + i)='W';
    }


//Scanning values of ribs
    int M = getchar()-48;
    getchar();
    if(M < 0 || M > (N*(N-1)/2)){
        printf("bad number of edges");
        return 0;
    }

//Malloc memory and zeroing array
    int * ar = (int*)malloc(sizeof(int)*N*N);
    zeroing_array(ar,N);

//Add graph_ribs with adjecency matrix
    int c1,c2;
    int count=0;
      while((c1=getchar())!='d'){
        c1=c1-48;
        getchar();
        c2=getchar()-48;
        *(ar+(c1-1)*N+(c2-1))=1;
        count++;
        getchar();
    }

    if(count > M+2 ){
        printf("bad number of lines");
        return 0;
    }

    int index = 0;
    for(int line=0;line<N;line++){
        index = line*N+0;
        rec_found(ar, colour_ar, index, N, 0);
    }


    free(ar);
    free(colour_ar);
    return 0;
}