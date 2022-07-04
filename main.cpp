#include <iostream>

using namespace std;

#define NUMBER_OF_FIELDS 9
#define NUMBER_OF_ROWS 3
#define NUMBER_OF_COLUMNS 3

enum Fields
{
    FIELD1,
    FIELD2,
    FIELD3,
    FIELD4,
    FIELD5,
    FIELD6,
    FIELD7,
    FIELD8,
    FIELD9
};

enum FieldDefaultValues
{
    FIELD1_DEFAULT = 1,
    FIELD2_DEFAULT,
    FIELD3_DEFAULT,
    FIELD4_DEFAULT,
    FIELD5_DEFAULT,
    FIELD6_DEFAULT,
    FIELD7_DEFAULT,
    FIELD8_DEFAULT,
    FIELD9_DEFAULT
};

static int fields[9] =
            {
                FIELD1_DEFAULT, FIELD2_DEFAULT, FIELD3_DEFAULT,
                FIELD4_DEFAULT, FIELD5_DEFAULT, FIELD6_DEFAULT,
                FIELD7_DEFAULT, FIELD8_DEFAULT, FIELD9_DEFAULT
            };

enum ValuesOfBoard
{
    FREE = 10,
    O_PLAYER,
    X_PLAYER
};

static void playTicTacToe(void);
static bool setField(int choice, ValuesOfBoard valueOfBoard);
static bool checkIfFieldIsUsed(int choice);
static void printBoard(void);

int main()
{
    playTicTacToe();
}

/* Print board in real-time game */
static void printBoard(void)
{
    cout << "***** BOARD *****\n";
    for(int i = 0; i < NUMBER_OF_ROWS; i++)
    {
        for(int j = 0; j < NUMBER_OF_COLUMNS; j++)
        {
            if(fields[i * 3 + j] == 11)
            {
                cout << "O";
            }
            else if(fields[i * 3 + j] == 12)
            {
                cout << "X";
            }
            else
            {
                cout << fields[i * 3 + j];
            }
            cout << "\t";
        }
        cout << "\n";
    }
    cout << "***** ***** *****\n";
}

/* Return true is (choice) field is used */
static bool checkIfFieldIsUsed(int choice)
{
    if(fields[(choice - 1)] > 9)
    {
        return true;
    }

    return false;
}

static bool setField(int choice, ValuesOfBoard valueOfBoard)
{
    bool isMoveCorrect = true;
    bool isFieldUsed = checkIfFieldIsUsed(choice);
    if(isFieldUsed == true)
    {
        isMoveCorrect = false;
    }
    else
    {
        switch(choice)
        {
            case 1:
                fields[FIELD1] = valueOfBoard;
                break;
            case 2:
                fields[FIELD2] = valueOfBoard;
                break;
            case 3:
                fields[FIELD3] = valueOfBoard;
                break;
            case 4:
                fields[FIELD4] = valueOfBoard;
                break;
            case 5:
                fields[FIELD5] = valueOfBoard;
                break;
            case 6:
                fields[FIELD6] = valueOfBoard;
                break;
            case 7:
                fields[FIELD7] = valueOfBoard;
                break;
            case 8:
                fields[FIELD8] = valueOfBoard;
                break;
            case 9:
                fields[FIELD9] = valueOfBoard;
                break;
            default:
                cout << "Bad number entered\n";
        }
    }

    return isMoveCorrect;
}


static void playTicTacToe(void)
{
    // I will not use array. Arrays are used in the next chaper

    // To set how many moves were czrried out
    int counter = 1;

    // To choose field to be marked by O or X
    int choice;

    cout << "Lets start Tic Tac Toe game.\n";

    cout << "This is the board, number is one field\n";
    cout << "1" << "\t" << "2" << "\t" << "3\n";
    cout << "4" << "\t" << "5" << "\t" << "6\n";
    cout << "7" << "\t" << "8" << "\t" << "9\n";

    cout << "O starts!\n";

    while(counter <= NUMBER_OF_FIELDS)
    {
        if(counter % 2 == 1)
        {
            cout << "O move:";
            cin >> choice;
            bool isOMoveCorrect = setField(choice, O_PLAYER);

            if(isOMoveCorrect)
            {
                counter++;
            }
            else
            {
                cout << "This field is used! Set field one more time!\n";
            }
        }
        else
        {
            cout << "X move:";
            cin >> choice;

            bool isXMoveCorrect = setField(choice, X_PLAYER);

            if(isXMoveCorrect)
            {
                counter++;
            }
            else
            {
                cout << "This field is used! Set field one more time!\n";
            }
        }

        printBoard();

        if((fields[FIELD1] == fields[FIELD2]) && (fields[FIELD2] == fields[FIELD3]) ||
           (fields[FIELD1] == fields[FIELD4]) && (fields[FIELD4] == fields[FIELD7]) ||
           (fields[FIELD3] == fields[FIELD6]) && (fields[FIELD6] == fields[FIELD9]) ||
           (fields[FIELD7] == fields[FIELD8]) && (fields[FIELD8] == fields[FIELD9]) ||
           (fields[FIELD1] == fields[FIELD5]) && (fields[FIELD5] == fields[FIELD9]) ||
           (fields[FIELD3] == fields[FIELD5]) && (fields[FIELD5] == fields[FIELD7]) ||
           (fields[FIELD2] == fields[FIELD5]) && (fields[FIELD5] == fields[FIELD8]) ||
           (fields[FIELD4] == fields[FIELD5]) && (fields[FIELD5] == fields[FIELD6]))
        {
            if(counter % 2 == 1)
            {
                cout << "X wins!\n";
                break;
            }
            else
            {
                cout << "O wins!\n";
                break;
            }
        }

        if(counter == 10)
        {
            cout << "Nobody wins!\n";
            break;
        }
    }
}