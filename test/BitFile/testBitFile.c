#include "BitFile.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *f = fopen("write_5bits.bin", "w");

    uint8_t bits[] = {1, 0, 0, 1, 1};
    struct BitFile *bf = BitFile_create(f);
    BitFile_writeBits(bits, 5, bf);
    printf("1: bitPos: %zu\n", bf->bitPos);
    BitFile_close(bf);

    fclose(f);

    f = fopen("write_5bits.bin", "r");
    bf = BitFile_create(f);
    uint8_t bits2[5] = {0};
    BitFile_readBits(bits2, 5, bf);
    printf("2:\n");
    for (size_t i = 0; i < 5; i++) {
        printf("%hhu ", bits2[i]);
    }
    putchar('\n');
    printf("3: bitPos: %zu\n", bf->bitPos);
    BitFile_close(bf);

    fclose(f);

    f = fopen("write_17bits.bin", "w");
    bf = BitFile_create(f);
    // 0x9C 0x9C + 1
    uint8_t bits3[17] = {1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1};

    BitFile_writeBits(bits3, 17, bf);
    printf("4: bitPos: %zu\n", bf->bitPos);
    BitFile_close(bf);

    fclose(f);

    f = fopen("write_17bits.bin", "r");
    bf = BitFile_create(f);
    uint8_t bits4[17] = {0};

    BitFile_readBits(bits4, 17, bf);
    printf("5:\n");
    for (size_t i = 0; i < 17; i++) {
        printf("%hhu ", bits4[i]);
    }
    putchar('\n');
    printf("6: bitPos: %zu\n", bf->bitPos);
    BitFile_close(bf);

    fclose(f);

    f = fopen("write_17bits_seek_5bits.bin", "w");
    bf = BitFile_create(f);
    BitFile_writeBits(bits3, 17, bf);
    BitFile_close(bf);
    fclose(f);

    f = fopen("write_17bits_seek_5bits.bin", "r+");
    bf = BitFile_create(f);
    BitFile_seek(bf, 5);
    BitFile_writeBits(bits3, 17, bf);
    BitFile_close(bf);
    fclose(f);

    f = fopen("write_17bits_seek_5bits.bin", "r");
    bf = BitFile_create(f);

    uint8_t bits5[22] = {0};
    BitFile_readBits(bits5, 22, bf);

    printf("7:\n");
    for (size_t i = 0; i < 22; i++) {
        printf("%hhu ", bits5[i]);
    }
    putchar('\n');

    BitFile_close(bf);
    fclose(f);

    f = fopen("write_17bits_seek_5bits.bin", "r");
    bf = BitFile_create(f);
    uint8_t bits6[17] = {0};
    BitFile_seek(bf, 5);
    BitFile_readBits(bits6, 17, bf);

    printf("8:\n");
    for (size_t i = 0; i < 17; i++) {
        printf("%hhu ", bits6[i]);
    }
    putchar('\n');

    BitFile_seek(bf, 17);
    memset(bits6, 0, 17);
    printf("9: actualReadBits: %zu\n", BitFile_readBits(bits6, 17, bf));

    printf("10:\n");
    for (size_t i = 0; i < 17; i++) {
        printf("%hhu ", bits6[i]);
    }
    putchar('\n');

    BitFile_close(bf);
    fclose(f);

    f = fopen("write_twice_5bits.bin", "w");
    bf = BitFile_create(f);

    uint8_t bits7[5] = {1, 0, 0, 1, 1};
    BitFile_writeBits(bits7, 5, bf);
    BitFile_writeBits(bits7, 5, bf);
    BitFile_close(bf);
    fclose(f);

    f = fopen("write_twice_5bits.bin", "r");
    bf = BitFile_create(f);

    uint8_t bits8[5] = {0};
    BitFile_readBits(bits8, 5, bf);

    printf("11:\n");
    for (size_t i = 0; i < 5; i++) {
        printf("%hhu ", bits8[i]);
    }
    putchar('\n');

    memset(bits8, 0, 5);
    BitFile_readBits(bits8, 5, bf);
    printf("12:\n");
    for (size_t i = 0; i < 5; i++) {
        printf("%hhu ", bits8[i]);
    }
    putchar('\n');

    BitFile_close(bf);
    fclose(f);

    return 0;
}