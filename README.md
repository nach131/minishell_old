<h1 align="center">
  <img  width="120" alt="42logo"  src="https://user-images.githubusercontent.com/19689770/129336866-169b0dc7-ea41-47d4-b50a-d466508031af.png">

	minishell

</h1>
 <p align="center">
<img alt="GitHub repo size" src="https://img.shields.io/github/repo-size/nach131/minishell">
<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/nach131/minishell">
<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/nach131/minishell">
<img alt="license-MIT" src="https://img.shields.io/badge/license-MIT-blue">
</p>

## [Funciones permitidas](markdown/allowed.md)

## [Instalación libreadline](markdown/libreadline.md)

## Usadas

pipe, perror, dup2, execve, access

```mermaid
flowchart TD
    A{Leer entrada}
    A -->|Desde archivo| B{Dividir}
    A -->|Desde Argv| B
    A -->|Desde terminal| B
    B --> |Palabras| C{Tokens}
    B --> |Operadores| C
    C --> |Simples| D[Expandir]
    C --> |Compuestos| D
    D --> E[Redirecionar] --> F
    F([Ejecutar comando]) --> G
    G{{Esperar fin comando}}
```
