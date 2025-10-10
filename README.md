# MyString

MyString é um mini framework para trabalhar com Strings em C.



Para compilar use os seguintes passos:


1. Crie o object (.o) do source com o header: gcc -c src/smystring.c -Iinclude -o build/smystring.o
2. Crie a lib estática (.a) com base nos objects (.o): ar rcs build/libsmystring.a build/smystring.o 
3. Compile seu projeto com a biblioteca: gcc app.c -Iinclude -Lbuild -lsmystring