#include <bits/stdc++.h>
using namespace std;

const int N = 300;

class Sort{
    public:
        int a[N];
        int x, y, z, w;

        int multfrac(int k, int l, int m){
            return (k * l + (m - 1)) / m;
        }

        void compare_swap(int *p, int *q){
            if (*p > *q) {
                int tmp = *p;
                *p = *q;
                *q = tmp;
            }
        }

        void mysort(int a[], int i, int j){
            // printf("i = %d; j = %d\n", i, j); 
            int k = j - i;
            if (k < 4){
                if (k <= 1){
                    return;
                }
                while (k--){
                    for (int h = i; h + 1 < j; h++){
                        compare_swap(a + h, a + (h + 1));
                    }
                }
            } else {
                //printf("divided:k = %d ; w = %d\n", k, w);
                mysort(a, i, i + multfrac(k, x, w));
                mysort(a, j - multfrac(k, y, w), j);
                mysort(a, i, i + multfrac(k, z, w));
            }
        }
        bool test(int w, int x, int y, int z, bool output){
            if((4 * x + (w - 1)) / w >= 4 || (4 * y + (w - 1)) / w >= 4 || (4 * z + (w - 1)) / w >= 4) return false;
            
            for (int i = 0; i < N; i++){
                a[i] = N - i;
            }
            // for (int i = 0; i < N; i++){
            //     int idx = rand() % (N - i) + i;
            //     int temp = a[idx];
            //     a[idx] = a[i];
            //     a[i] = temp;
            // }

            if (output){
                for (int i = 0; i < N; i++){
                    printf(" %d ", a[i]);
                }
                puts("");
            }

            this->w = w;
            this->x = x;
            this->y = y;
            this->z = z;

            mysort(a, 0, N);
            if (output){
                for (int i = 0; i < N; i++){
                    printf("%d ", a[i]);
                }
                puts("");
            }

            for (int i = 0; i + 1 < N; i++){
                if (a[i] > a[i + 1]){
                    return false;
                }
            }
            return true;
        }
};




int main(){
    std::ofstream outFile;
    
    srand (time(NULL));
    Sort ojb;

    outFile.open("/Users/haoji/Downloads/test.txt");
    
    int index = 30;

    for(int j = 0; j < index; j++){
        for(int h = 0; h < index; h++){
            for(int g = 0; g < index; g++){
                if (ojb.test(index, j, h, g, false)){
                    // cout << j << ";" << h << ";" << g << ";"<< endl;
                    // cout << "true" << endl; 
                    outFile << j << ";" << h << ";" << g << ";"<< j + h + g << endl;
                    //outFile << j + h + g << endl;
                    //outFile << "true" << endl; 
                } 
                // else{
                //     // cout << j << " " << h << " " << g << " "<< endl;
                //     // cout << "false" << endl;
                    // outFile << j << " " << h << " " << g << " "<< endl;
                    // outFile << "false" << endl;
                // }
            }
        }
    }
    return 0;
}
