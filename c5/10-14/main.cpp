#include <iostream> 
using namespace std;
#include <cmath>
#include <iomanip>

class Vector{
    public:
    Vector(int in_size);
    Vector(int in_size,double* in_col);
    double *col;//store the col elements in Vector
    int size;
    ~Vector();
    void showVec();
    
};

Vector::Vector(int in_size){
    size  = in_size;
    col = new double[size];
}

Vector::Vector(int in_size,double* in_col){
    size  = in_size;
    col = new double[size];
    for(int i =0;i<size;i++){
        col[i] = in_col[i];
    }
}

Vector::~Vector(){
    if(!col) delete col;
}

void Vector::showVec(){

    for (int i = 0;i<size;i++){
        cout<<"  "<<setiosflags(ios::left)<<setw(8)<<col[i]<<"  ";
    }
    cout<<endl;


}

void test01(int row_num, int col_num){
    cout<<"Double pointer of Vector is created!!!"<<endl;
    Vector** Mat = new Vector* [row_num];
    for(int i = 0;i<row_num;i++){
        double* data = new double[col_num];
        for(int j= 0;j<col_num;j++){
            if(j<=i)data[j] = 1/(i+j+1.0);
            else data[j] = 0;
        }
        Mat[i] = new Vector(col_num,data);
        delete data;
    }
    //essemble

    //show Mat
    for (int i= 0;i<row_num;i++){
        Mat[i]->showVec();
    }


    //delete
    for(int i = 0;i<row_num;i++){
        delete Mat[i];
    }
    delete[] Mat;
    
    cout<<"Double pointer of Vector is deleted!!!"<<endl;


}

int main(){
    cout<<"Please input the size of an n*n Matrix:"<<endl;
    int size = 0;
    cin>>size;
    int row_num = size;
    int col_num = size;
    test01( row_num,  col_num);
    return 0;
}
