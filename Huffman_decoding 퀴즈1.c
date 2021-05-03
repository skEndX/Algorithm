/*문제 설명

최대 9개의 다른 알파벳 소문자로 구성된 문자열 (최대길이 50)을 입력받아,
이를 허프만 인코딩한 형태로 출력하시오.

예를 들어,
문자열 aaabbc 가 입력되면,
각 문자수 별로 빈도수를 파악한다.
a:3개, b:2개, c: 1개

 허프만트리를 구성할 알파벳 순서가 빠른 것 (b는 c보다 순서가 빠르다)을
 왼쪽 자식으로 놓고 구성하고,
만약, 2개 이상의 문자가 합쳐진 노드들을 허프만 트리로 만드는 경우,
가장 순서가 빠른 알파벳을 포함한 노드를 왼쪽 자식으로 놓는다.

이에 따라, 구성된 허프만 코드는 아래와 같다.
a : 0
 b : 10
 c : 11

위 정보를 이용하여, 인코딩한 형태는
3a10b210c211$000101011# 이 되어야 한다.

허프만 트리 정보를 인코딩에 포함시킬 때는
 알파벳 오름차순 (a->b->c)에 따라 넣는다.


입력

aaabbc

출력

3a10b210c211$000101011#

입력 예시
aaabbc

출력 예시
3a10b210c211$000101011#
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
   char c;
   int freq;
   struct node *next;
   struct node *right;
   struct node *left;
};
struct node *head = 0;
char string[51];
char ASC[256];
char enco[100];
int iidx=-1;
char ccode[100];
int cnt = 0;
char arr[51];
char deco[100];
int deidx = 0;
struct node* node(char c, int freq)
{
   struct node *new = (struct node *)malloc(sizeof(struct node));
   new->c = c;
   new->freq = freq;
   new->left = new->right = new->next = 0;
   return new;
}
void addSLL(struct node *new)
{
   struct node *cur = head;
   if (head == 0)
   {
      head = new;
      return;
   }
   else
   {
      while (cur->next != 0)
      {
         cur = cur->next;
      }
      cur->next = new;
   }
}
struct node *smallnode()
{
   struct node *fnode = head;
   struct node *cur = head;
   int small = 999999999;
   while (cur != 0)
   {
      if (cur->freq < small)
      {
         small = cur->freq;
         fnode = cur;
      }
      cur = cur->next;
   }
   if (head == fnode)
   {
      head = head->next;
   }
   else
   {
      cur = head;
      while (cur->next != fnode)
      {
         cur = cur->next;
      }
      cur->next = fnode->next;
   }
   fnode->next = 0;
   return fnode;
}
void traverse(struct node *cur, char c, char find,int idx,int f)
{
   iidx++;
   ccode[iidx] = c;
   ccode[iidx + 1] = 0;
   if (cur->left == 0 && cur->right == 0)
   {
      if (find == cur->c)
      {
         if (f == 0)
         {
            enco[idx] = (iidx + 1) + 48;
            for (int i = 0; i <= iidx; i++)
            {
               enco[idx + i + 1] = ccode[i];
               cnt++;
            }
         }
         else
         {
            for (int i = 0; i <= iidx; i++)
            {
               deco[deidx] = ccode[i];
               deidx++;
            }
         }
      }
      ccode[iidx] = 0;
      iidx--;
      return;
   }
   else
   {
      traverse(cur->left, '0', find, idx,f);
      traverse(cur->right, '1', find, idx,f);
   }
   ccode[iidx] = 0;
   iidx--;
   return;
}

int main(void)
{
   int k = 1;
   int total = 0;
   memset(string, 0, sizeof(51));
   scanf("%s", string);
   int flag = 0;
   int h = 0;
   deco[0] = '$';
   deidx++;
   for (int i = 0; i < strlen(string); i++)
   {
      for (int j = 0; j <= h; j++)
      {
         if (string[i] == arr[j])
         {
            flag = 1;
         }
      }
      if (flag == 0)
      {
         arr[h] = string[i];
         h++;
      }
      flag = 0;
   }
   total = h;
   for (int i = 0; i < strlen(string); i++)
   {
      ASC[(int)string[i]]++;
   }
   for (int i = 0; i < 256; i++)
   {
      if (ASC[i] > 0)
      {
         addSLL(node(i, ASC[i]));
      }
   }
   while (head->next != 0)
   {
      struct node *first = smallnode();
      struct node *secound = smallnode();
      struct node *new = node(first->c, first->freq + secound->freq);
      if (first->c > secound->c)
      {
         new->left = secound;
         new->right = first;
      }
      else
      {
         new->left = first;
         new->right = secound;
      }
      addSLL(new);
   }
   memset(enco, 0, sizeof(100));
   enco[0] = total + 48;
   for (int i = 0; i < h; i++)
   {
      enco[k] = arr[i];
      k++;
      traverse(head->left, '0', arr[i], k,0);
      traverse(head->right, '1', arr[i], k,0);
      k = k + cnt + 1;
      cnt = 0;
   }
   for (int i = 0; i < strlen(string); i++)
   {
      traverse(head->left, '0', string[i], k, 1);
      traverse(head->right, '1', string[i], k, 1);
   }
   deco[deidx] = '#';
   for (int i = 0; i < strlen(enco); i++)
   {
      printf("%c", enco[i]);
   }
   printf("%s", deco);
}