#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    /* 0 -> turtle, 1 -> hare */
    int turn = 0;
    int i = 0;
    int j;
    char uppercaseC;
    int A = 0;
    int B = 0;
    int Y = 0;
    int hi = 0;
    int yes  = 0;
    int hFences = 8;
    int tFences = 8;
    int hfenceR=50;
    int vfenceR=50;
    char hfenceCtemp;
    char vfenceCtemp;
    int vfenceC=50;
    int hfenceC=50;

    char line[256];
    int hareR = 0;
    int hareC = 3;
    int turtleR = 6;
    int turtleC = 3;

    if (argc <= 1)
    {
        return -1;
    }

    while (fgets(line, sizeof(line), file))
    {
        if (turn == 0)
        {
            
            if (line[0] == 'H' || line[0] == 'h')
            {
              tFences--;
                hfenceR = line[3];
                
                switch (hfenceR)
                {
                case '6':
                    hfenceR = 0;
                    break;
                case '5':
                    hfenceR = 1;
                    break;
                case '4':
                    hfenceR = 2;
                    break;
                case '3':
                    hfenceR = 3;
                    break;
                case '2':
                    hfenceR = 4;
                    break;
                case '1':
                    hfenceR = 5;
                    break;
                case '0':
                    hfenceR = 6;
                    break;
                }
                hfenceCtemp = line[2];
                uppercaseC = toupper(hfenceCtemp);
                switch (toupper(uppercaseC))
                {
                case 'A':
                    hfenceC = 0;
                    break;
                case 'B':
                    hfenceC = 1;
                    break;
                case 'C':
                    hfenceC = 2;
                    break;
                case 'D':
                    hfenceC = 3;
                    break;
                case 'E':
                    hfenceC = 4;
                    break;
                case 'F':
                    hfenceC = 5;
                    break;
                }
                if((hfenceR == vfenceR) && (hfenceC == vfenceC))
                {
                  continue;
                }
                turn = 1;
            }
            if (line[0] == 'V' || line[0] == 'v')
            {
            
              tFences--;
                vfenceR = line[3]-'0';
                switch (vfenceR)
                {
                case 6:
                    vfenceR = 0;
                    break;
                case 5:
                    vfenceR = 1;
                    break;
                case 4:
                    vfenceR = 2;
                    break;
                case 3:
                    vfenceR = 3;
                    break;
                case 2:
                    vfenceR = 4;
                    break;
                case 1:
                    vfenceR = 5;
                    break;
                case 0:
                    vfenceR = 6;
                    break;
                }
                vfenceCtemp = line[2];
            uppercaseC = toupper(vfenceCtemp);
                switch (toupper(uppercaseC))
                {
                case 'A':
                    vfenceC = 0;
                    break;
                case 'B':
                    vfenceC = 1;
                    break;
                case 'C':
                    vfenceC = 2;
                    break;
                case 'D':
                    vfenceC = 3;
                    break;
                case 'E':
                    vfenceC = 4;
                    break;
                case 'F':
                    vfenceC = 5;
                    break;
                }
            if((hfenceR == vfenceR) && (hfenceC == vfenceC))
                {
                  continue;
                }
                turn = 1;
        }
        if (line[0] == 'N' || line[0] == 'n')
        {
        if(turtleR == hfenceR && turtleC == hfenceC)
        {
        turtleR--;
                    turn = 1;
                    continue;
        }
            else if((turtleR == hfenceR) && (((turtleC == hfenceC) || (turtleC == hfenceC+1) )))
        {
        
        continue;
        }
            if ((turtleR == 0 || (hfenceR == (turtleR - 1))) && ((hfenceC == turtleC) || (hfenceC == (turtleC - 1))))
            {
            
                continue;
            }
            
            else
            {
                if ((hareR == (turtleR - 1)) && ((turtleR - 2) != 0) && (hareC == turtleC))
                {
                if(line[1] == 'W' || line[1] == 'w')
            {
            if(((hareR-1) == hfenceR) && ((hfenceC == hareC) || (hfenceC == (hareC-1))))
            {
              turtleR--;
              turtleC--;
              turn = 1;
              continue;
            }
            }
            if(line[1] == 'E' || line[1] == 'e')
            {
            if(((hareR-1) == hfenceR) && ((hfenceC == hareC) || (hfenceC == (hareC-1))))
            {
              turtleR--;
              turtleC++;
              turn = 1;
              continue;
            }
            }
            else{
                    turtleR = turtleR - 2;
                    turn = 1;
                    continue;
                    }
                }
                else
                {
                    turtleR--;
                    turn = 1;
                    continue;
                }
            }
        }
        if (line[0] == 'S' || line[0] == 's')
        {
        if((turtleR == hfenceR) && ((turtleC == hfenceC) || (turtleC == hfenceC+1) ))
        {
        continue;
        }
             if (turtleR == 6 || ((hfenceR == (turtleR + 1)) && ((hfenceC == turtleC) || (hfenceC == (turtleC + 1)))))
            {
                continue;
            }
            else
            {
                if ((hareR == (turtleR + 1)) && ((turtleR + 2) != 6) && (hareC == turtleC))
                {
                 if(line[1] == 'W' || line[1] == 'w')
            {
            if((((hareR+1) == hfenceR) || hareR ==hfenceR ) && ((hfenceC == turtleC) || (hfenceC == (hareC+1))))
            {
              turtleR++;
              turtleC--;
              turn = 1;
              continue;
            }
            }
            if(line[1] == 'E' || line[1] == 'e')
            {
            if((((hareR-1) == hfenceR) || hareR == hfenceR ) && ((hfenceC == turtleC) || (hfenceC == (hareC-1))))
            {
              turtleR++;
              turtleC++;
              turn = 1;
              continue;
            }
            }
            else{
                    turtleR = turtleR + 2;
                    turn = 1;
                    continue;
                    }
                }
                else
                {
                    turtleR++;
                    turn = 1;
                    continue;
                }
            }
        }
        if (line[0] == 'W' || line[0] == 'w')
        {
        if((turtleR == vfenceR) && ((turtleC == vfenceC) || (turtleC == vfenceC+1) ))
        {
        continue;
        }
            if ((turtleC == 0 || (vfenceC == (turtleC - 1))) && ((vfenceR == turtleR) || (vfenceR == (turtleR + 1))))
            {
              
                continue;
            }
            if((turtleC == vfenceC) && (turtleR == vfenceR))
            {
            
            continue;
            }
            
            else
            {
                if ((hareC == (turtleC - 1)) && ((turtleC - 2) != 0) && hareR == turtleR)
                {
                    turtleC = turtleC - 2;
                    turn = 1;
                    continue;
                }
                else
                {
                    turtleC--;
                    turn = 1;
                    continue;
                }
            }
        }
        if (line[0] == 'E' || line[0] == 'e')
        {
        if((turtleR == vfenceR) && ((turtleC == vfenceC) || (turtleC == vfenceC+1) ))
        {
        continue;
        }
            if ((turtleC == 6 || (vfenceC == (turtleC + 1))) && ((vfenceR == turtleR) || (vfenceR == (turtleR - 1))))
            {
                continue;
            }
            if((turtleC == vfenceC) && (turtleR == vfenceR || turtleR == (vfenceR+1)))
            {
            continue;
            }
            else
            {
                if ((hareC == (turtleC + 1)) && ((turtleC + 2) != 6) && hareR == turtleR)
                {
                    turtleC = turtleC + 2;
                    turn = 1;
                    continue;
                }
                else
                {
                    turtleC++;
                    turn = 1;
                    continue;
                }
            }
        }
        }

       else if (turn == 1)
        {
        if (line[0] == 'H' || line[0] == 'h')
            {
              hFences--;
                hfenceR = line[3];
                switch (hfenceR)
                {
                case '6':
                    hfenceR = 0;
                    break;
                case '5':
                    hfenceR = 1;
                    break;
                case '4':
                    hfenceR = 2;
                    break;
                case '3':
                    hfenceR = 3;
                    break;
                case '2':
                    hfenceR = 4;
                    break;
                case '1':
                    hfenceR = 5;
                    break;
                case '0':
                    hfenceR = 6;
                    break;
                }
                hfenceCtemp = line[2];
                uppercaseC = toupper(hfenceCtemp);
                switch (toupper(uppercaseC))
                {
                case 'A':
                    hfenceC = 0;
                    break;
                case 'B':
                    hfenceC = 1;
                    break;
                case 'C':
                    hfenceC = 2;
                    break;
                case 'D':
                    hfenceC = 3;
                    break;
                case 'E':
                    hfenceC = 4;
                    break;
                case 'F':
                    hfenceC = 5;
                    break;
                }
                if((hfenceR == vfenceR) && (hfenceC == vfenceC))
                {
                  continue;
                }
                turn = 0;
            }
            if (line[0] == 'V' || line[0] == 'v')
            {
            hFences--;
                vfenceR = line[3];
                switch (vfenceR)
                {
                case 6 :
                    vfenceR = 0;
                    break;
                case 5 :
                    vfenceR = 1;
                    break;
                case 4 :
                    vfenceR = 2;
                    break;
                case 3 :
                    vfenceR = 3;
                    break;
                case 2 :
                    vfenceR = 4;
                    break;
                case 1 :
                    vfenceR = 5;
                    break;
                case 0 :
                    vfenceR = 6;
                    break;
                }
                vfenceCtemp = line[2];
            uppercaseC = toupper(vfenceCtemp);
           switch (toupper(uppercaseC))
                {
                case 'A':
                    vfenceC = 0;
                    break;
                case 'B':
                    vfenceC = 1;
                    break;
                case 'C':
                    vfenceC = 2;
                    break;
                case 'D':
                    vfenceC = 3;
                    break;
                case 'E':
                    vfenceC = 4;
                    break;
                case 'F':
                    vfenceC = 5;
                    break;
                }
            if((hfenceR == vfenceR) && (hfenceC == vfenceC))
                {
                  continue;
                }
                turn = 0;
        }
            if (line[0] == 'N' || line[0] == 'n')
            {
            if((hareR == hfenceR) && ((hareC == hfenceC) || (hareC == hfenceC-1) ))
        {
        continue;
        }
                 if ((hareR == 0 || (hfenceR == (hareR - 1))) && ((hfenceC == hareC) || (hfenceC == (hareC - 1))))
                {
                    continue;
                }
                else
                {
                    if ((turtleR == (hareR - 1)) && ((hareR - 2) != 0) && (hareC == turtleC))
                    {
                    if(line[1] == 'W' || line[1] == 'w')
            {
            if(((turtleR-1) == hfenceR) && ((hfenceC == hareC) || (hfenceC == (turtleC-1))))
            {
              hareR--;
              hareC--;
              turn = 1;
              continue;
            }
            }
            if(line[1] == 'E' || line[1] == 'e')
            {
            if(((turtleR-1) == hfenceR) && ((hfenceC == hareC) || (hfenceC == (turtleC-1))))
            {
              hareR--;
              hareC++;
              turn = 1;
              continue;
            }
            }
            else{
                        hareR = hareR - 2;
                        turn = 0;
                        continue;
                        }
                    }
                    else
                    {
                        hareR--;
                        turn = 0;
                        continue;
                    }
                }
            }
            if (line[0] == 'S' || line[0] == 's')
            {
            if((hareR == hfenceR) && ((hareC == hfenceC) || (hareC == hfenceC-1) ))
        {
        continue;
        }
                 if ((hareR == 6 || (hfenceR == (hareR + 1))) && (hfenceC != turtleC) && (hfenceR != turtleR) && ((hfenceC == hareC) || (hfenceC == (hareC + 1))))
                {

                    continue;
                }
                else
                {
                
                    if ((turtleR == (hareR + 1)) && ((hareR + 2) != 6) && (hareC == turtleC))
                    {
                    
                    if(line[1] == 'W' || line[1] == 'w')
            {
            
            if((((turtleR+1) == hfenceR) || turtleR ==hfenceR ) && ((hfenceC == hareC) || (hfenceC == (turtleC+1))))
            {
            
              hareR++;
              hareC--;
              turn = 1;
              continue;
            }
            }
            if(line[1] == 'E' || line[1] == 'e')
            {
            if((((turtleR-1) == hfenceR) || turtleR == hfenceR ) && ((hfenceC == hareC) || (hfenceC == (turtleC-1))))
            {
              hareR++;
              hareC++;
              turn = 1;
              continue;
            }
            }
            else{
                        hareR = hareR + 2;
                        turn = 0;
                        continue;
                        }
                    }
                    else
                    {
                        hareR++;
                        turn = 0;
                        continue;
                    }
                }
            }
            if (line[0] == 'W' || line[0] == 'w')
            {
            if((hareR == vfenceR) && ((hareC == vfenceC) || (hareC == vfenceC+1) ))
        {
        continue;
        }
            
                if (hareC == 0 || ((vfenceC == (hareC - 1)) && (vfenceR == hareR)) || (vfenceR == (hareR + 1)))
                {
                    continue;
                }
                if((hareC == vfenceC) && (hareR == vfenceR || hareR == (vfenceR+1)))
            {
            continue;
            }
                else
                {
                    if ((turtleC == (hareC - 1)) && ((hareC - 2) != 0) && hareR == turtleR)
                    {
                        hareC = hareC - 2;
                        turn = 0;
                        continue;
                    }
                    else
                    {

                        hareC--;
                        turn = 0;
                        continue;
                    }
                }
            }
            if (line[0] == 'E' || line[0] == 'e')
            {
            if((hareR == vfenceR) && ((hareC == vfenceC) || (hareC == vfenceC+1) ))
        {
        continue;
        }
                if ((hareC == 6 || (vfenceC == (hareC + 1))) && ((vfenceR == hareR) || (vfenceR == (hareR - 1))))
                {
                    continue;
                }
                if((hareC == vfenceC) && (hareR == vfenceR || hareR == (vfenceR+1)))
            {
            continue;
            }
                else
                {
                    if ((turtleC == (hareC + 1)) && ((hareC + 2) != 6) && hareR == turtleR)
                    {
                        hareC = hareC + 2;
                        turn = 0;
                        continue;
                    }
                    else
                    {
                        hareC++;
                        turn = 0;
                        continue;
                    }
                }
            }
        }
    }
    /*
    printf("%d\t",hareR);
    printf("%d\n",hareC);
    printf("%d\t",turtleR);
    printf("%d\n",turtleC);
    */
    printf("                     [N]\n\n");
    printf("            a   b   c   d   e   f\n            |   |   |   |   |   |\n");
    printf("        +---------------------------+\n");
    
    if ((hareR == i) || (turtleR == i))
    {
        printf("        | ");

        for (j = 0; j < 7; j++)
        {
        
         if(vfenceR ==i && vfenceC == j)
         {
           printf("  | ");

         }
         else{
            if (j == hareC && A == 0 && hareR == i)
            {
                if (((hareC + 1) == turtleC) && (hareR == turtleR))
                {
                    printf("H   ");
                    A = 1;
                }
                else
                {
                    printf("H");
                    A = 1;
                }
            }
            else if (j == turtleC && Y == 0 && turtleR == i)
            {
                printf("T");
                Y = 1;
            }
            else
            {
                printf("    ");
            }
            }
        }
        printf(" |\n");
    }
    else
    {
    if(((vfenceR == i) || ((vfenceR-1 == i))))
    {
    printf("        |   ");
      for (j = 0; j < 7; j++)
        {
            if (vfenceC == j)
            {
                printf("|");
            }
            else
            {
                printf("    ");
            }
        }
        printf("|\n");
    }
    else
        printf("        |                           |\n");
    }
    i++;
    /*
    printf("%d\n",hfenceR);
    */
    if (hfenceR == i - 1)
    {
        printf("     6--|");
        for (j = 0; j < 5; j++)
        {
            if (hfenceC == j)
            {
                printf("---+---+");
            }
            else
            {
                printf("   +");
            }
        }
        printf("   |--6        Player (H)\n");
    }
    else
    {
        printf("     6--|   +   +   +   +   +   +   |--6        Player (H)\n");
    }

    if ((hareR == i) || (turtleR == i))
    {
        printf("        | ");
        for (j = 0; j < 7; j++)
        {
            if (j == hareC && A == 0 && hareR == i)
            {
                if ((hareC + 1) == turtleC)
                {
                    printf("H   ");
                    A = 1;
                }
                else
                {
                    printf("H");
                    A = 1;
                }
            }
            else if (j == turtleC && Y == 0 && turtleR == i)
            {
                printf("T");
                Y = 1;
            }
            else
            {
                printf("    ");
            }
        }
        printf(" |           Fences - %d\n", hFences);
    }
        
    else
    {
     if(((vfenceR == i) || ((vfenceR-1 == i) || (vfenceR==i-1))))
    {

    printf("        |   ");
      for (j = 0; j < 7; j++)
        {
            if (vfenceC == j)
            {
                printf("|");
                yes = 1;
            }
            else if(yes == 0)
                printf("    ");
            else
              printf("   ");
        }
        printf("   |           Fences - 7\n");
    }
    else
        printf("        |                           |           Fences - %d\n", hFences);
    }
    i++;
    if (hfenceR == i - 1)
    {
        printf("     5--|");
        for (j = 0; j < 5; j++)
        {
            if (hfenceC == j)
            {
                printf("---+---+");
            }
            else
            {
                printf("   +");
            }
        }
        printf("   |--5        ==========\n");
    }
    else{
      printf("     5--|   +   +   +   +   +   +   |--5        ==========\n");
      
      }
      
    if ((hareR == i) || (turtleR == i))
    {
        printf("        | ");
        for (j = 0; j < 7; j++)
        {
            if (j == hareC && A == 0 && hareR == i)
            {
                if ((hareC + 1) == turtleC)
                {
                    printf("H   ");
                    A = 1;
                }
                else
                {
                    printf("H");
                    A = 1;
                }
            }
            else if (j == turtleC && Y == 0 && turtleR == i)
            {
                printf("T");
                Y = 1;
            }
            else
            {
                printf("    ");
            }
        }
        switch(hFences)
        {
          case 4 :
            printf(" |            | | | |\n");
            break;
          case 3 : 
            printf(" |            | | |\n");
            break;
          case 2 :
            printf(" |            | |\n");
            break;
          case 1 :
            printf(" |            |\n");
            break;
          case 0 :
            printf(" |\n");
            break; 
          default :
            printf(" |            | | | |\n");
            break;          
        }
        
    }
    else
    {
    if(((vfenceR == i) || ((vfenceR-1 == i))))
    {
    printf("        |   ");
      for (j = 0; j < 7; j++)
        {
            if (vfenceC == j)
            {
                printf("|");
            }
            else
            {
                printf("    ");
            }
        }
        switch(hFences)
        {
          case 4 :
            printf("|            | | | |\n");
            break;
          case 3 : 
            printf("|            | | |\n");
            break;
          case 2 :
            printf("|            | |\n");
            break;
          case 1 :
            printf("|            |\n");
            break;
          case 0 :
            printf("|\n");
            break; 
          default :
            printf("|            | | | |\n");
            break;          
        }
    }
    else
    {
    printf("        |                          ");
        switch(hFences)
        {
          case 4 :
            printf(" |            | | | |\n");
            break;
          case 3 : 
            printf(" |            | | |\n");
            break;
          case 2 :
            printf(" |            | |\n");
            break;
          case 1 :
            printf(" |            |\n");
            break;
          case 0 :
            printf(" |\n");
            break; 
          default :
            printf(" |            | | | |\n");
            break;          
        }
        }
    }
    
    i++;
    if (hfenceR == i - 1)
    {
        printf("     4--|");
        for (j = 0; j < 5; j++)
        {
            if (hfenceC == j)
            {
                printf("---+---+");
                hi = 1;
            }
            else
            {
                printf("   +");
            }
        }
        if(hi == 1)
        {
        printf("  ");
        }
        switch(hFences)
        {
          case 8 :
            printf(" |            | | | |\n");
            break;
          case 7 : 
            printf(" |            | | |\n");
            break;
          case 6 :
            printf(" |            | |\n");
            break;
          case 5 :
            printf(" |            |\n");
            break;
          case 4 :
            printf(" |\n");
            break; 
          default :
            printf(" |            | | | |\n");
            break;        
        }
    }
    else{
    switch(hFences)
        {
          case 8 :
            printf("     4--|   +   +   +   +   +   +   |--4         | | | |\n");
            break;
          case 7 : 
            printf("     4--|   +   +   +   +   +   +   |--4         | | |\n");
            break;
          case 6 :
            printf("     4--|   +   +   +   +   +   +   |--4         | |\n");
            break;
          case 5 :
            printf("     4--|   +   +   +   +   +   +   |--4         |\n");
            break;
          case 4 :
            printf("     4--|   +   +   +   +   +   +   |--4\n");
            break; 
          default :
            printf("     4--|   +   +   +   +   +   +   |--4\n");
            break;        
        }
    }
    if ((hareR == i) || (turtleR == i))
    {
        printf("[W]     | ");
        for (j = 0; j < 7; j++)
        {
            if (hareR == turtleR)
            {
                if (j == hareC && A == 0 && hareR == i)
                {
                    if ((hareC + 1) == turtleC)
                    {
                        printf("H   ");
                        A = 1;
                        B = 1;
                    }
                    else
                    {
                        printf("H");
                        A = 1;
                    }
                }
                else if (j == turtleC && Y == 0 && turtleR == i)
                {
                    printf("T   ");
                    Y = 1;
                }
                else
                {
                    if (B == 1)
                    {
                        printf(" ");
                        B = 0;
                    }
                    else
                    {
                        printf("    ");
                    }
                }
            }
            else
            {
                if (j == hareC && A == 0 && hareR == i)
                {

                    printf("H");
                    A = 1;
                }
                else if (j == turtleC && Y == 0 && turtleR == i)
                {
                    printf("T");
                    Y = 1;
                }
                else
                {
                    printf("    ");
                }
            }
        }
        printf(" |     [E]\n");
    }
    else
    {
    if(((vfenceR == i) || ((vfenceR-1 == i))))
    {
    printf("[W]     |   ");
      for (j = 0; j < 7; j++)
        {
            if (vfenceC == j)
            {
                printf("|");
            }
            else
            {
                printf("    ");
            }
        }
        printf("|     [E]\n");
    }
    else
        printf("[W]     |                           |     [E]\n");
    }
    i++;
    if (hfenceR == i - 1)
    {
        printf("     3--|");
        for (j = 0; j < 5; j++)
        {
            if (hfenceC == j)
            {
                printf("---+---+");
            }
            else
            {
                printf("   +");
            }
        }
        printf("   |--3        Player (T)\n");
    }
    else{
    
    printf("     3--|   +   +   +   +   +   +   |--3        Player (T)\n");
    }
    if ((hareR == i) || (turtleR == i))
    {
        printf("        | ");
        for (j = 0; j < 7; j++)
        {
            if (j == hareC && A == 0 && hareR == i)
            {
                if ((hareC + 1) == turtleC)
                {
                    printf("H   ");
                    A = 1;
                }
                else
                {
                    printf("H");
                    A = 1;
                }
            }
            else if (j == turtleC && Y == 0 && turtleR == i)
            {
                printf("T");
                Y = 1;
                if(turtleC == hareC-1 && turtleR == hareR)
                {
                printf("   ");
                }
            }
            else
            {
                printf("    ");
            }
        }
        printf(" |           Fences - %d\n", tFences);
    }
    else
    {
        printf("        |                           |           Fences - %d\n", tFences);
    }
    i++;
    if (hfenceR == i - 1)
    {
        printf("     2--|");
        for (j = 0; j < 5; j++)
        {
            if (hfenceC == j)
            {
                printf("---+---+");
            }
            else
            {
                printf("   +");
            }
        }
        printf("   |--2        ==========\n");
    }
    else
    {
    printf("     2--|   +   +   +   +   +   +   |--2        ==========\n");
    }
    if ((hareR == i) || (turtleR == i))
    {
        printf("        | ");
        for (j = 0; j < 7; j++)
        {
            if (j == hareC && A == 0 && hareR == i)
            {
                if ((hareC + 1) == turtleC)
                {
                    printf("H   ");
                    A = 1;
                }
                else
                {
                    printf("H");
                    A = 1;
                }
            }
            else if (j == turtleC && Y == 0 && turtleR == i)
            {
                printf("T");
                Y = 1;
            }
            else
            {
                printf("    ");
            }
        }
        switch(tFences)
        {
          case 4 :
            printf(" |            | | | |\n");
            break;
          case 3 : 
            printf(" |            | | |\n");
            break;
          case 2 :
            printf(" |            | |\n");
            break;
          case 1 :
            printf(" |            |\n");
            break;
          case 0 :
            printf(" |\n");
            break; 
          default :
            printf(" |            | | | |\n");
            break;        
        }
    }
    else
    {
    if(((vfenceR == i) || ((vfenceR-1 == i))))
    {
    printf("        |   ");
      for (j = 0; j < 7; j++)
        {
            if (vfenceC == j)
            {
                printf("|");
            }
            else
            {
                printf("    ");
            }
        }
         switch(tFences)
        {
          case 4 :
            printf("|            | | | |\n");
            break;
          case 3 : 
            printf("|            | | |\n");
            break;
          case 2 :
            printf("|            | |\n");
            break;
          case 1 :
            printf("|            |\n");
            break;
          case 0 :
            printf("|\n");
            break; 
          default :
            printf("|            | | | |\n");
            break;          
        }
    }
    else
    {
    printf("        |                          ");
        switch(tFences)
        {
          case 4 :
            printf(" |            | | | |\n");
            break;
          case 3 : 
            printf(" |            | | |\n");
            break;
          case 2 :
            printf(" |            | |\n");
            break;
          case 1 :
            printf(" |            |\n");
            break;
          case 0 :
            printf(" |\n");
            break; 
          default :
            printf(" |            | | | |\n");
            break;          
        }
        }
    }
    i++;
     if (hfenceR == i - 1)
    {
        printf("     1--|");
        for (j = 0; j < 5; j++)
        {
            if (hfenceC == j)
            {
                printf("---+---+");
            }
            else
            {
                printf("   +");
            }
        }
        printf("   |--1         | | | |\n");
        switch(tFences)
        {
          case 8 :
            printf(" |            | | | |\n");
            break;
          case 7 : 
            printf(" |            | | |\n");
            break;
          case 6 :
            printf(" |            | |\n");
            break;
          case 5 :
            printf(" |            |\n");
            break;
          case 4 :
            printf(" |\n");
            break; 
          default :
            printf(" |\n");
            break;        
        }
    }
    else{
    switch(tFences)
        {
          case 8 :
            printf("     1--|   +   +   +   +   +   +   |--1         | | | |\n");
            break;
          case 7 : 
            printf("     1--|   +   +   +   +   +   +   |--1         | | |\n");
            break;
          case 6 :
            printf("     1--|   +   +   +   +   +   +   |--1         | |\n");
            break;
          case 5 :
            printf("     1--|   +   +   +   +   +   +   |--1         |\n");
            break;
          case 4 :
            printf("     1--|   +   +   +   +   +   +   |--n1\n");
            break; 
          default :
            printf("     1--|   +   +   +   +   +   +   |--1\n");
            break;        
        }
    }
    if ((hareR == i) || (turtleR == i))
    {
        printf("        | ");
        for (j = 0; j < 7; j++)
        {
            if (j == hareC && A == 0 && hareR == i)
            {
                if ((hareC + 1) == turtleC)
                {
                    printf("H   ");
                    A = 1;
                    B = 1;
                }
                else
                {
                    printf("H");
                    A = 1;
                }
            }
            else if (j == turtleC && Y == 0 && turtleR == i)
            {
                printf("T");
                Y = 1;
            }
            else
            {
                printf("    ");
            }
        }
        printf(" |\n");
    }
    else
    {
    if(((vfenceR == i) || ((vfenceR-1 == i))))
    {
    printf("        |   ");
      for (j = 0; j < 7; j++)
        {
            if (vfenceC == j)
            {
                printf("|");
            }
            else
            {
                printf("    ");
            }
        }
        printf("|\n");
    }
    else
        printf("        |                           |\n");
    }
    printf("        +---------------------------+\n            |   |   |   |   |   |\n            a   b   c   d   e   f\n\n                     [S]\n");
    if (hareR == 6)
    {
        printf("Hare wins!\n");
    }
    if (turtleR == 0)
    {
        printf("Tortoise wins!\n");
    }


    return 0;
}

