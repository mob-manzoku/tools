#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILES 2
#define PATTERN  50
#define URL    "http://hogehoge"     // no slash
#define NAME   "sitemap-20140326-"

int main (void){

  FILE *fp;
  int i;
  int j;
  char filename[100] = "test";
  char num[10];
  char suffix[10] = ".xml";
  int uid;

  for (i = 1;i <= FILES;i++){

    sprintf(num,"%03d",i);
    
    strcpy(filename,NAME);
    strcat(filename, num);
    strcat(filename,suffix);
		       
    fp = fopen(filename, "w");

    fprintf(fp,"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
    fprintf(fp,"<urlset xmlns=\"http://www.sitemaps.org/schemas/sitemap/0.9\">\n");

    for (j = 1;j <= PATTERN;j++){
      
      uid = (i-1)*PATTERN + j;

      fprintf(fp,"<url>\n");
      fprintf(fp,"<loc>%s/%d</loc>\n",URL,uid);
      fprintf(fp,"</url>\n");

    }
    fprintf(fp,"</urlset>\n");
    fclose(fp);
  }

  return 0;
}
