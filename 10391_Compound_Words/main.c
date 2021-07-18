/*
 * Probllem 10391 Compound Words
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_BITS 17
#define WORD_LENGTH 16

/* based on https://stackoverflow.com/questions/16870485 */
char *read_line(int size) {
    char *str = malloc(size);
    if (!str) {
        fprintf(stderr, "malloc error\n");
        exit(1);
    }

    int ch;
    int len = 0;
    while ((ch = getchar()) != EOF && (ch != '\n')) {
        str[len++] = ch;
        if (len == size) {
            size *= 2;
            str = realloc(str, size);
            if (!str) {
                fprintf(stderr, "realloc error\n");
                exit(1);
            }
        }
    }
    str[len] = '\0';
    return str;
}

typedef struct word_node {
    char **word;
    struct word_node *next;
} word_node;

#define hashsize(n) ((unsigned long)1 << (n))
#define hashmask(n) (hashsize(n) - 1)

unsigned long oaat(char *key, unsigned long len, unsigned long bits) {
    unsigned long hash, i;
    for (hash = 0, i = 0; i < len; ++i) {
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash & hashmask(bits);
}

int identical_right(int snow1[], int snow2[], int start) {
    for (int offset = 0; offset < 6; ++offset) {
        if (snow1[offset] != snow2[(start + offset) % 6]) {
            return 0;
        }
    }
    return 1;
}

int in_hash_table(word_node *hash_table[], char *find,
        unsigned find_len) {
    unsigned word_code = oaat(find, find_len, NUM_BITS);
    word_node *wordptr = hash_table[word_code];
    while (wordptr) {
        if ((strlen(*(wordptr->word)) == find_len) &&
                (strncmp(*(wordptr->word), find, find_len) == 0)) {
            return 1;
        }
        wordptr = wordptr->next;
    }
    return 0;
}

void identify_compound_words(char *words[], word_node *hash_table[],
        int total_words) {
    for (int i = 0; i < total_words; ++i) {
        unsigned len = strlen(words[i]);
        for (int j = 1; j < len; ++j) {
            if (in_hash_table(hash_table, words[i], j) &&
                    in_hash_table(hash_table, &words[i][j], len - j)) {
                printf("%s\n", words[i]);
                break;
            }
        }
    }
}


int main(void) {
    static char *words[1 << NUM_BITS] = {NULL};
    static word_node *hash_table[1 << NUM_BITS] = {NULL};

    int total = 0;
    char *word = read_line(WORD_LENGTH);
    while (*word) {
        words[total] = word;
        word_node *wordptr = malloc(sizeof(word_node));
        if (!wordptr) {
            fprintf(stderr, "malloc error\n");
            return EXIT_FAILURE;
        }
        unsigned length = strlen(word);
        unsigned word_code = oaat(word, length, NUM_BITS);
        wordptr->word = &words[total];
        wordptr->next = hash_table[word_code];
        hash_table[word_code] = wordptr;
        word = read_line(WORD_LENGTH);
        ++total;
    }
    identify_compound_words(words, hash_table, total);
    return EXIT_SUCCESS;
}
