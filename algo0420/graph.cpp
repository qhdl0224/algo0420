
#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include "graph.h"
#include "stack.h"
#include "queue.h"

int check[MAX_VERTEX]; //Ž���� ���
/* �湮�� ������ 1�� �̹湮 ������ 0���� ���� */
						/*--------------------------------------------------------------------------------------
						�Լ��� �� ���: initGraph() - ���������Ͽ��� �׷����� ������ ���� ������ �Է� �޾� '
						�׷����� ���� ��Ĺ����� �ʱ�ȭ�ϴ� �Լ�
						��������:  gm - �׷��� ���� ����ü�� �ּ�
						fileName - �׷����� ���� �� ���� ������ ����� ������ ���ϸ�
						���ϰ�: ����
						--------------------------------------------------------------------------------------*/
void initGraph(GraphMatrix *gm, const char *fileName)
{
	char vertex[3];  /* �������� �Է��� ���� ���� "AB" ������ ������ ���� char �迭 */
	int i, j, k;       /* iterator */
	FILE *fp;        /* �׷��� ���� ���� ������ ���������� */

	fp = fopen(fileName, "rt");
	assert(fp != NULL);
	fscanf(fp, "%d %d\n", &gm->vertexCnt, &gm->edgeCnt);  /* ������ ������ ������ �б� */

	for (j = 0; j < gm->vertexCnt; j++)
	{
		for (k = 0; k < gm->vertexCnt; k++)
		{
			gm->graph[j][k] = 0;
		}
	}
	for (i = 0; i < gm->edgeCnt; i++)
	{
		fscanf(fp, "%s", vertex);
		//��Ī�� ���
		gm->graph[vertex[0] - 'A'][vertex[1] - 'A'] = 1;
		gm->graph[vertex[1] - 'A'][vertex[0] - 'A'] = 1;
	}
														  //TODO

	fclose(fp);
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: outputGraph() - �׷������� ������ ������ ���踦 ���� ��� ���·� ���
��������:  gm : �׷��� ���� ����ü�� �ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void outputGraph(GraphMatrix *gm)
{
	int i, j;         /* iterator */

					  /* ������ ���ι��� ��� */
	printf("   ");
	for (i = 0; i<gm->vertexCnt; ++i)
		printf("%3c", 'A' + i);

	NEWL;  // ���� ��ũ��

	for (i = 0; i<gm->vertexCnt; ++i)
	{
		printf("%3c", 'A' + i);
		for (j = 0; j<gm->vertexCnt; j++)
			printf("%3d", gm->graph[i][j]);
		NEWL;
	}
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: DFS_Matrix() - ���� ���� ���� ��ҷ� ������ �׷����� ���� �켱 Ž��
�ϱ� ���� �Լ�(�����)
��������:  gm : �׷��� ���� ����ü�� �ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void DFS_Matrix(GraphMatrix *gm)
{
	int i;
	for (i = 0; i<gm->vertexCnt; ++i)  /* ������ �湮���� ������ ������ check�迭 �ʱ�ȭ */
		check[i] = 0;
	for (i = 0; i<gm->vertexCnt; ++i)
		if (check[i] == 0)
			DFS_recursive(gm, i);
	return;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: DFS_recursive() - ����Ǿ��ִ� �ϳ��� �׷��� ���� ��� ������
���ȣ�������� �湮�ϴ� �Լ�
��������:  gm : �׷��� ���� ����ü�� �ּ�
vNum : �湮�ϰ��� �ϴ� ���� ��ȣ
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void DFS_recursive(GraphMatrix *gm, int vNum)
{
	
	//TODO

}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: visit() - �湮�� ������ ó���ϴ� �Լ�(�� �Լ������� �湮�� ������ ��� ��)
��������: vNum : �湮�ϰ��� �ϴ� ���� ��ȣ
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void visit(int vNum)
{
	printf("%3c", 'A' + vNum);
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: nrDFS_Matrix() - ���� ���� ���� ��ҷ� ������ �׷����� ���� �켱 Ž��
�ϱ� ���� �Լ�(�� �����)
��������:  gm : �׷��� ���� ����ü�� �ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void nrDFS_Matrix(GraphMatrix *gm)
{
	int popData;  /* pop�� ������ ���� */
	Stack stack;
	initStack(&stack);  /* ����� ó���� ���� ���� ���� �ʱ�ȭ */

	for (int i = 0; i < MAX_VERTEX; i++)
	{
		check[i] = 0;
	}

	for (int i = 0; i < gm->vertexCnt; i++)
	{
		if (check[i] == 0)
		{
			push(&stack, i);
			check[i] = 1;
			while (!isStackEmpty(&stack))
			{
				pop(&stack, &popData);
				visit(popData);
				for (int j = 0; j < gm->vertexCnt; j++)
				{
					if (gm->graph[popData][j] == 1 && check[j] == 0)
					{
						push(&stack, j);
						check[j] = 1;
					}
				}
				
			}
		}
	}
						//TODO
	destroyStack(&stack);
	return;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: nrBFS_Matrix() - ���� ���� ���� ��ҷ� ������ �׷����� �ʺ� �켱 Ž��
�ϱ� ���� �Լ�(�� �����)
��������:  gm : �׷��� ���� ����ü�� �ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void BFS_Matrix(GraphMatrix *gm)
{
	int i, j;
	int getData;  /* dequeue(get)�� ������ ���� */
	Queue queue;
	initQueue(&queue, MAX_VERTEX);  /* ť �ʱ�ȭ */

	for (int i = 0; i < MAX_VERTEX; i++)
	{
		check[i] = 0;
	}

	for (int i = 0; i < gm->vertexCnt; i++)
	{
		if (check[i] == 0)
		{
			enqueue(&queue, i);
			check[i] = 1;
			while (!isQueueEmpty(&queue))
			{
				dequeue(&queue, &getData);
				visit(getData);
				for (int j = 0; j < gm->vertexCnt; j++)
				{
					if (gm->graph[getData][j] == 1 && check[j] == 0)
					{
						enqueue(&queue, j);
						check[j] = 1;
					}
				}

			}
		}
	}

	destroyQueue(&queue);
	return;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: countGraphComponents() - ���� ��Ĺ����� ǥ��� �׷��� ���� ���� ��Һ���
�������� ����ϰ� ���� ����� ���� ����
��������:  gm : �׷��� ���� ����ü�� �ּ�
���ϰ�: �׷������� ���� ����� ����
--------------------------------------------------------------------------------------*/
int countGraphComponents(GraphMatrix *gm)
{
	int componetsCount = 0;  /* �׷��� ���� ���� ��� ī��Ʈ ���� */
	int i, j;
	int popData;  /* pop�� ������ ���� */
	Stack stack;
	initStack(&stack);  /* ����� ó���� ���� ���� ���� �ʱ�ȭ */


						//TODO


	destroyStack(&stack);
	return componetsCount;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: initGraph_L() - ���������Ͽ��� �׷����� ������ ���� ������ �Է� �޾� '
�׷����� ���� ����Ʈ������ �ʱ�ȭ�ϴ� �Լ�
��������:  g : �׷��� ���� ����ü�� �ּ�
fileName : �׷����� ���� �� ���� ������ ����� ������ ���ϸ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void initGraph_List(GraphList *g, const char *fileName)
{
	char vertex[3];  /* �������� �Է��� ���� ���� "AB" ������ ������ ���� char �迭 */
	int i, j, k;       /* iterator */
	FILE *fp;        /* �׷��� ���� ���� ������ ���������� */

	fp = fopen(fileName, "rt");
	assert(fp != NULL);
	fscanf(fp, "%d %d\n", &g->vertexCnt, &g->edgeCnt);  /* ������ ������ ������ �б� */

	//1. g->graph �迭 �ʱ�ȭ Null �����ͷ�
	for (i = 0; i < MAX_VERTEX; i++)
	{
		g->graph[i] = NULL;
	}
	//2. linkedlist ���·� node���� ����
	
	for (k = 0; k < g->edgeCnt; k++)
	{
		fscanf(fp, "%s", vertex);
		Node *tmp = (Node *)calloc(1, sizeof(Node));
		tmp->vertex = vertex[1] - 'A';
		tmp->next = g->graph[vertex[0] - 'A'];
		g->graph[vertex[0] - 'A'] = tmp;

		Node *tmp2 = (Node *)calloc(1, sizeof(Node));
		tmp2->vertex = vertex[0] - 'A'; 
		tmp2->next = g->graph[vertex[1] - 'A'];
		g->graph[vertex[1] - 'A'] = tmp2;
	}
	
	//TODO


	fclose(fp);
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: addNode() - �� ������ ���踦 ����Ʈ�� �����
��������:  g - �׷��� ���� ����ü�� �ּ�
vNum1 - ù��° ������ ��ȣ
vNum2 - �ι�° ������ ��ȣ
���ϰ�: ���� ����� �����ϸ� TRUE ����, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
int addNode(GraphList *g, int vNum1, int vNum2)
{

	//TODO

	return 0;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: outputGraph_L() - �׷������� ������ ������ ���踦 ���� ����Ʈ ���·� ���
��������:  g : �׷��� ���� ����ü�� �ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void outputGraph_List(GraphList *g)
{
	Node *tmp;


	for (int i = 0; i < g->vertexCnt; i++)
	{
		tmp = g->graph[i];
		printf("%c :", i+'A');
		while (tmp != NULL)
		{
			if (tmp->next == NULL)
			{
				printf("%c", tmp->vertex + 'A');
			}
			else
			{
				printf("%c -> ", tmp->vertex + 'A');
			}
			tmp = tmp->next;
		}
		printf("\n");
	}
	
	//TODO

}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: destroyGraph_L() - �׷������� ���� ��� ��� ����
��������:  g : �׷��� ���� ����ü�� �ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void destroyGraph_List(GraphList *g)
{
	Node *tmp;
	for (int i = 0; i < g->vertexCnt; i++)
	{
		tmp = g->graph[i];
		while (tmp != NULL)
		{
			g->graph[i] = tmp->next;
			free(tmp);
			tmp = g->graph[i];
		}
		
	}
	//TODO


}
