<h2>Do que se trata o projeto? 🤔</h1>

Este projeto consiste em um trabalho desenvolvido para a disciplina Introdução às Técnicas de Programação, no qual o objetivo é criar um programa capaz de processar, analisar e exibir informações a partir dos dados obtidos de um código de barra (<strong>EAN-8</strong>). Ele é capaz de:
<ul>
    <li>Gerar a imagem PBM do código de barras com base em um identificador fornecido, verificando possíveis erros.
    </li>
    <li>Validar a integridade de um identificador utilizando o cálculo do dígito verificador.
    </li>
    <li>Decodificar um código de barras para verificar suas informações.
    </li>
    
</ul>

<h2>Estrutura de pastas: 📂</h1>
   <ul>
        <li>include
            <ul>
                <li>arquivo.h</li>
                <li>codigo.h</li>
                <li>tabela.h</li>
            </ul>
        </li>
        <li>src
            <ul>
                <li>codigo.c</li>
                <li>geradorCodigo.c</li>
                <li>leitorCodigo.c</li>
                <li>tabela.c</li>
            </ul>
        </li>
        <li>readme
            <ul>
                <li>readme.md</li>
            </ul>
        </li>
    </ul>

<h2>Como usar? 👤</h2>
Para utilizar este projeto, temos dois arquivos com o método main: <strong>geradorCodigo.c</strong> e <strong>leitorCodigo.c</strong>.
<ul>
        <li>geradorCodigo.c
            <ul>
                <li>gcc codigo.c geradorCodigo.c tabela.c -o "NomeDoExecutavel"</li>
                Tendo compilado, fazemos (<strong>Opcional: <'Espaçamento Lateral'> <'Área por pixel'> <'Altura'> <'Nome do Arquivo Gerado>*</strong>):
                <li><'NomeDoExecutavel'> <'Identificador do código'> <'Espaçamento Lateral'> <'Área por pixel'> <'Altura'> <'Nome do Arquivo Gerado>'</li>
            </ul>
        </li>
        <li>leitorCodigo.c
            <ul>
                <li>gcc codigo.c leitorCodigo.c tabela.c -o "NomeDoExecutavel"</li>
                <li><'NomeDoExecutavel'> <'Nome do Arquivo Gerado'></li>
            </ul>
        </li>
    </ul>
<strong>Observação: caso for utilizar, coloque 0 no lugar dos argumentos opcionais que não queiram alterar os valores padrões do geradorCodigo.C.</strong>

<h2>Colaboradores: 🤝</h2>
Este projeto possui por colaboradores (principais desenvolvedores):
<ul>
    <li>Juvam Rodrigues do Nascimento Neto</li>
    <li>Vinicius de Freitas Cavalcante Moreira</li>
</ul>