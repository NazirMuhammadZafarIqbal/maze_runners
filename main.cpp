#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <chrono>
#include <thread>
#include <sys/time.h>


//matrix size
const int n = 10;
const int m = 10;

//Random number generation based on time (not final)
double random(double r){
  timeval t1;
  gettimeofday(&t1, NULL);
  std::srand(t1.tv_usec * t1.tv_usec * t1.tv_sec); 
        r = (float) rand()/RAND_MAX;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
  return r;
}

//print matrix
template<typename T>
void printMaze(T mat, std::size_t N, std::size_t M) {
    for(int i = 0 ; i < N ; ++i) {
        for(int j = 0 ; j < N; ++j)
            std::cout<< *(*(mat+i)+j)<<" ";
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}



int main()
{
  //initialize matrix
  double r = random(0);
  char matrix[n][m];
  
  //Matrix generation   <x : wall>   <o : space>  <s : start>  <e : exit>
  for (int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      r = random(0);
      // std::cout << r << std::endl;
      if (j == 0 or j == m-1 or i == 0 or i == n-1){       
        matrix[i][j] = 'x';               //Generate outer walls
      }
      else{                               
        if (r > 0.5){
          matrix[i][j] = 'x';             
        }                                //Generate inner structure
        else{
          matrix[i][j] = 'o';
        }
      }
    }
  }

  int exit = random(0) / 0.1;
  matrix[0][exit] = 'e';
                                        //Generate exit and startpoint
  int start = random(0) / 0.1;
  matrix[n-1][start] = 's';

  // (fix it later : 0 and m shouldnt be starting or exit point)


  printMaze(matrix,n,m);
  return 0;
}




//Next steps:
//-Make sure the maze is "walkable" (you can go from 's' to 'e')
//-Structurize walls (walls cant be next to each other, there are no holes, no pointless space)
//-Optimalize generation (to look more like a normal maze)
//-Optimalize random generation (make it faster and more random)
