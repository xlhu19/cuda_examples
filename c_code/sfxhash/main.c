#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "sfxhash.h"

#define MAX_SIZE           (1024 * 8)

/* key struct for the sfxhash */
struct frag_key
{
	u_int32_t sip;      /* src IP */
	u_int32_t dip;      /* dst IP */
	u_int16_t id;       /* IP ID */
	u_int8_t proto;     /* IP protocol */
};

struct frag_tracker
{
	u_int32_t sip;      /* src IP */
	u_int32_t dip;      /* dst IP */
};

static SFXHASH *frag_cache = NULL;    /*FragTracker sfxhash table*/

static int frag_auto_free(void* key, void* data)
{
	return 0;
}

static int frag_user_free(void* key, void* data)
{
	return 0;
}

int main()
{
	int table_size;
	int frag_tracker_mem;
	int table_mem;
	int max_mem;
	int i;
	SFXHASH_NODE *hnode;
	struct frag_key fkey;
	struct frag_tracker* da;
	char* tmp;

	/*calculate the table size*/
	table_size = MAX_SIZE * 1.4;
	/*calculate the mam_mem for memcap*/
	frag_tracker_mem = MAX_SIZE * (sizeof(SFXHASH_NODE) + sizeof (struct frag_key)
			 + sizeof(struct frag_tracker) + sizeof(long));
	table_mem = (table_size + 1) * sizeof(SFXHASH_NODE *);
	max_mem = frag_tracker_mem + table_mem;
#if 1
	printf("===== table_size == %d\n", table_size);
	printf("===== max_mem == %d\n", max_mem);
#endif
	frag_cache = sfxhash_new(
		table_size,                  /* number of hash buckets */
		sizeof(struct frag_key),     /* size of the key we're going to use */
		sizeof(struct frag_tracker), /* size of the storage node */
		max_mem,                     /* memcap for frag trackers */
		1,                           /* use auto node recovery when oom*/
		frag_auto_free,              /* anr free function */
		frag_user_free,              /* user free function */
		1);                          /* recycle node flag, free node list*/

	for (i = 0; i < 10; i++)
	{
		fkey.sip = i;
		fkey.dip = 1;
		fkey.id = 1;
		fkey.proto = 1;
	
		hnode = sfxhash_get_node(frag_cache, &fkey);
		if (hnode == NULL)
			printf("===== not find hnode\n");
		else
		{
			printf("===== hnode->rindex == %d\n", hnode->rindex);
		}
		((struct frag_tracker*) (hnode->data) )->dip = i*5;
	}

	fkey.sip = 2;
	fkey.dip = 1;
	fkey.id = 1;
	fkey.proto = 1;
	da = (struct frag_tracker*) sfxhash_find(frag_cache, &fkey);
	if (da)
	{
		printf("===== da->dip == %d\n", ((struct frag_tracker*) da)->dip);
	}

	tmp = malloc(1024*16);
	if (tmp == NULL)
	{
		printf("malloc error\n");
	}
	free(tmp);

	sfxhash_delete(frag_cache);

	return 0;
}
