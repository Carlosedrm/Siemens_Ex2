# Exercise 2

This is the main part of the code, here we ask the user for the strings and the k value and check if they are valid.

```
int main()
{   
    // Starting string
    char s[101];
    printf("Input the starting string: ");
    scanf("%99[^\n]", s);
    getchar();
    
    // Desired string
    char t[101];
    printf("Input the desired string: ");
    scanf("%99[^\n]", t);
    getchar();

    // The k number of operations
    int k;
    printf("Input the number of operations: ");
    scanf("%d",&k);
    if(k >= 2 && k <= 100){
        printf("%s", ConcatRemove(s,t,k));
    } else{
        printf("Use a different number.");
    }

    return 0;
}
```

This is a function we use to get the size of a string.
```
int sizeofString(const char*strings){
    int sizeofString = 0;
    
    // We go over the string and get the size.
    for(int i = 0; strings[i] != 0; i++){
        sizeofString++;
    }
    
    return sizeofString;
}
```

This is the function we use to remove any whitespaces from a string by creating a new string that does not have any of the whitespaces of the original string.
```
/* This is a function to remove all the whitspaces a string may have*/
const char * removeWhitespace(const char* strings, size_t Buffer){
    // First we get the size of the string 
    int stringSize = 0;
    stringSize = sizeofString(strings);
    
    //Create a new string variable to receive the new string
    char * finalString = (char*) malloc(Buffer);
    int index = 0;
    
    //Then we go over the string create a new string with no whitespaces
    for(int i = 0; i < stringSize; i++){
        if(strings[i] != ' '){
            finalString[index] = strings[i];
            index++;
        }
    }
    finalString[index] = '\0';
    
    return finalString;
}
```

Here is the important part of the code, it receives the strings and the k number of operations and checks if it's possible to make the starting string into the desired string.
We do this by first cleaning the string of any whitespaces, then getting the size of each string and the common part of both strings(prefix). Then we need to get the difference of the prefix with the size of the starting string and the desired string and sum them up. The result would be the total amount of operations needed to get the starting string into the desired string.
```
const char * ConcatRemove(const char* s, const char* t, int k){
    //Here we remove any whitespace a string may have.
    const char* cleanS = removeWhitespace(s, sizeof(s));
    const char* cleanT = removeWhitespace(t, sizeof(t));
    
    // We get the size of each string.
    int sizeofS = 0;
    int sizeofT = 0;
    
    sizeofS = sizeofString(cleanS);
    sizeofT = sizeofString(cleanT);
    
    // Then we need to find the part both strings have in common and see if we can perform enough operations to get the desired string.
    
    char prefix[101];
    int index = 0;
    int x = 0;
    while(cleanS[x] == cleanT[x]){
        prefix[index] = cleanS[x];
        index++;
        x++;
    }
    prefix[index] = '\0';
    //printf("The prefix we have is: %s\n", prefix);
    
    // After we find the common part of both strings(prefix) we calculate the difference between the prefix and the size of the starting and desired string.
    int sizeofPrefix, difference = 0;
    sizeofPrefix = sizeofString(prefix);
    difference = (sizeofS - sizeofPrefix) + (sizeofT - sizeofPrefix);
    //printf("The difference between the two is: %d\n",difference);
    
    /*The difference is used to see how many times we would remove characters from the starting string
    and how many we would then add to get the desired string. If the difference is less or equal then the number the user inputed then it means
    it's possible to go from the starting string to the desired string in k operations.*/
    /* If the sum of the size of both strings is less or equal than the number of operations
    it's guaranteed that we can go from s to t, since we can fully remove everything from s and add everything from t.*/
    if(difference <= k || sizeofS + sizeofT <= k){
        return "yes";
    } else{
        return "no";
    }
}
```

