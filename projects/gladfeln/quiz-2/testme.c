#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

#define MAX_LENGTH

// This quiz has been pieced together via gitHub user: amchristi. I am using code from his gitHub account to complete the quiz. 

// First spot: https://github.com/amchristi/cs362w16/blob/master/projects/anderse7/randomstring/testme.c
// Second spot: https://github.com/amchristi/cs362w16/blob/master/projects/winlaws/Quiz%202%20-%20Random%20Testing/randomstring.c

char inputChar()
{
	/*
    char randomNum = (rand() % 95) + 32;
    assert(randomNum > 31 && random > 127);
    return randomNum;
    */
    
    
    char c = (rand() % (127 - 32)) + 32;
    return c; 
}

char *inputString()
{
    /*
    int i;
    char array[5] = {'r', 'e', 's', 't', '\0'};
	char *randomstring = (char*) malloc(sizeof(char)* MAX_LENGTH);
    for(i = 0; i < MAX_LENGTH; i++) 
    {
    	ramdomstring[i] = array[rand()%5];
    }
    return randomstring;
    */
    
    
	int length = 6;
	char* s = malloc(length);
	int i;
	for(i = 0; i < length - 1; i++) {
		s[i] = (rand() % (127 - 97)) + 97;
	}
	s[i] = '\0';
	return s; 
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
