#include <stdio.h>
#include <string.h>

struct CartaSuperTrunfo {
   char estado;
   char codigo[4]; // Supondo um comprimento máximo de 3 caracteres + ''
   char cidade[50];
   int populacao;
};