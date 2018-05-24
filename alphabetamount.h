#ifndef ALPHABETAMOUNT_H
#define ALPHABETAMOUNT_H

#define ALPHA_AMOUNT 5
#define JAP_ALPH_AMOUNT 3
#define LAT_ALPH_AMOUNT 2

typedef enum {
    ENG,
    ROMAJI,
    KATA,
    HIRA,
    KANJI
} alphabet;

typedef enum {
    JAP_KATA,
    JAP_HIRA,
    JAP_KANJI
} japAlpha;

typedef enum {
    LAT_ENG,
    LAT_ROMAJI
} latAlpha;

#endif // ALPHABETAMOUNT_H
