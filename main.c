#include <stdio.h>
#include <stdlib.h>


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
/*
void fnCadastraCurso(){

}

void fnCadastraTurma(){

}

void fnCadastraDisciplina(){

}

void fnCadastraAluno(){

}

void fnListaAluno(int matricula){

}

void fnListaCurso(){

}

void fnListaTurma(int codCurso){

}

void fnListaDisciplina(int codTurma){

}*/

void main(){
	/*//Declaração de variaveis dinamicas com malloc()
    disciplina *disciplinas = (disciplina *) malloc(sizeof(disciplina));
	aluno *alunos = (aluno *) malloc(sizeof(aluno));
	turma *turmas = (turma *) malloc(sizeof(turma));
	curso *cursos = (curso *) malloc(sizeof(curso));*/

	/*struct rec *ptr_one;*/
    /*ptr_one =(struct rec *) malloc (sizeof(struct rec));*/
    aluno *alunos = (aluno *) malloc(sizeof(aluno));

    alunos->nome[0] = 'D';
    alunos->nome[1] = 'o';
    alunos->nome[2] = 'u';
    alunos->nome[3] = 'g';
    alunos->nome[4] = 'l';
    alunos->nome[5] = 'a';
    alunos->nome[5] = 's';
    alunos->matricula = 35514;
    alunos->codDisciplina = 10;

    printf("First value: %c\n", alunos->nome);
    memcpy(string, array, 5);
    string[x] = '\0'; 
    printf("Matricula: %d\n", alunos->matricula);
    printf("Codigo Disciplina: %d\n", alunos->codDisciplina);

    free(alunos);

	/*//Menu do sistema*/
	int controle = 9999,entrada,controle1 = 9999,entrada1;
	while(controle != 0){
    	printf("Selecione uma opcao do menu:\n");
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
                        	/*fnCadastraCurso();*/
                        	break;
                    	case 2:
                        	/*fnListaCurso();*/
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
                        	/*fnCadastraTurma();*/
                        	break;
                    	case 2:
                        	/*fnListaTurma(0);*/
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
