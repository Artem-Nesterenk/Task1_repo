OBJS	 = main.o msg_ctrl.o reciever.o sender.o vehicle.o
SOURCE	 = main.c msg_ctrl.c reciever.c sender.c vehicle.c
HEADER	 = defines.h msg_ctrl.h reciever.h sender.h vehicle.h
OUT		 = platform_internal
CC	 	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = -lpthread -lrt

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS) && \
	rm -f $(OBJS)

main.o: main.c
	$(CC) $(FLAGS) main.c 

msg_ctrl.o: msg_ctrl.c
	$(CC) $(FLAGS) msg_ctrl.c 

reciever.o: reciever.c
	$(CC) $(FLAGS) reciever.c 

sender.o: sender.c
	$(CC) $(FLAGS) sender.c 

vehicle.o: vehicle.c
	$(CC) $(FLAGS) vehicle.c 

clean:
	rm -f $(OBJS) $(OUT)

run: $(OUT)
	./$(OUT)