#include<iostream>
#include<string>
using namespace std;
void solve_tower(int n,string src,string help,string dest){
    if(n==0){
        return ;
    }    
    solve_tower(n-1,src,dest,help);    
    cout<<"Moving "<<n<<" from "<<src<<" to "<<dest<<endl; 
    solve_tower(n-1,help,src,dest);
    return ;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
}
int main(){
    solve_tower(4,"S","H","D");
    return 0;
}