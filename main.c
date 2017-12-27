//=====================================================
// Arquivo: main.c
//
// Autores: Ana Paula Fernandes de Souza
//          Renata Caroline Cunha
// Data: 31/07/2016
// Disciplina: Programacao II - AED
//=====================================================

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "ordenacao.h"

struct dados{
            unsigned long int compara[3];
            unsigned long int troca[3];
            double tempo[3];    
};

typedef struct dados * inf;

void salvaResultado(inf p,char *nome)
{
    FILE *arq;    
    
    char resultado[]="resultados.txt";
    arq=fopen(resultado,"a");
    
    if(arq==NULL)
    {
        return;
    }
    
    fprintf(arq,"\n%s\n\n",nome);
    
    int i; 
    for(i=0;i<3;i++)
    {
        if(i==0)
        {
            fprintf(arq,"compara=c(%lu,",p->compara[i]);              
        }       
        if(i==1)
        {
            fprintf(arq,"%lu,",p->compara[i]);
        }    
        if(i==2)
        {
            fprintf(arq,"%lu); \n",p->compara[i]);
            fprintf(arq,"mean(compara); \n");
            fprintf(arq,"sd(compara); \n\n");           
        }                
    }

    for(i=0;i<3;i++)
    {
        if(i==0)
        {
            fprintf(arq,"troca=c(%lu,",p->troca[i]);      
        }
        if(i==1)
        {
            fprintf(arq,"%lu,",p->troca[i]);
        }    
        if(i==2)
        {
            fprintf(arq,"%lu); \n",p->troca[i]);
            fprintf(arq,"mean(troca); \n");
            fprintf(arq,"sd(troca); \n\n");        
        }                
    }  
    
    for(i=0;i<3;i++)
    {
        if(i==0)
        {
            fprintf(arq,"tempo=c(%lf,",p->tempo[i]);      
        }
        if(i==1)
        {
            fprintf(arq,"%lf,",p->tempo[i]);
        }    
        if(i==2)
        {
            fprintf(arq,"%lf); \n",p->tempo[i]);
            fprintf(arq,"mean(tempo); \n");
            fprintf(arq,"sd(tempo); \n\n");       
        }                
    }  
    
  fclose(arq);

  return;
}