## Unit Test
For the Unit Test please add the library string.h using: #include <string.h>. And put it in the start of the code like this:
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
```


After that use this main part of the code and run it:
```
int main()
{   
    // Starting string
    char s[101];
    // Desired string
    char t[101];
    // The k number of operations
    int k;
    //Here you can put more or less strings and numbers to test
    char startingStrings[5][20] = {
        "blae",
        "bla bla bla bla",
        "tab",
        "asdf",
        "Carlos"
    };
    
    char desiredStrings[5][20] = {
        "blax",
        "blablabcde",
        "tab",
        "asdfghjk",
        "CarlosEduardo"
    };
    
    int kOperations[] = {
        2,
        8,
        7,
        2,
        5
    };
    
    int i = 0;
    while (i < 5){
        strcpy(s, startingStrings[i]);
        printf("Starting String: %s\n",s);
        strcpy(t, desiredStrings[i]);
        printf("Desired String: %s\n",t);
        k = kOperations[i];
        printf("%s\n\n", ConcatRemove(s,t,k));
        i++;
    };
    return 0;
}
```

Or just copy and paste this code:
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to get the size of any string. */
int sizeofString(const char*strings){
    int sizeofString = 0;
    
    // We go over the string and get the size.
    for(int i = 0; strings[i] != 0; i++){
        sizeofString++;
    }
    
    return sizeofString;
}

/* This is a function to remove all the whitspaces a string may have.*/
const char * removeWhitespace(const char* strings, size_t Buffer){
    // First we get the size of the string 
    int stringSize = 0;
    stringSize = sizeofString(strings);
    
    //Create a new string variable to receive the new string.
    char * finalString = (char*) malloc(Buffer);
    int index = 0;
    
    //Then we go over the string create a new string with no whitespaces.
    for(int i = 0; i < stringSize; i++){
        if(strings[i] != ' '){
            finalString[index] = strings[i];
            index++;
        }
    }
    finalString[index] = '\0';

    return finalString;
}

const char * ConcatRemove(const char* s, const char* t, int k){
    //Here we remove any whitespace a string may have.
    const char* cleanS = removeWhitespace(s, sizeof(s));
    const char* cleanT = removeWhitespace(t, sizeof(t));
    
    // We get the size of each string 
    int sizeofS = 0;
    int sizeofT = 0;
    
    sizeofS = sizeofString(cleanS);
    sizeofT = sizeofString(cleanT);
    
    /* Then we need to find the part both strings have in common and see if we can perform enough operations to get the desired string.*/
    
    char prefix[101];
    int index = 0;
    int x = 0;
    while(cleanS[x] == cleanT[x]){
        prefix[index] = cleanS[x];
        index++;
        x++;
    }
    prefix[index] = '\0';
    //printf("The prefix we have is: %s\n", prefix);
    
    // After we find the common part of both strings(prefix) we calculate the difference between the prefix and the size of the starting and desired string.
    int sizeofPrefix, difference = 0;
    sizeofPrefix = sizeofString(prefix);
    difference = (sizeofS - sizeofPrefix) + (sizeofT - sizeofPrefix);
    //printf("The difference between the two is: %d\n",difference);
    
    /*The difference is used to see how many times we would remove characters from the starting string
    and how many we would then add to get the desired string. If the difference is less or equal then the number the user inputed then it means
    it's possible to go from the starting string to the desired string in k operations.*/
    /* If the sum of the size of both strings is less or equal than the number of operations
    it's guaranteed that we can go from s to t, since we can fully remove everything from s and add everything from t.*/
    if(difference <= k || sizeofS + sizeofT <= k){
        return "yes";
    } else{
        return "no";
    }
}

int main()
{   
    // Starting string
    char s[101];
    // Desired string
    char t[101];
    // The k number of operations
    int k;
    //Here you can put more or less strings and numbers to test
    char startingStrings[5][20] = {
        "blae",
        "bla bla bla bla",
        "tab",
        "asdf",
        "Carlos"
    };
    
    char desiredStrings[5][20] = {
        "blax",
        "blablabcde",
        "tab",
        "asdfghjk",
        "CarlosEduardo"
    };
    
    int kOperations[] = {
        2,
        8,
        7,
        2,
        5
    };
    
    int i = 0;
    while (i < 5){
        strcpy(s, startingStrings[i]);
        printf("Starting String: %s\n",s);
        strcpy(t, desiredStrings[i]);
        printf("Desired String: %s\n",t);
        k = kOperations[i];
        printf("%s\n\n", ConcatRemove(s,t,k));
        i++;
    };
    return 0;
}

```

Please go to: https://onlinegdb.com and run the full code there.
