<h1 align="center">Processo Seletivo 42 São Paulo: 42Labs 2ª edição</h1>

Nesse desafio você vai construir duas aplicações utilizando C: uma API e uma aplicação de interface de linha de comando(CLI).

##  Tecnologias
- <b>C</b>
- <b>Mysql 5.7.37</b>
- <b>Docker</b>
- <b>Mongoose (biblioteca de rede para C/C++.)</b>
- <b>Makefile</b>
- <b>Trello (Ferramenta de organização/criação de tarefas)</b>
- <b>Notion (Ferramenta de anotação)</b>

## Api
-- A API que você irá construir poderá lidar com dados com formato e origem de sua escolha. Um exemplo seria fazer uma API que retorna o conteúdo de postagens de um blog.

## Sobre a Api
-- Para criar um servidor e deixa-lo no ar (escutando), utilizamos a biblioteca mongoose, em seguida ele detecta qual o metetodo e endpoint que foi passado e faz uma chamada no nosso banco de dados (hospedado na nuvem), e traz uma resposta para o client em formato json.

-- Para rodar a api basta clonar o repositorio: "https://github.com/42sp/42labs-selection-process-v2-Warley-Juneo.git"

-- Entre na pasta sources e utilize: "docker build -t api:focal ."

-- Depois utilize: "docker run -v /home/saitama/github/42labs/42labsWJ/sources/logs/logs.log:/home/wj/logs/logs.log --env-file ../db.env -p 8080:8080 api:focal"

## Cli
-- A aplicação CLI que você irá construir deverá consumir e processar o arquivo de logs gerado pela API REST.

## Sobre a CLI
-- Para criar a Cli usei apenas C, simplesmente ele consome os logs gerados pela Api, faz um parseamento desses dados e imprime no terminal de forma legivel.

-- Para executar a cli, entre na pasta ./cli execute: make && ./cli com alguma das opções abaixo.

-- opções: "GET all", "GET", "GET /", "GET /all"


## Minha Visão sobre o projeto
-- Particulamente achei o projeto incrivel, eu entrei no projeto apenas sabendo C, e tive uma experiência incrivel sobre como funciona um projeto na "vida real", onde se usa containers, banco de dados, bibliotecas, parseamento do JSON entre outros. Com certeza esse projeto me fez enxergar mais longe, entender melhor oque eu quero como carreira e que trabalho em equipe nos ajuda a ir incrivelmente mais longe.
