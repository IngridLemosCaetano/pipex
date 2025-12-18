<h1 align="center"> 🚀✅ pipex ✅🚀 </h1>



## 💻 Sobre o projeto


O <strong>pipex</strong> faz parte da grade da Escola 42 (Milestone 2).

O projeto consiste em reproduzir o comportamento do operador | (pipe) do shell, permitindo encadear a saída de um comando como entrada de outro, utilizando as chamadas de sistema em C.

Na prática o programa deve executar algo equivalente a:

		< infile cmd1 | cmd2 > outfile
Utilizando o programa:

		./pipex infile "cmd1" "cmd2" outfile

## 🧠 Conceitos utilizados

- Processos (fork)
- Comunicação entre processos (pipe)
- Redirecionamento de arquivos (dup2)
- Execução de comandos (execve)
- Manipulação de erros
- Variáveis de ambiente (PATH)


## ⚙️ Funcionamento

O programa recebe 4 argumentos:

		./pipex infile cmd1 cmd2 outfile
-	**infile**: arquivo de entrada.
-	**cmd1**: primeiro comando a ser executado.
-	**cmd2**: segundo comando a ser executado.
-	**outfile**: arquivo de saída.

**Fluxo:**
1. O conteúdo de infile é passado para cmd1
2. A saída de cmd1 é redirecionada para cmd2 através de um pipe.
3. A saída de cmd2 é escrita em outfile


## 📁 Estrutura do Projeto

pipex/ <br>
├── inc/ <br>
│ └── pipex.h <br>
│ └── pipex_bonus.h <br>
├── lib/ <br>
│ └── libft/ <br>
│   └── libft.a/ <br>
├── src/ <br>
│ ├── main_bonus.c <br>
│ ├── main.c <br>
│ ├── pipex_bonus.c <br>
│ ├── pipex_utils_bonus.c/ <br>
│ ├── pipex_utils.c/ <br>
│ ├── pipex.c/ <br>
├── infile <br>
├── Makefile <br>
└── README.md <br>



## ⚙️ Compilação

 - Para compilar o projeto, execute:

       make ou make bonus

 - Para limpar os arquivos objeto:

       make clean

 - Para remover tudo (obj e executável):

       make fclean

## ▶️ Execução
**Execução obrigatória**

    	./pipex infile "ls -l" "wc -l" outfile

**⭐ Bônus – múltiplos pipes**

O programa também suporta múltiplos comandos encadeados, reproduzindo o comportamento do shell com vários pipes:

		< infile cmd1 | cmd2 | cmd3 | ... | cmdn > outfile
Utilizando o pipex_bonus:		

  		./pipex_bonus infile "cat" "grep que" "tr a-z A-Z" outfile


## ✅ Grade ✅

![Web1](https://github.com/IngridLemosCaetano/pipex/blob/main/pipex.png)



## <img src="https://github.com/user-attachments/assets/c7002718-57e0-4c87-9a47-5c14e509d9ea" width="30px"/> Autora

Ingrid Lemos Caetano Silva

👩‍💻 [GitHub](https://github.com/IngridLemosCaetano) | 💼 [Linkedin](https://br.linkedin.com/in/ingrid-lemos-caetano)


![42](https://img.shields.io/badge/School-42-black)  ![42](https://img.shields.io/badge/42-pipex-blue)

