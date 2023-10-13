#include <algorithm>
#include <random>
#include <iostream>
#include <climits>

#include "board.hpp"
#include "engine.hpp"
using namespace std;
int mplayer = -1;

int evaluate(const Board &b){

    int count = 0;
    int num = 1;
    if(mplayer == 1){
        num = -1;
    }
    string mboard = board_to_str(b.data.board_0);

    for(int i = 0 ; i < mboard.size() ; i++){

        if(mboard[i] == 'p'){
            count += -1*num;
        }
        if(mboard[i] == 'r'){
            count += -5*num;
        }
        if(mboard[i] == 'b' || mboard[i] == 'k'){
            count += -3*num;
        }

        if(mboard[i] == 'P'){
            count += 1*num;
        }

        if(mboard[i] == 'R'){
            count += 5*num;
        }

        if(mboard[i] == 'B' || mboard[i] == 'K'){
            count += 3*num;
        }
    }

    return count;

}

int do_calc(const Board &b, bool isMeDoing, int depth, int alpha, int beta, atomic<bool> &msearch) {

    if(depth == 4){
        return evaluate(b);
    }

    if(isMeDoing){

        int maxi = INT_MIN;

        auto moveset = b.get_legal_moves();

        for(auto move : moveset){

            if(!msearch){
                break;
            }

            Board* myboard = b.copy();
            myboard->do_move(move);
            int mymaxi = do_calc(*myboard,!isMeDoing,depth+1,alpha,beta,msearch);
            if(mymaxi >= maxi){
                alpha = max(alpha,mymaxi);
                maxi = mymaxi;
            }
            free(myboard);

            if (alpha>=beta)break;

        }

        return maxi;

    }else{

        int maxi = INT_MAX;

        auto moveset = b.get_legal_moves();
        
        for(auto move : moveset){

            if(!msearch){
                break;
            }

            Board* myboard = b.copy();
            myboard->do_move(move);
            int mymaxi = do_calc(*myboard,!isMeDoing,depth+1,alpha,beta,msearch);
            if(mymaxi <= maxi){
                beta = min(beta,mymaxi);
                maxi = mymaxi;
            }
            free(myboard);

            if (alpha>=beta)break;
        }

        return maxi;
    }
}

int numpieces(const Board &b){
    string mboard = board_to_str(b.data.board_0);
    int count = 0;
    if(mplayer == 0){
        for(int i = 0 ; i < mboard.size() ; i++){
            if(mboard[i] == 'P'){
                count ++;
            }
            if(mboard[i] == 'R'){
                count ++;
            }
            if(mboard[i] == 'B' || mboard[i] == 'K'){
                count ++;
            }
        }
    }else{
        for(int i = 0 ; i < mboard.size() ; i++){
            if(mboard[i] == 'p'){
                count ++;
            }
            if(mboard[i] == 'r'){
                count ++;
            }
            if(mboard[i] == 'b' || mboard[i] == 'k'){
                count ++;
            }
        }
    }
    return count;
}

void Engine::find_best_move(const Board& b) {

    if(mplayer == -1){
        if(b.data.player_to_play == WHITE){
            mplayer = 0;
        }
        if(b.data.player_to_play == BLACK){
            mplayer = 1;
        }
    }

    auto moveset = b.get_legal_moves();

    if(moveset.size() == 0){

        this->best_move = 0;
        
    }else{

        int maxi = INT_MIN;
        this->best_move = 0;
        
        int dpt = 1;
        if(moveset.size() <= 6){
            dpt = 0;
        }
        if(numpieces(b) <= 3){
            dpt = -1;
        }

        for(auto move : moveset){

            Board* myboard = b.copy();
            myboard->do_move(move);

            int mymaxi = do_calc(*myboard,false,dpt,INT_MIN,INT_MAX,search);
            if(mymaxi >= maxi){
                maxi = mymaxi;
                this->best_move = move;
            }

            free(myboard);

        }
    }
}

