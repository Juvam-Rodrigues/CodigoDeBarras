#include "../include/tabela.h"
#include "../include/codigo.h"
#include <string.h>

// Tabela de codificação para os dígitos 0-9

const char *leftCode[10] = {
    "0001101", // 0
    "0011001", // 1
    "0010011", // 2
    "0111101", // 3
    "0100011", // 4
    "0110001", // 5
    "0101111", // 6
    "0111011", // 7
    "0110111", // 8
    "0001011"  // 9
};

const char *rightCode[10] = {
    "1110010", // 0
    "1100110", // 1
    "1101100", // 2
    "1000010", // 3
    "1011100", // 4
    "1001110", // 5
    "1010000", // 6
    "1000100", // 7
    "1001000", // 8
    "1110100"  // 9
};
const char *inicio[1] = {
    "101"};

const char *final[1] = {
    "101"

};

const char *centro[1] = {
    "01010"};

