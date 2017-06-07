#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Tamanho 100
struct Alunos{
	char nome[30];
	int matricula;
	int codDisciplina;
};
typedef struct Alunos aluno;

struct Disciplina{
	char nome[30];
	int codDisciplina;
	int codTurma;
};
typedef struct Disciplina disciplina;

struct Curso{
	char nome[30];
	int codCurso;
};
typedef struct Curso curso;

struct Turma{
	char nome[30];
	int codTurma;
	int codCurso;
};
typedef struct Turma turma;

int fnCadastraCurso(curso *cursos, int intContador){
    intContador++;
    printf("Digite o nome do curso: \n");
    scanf("%s",cursos[intContador].nome);
    printf("Digite o codigo do curso: \n");
    scanf("%d", &cursos[intContador].codCurso);

    return intContador;
}

void fnListaCurso(curso *cursos,int intContador){
    printf(" ______________________________________________\n");
    printf("|Codigo               | Curso                  |\n");
    printf(" ______________________________________________\n");
    for(int i = 1; i <= intContador ;i++){
            printf("|%s               | %d                  |\n",cursos[i].nome,cursos[i].codCurso);
    }
    printf(" ______________________________________________\n");
}

int fnCadastraTurma(turma *turmas,int intContador){
    intContador++;
    printf("Digite o nome da turma: \n");
    scanf("%s",turmas[intContador].nome);
    printf("Digite o codigo da turma: \n");
    scanf("%d", &turmas[intContador].codTurma);
    printf("Digite o codigo do curso que a turma pertence: \n");
    scanf("%d", &turmas[intContador].codCurso);

    return intContador;
}
const char* fnSearchCurso(int codCurso,curso *cursos){
    for(int i = 1; i <= Tamanho ;i++){
            if(cursos[i].codCurso == codCurso){
                return cursos[i].nome;
            }
    }
    return "Nao foi possivel encontrar o Curso";
}

void fnListaTurma(int codCurso,turma *turmas,int intContador,curso *cursos){

    printf("Curso : %s\n",fnSearchCurso(codCurso,cursos));
    printf(" ______________________________________________\n");
    printf("|Codigo               | Turma                  |\n");
    printf(" ______________________________________________\n");
    for(int i = 1; i <= intContador ;i++){
            printf("|%d               | %s                  |\n",turmas[i].codTurma, turmas[i].nome);
    }
    printf(" ______________________________________________\n");
}
/*
void fnCadastraDisciplina(){
}

}#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Alunos{
	char nome[30];
	int matricula;
	int codDisciplina;
};
typedef struct Alunos aluno;

struct Disciplina{
	char nome[30];
	int codDisciplina;
	int codTurma;
};
typedef struct Disciplina disciplina;

struct Curso{
	char nome[30];
	int codCurso;
};
typedef struct Curso curso;

struct Turma{
	char nome[30];
	int codTurma;
	int codCurso;
};
typedef struct Turma turma;

int fnCadastraCurso(curso *cursos){
    printf("Digite o nome do curso: \n");
    scanf("%s",cursos[0].nome);int fnCadastraCurso(curso *cursos, int intContador){
    intContador++;
    printf("Digite o nome do curso: \n");
    scanf("%s",cursos[intContador].nome);
    printf("Digite o codigo do curso: \n");
    scanf("%d", &cursos[intContador].codCurso);

    return intContador;
}
    printf("Digite o codigo do curso: \n");
    scanf("%d", &cursos[0].codCurso);

    return 1;
}

void fnCadastraDisciplina(){

}

void fnCadastraAluno(){

}

void fnListaAluno(int matricula){

}

void fnListaDisciplina(int codTurma){

}*/

