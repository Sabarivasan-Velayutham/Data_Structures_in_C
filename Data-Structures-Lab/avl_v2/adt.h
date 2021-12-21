
struct wordMeaning
{
    char *word ; 
    char *meaning ; 
};


struct dictionary
{
    struct wordMeaning w ; 
    struct dictionary *left;
    struct dictionary *right;
    int height ; 
};

// void insert(struct dictionaryADT *D, struct wordMeaning x) – Insertion of a new word and meaning into dictionary
// void disp(struct dictionaryADT *D) – Display all the words and their meanings in ascending order
// void search(struct dictionaryADT *D, char word[]) – Will search for a word and provides its meaning
