#include <stdio.h>
#include <stdlib.h>

#define Tamanho 100

/** LOCATION WHERE THIS MAIN.C*/
static const char Path[] = "D:\\projeto\\learnC\\files\\";

struct Alunos{
    char nome[Tamanho];
    int matricula;
    int codDisciplina[Tamanho];
};

typedef struct Alunos aluno;

struct Disciplina{
    char nome[Tamanho];
    int codDisciplina;
    int codTurma;
};
typedef struct Disciplina disciplina;

struct Curso{
    char nome[Tamanho];
    int codCurso;
};
typedef struct Curso curso;

struct Turma{
    char nome[Tamanho];
    int codTurma;
    int codCurso;
};
typedef struct Turma turma;

/**FUNCTION CONVERT STRING ARRAY BY SEPARETE*/
void explode(const char *src, const char *tokens, char ***list, size_t *len){
    if(src == NULL || list == NULL || len == NULL)
        return;

    char *str, *copy, **_list = NULL, **tmp;
    *list = NULL;
    *len  = 0;

    copy = strdup(src);
    if(copy == NULL)
        return;

    str = strtok(copy, tokens);
    if(str == NULL)
        goto free_and_exit;

    _list = realloc(NULL, sizeof *_list);
    if(_list == NULL)
        goto free_and_exit;

    _list[*len] = strdup(str);
    if(_list[*len] == NULL)
        goto free_and_exit;
    (*len)++;


    while((str = strtok(NULL, tokens))){
        tmp = realloc(_list, (sizeof *_list) * (*len + 1));
        if(tmp == NULL)
            goto free_and_exit;

        _list = tmp;

        _list[*len] = strdup(str);
        if(_list[*len] == NULL)
            goto free_and_exit;
        (*len)++;
    }


free_and_exit:
    *list = _list;
    free(copy);
}

int fnCadastraCurso(curso *cursos, int intContador){
    intContador++;
    printf("Digite o nome do curso: \n");
    scanf("%s",cursos[intContador].nome);
    printf("Digite o codigo do curso: \n");
    scanf("%d", &cursos[intContador].codCurso);

    /**SAVE INTO FILES*/
    char str[1024];
    char strArquivo[Tamanho] = "curso.txt";
    char aux[Tamanho];
    sprintf(aux, "%d", cursos[intContador].codCurso);
    strcpy(str,aux);
    strcat(str,";");
    strcat(str,cursos[intContador].nome);
    if(fnWriteFile(strArquivo,str) == 0){
            return -1;
    }

    return intContador;
}

void fnListaCurso(curso *cursos,int intContador){
    int i = 1;
    printf("Lista de Cursos :\n");
    for(i; i <= intContador; i++){
            if(!cursos[i].codCurso == 0){
                printf("    %d - %s;\n",cursos[i].codCurso,cursos[i].nome);
            }
    }
}

int fnCadastraTurma(turma *turmas,int intContador){
    intContador++;
    printf("Digite o nome da turma: \n");
    scanf("%s",turmas[intContador].nome);
    printf("Digite o codigo da turma: \n");
    scanf("%d", &turmas[intContador].codTurma);
    printf("Digite o codigo do curso que a turma pertence: \n");
    scanf("%d", &turmas[intContador].codCurso);

     /**SAVE INTO FILES*/
    char str[1024];
    char strArquivo[Tamanho] = "turma.txt";
    char aux[Tamanho];

    sprintf(aux, "%d", turmas[intContador].codTurma);
    strcpy(str,aux);
    strcat(str,";");

    sprintf(aux, "%d", turmas[intContador].codCurso);
    strcat(str,aux);
    strcat(str,";");

    strcat(str,turmas[intContador].nome);

    if(fnWriteFile(strArquivo,str) == 0){
            return -1;
    }

    return intContador;
}

const char* fnSearchCurso(int codCurso,curso *cursos){
    int i = 1;
    for(i; i <= Tamanho ;i++){
            if(cursos[i].codCurso == codCurso){
                return cursos[i].nome;
            }
    }
    return "Nao foi possivel encontrar o Curso!";
}

void fnListaTurma(int codCurso,turma *turmas,int intContador,curso *cursos){

    printf("Curso : %s\n",fnSearchCurso(codCurso,cursos));
    printf("Lista de Turmas :\n");
    int i = 1;
    for(i; i <= intContador ;i++){
            if(turmas[i].codCurso == codCurso){
                    printf("    %d - %s;\n",turmas[i].codTurma, turmas[i].nome);
            }
    }
}

