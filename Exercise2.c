#include <stdio.h>
#include <stdlib.h>

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
    
    // We get the size of each string. 
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
