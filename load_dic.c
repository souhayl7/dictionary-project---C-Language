#include "load_dic.h"


dictionnaire * fill_dict(void )
  {

    dictionnaire * dictionnary ;
    dictionnary  = malloc(sizeof(*dictionnary)) ;
    if (dictionnary == NULL){
      fprintf(stderr ,"Erreur:Probleme Creation Dictionnaire.\n") ;
      exit(EXIT_FAILURE);
    }
    dictionnary->word = malloc(MAX*sizeof(mot)) ;

    if (dictionnary->word == NULL){
      fprintf(stderr ,"Erreur:Probleme Creation des mots.\n") ;
      exit(EXIT_FAILURE);
    }

    FILE *fichier =  fopen("dic.txt", "r");
   if (fichier == NULL ){
		fprintf(stderr, "Erreur : probleme d'ourverture de fichier.\n");
		exit(EXIT_FAILURE);
	}

  mot * temp = dictionnary->word ;
  for (int i=0 ; i <MAX ; i++)
    {
        fgets(temp->WORD,MAX_WORD,fichier);
        temp->longueur =strlen(temp->WORD)-1;
        temp->nombre=i+1;
        temp++;
    }

    fclose(fichier);
    return dictionnary ;
}



void etape_1statistiques(dictionnaire *dictionnary)
{
  mot *temp=dictionnary->word;
  int tab[25] = {0} ;
  int min=25;
  int max=0;
  double a=0;
  for(int i=0;i<MAX;i++)
  {
    if((temp->longueur)<min && (temp->longueur)>0)
      {min=temp->longueur;}
    if((temp->longueur)>max)
      { max=temp->longueur;}
    tab[temp->longueur-1]++;
    a+=temp->longueur;
    temp++;
  }
  a=a/MAX;
  printf ("(II) Taille minimum des mots : %d\n" , min) ;
  printf ("(II) Taille maximum des mots : %d\n" , max) ;
  printf("(II) Taille moyenne des mots : %f\n", a);
  for(int j=1;j<26;j++)
  {
    printf("(II) Taille %d \t %d \tmots\t (%f%%)\t", j, tab[j-1], tab[j-1]*100.0/MAX);
    int p = tab[j-1]*100.0/(MAX)*4 +1 ;
    for (int c =0 ; c<p ; c++) { printf("#");}
    printf ("\n");
  }

}
void etape_2statistiques(dictionnaire *dico)
{
  mot *temp=dico->word;
  int tab[27]={0};
  char alpha[26]="abcdefghijklmnopqrstuvwxyz";
  for(int i=0;i<MAX;i++)
  {
    int m=97;
    char a=m;
    for(int j=0;j<temp->longueur;j++)
    {
      int car=temp->WORD[j];
      switch (car)
    {

    case 97:
      tab[0]++;
      break;
    case 98:
      tab[1]++;
      break;
    case 99:
      tab[2]++;
      break;
    case 100:
      tab[3]++;
      break;
    case 101:
      tab[4]++;
      break;
    case 102:
      tab[5]++;
      break;
    case 103:
      tab[6]++;
      break;
    case 104:
      tab[7]++;
      break;
    case 105:
      tab[8]++;
      break;
    case 106:
      tab[9]++;
      break;
    case 107:
      tab[10]++;
      break;
    case 108:
      tab[11]++;
      break;
    case 109:
      tab[12]++;
      break;
    case 110:
      tab[13]++;
      break;
    case 111:
      tab[14]++;
      break;
    case 112:
      tab[15]++;
      break;
    case 113:
      tab[16]++;
      break;
    case 114:
      tab[17]++;
      break;
    case 115:
      tab[18]++;
      break;
    case 116:
      tab[19]++;
      break;
    case 117:
      tab[20]++;
      break;
    case 118:
      tab[21]++;
      break;
    case 119:
      tab[22]++;
      break;
    case 120:
      tab[23]++;
      break;
    case 121:
      tab[24]++;
      break;
    case 122:
      tab[25]++;
      break;
    }
    }
    temp++;
  }
  int somme;
  for(int n=0;n<26;n++)
  {
    somme=tab[n];
  }
  for(int n=0;n<26;n++)
  {
    char harf=n+97;
    double d=tab[n]*1.0/somme;
    printf("(II) Lettre (%c) : %d  \tlettres\t (%f%%)\n ", harf, tab[n], d);
  }
}
int palindrome(mot* wort)
{
  mot *temp1=wort;
  if (temp1->longueur==1)
    return 1;
  for(int i=0;i<strlen(temp1->WORD)/2;i++)
  {
    if(temp1->WORD[i]!=temp1->WORD[temp1->longueur-1-i])
      return 0;
  }
  return 1;
}

void etape_3statistiques(dictionnaire *dico)
{
  mot *temp=dico->word;
  int j=1;
  int k=1;
  for(int i=0;i<MAX;i++)
  {
    if(palindrome(temp)==1)
    {
      printf("le mot numero %d (%s) est %deme un palindrome \n",j,temp->WORD, k);
      k++;
    }
    temp++;
    j++;
  }
}
void conversion(char* t, int* tab)
{
  for(int i=0;i<strlen(t);i++)
  {
    tab[i]=t[i];
  }
}
void selection(int taille, int* tab)
{
  int i, mini, j, x;
  for(j=0;j<taille-1;j++)
  {
    for (i = j+1; i < taille; i++)
    {
      if(tab[i]<tab[j])
      {
        x=tab[j];
        tab[j]=tab[i];
        tab[i]=x;
      }
    }
  }
}

