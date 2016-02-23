/*************************************************************************
> File Name: Eight_queens.cpp
> Created Time: Sun 21 Feb 2016 04:31:20 PM CST
************************************************************************/
/**
*八皇后问题是一个很经典的算法问题，即：
*在8×8格的国际象棋上摆放八个皇后，使其不能互相攻击，
*即任意两个皇后都不能处于同一行、同一列或同一斜线上，
*有多少种摆法?
* */

/**
 * 算法思路是：
 * 首先每个皇后有8种可能，运行到第i个皇后时，判断该位置是否被占据
 * 如果没有占据，则占据该位置同时占据这一行，这一列，以及所有的对线方向
 * 然后调用queen(i + 1)进行下次搜索
 * 等这个状态搜索完后（实际上会搜索到queen(8)，回溯到没有占据的状态
 **/

 /**
  * queen(i)
  *  if i > 8 then find a solution, exit
  *  else
  *  for(j = 0; j < 8; ++j)
  *     if(check_pos_valid() == true)
  *         occupy_relation_position();
  *         queen(i + 1);
  *     backdata_the_state()
  **/


#include<iostream>

static int gEightQueen[8] = { 0 }, gCount = 0;

void print(){
    //输出每一种情况下棋盘中皇后的摆放情况
    for (int i = 0; i < 8; i++)
    {   
        int inner;
        for (inner = 0; inner < gEightQueen[i]; inner++)
            std::cout << " ";
        for (inner = gEightQueen[i] + 1; inner < 8; inner++)
            std::cout << "";
        std::cout <<"#" << std::endl;
    }
    std::cout << "==========================\n";

}

bool check_pos_valid(int loop, int value){
    //检查是否存在有多个皇后在同一行/列/对角线的情况
    int index;
    int data;
    for (index = 0; index < loop; index++){
        data = gEightQueen[index];
        if (value == data)
            return false;
        if ((index + data) == (loop + value))
            return false;
        if ((index - data) == (loop - value))
            return false;

    }
    return true;

}

void eight_queen(int index){
    int loop;
    for (loop = 0; loop < 8; loop++){
        if (check_pos_valid(index, loop)){
            gEightQueen[index] = loop;
            if (7 == index){
                gCount++, print();
                gEightQueen[index] = 0;
                return;
            }
            eight_queen(index + 1);
            gEightQueen[index] = 0;            
        }
    }

}

int main(int argc, char*argv[]){
    eight_queen(0);
    std::cout << "total=" << gCount << std::endl;
    return 0;

}