void main(){
	/*Declaração de variaveis dinamicas com malloc()*/
    disciplina *disciplinas = (disciplina *) malloc(sizeof(disciplina)* Tamanho);
	aluno *alunos = (aluno *) malloc(sizeof(aluno)*Tamanho);
	turma *turmas = (turma *) malloc(sizeof(turma)*Tamanho);
	curso *cursos = (curso *) malloc(sizeof(curso)*Tamanho);

	/** Accountants struct */
    int intContCurso = 0,intContTurma = 0, intCodCurso = 0;

	/** Menu system */
	int controle = 9999,entrada,controle1 = 9999,entrada1;
	while(controle != 0){
    	printf("Selecione uma mingw32-gcc.exeopcao do menu:\n");
    	printf("1 - Curso\n2 - Turma\n3 - Disciplina\n4 - Aluno\n0 - Exit\n");
    	controle1 = 9999;
    	scanf("%d", &entrada);

    	switch(entrada){
        	case 1:
            	while(controle1 != 0){
                	printf("Selecione uma opcao do menu Cursos:\n");
                	printf("1 - Cadastrar\n2 - Listar\n0 - Back\n");
                	scanf("%i", &entrada1);
                	switch(entrada1){
                    	case 1:
                    	    intContCurso = fnCadastraCurso(cursos,intContCurso);
                        	if(intContCurso > -1){
                                printf("Salvo!");
                        	}else{
                        	    printf("Erro!");
                        	}
                        	break;
                    	case 2:
                        	fnListaCurso(cursos,intContCurso);
                        	break;
                    	case 0:
                        	controle1 = 0;
                        	break;
                    	default:
                        	printf("Opcao invalida, por favor digite uma opcao valida!!!\n");
                        	break;
                	}
            	}
            	break;
        	case 2:
             	while(controle1 != 0){
                	printf("Selecione uma opcao do menu Turma:\n");
                	printf("1 - Cadastrar\n2 - Listar\n0 - Back\n");
                	scanf("%d", &entrada1);
                	switch(entrada1){
                    	case 1:
                        	intContTurma = fnCadastraTurma(turmas,intContTurma);
                        	if(intContTurma > -1){
                                printf("Salvo!");
                        	}else{
                        	    printf("Erro!");
                        	}
                        	break;
                    	case 2:
                    	    printf("Digite o codigo do curso, das turma que deseja listar:\n");
                            scanf("%d", &intCodCurso);
                        	fnListaTurma(intCodCurso,turmas,intContTurma,cursos);
                        	break;
                    	case 0:
                        	controle1 = 0;
                        	break;
                    	default:
                        	printf("Opcao invalida, por favor digite uma opcao valida!!!\n");
                        	break;
                	}
            	}
            	break;
        	case 3:
             	while(controle1 != 0){
                	printf("Selecione uma opcao do menu Disciplina:\n");
                	printf("1 - Cadastrar\n2 - Listar\n0 - Back\n");
                	scanf("%d", &entrada1);
                	switch(entrada1){
                    	case 1:
                        	/*fnCadastraDisciplina();*/
                        	break;
                    	case 2:
                        	/*fnListaDisciplina(0);*/
                        	break;
                    	case 0:
                        	controle1 = 0;
                        	break;
                    	default:
                        	printf("Opcao invalida, por favor digite uma opcao valida!!!\n");
                        	break;
                	}
            	}
            	break;
        	case 4:
              	while(controle1 != 0){
                	printf("Selecione uma opcao do menu Aluno:\n");
                	printf("1 - Cadastrar\n2 - Listar\n0 - Back\n");
                	scanf("%d", &entrada1);
                	switch(entrada1){
                    	case 1:
                       	/* fnCadastraAluno();*/
                        	break;
                    	case 2:
                        	/*fnListaAluno(0);*/
                        	break;
                    	case 0:
                        	controle1 = 0;
                        	break;
                    	default:
                        	printf("Opcao invalida, por favor digite uma opcao valida!!!\n");
                        	break;
                	}
            	}
            	break;
            	case 0:
                	printf("\n\n---- GOOD BYE ----\n\n");
                	controle = 0;
                	break;
            	default:
                	printf("Opcao invalida, por favor digite uma opcao valida!!!\n");
                	break;
    	}
	}

}
  /* CRIA ARQUIVO E SALVA

  FILE *fp;
   int c;
   fp = fopen("C:\\Users\\Aluno\\Desktop\\arquivoTex.txt","r");
   while(1)
   {
      c = fgetc(fp);
      if( feof(fp) )
      {
         break ;
      }
      printf("%c", c);
   }
   fclose(fp);
  FILE * fp;
  fp = fopen ("C:\\Users\\Aluno\\Desktop\\arquivoTex.txt", "w+");
  fprintf(fp, "%s %s %s %d", "We", "are", "in", 2012);
  fclose(fp);
  return(0);
*/
