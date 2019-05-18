
#include<iostream>
#include<vector>

class Sorting
{
    int i, j;
    int temp;
    void swap(int* k, int* l)
    {
        temp = *k;
        *k = *l;
        *l = temp;
    }
    
    public:
    
        std::vector<int> bubbleSort (std::vector <int>*x)
        {   std::vector<int> h = *x;
            int len = h.size();
            for (i = 0;i<len-1; i++)
            {
                for(j = 0;j<len-i-1;j++)
                {  int tmp;
                    if(h[j]>h[j+1])
                      swap(&h[j],&h[j+1]);
                }
            }
         return h;
        }
        
        std::vector<int> QuickSort(std::vector <int>* y)
        {   std::vector<int> h = *x;
            int len = h.size();
            for (i = 0;i<len-1; i++)
            {
                for(j = 0;j<len-i-1;j++)
                {  int tmp;
                    if(h[j]>h[j+1])
                      swap(&h[j],&h[j+1]);
                }
            }
         return h;
        }
};
    int main (void)
    {
      std::vector < int >a = { 2, 4, 5, 6, 7, 8, 1, 2, 3, 4 };
      Sorting b;
      std::vector bubble = b.bubbleSort (&a);
      int i;
      for(i=0;i<10;i++)
        std::cout<<bubble[i]<<" ";
      std::vector quick = b.QuickSort(&a);
      
      return 0;
    }
