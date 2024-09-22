## 常用数据结构类型

- > 什么是随机存取？这个性质属于哪种线性表的特征？

  随机读取是 $O(1)$ 复杂度访问任意一个位置,数组可以做到,因为数组地址是连续的

  如果我想访问a数组第 $3$个数 $a+2$ 对应地址就是

  对于链表,地址不连续,需要从第一个开始往后找复杂度 $O(n)$

- > 什么是**指针**？如何在C语言中定义指针变量？指针变量的大小是固定的吗

  指针是储存地址的变量
  
  ```c
  type *p;// type为类型
  int *p // 指向int类型的指针
  ```
- > 你能为不同的数据结构设想出适用的具体情况吗?

  ​数组 : 按学号给出每个人的成绩，要求迅速查询第 $l$ 个人的成绩

  链表: 按学号给出每个人的成绩，支持删除和加入某人成绩，最后按学号输出所有人成绩

  栈: 不用函数来模拟递归

  队列：排队打法问题，排队接水问题，调度任务

  图:求两点最短路

- > 如何使用C语言保存一张图的信息？
  
	使用邻接表，邻接矩阵

	```c
  // 数组实现邻接表
  struct edge{
      int nex,v,w;
  } e[100005];
  int head[100005],cnt;
  
  
  
  void add(int x,int y,int z){
      e[++cnt] . nex = head[x];
      e[cnt].v = y;
      e[cnt] .w = z;
      head[x] = cnt;
  }
  void solve(int x){
          for(int i = head[x];i;i = e[i].nex){
          int v = e[i].v;
          int w = e[i].w;
      }
	}
  ```
  
  ```c
  //基于指针的邻接表
  //边
  typedef struct Edge{
      int v;
      int w;
      struct Edge *nxt;
  }Edge;
  // 点
  typedef struct Node{
      int data;
      Edge * head;
  }AdjList;
  
  typedef struct Graph{
      AdjList *adjlist;
      int vnum,edge;
  }Graph;
  // 初始化
  void init(Graph *G){
      G->adjlist = (AdjList*)malloc(N*sizeof(AdjList)) ;
      G->edge = G->vnum = 0;
      for (int i = 0; i<N; i++) {
          G->adjlist[i].head = NULL;
      }
  }
  // 加入一条边
  void add(Graph *G,int x,int y,int z){
      Edge *temp = (Edge*)malloc(sizeof(Edge));
      temp->v = y;
      temp->w = z;
      temp->nxt = G->adjlist[x].head;
      G->adjlist[x].head = temp;
  }
  // 遍历
  void solve(Graph *G,int x){
      for(Edge *v=G->adjlist[x].head;v!=NULL;v=v->nxt){
  
      }
  
	}
	
  ```
	
  ```
  // 邻接矩阵
  int edge[N][N];
  void add(int x,int y){
      edge[x][y] = 1;
  }
  void solve(int x){
      for(int v=1;v<=n;v++){
          if(edge[x][v]){
              // ... 
          }
      }
	}
  ```
  
  

## 应用

代码在对应文件夹中

P1写了个指针的单向链表

P2在P1基础上写了个约瑟夫问题

P3写了个简单栈



P1.out

```
1 1 1 1 2 1 2 2 1 1 2 1 2 1 3 2 1 1 1 1 1 1 1 2 2 2 1 2 2 1 1 2 2 2 
```

P2.out

```
3 1 1 2 2 1 2 1 1 2 1 2 2 1 1 2 2 1 1 2 2 1 1 2 2 1 1 2 1 1 1 1 1 2
```

P3.out(感觉不太对劲)

```
glimmerinheartnofear4dark
```

Code:[P1](JosephusPart1/JosephusPart1.c) [P2](JosephusPart2/JosephusPart2.c) [P3](Part3/Part3.c)



