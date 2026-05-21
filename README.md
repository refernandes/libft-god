# Libft-God (Versão 2026) 🚀

O **Libft-God** é um testador avançado e moderno para o projeto `libft` da 42. Ele foi desenvolvido para garantir que sua biblioteca esteja em conformidade com o padrão PDF de 2026, oferecendo testes rigorosos de funcionalidade, gestão de memória e estilo.

## ✨ Funcionalidades

- ✅ **Testes Funcionais:** Cobre as Partes 1, 2, Bônus (Part 3) e funções adicionais.
- 🎨 **Interface Moderna:** Exibição em tabelas coloridas com caracteres de desenho de caixa e progresso em tempo real.
- 🔍 **Detecção de Leaks:** Integração automática com o **Valgrind** para verificar vazamentos de memória em cada caso de teste.
- 📏 **Norminette:** Verificação de normas diretamente pelo script.
- 🚫 **Funções Proibidas:** Checagem automática para garantir que você não usou funções não autorizadas.
- 🛠️ **Gestão de Makefile:** Testa todas as regras obrigatórias (`all`, `clean`, `fclean`, `re`, `bonus`).
- 🎯 **Testes Granulares:** Permite testar apenas uma função específica ou partes selecionadas do projeto.

## 📋 Pré-requisitos

Para usar este tester, você precisará de:
- **Norminette** (instalado no ambiente 42).
- **Valgrind** (opcional, mas recomendado para testes de leak).
- **GCC** ou **Clang**.

## 🚀 Como Usar

### 1. Configuração

Antes de rodar, você precisa informar ao tester onde está sua `libft`.

1. Copie o arquivo de template (se não existir `my_config.sh` na raiz):
   ```bash
   cp srcs/config_template.sh my_config.sh
   ```
2. Edite o arquivo `my_config.sh` e preencha a variável `PATH_LIBFT` com o caminho do seu projeto:
   ```bash
   PATH_LIBFT="/caminho/para/sua/libft"
   ```

### 2. Execução

Para rodar todos os testes padrão:
```bash
bash grademe.sh
```

### 3. Exemplos de Comandos Úteis

- **Testar apenas uma função:**
  ```bash
  bash grademe.sh ft_atoi
  ```

- **Testar apenas uma parte específica:**
  ```bash
  bash grademe.sh -op1  # Apenas Parte 1
  bash grademe.sh -op2  # Apenas Parte 2
  bash grademe.sh -op3  # Apenas Bônus
  ```

- **Ignorar Norminette ou Leaks:**
  ```bash
  bash grademe.sh -n    # Pula a Norminette
  bash grademe.sh -f    # Pula checagem de funções proibidas
  ```

## 🛠️ Opções Disponíveis

| Opção | Descrição |
| :--- | :--- |
| `-h`, `--help` | Exibe o manual completo. |
| `-d` | Permite testes mesmo que os arquivos estejam em subdiretórios. |
| `-c` | Desativa as cores no terminal. |
| `-m` | Testa rigorosamente todas as regras do seu Makefile. |
| `-u` | Desativa a busca por atualizações ao iniciar. |
| `-p1, -p2, -p3` | Desativa os testes da Parte 1, 2 ou Bônus, respectivamente. |

## 📁 Funções Suportadas

O tester suporta todas as funções clássicas da `libc`, funções de manipulação de strings da Parte 2, funções de lista encadeada (Bônus) e diversas funções extras como `ft_isspace`, `ft_itoa_base`, etc. (Veja a lista completa em `supported_functions.md`).

---
*Disclaimer: Este tester é uma ferramenta de auxílio. Passar em todos os testes não garante nota máxima, mas aumenta drasticamente suas chances!*
