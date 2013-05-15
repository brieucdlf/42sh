/*
** seg.c for seg in /home/delafob/delafo_b/SVN/42sh-2017-fritsc_h/tests
** 
** Made by Brieuc de La Fouchardière
** Login   <delafob@epitech.net>
** 
** Started on  Wed May  8 17:13:48 2013 Brieuc de La Fouchardière
** Last update Tue May 14 18:56:48 2013 Brieuc de La Fouchardière
*/

#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SEG_V		"Segmentation fault !\n"
#define PIP_E		"Pipe error !\n"
#define KILL_SIG	"KIll error !\n"
#define FLT		"Floating exeption !\n"
#define SIG_Q		"Quit error !\n"
#define BUS_SIG		"Bus error !\n"
#define INT_S		"INT_S !\n"
#define TRAP_S		"TRAP_S !\n"
#define	STP_S		"STP_S ! \n"

void	executing()
{
  char	*str;

  str[4097] = 'c';
  /*printf("%d", 1 / 0);*/
}

void 	sig_quit(int sig)
{
  write(2, SIG_Q, strlen(SIG_Q));  
}

void	pip_e(int sig)
{
  write(2, PIP_E, strlen(PIP_E));
  return ;
}

void	seg_v(int sig)
{
  write(2, SEG_V, strlen(SEG_V));
}

void	sig_fpe(int sig)
{
  write(2, FLT, strlen(FLT));
}

void	sig_kill(int sig)
{
  write(2, KILL_SIG, strlen(KILL_SIG));
}

void	sig_bus(int sig)
{
  write(2, BUS_SIG, strlen(BUS_SIG));
}

void	int_sig(int sig)
{
  write(2, INT_S, strlen(INT_S));
}

void	trap_sig(int sig)
{
  write(2, TRAP_S, strlen(TRAP_S));
}

void	stp_sig(int sig)
{
  write(2, STP_S, strlen(STP_S));
}

void	call_all_sig()
{
  signal(SIGINT, int_sig);
  signal(SIGTSTP, trap_sig);
  signal(SIGTRAP, trap_sig);
  signal(SIGQUIT, sig_quit);
  signal(SIGKILL, sig_kill);
  signal(SIGBUS, sig_bus);
  signal(SIGSEGV, seg_v);
  signal(SIGPIPE, pip_e);
  signal(SIGFPE, sig_fpe);
}

void	chk_command()
{
  pid_t	pid;
  int	status;

  if ((pid = fork()) == -1)
    {
      printf("Fork failed\n");
      exit(1);
    }
  if (pid == 0)
    executing();
  else
    wait(&status);
  return ;
}

int	main(int ac, char **av)
{
  call_all_sig();
  chk_command();
  return (0);
}
