#include <bits/stdc++.h>
using namespace std;

// < (less than operator)
class ltclass{
public:
    int a,b,c; // b+c
};

/*class compclass{
public:
    bool operator()(const ltclass & left, const ltclass & right){
        return left.b+left.c < right.b+right.c;
    }
};*/

bool mcomp(const ltclass left, const ltclass right){
    return left.b+left.c < right.b+right.c;
}

int main(){

    srand(time(NULL));
   
    priority_queue < ltclass, vector < ltclass >, function < bool(ltclass,ltclass) > > ltpq(mcomp);
    
    for(int i=0;i<10;i++){
        ltclass curr;
        curr.a = rand() % 20;
        curr.b = rand() % 20;
        curr.c = rand() % 20;
        ltpq.push(curr);
    }

    while(!ltpq.empty()){
        cout << ltpq.top().b + ltpq.top().c << endl;
        ltpq.pop();
    }


}
