# rectangles
Um programa composto por modulos que aceita entrada .txt e da a saida .txt que controla retângulos que vão caindo para a base
Este código adiciona uma função chamada “calculateInstability” a um programa existente. A função 
calcula o grau de instabilidade de um conjunto de retângulos e exibe uma mensagem se o grau médio de 
instabilidade for igual ou superior a 70%
if(n_instable > 0){ n_instable = 1; } if(instability/n_instable >= 70) printf("O sistema exibe um grau de 
instabilidade de %.2f%%\n", instability/n_instable);
A função percorre todos os retângulos na lista de retângulos. Para cada retângulo, verifica se ele está 
apoiado por outros retângulos abaixo dele. Se estiver, calcula a quantidade de suporte que esses 
retângulos fornecem. 
if (support->y + support->h == rectangle->y) { if(rectangle->x >= support->x && rectangle->x <= support-
>x + support->l - 1){ supported += support->x + support->l - rectangle->x; } else if(rectangle-
>x+rectangle->l-1 >= support->x && rectangle->x+rectangle->l-1 <= support->x + support->l - 1){ 
supported += rectangle->x+rectangle->l - support->x; } }
Em seguida, verifica se a quantidade de suporte é menor ou igual a metade da largura do retângulo. Se 
for, o retângulo é considerado instável. Nesse caso, o grau de instabilidade é calculado com a diferença 
entre a largura do retângulo e a quantidade de suporte, dividida pela largura do retângulo e multiplicada 
por 100. O grau de instabilidade é acumulado em uma variável.
if(supported <= rectangle->l/2){ instability += ((float)rectangle->l - supported)/rectangle->l*100; 
n_instable++
