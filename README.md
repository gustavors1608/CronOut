# CronOut
Uma biblioteca para o Arduino que gerencie um único timeout por instância da classe. Cada timeout pode ser iniciado, reiniciado, cancelado e verificado se já foi atingido. O tempo será em milissegundos e, ao atingir o timeout, será executada uma função de callback que não recebe parâmetros, além de alterar uma variável interna.
