// C program to verify the identifiers in C

# include <stdio.h>
# include <string.h>
# include <ctype.h>

char keywords[32][10] = {
    "auto",	"break", "case", "char",
    "const", "continue", "default", "do",
    "double", "else", "enum", "extern",
    "float", "for", "goto",	"if",
    "int", "long", "register", "return",
    "short", "signed", "sizeof", "static",
    "struct", "switch",	"typedef", "union",
    "unsigned",	"void",	"volatile",	"while"
};

int isValidIdentifier(char s[40])
{
    int count_underscores = 0;
    int count_validCharacters = 0;

    // checking if tokens match KEYWORDS
    for (int i=0; i<32; i++)
    {
        if (strcmp(keywords[i], s) == 0) return 0;
    }

    // if token contains white spaces
    for (int i=0; i!='\0'; i++)
        if (&s[i] == " ") 
            return 0;

    // if starting character is alphabet or underscore
    if (isalpha(s[0]) || s[0] == '_')
    {
        // nothing
    }
    else return 0;

    // checking if all the characters are either alpha, num or underscore
    for (int i=0; s[i]!='\0'; i++)
    {
        if (isalnum(s[i]) || s[i]=='_') count_validCharacters+=1;
    }
    if (count_validCharacters != strlen(s))
        return 0;
        
    // checking if the token has a length below 32
    if (strlen(s)>31)
        return 0;
    else
        return 1;
}

int main()
{
    // recursive main loop
    while (1){
        char myInput[40];

        printf("\nEnter token to check if it can be used as a valid IDENTIFIER -- ");
        scanf("%[^\n]%*c", myInput);

        if (isValidIdentifier(myInput))
            printf("YES, '%s' can be used as an IDENTIFIER in C\n", myInput);
        else
            printf("NO, '%s' cannot be used as an IDENTIFIER in C\n", myInput);

        // repeating the program indefinitely
        main();
    }

    // never executed
    return 0;
}
