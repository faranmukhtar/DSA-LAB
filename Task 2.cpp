#include <iostream>
#include <ctime>
#include <random>
using namespace std;


void guessgame(int num,int pos = 0 ){
    int guess;
    int player;
    if (pos %2 == 0){
        player =1;
    }
    else{
        player = 2;
    }

    cout<< "Player "<<player<<" enter your guess: ";
    cin>>guess;
    if(guess> num){
        cout<<"Too high"<<endl;
    }
    else if(guess < num){
        cout<<"Too Low"<<endl;
    }
    else{
        cout<< "Player "<<player<<" wins!!! "<<endl;
        return;
    }
    pos++;
    guessgame(num, pos);
}

int main(){
    srand(time(nullptr));
    int randnum = rand() %100 +1;
    guessgame(randnum);
}