int fnCadastraDisciplina(disciplina *disciplinas, int intContador){
    intContador++;
    printf("Digite o nome da disciplina: \n");
    scanf("%s",disciplinas[intContador].nome);
    printf("Digite o codigo da disciplina: \n");
    scanf("%d", &disciplinas[intContador].codDisciplina);
    printf("Digite o codigo do turma que a disciplina pertence: \n");
    scanf("%d", &disciplinas[intContador].codTurma);

    /**SAVE INTO FILES*/
    char str[1024];
    char strArquivo[Tamanho] = "disciplina.txt";
    char aux[Tamanho];

    sprintf(aux, "%d", disciplinas[intContador].codDisciplina);
    strcpy(str,aux);
    strcat(str,";");

    sprintf(aux, "%d", disciplinas[intContador].codTurma);
    strcat(str,aux);
    strcat(str,";");

    strcat(str,disciplinas[intContador].nome);

    if(fnWriteFile(strArquivo,str) == 0){
            return -1;
    }

    return intContador;
}

const char* fnSearchTurma(int codTurma,turma *turmas){
    int i = 1;
    for(i; i <= Tamanho ;i++){
            if(turmas[i].codTurma == codTurma){
                return turmas[i].nome;
            }
    }
    return "Nao foi possivel encontrar uma Turma!";
}


void fnListaDisciplina(int codTurma,disciplina *disciplinas,int intContador,turma *turmas){
    printf("Turma : %s\n",fnSearchTurma(codTurma,turmas));
    printf("Lista de Disciplinas :\n");
    int i = 1;
    for(i; i <= intContador ;i++){
            if(disciplinas[i].codTurma == codTurma){
                    printf("    %d - %s;\n",disciplinas[i].codDisciplina, disciplinas[i].nome);
            }

    }
}

int fnCadastraDisciplinaAluno(aluno *alunos,int codAluno,int intContador){
    printf("Digite o codigo da disciplina que o aluno pertence: \n");
    scanf("%d", &alunos[codAluno].codDisciplina[intContador]);
    int intCodDisciplina = alunos[codAluno].codDisciplina[intContador];
    intContador++;

    /**SAVE INTO FILES*/
    char str[1024];
    char strArquivo[Tamanho] = "disciplinaAluno.txt";
    char aux[Tamanho];

    sprintf(aux, "%d", codAluno);
    strcpy(str,aux);
    strcat(str,";");

    sprintf(aux, "%d", intCodDisciplina);
    strcat(str,aux);

    if(fnWriteFile(strArquivo,str) == 0){
            return -1;
    }

    return intContador;
}

int fnCadastraAluno(aluno *alunos, int intContador){
    printf("Digite o nome do aluno: \n");
    scanf("%s",alunos[intContador].nome);
    printf("Digite a matricula do aluno: \n");
    scanf("%d", &alunos[intContador].matricula);
    int controle = 9999,entrada;
    int intContDisciplina = 1;

    /**SAVE INTO FILES*/
    char str[1024];
    char strArquivo[Tamanho] = "aluno.txt";
    char aux[Tamanho];

    sprintf(aux, "%d", alunos[intContador].matricula);
    strcpy(str,aux);
    strcat(str,";");

    strcat(str,alunos[intContador].nome);

    if(fnWriteFile(strArquivo,str) == 0){
            return -1;
    }

    while(controle != 0){
        printf("1 - Cadastrar nova disciplina\n0 - Voltar cadastro de aluno\n");
        scanf("%d", &entrada);
        switch(entrada){
            case 1:
                   intContDisciplina = fnCadastraDisciplinaAluno(alunos, intContador,intContDisciplina);
                break;
            case 0:
                controle = 0;
                break;
            default:
                printf("Opcao invalida, por favor digite uma opcao valida!!!\n");
                break;
        }

    }
    intContador++;
    return intContador;
}

int fnSearchAluno(int matricula,aluno *alunos){
    int i = 1;
    for(i; i <= Tamanho ;i++){
            if(alunos[i].matricula == matricula){
                return i;
            }
    }
    return -1;
}

const char* fnSearchDisciplina(int codDisciplina,disciplina *disciplinas){
    int i = 1;
    for(i; i <= Tamanho ;i++){
            if(disciplinas[i].codDisciplina == codDisciplina){
                return disciplinas[i].nome;
            }
    }
    return "Nao foi possivel encontrar uma Turma!";
}


int fnSearchTurmaByDisciplina(int codDisciplina,disciplina *disciplinas){
    int i = 1;
    for(i; i <= Tamanho ;i++){
            if(disciplinas[i].codDisciplina == codDisciplina){
                return disciplinas[i].codTurma;
            }
    }
    return -1;
}

int fnSearchCursoByTurma(int codTurma,turma *turmas){
    int i = 1;
    for(i; i <= Tamanho ;i++){
            if(turmas[i].codTurma == codTurma){
                return turmas[i].codCurso;
            }
    }
    return -1;
}

