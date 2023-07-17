#include "pong.h"

#include <stdio.h>
#include <stdlib.h>

int game() {
    const int rand_nums[2] = {-1, 1};
    Ball ball = get_ball();
    Paddle l_paddle = get_paddle();
    Paddle r_paddle = get_paddle();
    Collision col = get_collision(rand_nums);
    int winner = 0;
    int count_side = 0;
    getchar();
    while (1) {
        char inp;
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
            case 'k':
                r_paddle = move_up(r_paddle);
                break;
            case 'm':
                r_paddle = move_down(r_paddle);
                break;
            case 'q':
                return 0;
            case '\n':
                col = ball_collision(ball, col, l_paddle, r_paddle);
                ball = move_ball(ball, col);
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
            is_winner(winner);
            getchar();
            break;
        }
    }

    return 0;
}

Ball get_ball() {
    Ball ball;
    ball.x = WIDTH / 2;
    ball.y = HEIGHT / 2;
    return ball;
}

Paddle get_paddle() {
    Paddle paddle;
    paddle.score = 0;
    paddle.y = HEIGHT / 2;
    return paddle;
}

Collision get_collision(const int rand_nums[2]) {
    Collision col;
    col.x = rand_nums[rand() % 2];
    col.y = rand_nums[rand() % 2];
    return col;
}

Ball reset_ball(Ball ball) {
    ball.x = WIDTH / 2;
    ball.y = HEIGHT / 2;
    return ball;
}

Paddle reset_paddle(Paddle paddle) {
    paddle.y = HEIGHT / 2;
    return paddle;
}

Ball move_ball(Ball ball, Collision col) {
    if (col.x == 1)
        ball.x -= 1;
    else
        ball.x += 1;
    if (col.y == 1)
        ball.y -= 1;
    else
        ball.y += 1;
    return ball;
}

Paddle move_up(Paddle paddle) {
    if (paddle.y - 1 != 1) paddle.y -= 1;
    return paddle;
}

Paddle move_down(Paddle paddle) {
    if (paddle.y + 1 != HEIGHT - 2) paddle.y += 1;
    return paddle;
}

Collision ball_collision(Ball ball, Collision col, Paddle l_paddle, Paddle r_paddle) {
    if (ball.x == R_PADDLE_X - 1 &&
        (ball.y == r_paddle.y - 1 || ball.y == r_paddle.y || ball.y == r_paddle.y + 1))
        col.x *= -1;
    if (ball.x == L_PADDLE_X + 1 &&
        (ball.y == l_paddle.y - 1 || ball.y == l_paddle.y || ball.y == l_paddle.y + 1))
        col.x *= -1;
    if (ball.y == 1 || ball.y == HEIGHT - 2) col.y *= -1;
    return col;
}

void is_winner(int winner) {
    system("clear");
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            if (col == WIDTH / 2 && row == HEIGHT / 2 && winner == 1)
                printf("Winner: Left");
            else if (col == WIDTH / 2 && row == HEIGHT / 2 && winner == 2)
                printf("Winner: Right");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void print_score(Paddle l_paddle, Paddle r_paddle) {
    system("clear");
    int l_coordinate = 30;
    int r_coordinate = 50;
    for (int col = 0; col < WIDTH; col++) {
        if (l_paddle.score > 9) {
            l_coordinate = 29;
            r_coordinate = 49;
        }
        if (col == l_coordinate)
            printf("%d", l_paddle.score);
        else if (col == r_coordinate) {
            printf("%d", r_paddle.score);
        } else
            printf(" ");
    }
    printf("\b");
    printf("\n");
}

void print_board(Ball ball, Paddle l_paddle, Paddle r_paddle) {
    int is_paddle_l;
    int is_paddle_r;
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            is_paddle_l =
                (col == L_PADDLE_X && (l_paddle.y - 1 == row || l_paddle.y == row || l_paddle.y + 1 == row));
            is_paddle_r =
                (col == R_PADDLE_X && (r_paddle.y - 1 == row || r_paddle.y == row || r_paddle.y + 1 == row));
            if (ball.y == row && ball.x == col)
                printf("O");
            else if ((row == 0 || row == HEIGHT - 1) && col > 0 && col < WIDTH - 1)
                printf("-");
            else if ((col == 0 || col == WIDTH / 2 || col == WIDTH - 1) && row > 0 && row < HEIGHT - 1)
                printf("|");
            else if (is_paddle_l)
                printf("]");
            else if (is_paddle_r)
                printf("[");
            else
                printf(" ");
        }
        printf("\n");
    }
}