#include<iostream>
#define A int main(void) { std::cout<<'A'; }
#define B int main(void) { std::cout<<'B'; }
#define C int main(void) { std::cout<<'C'; }
#define D int main(void) { std::cout<<'D'; }

/**
  
  下面程序段的空间复杂度是：（   ）
  
  int i=1, k=100;
  
  while (i<=n) {
  
  k++;
  
  i+=2;
  
  }
  
  A. O(1)     B. O(n)    C. O(2n)     D. O(n^2) 
  
 */
// 请在下面的代码段填入正确的选项（请使用大写）
A