void fnListaAluno(int matricula,aluno *alunos,int intContador,disciplina *disciplinas,turma * turmas,curso * cursos){

    int codIndexAluno = fnSearchAluno(matricula,alunos);
    int codTurma = fnSearchTurmaByDisciplina(alunos[codIndexAluno].codDisciplina[1],disciplinas);
    int codCurso = fnSearchCursoByTurma(codTurma,turmas);

    if(codIndexAluno == -1){
        printf("Nao foi possivel encontrar aluno com a seguinte matricula \"%d\".\n",matricula);
        return;
    }

    printf("Aluno : %s;\nMatricula : %d;\nCurso : %s;\nTurma : %s;\n",alunos[codIndexAluno].nome,alunos[codIndexAluno].matricula,fnSearchCurso(codCurso,cursos),fnSearchTurma(codTurma,turmas));

    printf("Lista Disciplinas :\n");

    int i;
    for(i = 0; i <= Tamanho ;i++){
        if(alunos[codIndexAluno].codDisciplina[i] != 0){
            printf("   - %s;\n",fnSearchDisciplina(alunos[codIndexAluno].codDisciplina[i],disciplinas));
        }
    }
}

int fnWriteFile(char strFile[Tamanho],char strData[1024]){
    char file[Tamanho];
    strcpy(file,Path);
    strcat(file,strFile);
    strcat(strData,"\n");

    FILE *fp;
    fp = fopen(file, "a+");
    if (fp == NULL){
        fp = fopen(file, "wb");
    }

    if(fwrite(strData,strlen(strData), 1,fp) != 1){
        printf("Erro na escrita do arquivo");
        return 0;
    }

    fclose(fp);
    return 1;
}

int fnFillStructFile(char strFile[Tamanho],int codStruct,curso *cursos,disciplina *disciplinas,turma *turmas,aluno *alunos){
    char file[Tamanho];
    strcpy(file,Path);
    strcat(file,strFile);
    int intContador = 1;
    int codAlunoAux = 0;

    FILE *fp;
    fp = fopen(file, "a+");
    if (fp == NULL){
        fp = fopen(file, "wb");
    }

    char buff[1024];

    switch(codStruct){
        case 1:/**Curso*/
            while(fgets(buff, 1024, (FILE*)fp) != NULL){
                char **list;
                size_t i, len;

                /**FUNCTION CONVERT STRING ARRAY BY SEPARETE*/
                explode(buff, ";", &list, &len);
                cursos[intContador].codCurso = strtol(list[0], NULL, 10);
                strcpy(cursos[intContador].nome,list[1]);
                cursos[intContador].nome[strlen(cursos[intContador].nome)-1] = 0;

                /* free list */
                for(i = 0; i < len; ++i)
                    free(list[i]);
                free(list);
                intContador++;
            }
            break;
        case 2:/**Turma*/
            while(fgets(buff, 1024, (FILE*)fp) != NULL){
                char **list;
                size_t i, len;

                /**FUNCTION CONVERT STRING ARRAY BY SEPARETE*/
                explode(buff, ";", &list, &len);
                turmas[intContador].codTurma = strtol(list[0], NULL, 10);
                turmas[intContador].codCurso = strtol(list[1], NULL, 10);
                strcpy(turmas[intContador].nome,list[2]);
                turmas[intContador].nome[strlen(turmas[intContador].nome)-1] = 0;

                /* free list */
                for(i = 0; i < len; ++i)
                    free(list[i]);
                free(list);
                intContador++;
            }
            break;
        case 3:/**Disciplina*/
            while(fgets(buff, 1024, (FILE*)fp) != NULL){
                char **list;
                size_t i, len;

                /**FUNCTION CONVERT STRING ARRAY BY SEPARETE*/
                explode(buff, ";", &list, &len);
                disciplinas[intContador].codDisciplina = strtol(list[0], NULL, 10);
                disciplinas[intContador].codTurma = strtol(list[1], NULL, 10);
                strcpy(disciplinas[intContador].nome,list[2]);
                disciplinas[intContador].nome[strlen(disciplinas[intContador].nome)-1] = 0;

                /* free list */
                for(i = 0; i < len; ++i)
                    free(list[i]);
                free(list);
                intContador++;
            }
            break;
        case 4:/**Aluno*/
            while(fgets(buff, 1024, (FILE*)fp) != NULL){
                char **list;
                size_t i, len;

                /**FUNCTION CONVERT STRING ARRAY BY SEPARETE*/
                explode(buff, ";", &list, &len);
                alunos[intContador].matricula = strtol(list[0], NULL, 10);
                strcpy(alunos[intContador].nome,list[1]);
                alunos[intContador].nome[strlen(alunos[intContador].nome)-1] = 0;

                /* free list */
                for(i = 0; i < len; ++i)
                    free(list[i]);
                free(list);
                intContador++;
            }
            break;
        case 5:/**Disciplina Aluno*/
            while(fgets(buff, 1024, (FILE*)fp) != NULL){
                char **list;
                size_t i, len;
                /**FUNCTION CONVERT STRING ARRAY BY SEPARETE*/
                explode(buff, ";", &list, &len);

                if(strtol(list[0], NULL, 10) == codAlunoAux || codAlunoAux == 0){
                    codAlunoAux = strtol(list[0], NULL, 10);
                }else{
                    intContador = 1;
                }
                alunos[strtol(list[0], NULL, 10)].codDisciplina[intContador] = strtol(list[1], NULL, 10);

                /* free list */
                for(i = 0; i < len; ++i)
                    free(list[i]);
                free(list);
                intContador++;
            }
            break;
        default:
            printf("N�o foi possivel reconhecer a origem do arquivo!");
            break;
    }

    fclose(fp);
    return intContador;
}


