#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "pong.h"

int bot_game() {
    srand((unsigned int)time(NULL));
    const int rand_nums[2] = {-1, 1};
    char inp;
    int level;
    Ball ball = get_ball();
    Paddle l_paddle = get_paddle();
    Paddle r_paddle = get_paddle();
    Collision col = get_collision(rand_nums);
    int winner = 0;
    int count_side = 0;
    printf("Choose level:\n");
    printf("1: Easy\n2: Medium\n3: Hard\n>");
    scanf("%d", &level);
    getchar();
    while (1) {
        print_score(l_paddle, r_paddle);
        print_board(ball, l_paddle, r_paddle);
        scanf("%c", &inp);
        switch (inp) {
            case 'a':
                l_paddle = move_up(l_paddle);
                break;
            case 'z':
                l_paddle = move_down(l_paddle);
                break;
            case 'q':
                return 0;
            case '\n':
                col = ball_collision(ball, col, l_paddle, r_paddle);
                ball = move_ball(ball, col);
                int rand_n = rand() % 100;
                r_paddle = bot_move(ball, r_paddle, level, rand_n);
                break;
        }
        if (ball.x == 1) r_paddle.score += 1;
        if (ball.x == WIDTH - 2) l_paddle.score += 1;
        if (ball.x == 1 || ball.x == WIDTH - 2) {
            ball = reset_ball(ball);
            l_paddle = reset_paddle(l_paddle);
            r_paddle = reset_paddle(r_paddle);
            count_side += 1;
            if (count_side == 2) {
                count_side = 0;
                col.x *= -1;
            }
            col.y = rand_nums[rand() % 2];
        }
        if (l_paddle.score == WIN_SCORE)
            winner = 1;
        else if (r_paddle.score == WIN_SCORE)
            winner = 2;
        if (winner == 1 || winner == 2) {
            is_winner_bot(winner);
            getchar();
            break;
        }
    }

    return 0;
}
int bot(Ball ball, Paddle paddle, int level, int rand_n) {
    int res = rand_n;
    if (level == 1) {
        if (ball.y > paddle.y) {
            if (res < 80)
                res = 1;
            else
                res = 0;
        } else if (ball.y <= paddle.y) {
            if (res > 80)
                res = 1;
            else
                res = 0;
        }
    }
    if (level == 2) {
        if (ball.y > paddle.y) {
            if (res < 88)
                res = 1;
            else
                res = 0;
        } else if (ball.y <= paddle.y) {
            if (res > 88)
                res = 1;
            else
                res = 0;
        }
    }
    if (level == 3) {
        if (ball.y > paddle.y) {
            if (res < 98)
                res = 1;
            else
                res = 0;
        } else if (ball.y <= paddle.y) {
            if (res > 98)
                res = 1;
            else
                res = 0;
        }
    }
    return res;
}

Paddle bot_move(Ball ball, Paddle paddle, int level, int rand_n) {
    int res = bot(ball, paddle, level, rand_n);
    if (res == 0 && paddle.y - 1 != 1)
        paddle.y -= 1;
    else if (res == 1 && paddle.y + 1 != HEIGHT - 2)
        paddle.y += 1;
    return paddle;
}
void is_winner_bot(int winner) {
    system("clear");
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            if (col == WIDTH / 2 && row == HEIGHT / 2 && winner == 1)
                printf("You win!");
            else if (col == WIDTH / 2 && row == HEIGHT / 2 && winner == 2)
                printf("You Lose!");
            else
                printf(" ");
        }
        printf("\n");
    }
}