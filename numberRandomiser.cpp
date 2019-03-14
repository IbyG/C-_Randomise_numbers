#include <iostream>
#include <cstdlib>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <algorithm>


using namespace std;

//generates a number and returns it. (0-9)
int genNum()
{

    int x = (rand() % 10) ;
    return x;

}

int binary()
{
    //produces a zero or a one
        int x = (rand() % 2) ;
        return x;

}

void printArray(int array[])
{
    cout<<"\n";
    //printing the values in the array
    for(int a = 0; a < 10; a++)
    {
        cout<<array[a]<<" ";
    }

}
//approach 1
int assignNum(int numArray[])
{

    int totalcalls = 0;

    //getting random number
    int num = genNum();
    totalcalls += 1;

    //filling the array with dummy data
    std::fill_n(numArray, 10, 'e');

    //incrementing the array and adding the random generated value
    for(int k = 0; k < 10; k++)
    {
      //going through the array making sure that there are no doubles
      for(int i = 0; i < 10; i++)
        {
            //checking if the number already exists in the array
            if(numArray[i] == num)
            {
                do
                {
                    //cout<<"true"<<num<<"\t in Array:"<<numArray[i]<<"\n";
                    i = 0;
                    num = genNum();
                    totalcalls += 1;
                }while(numArray[i] == num);
            }

        }
        numArray[k] = num;
    }

    return totalcalls;



}

//approach 2
int assignnum2(int numArray[])
{
    /*
    1. get random number
    2. that is the position in the array
    3. swap it with the one before is or after
    */

    int num; //storing the random integer produced by genNum
    int temp; //stores int temperarly
    int either; //stores one or zero
    int totalcalls = 0; //stores the amount of calls to genNum()

    //setting the array from 0-9
     for(int i = 0; i <= 9; i++)
    {
        numArray[i] = i;
    }

    for(int a = 0; a < 25; a++)
    {
        num = genNum();
        totalcalls +=1;

        //swapping the first and the last
        ;
        if(num==0)
        {
            num = genNum(); //getting random position to switch with
            totalcalls +=1;
            temp = numArray[0];
            numArray[0] = numArray[num];
            numArray[num] = temp;
        }else if(num==9)
        {
            num = genNum(); //getting random position to switch with
            totalcalls +=1;
            temp = numArray[9];
            numArray[9] = numArray[num];
            numArray[num] = temp;
        }else //swapping at random either from left to right(0) or right to left(1)
        {
            either = binary();
            if(either == 1)
            {
                    temp = numArray[num + 1];
                    numArray[num + 1] = numArray[num];
                    numArray[num] = temp;
            }else
            {
                temp = numArray[num - 1];
                numArray[num - 1] = numArray[num];
                numArray[num] = temp;
            }

        }



    }
    return totalcalls;




}

//approach 3
void shuffle(int digits[])
{

    //here we are shuffling the numbers and printing them out.
    for(int i = 0; i <= 9; i++)
    {
        digits[i] = i;
    }

    for(int k = 0; k <=10; k++)
    {
        std::random_shuffle(digits,digits + 10);
    }





}


int alike(int digits[])
{
    int order[10] = {0,1,2,3,4,5,6,7,8,9};
    int alike = 0;

    for(int i = 0; i <= 10; i++)
    {
        if(order[i] == digits[i])
        {
            alike++;
        }
    }

    return alike;
}

int main()
{

    //stores how many times a function has been called
    int totalcalls = 0;
    int sumTotalCalls = 0;
    //basic int array
    int ranNum[9];

    //emptying array

    std::fill_n(ranNum, 10, 1024);


    //making a random seed
    srand(time(0));

    //stores the amount of unchanged letters in the alphabet
    int totalunchanged = 0;

    //approach one
    cout<<"Aproach1";
    for(int i = 0; i < 20; i++)
    {
        totalcalls = assignNum(ranNum);
        printArray(ranNum);
        cout<<"\t Unchanged: "<<alike(ranNum)<< "\tcalls to genNum(): "<<totalcalls;
        totalunchanged += alike(ranNum);
        sumTotalCalls += totalcalls; //getting the accumilation of total calls

    }
    cout<<"\nTotal Unchanged: "<< totalunchanged;
    cout<<"\nSum Of Total Calls: "<< sumTotalCalls;
    totalunchanged = 0;
    sumTotalCalls = 0;


    cout<<"\n\nAproach2";
    for(int i = 0; i < 20; i++)
    {

            totalcalls = assignnum2(ranNum);
            printArray(ranNum);
            cout<<"\t Unchanged: "<<alike(ranNum)<< "\tcalls to genNum(): "<<totalcalls;
            totalunchanged += alike(ranNum);
            sumTotalCalls += totalcalls; //getting the accumilation of total calls
    }

    cout<<"\nTotal Unchanged: "<< totalunchanged;
    cout<<"\nSum Of Total Calls: "<< sumTotalCalls;
    totalunchanged = 0;
    sumTotalCalls = 0;

    cout<<"\n\nAproach3";
    for(int i = 0; i < 20; i++)
    {
        shuffle(ranNum);
        printArray(ranNum);
        cout<<"\t Unchanged: "<<alike(ranNum)<< "\tShuffled 10";
        totalunchanged += alike(ranNum);
        sumTotalCalls += totalcalls; //getting the accumilation of total calls
    }
    cout<<"\nTotal Unchanged: "<< totalunchanged;
    totalunchanged = 0;








    return 0;
}

