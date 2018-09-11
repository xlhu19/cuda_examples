
#include <stdio.h>
#include <string.h>
#include "list.h"

struct test_abc
{
	struct list_head list;
	int port;
};

int main(void)
{
	struct list_head head;
	struct test_abc tmp_a;
	struct test_abc tmp_b;
	struct test_abc tmp_c;
	struct test_abc* tmp_p;
	struct list_head *p;

	int i;

	INIT_LIST_HEAD(&head);

	if (list_empty(&head))
		printf("list empty\n");

	tmp_a.port = 19;
	tmp_b.port = 11;
	tmp_c.port = 03;

	list_add(&tmp_a.list, &head);
	list_add(&tmp_b.list, &head);
	list_add(&tmp_c.list, &head);

	//list_del(&tmp_b.list);
	list_for_each(p, &head)
	{
		tmp_p = list_entry(p, struct test_abc, list);
		printf("%d\n", tmp_p->port);
	}

	return 0;
}
