# ArduinoDayUnisinosDojo
Arduino Day 2019 realizado na Unisinos. Atividade: DOJO - Aplicado segurança ao telegram com ESP32


Este projeto foi desenvolvido em uma oficina realizada no Arduino Day da Unisinos no dia 16/03/2019. Como base, foi utilizado o seguinte projeto:

https://portal.vidadesilicio.com.br/controlando-seu-projeto-com-telegram-esp/

neste projeto, foi utilizado o NodeMcu (ESP8266) e como desafio foi proposto o seguinte:

"Qualquer pessoa que adicionar seu Bot (basta pesquisar), pode enviar comandos e controla-lo. Você terá que criar algum tipo de “cadeado” para aceitar apenas comandos de pessoas autorizadas. Cada usuário no Telegram tem um ID, então você pode usar isso à seu favor e fazer o sistema aceitar apenas comandos de algumas pessoas."

Nossa missão era transportar esse código para o ESP32 e realizar o desafio proposto em uma hora.

Para resolver isso, criamos um array volátil que armazena "n" usuários (inicialmente testamos 3) que validará os ID's conhecidos através do envio de uma senha.




