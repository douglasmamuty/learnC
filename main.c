#include <stdio.h>
/*
struct Alunos{
	char nome[30];
	int matricula;
	int codDisciplina[3];
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
 
}
*/
void main(){
	//Declaração de variaveis dinamicas com malloc()
  /*  disciplina *disciplinas = (disciplina *) malloc(sizeof(disciplina));
	aluno *alunos = (aluno *) malloc(sizeof(aluno));
	turma *turmas = (turma *) malloc(sizeof(turma));
	curso *cursos = (curso *) malloc(sizeof(curso));*/
 
	//Menu do sistema
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
                        	//fnCadastraCurso();
                        	break;
                    	case 2:
                        	//fnListaCurso();
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
                        	//fnCadastraTurma();
                        	break;
                    	case 2:
                        	//fnListaTurma(0);
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
                        	//fnCadastraDisciplina();
                        	break;
                    	case 2:
                        	//fnListaDisciplina(0);
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
                       	// fnCadastraAluno();
                        	break;
                    	case 2:
                        	//fnListaAluno(0);
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