int main(void) 
{   
    struct dados *aux=(struct dados*)malloc(sizeof(struct dados));
        
    double inicio,fim;     
    int qtd[5]={500,1000,10000,100000,300000};
    
    int i,j;
    for(i=0;i<5;i++)
    { 
        Ordena Vetor1=OPcriaVetor(qtd[i]);
        OPgeraValores(Vetor1);
                       
        Ordena Vetor2=OPcriaVetor(qtd[i]);
        OPgeraValores(Vetor2);
        
        Ordena Vetor3=OPcriaVetor(qtd[i]);
        OPgeraValores(Vetor3);
               
        Ordena copia;
        
//=================Metodo Bolha=================//            
        for(j=0;j<3;j++)
        {            
           switch (j)
           {
                case 0:
                       copia=OPcopiaVetor(Vetor1);
                   
                       inicio=(double)clock()/CLOCKS_PER_SEC;

                       OPmetodoBolha(copia);

                       fim=(double)clock()/CLOCKS_PER_SEC;
                       
                       aux->compara[j]=OPretornaComparacoes(copia);
                       aux->troca[j]=OPretornaTroca(copia);
                       aux->tempo[j]=(fim-inicio);
                       
                       OPdestroiVetor(copia);
                       copia=NULL;                   
                break;
            
                case 1:
                       copia=OPcopiaVetor(Vetor2);
                   
                       inicio=(double)clock()/CLOCKS_PER_SEC;

                       OPmetodoBolha(copia);

                       fim=(double)clock()/CLOCKS_PER_SEC;
                       
                       aux->compara[j]=OPretornaComparacoes(copia);
                       aux->troca[j]=OPretornaTroca(copia);
                       aux->tempo[j]=fim-inicio;
                       
                       OPdestroiVetor(copia);
                       copia=NULL;            
                break;

                case 2:
                       copia=OPcopiaVetor(Vetor3);
                   
                       inicio=(double)clock()/CLOCKS_PER_SEC;

                       OPmetodoBolha(copia);

                       fim=(double)clock()/CLOCKS_PER_SEC;
                       
                       aux->compara[j]=OPretornaComparacoes(copia);
                       aux->troca[j]=OPretornaTroca(copia);
                       aux->tempo[j]=(fim-inicio);
                       
                       OPdestroiVetor(copia);
                       copia=NULL;              
                break;                            
           }   
        }
       
         char nome1[1000]="Metodo Bolha - Quantidade: ";
         char convert1[10];
         
         sprintf(convert1, "%d",qtd[i]);         
         strcat(nome1,convert1);    
         
         salvaResultado(aux,nome1);      

//=================Metodo Inserção=================//       
        for(j=0;j<3;j++)
        {            
           switch (j)
           {
                case 0:
                       copia=OPcopiaVetor(Vetor1);
                   
                       inicio=(double)clock()/CLOCKS_PER_SEC;

                       OPmetodoInsercao(copia,0,(qtd[i]-1));

                       fim=(double)clock()/CLOCKS_PER_SEC;
                       
                       aux->compara[j]=OPretornaComparacoes(copia);
                       aux->troca[j]=OPretornaTroca(copia);
                       aux->tempo[j]=(fim-inicio);                       

                       OPdestroiVetor(copia);                       
                break;
            
                case 1:
                       copia=OPcopiaVetor(Vetor2);
                   
                       inicio=(double)clock()/CLOCKS_PER_SEC;

                       OPmetodoInsercao(copia,0,qtd[i]-1);

                       fim=(double)clock()/CLOCKS_PER_SEC;
                       
                       aux->compara[j]=OPretornaComparacoes(copia);
                       aux->troca[j]=OPretornaTroca(copia);
                       aux->tempo[j]=(fim-inicio);
                       
                       OPdestroiVetor(copia);                       
                break;

                case 2:
                       copia=OPcopiaVetor(Vetor3);
                   
                       inicio=(double)clock()/CLOCKS_PER_SEC;

                       OPmetodoInsercao(copia,0,qtd[i]-1);

                       fim=(double)clock()/CLOCKS_PER_SEC;
                       
                       aux->compara[j]=OPretornaComparacoes(copia);
                       aux->troca[j]=OPretornaTroca(copia);
                       aux->tempo[j]=(fim-inicio);
                       
                       OPdestroiVetor(copia);                       
                break;                            
           }   
        }
         
         char nome2[1000]="Inserção - Quantidade: ";
         char convert2[10];
         
         sprintf(convert2, "%d",qtd[i]);         
         strcat(nome2,convert2);    
         
         salvaResultado(aux,nome2);      

//=================Metodo QuickSort=================//
        for(j=0;j<3;j++)
        {            
           switch (j)
           {
                case 0:
                       copia=OPcopiaVetor(Vetor1);
                   
                       inicio=(double)clock()/CLOCKS_PER_SEC;

                       OPmetodoQuickSort(copia,0,qtd[i]-1);

                       fim=(double)clock()/CLOCKS_PER_SEC;
                       
                       aux->compara[j]=OPretornaComparacoes(copia);
                       aux->troca[j]=OPretornaTroca(copia);
                       aux->tempo[j]=(fim-inicio);
                       
                       OPdestroiVetor(copia);                       
                break;
            
                case 1:
                       copia=OPcopiaVetor(Vetor2);
                   
                       inicio=(double)clock()/CLOCKS_PER_SEC;

                       OPmetodoQuickSort(copia,0,qtd[i]-1);

                       fim=(double)clock()/CLOCKS_PER_SEC;
                       
                       aux->compara[j]=OPretornaComparacoes(copia);
                       aux->troca[j]=OPretornaTroca(copia);
                       aux->tempo[j]=(fim-inicio);
                       
                       OPdestroiVetor(copia);                       
                break;

                case 2:
                       copia=OPcopiaVetor(Vetor3);
                   
                       inicio=(double)clock()/CLOCKS_PER_SEC;

                       OPmetodoQuickSort(copia,0,qtd[i]-1);

                       fim=(double)clock()/CLOCKS_PER_SEC;
                       
                       aux->compara[j]=OPretornaComparacoes(copia);
                       aux->troca[j]=OPretornaTroca(copia);
                       aux->tempo[j]=(fim-inicio);
                       
                       OPdestroiVetor(copia);                       
                break;                            
           }   
        } 
         char nome3[1000]="Quick Sorte - Quantidade: ";
         char convert3[10];
         
         sprintf(convert3, "%d",qtd[i]);         
         strcat(nome3,convert3);    
         
         salvaResultado(aux,nome3);      
         
//=================Metodo QuickSorte Turbinado=================//
        for(j=0;j<3;j++)
        {            
           switch (j)
           {
                case 0:
                       copia=OPcopiaVetor(Vetor1);
                   
                       inicio=(double)clock()/CLOCKS_PER_SEC;

                       OPmetodoQuickTurbinado(copia,0,qtd[i]-1);

                       fim=(double)clock()/CLOCKS_PER_SEC;
                       
                       aux->compara[j]=OPretornaComparacoes(copia);
                       aux->troca[j]=OPretornaTroca(copia);
                       aux->tempo[j]=(fim-inicio);
                       
                       OPdestroiVetor(copia);                       
                break;
            
                case 1:
                       copia=OPcopiaVetor(Vetor2);
                   
                       inicio=(double)clock()/CLOCKS_PER_SEC;

                       OPmetodoQuickTurbinado(copia,0,qtd[i]-1);

                       fim=(double)clock()/CLOCKS_PER_SEC;
                       
                       aux->compara[j]=OPretornaComparacoes(copia);
                       aux->troca[j]=OPretornaTroca(copia);
                       aux->tempo[j]=(fim-inicio);
                       
                       OPdestroiVetor(copia);                       
                break;

                case 2:
                       copia=OPcopiaVetor(Vetor3);
                   
                       inicio=(double)clock()/CLOCKS_PER_SEC;

                       OPmetodoQuickTurbinado(copia,0,qtd[i]-1);

                       fim=(double)clock()/CLOCKS_PER_SEC;
                       
                       aux->compara[j]=OPretornaComparacoes(copia);
                       aux->troca[j]=OPretornaTroca(copia);
                       aux->tempo[j]=(fim-inicio);
                       
                       OPdestroiVetor(copia);                       
                break;                            
           }   
        }
         
         char nome4[1000]="Quick Sorte Turbinado - Quantidade: ";
         char convert4[10];
         
         sprintf(convert4,"%d",qtd[i]);         
         strcat(nome4,convert4);    
         
         salvaResultado(aux,nome4);       
    }
    
  free(aux);
  aux=NULL;
    
  return 0;   
}