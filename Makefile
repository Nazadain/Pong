all:
	gcc menu.c pong.c pong_bot.c -Wall -Werror -Wextra
	
clean:
	rm a.out