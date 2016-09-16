#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define INCSIZE 1
#define LOOPSIZE 2000000
int race = 0;
void* subtractor(void * args){
  
  int i =0;
  for(i;i<LOOPSIZE;i++){
    race -= INCSIZE;
  }
  return NULL;

}
void* adder(void* args){
  int i =0;
  for(i;i<LOOPSIZE;i++){
    race += INCSIZE;
  }
  return NULL;
}

int main(int argc, char** argv){
  pthread_t id1,id2,id3,id4;
  int test;
  printf("race is %d\n",race);
  test = pthread_create(&id1,NULL,adder,NULL);//adder();
  printf("race is %d\n",race);
  //adder();
  test = pthread_create(&id2,NULL,subtractor,NULL);//adder();
  printf("race is %d\n",race);
  //subtractor();
  test = pthread_create(&id3,NULL,adder,NULL);//adder();
  printf("race is %d\n",race);
  //subtractor();
  test = pthread_create(&id4,NULL,subtractor,NULL);//adder();
  printf("race is %d\n",race);

  test = pthread_join(id1,NULL);
  test = pthread_join(id2,NULL);
  test = pthread_join(id3,NULL);
  test = pthread_join(id4,NULL);


  return 0;
}
