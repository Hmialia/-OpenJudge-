#include<iostream>
#define A int main(void) { std::cout<<'A'; }
#define B int main(void) { std::cout<<'B'; }
#define C int main(void) { std::cout<<'C'; }
#define D int main(void) { std::cout<<'D'; }

/**
  
  下面程序段的时间复杂度是：（   ）
  
  for (i=0; i<n; i++)   
  for(j=0; j<n; j++)    
  a[i][j] = i*j; 
  
  A. O(m^2)      B. O(n^2)      C. O(m*n)      D. O(m+n)
  
 */

// 请在下面的代码段填入正确的选项（请使用大写）
B
