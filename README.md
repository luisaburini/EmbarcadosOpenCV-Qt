# EmbarcadosOpenCV-Qt

Este código demonstra a inserção do OpenCV em uma aplicação de Qt através de uma aplicação simples de detecção facial.

## Hardware ##
* Computador em módulo Apalis iMX6Q
* Placa base Ixora
* Módulo de câmera CSI OV5640

## Como usar a aplicação ##
* Compile com o kit de compilação gerado segundo o artigo Como Adicionar OpenCV em aplicações Qt do Blog Embarcados
* Rode o binário na placa com o appcontroller
<code>
/usr/bin/appcontroller /opt/EmbarcadosOpenCV-Qt/bin/EmbarcadosOpenCV-Qt
</code>

* Na aplicação, é possível tirar uma foto ao apertar o botão, logo em seguida, as faces frontais são circuladas na imagem. 
Ao clicar na imagem com as faces circuladas, retorna ao modo de captura.

![alt text](demo.gif)
