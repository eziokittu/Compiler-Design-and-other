# Python program to identify the identifiers in C

import re

keywords = [
    "auto",	"break", "case", "char",
    "const", "continue", "default", "do",
    "double", "else", "enum", "extern",
    "float", "for", "goto",	"if",
    "int", "long", "register", "return",
    "short", "signed", "sizeof", "static",
    "struct", "switch",	"typedef", "union",
    "unsigned",	"void",	"volatile",	"while"]

def isIdentifier(s):
    '''function for checking if the string can be used as an identifier and returns TRUE. '''
    number_of_underscores = 0
    identifier_max_length = 31

    # if identifier matches a keyword
    if s in keywords:
        return False

    # if identifier contains white spaces
    if ' ' in s:
        return False

    # if starting character is alphabet or underscore
    if s[0].isalpha() or s[0] == "_":
        number_of_underscores = s.count('_')
    else:
        return False

    # checking if all the characters are either alpha, num or underscore
    if (len(re.findall("[a-zA-Z0-9]", s)) + number_of_underscores) != len(s):
        return False

    # checking if the indentifier is below the maximum significant character limit
    if len(s) > identifier_max_length:
        return False

    else:
        return True

# This loop will run infinitely
while True:
    inputToken = input("\nEnter a string to check if it can be used as an IDENTIFIER for C --- ")
    if isIdentifier(inputToken):
        print(f"YES, '{inputToken}' can be used as an IDENTIFIER in C")
    else:
        print(f"NO, '{inputToken}' cannot be used as an Identifier in C")
