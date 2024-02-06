#include <stdio.h>

// enum for possible directions
enum DIRECTION
{
    N,
    O,
    S,
    W
};

// robot structure
typedef struct
{
    int xpos;
    int ypos;
    enum DIRECTION dir;
} ROBOT;

void move(ROBOT *robot)
{
    int direction = robot->dir; // current direction we are facing

    // switch to find which action we wanna do, 0 = N, 1 = O, 2 = S, 3 = W;
    switch (direction)
    {
    case 0:
        robot->ypos = robot->ypos + 1; // North = move 1 step upwards on y axis
        break;

    case 1:
        robot->xpos = robot->xpos + 1; // East = move 1 step right on x axis;
        break;

    case 2:
        robot->ypos = robot->ypos - 1; // South = move 1 step down on y axis;
        break;

    case 3:
        robot->xpos = robot->xpos - 1; // West = move 1 step left on x axis;
    }
}

void turn(ROBOT *robot)
{
    // Since directions are defiend in clockwise order alreadyt we can just plus 1 it, modulo to wrap around.
    robot->dir = (robot->dir + 1) % 4;
}

int main(char *argv[])

{
    // define robot
    ROBOT robot;

    // set default direction
    robot.dir = N;

    // infinite loop until ctrl-z
    while (1)
    {
        // string to store input, 100 max chars
        char inputString[100];

        printf("Enter string of moves you wanna make, m = mov, t = turn\n");

        scanf("%s", inputString);

        // loop over each character in the string
        for (int i = 0; inputString[i] != '\0'; i++)
        {
            char c = inputString[i]; // current char

            // if user enters 'm' robot moves
            if (c == 'm')
            {
                move(&robot);
            }
            // if user enters 't' we turn the robot
            else if (c == 't')
            {
                turn(&robot); //
            }
        }

        printf("Robot location after instructions are: x=%d y=%d\n", robot.xpos, robot.ypos);
    }
    //
}