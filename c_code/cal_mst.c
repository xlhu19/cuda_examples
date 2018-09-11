

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


#define P_NUM              6
#define V_MAX              0xffff

unsigned int g_vexs[P_NUM];
unsigned int g_arcs[P_NUM][P_NUM];

void graphic_init(void)
{
	/*
	2-----------5
	|\         /|
	| \       / |
	|  \     /  |
	|   \   /   |
	|    \ /    |
	0-----3     |
	|    / \    |
	|   /   \   |
	|  /     \  |
	| /       \ |
	|/         \|
	4-----------1
	*/
	int i, j;
	for (i = 0; i < P_NUM; i++)
		g_vexs[i] = i;
	for (i = 0; i < P_NUM; i++)
		for (j = 0; j < P_NUM; j++)
			g_arcs[i][j] = V_MAX;
	g_arcs[0][2] = 2;
	g_arcs[0][3] = 3;
	g_arcs[0][4] = 4;
	g_arcs[1][3] = 2;
	g_arcs[1][4] = 3;
	g_arcs[1][5] = 4;
	g_arcs[2][0] = 2;
	g_arcs[2][3] = 1;
	g_arcs[2][5] = 3;
	g_arcs[3][0] = 3;
	g_arcs[3][1] = 2;
	g_arcs[3][2] = 1;
	g_arcs[3][4] = 1;
	g_arcs[3][5] = 2;
	g_arcs[4][0] = 4;
	g_arcs[4][1] = 3;
	g_arcs[4][3] = 1;
	g_arcs[5][1] = 4;
	g_arcs[5][2] = 3;
	g_arcs[5][3] = 2;
}

#define ADJVEXS 0
#define LOWCOST 1

int find_min(unsigned int* arg, unsigned int len)
{
	int i, lo = 0;
	unsigned int* data = arg;
	unsigned int tmp = V_MAX;

	for (i = 0; i < len; i++)
	{
		if ((data[i] >= tmp) || (data[i] == 0))
		{
			continue;
		}
		else
		{
			tmp = data[i];
			lo = i;
		}
	}
	return lo;
}

int main()
{
	int i, j, m, tmp = V_MAX, min_lo;
	unsigned int closedge[2][P_NUM];
	graphic_init();

	memset(&(closedge[ADJVEXS][0]), 0, P_NUM * sizeof(unsigned int));
	memcpy(&(closedge[LOWCOST][0]), &(g_arcs[0][0]), P_NUM * sizeof(unsigned int));
	closedge[LOWCOST][0] = 0;

	for (i = 0; i < P_NUM - 1; i++)
	{
#if 0
		for (m = 0; m < P_NUM; m++)
		{
			printf("%5d  ", closedge[ADJVEXS][m]);
		}
		printf("\n");
		for (m = 0; m < P_NUM; m++)
		{
			printf("%5d  ", closedge[LOWCOST][m]);
		}
		printf("\n");
#endif
		min_lo = find_min(closedge[LOWCOST], P_NUM);
		closedge[LOWCOST][min_lo] = 0;
//		printf("min_lo %d\n", min_lo);
		printf("%d-------->%d\n", 
			closedge[ADJVEXS][min_lo], g_vexs[min_lo]);

		for (j = 0; j < P_NUM; j++)
		{
			if (closedge[LOWCOST][j] == 0)
				continue;
			if (closedge[LOWCOST][j] > g_arcs[min_lo][j])
			{
				closedge[LOWCOST][j] = g_arcs[min_lo][j];
				closedge[ADJVEXS][j] = min_lo;
			}
		}
	}
	return 0;
}
