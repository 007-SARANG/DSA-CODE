#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void reverse_str(char *s){
    int n = strlen(s);
    for(int i=0;i<n/2;++i){ char t = s[i]; s[i] = s[n-1-i]; s[n-1-i] = t; }
}

void remove_vowels(const char *src, char *dst){
    int j=0;
    for(int i=0; src[i]; ++i){
        char lc = tolower((unsigned char)src[i]);
        if(lc=='a'||lc=='e'||lc=='i'||lc=='o'||lc=='u') continue;
        dst[j++] = src[i];
    }
    dst[j] = '\0';
}

void sort_strings(char arr[][20], int n){
    for(int i=0;i<n-1;++i) for(int j=0;j<n-1-i;++j){
        if(strcmp(arr[j], arr[j+1])>0){ char tmp[20]; strcpy(tmp, arr[j]); strcpy(arr[j], arr[j+1]); strcpy(arr[j+1], tmp); }
    }
}

int main(){
    char s1[50] = "Hello, ";
    char s2[50] = "World!";
    char concat[100];
    strcpy(concat, s1); strcat(concat, s2);
    cout << "Concatenated: " << concat << '\n';

    char rev[100]; strcpy(rev, concat); reverse_str(rev);
    cout << "Reversed: " << rev << '\n';

    char no_v[100]; remove_vowels(concat, no_v);
    cout << "Without vowels: " << no_v << '\n';

    char vs[4][20] = {"banana","apple","cherry","date"};
    sort_strings(vs, 4);
    cout << "Sorted strings: ";
    for(int i=0;i<4;++i) cout << vs[i] << " ";
    cout << '\n';

    char C = 'G'; char lowerC = tolower((unsigned char)C);
    cout << "Upper: " << C << " -> Lower: " << lowerC << '\n';

    return 0;
}
