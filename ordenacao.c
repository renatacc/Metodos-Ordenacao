//=====================================================
// Arquivo: ordenacao.c
//
// Autores: Ana Paula Fernandes de Souza
//          Renata Caroline Cunha
// Data: 31/07/2016
// Disciplina: Programacao II - AED
//=====================================================

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

struct dados{
            unsigned long int contCompara;
            unsigned long int contTroca;
            int qtd;
            int *vetor;
};

void OPgerarSemente(void);
int OPmedianaPivo(Ordena vet,int min,int max);
void debug(Ordena p,int inicio,int fim, int pivo);

Ordena OPcriaVetor(int qtd)
{
    Ordena aux=(struct dados*)malloc(sizeof(struct dados));
    aux->vetor=(int*)malloc(qtd*sizeof(int));
    
    aux->contCompara=0;
    aux->contTroca=0;
    aux->qtd=qtd;
    
    return(aux); 
}

void OPdestroiVetor(Ordena p)
{   
    free(p->vetor);
    p->vetor=NULL;
    free(p);
    p=NULL;
      
    return;
}

void OPgeraValores(Ordena p)
{
    OPgerarSemente();
    
    int i;   
    for(i=0;i<p->qtd;i++)
    {        
        p->vetor[i]=rand()%(p->qtd*2);            
    }    
}

Ordena OPcopiaVetor(Ordena p)
{
   Ordena aux=OPcriaVetor(p->qtd); 
    
   int i;   
   for(i=0;i<p->qtd;i++)
   {       
     aux->vetor[i]=p->vetor[i];         
   }
   
   return(aux);  
}

void OPtrocaValores(Ordena p,int pos1,int pos2)
{
   int aux; 
    
   aux=p->vetor[pos1];
   p->vetor[pos1]=p->vetor[pos2];
   p->vetor[pos2]=aux; 
   p->contTroca++; 
   
   return; 
}

//Se pos1>pos2 retorna 1;
int OPcomparaValores(Ordena p,int pos1,int pos2)
{
  int valorRetorno=0;
  
  if((p->vetor[pos1]>(p->vetor[pos2])))
  {
      valorRetorno=1;    
  } 
  p->contCompara++;
  
  return(valorRetorno);  
}
//Ordenada os valores de forma crescente.
void OPmetodoBolha(Ordena p)
{
   int i,j;   
   for(i=0;i<p->qtd;i++)
   {
       for(j=i+1;j<p->qtd;j++)
       {
           if(OPcomparaValores(p,i,j))
           {
               OPtrocaValores(p,i,j);               
           }                    
       }     
   }   
 
   return;
}

void OPmetodoInsercao(Ordena p,int min,int max)
{        
   int i,auxPos1,auxPos2;
   for(i=min+1;i<max;i++)
   {     
        auxPos1=i-1;
        auxPos2=i;     
        while(auxPos1>=min && OPcomparaValores(p,auxPos1,auxPos2)==1)
        {       
          OPtrocaValores(p,auxPos1,auxPos2);           
                  
          auxPos1--;
          auxPos2--;          
        }      
    }
 }  

int OPmedianaPivo(Ordena vet,int min,int max)
{    
   Ordena p=OPcriaVetor(3);     
    
   int p1=rand()%(max-min)+min;
   int p2=rand()%(max-min)+min;
   int p3=rand()%(max-min)+min;
   
   p->vetor[0]=vet->vetor[p1];
   p->vetor[1]=vet->vetor[p2];
   p->vetor[2]=vet->vetor[p3];
   
   OPmetodoBolha(p);
   
   int retorno;
   
   if(p->vetor[1]==vet->vetor[p1])
   {     
     retorno=p1;       
   }
      if(p->vetor[1]==vet->vetor[p2])
   {  
      retorno=p2;       
   }
   if(p->vetor[1]==vet->vetor[p3])
   {       
      retorno=p3;        
   }
   OPdestroiVetor(p);
   
   return(retorno);    
}

void OPmetodoQuickSort(Ordena p,int min,int max)
{    
   if(max==min)
   {
      return;     
   }

   if(max-min==1)
   {
       if(OPcomparaValores(p,min,max))
       {
           OPtrocaValores(p,min,max);         
       }
       return;  
   }
   
     int pivo=OPmedianaPivo(p,min,max);   
     int i=min,j=min;
     
     OPtrocaValores(p,pivo,max);
     
     while(OPcomparaValores(p,max,i)==1 && i<(max-1))
     {
         i++;           
     }
     
     j=i+1;
      
     if(i<max)
     {
          while(j<max)
          {
              if(OPcomparaValores(p,max,j))
              {
                   OPtrocaValores(p,i,j);
                   i++;
              }
              j++;       
          }
          if(OPcomparaValores(p,i,max))
          {
              OPtrocaValores(p,i,max); //trocar o sentinela para dividir o vetor em números menores e maiores.
          }
     }
            
   if(min<=i)
   {
      OPmetodoQuickSort(p,min,i);
   }
   if(i+1<=max)
   { 
      OPmetodoQuickSort(p,i+1,max);  
   } 
}

void OPmetodoQuickTurbinado(Ordena p,int min,int max)
{

   if(max-min<40)
   {
    	OPmetodoInsercao(p,min,max);
   }
 
   int pivo=OPmedianaPivo(p,min,max);   
   int i=min,j=min;
   
   OPtrocaValores(p,pivo,max);
   
   while(OPcomparaValores(p,max,i)==1 && i<(max-1))
   {
       i++;           
   }
   
   j=i+1;
    
   if(i<max)
   {
        while(j<max)
        {
            if(OPcomparaValores(p,max,j))
            {
                 OPtrocaValores(p,i,j);
                 i++;
            }
            j++;       
        }
        if(OPcomparaValores(p,i,max))
        {
            OPtrocaValores(p,i,max);
        }
   }
          
  if(min<=i)
  {
      OPmetodoQuickSort(p,min,i);
  }
   if(i+1<=max)
   { 
      OPmetodoQuickSort(p,i+1,max);  
   }

}

unsigned long int OPretornaComparacoes(Ordena p)
{
   return(p->contCompara);     
}

unsigned long int OPretornaTroca(Ordena p)
{
   return(p->contTroca);    
}

void OPgerarSemente(void)
{
   static int x=0;
   
   if(x==0)
   {
      srand(time(NULL));  
      x=1; 
   }   

   return; 
}

void debug(Ordena p,int inicio,int fim, int pivo)
{
  printf("\n");
  
  int i;  
  for(i=0;i<p->qtd;i++)
  {
      if(i==inicio)
      {
         printf("[");           
      }
            
      if(pivo==i)
      {    
        printf("(%d) \t ",p->vetor[i]);          
      }
      else
      {          
        printf("%d \t ",p->vetor[i]);  
      } 
      
      if(i==fim)
      {
         printf("]");           
      }     
  }    
  
  printf("\n");  

  return;   
}

void OPsalvaResultado(Ordena p,char *nome,double tempo)
{
    FILE *arq;    
    arq=fopen(nome,"w");
    
    if(arq==NULL)
    {
        return;
    }

    fprintf(arq,"Tempo : %lf \n",tempo);    
    fprintf(arq,"Numero de comparacoes : %lu \n",p->contCompara);
    fprintf(arq,"Numero de trocas %lu \n",p->contTroca);   

    fclose(arq);

    return;
}