void main(){

    /**CREATE FOLDER FOR FILES*/
    mkdir(Path, 777);

    /**VARIABLES DINAMICS WITH malloc()*/
    disciplina *disciplinas = (disciplina *) malloc(sizeof(disciplina)* Tamanho);
    aluno *alunos = (aluno *) malloc(sizeof(aluno)*Tamanho);
    turma *turmas = (turma *) malloc(sizeof(turma)*Tamanho);
    curso *cursos = (curso *) malloc(sizeof(curso)*Tamanho);

    int i;
    for(i = 0; i < Tamanho; i++){
        free(alunos[i].matricula);
        free(alunos[i].nome);
    }

    /**COUNTERS STRUCT*/
    int intContCurso = 1,intContTurma = 1, intContDisciplina = 1, intContAluno = 1;
    int intCodCurso = 0,intCodTurma,intCodAluno,aux ;

    /**FILL */
    intContCurso = fnFillStructFile("curso.txt",1,cursos,disciplinas,turmas,alunos);
    intContTurma = fnFillStructFile("turma.txt",2,cursos,disciplinas,turmas,alunos);
    intContDisciplina = fnFillStructFile("disciplina.txt",3,cursos,disciplinas,turmas,alunos);
    intContAluno = fnFillStructFile("aluno.txt",4,cursos,disciplinas,turmas,alunos);
    fnFillStructFile("disciplinaAluno.txt",5,cursos,disciplinas,turmas,alunos);

    /**MENU SYSTEM*/
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
                            aux = intContCurso;
                            intContCurso = fnCadastraCurso(cursos,intContCurso);
                            if(intContCurso > -1){
                                printf("O curso foi salvo com sucesso!\n");
                            }else{
                                intContCurso = aux;
                                printf("Erro, ao cadastrar o curso!\n");
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
                            aux = intContTurma;
                            intContTurma = fnCadastraTurma(turmas,intContTurma);
                            if(intContTurma > -1){
                                printf("A turma foi salvo com sucesso!\n");
                            }else{
                                intContTurma = aux;
                                printf("Erro, ao cadastrar a turma!\n");
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
                            aux = intContDisciplina;
                            intContDisciplina = fnCadastraDisciplina(disciplinas,intContDisciplina);
                            if(intContDisciplina > -1){
                                printf("A disciplina foi salvo com sucesso!\n");
                            }else{
                                intContDisciplina = aux;
                                printf("Erro, ao cadastrar a disciplina!\n");
                            }
                            break;
                        case 2:
                            printf("Digite o codigo da Turma, das disciplinas que deseja listar:\n");
                            scanf("%d", &intCodTurma);
                            fnListaDisciplina(intCodTurma,disciplinas,intContDisciplina,turmas);
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
                    printf("1 - Cadastrar\n2 - Buscar Aluno\n0 - Back\n");
                    scanf("%d", &entrada1);
                    switch(entrada1){
                        case 1:
                            aux = intContAluno;
                            intContAluno = fnCadastraAluno(alunos,intContAluno);
                            if(intContAluno > -1){
                                printf("O aluno foi salvo com sucesso!\n");
                            }else{
                                intContAluno = aux;
                                printf("Erro, ao cadastrar o aluno!\n");
                            }
                            break;
                        case 2:
                            printf("Digite matricula do aluno:\n");
                            scanf("%d", &intCodAluno);
                            fnListaAluno(intCodAluno,alunos,intContAluno,disciplinas,turmas,cursos);
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
