
//#define TIMER_KERNEL

#ifdef TIMER_KERNEL

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/version.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/timer.h>
#include <linux/delay.h>
#include <linux/wait.h>

#define MON_TIMER_INTERVAL 3

struct timer_list ge_timer;

int handle_timer()
{
	printk("timer\n");
	mod_timer(&ge_timer, jiffies + MON_TIMER_INTERVAL * HZ);
	return 0;
}

int main()
{
	init_timer(&ge_timer);
	ge_timer.function = handle_timer;
	ge_timer.expires = jiffies + 10 * HZ;
	add_timer(&ge_timer);

	sleep(100);
	del_timer(&ge_timer);
}

#else

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <signal.h>

int count = 0;

void set_timer()
{
	struct itimerval itv, oldtv;
	itv.it_interval.tv_sec = 5;
	itv.it_interval.tv_usec = 0;
	itv.it_value.tv_sec = 5;
	itv.it_value.tv_usec = 0;
	
	setitimer(ITIMER_REAL, &itv, &oldtv);
}

void sigalrm_handler(int sig)
{
	count++;
	printf("timer signal.. %d\n", count);
}

int main()
{
	signal(SIGALRM, sigalrm_handler);
	set_timer();
	while (count < 1000)
	{}
	exit(0);
}

#endif
