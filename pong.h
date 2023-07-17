#define WIDTH 80
#define HEIGHT 25
#define L_PADDLE_X 1
#define R_PADDLE_X 78
#define WIN_SCORE 11

typedef struct Ball {
    int x;
    int y;
} Ball;

typedef struct Paddle {
    int y;
    int score;
} Paddle;

typedef struct Collision {
    int x;
    int y;
} Collision;

int game();
Ball get_ball();
Paddle get_paddle();
Ball reset_ball(Ball ball);
void is_winner(int winner);
void is_winner_bot(int winner);
Paddle reset_paddle(Paddle paddle);
Collision get_collision(const int rand_nums[2]);
Paddle move_up(Paddle paddle);
Paddle move_down(Paddle paddle);
Ball move_ball(Ball ball, Collision col);
Collision ball_collision(Ball ball, Collision col, Paddle l_paddle, Paddle r_paddle);
void print_board(Ball ball, Paddle l_paddle, Paddle r_paddle);
void print_score(Paddle l_paddle, Paddle r_paddle);
Paddle bot_move(Ball ball, Paddle paddle, int level, int rand_n);
int bot(Ball ball, Paddle paddle, int level, int rand_n);