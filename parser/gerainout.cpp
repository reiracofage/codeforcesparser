#include <cstdio>
#include <cstring>

#define SIZE 10000001

using namespace std;

char s[SIZE];
char aux[1024];

int main() {

    int countin=0, countout=0;
    while (fgets(s,SIZE,stdin)) {
        for (int i=0;s[i];i++)
            if (!strncmp(s+i, "<div class=\"input\">", 19)) {
                sprintf(aux,"in%d",countin);
                FILE *in = fopen(aux,"w");
                //axa pre
                for (int j=i;s[j];j++) {
                    if (!strncmp(s+j,"<pre>",5)) {
                        for (int k=j+5;strncmp(s+k,"</pre>",6);k++)
                            if (!strncmp(s+k,"<br />", 6)) {
                                fprintf(in,"\n");
                                k += 5;
                            } else
                                fprintf(in,"%c",s[k]);
                        break;
                    }
                }
                fclose(in);
                countin++;
            } else if (!strncmp(s+i, "<div class=\"output\">", 20)) {
                sprintf(aux,"out%d", countout);
                FILE *out = fopen(aux, "w");
                //axa pre
                for (int j=i;s[j];j++) {
                    if (!strncmp(s+j,"<pre>",5)) {
                        for (int k=j+5;strncmp(s+k,"</pre>",6);k++)
                            if (!strncmp(s+k,"<br />", 6)) {
                                fprintf(out,"\n");
                                k += 5;
                            } else
                                fprintf(out,"%c",s[k]);
                        break;
                    }
                }
                fclose(out);
                countout++;
            }
    }

    return 0;
}
