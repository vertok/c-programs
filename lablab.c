#include<curses.h>
#include<stdio.h>
#define n 30
//enum Direction { DOWN, RIGHT, UP, LEFT }; zamenil na int directions[4];
//bool ne rabotaet.
void mazeTraversal( int [][ n ], const int, const int, int, int, int);
void printMaze();
int checkWays(int,int);
int validMove(int, int );
int coordsAreEdge( int, int );
   int XY[200][2];
   int k=0;int out=1; int cross1;
   int directions[4]={1,2,3,4};
   int matrix[n][n]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                     {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                     {1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                     {1,1,0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                     {1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                     {1,1,1,1,1,1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1},
                     {1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
                     {1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
                     {1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
                     {1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                     {1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                     {1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                     {1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1},
                     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1},
                     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1},
                     {1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
                     {1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                     {1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                     {1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                     {1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                     {1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                     {1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                     {1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1},
                     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
                     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
                     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
                     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
                     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
                     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1}};
int main()
{
  int xStart = 2; // starting X and Y coordinates for maze
  int yStart = 0;
  int x = xStart; // current X and Y coordinates
  int y = yStart;
  mazeTraversal( matrix, xStart, yStart, x, y, 1 );
 
  getch();                
  return 0;
}
void mazeTraversal( int matrix[n][ n ], const int xStart, const int yStart,int xCoord, int yCoord, int direction )
{
    int flag=1;
     if(cross(xCoord,yCoord)==0)cross1++;
     matrix[ xCoord ][ yCoord ] =5;
     XY[k][0]=xCoord;
     XY[k][1]=yCoord;
     k++;
     printMaze();
     printf("%d",cross1);
     if ( coordsAreEdge( xCoord, yCoord )==0) 
       {
         printf("\nI AM OUT OF THIS SHIT! x=%d y=%d\n\n",xCoord,yCoord);
         out=0;
         int p=0;
         for(p=0;XY[p][0]!=0&&XY[p][1]!=0;p++)
         {
           printf("x=%d y=%d\n",XY[p][0],XY[p][1]);
         }
         return; // maze is complete
       }
     else if ( (xCoord == xStart) && (yCoord == yStart) && (flag == 0)) //zachem zdes' flag?
       {
         printf("\nBASTAN GERI DONDUK\n\n");
         return;
       }
     else 
       {
         flag = 0;
 
// for loop uses switch to determine appropriate move 
         int move,count;
         for (move=direction,count=0;count<4;count++,move++,move%=4 )
           {
               switch( move ) 
                    {
                      case 4: // move down
                              if ( validMove(xCoord + 1, yCoord ) ==0) 
                               {
                                 printf("move DOWN\n");
                                 mazeTraversal(matrix, xStart, yStart, xCoord + 1, yCoord, 4);/*ya perebroboval vse varinaty, no rabtoaet tolko togda kogda 4(down) otprovlyayu*/
                                 
                                
                                } // end if
                      break;
                      case 1: // move right
                              if ( validMove(xCoord, yCoord + 1 ) ==0) 
                               {
                                   printf("move RIGHT\n");
                                 mazeTraversal(matrix, xStart, yStart, xCoord, yCoord + 1,4);
                                
                                 
                               } // end if
                      break;
                      case 3: // move up
                              if ( validMove(xCoord - 1, yCoord ) ==0) 
                               {printf("move UP\n");
                                 mazeTraversal(matrix, xStart, yStart, xCoord - 1, yCoord, 4 );
                                 
                                 
                               } // end if
                      break;
                      case 2: // move left
                              if ( validMove(xCoord, yCoord - 1 ) ==0) 
                                {printf("move LEFT\n");
                                  mazeTraversal(matrix, xStart, yStart, xCoord, yCoord - 1, 4);
                                  
                                  
                                 } // end if
                      break;
                      //default:
                            
                    } // end switch
           } // end for
       } // end else
       if(checkWays(xCoord,yCoord)==1)
     {
       k=cross1-1;
       int l;
         for(l=cross1;l<40;l++)
         {
            XY[l][0]=0;XY[l][1]=0;
         }
       cross1=0;
     }
}//end of mazTraversal
int validMove(int r, int c )
{
 if( r >= 0 && r <= n-1 && c >= 0 && c <= n-1 && matrix[ r ][ c ] == 0 )
   return 0;
 else
   return 1;
}//end of validMove
int coordsAreEdge( int x, int y )
{
if( y ==n-1)
return 0;
else
return 1;
} // end function coordsAreEdge
int checkWays(int x,int y)
{
     if ( (validMove(x+1,y)!=0)&&(validMove(x,y+1)!=0)&&(validMove(x-1,y)!=0)&&(validMove(x,y-1)!=0))
     return 1;
     else
     return 0;
   
}
int cross(int x,int y)
{
     int count1=0;
     if(validMove(x+1,y)==0)count1++;
     if(validMove(x,y+1)==0)count1++;
     if(validMove(x-1,y)==0)count1++;
     if(validMove(x,y-1)!=0)count1++;
     if(count1>1)return 0;
     else return 1;
}
void printMaze()
{
     int i,j;
  for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
    printf("%d",matrix[i][j]);
   printf("\n");
  } // end for
getch();
} // end function printMaze