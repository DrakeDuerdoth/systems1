#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

const int TEXT_LEN = 16;

const int NUM_SECS_TO_RUN = 30;

#define PROGNAME "selfCaller"

int numTimesCalled[3] = {0,0,0};

pid_t pidToSignal = -1;

pid_t childPid = -1;

int level = +2;

int shouldRun = 1;

void sigAlarmHandler( int sig ) {

  printf("Process %d: called level 0\n", level);
  alarm(rand() % 10 + 1);
  numTimesCalled[0] += 1;
  if (level != 2) kill(getppid(), SIGUSR1);
}

void usr1Handler(int sig) {
  printf("Process %d: called level 1\n", level);
  numTimesCalled[1] += 1;
  if (level != 2) kill(getppid(), SIGUSR2);
}

void usr2Handler(int sig) {
  printf("Process %d: called level 2\n", level);
  numTimesCalled[2] += 1;
}

void intHandler(int sig) {
  shouldRun = 0;
}

int main(int argc, char*argv[])
{
  srand(getpid());

  struct sigaction var1;

  memset(&var1, '\0', sizeof(var1));

  var1.sa_handler = sigAlarmHandler;
  sigaction(SIGALRM, &var1, NULL);

  var1.sa_handler = usr1Handler;
  sigaction(SIGUSR1, &var1, NULL);

  var1.sa_handler = usr2Handler;
  sigaction(SIGUSR2, &var1, NULL);

  var1.sa_handler = intHandler;
  sigaction(SIGINT, &var1, NULL);


  if (argc > 1) level = strtol(argv[1], NULL, 10);
  else level = 2;

  if (level > 0) {

    if ((childPid = fork()) == 0) {
      char text[TEXT_LEN];
      snprintf(text,TEXT_LEN,"%d",level-1);
      execl(PROGNAME, PROGNAME, text, NULL);
      fprintf(stderr,"Cannot find %s\n",PROGNAME);
      exit(EXIT_FAILURE);
    }
  }

  signal(SIGALRM, sigAlarmHandler);
  alarm(rand() % 10 +1);
  
  

  if(level == 2){
    int i;
    for(i = 0; i < NUM_SECS_TO_RUN; i++)
      {
	sleep(1);
      }
  }
  else{
      pidToSignal= getppid();
      while  (shouldRun)
	{
	  sleep(1);
	}
    }

  if (childPid > 0){
    kill(childPid, SIGINT);
    wait(NULL);
  }

  printf("Level %d: %d %d %d\n",level,
	 numTimesCalled[0],numTimesCalled[1],numTimesCalled[2]
	 );

  return(EXIT_SUCCESS);
}