int same(int* a, int* b, int taille)
{
  for(int i=0;i<taille;i++)
  {
    if (a[i]!=b[i])
      {
        return 0;
      }
  }
  return 1;
}
void etape_4statistiques(dictionnaire *dico)
{
  mot *temp=dico->word;
  char anagram[MAX_WORD] ;
  printf("Saisir le mot de reference pour chercher des anagrammes \n") ;
  scanf("%s", anagram);
  int tab1[30]={0};
  int tab2[30]={0};
  int k =0;
  for(int i=0;i<MAX;i++)
  {
    if(temp->longueur==strlen(anagram))
    {
      conversion(temp->WORD, tab1);
      selection(temp->longueur, tab1);
      conversion(anagram, tab2);
      selection(strlen(anagram), tab2);
      if(same(tab1, tab2, strlen(anagram))==1)
      {
        k++;
        printf("le mot numero %d (%s) est %d eme un anagramme\n", temp->nombre, temp->WORD, k);
      }
    }
    temp++;
  }
}

void etape_5statistiques(dictionnaire *dico)
{
  int tab[MAX]={0};
  char ptrn[MAX_WORD];
  printf("Saisir le mot de reference pour trouver un pattern \n") ;
  scanf("%s", ptrn );
  int k=0;
  mot *temp=dico->word;
  mot *tmp=dico->word;
  for(int i=0;i<MAX;i++)
  {
    if(temp->longueur==strlen(ptrn))
    {
      while((temp->WORD[k]==ptrn[k]) || (ptrn[k]=='?'))
      {
        tab[temp->nombre]++;
        k++;
      }
    }
    k=0;
    temp++;
  }
  int l=0;
  for(int j=0;j<MAX;j++)
  {
    if(tab[tmp->nombre]==tmp->longueur)
    {

      l=l+1;
      printf("  le mot numero %d (%s) est %d eme répond au critère\n",tmp->nombre,tmp->WORD,l );
    }
    tmp++;
  }
  printf("on a trouvé %d mots", l);
}

void etape_6statistiques(dictionnaire * dico)
{

  mot * temp = dico->word ;
  char ptrn[MAX_WORD] ;
  printf("Saisir le mot de reference pour dechiffrer un pattern *\n") ;
  scanf("%s", ptrn );
  int l=0;
  for (int i=0 ; i<MAX ; i++)
  {
    int j=0;
    int w=1;
    while(w==1 && ptrn[j]!='*')
    {
      if(ptrn[j]!=temp->WORD[j])
        w=0;
      j++;
    }
    int k=strlen(ptrn)-1;
    int m=temp->longueur-1;
    while(w==1 && ptrn[k]!='*')
    {
      if(ptrn[k]!=temp->WORD[m])
        w=0;
      k--;
      m--;
    }
    if (w==1)
    {
      l++;
      printf ("Le mot numero %d (%s) est le %deme qui repond au critere\n", temp->nombre , temp->WORD , l);
    }
    temp++;
  }
  printf ("on a trouve %d mots\n" , l) ;
}
char* delete_char(char  str[], int r) {

  char * st ;
  st = malloc(sizeof(char)*(strlen(str)-1)) ;
  char* new;
  for(int j=0;j<r-1;j++)
  {
    new[j]=str[j];
  }
  for(int i=r;i<strlen(str)-1;i++)
  {
    new[i]=str[i+1];
  }
  strcpy(st,new);
  return st ;
}

void etape_7statistiques(dictionnaire * dico)
{
  int tab[MAX]={0};
  mot *temp=dico->word;
  char ref[MAX_WORD] ;
  printf("Saisir les lettres de reference SCRRABLE\n") ;
  scanf("%s", ref );
  char* ref1;
  int n;
  int l=0;
  for(int i=0;i<MAX;i++)
  {
    for(int m=0;m<temp->longueur;m++)
    {
      for(int j=0;j<strlen(ref1)-n;j++)
      {
        if(temp->WORD[m]==ref1[j])
        {
          tab[temp->nombre]++;
          ref1=delete_char(ref1,j);
          n++;
        }
      }
    }
    if(tab[temp->nombre]==temp->longueur)
    {
      printf("ok \n");
      l=l+1;
      printf("Le mot numero %d (%s) est le %deme qui repond au critere\n",temp->nombre,temp->WORD,l );
    }
    temp++;
    strcpy(ref1,ref);
    n=0;
  }
  printf("on a trouvé %d mots", l);
}

void etape_9statistiques(dictionnaire *dico)
{
  mot *temp=dico->word;
  char corri[MAX_WORD] ;
  printf("Saisir les lettres de reference\n") ;
  scanf("%s", corri);
  char * text ;
  int l=0;
  for(int i=0;i<MAX;i++)
  {
    if(strlen(corri)==temp->longueur)
    {
      int r=0;
      int j=0;
      while(j<strlen(corri) && r<2)
      {
        if(corri[j]!=temp->WORD[j])
        {
          r++;
        }
        j++;
      }
      if(r==1)
      {
        l++;
        printf("Le mot numero %d (%s) est le %deme repond au critere", temp->nombre, temp->WORD, l );
      }
    }
    temp++;
  }
  printf("on a trouve %d mots\n", l);
}

int main(void)
{

  dictionnaire * dic = fill_dict() ;
  //etape_1statistiques(dic);
  //smiya(dic);
  //etape_2statistiques(dic);
  //etape_3statistiques(dic);
  //etape_4statistiques(dic);
  //etape_5statistiques(dic);
  //etape_6statistiques(dic);
  //etape_7statistiques(dic);
  etape_9statistiques(dic);

  return 0;
}
