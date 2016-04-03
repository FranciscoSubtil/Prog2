#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
	char nome[15];
	int vitorias;
} jogador;


/* problema 2 */
jogador* conta_vitorias(FILE* f, int *njogadores)
{
        jogador * jog = malloc(sizeof(jogador));
        char aux[15];
        int i, j;
        jogador tmp;
        
        *njogadores = 0;
	while(fscanf(f, "%s", aux) == 1)
        {
            aux[strlen(aux)] = '\0';
            puts(aux);
            int found = 0;
            for(i = 0; i < *njogadores; i++)
            {
                if(strcmp(aux, jog[i].nome) == 0)
                {
                    jog[i].vitorias++;
                    found = 1;
                    break;
                }
            }
            
            if(!found)
            {
                jog = realloc(jog, (*njogadores + 1)*sizeof(jogador));
                strcpy(jog[i].nome, aux);
                jog[i].vitorias = 1;
                *njogadores = *njogadores + 1;
            }
            
        }
        
        /* Ordenação */
        for (i = 1; i < *njogadores; i++)
        {
		tmp = jog[i];
		for (j = i; j > 0 && tmp.vitorias > jog[j-1].vitorias; j--)
		{
			jog[j] = jog[j-1];
		}
		jog[j] = tmp;
        }
        
        return jog;
}

/***************************************************/
/*** não alterar o ficheiro a partir deste ponto ***/
/***************************************************/

int main()
{
	FILE * f = fopen("log.txt", "r");
	jogador *j;
	int i, n=0;

	j = conta_vitorias(f, &n);
	
	fprintf(stderr, "Vencedores:\n");
	if(j != NULL)
	{
		for(i=0; i<n; i++)
			fprintf(stderr, "%s - %d\n", j[i].nome, j[i].vitorias);		
	}

	free(j);
	fclose(f);
	return 0;
}