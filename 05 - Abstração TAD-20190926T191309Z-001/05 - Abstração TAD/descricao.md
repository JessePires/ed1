# Abstração TAD

A partir da descrição abaixo, defina uma estrutura (*struct*) que atenda as necessidades mencionadas. 

## Descrição

Precisa-se representar computacionalmente uma agenda de pessoas. A partir desta modelagem, será necessária a criação de várias agendas de diferentes tamanhos. 

- Uma agenda possui uma descrição e uma lista de pessoas (sem tamanho máximo). 
- Cada pessoa é composto por:
  - nome
  - idade
  - email
  - endereço
    - cep
    - número 
    - estado
  - lista de telefones. Cada pessoa pode ter no máximo 4 telefones cadastrados. Além do telefone, necessita-se armazenar se o número possui cadastro no aplicativo whatsapp.
    - telefone
    - tem whatsapp? sim ou não


**Obs.:** Para a respresentação desses dados, quando possível, tente minimizar o espaço ocupado em memória. Por exemplo: ao invés de vetores de `struct`, utilize vetores de ponteiros de `struct`. 

## Funcionalidades


