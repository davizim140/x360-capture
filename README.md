# X360 Capture — etapa 2: testes automáticos

Esta etapa adiciona um workflow do GitHub Actions para compilar e executar os testes portáveis do núcleo C++.

## Estado honesto
- O workflow testa apenas a lógica portátil.
- Não compila um `.xex`.
- Ainda não há captura de gameplay, codificador de vídeo ou gravação USB no console.

## Teste local
```sh
g++ -std=c++17 -Wall -Wextra -Werror -pedantic src/capture_core.cpp tests/test_capture_core.cpp -o capture-tests
./capture-tests
```

## Publicar no GitHub pelo navegador
1. Crie um repositório chamado `x360-capture` no GitHub.
2. Envie os arquivos deste ZIP para a raiz do repositório, incluindo a pasta `.github/workflows`.
3. Abra **Actions**. O workflow `Portable core tests` executa automaticamente após o push.
4. Confirme que o job fica verde e que os testes mostram `7/7 tests passed`.

## Próxima integração Xbox 360
O SDK de referência é https://github.com/xenosworks/xsdk. A integração com um template de título e as APIs específicas do console deve ser validada separadamente. Não marque um `.xex` como produzido sem um artefato real e log de compilação.
