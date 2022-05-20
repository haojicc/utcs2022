# utcs2022

## Problem：
### input:array A[i,j]
### output:ascending array A[i,j-1]

int multfrac(int k, int l, int m){
  return (k * l + (m - 1))/m;
}

void compare_swap(int *p, int *q){
  if(*p > *q) {
    int tmp = *p;
    *p = *q;
    *q = tmp;
  }
}


void mysort(int a[], int i, int j){
  int k = j - 1;
  if(k < 4){
    ?X
  } else{
    mysort(a, i, i + multfrac(k, x, w));
    mysort(a, j - multfrac(k, y, w), j);
    mysort(a, i, i + multfrac(k, z, w));
  }
}

(1)if(w,x,y,z)=(4,3,3,3); Fill in some code at ?X, so that the program can achieve the expected output.

(2)Let T(n) denote the number of times that the code fragment ?X is executed while mysort(a, 0, n) is called. Give the order of T(n) on n when (w,x,y,z)=(4,3,3,3).

(3)Answer whether or not mysout always works correctly for each case where (w,x,y,z)={(4,2,3,3),(4,3,2,3),(4,3,3,2),(4,2,3,2)}

(4)Gice a neccessary and sufficient condition on w,x,y,z that guarantees mysort to always work correctly.
